<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_apartment_documents_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Apartment documents'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_apartment_documents_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $nid = arg(1);
  $apartment_info = realty_get_info_apartment($nid);
  $complex_id = $apartment_info['complex_nid'];
  $view = views_embed_view('complex', 'complex_documents', $complex_id);

  $block->content = $view;

  return $block;
}
