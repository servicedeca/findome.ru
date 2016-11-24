<?php
/**
 * @file
 * realty_features_node_mortgage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function realty_features_node_mortgage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function realty_features_node_mortgage_node_info() {
  $items = array(
    'mortgage' => array(
      'name' => t('Заявки на ипотеку'),
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
