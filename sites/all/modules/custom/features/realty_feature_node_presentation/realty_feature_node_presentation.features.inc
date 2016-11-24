<?php
/**
 * @file
 * realty_feature_node_presentation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function realty_feature_node_presentation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function realty_feature_node_presentation_node_info() {
  $items = array(
    'presentation' => array(
      'name' => t('Презентация'),
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
