<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_developer_complexes_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('developer complexes'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_developer_complexes_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_developer_complexes_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_developer_complexes');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_developer_complexes_content_type_theme(&$theme, $plugin) {
  $theme['realty_developer_complexes'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-developer-complexes',
  );
}

/**
 * Process variables for realty-menu-complex.tpl.php.
 */
function template_preprocess_realty_developer_complexes(&$vars) {
  $tid = arg(1);

  $vars['map'] = views_embed_view('map', 'developer_map', $tid);
  $complexes = views_get_view_result('complex', 'complex_developers', $tid);

  if($complexes) {
    foreach ($complexes as $complex) {
      $img = theme('image', array(
          'path' => $complex->field_field_complex_logo[0]['raw']['uri'],
        )
      );

      $vars['logos'][] = l($img, 'node/' . $complex->nid, array(
          'html' => TRUE,
          'attributes' => array(
            'class' => array('col-xs-12'),
            'target' => '_blank'
          )
        )
      );
    }

    $index = rand (0, count($complexes) - 1);
    $vars['background'] = '/' . realty_file_directory_path() . '/' . $complexes[$index]->field_field_main_photo[0]['raw']['filename'];
  }

  $vars['archive_map'] = views_embed_view('map', 'archive_developer_map', $tid);
  $archive_complexes = views_get_view_result('complexes_archiv', 'archiv_complexes_developer', $tid);

  if($archive_complexes) {
    foreach ($archive_complexes as $archive_complex) {
      $img = theme('image', array(
          'path' => $archive_complex->field_field_archiv_complex_logo[0]['raw']['uri'],
        )
      );

      $vars['logos_archive'][] = l($img, 'node/' . $archive_complex->nid, array(
          'html' => TRUE,
          'attributes' => array(
            'class' => array('col-xs-12'),
            'target' => '_blank'
          )
        )
      );
    }
  }

  $file = REALTY_FRONT_THEME_PATH . '/images/cmp_hover.svg';
  $vars['img_hover'] = file_get_contents($file);
}