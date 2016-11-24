<?php
/**
 * @file
 * realty_node_apartment.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function realty_node_apartment_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function realty_node_apartment_node_info() {
  $items = array(
    'apartament' => array(
      'name' => t('Квартира'),
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
