<?php
/**
 * @file
 * realty_feature_page_mortgage_program.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function realty_feature_page_mortgage_program_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
