<?php
/**
 * @file
 * realty_feature_page_404.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function realty_feature_page_404_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'page_not_found';
  $page->task = 'page';
  $page->admin_title = 'page_not_found';
  $page->admin_description = '';
  $page->path = 'notfound';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_page_not_found__panel_context_35301a35-8df3-4687-bed5-02d68e5a77df';
  $handler->task = 'page';
  $handler->subtask = 'page_not_found';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'panels_everywhere_site_template' => 'site_template__panel_context_9f2b4c28-164e-4a94-b08b-abb7ea04f63c',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Страница не найдена';
  $display->uuid = 'c9786595-14f8-486e-9765-1969e57b3fab';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-61f0d1e4-f8fc-48be-9535-669cfed8a430';
    $pane->panel = 'middle';
    $pane->type = 'page_404';
    $pane->subtype = 'page_404';
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
    $pane->uuid = '61f0d1e4-f8fc-48be-9535-669cfed8a430';
    $display->content['new-61f0d1e4-f8fc-48be-9535-669cfed8a430'] = $pane;
    $display->panels['middle'][0] = 'new-61f0d1e4-f8fc-48be-9535-669cfed8a430';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['page_not_found'] = $page;

  return $pages;

}
