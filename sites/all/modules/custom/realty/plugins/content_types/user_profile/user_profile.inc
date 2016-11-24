<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_user_profile_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('User profile'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_user_profile_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_user_profile_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $block->content = theme('realty_user_profile');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_user_profile_content_type_theme(&$theme, $plugin) {
  $theme['realty_user_profile'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-user-profile',
  );
}

/**
 * Process variables for realty-block-stock.tpl.php.
 */
function template_preprocess_realty_user_profile(&$vars) {
  global $user;

  // Если был переход по ссылке Подтвердить заявку на квартиру и ипотеку и заявки были отправлены
  if ($_GET['p'] == 'booking_mortgage_request_success') {
    $vars['modal_title'] = 'Заявки успешно отправлены';
    $vars['modal_text'] = 'Поздравляем, Вы только что отправили заявки на обратный звонок и на ипотеку! В самое ближайшее время с Вами свяжется специалисты отдела продаж и кредитования!';

    $vars['img_close'] = realty_get_image_close();;
  }
  if ($_GET['p'] == 'booking_request_success') {
    $vars['modal_title'] = 'Заявка успешно отправлена';
    $vars['modal_text'] = 'Поздравляем, Вы только что отправили заявку застройщику на обратный звонок! В самое ближайшее время с Вами свяжется специалист отдела продаж!';

    $vars['img_close'] = realty_get_image_close();;
  }
  if ($_GET['p'] == 'mortgage_request_success') {
    $vars['modal_title'] = 'Заявка успешно отправлена';
    $vars['modal_text'] = 'Поздравляем, Вы только что отправили заявку на ипотеку! В самое ближайшее время с Вами свяжется специалист отдела кредитования!';

    $vars['img_close'] = realty_get_image_close();;
  }
  // Если был переход по ссылке Подтвердить заявку и нет не отправленых заявок
  if ($_GET['p'] == 'request_not_found') {
    $vars['modal_title'] = 'Нет не отправленных заявок';
    $vars['modal_text'] = 'В настоящий момент нет сформированных и не отправленных заявок.';

    $vars['img_close'] = realty_get_image_close();;
  }

/*  // Формирование таблица Сравнения квартир
  $comprassion = views_get_view_result('apartments',
    'comprassion_apartment', $user->uid);

  $vars['comparison'] = theme ('realty_comparison_apartment_table',
    array('apartments' => $comprassion));*/


  // Формирование списка заявок на квартиры
  $booking = views_get_view_result("booking", 'bookings_user',
    $user->uid);

  $vars['booking'] = theme ('realty_booking_apartment_table',
    array('apartments' => $booking));


  // Формирование списка заявок на ипотеку
  $mortgage = views_get_view_result("booking", 'mortgage_user', $user->uid);

  $vars['mortgage'] = theme('realty_mortgage_apartment_table',
    array('apartments' => $mortgage));


  $vars['modal'] = theme('realty_apartment_modal');

  $vars['img_strel'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/strel.svg');

  drupal_add_library('system', 'jquery.form');
  drupal_add_library('system', 'drupal.ajax');
}