<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_apartment_visualization_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Apartment visualization'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_apartment_visualization_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_apartment_visualization_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_apartment_visualization');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_apartment_visualization_content_type_theme(&$theme, $plugin) {
  $theme['realty_apartment_visualization'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-apartment-visualization',
  );
}

/**
 * Process variables for realty-info-complex.tpl.php.
 */
function template_preprocess_realty_apartment_visualization(&$vars) {
  $nid = arg(1);
  $node_apartment = node_load($nid);

  $apartment_info = realty_get_info_apartment($nid);
  $vars['complex_id'] = $apartment_info['complex_nid'];

  $node_complex = node_load($apartment_info['complex_nid']);

  $vars['background'] = file_create_url( $node_complex->field_main_photo[LANGUAGE_NONE][0]['uri']);

  $vars['visual'] = theme('image', array(
    'path' => $node_apartment->field_apartment_vizual[LANGUAGE_NONE][0]['uri'],
    )
  );

}
