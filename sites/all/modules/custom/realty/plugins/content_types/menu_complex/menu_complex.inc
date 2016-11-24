<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_menu_complex_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Menu complex'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_menu_complex_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_menu_complex_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_menu_complex');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_menu_complex_content_type_theme(&$theme, $plugin) {
  $theme['realty_menu_complex'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-menu-complex',
  );
}

/**
 * Process variables for realty-menu-complex.tpl.php.
 */
function template_preprocess_realty_menu_complex(&$vars) {
  $nid = arg(1);
  $node = node_load($nid);

  $entity_rating_id = $node->field_complex_rating['und'][0]['value'];
  $entity_rating = entity_load('field_collection_item', array($entity_rating_id));

  $vars['rating_value'] = $node->field_complex_rating_val['und'][0]['value'] != '' ?
      $node->field_complex_rating_val['und'][0]['value'] : 0;

  $dev_tid = $node->field_complex_developer['und'][0]['tid'];
  $developer = taxonomy_term_load($dev_tid);
  $city_tid = $developer->field_city[LANGUAGE_NONE][0]['tid'];
  $city = taxonomy_term_load($city_tid);
  $vars['complex_title'] = $node->title;
  $vars['city'] = l($city->name, 'taxonomy/term/' . $city->tid);
  $vars['complex_nid'] =  $node->nid;
  $vars['complex'] = l($node->title, 'node/' . $node->nid);
  $vars['title_complex'] = l($node->title, 'node/' . $node->nid, array('attributes' => array('class' => array('active-complex'))));
  if (!empty($node->field_complex_logo)) {
    $vars['complex_mini_logo'] = theme('image', array(
      'path' => $node->field_complex_logo[LANGUAGE_NONE][0]['uri'],
      'alt' => $node->title,
      'title' => $node->title,
      //'attributes' => array(
      //  'class' => array('complex-logo'),
      //),
    ));
  }

  $img_booking = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/apartment_booking.svg');
  $vars['button_booking'] = '<div class="col-xs-4 ap-button button-newcomplex-fix" data-toggle="modal" data-target=".modal_free" rel="tooltip" data-placement="left" title="Заявка отправляется в отдел продаж застройщика. Специалист отдела продаж застройщика свяжется с Вами по указанному в заявке телефону и ответит на все Ваши вопросы.">' .
    $img_booking . '<p class="s-label-small">Связаться с застройщиком</p></div>';

  $vars['img_close'] = realty_get_image_close();
  if(realty_limit_booking_apartment($nid)) {
    $vars['booking_form'] = drupal_get_form('realty_booking_apartment_form', $node);
  }
  else {
    $vars['booking_form'] = '<div class="col-xs-12 text-center"><p>' .
      t('Лимит заявок по данному ЖК исчерпан. Вы можете повторно отправить заявку по истечении 24 часов.') .
      '</p></div>';
  }

  $vars['img_starz'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/starz.svg',
  ));

  $vars['img_question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question.svg',
    'attributes' => array(
      'class' => array('rating-question'),
      'rel' => array('tooltip'),
      'data-placement' => array('right'),
      'title' => array('Рейтинг ЖК складывается из множества показателей. Для подробного описания перейдите на страницу рейтинга.'),
    )
  ));

  $img = theme('image', array(
    'path' => $node->field_complex_logo[LANGUAGE_NONE][0]['uri'],
    'alt' => $node->title,
    'title' => $node->title,
  ));

  $vars['logo'] = l($img, 'node/' . $node->nid, array(
      'html' => TRUE,
      'attributes' => array(
        'class' => array('col-xs-3 complex-logo'),
      )
    )
  );

  $vars['plan'] =  l(t('Посмотреть планировки'), 'complexes/' . $node->nid . '/plan', array (
    'attributes' => array (
      'class' => array('active-plans'))));

  $menu_items = array(
    0 => array(
      'path' => l(t('об объекте'), 'node/' .$node->nid),
      'title' => 'node',
    ),
    1 => array(
      'path' => l(t('планировки'), 'complexes/' . $node->nid . '/plan'),
      'title' => 'plan',
    ),
    2 => array(
      'path' => l(t('Gallery'), 'complexes/' . $node->nid . '/gallery'),
      'title' => 'gallery',
    ),
    3 => array(
      'path' => l(t('Ипотека'), 'complexes/' . $node->nid . '/mortgage'),
      'title' => 'mortgage',
    ),
    4 => array(
      'path' => l(t('Stock'), 'complexes/' . $node->nid . '/stock'),
      'title' => 'stock',
    ),
    5 => array(
      'path' => l(t('Отзывы'), 'complexes/' . $node->nid . '/reviews'),
      'title' => 'reviews',
    ),
    6 => array(
      'path' => l(t('Рейтинг'), 'complexes/' . $node->nid . '/rating'),
      'title' => 'rating',
    ),
  );

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

  $vars['complex_id'] = $node->nid;
}