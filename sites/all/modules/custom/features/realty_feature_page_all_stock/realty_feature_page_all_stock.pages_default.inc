<?php
/**
 * @file
 * realty_feature_page_all_stock.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function realty_feature_page_all_stock_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'all_stock_city';
  $page->task = 'page';
  $page->admin_title = 'Все акции в городе';
  $page->admin_description = '';
  $page->path = 'stock/city/%name';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          1 => '1',
          6 => 0,
          3 => 0,
          5 => 0,
          7 => 0,
        ),
        'breadcrumb' => 1,
        'transform' => 0,
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
  $handler->name = 'page_all_stock_city_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'all_stock_city';
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
    'panels_everywhere_site_template' => 'site_template__panel_context_9f2b4c28-164e-4a94-b08b-abb7ea04f63c',
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'description' => array(
          'value' => '[site:name] - поиск квартир в новостройках. Акции от застройщика.',
        ),
        'keywords' => array(
          'value' => 'срок сдачи, жилые комплексы, застройщики, новостройки, findome, файндом, акции от застройщика.',
        ),
      ),
    ),
    'pathalias' => 'stock',
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
  $display->title = 'Акции';
  $display->uuid = '5359a301-0fbc-488a-8494-b324200dc0fe';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5c5dc331-c05b-4358-8309-b9fc4f0462a3';
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
    $pane->uuid = '5c5dc331-c05b-4358-8309-b9fc4f0462a3';
    $display->content['new-5c5dc331-c05b-4358-8309-b9fc4f0462a3'] = $pane;
    $display->panels['middle'][0] = 'new-5c5dc331-c05b-4358-8309-b9fc4f0462a3';
    $pane = new stdClass();
    $pane->pid = 'new-3fe0ce7d-e994-476e-a0ec-830938a397e5';
    $pane->panel = 'middle';
    $pane->type = 'stock_filter';
    $pane->subtype = 'stock_filter';
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
    $pane->uuid = '3fe0ce7d-e994-476e-a0ec-830938a397e5';
    $display->content['new-3fe0ce7d-e994-476e-a0ec-830938a397e5'] = $pane;
    $display->panels['middle'][1] = 'new-3fe0ce7d-e994-476e-a0ec-830938a397e5';
    $pane = new stdClass();
    $pane->pid = 'new-b41e78fa-0f2a-4043-a06f-9f05f4698ad0';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'stock-all_stock_city';
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
    $pane->uuid = 'b41e78fa-0f2a-4043-a06f-9f05f4698ad0';
    $display->content['new-b41e78fa-0f2a-4043-a06f-9f05f4698ad0'] = $pane;
    $display->panels['middle'][2] = 'new-b41e78fa-0f2a-4043-a06f-9f05f4698ad0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['all_stock_city'] = $page;

  return $pages;

}
