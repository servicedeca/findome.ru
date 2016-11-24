<?php

/**
 * @file.
 */

/**
 * Preprocess for taxonomy-form-term-homes.tpl.php
 */
function mark_picture_preprocess_taxonomy_form_term_homes(&$vars) {

  drupal_add_js(drupal_get_path('module', 'mark_picture') . '/js/mark_picture.js');
  drupal_add_css(drupal_get_path('module', 'mark_picture') . '/css/mark_picture.css');

  $vars['palan_complex'] = '';

  $vars['tool_add_complex'] = theme('image', array(
    'path' => drupal_get_path('module', 'mark_picture') . '/images/centre.png',
    'title' => t('add picture'),
    'width' => '25px',
    'attributes' => array (
      'class' => array('tool-add', 'tool-add-complex'),
    ),
  ));

  $vars['tool_add_section'] = theme('image', array(
    'path' => drupal_get_path('module', 'mark_picture') . '/images/centre.png',
    'title' => t('add picture'),
    'width' => '25px',
    'attributes' => array (
      'class' => array('tool-add', 'tool-add-section'),
    ),
  ));
  if (!empty($vars['form']['field_home_plan']['und'][0]['#entity']->field_home_plan)){
    $vars['image_home_plan'] = theme('image', array(
      'path' => $vars['form']['field_home_plan']['und'][0]['#entity']->field_home_plan['und'][0]['uri'],
      'attributes' => array (
      ),
    ));
  }

  $vars['tool_add_queue'] = theme('image', array(
    'path' => drupal_get_path('module', 'mark_picture') . '/images/centre.png',
    'title' => t('add picture'),
    'width' => '25px',
    'attributes' => array (
      'class' => array('tool-add', 'tool-add-queue-home'),
    ),
  ));

}

/**
 * Preprocess for node-form-complexes.tpl.php
 */
function mark_picture_preprocess_node_form_complexes(&$vars) {
  drupal_add_js(drupal_get_path('module', 'mark_picture') . '/js/mark_picture.js');
  drupal_add_css(drupal_get_path('module', 'mark_picture') . '/css/mark_picture.css');

  $vars['tool_add_queue'] = theme('image', array(
    'path' => drupal_get_path('module', 'mark_picture') . '/images/centre.png',
    'title' => t('add picture'),
    'width' => '25px',
    'attributes' => array (
      'class' => array('tool-add', 'tool-add-queue'),
    ),
  ));
}