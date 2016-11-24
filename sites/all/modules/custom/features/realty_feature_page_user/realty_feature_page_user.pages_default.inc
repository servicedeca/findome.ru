<?php
/**
 * @file
 * realty_feature_page_user.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function realty_feature_page_user_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Профиль',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'content_left' => NULL,
      'content_center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Личный кабинет';
  $display->uuid = '83ad53d3-f808-403e-8c29-af07c01a8d39';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1004238f-37e1-4816-80d7-8bb20f78ff9e';
    $pane->panel = 'middle';
    $pane->type = 'page_breadcrumb';
    $pane->subtype = 'page_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1004238f-37e1-4816-80d7-8bb20f78ff9e';
    $display->content['new-1004238f-37e1-4816-80d7-8bb20f78ff9e'] = $pane;
    $display->panels['middle'][0] = 'new-1004238f-37e1-4816-80d7-8bb20f78ff9e';
    $pane = new stdClass();
    $pane->pid = 'new-1e1bd664-8144-40f2-940a-232fecfaa83d';
    $pane->panel = 'middle';
    $pane->type = 'user_menu';
    $pane->subtype = 'user_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1e1bd664-8144-40f2-940a-232fecfaa83d';
    $display->content['new-1e1bd664-8144-40f2-940a-232fecfaa83d'] = $pane;
    $display->panels['middle'][1] = 'new-1e1bd664-8144-40f2-940a-232fecfaa83d';
    $pane = new stdClass();
    $pane->pid = 'new-15ae0b94-63fe-4021-9716-0759de4914a3';
    $pane->panel = 'middle';
    $pane->type = 'user_profile';
    $pane->subtype = 'user_profile';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '15ae0b94-63fe-4021-9716-0759de4914a3';
    $display->content['new-15ae0b94-63fe-4021-9716-0759de4914a3'] = $pane;
    $display->panels['middle'][2] = 'new-15ae0b94-63fe-4021-9716-0759de4914a3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context'] = $handler;

  return $export;
}
