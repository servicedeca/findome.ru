<?php
/**
 * @file
 * realty_feature_page_comparison.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function realty_feature_page_comparison_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
