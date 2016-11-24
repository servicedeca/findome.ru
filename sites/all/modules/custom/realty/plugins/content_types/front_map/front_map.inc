<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_front_map_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Front_map'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_front_map_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_front_map_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_front_map');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_front_map_content_type_theme(&$theme, $plugin) {
  $theme['realty_front_map'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-front-map',
  );
}

/**
 * Process variables for realty-front-map.tpl.php.
 */
function template_preprocess_realty_front_map(&$vars) {

  $city = menu_get_object('taxonomy_term', 2);

  $vars['image_map'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/minihome.png',
    'attributes' => array(
      'class' => array('minihome'),
    ),
  ));

  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));

  $complex = views_get_view_result('complex', 'random_complex');

  if (!empty($complex)) {
    $vars['title'] =  $complex[0]->node_title;

    if (!empty($complex[0]->field_field_main_photo)) {
      $vars['image'] =  theme('image', array(
        'path' => $complex[0]->field_field_main_photo[0]['raw']['uri'],
        'title' => $complex[0]->node_title,
        'alt' => $complex[0]->node_title,
        'attributes' => array(
          'class' => array('title-image'),
        ),
      ));
    }

    if (!empty($complex[0]->field_field_complex_logo)) {
      $logo =  theme('image', array(
        'path' => $complex[0]->field_field_complex_logo[0]['raw']['uri'],
        'title' => $complex[0]->node_title,
        'alt' => $complex[0]->node_title,
        'attributes' => array(
          'class' => array('logo-c'),
        ),
      ));

      $vars['logo'] = l($logo, 'node/' . $complex[0]->nid,
        array(
          'html' => TRUE,
          'attributes' => array(
            'class' => array (
              'col-xs-12 half-item zero-padding',
            )
          )
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
        'modal_id' => 'modal-map-area',
        'checkbox_id' => 'CheckboxMapArea',
        'text' => t('Выберите район'),
        'options' => realty_get_options_current_city('area')
      )
    );

    $vars['modal'] .= theme('realty_modal_search_form', array(
        'std' => 'std',
        'modal_id' => 'modal-map-developer',
        'checkbox_id' => 'CheckboxMapDeveloper',
        'text' => t('Выберите застройщика'),
        'options' => realty_get_developer_current_city()
      )
    );

    $vars['modal'] .= theme('realty_modal_search_form', array(
        'std' => 'std',
        'modal_id' => 'modal-map-complex',
        'checkbox_id' => 'CheckboxMapComplex',
        'text' => t('Выберите жилой комплекс'),
        'options' => realty_get_complex_current_city(null, $city->tid)
      )
    );

    $vars['modal'] .= theme('realty_modal_search_form', array(
        'std' => 'category',
        'modal_id' => 'modal-map-category',
        'checkbox_id' => 'CheckboxMapCategory',
        'text' => t('Выберите категорию'),
        'options' => $categories,
      )
    );

    $vars['search_map_form'] = drupal_get_form('realty_search_map_form');

    unset($vars['search_map_form']['category']['#title']);

    if (!empty($complex[0]->_field_data['nid']['entity']->field_slogan)) {
      $vars['description'] = $complex[0]->_field_data['nid']['entity']->field_slogan['und'][0]['safe_value'];
    }

    $vars['details'] = l(t('Перейти'), 'node/' . $complex[0]->nid, array('attributes' =>
      array('class' => array(
        'button-info', 'button-info-top')
        )
      )
    );
  }
  $vars['city_tid'] = $city->tid;

  $view = views_embed_view('map', 'map_city');

  $vars['map'] = $view;

}