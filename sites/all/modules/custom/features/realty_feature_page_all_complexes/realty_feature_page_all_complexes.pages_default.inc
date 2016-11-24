<?php
/**
 * @file
 * realty_feature_page_all_complexes.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function realty_feature_page_all_complexes_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'complexes';
  $page->task = 'page';
  $page->admin_title = 'Жилые комплексы';
  $page->admin_description = '';
  $page->path = 'complexes/city/%name';
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
  $handler->name = 'page_complexes_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'complexes';
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
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => 'Жилые комплексы %name:name | [site:name]',
        ),
        'description' => array(
          'value' => 'Findome - жилые комплексы %name:name. Сравнение жилых комплексов %name:name, рейтинг жилых комплексов %name:name. Новостройки %name:name.
',
        ),
        'keywords' => array(
          'value' => 'новостройки %name:name, Findome, файндом, жилые комплексы, жилые комплексы %name:name, рейтинг жилых комплексов %name:name, жк %name:name',
        ),
      ),
    ),
    'pathalias' => 'complexes',
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
  $display->title = 'Новостройки';
  $display->uuid = '857df2a4-5caa-439e-9d2d-8eec6344f191';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8b812329-ed70-4724-9b04-e6a44a96d9db';
    $pane->panel = 'middle';
    $pane->type = 'page_breadcrumb';
    $pane->subtype = 'page_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '345600',
        'granularity' => 'none',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8b812329-ed70-4724-9b04-e6a44a96d9db';
    $display->content['new-8b812329-ed70-4724-9b04-e6a44a96d9db'] = $pane;
    $display->panels['middle'][0] = 'new-8b812329-ed70-4724-9b04-e6a44a96d9db';
    $pane = new stdClass();
    $pane->pid = 'new-4367457a-0f66-4404-a4d8-023fdc610c4c';
    $pane->panel = 'middle';
    $pane->type = 'complexes_filter';
    $pane->subtype = 'complexes_filter';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '86400',
        'granularity' => 'none',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4367457a-0f66-4404-a4d8-023fdc610c4c';
    $display->content['new-4367457a-0f66-4404-a4d8-023fdc610c4c'] = $pane;
    $display->panels['middle'][1] = 'new-4367457a-0f66-4404-a4d8-023fdc610c4c';
    $pane = new stdClass();
    $pane->pid = 'new-f3909395-77b5-49bd-a1b8-a5a17f9cfb3e';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'complex-complexs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '86400',
        'granularity' => 'none',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f3909395-77b5-49bd-a1b8-a5a17f9cfb3e';
    $display->content['new-f3909395-77b5-49bd-a1b8-a5a17f9cfb3e'] = $pane;
    $display->panels['middle'][2] = 'new-f3909395-77b5-49bd-a1b8-a5a17f9cfb3e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['complexes'] = $page;

  return $pages;

}
