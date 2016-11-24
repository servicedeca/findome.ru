<?php
/**
 * @file
 * realty_feature_page_mortgage_program.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function realty_feature_page_mortgage_program_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'mortgage';
  $page->task = 'page';
  $page->admin_title = 'Ипотека';
  $page->admin_description = '';
  $page->path = 'mortgage/city/%city/!name';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'city' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          1 => '1',
          20 => 0,
          21 => 0,
          6 => 0,
          3 => 0,
          9 => 0,
          14 => 0,
          15 => 0,
          12 => 0,
          8 => 0,
          10 => 0,
          18 => 0,
          17 => 0,
          5 => 0,
          16 => 0,
          13 => 0,
        ),
        'breadcrumb' => 1,
        'transform' => 0,
      ),
    ),
    'name' => array(
      'id' => 2,
      'identifier' => 'Taxonomy term: ID 2',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          20 => 0,
          21 => 0,
          6 => 0,
          3 => 0,
          9 => 0,
          14 => 0,
          15 => 0,
          12 => 0,
          8 => 0,
          10 => 0,
          18 => 0,
          17 => 0,
          5 => 0,
          16 => 0,
          13 => 0,
          1 => 0,
        ),
        'breadcrumb' => 0,
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
  $handler->name = 'page_mortgage__panel_context_9fa359d4-8258-4bd8-b49e-8a6af783a56d';
  $handler->task = 'page';
  $handler->subtask = 'mortgage';
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
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => 'Ипотека в новостройках %city:name | [site:name]',
        ),
        'description' => array(
          'value' => '[site:name]. Ипотечные программы банков, заявка на ипотеку online. Рассчитать и получить ипотеку на выгодных условиях. Ипотечные программы на Findome - поиск квартир в новостройках.',
        ),
        'keywords' => array(
          'value' => '"Газпромбанк" (АО) ипотека, «Сбербанк России» (ПАО) ипотека, Банк ВТБ 24 (ПАО) ипотека, ипотечные программы, ипотека, военная ипотека в новостройке, ипотека с государственной поддержкой, ипотека с господдержкой, findome, файндом, ипотека в новостройках, ипотека, ипотека в %city:name',
        ),
      ),
    ),
    'pathalias' => 'mortgage',
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
  $display->title = 'Ипотека';
  $display->uuid = 'dc352ceb-7d16-43f8-adce-cba688f16717';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-caad1186-1682-45a7-8df3-8699b0f5959e';
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
    $pane->uuid = 'caad1186-1682-45a7-8df3-8699b0f5959e';
    $display->content['new-caad1186-1682-45a7-8df3-8699b0f5959e'] = $pane;
    $display->panels['middle'][0] = 'new-caad1186-1682-45a7-8df3-8699b0f5959e';
    $pane = new stdClass();
    $pane->pid = 'new-c645ec66-b8d4-4564-80a7-b09dfb52d21f';
    $pane->panel = 'middle';
    $pane->type = 'bank_mortgage';
    $pane->subtype = 'bank_mortgage';
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
    $pane->uuid = 'c645ec66-b8d4-4564-80a7-b09dfb52d21f';
    $display->content['new-c645ec66-b8d4-4564-80a7-b09dfb52d21f'] = $pane;
    $display->panels['middle'][1] = 'new-c645ec66-b8d4-4564-80a7-b09dfb52d21f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-caad1186-1682-45a7-8df3-8699b0f5959e';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['mortgage'] = $page;

  return $pages;

}
