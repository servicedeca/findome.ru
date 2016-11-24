<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_developer_gallery_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Developer gallery'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_developer_gallery_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_developer_gallery_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_developer_gallery');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_developer_gallery_content_type_theme(&$theme, $plugin) {
  $theme['realty_developer_gallery'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-developer-gallery',
  );
}


/**
 * Process variables for realty-info-complex.tpl.php.
 */
function template_preprocess_realty_developer_gallery(&$vars) {

  $term_id = arg(1);
  $developer = taxonomy_term_load($term_id);

  // Видео
  if (!empty($developer->field_developer_video)) {
    $vars['video'] = views_embed_view('term_view', 'developer_gallery_video', arg(1));
  }

  // Визуализации Жилых комплесов
  if (!empty($developer->field_developer_gallery['und'])) {
    $vars['photos'] = views_embed_view('term_view', 'developer_gallery');
  }

  $complexes = views_get_view_result('complex', 'complex_developers', $term_id);

  $index = rand (0, count($complexes) - 1);
  $vars['background'] = '/' . realty_file_directory_path() . '/' . $complexes[$index]->field_field_main_photo[0]['raw']['filename'];

  $file = REALTY_FRONT_THEME_PATH . '/images/cmp_hover.svg';
  $vars['img_hover'] = file_get_contents($file);
  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));
}