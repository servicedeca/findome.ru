<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_search_search_form_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Search search form'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_search_search_form_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_search_search_form_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_search_search_form');

  drupal_add_js(array('get' => $_GET), 'setting');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_search_search_form_content_type_theme(&$theme, $plugin) {
  $theme['realty_search_search_form'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-search-search-form',
  );
}

/**
 * Process variables for realty-search-form.tpl.php.
 */
function template_preprocess_realty_search_search_form(&$vars) {
  drupal_add_js(REALTY_FRONT_THEME_PATH . '/js/realty_search_form.js');
  $result = views_get_view_result('news', 'information_form_search');

  if ($result[0]) {
    $vars['image_path'] = '/' . realty_file_directory_path() . '/' . $result[0]->field_field_image_news[0]['raw']['filename'];
    $logo_path = $result[0]->field_field_news_logo[0]['raw']['uri'];
    $vars['title'] = $result[0]->node_title;
    if (!empty($logo_path)) {
      $vars['news_logo'] =  theme('image', array(
          'path' => $logo_path,
          'attributes' => array(
            'class' => array('logo-z'),
          ),
        )
      );;
    }
      $vars['details'] = l(t('Details'), 'node/' . $result[0]->nid, array('attributes' => array('class' => 'button-info')));
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

  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.svg',
    'title' => t('Plus'),
  ));

  $vars['img_plus'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/plus2.svg',
    'title' => t('Plus'),
  ));

  $areas_array = views_get_view_result('search', 'search_area', arg(1));

  foreach ($areas_array as $area) {
    $areas[$area->tid] = $area->taxonomy_term_data_name;
  }

  $metro_array = views_get_view_result('search', 'search_metro', arg(1));

  foreach ($metro_array as $metro) {
    $metros[$metro->tid] = $metro->taxonomy_term_data_name;
  }

  $type = realty_options_search('room');
  $masonry = realty_options_search('masonry');

  $developers_by_city = realty_get_developer_current_city();
  $complexes_by_city = realty_get_complex_current_city();

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

  $balcony = realty_options_search('balcony');

  $vars['modal'] = theme('realty_modal_search_form', array(
    'std' => 'slider',
    'modal_id' => 'modal_slider_sq',
    'class' => 'sq',
    'text' => 'Площадь, м<sup>2</sup>',
    'submit' => TRUE,
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'slider',
      'modal_id' => 'modal_slider_price',
      'class' => 'price',
      'text' => 'Цена, за м<sup>2</sup> тыс.руб.',
      'submit' => TRUE,
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'slider',
      'modal_id' => 'modal_slider_cost',
      'class' => 'coast',
      'text' => 'Стоимость, млн.руб.',
      'submit' => TRUE,
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'slider',
      'modal_id' => 'modal_slider_ceiling',
      'class' => 'ceiling',
      'text' => 'Высота потолка, м',
      'submit' => TRUE,
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'std',
      'modal_id' => 'modal_area',
      'class' => 'CheckboxArea',
      'checkbox_id' => 'CheckboxArea',
      'text' => 'Район',
      'options' => $areas,
      'submit' => TRUE,
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'std',
      'modal_id' => 'modal_developer',
      'class' => 'CheckboxDeveloper',
      'checkbox_id' => 'CheckboxDeveloper',
      'text' => 'Застройщик',
      'options' => $developers_by_city,
      'submit' => TRUE,
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'std',
      'modal_id' => 'modal_complex',
      'class' => 'CheckboxComplex',
      'checkbox_id' => 'CheckboxComplex',
      'text' => 'Жилой комплекс',
      'options' => $complexes_by_city,
      'submit' => TRUE,
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'type',
      'modal_id' => 'modal_type',
      'class' => 'CheckboxRoom',
      'checkbox_id' => 'CheckboxRoom',
      'text' => 'Количество комнат',
      'options' => $type,
      'submit' => TRUE,
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'slider',
      'modal_id' => 'modal_floor',
      'class' => 'floor',
      'text' => 'Этаж',
      'submit' => TRUE,
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'material',
      'modal_id' => 'modal_material',
      'checkbox_id' => 'CheckboxMaterial',
      'text' => 'Материал стен',
      'options' => $materials,
      'submit' => TRUE,
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'category',
      'modal_id' => 'modal_category',
      'checkbox_id' => 'CheckboxCategory',
      'text' => 'Категория',
      'options' => $categories,
      'submit' => TRUE,
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
    'std' => 'deadline',
    'modal_id' => 'modal_deadline',
    'checkbox_id' => 'CheckboxDeadline',
    'text' => t('Срок сдачи'),
    'options' => realty_get_years_range(),
    'submit' => TRUE,
  ));

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'balcony',
      'modal_id' => 'modal_balcony',
      'text' => 'Балкон',
      'options' => $balcony,
      'submit' => TRUE,
    )
  );

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'std',
      'modal_id' => 'modal_metro',
      'class' => 'CheckboxMetro',
      'text' => 'Метро',
      'options' => $metros,
      'submit' => TRUE,
    )
  );

}