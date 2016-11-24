<?php
/**
 * @file
 * realty_feature_helper_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function realty_feature_helper_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'contacts';
  $page->task = 'page';
  $page->admin_title = 'Контакты';
  $page->admin_description = '';
  $page->path = 'contacts';
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
  $handler->name = 'page_contacts__panel_context_4c9d9435-5d82-489d-8821-394658c280e3';
  $handler->task = 'page';
  $handler->subtask = 'contacts';
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
        'description' => array(
          'value' => 'Все предложения в новостройках напрямую от застройщиков.',
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
  $display->title = 'Контакты';
  $display->uuid = 'f87ad7ce-0abe-4d4a-8d52-b3986b6fab1e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-58fdded6-3f3c-43c0-bc48-45ea1e1b4ae9';
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
    $pane->uuid = '58fdded6-3f3c-43c0-bc48-45ea1e1b4ae9';
    $display->content['new-58fdded6-3f3c-43c0-bc48-45ea1e1b4ae9'] = $pane;
    $display->panels['middle'][0] = 'new-58fdded6-3f3c-43c0-bc48-45ea1e1b4ae9';
    $pane = new stdClass();
    $pane->pid = 'new-f7731823-fb8e-4d5d-9b66-b568489c113f';
    $pane->panel = 'middle';
    $pane->type = 'menu_helper';
    $pane->subtype = 'menu_helper';
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
    $pane->uuid = 'f7731823-fb8e-4d5d-9b66-b568489c113f';
    $display->content['new-f7731823-fb8e-4d5d-9b66-b568489c113f'] = $pane;
    $display->panels['middle'][1] = 'new-f7731823-fb8e-4d5d-9b66-b568489c113f';
    $pane = new stdClass();
    $pane->pid = 'new-9f9bc6c0-aeb9-474d-8345-cd317032bd93';
    $pane->panel = 'middle';
    $pane->type = 'reference_book';
    $pane->subtype = 'reference_book';
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
    $pane->uuid = '9f9bc6c0-aeb9-474d-8345-cd317032bd93';
    $display->content['new-9f9bc6c0-aeb9-474d-8345-cd317032bd93'] = $pane;
    $display->panels['middle'][2] = 'new-9f9bc6c0-aeb9-474d-8345-cd317032bd93';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-58fdded6-3f3c-43c0-bc48-45ea1e1b4ae9';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['contacts'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'cooperation';
  $page->task = 'page';
  $page->admin_title = 'Сотрудничество';
  $page->admin_description = '';
  $page->path = 'cooperation';
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
  $handler->name = 'page_cooperation__panel_context_ed391afc-5bf0-451e-8bfb-451f8a5770fe';
  $handler->task = 'page';
  $handler->subtask = 'cooperation';
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
        'description' => array(
          'value' => 'Все предложения в новостройках напрямую от застройщиков.',
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
  $display->title = 'Сотрудничество';
  $display->uuid = 'f5b43995-7e92-4a6e-82a0-95714b01a4f7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e995ec80-4ad5-4e03-ad64-4d375d951b7b';
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
    $pane->uuid = 'e995ec80-4ad5-4e03-ad64-4d375d951b7b';
    $display->content['new-e995ec80-4ad5-4e03-ad64-4d375d951b7b'] = $pane;
    $display->panels['middle'][0] = 'new-e995ec80-4ad5-4e03-ad64-4d375d951b7b';
    $pane = new stdClass();
    $pane->pid = 'new-a1c2e7aa-7da1-4f34-85cc-1ae1dff520e2';
    $pane->panel = 'middle';
    $pane->type = 'menu_helper';
    $pane->subtype = 'menu_helper';
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
    $pane->uuid = 'a1c2e7aa-7da1-4f34-85cc-1ae1dff520e2';
    $display->content['new-a1c2e7aa-7da1-4f34-85cc-1ae1dff520e2'] = $pane;
    $display->panels['middle'][1] = 'new-a1c2e7aa-7da1-4f34-85cc-1ae1dff520e2';
    $pane = new stdClass();
    $pane->pid = 'new-1a52c6b9-5a91-42fa-9f49-2d6710cf2fc4';
    $pane->panel = 'middle';
    $pane->type = 'reference_book';
    $pane->subtype = 'reference_book';
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
    $pane->uuid = '1a52c6b9-5a91-42fa-9f49-2d6710cf2fc4';
    $display->content['new-1a52c6b9-5a91-42fa-9f49-2d6710cf2fc4'] = $pane;
    $display->panels['middle'][2] = 'new-1a52c6b9-5a91-42fa-9f49-2d6710cf2fc4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e995ec80-4ad5-4e03-ad64-4d375d951b7b';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['cooperation'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'faq';
  $page->task = 'page';
  $page->admin_title = 'FAQ';
  $page->admin_description = '';
  $page->path = 'faq';
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
  $handler->name = 'page_faq__panel_context_5587c6ed-ec92-460d-8268-92e596f8f11c';
  $handler->task = 'page';
  $handler->subtask = 'faq';
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
  $display->title = 'FAQ';
  $display->uuid = '9840b4eb-84ee-440a-8f6f-49a07b0e1d9e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3e286bfd-95e9-4b14-8c05-4f52ee3b7fea';
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
    $pane->uuid = '3e286bfd-95e9-4b14-8c05-4f52ee3b7fea';
    $display->content['new-3e286bfd-95e9-4b14-8c05-4f52ee3b7fea'] = $pane;
    $display->panels['middle'][0] = 'new-3e286bfd-95e9-4b14-8c05-4f52ee3b7fea';
    $pane = new stdClass();
    $pane->pid = 'new-b7320fb6-51d2-4151-8fe2-e1797698e5d0';
    $pane->panel = 'middle';
    $pane->type = 'menu_helper';
    $pane->subtype = 'menu_helper';
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
    $pane->uuid = 'b7320fb6-51d2-4151-8fe2-e1797698e5d0';
    $display->content['new-b7320fb6-51d2-4151-8fe2-e1797698e5d0'] = $pane;
    $display->panels['middle'][1] = 'new-b7320fb6-51d2-4151-8fe2-e1797698e5d0';
    $pane = new stdClass();
    $pane->pid = 'new-cd490965-307e-4639-8f3c-bda96c6dca26';
    $pane->panel = 'middle';
    $pane->type = 'reference_book';
    $pane->subtype = 'reference_book';
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
    $pane->uuid = 'cd490965-307e-4639-8f3c-bda96c6dca26';
    $display->content['new-cd490965-307e-4639-8f3c-bda96c6dca26'] = $pane;
    $display->panels['middle'][2] = 'new-cd490965-307e-4639-8f3c-bda96c6dca26';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3e286bfd-95e9-4b14-8c05-4f52ee3b7fea';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['faq'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'guide';
  $page->task = 'page';
  $page->admin_title = 'Путеводитель';
  $page->admin_description = '';
  $page->path = 'guide';
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
  $handler->name = 'page_guide__panel_context_f664ef72-110c-417d-9f9f-8cb66f517756';
  $handler->task = 'page';
  $handler->subtask = 'guide';
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
        'description' => array(
          'value' => 'Все предложения в новостройках напрямую от застройщиков.',
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
  $display->title = 'Путеводитель';
  $display->uuid = '6762f428-ec92-4ae6-8ce3-12f56c9b235b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a9c38bee-fff6-42d9-ba8a-361d6f073697';
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
    $pane->uuid = 'a9c38bee-fff6-42d9-ba8a-361d6f073697';
    $display->content['new-a9c38bee-fff6-42d9-ba8a-361d6f073697'] = $pane;
    $display->panels['middle'][0] = 'new-a9c38bee-fff6-42d9-ba8a-361d6f073697';
    $pane = new stdClass();
    $pane->pid = 'new-e27b855b-7d73-470a-b063-1e9fe305b999';
    $pane->panel = 'middle';
    $pane->type = 'menu_helper';
    $pane->subtype = 'menu_helper';
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
    $pane->uuid = 'e27b855b-7d73-470a-b063-1e9fe305b999';
    $display->content['new-e27b855b-7d73-470a-b063-1e9fe305b999'] = $pane;
    $display->panels['middle'][1] = 'new-e27b855b-7d73-470a-b063-1e9fe305b999';
    $pane = new stdClass();
    $pane->pid = 'new-0c417222-664e-4ac6-80ca-d5ad1f193163';
    $pane->panel = 'middle';
    $pane->type = 'reference_book';
    $pane->subtype = 'reference_book';
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
    $pane->uuid = '0c417222-664e-4ac6-80ca-d5ad1f193163';
    $display->content['new-0c417222-664e-4ac6-80ca-d5ad1f193163'] = $pane;
    $display->panels['middle'][2] = 'new-0c417222-664e-4ac6-80ca-d5ad1f193163';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e27b855b-7d73-470a-b063-1e9fe305b999';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['guide'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'policy';
  $page->task = 'page';
  $page->admin_title = 'Политика';
  $page->admin_description = '';
  $page->path = 'policy';
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
  $handler->name = 'page_policy__panel_context_38bcb4b8-3d10-4f60-8de6-95691f9f6af3';
  $handler->task = 'page';
  $handler->subtask = 'policy';
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
        'description' => array(
          'value' => 'Все предложения в новостройках напрямую от застройщиков.',
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
  $display->title = 'Политика';
  $display->uuid = 'c5e6aa37-dca2-4e2e-b549-1f825471383e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b742001f-8679-40c0-8192-40771374e31b';
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
    $pane->uuid = 'b742001f-8679-40c0-8192-40771374e31b';
    $display->content['new-b742001f-8679-40c0-8192-40771374e31b'] = $pane;
    $display->panels['middle'][0] = 'new-b742001f-8679-40c0-8192-40771374e31b';
    $pane = new stdClass();
    $pane->pid = 'new-133bd876-26fd-49fc-968e-0e6231623975';
    $pane->panel = 'middle';
    $pane->type = 'menu_helper';
    $pane->subtype = 'menu_helper';
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
    $pane->uuid = '133bd876-26fd-49fc-968e-0e6231623975';
    $display->content['new-133bd876-26fd-49fc-968e-0e6231623975'] = $pane;
    $display->panels['middle'][1] = 'new-133bd876-26fd-49fc-968e-0e6231623975';
    $pane = new stdClass();
    $pane->pid = 'new-dff6c166-2108-45ea-992c-d8295cd561c0';
    $pane->panel = 'middle';
    $pane->type = 'reference_book';
    $pane->subtype = 'reference_book';
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
    $pane->uuid = 'dff6c166-2108-45ea-992c-d8295cd561c0';
    $display->content['new-dff6c166-2108-45ea-992c-d8295cd561c0'] = $pane;
    $display->panels['middle'][2] = 'new-dff6c166-2108-45ea-992c-d8295cd561c0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b742001f-8679-40c0-8192-40771374e31b';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['policy'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'remunerations';
  $page->task = 'page';
  $page->admin_title = 'Вознаграждения';
  $page->admin_description = '';
  $page->path = 'remunerations';
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
  $handler->name = 'page_remunerations__panel_context_0c1dd3d3-4d3a-4afa-b5d6-14f2da2e2228';
  $handler->task = 'page';
  $handler->subtask = 'remunerations';
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
  $display->title = 'Вознаграждения';
  $display->uuid = '3df06640-eafb-48f6-a998-2527b955dc34';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6f53ef35-c5d5-47ac-a2a4-f76781351582';
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
    $pane->uuid = '6f53ef35-c5d5-47ac-a2a4-f76781351582';
    $display->content['new-6f53ef35-c5d5-47ac-a2a4-f76781351582'] = $pane;
    $display->panels['middle'][0] = 'new-6f53ef35-c5d5-47ac-a2a4-f76781351582';
    $pane = new stdClass();
    $pane->pid = 'new-aef00571-4686-41dd-978d-1eb8511123bf';
    $pane->panel = 'middle';
    $pane->type = 'menu_helper';
    $pane->subtype = 'menu_helper';
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
    $pane->uuid = 'aef00571-4686-41dd-978d-1eb8511123bf';
    $display->content['new-aef00571-4686-41dd-978d-1eb8511123bf'] = $pane;
    $display->panels['middle'][1] = 'new-aef00571-4686-41dd-978d-1eb8511123bf';
    $pane = new stdClass();
    $pane->pid = 'new-425fd1b5-5d51-4fb3-957c-f40adb5c238a';
    $pane->panel = 'middle';
    $pane->type = 'reference_book';
    $pane->subtype = 'reference_book';
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
    $pane->uuid = '425fd1b5-5d51-4fb3-957c-f40adb5c238a';
    $display->content['new-425fd1b5-5d51-4fb3-957c-f40adb5c238a'] = $pane;
    $display->panels['middle'][2] = 'new-425fd1b5-5d51-4fb3-957c-f40adb5c238a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6f53ef35-c5d5-47ac-a2a4-f76781351582';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['remunerations'] = $page;

  return $pages;

}
