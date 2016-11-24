<?php
/**
 * @file
 * landing_user.inc
 * Definition of custom panels layout.
 *
 */

// Plugin definition
$plugin = array(
  'category' => t('Realty'),
  'title' => t('Two columns'),
  'icon' => 'sidebar_left.png',
  'theme' => 'two-columns',
  'regions' => array(
    'content_left' => t('Content: left'),
    'content_right' => t('Content: right'),
  ),
);