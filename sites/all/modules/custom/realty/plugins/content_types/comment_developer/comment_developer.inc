<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_comment_developer_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Comment developer'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_comment_developer_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_comment_developer_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $block->content = theme('realty_comment_developer');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_comment_developer_content_type_theme(&$theme, $plugin) {
  $theme['realty_comment_developer'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-comment-developer',
  );
}

/**
 * Process variables for realty-comment-developer.tpl.php.
 */
function template_preprocess_realty_comment_developer(&$vars) {
  $arg = arg('1');
  $arg == 'term' ? $tid = arg('2') :  $tid = $arg;

  drupal_add_js(REALTY_FRONT_THEME_PATH . '/js/jquery.rating-2.0.js');

  // Фоновое изображение
  $complexes = views_get_view_result('complex', 'complex_developers', $arg);

  $index = rand (0, count($complexes) - 1);
  $vars['background'] = '/' . realty_file_directory_path() . '/' . $complexes[$index]->field_field_main_photo[0]['raw']['filename'];

  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
    )
  );

  $file = REALTY_FRONT_THEME_PATH . '/images/cmp_review.svg';
  $vars['img_review'] = file_get_contents($file);

  $file = REALTY_FRONT_THEME_PATH . '/images/comment_plus.svg';
  $vars['img_plus'] = file_get_contents($file);

  $vars['img_star_full'] =   theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/star-full.svg',
    )
  );

  $node_rev = db_query("SELECT field_data_field_review_developer_developer.entity_id
                          FROM field_data_field_review_developer_developer
                          WHERE field_data_field_review_developer_developer.field_review_developer_developer_target_id = :tid",
                          array(':tid' => $tid))->fetchAll();

  if (!$node_rev) {
    $node = new stdClass();
    $node->type = 'review_developer';

    node_object_prepare($node);

    $node->title = 'Отзыв о застройщике' . $_POST['tid'];
    $node->status = 0;
    $node->uid = 1;

    $node->language = LANGUAGE_NONE;
    $node->field_review_developer_developer[LANGUAGE_NONE][0]['target_id'] = $tid;

    node_save($node);

    $nid = $node->nid;
  }
  else {
    $nid = $node_rev[0]->entity_id;
  }

  $vars['comments'] = views_embed_view('comments_complex', 'comments_developer', $nid);

  $vars['nid'] = $nid;

  $vars['developer_tid'] = $tid;
  $vars['count_assessmen'] = realty_get_count_assessmens_developer($tid);

  $developer_assessmens = json_decode($_COOKIE['developer_assessmens']);

  $a= array_search((int)$tid, $developer_assessmens);

  if ($a != 0) {
    $vars['already_submit'] = TRUE;
  }
  else {
    $vars['already_submit'] = FALSE;
  }

  drupal_add_js(array(
    'developerRating' => TRUE), 'setting');

  if ($_GET['p'] == 'assessmen') {
    $vars['assessmen'] = TRUE;
  }
}
