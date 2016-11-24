<?php
/**
 * @file
 * realty_feature_page_node.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function realty_feature_page_node_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__basic_page';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Страница',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'basic_page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'basic_page' => 'basic_page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->title = '';
  $display->uuid = '4290087e-ae36-4338-b973-45eb7ac28e2c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c7ac315a-b224-4947-9a01-d8f2a9a41e8b';
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
    $pane->uuid = 'c7ac315a-b224-4947-9a01-d8f2a9a41e8b';
    $display->content['new-c7ac315a-b224-4947-9a01-d8f2a9a41e8b'] = $pane;
    $display->panels['middle'][0] = 'new-c7ac315a-b224-4947-9a01-d8f2a9a41e8b';
    $pane = new stdClass();
    $pane->pid = 'new-649bc391-1485-424b-ae1f-b7e22248a6f9';
    $pane->panel = 'middle';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 1,
      'override_title' => 0,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 1,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '649bc391-1485-424b-ae1f-b7e22248a6f9';
    $display->content['new-649bc391-1485-424b-ae1f-b7e22248a6f9'] = $pane;
    $display->panels['middle'][1] = 'new-649bc391-1485-424b-ae1f-b7e22248a6f9';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__basic_page'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_85d735dd-b4bf-40d4-9ee8-2c16bec08daf';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'Статья',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'myarticle' => 'myarticle',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
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
  $display->uuid = '08efbc00-d7d9-4867-9124-1d1c63480937';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5c4b2ef3-25e2-467b-8075-1e4f42c25fa9';
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
    $pane->uuid = '5c4b2ef3-25e2-467b-8075-1e4f42c25fa9';
    $display->content['new-5c4b2ef3-25e2-467b-8075-1e4f42c25fa9'] = $pane;
    $display->panels['middle'][0] = 'new-5c4b2ef3-25e2-467b-8075-1e4f42c25fa9';
    $pane = new stdClass();
    $pane->pid = 'new-50b4e730-877e-472e-b799-53e6283b45ad';
    $pane->panel = 'middle';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 0,
      'no_extras' => 1,
      'override_title' => 1,
      'override_title_text' => '<none>',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '50b4e730-877e-472e-b799-53e6283b45ad';
    $display->content['new-50b4e730-877e-472e-b799-53e6283b45ad'] = $pane;
    $display->panels['middle'][1] = 'new-50b4e730-877e-472e-b799-53e6283b45ad';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_85d735dd-b4bf-40d4-9ee8-2c16bec08daf'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__presentation';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'Презентация',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'presentation',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'presentation' => 'presentation',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template__panel_context_9f2b4c28-164e-4a94-b08b-abb7ea04f63c',
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'description' => array(
          'value' => '[site:name]. Все предложения в новостройках напрямую от застройщиков.',
        ),
        'keywords' => array(
          'value' => 'Новостройки, жилые комплексы, ипотека, застройщики, поиск квартир, квартиры, квартиры в новостройках, файндом, findome.',
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
  $display->uuid = 'f83a19ae-491d-4da7-b17a-ea5c3c2922f1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2819829f-f8f6-4cd3-b5e4-27e8464755db';
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
    $pane->uuid = '2819829f-f8f6-4cd3-b5e4-27e8464755db';
    $display->content['new-2819829f-f8f6-4cd3-b5e4-27e8464755db'] = $pane;
    $display->panels['middle'][0] = 'new-2819829f-f8f6-4cd3-b5e4-27e8464755db';
    $pane = new stdClass();
    $pane->pid = 'new-307208f8-6ed6-4c15-b44c-8f58b800accc';
    $pane->panel = 'middle';
    $pane->type = 'menu_helper';
    $pane->subtype = 'menu_helper';
    $pane->shown = TRUE;
    $pane->access = array(
      'logic' => 'and',
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '307208f8-6ed6-4c15-b44c-8f58b800accc';
    $display->content['new-307208f8-6ed6-4c15-b44c-8f58b800accc'] = $pane;
    $display->panels['middle'][1] = 'new-307208f8-6ed6-4c15-b44c-8f58b800accc';
    $pane = new stdClass();
    $pane->pid = 'new-762cbab6-97fe-4b44-9395-2faf413e4221';
    $pane->panel = 'middle';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 0,
      'no_extras' => 1,
      'override_title' => 1,
      'override_title_text' => '<none>',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '762cbab6-97fe-4b44-9395-2faf413e4221';
    $display->content['new-762cbab6-97fe-4b44-9395-2faf413e4221'] = $pane;
    $display->panels['middle'][2] = 'new-762cbab6-97fe-4b44-9395-2faf413e4221';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__presentation'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Жилой комплекс',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'complex' => 'complex',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template__panel_context_85e7b2d9-5028-4a9a-b93d-8279bcb20c3a',
    'metatag_panels' => array(
      'enabled' => 0,
      'metatags' => array(
        'description' => array(
          'value' => 'Поиск и сравнение квартир в [current-page:title] - планировки, инфраструктура, условия покупки, ипотечные программы, галерея.',
        ),
        'keywords' => array(
          'value' => '[current-page:title], квартиры в [current-page:title], планировка [current-page:title], планировки, квартира, комната, купить квартиру, купить [current-page:title], застройщик [current-page:title], [current-page:title], ипотека [current-page:title], Findome [current-page:title]',
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
      'top' => NULL,
      'content_left' => NULL,
      'content_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '152d0f9f-404c-4fb6-8e25-d13920194add';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-79f791b1-26ef-414f-9771-0928de310268';
    $pane->panel = 'middle';
    $pane->type = 'info_complex';
    $pane->subtype = 'info_complex';
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
    $pane->uuid = '79f791b1-26ef-414f-9771-0928de310268';
    $display->content['new-79f791b1-26ef-414f-9771-0928de310268'] = $pane;
    $display->panels['middle'][0] = 'new-79f791b1-26ef-414f-9771-0928de310268';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Квартира',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'apartament' => 'apartament',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template__panel_context_3d0c4bc6-cd97-49bd-be6a-26eec4a63b53',
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => '%node:breadcrumbs_appartment_title | [site:name]',
        ),
        'description' => array(
          'value' => '[site:name]  %node:complex_apartment - планировки, инфраструктура, условия покупки, ипотечные программы, галерея.',
        ),
        'keywords' => array(
          'value' => '%node:complex_apartment , квартиры в %node:complex_apartment , новостройки, новостройка, недвижимость, новосибирск, планировка, планировки, квартира, комната, дом, купить квартиру',
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
      'top' => NULL,
      'content_left' => NULL,
      'content_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Квартира ';
  $display->uuid = 'cddd9adc-744d-45c9-af12-e4b867ef9bbd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b50b053d-bbb0-4de0-a45d-8cd071e069dd';
    $pane->panel = 'middle';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array(
      'logic' => 'and',
    );
    $pane->configuration = array(
      'links' => 0,
      'no_extras' => 0,
      'override_title' => 1,
      'override_title_text' => '<none>',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array(
      'type' => 'none',
      'regions' => array(
        'top' => 'top',
      ),
    );
    $pane->uuid = 'b50b053d-bbb0-4de0-a45d-8cd071e069dd';
    $display->content['new-b50b053d-bbb0-4de0-a45d-8cd071e069dd'] = $pane;
    $display->panels['middle'][0] = 'new-b50b053d-bbb0-4de0-a45d-8cd071e069dd';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  return $export;
}
