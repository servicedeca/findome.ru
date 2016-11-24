<?php
/**
 * @file
 * realty_feature_user_field.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function realty_feature_user_field_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
