<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_developer_menu_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Menu developer'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_developer_menu_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_developer_menu_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_developer_menu');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_developer_menu_content_type_theme(&$theme, $plugin) {
  $theme['realty_developer_menu'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-developer-menu',
  );
}

/**
 * Process variables for realty-menu-complex.tpl.php.
 */
function template_preprocess_realty_developer_menu(&$vars) {
  $entity = arg(1);
  if ($entity == 'term') {
    $term = menu_get_object('taxonomy_term', 2);
  }
  else {
    $term = taxonomy_term_load($entity);
    $url = arg(2);
  }

  $menu_items = array(
    0 => array(
      'path' => l(t('о застройщике'), 'taxonomy/term/' . $term->tid),
      'title' => $term->tid,
    ),
    1 => array(
      'path' => l(t('объекты'), 'developer/' . $term->tid . '/complexes'),
      'title' => 'complexes',
    ),
    2 => array(
      'path' => l(t('галерея'), 'developer/' . $term->tid . '/gallery'),
      'title' => 'gallery',
    ),
    3 => array(
      'path' => l(t('акции'), 'developer/' . $term->tid . '/stock'),
      'title' => 'stock',
    ),
    4 => array(
      'path' => l(t('отзывы'), 'developer/' . $term->tid . '/reviews'),
      'title' => 'reviews',
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

  $vars['developer_name'] = $term->name;

  $vars['name'] = l($term->name, 'taxonomy/term/' . $term->tid, array(
    'attributes' => array(
      'class' => array('active-complex'),
    ),
  ));

  $img = theme('image', array(
    'path' => $term->field_developer_logo[LANGUAGE_NONE][0]['uri'],
    'attributes' => array(
      'class' => array('complex-logo', 'developer-logo'),
    ),
  ));

  $vars['logo'] = l($img, 'taxonomy/term/' . $term->tid, array(
      'html' => TRUE,
      'attributes' => array(
        'class' => array('col-xs-3 complex-logo'),
      )
    )
  );

  $img_booking = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/apartment_booking.svg');
  $vars['button_booking'] = '<div class="col-xs-4 ap-button button-newcomplex-fix" data-toggle="modal" data-target=".modal_free" rel="tooltip" data-placement="left" title="Заявка отправляется в отдел продаж застройщика. Специалист отдела продаж застройщика свяжется с Вами по указанному в заявке телефону и ответит на все Ваши вопросы.">' .
    $img_booking . '<p class="s-label-small">Связаться с застройщиком</p></div>';

  $vars['img_close'] = realty_get_image_close();

  $vars['booking_form'] = drupal_get_form('realty_booking_apartment_form', NULL, $term);

  $vars['img_question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question.svg',
    'attributes' => array(
      'class' => array('rating-question'),
      'rel' => array('tooltip'),
      'data-placement' => array('right'),
      'title' => array('Рейтинг складывается из средней оценки застройщика'),
    )
  ));

  $vars['img_starz'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/starz.svg',
  ));

  $vars['developer_tid'] = $term->tid;

  $vars['rating_value'] = (float)$term->field_developer_rating_ass_value['und'][0]['value'];
}
