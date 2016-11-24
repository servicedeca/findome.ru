<?php
/**
 * @file
 * realty_faeture_page_taxonomy.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function realty_faeture_page_taxonomy_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
