<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_user_menu_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('User menu'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_user_menu_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_user_menu_content_type_render($subtype, $conf, $panel_args, $context) {
  $account = reset($context)->data;
  drupal_add_js('/' . REALTY_FRONT_THEME_PATH . '/js/realty_edit_user_profile.js');
  $block = new stdClass();
  $block->content = theme('realty_user_menu', array('account' => $account));;

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_user_menu_content_type_theme(&$theme, $plugin) {
  $theme['realty_user_menu'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-user-menu',
  );
}

/**
 * Process variables for realty-user-menu.tpl.php.
 */
function template_preprocess_realty_user_menu(&$vars) {
  $vars['img_profile'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/profile.svg'
    )
  );

  $vars['img_mail'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/mail.svg'
    )
  );

  $vars['img_phone'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/phone.svg'
    )
  );

  $vars['img_edit_profile'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/edit_profile.svg');

  $vars['name'] = $vars['account']->field_user_name[LANGUAGE_NONE][0]['value'];
  $vars['mail'] = $vars['account']->mail;
  $vars['phone'] = !empty($vars['account']->field_phone_number) ?
    $vars['account']->field_phone_number[LANGUAGE_NONE][0]['value'] :
    '-';

  //$vars['form'] = drupal_get_form('realty_edit_user_profile_form');
}