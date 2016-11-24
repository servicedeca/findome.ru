<?php
/**
 * @file
 * realty_features_node_complex.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function realty_features_node_complex_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function realty_features_node_complex_node_info() {
  $items = array(
    'complex' => array(
      'name' => t('Жилой комплекс'),
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
