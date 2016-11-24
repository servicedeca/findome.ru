<?php
/**
 * @file
 * realty_feature_page_all_articles.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function realty_feature_page_all_articles_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'articles';
  $page->task = 'page';
  $page->admin_title = 'Статьи';
  $page->admin_description = '';
  $page->path = 'articles';
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
  $handler->name = 'page_articles__panel_context_b335a5e4-5323-4b1a-8e0b-ef86cc797a32';
  $handler->task = 'page';
  $handler->subtask = 'articles';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
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
  $display->title = '';
  $display->uuid = '8f9d6f82-a6c7-4fd9-ae6b-02016c65b4f8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-67f80204-e517-4a80-a271-8443f1114512';
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
    $pane->uuid = '67f80204-e517-4a80-a271-8443f1114512';
    $display->content['new-67f80204-e517-4a80-a271-8443f1114512'] = $pane;
    $display->panels['middle'][0] = 'new-67f80204-e517-4a80-a271-8443f1114512';
    $pane = new stdClass();
    $pane->pid = 'new-9a2a8206-3446-4dde-9b37-b56f6271e3fa';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'view_articles-all_articles';
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
    $pane->uuid = '9a2a8206-3446-4dde-9b37-b56f6271e3fa';
    $display->content['new-9a2a8206-3446-4dde-9b37-b56f6271e3fa'] = $pane;
    $display->panels['middle'][1] = 'new-9a2a8206-3446-4dde-9b37-b56f6271e3fa';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['articles'] = $page;

  return $pages;

}
