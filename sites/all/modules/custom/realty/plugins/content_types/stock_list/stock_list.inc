<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_stock_list_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Stock list'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_stock_list_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_stock_list_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_stock_list');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_stock_list_content_type_theme(&$theme, $plugin) {
  $theme['realty_stock_list'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-stock-list',
  );
}

/**
 * Process variables for realty-block-stock.tpl.php.
 */
function template_preprocess_realty_stock_list(&$vars) {

  $page = arg(0);

  switch ($page) {
    case 'complexes': {
      $complex_nid = arg(1);

      $vars['stock'] = views_embed_view('stock', 'stock_complex', $complex_nid);

      $node = node_load($complex_nid);
      $vars['background'] = '/' . realty_file_directory_path() . '/' . $node->field_main_photo[LANGUAGE_NONE][0]['filename'];

      break;
    }
    case 'developer': {
      $developer_tid = arg(1);

      $vars['stock'] = views_embed_view('stock', 'stock_developer', $developer_tid);

      $complexes = views_get_view_result('complex', 'complex_developers', $developer_tid);

      $index = rand (0, count($complexes) - 1);
      $vars['background'] = '/' . realty_file_directory_path() . '/' . $complexes[$index]->field_field_main_photo[0]['raw']['filename'];

      break;
    }
  }
}