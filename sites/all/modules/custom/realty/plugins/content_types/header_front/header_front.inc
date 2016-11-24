<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_header_front_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Header front'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_header_front_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_header_front_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_header_front');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_header_front_content_type_theme(&$theme, $plugin) {
  $theme['realty_header_front'] = array(
    'path' => $plugin['path'],
    'template' => 'realty_header_front',
  );
}

/**
 * Process variables for realty-panel-buttons.tpl.php.
 */
function template_preprocess_realty_header_front(&$vars) {

  $vars['logo'] = theme('image', array(
    'path' => theme_get_setting('logo_path'),
    'alt' => t(variable_get('site_name')),
    'title' => t(variable_get('site_name')),
    )
  );

  $vars['logo2'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/logotip.svg',
    )
  );
  $vars['img_question_index'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/question_index.svg');
  
  $vars['menu'] = array(
    0 => l('Поиск', 'search/' . arg(2), array (
      'html' => TRUE,
    )),

    1 => l('Новостройки', 'complexes/city/' . arg(2), array (
      'html' => TRUE,
    )),

    2 => l('Застройщики', 'developers/city/' . arg(2), array (
      'html' => TRUE,
    )),

    3 => '<a href="http://tradein.findome.ru" target="_blank">Trade-in</a>',

    4 => l('Ипотека', 'mortgage/city/' . arg(2), array (
    'html' => TRUE,
  ))
  );
}
