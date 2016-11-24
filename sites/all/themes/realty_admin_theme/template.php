<?php

/**
 * Preprocess variables for node.
 */
function realty_admin_theme_preprocess_node(&$vars, $hook) {
  $node = $vars['node'];
  $view_mode = $vars['view_mode'];

  $vars['theme_hook_suggestions'][] = 'node__' . $view_mode;
  $vars['theme_hook_suggestions'][] = 'node__' . $node->type . '_' . str_replace('-', '_', $view_mode);

  $preprocesses[] = 'realty_admin_theme_preprocess_node__' . $view_mode;
  $preprocesses[] = 'realty_admin_theme_preprocess_node__' . $node->type;
  $preprocesses[] = 'realty_admin_theme_preprocess_node__' . $node->type . '_' . str_replace('-', '_', $view_mode);

  foreach ($preprocesses as $preprocess) {
    if (function_exists($preprocess)) {
      $preprocess($vars, $hook);
    }
  }
}

/**
 * Process variables for views-exposed-form.tpl.php.
 */
function realty_admin_theme_preprocess_views_exposed_form(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'realty_admin_theme_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view.tpl.php.
 */
function realty_admin_theme_preprocess_views_view(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'realty_admin_theme_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-unformatted.tpl.php.
 */
function realty_admin_theme_preprocess_views_view_unformatted(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'realty_admin_theme_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-fields.tpl.php.
 */
function realty_admin_theme_preprocess_views_view_fields(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'realty_admin_theme_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-grid.tpl.php.
 */
function realty_admin_theme_preprocess_views_view_grid(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'realty_admin_theme_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-table.tpl.php.
 */
function realty_admin_theme_preprocess_views_view_table(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'realty_admin_theme_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}



/**
 * Preprocess for views-view-unformatted--booking-mortgage-admin--bookings-admin.tpl.php
 */
function realty_admin_theme_preprocess_views_view_unformatted__booking_mortgage_admin__bookings_admin(&$vars) {

  if(!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $key => $val) {
      $vars['bookings'][] = array(
        'id' => $val->nid,
        'date' => date("Y-m-d H:i:s", $val->node_created),
        'name' => $val->field_field_booking_name[0]['rendered']['#markup'],
        'user_name' => l($val->field_field_user_name[0]['rendered']['#markup'], 'user/' . $val->users_field_data_field_booking_user_uid),
        'number_apartment' => l($val->field_field_number_apartament[0]['rendered']['#markup'], 'node/' . $val->node_field_data_field_booking_apartment_nid),
        'complex' => l($val->node_field_data_field_home_complex_title, 'node/' . $val->node_field_data_field_home_complex_nid),
        'manager' => $val->field_field_booking_manager[0]['rendered']['#markup'],
      );
    }
  }

}

/**
 * Preprocess for views-view-unformatted--booking-mortgage-admin--mortgage-admin.tpl.php
 */
function realty_admin_theme_preprocess_views_view_unformatted__booking_mortgage_admin__mortgage_admin(&$vars) {

  foreach ($vars['view']->result as $mortgage) {
    $vars['mortgages'][$mortgage->nid] = array (
      'title' => $mortgage->node_title . ' ' . $mortgage->nid,
      'date' => format_date($mortgage->node_created, 'medium', 'Y-m-d H:i:s'),
      'username' => l($mortgage->field_field_user_name[0]['rendered']['#markup'], 'user/' . $mortgage->users_field_data_field_user_uid),
      'full name' => $mortgage->field_field_full_name[0]['rendered']['#markup'],
      'bank' => $mortgage->field_field_bank[0]['rendered']['#title'],
      'affiliate' => $mortgage->field_field_mortgage_bank_affiliate[0]['rendered']['#markup'],
      'mortgage' => $mortgage->field_field_mortgage_name[0]['rendered']['#markup'],
      'amount' => $mortgage->field_field_required_amount[0]['rendered']['#markup'],
    );
  }
}