<?php
/**
 * @file
 * realty_features_view_stock.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function realty_features_view_stock_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'stock';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Акции';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Поле: Content: Изображение */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Поле: Content: Жилой комплекс */
  $handler->display->display_options['fields']['field_complex_stock']['id'] = 'field_complex_stock';
  $handler->display->display_options['fields']['field_complex_stock']['table'] = 'field_data_field_complex_stock';
  $handler->display->display_options['fields']['field_complex_stock']['field'] = 'field_complex_stock';
  $handler->display->display_options['fields']['field_complex_stock']['settings'] = array(
    'link' => 0,
  );
  /* Поле: Content: Краткое описание */
  $handler->display->display_options['fields']['field_mini_description']['id'] = 'field_mini_description';
  $handler->display->display_options['fields']['field_mini_description']['table'] = 'field_data_field_mini_description';
  $handler->display->display_options['fields']['field_mini_description']['field'] = 'field_mini_description';
  /* Критерий сортировки: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Критерий фильтра: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stock' => 'stock',
  );
  /* Критерий фильтра: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Критерий фильтра: Content: Приоритет (field_priority) */
  $handler->display->display_options['filters']['field_priority_value']['id'] = 'field_priority_value';
  $handler->display->display_options['filters']['field_priority_value']['table'] = 'field_data_field_priority';
  $handler->display->display_options['filters']['field_priority_value']['field'] = 'field_priority_value';
  $handler->display->display_options['filters']['field_priority_value']['value'] = array(
    1 => '1',
  );

  /* Display: Акции главная страница */
  $handler = $view->new_display('panel_pane', 'Акции главная страница', 'stock');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_complex_stock_target_id']['id'] = 'field_complex_stock_target_id';
  $handler->display->display_options['relationships']['field_complex_stock_target_id']['table'] = 'field_data_field_complex_stock';
  $handler->display->display_options['relationships']['field_complex_stock_target_id']['field'] = 'field_complex_stock_target_id';
  /* Связь: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['relationship'] = 'field_complex_stock_target_id';
  /* Связь: Taxonomy term: Город (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Поле: Content: Изображение */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Поле: Content: Жилой комплекс */
  $handler->display->display_options['fields']['field_complex_stock']['id'] = 'field_complex_stock';
  $handler->display->display_options['fields']['field_complex_stock']['table'] = 'field_data_field_complex_stock';
  $handler->display->display_options['fields']['field_complex_stock']['field'] = 'field_complex_stock';
  $handler->display->display_options['fields']['field_complex_stock']['settings'] = array(
    'link' => 0,
  );
  /* Поле: Content: Краткое описание */
  $handler->display->display_options['fields']['field_mini_description']['id'] = 'field_mini_description';
  $handler->display->display_options['fields']['field_mini_description']['table'] = 'field_data_field_mini_description';
  $handler->display->display_options['fields']['field_mini_description']['field'] = 'field_mini_description';
  /* Поле: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'field_complex_developer_tid';
  /* Поле: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_city_tid';
  /* Поле: Content: Приоритет */
  $handler->display->display_options['fields']['field_priority']['id'] = 'field_priority';
  $handler->display->display_options['fields']['field_priority']['table'] = 'field_data_field_priority';
  $handler->display->display_options['fields']['field_priority']['field'] = 'field_priority';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_city_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stock' => 'stock',
  );
  /* Критерий фильтра: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Все акции в городе */
  $handler = $view->new_display('panel_pane', 'Все акции в городе', 'all_stock_city');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_complex_stock_target_id']['id'] = 'field_complex_stock_target_id';
  $handler->display->display_options['relationships']['field_complex_stock_target_id']['table'] = 'field_data_field_complex_stock';
  $handler->display->display_options['relationships']['field_complex_stock_target_id']['field'] = 'field_complex_stock_target_id';
  /* Связь: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['relationship'] = 'field_complex_stock_target_id';
  /* Связь: Taxonomy term: Город (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_city_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stock' => 'stock',
  );
  /* Критерий фильтра: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Критерий фильтра: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['filters']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['filters']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['relationship'] = 'field_complex_stock_target_id';
  $handler->display->display_options['filters']['field_complex_developer_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['operator_id'] = 'field_complex_developer_tid_op';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['label'] = 'Застройщик (field_complex_developer)';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['operator'] = 'field_complex_developer_tid_op';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['identifier'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_complex_developer_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_complex_developer_tid']['vocabulary'] = 'developers';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Акции ЖК */
  $handler = $view->new_display('panel_pane', 'Акции ЖК', 'stock_complex');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_complex_stock_target_id']['id'] = 'field_complex_stock_target_id';
  $handler->display->display_options['relationships']['field_complex_stock_target_id']['table'] = 'field_data_field_complex_stock';
  $handler->display->display_options['relationships']['field_complex_stock_target_id']['field'] = 'field_complex_stock_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_complex_stock_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stock' => 'stock',
  );
  /* Критерий фильтра: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Акции Застройщика */
  $handler = $view->new_display('panel_pane', 'Акции Застройщика', 'stock_developer');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_complex_stock_target_id']['id'] = 'field_complex_stock_target_id';
  $handler->display->display_options['relationships']['field_complex_stock_target_id']['table'] = 'field_data_field_complex_stock';
  $handler->display->display_options['relationships']['field_complex_stock_target_id']['field'] = 'field_complex_stock_target_id';
  /* Связь: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['relationship'] = 'field_complex_stock_target_id';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'термин';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'developers' => 'developers',
    'banks' => 0,
    'taxonomy_remunerations' => 0,
    'homes' => 0,
    'categories' => 0,
    'mortgage_category' => 0,
    'taxonomy_contacts' => 0,
    'material' => 0,
    'metro' => 0,
    'partners' => 0,
    'taxonomy_policy' => 0,
    'taxonomy_guide' => 0,
    'area' => 0,
    'taxonomy_cooperation' => 0,
    'deadline' => 0,
    'cities' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stock' => 'stock',
  );
  /* Критерий фильтра: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['stock'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Жилой комплекс'),
    t('Краткое описание'),
    t('Акции главная страница'),
    t('more'),
    t('Content entity referenced from field_complex_stock'),
    t('term from field_complex_developer'),
    t('term from field_city'),
    t('Name'),
    t('Приоритет'),
    t('Все'),
    t('Представления-Фрагменты'),
    t('Все акции в городе'),
    t('Застройщик (field_complex_developer)'),
    t('Акции ЖК'),
    t('Акции Застройщика'),
    t('термин'),
  );
  $export['stock'] = $view;

  return $export;
}
