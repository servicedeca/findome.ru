<?php
/**
 * @file
 * realty_feature_panel_everywhere.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function realty_feature_panel_everywhere_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__panel_context_05a23155-d748-46e4-97fe-d996783aacf5';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'developer_template',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'description' => array(
          'value' => 'Поиск квартир в новостройках. [current-page:title] - условия покупки, ипотечные программы, галерея.',
        ),
        'keywords' => array(
          'value' => '[current-page:title], квартиры от [current-page:title], новостройки, новостройка, недвижимость,планировка, планировки, квартира, комната, дом, купить квартиру.',
        ),
      ),
    ),
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
  $display->uuid = '7ad1d793-7202-47cb-a833-c9759187b0ae';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-61fab54f-7100-4a07-ad05-40010a31c0b0';
    $pane->panel = 'middle';
    $pane->type = 'header';
    $pane->subtype = 'header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '61fab54f-7100-4a07-ad05-40010a31c0b0';
    $display->content['new-61fab54f-7100-4a07-ad05-40010a31c0b0'] = $pane;
    $display->panels['middle'][0] = 'new-61fab54f-7100-4a07-ad05-40010a31c0b0';
    $pane = new stdClass();
    $pane->pid = 'new-5d7b5b6f-8f06-48e4-a2dd-c075acda5101';
    $pane->panel = 'middle';
    $pane->type = 'page_breadcrumb';
    $pane->subtype = 'page_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'panels_hash_cache',
      'settings' => array(
        'lifetime' => '604800',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5d7b5b6f-8f06-48e4-a2dd-c075acda5101';
    $display->content['new-5d7b5b6f-8f06-48e4-a2dd-c075acda5101'] = $pane;
    $display->panels['middle'][1] = 'new-5d7b5b6f-8f06-48e4-a2dd-c075acda5101';
    $pane = new stdClass();
    $pane->pid = 'new-cd19937a-e8c9-4fb7-bc46-7a72a4f7bd9a';
    $pane->panel = 'middle';
    $pane->type = 'developer_menu';
    $pane->subtype = 'developer_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'panels_hash_cache',
      'settings' => array(
        'lifetime' => '604800',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'cd19937a-e8c9-4fb7-bc46-7a72a4f7bd9a';
    $display->content['new-cd19937a-e8c9-4fb7-bc46-7a72a4f7bd9a'] = $pane;
    $display->panels['middle'][2] = 'new-cd19937a-e8c9-4fb7-bc46-7a72a4f7bd9a';
    $pane = new stdClass();
    $pane->pid = 'new-3c698215-ac80-45d3-affa-e4c524c65976';
    $pane->panel = 'middle';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array(
      'method' => 'panels_hash_cache',
      'settings' => array(
        'lifetime' => '345600',
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '3c698215-ac80-45d3-affa-e4c524c65976';
    $display->content['new-3c698215-ac80-45d3-affa-e4c524c65976'] = $pane;
    $display->panels['middle'][3] = 'new-3c698215-ac80-45d3-affa-e4c524c65976';
    $pane = new stdClass();
    $pane->pid = 'new-5be574fe-a92f-4046-85de-4a1dac03482b';
    $pane->panel = 'middle';
    $pane->type = 'apartment_developer';
    $pane->subtype = 'apartment_developer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'lazy',
      'settings' => array(
        'load_strategy' => 'page-loaded',
        'show_spinner' => 1,
        'load_text' => 'Загрузка',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '5be574fe-a92f-4046-85de-4a1dac03482b';
    $display->content['new-5be574fe-a92f-4046-85de-4a1dac03482b'] = $pane;
    $display->panels['middle'][4] = 'new-5be574fe-a92f-4046-85de-4a1dac03482b';
    $pane = new stdClass();
    $pane->pid = 'new-33487ead-0ba6-4d01-9ede-1934ae1fd147';
    $pane->panel = 'middle';
    $pane->type = 'footer';
    $pane->subtype = 'footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'panels_hash_cache',
      'settings' => array(
        'lifetime' => '604800',
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '33487ead-0ba6-4d01-9ede-1934ae1fd147';
    $display->content['new-33487ead-0ba6-4d01-9ede-1934ae1fd147'] = $pane;
    $display->panels['middle'][5] = 'new-33487ead-0ba6-4d01-9ede-1934ae1fd147';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-61fab54f-7100-4a07-ad05-40010a31c0b0';
  $handler->conf['display'] = $display;
  $export['site_template__panel_context_05a23155-d748-46e4-97fe-d996783aacf5'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__panel_context_3d0c4bc6-cd97-49bd-be6a-26eec4a63b53';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'apartment_template',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => 'Квартира',
        ),
        'description' => array(
          'value' => 'Квартира',
        ),
        'keywords' => array(
          'value' => 'Квартира',
        ),
      ),
    ),
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
  $display->title = 'Квартира ';
  $display->uuid = 'e026e67c-bfdb-4729-a4ab-f470f61930ac';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ba96d48d-d178-4a20-9472-d42cb817f854';
    $pane->panel = 'middle';
    $pane->type = 'header';
    $pane->subtype = 'header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ba96d48d-d178-4a20-9472-d42cb817f854';
    $display->content['new-ba96d48d-d178-4a20-9472-d42cb817f854'] = $pane;
    $display->panels['middle'][0] = 'new-ba96d48d-d178-4a20-9472-d42cb817f854';
    $pane = new stdClass();
    $pane->pid = 'new-9795e228-22d8-40dc-b8b0-d39d52708769';
    $pane->panel = 'middle';
    $pane->type = 'page_breadcrumb';
    $pane->subtype = 'page_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'panels_hash_cache',
      'settings' => array(
        'lifetime' => '345600',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '9795e228-22d8-40dc-b8b0-d39d52708769';
    $display->content['new-9795e228-22d8-40dc-b8b0-d39d52708769'] = $pane;
    $display->panels['middle'][1] = 'new-9795e228-22d8-40dc-b8b0-d39d52708769';
    $pane = new stdClass();
    $pane->pid = 'new-89a1c270-3d31-41b9-97d7-b08d63c14b21';
    $pane->panel = 'middle';
    $pane->type = 'menu_apartment';
    $pane->subtype = 'menu_apartment';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'panels_hash_cache',
      'settings' => array(
        'lifetime' => '7200',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '89a1c270-3d31-41b9-97d7-b08d63c14b21';
    $display->content['new-89a1c270-3d31-41b9-97d7-b08d63c14b21'] = $pane;
    $display->panels['middle'][2] = 'new-89a1c270-3d31-41b9-97d7-b08d63c14b21';
    $pane = new stdClass();
    $pane->pid = 'new-1dbb1148-a09d-4f60-a6b7-36e85a19aef4';
    $pane->panel = 'middle';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array(
      'method' => 'panels_hash_cache',
      'settings' => array(
        'lifetime' => '172800',
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '1dbb1148-a09d-4f60-a6b7-36e85a19aef4';
    $display->content['new-1dbb1148-a09d-4f60-a6b7-36e85a19aef4'] = $pane;
    $display->panels['middle'][3] = 'new-1dbb1148-a09d-4f60-a6b7-36e85a19aef4';
    $pane = new stdClass();
    $pane->pid = 'new-376700f2-c945-4509-b040-4bd2b01704dd';
    $pane->panel = 'middle';
    $pane->type = 'apartment_complex';
    $pane->subtype = 'apartment_complex';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'lazy',
      'settings' => array(
        'load_strategy' => 'page-loaded',
        'show_spinner' => 1,
        'load_text' => 'Загрузка',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '376700f2-c945-4509-b040-4bd2b01704dd';
    $display->content['new-376700f2-c945-4509-b040-4bd2b01704dd'] = $pane;
    $display->panels['middle'][4] = 'new-376700f2-c945-4509-b040-4bd2b01704dd';
    $pane = new stdClass();
    $pane->pid = 'new-06d20717-c0ba-4d1a-867d-e3dc8d08c345';
    $pane->panel = 'middle';
    $pane->type = 'footer';
    $pane->subtype = 'footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'panels_hash_cache',
      'settings' => array(
        'lifetime' => '604800',
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '06d20717-c0ba-4d1a-867d-e3dc8d08c345';
    $display->content['new-06d20717-c0ba-4d1a-867d-e3dc8d08c345'] = $pane;
    $display->panels['middle'][5] = 'new-06d20717-c0ba-4d1a-867d-e3dc8d08c345';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-1dbb1148-a09d-4f60-a6b7-36e85a19aef4';
  $handler->conf['display'] = $display;
  $export['site_template__panel_context_3d0c4bc6-cd97-49bd-be6a-26eec4a63b53'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__panel_context_85e7b2d9-5028-4a9a-b93d-8279bcb20c3a';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Complex_template',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'description' => array(
          'value' => '[current-page:title]. [site:name] - поиск квартир в новостройках.
поиск квартир в новостройках. [current-page:title] - планировки, инфраструктура, условия покупки, ипотечные программы, галерея.',
        ),
        'keywords' => array(
          'value' => '[current-page:title], квартиры в [current-page:title], новостройки, новостройка, недвижимость, планировка, планировки, квартира, комната, дом, купить квартиру',
        ),
      ),
    ),
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
  $display->uuid = 'c9a07fa1-caaf-4276-b061-0a624aa4ce20';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4c0d1a79-3bd8-4a68-bafe-923b26c3b786';
    $pane->panel = 'middle';
    $pane->type = 'header';
    $pane->subtype = 'header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4c0d1a79-3bd8-4a68-bafe-923b26c3b786';
    $display->content['new-4c0d1a79-3bd8-4a68-bafe-923b26c3b786'] = $pane;
    $display->panels['middle'][0] = 'new-4c0d1a79-3bd8-4a68-bafe-923b26c3b786';
    $pane = new stdClass();
    $pane->pid = 'new-c030fdff-e9fa-4540-8664-46008f924cfc';
    $pane->panel = 'middle';
    $pane->type = 'page_breadcrumb';
    $pane->subtype = 'page_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'panels_hash_cache',
      'settings' => array(
        'lifetime' => '345600',
        'granularity' => array(
          'context' => 'context',
          'args' => 0,
          'url' => 0,
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c030fdff-e9fa-4540-8664-46008f924cfc';
    $display->content['new-c030fdff-e9fa-4540-8664-46008f924cfc'] = $pane;
    $display->panels['middle'][1] = 'new-c030fdff-e9fa-4540-8664-46008f924cfc';
    $pane = new stdClass();
    $pane->pid = 'new-02102315-c57e-4210-a450-f8f0c5867f36';
    $pane->panel = 'middle';
    $pane->type = 'menu_complex';
    $pane->subtype = 'menu_complex';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'panels_hash_cache',
      'settings' => array(
        'lifetime' => '345600',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '02102315-c57e-4210-a450-f8f0c5867f36';
    $display->content['new-02102315-c57e-4210-a450-f8f0c5867f36'] = $pane;
    $display->panels['middle'][2] = 'new-02102315-c57e-4210-a450-f8f0c5867f36';
    $pane = new stdClass();
    $pane->pid = 'new-bc6b1cf1-83cc-4f4f-9816-397f7c2f2be5';
    $pane->panel = 'middle';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'bc6b1cf1-83cc-4f4f-9816-397f7c2f2be5';
    $display->content['new-bc6b1cf1-83cc-4f4f-9816-397f7c2f2be5'] = $pane;
    $display->panels['middle'][3] = 'new-bc6b1cf1-83cc-4f4f-9816-397f7c2f2be5';
    $pane = new stdClass();
    $pane->pid = 'new-485901e5-37bf-4705-af10-53925027b69b';
    $pane->panel = 'middle';
    $pane->type = 'apartment_complex';
    $pane->subtype = 'apartment_complex';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'lazy',
      'settings' => array(
        'load_strategy' => 'page-loaded',
        'show_spinner' => 1,
        'load_text' => 'Загрузка',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '485901e5-37bf-4705-af10-53925027b69b';
    $display->content['new-485901e5-37bf-4705-af10-53925027b69b'] = $pane;
    $display->panels['middle'][4] = 'new-485901e5-37bf-4705-af10-53925027b69b';
    $pane = new stdClass();
    $pane->pid = 'new-73c7715c-423c-49f1-a925-fcbd4801b912';
    $pane->panel = 'middle';
    $pane->type = 'footer';
    $pane->subtype = 'footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'panels_hash_cache',
      'settings' => array(
        'lifetime' => '345600',
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '73c7715c-423c-49f1-a925-fcbd4801b912';
    $display->content['new-73c7715c-423c-49f1-a925-fcbd4801b912'] = $pane;
    $display->panels['middle'][5] = 'new-73c7715c-423c-49f1-a925-fcbd4801b912';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-c030fdff-e9fa-4540-8664-46008f924cfc';
  $handler->conf['display'] = $display;
  $export['site_template__panel_context_85e7b2d9-5028-4a9a-b93d-8279bcb20c3a'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__panel_context_9f2b4c28-164e-4a94-b08b-abb7ea04f63c';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Main template',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'metatag_panels' => array(
      'enabled' => 0,
      'metatags' => array(),
    ),
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
  $display->uuid = '18da76d5-d6e4-4440-95d4-33964b0f60bf';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5ebe10e4-0ba5-458c-99f8-5505572fed5a';
    $pane->panel = 'middle';
    $pane->type = 'header';
    $pane->subtype = 'header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5ebe10e4-0ba5-458c-99f8-5505572fed5a';
    $display->content['new-5ebe10e4-0ba5-458c-99f8-5505572fed5a'] = $pane;
    $display->panels['middle'][0] = 'new-5ebe10e4-0ba5-458c-99f8-5505572fed5a';
    $pane = new stdClass();
    $pane->pid = 'new-3b6777c2-b5a8-43aa-8a83-581b35be02d1';
    $pane->panel = 'middle';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3b6777c2-b5a8-43aa-8a83-581b35be02d1';
    $display->content['new-3b6777c2-b5a8-43aa-8a83-581b35be02d1'] = $pane;
    $display->panels['middle'][1] = 'new-3b6777c2-b5a8-43aa-8a83-581b35be02d1';
    $pane = new stdClass();
    $pane->pid = 'new-ccf2d653-5f92-4325-88b3-02a20525e5ef';
    $pane->panel = 'middle';
    $pane->type = 'footer';
    $pane->subtype = 'footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'panels_hash_cache',
      'settings' => array(
        'lifetime' => '345600',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ccf2d653-5f92-4325-88b3-02a20525e5ef';
    $display->content['new-ccf2d653-5f92-4325-88b3-02a20525e5ef'] = $pane;
    $display->panels['middle'][2] = 'new-ccf2d653-5f92-4325-88b3-02a20525e5ef';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-5ebe10e4-0ba5-458c-99f8-5505572fed5a';
  $handler->conf['display'] = $display;
  $export['site_template__panel_context_9f2b4c28-164e-4a94-b08b-abb7ea04f63c'] = $handler;

  return $export;
}
