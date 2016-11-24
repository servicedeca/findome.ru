<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_complex_gallery_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Complex gallery'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_complex_gallery_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_complex_gallery_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_complex_gallery');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_complex_gallery_content_type_theme(&$theme, $plugin) {
  $theme['realty_complex_gallery'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-complex-gallery',
  );
}


/**
 * Process variables for realty-info-complex.tpl.php.
 */
function template_preprocess_realty_complex_gallery(&$vars) {

  $nid = arg(1);
  $node = node_load($nid);

  // Дневники стройки
  if (!empty($node->field_gallery)) {
    $vars['photos'] = views_embed_view("complex","gallery_photo", arg(1));
  }

  // Визуализации
  if (!empty($node->field_visualization)) {
    $vars['visualisation'] = views_embed_view("complex","gallery_visualization", arg(1));
  }

  // Видео
  if (!empty($node->field_video)) {
    $vars['video'] = views_embed_view('complex', 'gallery_video', arg(1));
  }

  // Ресурсы для шаблона
  $file = REALTY_FRONT_THEME_PATH . '/images/cmp_hover.svg';

  $vars['img_hover'] = file_get_contents($file);

  $vars['background'] = '/' . realty_file_directory_path() . '/' . $node->field_main_photo[LANGUAGE_NONE][0]['filename'];

  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));
}