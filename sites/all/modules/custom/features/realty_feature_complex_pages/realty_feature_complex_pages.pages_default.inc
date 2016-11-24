<?php
/**
 * @file
 * realty_feature_complex_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function realty_feature_complex_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'complex_mortgage';
  $page->task = 'page';
  $page->admin_title = 'Жилой комплекс - Ипотека';
  $page->admin_description = '';
  $page->path = 'complexes/%name/mortgage';
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
  $handler->name = 'page_complex_mortgage__panel_context_af286974-b57c-4efa-914a-f0304cef1561';
  $handler->task = 'page';
  $handler->subtask = 'complex_mortgage';
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
    'panels_everywhere_site_template' => 'site_template__panel_context_85e7b2d9-5028-4a9a-b93d-8279bcb20c3a',
    'pathalias' => '%name:title/mortgage',
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
  $display->uuid = 'bd7ecbd5-7515-4f71-b86b-032f1b1ab1fd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9f9f393a-a07c-42ed-8981-3631d4aa4939';
    $pane->panel = 'middle';
    $pane->type = 'bank_mortgage';
    $pane->subtype = 'bank_mortgage';
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
    $pane->uuid = '9f9f393a-a07c-42ed-8981-3631d4aa4939';
    $display->content['new-9f9f393a-a07c-42ed-8981-3631d4aa4939'] = $pane;
    $display->panels['middle'][0] = 'new-9f9f393a-a07c-42ed-8981-3631d4aa4939';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['complex_mortgage'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'documents';
  $page->task = 'page';
  $page->admin_title = 'Докуметы';
  $page->admin_description = '';
  $page->path = 'complexes/%name/documents';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Материал: ID',
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
  $handler->name = 'page_documents__panel_context_5230c72c-2e70-4708-b813-3e17ab207274';
  $handler->task = 'page';
  $handler->subtask = 'documents';
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
    'panels_everywhere_site_template' => 'site_template__panel_context_85e7b2d9-5028-4a9a-b93d-8279bcb20c3a',
    'pathalias' => '%name:title/documents',
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
  $display->title = 'Документы';
  $display->uuid = 'b56b89e6-6813-4486-908d-7951cf395baa';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0a357ab4-1811-4a04-9017-24dd1208848b';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'complex-complex_documents';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0a357ab4-1811-4a04-9017-24dd1208848b';
    $display->content['new-0a357ab4-1811-4a04-9017-24dd1208848b'] = $pane;
    $display->panels['middle'][0] = 'new-0a357ab4-1811-4a04-9017-24dd1208848b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['documents'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'gallery';
  $page->task = 'page';
  $page->admin_title = 'Галерея';
  $page->admin_description = '';
  $page->path = 'complexes/%name/photo';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Материал: ID',
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
  $handler->name = 'page_gallery__panel_context_b0d676ab-1337-4d7d-bef0-afc8301e6402';
  $handler->task = 'page';
  $handler->subtask = 'gallery';
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
    'panels_everywhere_site_template' => 'site_template__panel_context_85e7b2d9-5028-4a9a-b93d-8279bcb20c3a',
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
  $display->title = 'Дневники стройки';
  $display->uuid = '626475fc-2917-4448-b87a-322b5233bcf1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7bc53049-1e20-4126-80e1-ebe1aba99b04';
    $pane->panel = 'middle';
    $pane->type = 'menu_complex_gallery';
    $pane->subtype = 'menu_complex_gallery';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7bc53049-1e20-4126-80e1-ebe1aba99b04';
    $display->content['new-7bc53049-1e20-4126-80e1-ebe1aba99b04'] = $pane;
    $display->panels['middle'][0] = 'new-7bc53049-1e20-4126-80e1-ebe1aba99b04';
    $pane = new stdClass();
    $pane->pid = 'new-278957f8-a5ce-4cce-8d2b-780dbb683eb1';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'complex-gallery_photo';
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
    $pane->uuid = '278957f8-a5ce-4cce-8d2b-780dbb683eb1';
    $display->content['new-278957f8-a5ce-4cce-8d2b-780dbb683eb1'] = $pane;
    $display->panels['middle'][1] = 'new-278957f8-a5ce-4cce-8d2b-780dbb683eb1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['gallery'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'gallery_tour';
  $page->task = 'page';
  $page->admin_title = '';
  $page->admin_description = '';
  $page->path = 'complexes/%name/tour';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Материал: ID',
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
  $handler->name = 'page_gallery_tour__panel_context_fb26f217-1f13-44de-a4a3-9f2206309b3d';
  $handler->task = 'page';
  $handler->subtask = 'gallery_tour';
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
    'panels_everywhere_site_template' => 'site_template__panel_context_85e7b2d9-5028-4a9a-b93d-8279bcb20c3a',
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
  $display->title = '3D Тур';
  $display->uuid = 'ad6d5f2f-4cde-4d1e-ae8e-c07762163b48';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-70cf041d-6925-408d-ad68-e1592f7f6387';
    $pane->panel = 'middle';
    $pane->type = 'menu_complex_gallery';
    $pane->subtype = 'menu_complex_gallery';
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
    $pane->uuid = '70cf041d-6925-408d-ad68-e1592f7f6387';
    $display->content['new-70cf041d-6925-408d-ad68-e1592f7f6387'] = $pane;
    $display->panels['middle'][0] = 'new-70cf041d-6925-408d-ad68-e1592f7f6387';
    $pane = new stdClass();
    $pane->pid = 'new-9534a62c-cffd-4ac5-8805-4597aa890e12';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'complex-gallery_tours';
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
    $pane->uuid = '9534a62c-cffd-4ac5-8805-4597aa890e12';
    $display->content['new-9534a62c-cffd-4ac5-8805-4597aa890e12'] = $pane;
    $display->panels['middle'][1] = 'new-9534a62c-cffd-4ac5-8805-4597aa890e12';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['gallery_tour'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'page_complex_reviews';
  $page->task = 'page';
  $page->admin_title = 'Жилой комплекс - Отзывы';
  $page->admin_description = '';
  $page->path = 'complexes/%name/reviews';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Node edit form: node ID',
      'name' => 'node_edit',
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
  $handler->name = 'page_page_complex_reviews__panel_context_253ecd7f-1497-4c2a-9215-a5c0e4d27a3b';
  $handler->task = 'page';
  $handler->subtask = 'page_complex_reviews';
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
    'panels_everywhere_site_template' => 'site_template__panel_context_85e7b2d9-5028-4a9a-b93d-8279bcb20c3a',
    'pathalias' => '%name:title/reviews',
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
  $display->uuid = '247fa7c7-89a1-45eb-8f2c-8761f2ab4f07';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-08531885-6f1c-426e-9bcc-552a33dd03d8';
    $pane->panel = 'middle';
    $pane->type = 'comment_complex';
    $pane->subtype = 'comment_complex';
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
    $pane->uuid = '08531885-6f1c-426e-9bcc-552a33dd03d8';
    $display->content['new-08531885-6f1c-426e-9bcc-552a33dd03d8'] = $pane;
    $display->panels['middle'][0] = 'new-08531885-6f1c-426e-9bcc-552a33dd03d8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['page_complex_reviews'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'plan_complex';
  $page->task = 'page';
  $page->admin_title = 'Выбрать квартиру';
  $page->admin_description = '';
  $page->path = 'complexes/%name/plan';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Материал: ID',
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
  $handler->name = 'page_plan_complex__panel_context_bcd0f298-5d3f-4a92-9b13-8a9987b01f34';
  $handler->task = 'page';
  $handler->subtask = 'plan_complex';
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
    'panels_everywhere_site_template' => 'site_template__panel_context_85e7b2d9-5028-4a9a-b93d-8279bcb20c3a',
    'pathalias' => '%name:title/plan',
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
  $display->title = 'План ЖК';
  $display->uuid = '531b5829-cd5b-431e-9888-a4ca8d21cc91';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4b13ff07-38b2-49e2-b9be-f38c2fce62e8';
    $pane->panel = 'middle';
    $pane->type = 'plan_complex';
    $pane->subtype = 'plan_complex';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4b13ff07-38b2-49e2-b9be-f38c2fce62e8';
    $display->content['new-4b13ff07-38b2-49e2-b9be-f38c2fce62e8'] = $pane;
    $display->panels['middle'][0] = 'new-4b13ff07-38b2-49e2-b9be-f38c2fce62e8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['plan_complex'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'stock';
  $page->task = 'page';
  $page->admin_title = 'Акции';
  $page->admin_description = '';
  $page->path = 'complexes/%name/stock';
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
  $handler->name = 'page_stock__panel_context_eba581c5-80f1-4502-82b3-160ec6782580';
  $handler->task = 'page';
  $handler->subtask = 'stock';
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
    'panels_everywhere_site_template' => 'site_template__panel_context_85e7b2d9-5028-4a9a-b93d-8279bcb20c3a',
    'pathalias' => '%name:title/stock',
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
  $display->uuid = '23c0f35a-3a37-4a98-9750-d6f0071ca094';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-abf84972-475c-40a9-ac92-8b4315047f69';
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
    $pane->uuid = 'abf84972-475c-40a9-ac92-8b4315047f69';
    $display->content['new-abf84972-475c-40a9-ac92-8b4315047f69'] = $pane;
    $display->panels['middle'][0] = 'new-abf84972-475c-40a9-ac92-8b4315047f69';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['stock'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'visualization';
  $page->task = 'page';
  $page->admin_title = '';
  $page->admin_description = '';
  $page->path = 'complexes/%name/gallery';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'name' => array(
      'id' => 1,
      'identifier' => 'Материал: ID',
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
  $handler->name = 'page_visualization__panel_context_5a544316-71a7-43b2-b184-07efb87762e5';
  $handler->task = 'page';
  $handler->subtask = 'visualization';
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
    'panels_everywhere_site_template' => 'site_template__panel_context_85e7b2d9-5028-4a9a-b93d-8279bcb20c3a',
    'pathalias' => '%name:title/gallery',
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
  $display->uuid = '27a36169-7597-4d34-8c16-ce4bf81475d4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6d51950c-d5d0-471d-940c-ad8ba35435c9';
    $pane->panel = 'middle';
    $pane->type = 'complex_gallery';
    $pane->subtype = 'complex_gallery';
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
    $pane->uuid = '6d51950c-d5d0-471d-940c-ad8ba35435c9';
    $display->content['new-6d51950c-d5d0-471d-940c-ad8ba35435c9'] = $pane;
    $display->panels['middle'][0] = 'new-6d51950c-d5d0-471d-940c-ad8ba35435c9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['visualization'] = $page;

  return $pages;

}
