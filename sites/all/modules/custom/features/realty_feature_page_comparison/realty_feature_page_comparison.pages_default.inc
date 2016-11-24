<?php
/**
 * @file
 * realty_feature_page_comparison.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function realty_feature_page_comparison_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'comparison';
  $page->task = 'page';
  $page->admin_title = 'Сравнение';
  $page->admin_description = '';
  $page->path = 'comparison';
  $page->access = array(
    'plugins' => array(),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_comparison_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'comparison';
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
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'content_left' => NULL,
      'content_center' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1e3b55de-7854-4aa8-a14d-a077500b82ea';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bbda269e-beea-4605-bb8c-208e7fbedbbd';
    $pane->panel = 'middle';
    $pane->type = 'bread_crumbs';
    $pane->subtype = 'bread_crumbs';
    $pane->shown = FALSE;
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
    $pane->uuid = 'bbda269e-beea-4605-bb8c-208e7fbedbbd';
    $display->content['new-bbda269e-beea-4605-bb8c-208e7fbedbbd'] = $pane;
    $display->panels['middle'][0] = 'new-bbda269e-beea-4605-bb8c-208e7fbedbbd';
    $pane = new stdClass();
    $pane->pid = 'new-e29d1562-e7f5-423e-8336-2ce8f42c00b6';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e29d1562-e7f5-423e-8336-2ce8f42c00b6';
    $display->content['new-e29d1562-e7f5-423e-8336-2ce8f42c00b6'] = $pane;
    $display->panels['middle'][1] = 'new-e29d1562-e7f5-423e-8336-2ce8f42c00b6';
    $pane = new stdClass();
    $pane->pid = 'new-958713bf-51c1-4109-99a6-4f303e89c35e';
    $pane->panel = 'middle';
    $pane->type = 'apartment_comprassion';
    $pane->subtype = 'apartment_comprassion';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'lazy',
      'settings' => array(
        'load_strategy' => 'page-loaded',
        'show_spinner' => 0,
        'load_text' => '',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '958713bf-51c1-4109-99a6-4f303e89c35e';
    $display->content['new-958713bf-51c1-4109-99a6-4f303e89c35e'] = $pane;
    $display->panels['middle'][2] = 'new-958713bf-51c1-4109-99a6-4f303e89c35e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['comparison'] = $page;

  return $pages;

}
