<?php
/**
 * @file
 * Ctools content type
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_apartment_complex_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Apartment complex'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_apartment_complex_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_apartment_complex_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $block->content = theme('realty_apartment_complex');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_apartment_complex_content_type_theme(&$theme, $plugin) {
  $theme['realty_apartment_complex'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-apartment-complex',
  );
}

/**
 * Process variables for realty-info-complex.tpl.php.
 */
function template_preprocess_realty_apartment_complex(&$vars) {
  drupal_add_js(REALTY_FRONT_THEME_PATH . '/js/realty_apartment_filter.js');

  $nid = arg(1);

  $node = node_load($nid);
  if ($node->type == 'apartament') {
    $apartment_info = realty_get_info_apartment($nid);
    $complex_id = $apartment_info['complex_nid'];

    $vars['view'] = '<div class="container fin zero-padding"><div class="col-xs-12 zero-padding">' .
      views_embed_view('apartments', 'apartment_complex', $complex_id) .
      '</div></div>';
  }
  else {
    $vars['view'] = views_embed_view('apartments', 'apartment_complex');
  }

  $vars['img_flt_add'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/flt_add.svg');
  $vars['img_flt_clear'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/flt_clear.svg');

  $vars['img_close']= realty_get_image_close();

  $vars['img_goto'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/goto.svg',
    'title' => t('Close'),
    )
  );

  $vars['img_lock'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/lock2.svg');
  $vars['img_cross'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/cross.svg');


  $options = realty_get_homes();

  $homes = $options['homes'];
  $sections = $options['sections'];

  $homes_id = array_keys($homes);

  $vars['modals'] = theme('realty_modal_search_form', array(
      'std' => 'type',
      'modal_id' => 'modal_type',
      'checkbox_id' => 'CheckboxRoom',
      'text' => t('Выберите тип'),
      'options' =>  realty_options_search('room'),
      'submit' => TRUE,
    )
  );

  $vars['modals'] .= theme('realty_modal_search_form', array(
      'std' => 'std',
      'modal_id' => 'modal_address',
      'checkbox_id' => 'CheckboxAddress',
      'text' => t('Выберите адрес дома'),
      'options' =>  $homes,
      'submit' => TRUE,
    )
  );

  $vars['modals'] .= theme('realty_modal_search_form', array(
      'std' => 'slider',
      'modal_id' => 'modal_floor',
      'class' => 'floor',
      'text' => 'Выберите этаж',
      'submit' => TRUE,
    )
  );

  $vars['modals'] .= theme('realty_modal_search_form', array(
      'std' => 'slider',
      'modal_id' => 'modal_sq',
      'class' => 'sq',
      'text' => 'Выберите площадь',
      'submit' => TRUE,
    )
  );

  $vars['modals'] .= theme('realty_modal_search_form', array(
      'std' => 'sections',
      'modal_id' => 'modal_section',
      'checkbox_id' => 'CheckboxSection',
      'text' => t('Выберите секцию дома'),
      'options' =>  $options,
      'submit' => TRUE,
    )
  );

  $vars['modal_apartment'] = theme('realty_apartment_modal');

  // Вычисление количества квартир в Жилом комплексе
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node');
  $query->propertyCondition('type', 'apartament');
  $query->propertyCondition('status','1');
  $query->fieldCondition('field_apartament_home', 'tid', $homes_id, 'IN');
  $result = $query->execute();

  $vars['count_apartment'] = count($result['node']);
}