<?php
/**
 * @file
 * realty_feature_page_rating_complex.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function realty_feature_page_rating_complex_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'complex_rating';
  $page->task = 'page';
  $page->admin_title = 'Жилой комплекс - Рейтинг';
  $page->admin_description = '';
  $page->path = 'complexes/%name/rating';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Содержимое: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_complex_rating__panel_context_733de4a4-96fb-49b2-990e-f22d953c29ac';
  $handler->task = 'page';
  $handler->subtask = 'complex_rating';
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
    'panels_everywhere_site_template' => 'site_template__panel_context_85e7b2d9-5028-4a9a-b93d-8279bcb20c3a',
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
  $display->title = 'Рейтинг';
  $display->uuid = '85be9221-ca08-468a-b472-c91ebece2799';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-956166aa-1ef3-4647-a9e7-67ea56e3ab4e';
    $pane->panel = 'middle';
    $pane->type = 'complex_rating';
    $pane->subtype = 'complex_rating';
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
    $pane->uuid = '956166aa-1ef3-4647-a9e7-67ea56e3ab4e';
    $display->content['new-956166aa-1ef3-4647-a9e7-67ea56e3ab4e'] = $pane;
    $display->panels['middle'][0] = 'new-956166aa-1ef3-4647-a9e7-67ea56e3ab4e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['complex_rating'] = $page;

  return $pages;

}
