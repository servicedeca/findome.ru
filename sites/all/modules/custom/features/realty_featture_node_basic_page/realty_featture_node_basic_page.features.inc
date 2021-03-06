<?php
/**
 * @file
 * realty_featture_node_basic_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function realty_featture_node_basic_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function realty_featture_node_basic_page_node_info() {
  $items = array(
    'basic_page' => array(
      'name' => t('Страница'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
