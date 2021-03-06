<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_stock_filter_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Stock filter'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_stock_filter_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_stock_filter_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_stock_filter');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_stock_filter_content_type_theme(&$theme, $plugin) {
  $theme['realty_stock_filter'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-stock-filter',
  );
}

/**
 * Process variables for realty-block-stock.tpl.php.
 */
function template_preprocess_realty_stock_filter(&$vars) {
  $city_id = arg(1);

  $developers = realty_get_developer_current_city();

  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));

  $vars['modal'] .= theme('realty_modal_search_form', array(
      'std' => 'std',
      'modal_id' => 'modal_developer',
      'class' => 'Checkbox-developer-stock',
      'text' => t('Застройщики'),
      'options' => $developers,
      'submit' => TRUE,
    )
  );

}