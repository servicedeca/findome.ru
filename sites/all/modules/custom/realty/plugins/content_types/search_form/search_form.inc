<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_search_form_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Search form'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_search_form_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_search_form_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_search_form');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_search_form_content_type_theme(&$theme, $plugin) {
  $theme['realty_search_form'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-search-form',
  );
}

/**
 * Process variables for realty-search-form.tpl.php.
 */
function template_preprocess_realty_search_form(&$vars) {

  $search_form = drupal_get_form('realty_filter_form');

  $vars['filters'] = theme ('realty_main_search_form');

  $vars['search_form'] = drupal_render($search_form);

  $result = views_get_view_result('news', 'information_form_search');

  if ($result[0]) {
    $image_path = $result[0]->field_field_image_news[0]['raw']['uri'];
    $vars['title'] = $result[0]->node_title;
    if (!empty($image_path)) {
      $vars['image'] =  theme('image', array(
          'path' => $image_path,
          'attributes' => array(
            'class' => array('photo', 'h75'),
          ),
        )
      );
    }
  }

  $material_terms = taxonomy_get_tree(12);
  foreach ($material_terms as $key => $material_term) {
    $material_term_full[] = taxonomy_term_load($material_term->tid);

    $materials[$material_term_full[$key]->tid]['name'] = $material_term_full[$key]->name;
    $materials[$material_term_full[$key]->tid]['description'] = $material_term_full[$key]->description;
    $materials[$material_term_full[$key]->tid]['image'] = theme('image', array(
        'path' => $material_term_full[$key]->field_material_image['und'][0]['uri'],
      )
    );
  }

  $category_terms = taxonomy_get_tree(9);
  foreach ($category_terms as $key => $category_term) {
    $category_term_full[] = taxonomy_term_load($category_term->tid);

    $categories[$category_term_full[$key]->tid]['name'] = $category_term_full[$key]->name;
    $categories[$category_term_full[$key]->tid]['description'] = $category_term_full[$key]->description;
    $categories[$category_term_full[$key]->tid]['image'] = theme('image', array(
        'path' => $category_term_full[$key]->field_category_image['und'][0]['uri'],
      )
    );
  }


  $vars['modal'] = theme('realty_modal_search_form', array(
      'std' => 'std',
      'modal_id' => 'modal_area',
      'checkbox_id' => 'CheckboxArea',
      'text' => t('Выберите район'),
      'options' => realty_get_options_current_city('area')
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'slider',
      'modal_id' => 'modal_floor',
      'class' => 'floor',
      'text' => 'Этаж'
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'std',
      'modal_id' => 'modal_developer',
      'checkbox_id' => 'CheckboxDeveloper',
      'text' => t('Выберите застройщика'),
      'options' => realty_get_developer_current_city()
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'std',
      'modal_id' => 'modal_complex',
      'checkbox_id' => 'CheckboxComplex',
      'text' => t('Выберите жилой комплекс'),
      'options' => realty_get_complex_current_city()
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'category',
      'modal_id' => 'modal_category',
      'checkbox_id' => 'CheckboxCategory',
      'text' => t('Выберите категорию'),
      'options' => $categories,
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'type',
      'modal_id' => 'modal_type',
      'checkbox_id' => 'CheckboxRoom',
      'text' => t('Выберите количество комнат'),
      'options' =>  realty_options_search('room'),
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'material',
      'modal_id' => 'modal_material',
      'checkbox_id' => 'CheckboxMaterial',
      'text' => t('Выберите материал стен'),
      'options' =>  $materials,
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'std',
      'modal_id' => 'modal_metro',
      'checkbox_id' => 'CheckboxMetro',
      'text' => t('Выберите станцию метро'),
      'options' =>  realty_get_options_current_city('metro'),
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'std',
      'modal_id' => 'modal_balkon',
      'checkbox_id' => 'CheckboxBalkon',
      'text' => t('Выберите балкон или лоджию'),
      'options' => array(
        1 => 'Балкон',
        2 => 'Лоджия',
        3 => 'Балкон + Лоджия'
      )
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
    'std' => 'deadline',
    'modal_id' => 'modal_deadline',
    'checkbox_id' => 'CheckboxDeadline',
    'text' => t('Срок сдачи'),
    'options' => realty_get_years_range(),
  ));

}