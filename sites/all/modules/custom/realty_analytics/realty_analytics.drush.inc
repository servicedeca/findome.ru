<?php

/**
 * Implements hook_drush_command().
 */
function realty_analytics_drush_command() {
  $items['realty-analytics-add-average-price'] = array(
    'aliases' => array('ravpr'),
    'callback' => 'realty_analytics_add_average_price',
  );

  $items['realty-analytics-add-count-apartments'] = array(
    'aliases' => array('raca'),
    'callback' => 'realty_analytics_add_count_apartments',
  );

  return $items;
}

/**
 * Callback fo 'realty-analytics-add-average-price'
 */
function realty_analytics_add_average_price() {
  realty_analytics_get_date_average_price();

  $args = realty_analytics_average_price(1, NULL, NULL);
  realty_analytics_insert_average_price($args);
}

/**
 * Callback to 'realty-analytics-add-count-apartments'
 */
function realty_analytics_add_count_apartments() {
  $args = realty_admin_get_summary_info(1, $developers = NULL, $complexes = NULL);

  realty_analytics_insert_count_apartments($args);
}