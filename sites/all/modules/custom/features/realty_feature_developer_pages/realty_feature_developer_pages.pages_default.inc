<?php
/**
 * @file
 * realty_feature_developer_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function realty_feature_developer_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'developer_complexes';
  $page->task = 'page';
  $page->admin_title = '';
  $page->admin_description = '';
  $page->path = 'developer/%name/complexes';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          3 => '3',
          6 => 0,
          9 => 0,
          8 => 0,
          5 => 0,
          7 => 0,
          1 => 0,
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
  $handler->name = 'page_developer_complexes__panel_context_1aab22e6-679c-4100-9374-4a5e52dd759b';
  $handler->task = 'page';
  $handler->subtask = 'developer_complexes';
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
    'panels_everywhere_site_template' => 'site_template__panel_context_05a23155-d748-46e4-97fe-d996783aacf5',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'content_left' => NULL,
      'content_right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Объекты';
  $display->uuid = 'ea773ae2-a287-4577-9135-1aa037755a64';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7afee4c5-ad12-44fa-a14b-23f0de03f790';
    $pane->panel = 'middle';
    $pane->type = 'developer_complexes';
    $pane->subtype = 'developer_complexes';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'panels_hash_cache',
      'settings' => array(
        'lifetime' => '86400',
        'granularity' => array(
          'url' => 'url',
          'args' => 0,
          'context' => 0,
          'path' => 0,
          'user' => 0,
          'user_role' => 0,
        ),
        'granularity_roles_as_anon' => array(
          2 => 0,
          3 => 0,
        ),
        'granularity_role_selection' => 'all',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7afee4c5-ad12-44fa-a14b-23f0de03f790';
    $display->content['new-7afee4c5-ad12-44fa-a14b-23f0de03f790'] = $pane;
    $display->panels['middle'][0] = 'new-7afee4c5-ad12-44fa-a14b-23f0de03f790';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['developer_complexes'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'developer_gallery';
  $page->task = 'page';
  $page->admin_title = 'Галерея';
  $page->admin_description = '';
  $page->path = 'developer/%name/gallery';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          3 => '3',
          6 => 0,
          9 => 0,
          8 => 0,
          5 => 0,
          7 => 0,
          1 => 0,
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
  $handler->name = 'page_developer_gallery__panel_context_cfbc534e-f876-4f0b-8472-b32cac186f3e';
  $handler->task = 'page';
  $handler->subtask = 'developer_gallery';
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
    'panels_everywhere_site_template' => 'site_template__panel_context_05a23155-d748-46e4-97fe-d996783aacf5',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'content_left' => NULL,
      'content_right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Галерея';
  $display->uuid = '3d2aa6aa-16cd-46dd-bebd-4f289af76df0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d3c577c2-324d-4bbd-ade8-9e056af65d15';
    $pane->panel = 'middle';
    $pane->type = 'developer_gallery';
    $pane->subtype = 'developer_gallery';
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
    $pane->uuid = 'd3c577c2-324d-4bbd-ade8-9e056af65d15';
    $display->content['new-d3c577c2-324d-4bbd-ade8-9e056af65d15'] = $pane;
    $display->panels['middle'][0] = 'new-d3c577c2-324d-4bbd-ade8-9e056af65d15';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['developer_gallery'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'developer_reviews';
  $page->task = 'page';
  $page->admin_title = 'Застройщик - Отзывы';
  $page->admin_description = '';
  $page->path = 'developer/%name/reviews';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          3 => '3',
          22 => 0,
          20 => 0,
          21 => 0,
          6 => 0,
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
  $handler->name = 'page_developer_reviews__panel_context_31b2005e-a924-4d9e-9fb4-439b51edb20e';
  $handler->task = 'page';
  $handler->subtask = 'developer_reviews';
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
    'panels_everywhere_site_template' => 'site_template__panel_context_05a23155-d748-46e4-97fe-d996783aacf5',
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
  $display->title = 'Отзывы';
  $display->uuid = '587afb13-5f89-491c-95b0-c4a77818d54d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0237248f-f22e-413e-860c-b859de54b2b0';
    $pane->panel = 'middle';
    $pane->type = 'comment_developer';
    $pane->subtype = 'comment_developer';
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
    $pane->uuid = '0237248f-f22e-413e-860c-b859de54b2b0';
    $display->content['new-0237248f-f22e-413e-860c-b859de54b2b0'] = $pane;
    $display->panels['middle'][0] = 'new-0237248f-f22e-413e-860c-b859de54b2b0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['developer_reviews'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'developers';
  $page->task = 'page';
  $page->admin_title = 'Застройщик';
  $page->admin_description = '';
  $page->path = 'developers/city/%name';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
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
  $handler->name = 'page_developers_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'developers';
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
          'value' => 'Застройщики %name:name | [site:name]',
        ),
        'description' => array(
          'value' => 'Findome – ведущие застройщики Новосибирска. Независимый рейтинг застройщиков %name:name. Поиск и сравнение квартир в новостройках от застройщиков %name:name.',
        ),
        'keywords' => array(
          'value' => 'квартиры от застройщика, квартиры в новостройках, застройщики, новостройки, Findome - поиск и сравнение квартир в новостройках, файндом, новостройки %name:name, застройщики %name:name, рейтинг застройщиков %name:name, новостройки от застройщиков',
        ),
      ),
    ),
    'pathalias' => 'developers',
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
  $display->title = 'Застройщики';
  $display->uuid = '45d32603-8032-4eb5-9739-d29ce2311b93';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5b653028-cee3-4a35-9506-b4d844ec849e';
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
    $pane->uuid = '5b653028-cee3-4a35-9506-b4d844ec849e';
    $display->content['new-5b653028-cee3-4a35-9506-b4d844ec849e'] = $pane;
    $display->panels['middle'][0] = 'new-5b653028-cee3-4a35-9506-b4d844ec849e';
    $pane = new stdClass();
    $pane->pid = 'new-85248e1c-b8b0-4220-a8c0-0e51b5e3a991';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'term_view-developers';
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
    $pane->uuid = '85248e1c-b8b0-4220-a8c0-0e51b5e3a991';
    $display->content['new-85248e1c-b8b0-4220-a8c0-0e51b5e3a991'] = $pane;
    $display->panels['middle'][1] = 'new-85248e1c-b8b0-4220-a8c0-0e51b5e3a991';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['developers'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'stock_developer';
  $page->task = 'page';
  $page->admin_title = 'Акции Застройщика';
  $page->admin_description = '';
  $page->path = 'developer/%name/stock';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          3 => '3',
          6 => 0,
          9 => 0,
          8 => 0,
          5 => 0,
          7 => 0,
          1 => 0,
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
  $handler->name = 'page_stock_developer__panel_context_d739897a-14ff-47a8-8249-af1098f0e853';
  $handler->task = 'page';
  $handler->subtask = 'stock_developer';
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
    'panels_everywhere_site_template' => 'site_template__panel_context_05a23155-d748-46e4-97fe-d996783aacf5',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'content_left' => NULL,
      'content_right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Акции';
  $display->uuid = 'de9a6b3b-3316-4649-9933-bd8d37412d1e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a10fb6c1-4887-4797-a830-84e182b053fd';
    $pane->panel = 'middle';
    $pane->type = 'stock_list';
    $pane->subtype = 'stock_list';
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
    $pane->uuid = 'a10fb6c1-4887-4797-a830-84e182b053fd';
    $display->content['new-a10fb6c1-4887-4797-a830-84e182b053fd'] = $pane;
    $display->panels['middle'][0] = 'new-a10fb6c1-4887-4797-a830-84e182b053fd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['stock_developer'] = $page;

  return $pages;

}
