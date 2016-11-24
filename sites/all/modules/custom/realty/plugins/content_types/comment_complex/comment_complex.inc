<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_comment_complex_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Comment complex'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_comment_complex_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_comment_complex_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $block->content = theme('realty_comment_complex');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_comment_complex_content_type_theme(&$theme, $plugin) {
  $theme['realty_comment_complex'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-comment-complex',
  );
}

/**
 * Process variables for realty-block-stock.tpl.php.
 */
function template_preprocess_realty_comment_complex(&$vars) {
  global $user;

  $node = menu_get_object('node', 1);
  if ($node == NULL) {
    $nid = arg(1);
    $node = node_load($nid);
  }

  $vars['node'] = $node;

  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));

  $file = REALTY_FRONT_THEME_PATH . '/images/cmp_review.svg';
  $vars['img_review'] = file_get_contents($file);

  $file = REALTY_FRONT_THEME_PATH . '/images/comment_plus.svg';
  $vars['img_plus'] = file_get_contents($file);

  $nid = arg(1);
  $node = node_load($nid);

  $vars['background'] = '/' . realty_file_directory_path() . '/' . $node->field_main_photo[LANGUAGE_NONE][0]['filename'];

  $vars['comments'] = views_embed_view('comments_complex', 'comments_complex', $node->nid);
}
