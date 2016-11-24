<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_plan_complex_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Plan complex'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_plan_complex_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_plan_complex_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_plan_complex');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_plan_complex_content_type_theme(&$theme, $plugin) {
  $theme['realty_plan_complex'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-plan-complex',
  );
}

/**
 * Process variables for realty-info-complex.tpl.php.
 */
function template_preprocess_realty_plan_complex(&$vars) {

  switch (arg(0)) {

    // Если запрашиваемая страница из раздела Квартира
    case 'apartment' :
    {

      $vars['plan'] = TRUE;

      $nid = arg(1);
      $node_apartment = node_load($nid);

      $apartment_info = realty_get_info_apartment($nid);
      $vars['complex_id'] = $apartment_info['complex_nid'];

      $node_complex = node_load($apartment_info['complex_nid']);

      if (!empty($node_complex->field_plan_complex)) {
        $file = realty_file_directory_path() . '/' . $node_complex->field_plan_complex[LANGUAGE_NONE][0]['filename'];
        $vars['complex_plan'] = file_get_contents($file);
      }

      drupal_add_js(array(
        'apartment_plan_callback' => TRUE,
        'current_home_id' => $apartment_info['home_nid'],
        'current_section_id' => $node_apartment->field_section[LANGUAGE_NONE][0]['value'],
        'current_floor_value' => $node_apartment->field_apartment_floor[LANGUAGE_NONE][0]['value'],
        'current_apartment_id' => $node_apartment->nid
      ), 'setting');

      $vars['modal'] = theme('realty_apartment_modal', array('plan' => TRUE ));

      $file = REALTY_FRONT_THEME_PATH . '/images/cmp_hover.svg';
      $vars['img_hover'] = file_get_contents($file);

      $vars['background'] = '/' . realty_file_directory_path() . '/' . $node_complex->field_main_photo[LANGUAGE_NONE][0]['filename'];

      $vars['map'] = views_embed_view('map', 'map_complex', $node_complex->nid);

      break;
    }

    // Если запрашиваемая страница из раздела Жилой комплекс
    case 'complexes': {

      // Это страница планировки
      $vars['plan'] = TRUE;

      $nid = arg(1);
      $node = node_load($nid);
      $vars['complex_id'] = $nid;
      if (!empty($node->field_plan_complex)) {
        $file = realty_file_directory_path() . '/' . $node->field_plan_complex[LANGUAGE_NONE][0]['filename'];
        $vars['complex_plan'] = file_get_contents($file);
      }
      else {
        $home_tid = realty_get_home_complex($node->nid);
        drupal_add_js(array(
          'complex_plan_none' => TRUE,
          'home_tid' => $home_tid[0]->tid
        ), 'setting');
      }

      $vars['modal'] = theme('realty_apartment_modal', array('plan' => TRUE ));

      $file = REALTY_FRONT_THEME_PATH . '/images/cmp_hover.svg';
      $vars['img_hover'] = file_get_contents($file);

      $vars['background'] = '/' . realty_file_directory_path() . '/' . $node->field_main_photo[LANGUAGE_NONE][0]['filename'];

      $vars['map'] = views_embed_view('map', 'map_complex', $nid);

      break;
    }
    case 'node': {

      // Это не страница планировки
      $vars['plan'] = FALSE;

      $nid = arg(1);
      $node = node_load($nid);
      $vars['complex_id'] = $nid;
      if (!empty($node->field_plan_complex)) {
        $file = realty_file_directory_path() . '/' . $node->field_plan_complex[LANGUAGE_NONE][0]['filename'];
        $vars['complex_plan'] = file_get_contents($file);
      }
      else {
        $home_tid = realty_get_home_complex($node->nid);
        drupal_add_js(array(
          'complex_plan_none' => TRUE,
          'home_tid' => $home_tid[0]->tid
        ), 'setting');
      }

      $vars['modal'] = theme('realty_apartment_modal', array('plan' => TRUE ));

      $file = REALTY_FRONT_THEME_PATH . '/images/cmp_hover.svg';
      $vars['img_hover'] = file_get_contents($file);

      $vars['background'] = '/' . realty_file_directory_path() . '/' . $node->field_main_photo[LANGUAGE_NONE][0]['filename'];

      break;
    }
  }

  $vars['img_legend'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/area-legend.svg',
  ));

}
