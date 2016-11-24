<?php

/**
 * Preprocess for views-view-table--booking-mortgage-admin--bookings-admin.tpl.php
 */

/**
 * Process variables for realty-mortgage-request-user.tpl.php
 */
function realty_admin_preprocess_realty_admin_summary_info(&$vars) {

  $vars['developers'] = $vars['args']['developers'];
  $vars['apartment_types'] = $vars['args']['apartment_types'];

}