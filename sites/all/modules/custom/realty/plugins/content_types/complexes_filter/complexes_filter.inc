<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_complexes_filter_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Complexes filter'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_complexes_filter_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_complexes_filter_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_complexes_filter');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_complexes_filter_content_type_theme(&$theme, $plugin) {
  $theme['realty_complexes_filter'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-complexes-filter',
  );
}

/**
 * Process variables for realty-block-complexes.tpl.php.
 */
function template_preprocess_realty_complexes_filter(&$vars) {

  $developers_by_city = realty_get_developer_current_city();

  $vars['modal'] = theme('realty_modal_search_form', array(
      'std' => 'std',
      'modal_id' => 'modal_developer',
      'class' => 'CheckboxDeveloper',
      'text' => 'Застройщик',
      'options' => $developers_by_city,
      'submit' => TRUE,
    )
  );
}