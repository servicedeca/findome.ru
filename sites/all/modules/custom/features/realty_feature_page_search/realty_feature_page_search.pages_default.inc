<?php
/**
 * @file
 * realty_feature_page_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function realty_feature_page_search_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search';
  $page->task = 'page';
  $page->admin_title = 'Поиск';
  $page->admin_description = '';
  $page->path = 'search/%name';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term (multiple): ID',
      'name' => 'terms',
      'settings' => array(
        'breadcrumb' => 1,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_search_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'search';
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
    'pathalias' => 'search',
  );
  $display = new panels_display();
  $display->layout = 'two_columns';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'content_left' => NULL,
      'content_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Результаты поиска';
  $display->uuid = 'e7789cb1-4a13-47d4-9dc4-6ada6b706e01';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ec47d031-4889-43a4-823c-c47868c425a7';
    $pane->panel = 'content_left';
    $pane->type = 'search_search_form';
    $pane->subtype = 'search_search_form';
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
    $pane->uuid = 'ec47d031-4889-43a4-823c-c47868c425a7';
    $display->content['new-ec47d031-4889-43a4-823c-c47868c425a7'] = $pane;
    $display->panels['content_left'][0] = 'new-ec47d031-4889-43a4-823c-c47868c425a7';
    $pane = new stdClass();
    $pane->pid = 'new-e14706fc-1ac2-4fd0-b1a3-95023827db78';
    $pane->panel = 'content_left';
    $pane->type = 'search_bread_crumbs';
    $pane->subtype = 'search_bread_crumbs';
    $pane->shown = FALSE;
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
    $pane->uuid = 'e14706fc-1ac2-4fd0-b1a3-95023827db78';
    $display->content['new-e14706fc-1ac2-4fd0-b1a3-95023827db78'] = $pane;
    $display->panels['content_left'][1] = 'new-e14706fc-1ac2-4fd0-b1a3-95023827db78';
    $pane = new stdClass();
    $pane->pid = 'new-facae358-2783-4345-9500-adc012dee924';
    $pane->panel = 'content_right';
    $pane->type = 'search_result';
    $pane->subtype = 'search_result';
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
    $pane->uuid = 'facae358-2783-4345-9500-adc012dee924';
    $display->content['new-facae358-2783-4345-9500-adc012dee924'] = $pane;
    $display->panels['content_right'][0] = 'new-facae358-2783-4345-9500-adc012dee924';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search'] = $page;

  return $pages;

}
