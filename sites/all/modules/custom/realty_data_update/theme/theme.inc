<?php

/**
 * Process variables for realty-mortgage-request-user.tpl.php
 */
function realty_preprocess_realty_data_update_logs(&$vars) {

  $form_filter = drupal_get_form('realty_data_update_logs_filter_form',array(
    'timestamp_from' => $vars['timestamp_from'],
    'timestamp_to' => $vars['timestamp_to'],
    'developers_list' => $vars['developers_list'],
    'developers_filter' => $vars['developers_filter'])
  );

  $vars['filters'] = drupal_render($form_filter);
  $vars['log_periods'] = $vars['apartments'];
}

/**
 * Process variables for realty-data-update-files.tpl.php
 */
function realty_data_update_preprocess_realty_data_update_files(&$vars) {

}

/**
 * Process variables for realty-data-update-new-apartments.tpl.php
 */
function realty_data_update_preprocess_realty_data_update_new_apartments(&$vars) {

  $vars['form'] = drupal_get_form('realty_data_update_update_list_new_apartments');
  $vars['form_clear'] = drupal_get_form('realty_data_update_clear_list_new_apartments_form');
}