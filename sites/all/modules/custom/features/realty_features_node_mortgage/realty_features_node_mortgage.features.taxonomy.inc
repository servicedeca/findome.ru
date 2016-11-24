<?php
/**
 * @file
 * realty_features_node_mortgage.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function realty_features_node_mortgage_taxonomy_default_vocabularies() {
  return array(
    'banks' => array(
      'name' => 'Банки',
      'machine_name' => 'banks',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
