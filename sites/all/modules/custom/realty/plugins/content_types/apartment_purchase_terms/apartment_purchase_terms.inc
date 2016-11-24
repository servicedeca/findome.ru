<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_apartment_purchase_terms_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Apartment purchase terms'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_apartment_purchase_terms_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_apartment_purchase_terms_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_apartment_purchase_terms');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_apartment_purchase_terms_content_type_theme(&$theme, $plugin) {
  $theme['realty_apartment_purchase_terms'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-apartment-purchase-terms',
  );
}

/**
 * Process variables for realty-info-complex.tpl.php.
 */
function template_preprocess_realty_apartment_purchase_terms(&$vars) {
  $nid = arg(1);
  $node_apartment = node_load($nid);

  $apartment_info = realty_get_info_apartment($nid);
  $vars['complex_id'] = $apartment_info['complex_nid'];

  $node_complex = node_load($apartment_info['complex_nid']);

  $vars['background'] = file_create_url( $node_complex->field_main_photo[LANGUAGE_NONE][0]['uri']);
  $description_id = $node_complex->field_description[LANGUAGE_NONE][0]['value'];
  $description = entity_load('field_collection_item', array($description_id));
  $vars['description'] = $description[$description_id]->field_service[LANGUAGE_NONE][0]['safe_value'];
}
