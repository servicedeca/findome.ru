<?php
/**
 * @file
 * Ctools content type
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_apartment_developer_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Apartment developer'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_apartment_developer_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_apartment_developer_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_apartment_developer');
  $block->content .= theme('realty_apartment_modal');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_apartment_developer_content_type_theme(&$theme, $plugin) {
  $theme['realty_apartment_developer'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-apartment-developer',
  );
}

/**
 * Process variables for realty-info-complex.tpl.php.
 */
function template_preprocess_realty_apartment_developer(&$vars) {
  drupal_add_js(REALTY_FRONT_THEME_PATH . '/js/realty_apartment_filter.js');

  $entity = arg(1);
  if ($entity == 'term') {
    $term_tid = arg(2);
  }
  else {
    $term_tid = $entity;
  }

  $vars['view'] = views_embed_view('apartments', 'apartment_developer', $term_tid);

  $options = realty_get_homes();

  $homes = $options['homes'];
  $sections = $options['sections'];

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

  unset($complex);
  unset($complexes);

  // Получение списка Жилых комплексов у застройщика
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node');
  $query->propertyCondition('type', 'complex');
  $query->fieldCondition('field_complex_developer', 'tid', $term_tid, '=');
  $result = $query->execute();

  foreach ($result['node'] as $complex) {
    $complexes[] = $complex->nid;
  }

  // Получение списка Домов у застройщика
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'taxonomy_term');
  $query->propertyCondition('vid', 6);
  $query->fieldCondition('field_home_complex', 'target_id', $complexes, 'IN');
  $result = $query->execute();

  foreach ($result['taxonomy_term'] as $home) {
    $homes[] = $home->tid;
  }

  // Вычисление количества квартир у Застройщика
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node');
  $query->propertyCondition('type', 'apartament');
  $query->propertyCondition('status','1');
  $query->fieldCondition('field_apartament_home', 'tid', $homes, 'IN');
  $result = $query->execute();

  $vars['count_apartment'] = count($result['node']);

  $vars['img_flt_add'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/flt_add.svg');
  $vars['img_flt_clear'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/flt_clear.svg');
  $vars['img_lock'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/lock2.svg');
  $vars['img_cross'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/cross.svg');
}