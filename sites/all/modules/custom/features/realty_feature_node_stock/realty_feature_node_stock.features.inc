<?php
/**
 * @file
 * realty_feature_node_stock.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function realty_feature_node_stock_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function realty_feature_node_stock_node_info() {
  $items = array(
    'stock' => array(
      'name' => t('Акции'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
