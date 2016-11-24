<?php
/**
 * @file
 * realty_feature_apartment_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function realty_feature_apartment_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'apartment_documents';
  $page->task = 'page';
  $page->admin_title = 'Документы квартиры';
  $page->admin_description = '';
  $page->path = 'apartment/%name/documents';
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
  $handler->name = 'page_apartment_documents__panel_context_95d6f13a-608f-42e5-b6fc-4953e94561a5';
  $handler->task = 'page';
  $handler->subtask = 'apartment_documents';
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
  $display->title = 'Документы';
  $display->uuid = '805ae837-8e49-41cd-a2a4-e80a3733f04f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-03ef21e4-dee5-4b79-b0e4-ae445f5ffd70';
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
    $pane->uuid = '03ef21e4-dee5-4b79-b0e4-ae445f5ffd70';
    $display->content['new-03ef21e4-dee5-4b79-b0e4-ae445f5ffd70'] = $pane;
    $display->panels['middle'][0] = 'new-03ef21e4-dee5-4b79-b0e4-ae445f5ffd70';
    $pane = new stdClass();
    $pane->pid = 'new-cfe28b62-fe79-4ac8-8e06-ae166adada6f';
    $pane->panel = 'middle';
    $pane->type = 'menu_apartment';
    $pane->subtype = 'menu_apartment';
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
    $pane->uuid = 'cfe28b62-fe79-4ac8-8e06-ae166adada6f';
    $display->content['new-cfe28b62-fe79-4ac8-8e06-ae166adada6f'] = $pane;
    $display->panels['middle'][1] = 'new-cfe28b62-fe79-4ac8-8e06-ae166adada6f';
    $pane = new stdClass();
    $pane->pid = 'new-642bcd94-8678-408c-ba8e-fdb5103de259';
    $pane->panel = 'middle';
    $pane->type = 'apartment_documents';
    $pane->subtype = 'apartment_documents';
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
    $pane->uuid = '642bcd94-8678-408c-ba8e-fdb5103de259';
    $display->content['new-642bcd94-8678-408c-ba8e-fdb5103de259'] = $pane;
    $display->panels['middle'][2] = 'new-642bcd94-8678-408c-ba8e-fdb5103de259';
    $pane = new stdClass();
    $pane->pid = 'new-4d93b5d8-f799-4d68-a9e8-25021ceb452b';
    $pane->panel = 'middle';
    $pane->type = 'apartment_complex';
    $pane->subtype = 'apartment_complex';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '4d93b5d8-f799-4d68-a9e8-25021ceb452b';
    $display->content['new-4d93b5d8-f799-4d68-a9e8-25021ceb452b'] = $pane;
    $display->panels['middle'][3] = 'new-4d93b5d8-f799-4d68-a9e8-25021ceb452b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-03ef21e4-dee5-4b79-b0e4-ae445f5ffd70';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['apartment_documents'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'apartment_mortgage';
  $page->task = 'page';
  $page->admin_title = 'Квартира - Ипотека';
  $page->admin_description = '';
  $page->path = 'apartment/%name/mortgage';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
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
  $handler->name = 'page_apartment_mortgage__panel_context_cb5f7b97-ae3d-4594-80af-9bdfa0309d42';
  $handler->task = 'page';
  $handler->subtask = 'apartment_mortgage';
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
  $display->uuid = '8239b3de-8da5-47c3-9c73-5a9f25629cfd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5fc7c725-b33d-4c75-bfcf-6074fe8f7b33';
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
    $pane->uuid = '5fc7c725-b33d-4c75-bfcf-6074fe8f7b33';
    $display->content['new-5fc7c725-b33d-4c75-bfcf-6074fe8f7b33'] = $pane;
    $display->panels['middle'][0] = 'new-5fc7c725-b33d-4c75-bfcf-6074fe8f7b33';
    $pane = new stdClass();
    $pane->pid = 'new-c8422726-1dbf-4dbe-8cac-c09f4377d39e';
    $pane->panel = 'middle';
    $pane->type = 'menu_apartment';
    $pane->subtype = 'menu_apartment';
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
    $pane->uuid = 'c8422726-1dbf-4dbe-8cac-c09f4377d39e';
    $display->content['new-c8422726-1dbf-4dbe-8cac-c09f4377d39e'] = $pane;
    $display->panels['middle'][1] = 'new-c8422726-1dbf-4dbe-8cac-c09f4377d39e';
    $pane = new stdClass();
    $pane->pid = 'new-2697ab08-528f-401e-af79-02f8684e8a70';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '2697ab08-528f-401e-af79-02f8684e8a70';
    $display->content['new-2697ab08-528f-401e-af79-02f8684e8a70'] = $pane;
    $display->panels['middle'][2] = 'new-2697ab08-528f-401e-af79-02f8684e8a70';
    $pane = new stdClass();
    $pane->pid = 'new-356b89fb-615c-43c1-920f-211773daf87d';
    $pane->panel = 'middle';
    $pane->type = 'apartment_complex';
    $pane->subtype = 'apartment_complex';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '356b89fb-615c-43c1-920f-211773daf87d';
    $display->content['new-356b89fb-615c-43c1-920f-211773daf87d'] = $pane;
    $display->panels['middle'][3] = 'new-356b89fb-615c-43c1-920f-211773daf87d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5fc7c725-b33d-4c75-bfcf-6074fe8f7b33';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['apartment_mortgage'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'apartment_plan';
  $page->task = 'page';
  $page->admin_title = 'Квартира - Расположение';
  $page->admin_description = '';
  $page->path = 'apartment/%name/plan';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
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
  $handler->name = 'page_apartment_plan__panel_context_4f6fd4db-d5db-4a49-a35e-c44babb4681a';
  $handler->task = 'page';
  $handler->subtask = 'apartment_plan';
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
  $display->title = 'Расположение';
  $display->uuid = '5f499071-07fa-4a9b-ab46-6d61a949597a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fecb237a-5a5a-490c-9e49-03a363e17099';
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
    $pane->uuid = 'fecb237a-5a5a-490c-9e49-03a363e17099';
    $display->content['new-fecb237a-5a5a-490c-9e49-03a363e17099'] = $pane;
    $display->panels['middle'][0] = 'new-fecb237a-5a5a-490c-9e49-03a363e17099';
    $pane = new stdClass();
    $pane->pid = 'new-26579274-e2a6-4358-b8e1-ca53d925f225';
    $pane->panel = 'middle';
    $pane->type = 'menu_apartment';
    $pane->subtype = 'menu_apartment';
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
    $pane->uuid = '26579274-e2a6-4358-b8e1-ca53d925f225';
    $display->content['new-26579274-e2a6-4358-b8e1-ca53d925f225'] = $pane;
    $display->panels['middle'][1] = 'new-26579274-e2a6-4358-b8e1-ca53d925f225';
    $pane = new stdClass();
    $pane->pid = 'new-6e4ee85c-c2eb-4068-b37c-a426c87d64a2';
    $pane->panel = 'middle';
    $pane->type = 'plan_complex';
    $pane->subtype = 'plan_complex';
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
    $pane->uuid = '6e4ee85c-c2eb-4068-b37c-a426c87d64a2';
    $display->content['new-6e4ee85c-c2eb-4068-b37c-a426c87d64a2'] = $pane;
    $display->panels['middle'][2] = 'new-6e4ee85c-c2eb-4068-b37c-a426c87d64a2';
    $pane = new stdClass();
    $pane->pid = 'new-067702bd-9f8b-4ae6-915c-b99c575a7e9f';
    $pane->panel = 'middle';
    $pane->type = 'apartment_complex';
    $pane->subtype = 'apartment_complex';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '067702bd-9f8b-4ae6-915c-b99c575a7e9f';
    $display->content['new-067702bd-9f8b-4ae6-915c-b99c575a7e9f'] = $pane;
    $display->panels['middle'][3] = 'new-067702bd-9f8b-4ae6-915c-b99c575a7e9f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6e4ee85c-c2eb-4068-b37c-a426c87d64a2';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['apartment_plan'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'apartment_purchase_terms';
  $page->task = 'page';
  $page->admin_title = 'Условия покупки квартиры';
  $page->admin_description = '';
  $page->path = 'apartment/%name/purchase_terms';
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
  $handler->name = 'page_apartment_purchase_terms__panel_context_49c31ead-1f10-4527-b434-8248c3afb5ee';
  $handler->task = 'page';
  $handler->subtask = 'apartment_purchase_terms';
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
  $display->title = 'Условия покупки';
  $display->uuid = '63265df6-669b-492f-8940-80f43af12d0a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-cefe9af4-ece5-471c-b7a6-867f1dc121d4';
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
    $pane->uuid = 'cefe9af4-ece5-471c-b7a6-867f1dc121d4';
    $display->content['new-cefe9af4-ece5-471c-b7a6-867f1dc121d4'] = $pane;
    $display->panels['middle'][0] = 'new-cefe9af4-ece5-471c-b7a6-867f1dc121d4';
    $pane = new stdClass();
    $pane->pid = 'new-1675d0fd-fdfb-4332-ae00-82846f0c27b4';
    $pane->panel = 'middle';
    $pane->type = 'menu_apartment';
    $pane->subtype = 'menu_apartment';
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
    $pane->uuid = '1675d0fd-fdfb-4332-ae00-82846f0c27b4';
    $display->content['new-1675d0fd-fdfb-4332-ae00-82846f0c27b4'] = $pane;
    $display->panels['middle'][1] = 'new-1675d0fd-fdfb-4332-ae00-82846f0c27b4';
    $pane = new stdClass();
    $pane->pid = 'new-077a633a-e433-46f0-9338-3f24d4ce6497';
    $pane->panel = 'middle';
    $pane->type = 'apartment_purchase_terms';
    $pane->subtype = 'apartment_purchase_terms';
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
    $pane->uuid = '077a633a-e433-46f0-9338-3f24d4ce6497';
    $display->content['new-077a633a-e433-46f0-9338-3f24d4ce6497'] = $pane;
    $display->panels['middle'][2] = 'new-077a633a-e433-46f0-9338-3f24d4ce6497';
    $pane = new stdClass();
    $pane->pid = 'new-9824796b-0f05-4bb5-adfd-19baffc596cb';
    $pane->panel = 'middle';
    $pane->type = 'apartment_complex';
    $pane->subtype = 'apartment_complex';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '9824796b-0f05-4bb5-adfd-19baffc596cb';
    $display->content['new-9824796b-0f05-4bb5-adfd-19baffc596cb'] = $pane;
    $display->panels['middle'][3] = 'new-9824796b-0f05-4bb5-adfd-19baffc596cb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-cefe9af4-ece5-471c-b7a6-867f1dc121d4';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['apartment_purchase_terms'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'apartment_visualization';
  $page->task = 'page';
  $page->admin_title = 'Визуализация квартиры';
  $page->admin_description = '';
  $page->path = 'apartment/%name/visualization';
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
  $handler->name = 'page_apartment_visualization__panel_context_5835dbf4-0f01-4670-acec-b4d239fb4bb7';
  $handler->task = 'page';
  $handler->subtask = 'apartment_visualization';
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
  $display->title = 'Визуализация';
  $display->uuid = '891b691a-8ca6-4bd2-8c40-22f94db2bb5f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-35072718-2b7c-45c2-893b-aa94ff85fd34';
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
    $pane->uuid = '35072718-2b7c-45c2-893b-aa94ff85fd34';
    $display->content['new-35072718-2b7c-45c2-893b-aa94ff85fd34'] = $pane;
    $display->panels['middle'][0] = 'new-35072718-2b7c-45c2-893b-aa94ff85fd34';
    $pane = new stdClass();
    $pane->pid = 'new-17b27e31-984e-4d16-bbcf-f3873f2d7c88';
    $pane->panel = 'middle';
    $pane->type = 'menu_apartment';
    $pane->subtype = 'menu_apartment';
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
    $pane->uuid = '17b27e31-984e-4d16-bbcf-f3873f2d7c88';
    $display->content['new-17b27e31-984e-4d16-bbcf-f3873f2d7c88'] = $pane;
    $display->panels['middle'][1] = 'new-17b27e31-984e-4d16-bbcf-f3873f2d7c88';
    $pane = new stdClass();
    $pane->pid = 'new-72f09d2d-3162-4760-98ad-fac0592c9860';
    $pane->panel = 'middle';
    $pane->type = 'apartment_visualization';
    $pane->subtype = 'apartment_visualization';
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
    $pane->uuid = '72f09d2d-3162-4760-98ad-fac0592c9860';
    $display->content['new-72f09d2d-3162-4760-98ad-fac0592c9860'] = $pane;
    $display->panels['middle'][2] = 'new-72f09d2d-3162-4760-98ad-fac0592c9860';
    $pane = new stdClass();
    $pane->pid = 'new-f7de2940-306b-4841-8449-657dbb3b9503';
    $pane->panel = 'middle';
    $pane->type = 'apartment_complex';
    $pane->subtype = 'apartment_complex';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'f7de2940-306b-4841-8449-657dbb3b9503';
    $display->content['new-f7de2940-306b-4841-8449-657dbb3b9503'] = $pane;
    $display->panels['middle'][3] = 'new-f7de2940-306b-4841-8449-657dbb3b9503';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['apartment_visualization'] = $page;

  return $pages;

}
