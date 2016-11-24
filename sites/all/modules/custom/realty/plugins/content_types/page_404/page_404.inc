<?php
/**
 * @file
 * Ctools content type
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_page_404_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('page 404'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_page_404_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_page_404_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $block->content = theme('realty_page_404');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_page_404_content_type_theme(&$theme, $plugin) {
  $theme['realty_page_404'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-page-404',
  );
}

/**
 * Process variables for realty-page-404.tpl.php.
 */
function template_preprocess_realty_page_404(&$vars) {
  $vars['img_path'] = '/' . REALTY_FRONT_THEME_PATH . '/images/a4.jpg';
}