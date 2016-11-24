<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_menu_helper_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Menu helper'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_menu_helper_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_menu_helper_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_menu_helper');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_menu_helper_content_type_theme(&$theme, $plugin) {
  $theme['realty_menu_helper'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-menu-helper',
  );
}

/**
 * Process variables for realty-menu-helper.tpl.php.
 */
function template_preprocess_realty_menu_helper(&$vars) {

  $menu_items = array(
   /* 0 => array(
      'path' => l(t('путеводитель'), 'guide'),
      'title' => 'guide',
    ),*/
    1 => array(
      'path' => l('о проекте', 'about'),
      'title' => 'node',
    ),
    2 => array(
      'path' => l(t('политика'), 'policy'),
      'title' => 'policy',
    ),
    3 => array(
      'path' => l(t('сотрудничество'), 'cooperation'),
      'title' => 'cooperation',
    ),
    4 => array(
      'path' => l(t('контакты'), 'contacts'),
      'title' => 'contacts',
    ),/*
    5 => array(
      'path' => l(t('faq'), 'faq'),
      'title' => 'faq',
    ),*/

  );

  arg(2) == NULL ? $url = arg(0): $url = arg(2);
  foreach ($menu_items as $key => $item) {
    if ($url == $item['title']) {
      $vars['menu'][$key] = '<li class="active-menu">' . $item['path'] . '</li>';
      $vars['page'] = $item['path'];
    }
    else {
      $vars['menu'][$key] = '<li>' . $item['path'] . '</li>';
    }
  }
}