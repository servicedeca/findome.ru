<?php
/**
 * @file
 * realty_faeture_page_taxonomy.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function realty_faeture_page_taxonomy_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__partner';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Партнер',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'partner',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'partners' => 'partners',
            ),
          ),
          'context' => 'argument_term_1',
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
  $display->uuid = 'd756ea50-fcc7-441d-b0fa-b08f41724619';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a5b0e3e2-8976-41b3-a5af-f9a3ccd9bdd2';
    $pane->panel = 'middle';
    $pane->type = 'bread_crumbs';
    $pane->subtype = 'bread_crumbs';
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
    $pane->uuid = 'a5b0e3e2-8976-41b3-a5af-f9a3ccd9bdd2';
    $display->content['new-a5b0e3e2-8976-41b3-a5af-f9a3ccd9bdd2'] = $pane;
    $display->panels['middle'][0] = 'new-a5b0e3e2-8976-41b3-a5af-f9a3ccd9bdd2';
    $pane = new stdClass();
    $pane->pid = 'new-b9b466e0-6ca8-4b51-9bae-2d22ba41d8d2';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'term_view-partner';
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
    $pane->uuid = 'b9b466e0-6ca8-4b51-9bae-2d22ba41d8d2';
    $display->content['new-b9b466e0-6ca8-4b51-9bae-2d22ba41d8d2'] = $pane;
    $display->panels['middle'][1] = 'new-b9b466e0-6ca8-4b51-9bae-2d22ba41d8d2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a5b0e3e2-8976-41b3-a5af-f9a3ccd9bdd2';
  $handler->conf['display'] = $display;
  $export['term_view__partner'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Застройщики',
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
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'developers' => 'developers',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template__panel_context_05a23155-d748-46e4-97fe-d996783aacf5',
    'metatag_panels' => array(
      'enabled' => 0,
      'metatags' => array(
        'description' => array(
          'value' => 'Поиск квартир в новостройках. Квартиры от [current-page:title]. [current-page:title] - условия покупки, ипотечные программы, галерея.
',
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
      'top' => NULL,
      'content_left' => NULL,
      'content_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b06a4c31-e6a4-47d8-bca9-9d96414b9fa3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ea26439e-2a55-4741-b538-3f312afa72c2';
    $pane->panel = 'middle';
    $pane->type = 'info_developer';
    $pane->subtype = 'info_developer';
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
    $pane->uuid = 'ea26439e-2a55-4741-b538-3f312afa72c2';
    $display->content['new-ea26439e-2a55-4741-b538-3f312afa72c2'] = $pane;
    $display->panels['middle'][0] = 'new-ea26439e-2a55-4741-b538-3f312afa72c2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context_2';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Город',
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
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'cities' => 'cities',
            ),
          ),
          'context' => 'argument_term_1',
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
          'value' => 'Сервис поиска и сравнения квартир в новостройках Новосибирска. На одной площадке представлены квартиры от ведущих застройщиков. Актуальный текущий статус квартир. Удобная форма сравнения квартир.',
        ),
        'keywords' => array(
          'value' => 'квартиры в новостройках, квартиры от застройщика, новостройки, новостройки от застройщика, купить квартиру, купить новостройку, поиск квартир, поисковик квартир, файндом, findome, выбрать квартиру, подобрать квартиру, финдом, сравнение квартир, новостройки Новосибирска, квартиры в новостройках Новосибирска, Новосибирск',
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
  $display->cache = array(
    'method' => 'panels_hash_cache',
    'settings' => array(
      'lifetime' => '14400',
      'granularity' => array(
        'args' => 'args',
        'context' => 'context',
        'url' => 'url',
        'path' => 'path',
        'user' => 'user',
        'user_role' => 'user_role',
      ),
      'granularity_roles_as_anon' => array(
        2 => 0,
        3 => 0,
      ),
      'granularity_role_selection' => 'all',
    ),
  );
  $display->title = '';
  $display->uuid = '564e541c-7e81-4530-b759-5d6998007176';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-36830686-d59c-4999-8fd3-76b26bc0a388';
    $pane->panel = 'middle';
    $pane->type = 'header_front';
    $pane->subtype = 'header_front';
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
          2 => '2',
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
    $pane->uuid = '36830686-d59c-4999-8fd3-76b26bc0a388';
    $display->content['new-36830686-d59c-4999-8fd3-76b26bc0a388'] = $pane;
    $display->panels['middle'][0] = 'new-36830686-d59c-4999-8fd3-76b26bc0a388';
    $pane = new stdClass();
    $pane->pid = 'new-4249fbeb-1564-4cf9-b37e-1f993a65baea';
    $pane->panel = 'middle';
    $pane->type = 'search_form';
    $pane->subtype = 'search_form';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4249fbeb-1564-4cf9-b37e-1f993a65baea';
    $display->content['new-4249fbeb-1564-4cf9-b37e-1f993a65baea'] = $pane;
    $display->panels['middle'][1] = 'new-4249fbeb-1564-4cf9-b37e-1f993a65baea';
    $pane = new stdClass();
    $pane->pid = 'new-992656e8-f99d-4db9-8356-dcf43f6db755';
    $pane->panel = 'middle';
    $pane->type = 'block_complexs';
    $pane->subtype = 'block_complexs';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '992656e8-f99d-4db9-8356-dcf43f6db755';
    $display->content['new-992656e8-f99d-4db9-8356-dcf43f6db755'] = $pane;
    $display->panels['middle'][2] = 'new-992656e8-f99d-4db9-8356-dcf43f6db755';
    $pane = new stdClass();
    $pane->pid = 'new-2621b2b6-fe7d-4423-8726-1a084205a51e';
    $pane->panel = 'middle';
    $pane->type = 'front_map';
    $pane->subtype = 'front_map';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '2621b2b6-fe7d-4423-8726-1a084205a51e';
    $display->content['new-2621b2b6-fe7d-4423-8726-1a084205a51e'] = $pane;
    $display->panels['middle'][3] = 'new-2621b2b6-fe7d-4423-8726-1a084205a51e';
    $pane = new stdClass();
    $pane->pid = 'new-a057c449-dcff-4254-a908-6f22668be919';
    $pane->panel = 'middle';
    $pane->type = 'block_developers';
    $pane->subtype = 'block_developers';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'a057c449-dcff-4254-a908-6f22668be919';
    $display->content['new-a057c449-dcff-4254-a908-6f22668be919'] = $pane;
    $display->panels['middle'][4] = 'new-a057c449-dcff-4254-a908-6f22668be919';
    $pane = new stdClass();
    $pane->pid = 'new-448ca697-b5fa-434e-8eb1-b9e87e3b18b0';
    $pane->panel = 'middle';
    $pane->type = 'block_stock';
    $pane->subtype = 'block_stock';
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
    $pane->uuid = '448ca697-b5fa-434e-8eb1-b9e87e3b18b0';
    $display->content['new-448ca697-b5fa-434e-8eb1-b9e87e3b18b0'] = $pane;
    $display->panels['middle'][5] = 'new-448ca697-b5fa-434e-8eb1-b9e87e3b18b0';
    $pane = new stdClass();
    $pane->pid = 'new-bf58690d-e81a-4d4e-b972-3eadf5712e4c';
    $pane->panel = 'middle';
    $pane->type = 'block_mortgage';
    $pane->subtype = 'block_mortgage';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'bf58690d-e81a-4d4e-b972-3eadf5712e4c';
    $display->content['new-bf58690d-e81a-4d4e-b972-3eadf5712e4c'] = $pane;
    $display->panels['middle'][6] = 'new-bf58690d-e81a-4d4e-b972-3eadf5712e4c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context_2'] = $handler;

  return $export;
}
