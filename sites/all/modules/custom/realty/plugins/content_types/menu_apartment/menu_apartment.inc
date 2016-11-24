<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_menu_apartment_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Menu apartment'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_menu_apartment_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_menu_apartment_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_menu_apartment');
  drupal_add_js(array('apartment_page' => TRUE), 'setting');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_menu_apartment_content_type_theme(&$theme, $plugin) {
  $theme['realty_menu_apartment'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-menu-apartment',
  );
}

/**
 * Process variables for realty-menu-apartment.tpl.php.
 */
function template_preprocess_realty_menu_apartment(&$vars) {
  global $user;

  $nid = arg(1);

  $node_apartment = node_load($nid);
  $apartment_info = realty_get_info_apartment($nid);

  $node_complex = node_load($apartment_info['complex_nid']);

  // Номер квартиры
  $vars['apartment_status'] = $node_apartment->field_status[LANGUAGE_NONE][0]['value'];
  $vars['apartment_number'] = $node_apartment->field_number_apartament[LANGUAGE_NONE][0]['value'];
  $vars['nid'] = $node_apartment->nid ;

  // Кнопка Забронировать
  // Если квартира уже забронирована
  if ($node_apartment->field_status[LANGUAGE_NONE][0]['value'] == 0) {

    // Если уже запрошено уведомление о изменении статуса
    if (realty_check_status_apartment_user($user->uid, $node_apartment->nid) == TRUE) {
      $img_booking = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/apartment_comparsion_active.svg');
      $vars['button_booking'] = $img_booking . '<p class="s-label-small color-dark_gray">Запрошено уведомление</p>';
    }

    // Если еще не запрошено уведомление
    else {
      $img_booking = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/apartment_booking_active.svg');
      $vars['button_booking'] = '<div class="apartment-signal pa" data-node-id="' . $node_apartment->nid .
        '" data-page="1">' . $img_booking . '<p class="s-label-small">Оповестить о изменении статуса</p></div>';
    }
  }

  // Если еще не забронирована
  else {
    $img_booking = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/apartment_booking.svg');
    $vars['button_booking'] = '<div class="pa apartment-booking-but" data-toggle="modal" data-target=".modal_free">' .
      $img_booking . '<p class="s-label-small">Связаться с застройщиком</p></div>';

    $vars['img_close'] = realty_get_image_close();
    if(realty_limit_booking_apartment($node_complex)) {
      $vars['booking_form'] = drupal_get_form('realty_booking_apartment_form', $node_apartment);
    }
    else {
      $vars['booking_form'] = '<div class="col-xs-12 text-center"><p>' .
        t('Лимит заявок по данному ЖК исчерпан. Вы можете повторно отправить заявку по истечении 24 часов.') .
        '</p></div>';
    }
  }

    // Кнопка Добавить в сравнение
    // Если квартира уже добавлена в сравнение
    if (realty_checking_apartments_comparison($node_apartment->nid) == TRUE || realty_checking_apartments_comparison_cookies($node_apartment->nid)) {
      $img_comparsion = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/apartment_comparsion_active.svg');
      $vars['button_comparsion'] = $img_comparsion . '<p class="s-label-small color-dark_gray">Добавлена в сравнение</p>';
    }
    else {
      $img_comparsion = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/apartment_comparsion.svg');
      $vars['button_comparsion'] = '<div class="apartment-comparison pa" data-page="1" data-node-id="' .
        $node_apartment->nid . '">' . $img_comparsion . '<p class="s-label-small">Добавить в сравнение</p></div>';
    }

  // Кнопка Получить документы
  $vars['img_pdf'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/apartment_pdf.svg');

  // Получение логотипа Жилого комплекса
  $logo = theme('image', array(
    'path' => $node_complex->field_complex_logo['und'][0]['uri'],
    'title' => $node_complex->field_complex_logo['und'][0]['title'],
    'alt' => $node_complex->field_complex_logo['und'][0]['alt'],
  ));

  $vars['complex_logo'] = l($logo, 'node/' . $node_complex->nid,
    array(
      'html' => TRUE,
      'attributes' => array('target'=>'_blank')

    )
  );

  // Построение пунктов меню
  $menu_items = array(
    0 => array(
      'path' => l(t('о квартире'), 'node/' .$node_apartment->nid),
      'title' => 'node',
    ),
    1 => array(
      'path' => l('расположение', 'apartment/' . $node_apartment->nid . '/plan'),
      'title' => 'plan',
    ),
    2 => array(
      'path' => l(t('визуализация'), 'apartment/' . $node_apartment->nid . '/visualization'),
      'title' => 'visualization',
    ),
    3 => array(
      'path' => l(t('условия покупки'), 'apartment/' . $node_apartment->nid . '/purchase_terms'),
      'title' => 'purchase_terms',
    ),
    4 => array(
      'path' => l(t('ипотека'), 'apartment/' . $node_apartment->nid . '/mortgage'),
      'title' => 'mortgage',
    ),/*
    5 => array(
      'path' => l(t('Документы'), 'apartment/' . $node_apartment->nid . '/documents'),
      'title' => 'documents',
    ),*/
  );
  if(empty($node_apartment->field_apartment_vizual)) {
    unset($menu_items[2]);
  }

  // Выделение активного пункта меню
  arg(2) == NULL ? $url = arg(0): $url = arg(2);
  foreach ($menu_items as $key => $item) {
    if ($url == $item['title']) {
      $vars['menu'][$key] = '<li class="active">' . $item['path'] . '</li>';
      $vars['page'] = $item['path'];
    }
    else {
      $vars['menu'][$key] = '<li>' . $item['path'] . '</li>';
    }
  }

}