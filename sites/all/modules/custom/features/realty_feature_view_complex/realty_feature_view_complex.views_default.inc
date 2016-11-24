<?php
/**
 * @file
 * realty_feature_view_complex.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function realty_feature_view_complex_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'complex';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Жилой комплекс';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_home_complex_taxonomy_term']['id'] = 'reverse_field_home_complex_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_home_complex_taxonomy_term']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_home_complex_taxonomy_term']['field'] = 'reverse_field_home_complex_taxonomy_term';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Район */
  $handler->display->display_options['fields']['field_area']['id'] = 'field_area';
  $handler->display->display_options['fields']['field_area']['table'] = 'field_data_field_area';
  $handler->display->display_options['fields']['field_area']['field'] = 'field_area';
  /* Field: Content: Застройщик */
  $handler->display->display_options['fields']['field_complex_developer']['id'] = 'field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['field'] = 'field_complex_developer';
  /* Field: Content: Главное изображение */
  $handler->display->display_options['fields']['field_main_photo']['id'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['table'] = 'field_data_field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['field'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['label'] = '';
  $handler->display->display_options['fields']['field_main_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_photo']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '20',
  );
  /* Field: Content: Панорама */
  $handler->display->display_options['fields']['field_pano']['id'] = 'field_pano';
  $handler->display->display_options['fields']['field_pano']['table'] = 'field_data_field_pano';
  $handler->display->display_options['fields']['field_pano']['field'] = 'field_pano';
  $handler->display->display_options['fields']['field_pano']['settings'] = array(
    'edit' => 'Правка',
    'delete' => 'Удалить',
    'add' => 'Добавить',
    'description' => 1,
    'view_mode' => 'full',
  );
  /* Field: Content: Логотип */
  $handler->display->display_options['fields']['field_complex_logo']['id'] = 'field_complex_logo';
  $handler->display->display_options['fields']['field_complex_logo']['table'] = 'field_data_field_complex_logo';
  $handler->display->display_options['fields']['field_complex_logo']['field'] = 'field_complex_logo';
  $handler->display->display_options['fields']['field_complex_logo']['label'] = '';
  $handler->display->display_options['fields']['field_complex_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_complex_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_complex_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Слоган */
  $handler->display->display_options['fields']['field_slogan']['id'] = 'field_slogan';
  $handler->display->display_options['fields']['field_slogan']['table'] = 'field_data_field_slogan';
  $handler->display->display_options['fields']['field_slogan']['field'] = 'field_slogan';
  /* Field: Content: Сроки сдачи */
  $handler->display->display_options['fields']['field_complex_deadline']['id'] = 'field_complex_deadline';
  $handler->display->display_options['fields']['field_complex_deadline']['table'] = 'field_data_field_complex_deadline';
  $handler->display->display_options['fields']['field_complex_deadline']['field'] = 'field_complex_deadline';
  $handler->display->display_options['fields']['field_complex_deadline']['settings'] = array(
    'edit' => 'Правка',
    'delete' => 'Удалить',
    'add' => 'Добавить',
    'description' => 1,
    'view_mode' => 'full',
  );
  /* Field: Content: Стоимость квартир от */
  $handler->display->display_options['fields']['field_apartments_price']['id'] = 'field_apartments_price';
  $handler->display->display_options['fields']['field_apartments_price']['table'] = 'field_data_field_apartments_price';
  $handler->display->display_options['fields']['field_apartments_price']['field'] = 'field_apartments_price';
  /* Field: Content: Величина рейтинга */
  $handler->display->display_options['fields']['field_complex_rating_val']['id'] = 'field_complex_rating_val';
  $handler->display->display_options['fields']['field_complex_rating_val']['table'] = 'field_data_field_complex_rating_val';
  $handler->display->display_options['fields']['field_complex_rating_val']['field'] = 'field_complex_rating_val';
  $handler->display->display_options['fields']['field_complex_rating_val']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'reverse_field_home_complex_taxonomy_term';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'complex' => 'complex',
  );

  /* Display: Жилые комплексы */
  $handler = $view->new_display('panel_pane', 'Жилые комплексы', 'complexs');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = 'groupby:node.nid';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['required'] = TRUE;
  /* Relationship: Taxonomy term: Город (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_city_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
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
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'complex' => 'complex',
  );
  /* Filter criterion: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['filters']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['filters']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['operator_id'] = 'field_complex_developer_tid_op';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['label'] = 'Застройщик (field_complex_developer)';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['operator'] = 'field_complex_developer_tid_op';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['identifier'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_complex_developer_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_complex_developer_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_complex_developer_tid']['vocabulary'] = 'developers';
  $handler->display->display_options['filters']['field_complex_developer_tid']['error_message'] = FALSE;
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Жилой комплекс */
  $handler = $view->new_display('panel_pane', 'Жилой комплекс', 'complex');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Район */
  $handler->display->display_options['fields']['field_area']['id'] = 'field_area';
  $handler->display->display_options['fields']['field_area']['table'] = 'field_data_field_area';
  $handler->display->display_options['fields']['field_area']['field'] = 'field_area';
  /* Field: Content: Застройщик */
  $handler->display->display_options['fields']['field_complex_developer']['id'] = 'field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['field'] = 'field_complex_developer';
  /* Field: Taxonomy term: Срок сдачи */
  $handler->display->display_options['fields']['field_deadline']['id'] = 'field_deadline';
  $handler->display->display_options['fields']['field_deadline']['table'] = 'field_data_field_deadline';
  $handler->display->display_options['fields']['field_deadline']['field'] = 'field_deadline';
  $handler->display->display_options['fields']['field_deadline']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_deadline']['settings'] = array(
    'view_mode' => 'full',
  );
  /* Field: Content: Главное изображение */
  $handler->display->display_options['fields']['field_main_photo']['id'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['table'] = 'field_data_field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['field'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['label'] = '';
  $handler->display->display_options['fields']['field_main_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_photo']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Описание';
  /* Field: Content: План жилого комплекса */
  $handler->display->display_options['fields']['field_plan_complex']['id'] = 'field_plan_complex';
  $handler->display->display_options['fields']['field_plan_complex']['table'] = 'field_data_field_plan_complex';
  $handler->display->display_options['fields']['field_plan_complex']['field'] = 'field_plan_complex';
  $handler->display->display_options['fields']['field_plan_complex']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_plan_complex']['type'] = 'image';
  $handler->display->display_options['fields']['field_plan_complex']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Документы */
  $handler->display->display_options['fields']['field_documents']['id'] = 'field_documents';
  $handler->display->display_options['fields']['field_documents']['table'] = 'field_data_field_documents';
  $handler->display->display_options['fields']['field_documents']['field'] = 'field_documents';
  $handler->display->display_options['fields']['field_documents']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_documents']['type'] = 'file_default';
  $handler->display->display_options['fields']['field_documents']['group_column'] = '';
  $handler->display->display_options['fields']['field_documents']['delta_offset'] = '0';
  /* Field: Content: Панорама */
  $handler->display->display_options['fields']['field_pano']['id'] = 'field_pano';
  $handler->display->display_options['fields']['field_pano']['table'] = 'field_data_field_pano';
  $handler->display->display_options['fields']['field_pano']['field'] = 'field_pano';
  $handler->display->display_options['fields']['field_pano']['settings'] = array(
    'edit' => 'Правка',
    'delete' => 'Удалить',
    'add' => 'Добавить',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: ЖК застройщиков */
  $handler = $view->new_display('panel_pane', 'ЖК застройщиков', 'complex_developers');
  $handler->display->display_options['display_description'] = 'Жилые комплексы для нескольких застройщиков';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['required'] = TRUE;
  /* Relationship: Taxonomy term: Город (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_city_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['arguments']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['arguments']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['arguments']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['arguments']['field_complex_developer_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_complex_developer_tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_complex_developer_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_complex_developer_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_complex_developer_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_complex_developer_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'complex' => 'complex',
  );
  /* Filter criterion: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['filters']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['filters']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['operator_id'] = 'field_complex_developer_tid_op';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['label'] = 'Застройщик (field_complex_developer)';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['operator'] = 'field_complex_developer_tid_op';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['identifier'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_complex_developer_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_complex_developer_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_complex_developer_tid']['vocabulary'] = 'developers';
  /* Filter criterion: Content: Архивный жилой комплекс (field_archive) */
  $handler->display->display_options['filters']['field_archive_value']['id'] = 'field_archive_value';
  $handler->display->display_options['filters']['field_archive_value']['table'] = 'field_data_field_archive';
  $handler->display->display_options['filters']['field_archive_value']['field'] = 'field_archive_value';
  $handler->display->display_options['filters']['field_archive_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_archive_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_archive_value']['expose']['operator_id'] = 'field_archive_value_op';
  $handler->display->display_options['filters']['field_archive_value']['expose']['label'] = 'Архивный жилой комплекс (field_archive)';
  $handler->display->display_options['filters']['field_archive_value']['expose']['operator'] = 'field_archive_value_op';
  $handler->display->display_options['filters']['field_archive_value']['expose']['identifier'] = 'field_archive_value';
  $handler->display->display_options['filters']['field_archive_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: ЖК для поиска */
  $handler = $view->new_display('panel_pane', 'ЖК для поиска', 'complexs_search');
  $handler->display->display_options['display_description'] = 'Жилые комплексы для формы поиска';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['required'] = TRUE;
  /* Relationship: Taxonomy term: Город (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_city_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_city_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['argument'] = '11';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'complex' => 'complex',
  );
  /* Filter criterion: Content: Архивный жилой комплекс (field_archive) */
  $handler->display->display_options['filters']['field_archive_value']['id'] = 'field_archive_value';
  $handler->display->display_options['filters']['field_archive_value']['table'] = 'field_data_field_archive';
  $handler->display->display_options['filters']['field_archive_value']['field'] = 'field_archive_value';
  $handler->display->display_options['filters']['field_archive_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_archive_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Случайный комплекс */
  $handler = $view->new_display('panel_pane', 'Случайный комплекс', 'random_complex');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Логотип */
  $handler->display->display_options['fields']['field_complex_logo']['id'] = 'field_complex_logo';
  $handler->display->display_options['fields']['field_complex_logo']['table'] = 'field_data_field_complex_logo';
  $handler->display->display_options['fields']['field_complex_logo']['field'] = 'field_complex_logo';
  $handler->display->display_options['fields']['field_complex_logo']['label'] = '';
  $handler->display->display_options['fields']['field_complex_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_complex_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_complex_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Главное изображение */
  $handler->display->display_options['fields']['field_main_photo']['id'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['table'] = 'field_data_field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['field'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['label'] = '';
  $handler->display->display_options['fields']['field_main_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Город (field_city) */
  $handler->display->display_options['arguments']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['arguments']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['arguments']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['arguments']['field_city_tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['arguments']['field_city_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_city_tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_city_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_city_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_city_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_city_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'complex' => 'complex',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: ЖК застройщика */
  $handler = $view->new_display('panel_pane', 'ЖК застройщика', 'complex_developer');
  $handler->display->display_options['display_description'] = 'Жилые комплексы одного застройщика';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['required'] = TRUE;
  /* Relationship: Taxonomy term: Город (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_city_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'complex' => 'complex',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Галерея фотографий ЖК */
  $handler = $view->new_display('panel_pane', 'Галерея фотографий ЖК', 'gallery_photo');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Галерея (field_gallery) */
  $handler->display->display_options['relationships']['field_gallery_value']['id'] = 'field_gallery_value';
  $handler->display->display_options['relationships']['field_gallery_value']['table'] = 'field_data_field_gallery';
  $handler->display->display_options['relationships']['field_gallery_value']['field'] = 'field_gallery_value';
  $handler->display->display_options['relationships']['field_gallery_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Название */
  $handler->display->display_options['fields']['field_name_gallery']['id'] = 'field_name_gallery';
  $handler->display->display_options['fields']['field_name_gallery']['table'] = 'field_data_field_name_gallery';
  $handler->display->display_options['fields']['field_name_gallery']['field'] = 'field_name_gallery';
  $handler->display->display_options['fields']['field_name_gallery']['relationship'] = 'field_gallery_value';
  /* Field: Field collection item: Изображение */
  $handler->display->display_options['fields']['field_image_gallery']['id'] = 'field_image_gallery';
  $handler->display->display_options['fields']['field_image_gallery']['table'] = 'field_data_field_image_gallery';
  $handler->display->display_options['fields']['field_image_gallery']['field'] = 'field_image_gallery';
  $handler->display->display_options['fields']['field_image_gallery']['relationship'] = 'field_gallery_value';
  $handler->display->display_options['fields']['field_image_gallery']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_gallery']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image_gallery']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field collection item: Field collection item ID */
  $handler->display->display_options['sorts']['item_id']['id'] = 'item_id';
  $handler->display->display_options['sorts']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['sorts']['item_id']['field'] = 'item_id';
  $handler->display->display_options['sorts']['item_id']['relationship'] = 'field_gallery_value';
  $handler->display->display_options['sorts']['item_id']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Галерея визуализаций ЖК */
  $handler = $view->new_display('panel_pane', 'Галерея визуализаций ЖК', 'gallery_visualization');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Визуализация */
  $handler->display->display_options['fields']['field_visualization']['id'] = 'field_visualization';
  $handler->display->display_options['fields']['field_visualization']['table'] = 'field_data_field_visualization';
  $handler->display->display_options['fields']['field_visualization']['field'] = 'field_visualization';
  $handler->display->display_options['fields']['field_visualization']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_visualization']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_visualization']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Галерея ЖК - Видео */
  $handler = $view->new_display('panel_pane', 'Галерея ЖК - Видео', 'gallery_video');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Панорама (field_pano) */
  $handler->display->display_options['relationships']['field_pano_value']['id'] = 'field_pano_value';
  $handler->display->display_options['relationships']['field_pano_value']['table'] = 'field_data_field_pano';
  $handler->display->display_options['relationships']['field_pano_value']['field'] = 'field_pano_value';
  $handler->display->display_options['relationships']['field_pano_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Видео */
  $handler->display->display_options['fields']['field_video']['id'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['table'] = 'field_data_field_video';
  $handler->display->display_options['fields']['field_video']['field'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['click_sort_column'] = 'input';
  $handler->display->display_options['fields']['field_video']['settings'] = array(
    'youtube_size' => '420x315',
    'youtube_width' => '',
    'youtube_height' => '',
    'youtube_autoplay' => 0,
    'youtube_loop' => 0,
    'youtube_showinfo' => 0,
    'youtube_controls' => 0,
    'youtube_autohide' => 0,
    'youtube_iv_load_policy' => 0,
  );
  $handler->display->display_options['fields']['field_video']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Документы ЖК */
  $handler = $view->new_display('panel_pane', 'Документы ЖК', 'complex_documents');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Документы (field_documents) */
  $handler->display->display_options['relationships']['field_documents_value']['id'] = 'field_documents_value';
  $handler->display->display_options['relationships']['field_documents_value']['table'] = 'field_data_field_documents';
  $handler->display->display_options['relationships']['field_documents_value']['field'] = 'field_documents_value';
  $handler->display->display_options['relationships']['field_documents_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Название документа */
  $handler->display->display_options['fields']['field_title']['id'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['table'] = 'field_data_field_title';
  $handler->display->display_options['fields']['field_title']['field'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['relationship'] = 'field_documents_value';
  /* Field: Field collection item:  Документ */
  $handler->display->display_options['fields']['field_document']['id'] = 'field_document';
  $handler->display->display_options['fields']['field_document']['table'] = 'field_data_field_document';
  $handler->display->display_options['fields']['field_document']['field'] = 'field_document';
  $handler->display->display_options['fields']['field_document']['relationship'] = 'field_documents_value';
  $handler->display->display_options['fields']['field_document']['click_sort_column'] = 'fid';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: ЖК архивные застройщиков */
  $handler = $view->new_display('panel_pane', 'ЖК архивные застройщиков', 'archive_complex_developer');
  $handler->display->display_options['display_description'] = 'Жилые комплексы для нескольких застройщиков';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['required'] = TRUE;
  /* Relationship: Taxonomy term: Город (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_city_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['arguments']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['arguments']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['arguments']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['arguments']['field_complex_developer_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_complex_developer_tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_complex_developer_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_complex_developer_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_complex_developer_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_complex_developer_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'complex' => 'complex',
  );
  /* Filter criterion: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['filters']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['filters']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['operator_id'] = 'field_complex_developer_tid_op';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['label'] = 'Застройщик (field_complex_developer)';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['operator'] = 'field_complex_developer_tid_op';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['identifier'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_complex_developer_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_complex_developer_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_complex_developer_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_complex_developer_tid']['vocabulary'] = 'developers';
  /* Filter criterion: Content: Архивный жилой комплекс (field_archive) */
  $handler->display->display_options['filters']['field_archive_value']['id'] = 'field_archive_value';
  $handler->display->display_options['filters']['field_archive_value']['table'] = 'field_data_field_archive';
  $handler->display->display_options['filters']['field_archive_value']['field'] = 'field_archive_value';
  $handler->display->display_options['filters']['field_archive_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_archive_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_archive_value']['expose']['operator_id'] = 'field_archive_value_op';
  $handler->display->display_options['filters']['field_archive_value']['expose']['label'] = 'Архивный жилой комплекс (field_archive)';
  $handler->display->display_options['filters']['field_archive_value']['expose']['operator'] = 'field_archive_value_op';
  $handler->display->display_options['filters']['field_archive_value']['expose']['identifier'] = 'field_archive_value';
  $handler->display->display_options['filters']['field_archive_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['complex'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Элементов на страницу'),
    t('- Все -'),
    t('Пропустить'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
    t('Taxonomy term referencing Content from field_home_complex'),
    t('Район'),
    t('Застройщик'),
    t('Панорама'),
    t('Слоган'),
    t('Сроки сдачи'),
    t('Стоимость квартир от'),
    t('Величина рейтинга'),
    t('Все'),
    t('Жилые комплексы'),
    t('more'),
    t('term from field_complex_developer'),
    t('term from field_city'),
    t('Застройщик (field_complex_developer)'),
    t('Представления-Фрагменты'),
    t('Жилой комплекс'),
    t('Срок сдачи'),
    t('Описание'),
    t('План жилого комплекса'),
    t('Документы'),
    t('ЖК застройщиков'),
    t('Жилые комплексы для нескольких застройщиков'),
    t('Архивный жилой комплекс (field_archive)'),
    t('ЖК для поиска'),
    t('Жилые комплексы для формы поиска'),
    t('Случайный комплекс'),
    t('ЖК застройщика'),
    t('Жилые комплексы одного застройщика'),
    t('Галерея фотографий ЖК'),
    t('field collection item from field_gallery'),
    t('Название'),
    t('Изображение'),
    t('Галерея визуализаций ЖК'),
    t('Визуализация'),
    t('Галерея ЖК - Видео'),
    t('field collection item from field_pano'),
    t('Видео'),
    t('Документы ЖК'),
    t('field collection item from field_documents'),
    t('Название документа'),
    t(' Документ'),
    t('ЖК архивные застройщиков'),
  );
  $export['complex'] = $view;

  return $export;
}
