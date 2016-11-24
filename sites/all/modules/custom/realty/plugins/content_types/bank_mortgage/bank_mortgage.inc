<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_bank_mortgage_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Bank mortgage'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_bank_mortgage_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_bank_mortgage_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_bank_mortgage');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_bank_mortgage_content_type_theme(&$theme, $plugin) {
  $theme['realty_bank_mortgage'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-bank-mortgage',
  );
}


/**
 * Process variables for realty-info-complex.tpl.php.
 */
function template_preprocess_realty_bank_mortgage(&$vars) {

  $a=1;

  if (isset($_GET['p'])) {
    $vars['bank_active'] = TRUE;
  }

  // Если это главная страница Ипотеки
  if (arg(1) == 'city') {
    // То выводим заголок Ипотеки
    $vars['wrapper'] = TRUE;

    $vars['cityId'] = arg(2);

    $vars['bank_list'] = views_embed_view('term_view', 'bank_list', 'all', $vars['cityId']);
  }
  else {
    // Иначе не выводим заголовок
    $vars['wrapper'] = FALSE;
    $vars['cityId'] = FALSE;

    // Если это страница Квартиры
    if (arg(0) == 'apartment') {
      $nid = arg(1);

      $apartment_info = realty_get_info_apartment($nid);

      $node_complex = node_load($apartment_info['complex_nid']);

      // Формирование списка ипотечных программ действующих в жилом комплексе
      foreach ($node_complex->field_complex_morgage['und'] as $mortgage) {
        $mortgages = isset($mortgages) ?  $mortgages . '+' . $mortgage['target_id'] : $mortgage['target_id'];
      }

      if (!empty($mortgages)) {
        $vars['bank_list'] = views_embed_view('field_collection', 'current_mortgage', $mortgages);
      }

      $vars['background'] = '/' . realty_file_directory_path() . '/' . $node_complex->field_main_photo[LANGUAGE_NONE][0]['filename'];
      $vars['apt_id'] = $nid;
    }
    // Если это страница жилого комплекса
    if (arg(0) == 'complexes') {
      $nid = arg(1);

      $node_complex = node_load($nid);

      // Формирование списка ипотечных программ действующих в жилом комплексе
      foreach ($node_complex->field_complex_morgage['und'] as $mortgage) {
        $mortgages = isset($mortgages) ?  $mortgages . '+' . $mortgage['target_id'] : $mortgage['target_id'];
      }

      if (!empty($mortgages)) {
        $vars['bank_list'] = views_embed_view('field_collection', 'current_mortgage', $mortgages);
      }

      $vars['background'] = '/' . realty_file_directory_path() . '/' . $node_complex->field_main_photo[LANGUAGE_NONE][0]['filename'];
    }
  }

  $file = REALTY_FRONT_THEME_PATH . '/images/cmp_hover.svg';
  $vars['img_hover'] = file_get_contents($file);

  drupal_add_library('system', 'jquery.form');
  drupal_add_library('system', 'drupal.ajax');
}