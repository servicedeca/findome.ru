<?php
/**
 * @file
 * realty_feature_view_apartments.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function realty_feature_view_apartments_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'apartments';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Квартиры';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
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
  /* Relationship: Content: Дом (field_apartament_home) */
  $handler->display->display_options['relationships']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['relationship'] = 'field_apartament_home_tid';
  /* Relationship: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['relationship'] = 'field_home_complex_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_apartment_comparison_user']['id'] = 'reverse_field_apartment_comparison_user';
  $handler->display->display_options['relationships']['reverse_field_apartment_comparison_user']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_apartment_comparison_user']['field'] = 'reverse_field_apartment_comparison_user';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Главное изображение */
  $handler->display->display_options['fields']['field_main_photo']['id'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['table'] = 'field_data_field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['field'] = 'field_main_photo';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'apartament' => 'apartament',
  );
  /* Filter criterion: Content: Дом (field_apartament_home) */
  $handler->display->display_options['filters']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['filters']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_apartament_home_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['operator_id'] = 'field_apartament_home_tid_op';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['label'] = 'Дом (field_apartament_home)';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['operator'] = 'field_apartament_home_tid_op';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['identifier'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_apartament_home_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_apartament_home_tid']['vocabulary'] = 'homes';
  /* Filter criterion: Content: Количество комнат (field_number_rooms) */
  $handler->display->display_options['filters']['field_number_rooms_value']['id'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['table'] = 'field_data_field_number_rooms';
  $handler->display->display_options['filters']['field_number_rooms_value']['field'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['operator_id'] = 'field_number_rooms_value_op';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['label'] = 'Количество комнат (field_number_rooms)';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['operator'] = 'field_number_rooms_value_op';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['identifier'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Квартиры жилого комплекса */
  $handler = $view->new_display('panel_pane', 'Квартиры жилого комплекса', 'apartment_complex');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
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
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Дом (field_apartament_home) */
  $handler->display->display_options['relationships']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: номер квартиры */
  $handler->display->display_options['fields']['field_number_apartament']['id'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['field'] = 'field_number_apartament';
  /* Field: Taxonomy term: Адрес дома */
  $handler->display->display_options['fields']['field_address_house']['id'] = 'field_address_house';
  $handler->display->display_options['fields']['field_address_house']['table'] = 'field_data_field_address_house';
  $handler->display->display_options['fields']['field_address_house']['field'] = 'field_address_house';
  $handler->display->display_options['fields']['field_address_house']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['fields']['field_address_house']['label'] = 'Адрес';
  $handler->display->display_options['fields']['field_address_house']['type'] = 'text_plain';
  /* Field: Content: Секция */
  $handler->display->display_options['fields']['field_section']['id'] = 'field_section';
  $handler->display->display_options['fields']['field_section']['table'] = 'field_data_field_section';
  $handler->display->display_options['fields']['field_section']['field'] = 'field_section';
  $handler->display->display_options['fields']['field_section']['type'] = 'text_plain';
  /* Field: Content: Количество комнат */
  $handler->display->display_options['fields']['field_number_rooms']['id'] = 'field_number_rooms';
  $handler->display->display_options['fields']['field_number_rooms']['table'] = 'field_data_field_number_rooms';
  $handler->display->display_options['fields']['field_number_rooms']['field'] = 'field_number_rooms';
  /* Field: Content: Этаж */
  $handler->display->display_options['fields']['field_apartment_floor']['id'] = 'field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['field'] = 'field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['label'] = '';
  $handler->display->display_options['fields']['field_apartment_floor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_apartment_floor']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Общая площадь */
  $handler->display->display_options['fields']['field_gross_area']['id'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['field'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['type'] = 'number_unformatted';
  /* Field: Content: Цена за кв.м */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Стоимость */
  $handler->display->display_options['fields']['field_full_cost']['id'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['table'] = 'field_data_field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['field'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Статус */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  /* Field: Taxonomy term: Количество этажей */
  $handler->display->display_options['fields']['field_number_floor']['id'] = 'field_number_floor';
  $handler->display->display_options['fields']['field_number_floor']['table'] = 'field_data_field_number_floor';
  $handler->display->display_options['fields']['field_number_floor']['field'] = 'field_number_floor';
  $handler->display->display_options['fields']['field_number_floor']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['fields']['field_number_floor']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Балкон */
  $handler->display->display_options['fields']['field_balcony']['id'] = 'field_balcony';
  $handler->display->display_options['fields']['field_balcony']['table'] = 'field_data_field_balcony';
  $handler->display->display_options['fields']['field_balcony']['field'] = 'field_balcony';
  /* Field: Content: Лоджия */
  $handler->display->display_options['fields']['field_loggia']['id'] = 'field_loggia';
  $handler->display->display_options['fields']['field_loggia']['table'] = 'field_data_field_loggia';
  $handler->display->display_options['fields']['field_loggia']['field'] = 'field_loggia';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Этаж (field_apartment_floor) */
  $handler->display->display_options['sorts']['field_apartment_floor_value']['id'] = 'field_apartment_floor_value';
  $handler->display->display_options['sorts']['field_apartment_floor_value']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['sorts']['field_apartment_floor_value']['field'] = 'field_apartment_floor_value';
  $handler->display->display_options['sorts']['field_apartment_floor_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_apartment_floor_value']['expose']['label'] = 'Этаж (field_apartment_floor)';
  /* Sort criterion: Content: Общая площадь (field_gross_area) */
  $handler->display->display_options['sorts']['field_gross_area_value']['id'] = 'field_gross_area_value';
  $handler->display->display_options['sorts']['field_gross_area_value']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['sorts']['field_gross_area_value']['field'] = 'field_gross_area_value';
  $handler->display->display_options['sorts']['field_gross_area_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_gross_area_value']['expose']['label'] = 'Общая площадь (field_gross_area)';
  /* Sort criterion: Content: Цена за кв.м (field_price) */
  $handler->display->display_options['sorts']['field_price_value']['id'] = 'field_price_value';
  $handler->display->display_options['sorts']['field_price_value']['table'] = 'field_data_field_price';
  $handler->display->display_options['sorts']['field_price_value']['field'] = 'field_price_value';
  $handler->display->display_options['sorts']['field_price_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_price_value']['expose']['label'] = 'Цена за кв.м (field_price)';
  /* Sort criterion: Content: Стоимость (field_full_cost) */
  $handler->display->display_options['sorts']['field_full_cost_value']['id'] = 'field_full_cost_value';
  $handler->display->display_options['sorts']['field_full_cost_value']['table'] = 'field_data_field_full_cost';
  $handler->display->display_options['sorts']['field_full_cost_value']['field'] = 'field_full_cost_value';
  $handler->display->display_options['sorts']['field_full_cost_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_full_cost_value']['expose']['label'] = 'Стоимость (field_full_cost)';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['sorts']['random']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['random']['expose']['label'] = 'Случайно';
  /* Sort criterion: Content: Количество комнат (field_number_rooms) */
  $handler->display->display_options['sorts']['field_number_rooms_value']['id'] = 'field_number_rooms_value';
  $handler->display->display_options['sorts']['field_number_rooms_value']['table'] = 'field_data_field_number_rooms';
  $handler->display->display_options['sorts']['field_number_rooms_value']['field'] = 'field_number_rooms_value';
  $handler->display->display_options['sorts']['field_number_rooms_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_number_rooms_value']['expose']['label'] = 'Количество комнат (field_number_rooms)';
  /* Sort criterion: Content: Секция (field_section) */
  $handler->display->display_options['sorts']['field_section_value']['id'] = 'field_section_value';
  $handler->display->display_options['sorts']['field_section_value']['table'] = 'field_data_field_section';
  $handler->display->display_options['sorts']['field_section_value']['field'] = 'field_section_value';
  $handler->display->display_options['sorts']['field_section_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_section_value']['expose']['label'] = 'Секция (field_section)';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content revision: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node_revision';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'apartament' => 'apartament',
  );
  /* Filter criterion: Content: Дом (field_apartament_home) */
  $handler->display->display_options['filters']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['filters']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_apartament_home_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['operator_id'] = 'field_apartament_home_tid_op';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['label'] = 'Дом (field_apartament_home)';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['operator'] = 'field_apartament_home_tid_op';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['identifier'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_apartament_home_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_apartament_home_tid']['vocabulary'] = 'homes';
  /* Filter criterion: Content: Количество комнат (field_number_rooms) */
  $handler->display->display_options['filters']['field_number_rooms_value']['id'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['table'] = 'field_data_field_number_rooms';
  $handler->display->display_options['filters']['field_number_rooms_value']['field'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['operator_id'] = 'field_number_rooms_value_op';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['label'] = 'Количество комнат (field_number_rooms)';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['operator'] = 'field_number_rooms_value_op';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['identifier'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Этаж (field_apartment_floor) */
  $handler->display->display_options['filters']['field_apartment_floor_value']['id'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['filters']['field_apartment_floor_value']['field'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_apartment_floor_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['operator_id'] = 'field_apartment_floor_value_op';
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['label'] = 'Этаж (field_apartment_floor)';
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['operator'] = 'field_apartment_floor_value_op';
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['identifier'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_apartment_floor_value']['group_info']['label'] = 'Этаж (field_apartment_floor)';
  $handler->display->display_options['filters']['field_apartment_floor_value']['group_info']['identifier'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_apartment_floor_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Общая площадь (field_gross_area) */
  $handler->display->display_options['filters']['field_gross_area_value']['id'] = 'field_gross_area_value';
  $handler->display->display_options['filters']['field_gross_area_value']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['filters']['field_gross_area_value']['field'] = 'field_gross_area_value';
  $handler->display->display_options['filters']['field_gross_area_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_gross_area_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['operator_id'] = 'field_gross_area_value_op';
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['label'] = 'Общая площадь (field_gross_area)';
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['operator'] = 'field_gross_area_value_op';
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['identifier'] = 'field_gross_area_value';
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Секция (field_section) */
  $handler->display->display_options['filters']['field_section_value']['id'] = 'field_section_value';
  $handler->display->display_options['filters']['field_section_value']['table'] = 'field_data_field_section';
  $handler->display->display_options['filters']['field_section_value']['field'] = 'field_section_value';
  $handler->display->display_options['filters']['field_section_value']['operator'] = 'regular_expression';
  $handler->display->display_options['filters']['field_section_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_section_value']['expose']['operator_id'] = 'field_section_value_op';
  $handler->display->display_options['filters']['field_section_value']['expose']['label'] = 'Секция (field_section)';
  $handler->display->display_options['filters']['field_section_value']['expose']['operator'] = 'field_section_value_op';
  $handler->display->display_options['filters']['field_section_value']['expose']['identifier'] = 'field_section_value';
  $handler->display->display_options['filters']['field_section_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_section_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  /* Filter criterion: Content: Статус (field_status) */
  $handler->display->display_options['filters']['field_status_value']['id'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['table'] = 'field_data_field_status';
  $handler->display->display_options['filters']['field_status_value']['field'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_status_value']['expose']['operator_id'] = 'field_status_value_op';
  $handler->display->display_options['filters']['field_status_value']['expose']['label'] = 'Статус (field_status)';
  $handler->display->display_options['filters']['field_status_value']['expose']['operator'] = 'field_status_value_op';
  $handler->display->display_options['filters']['field_status_value']['expose']['identifier'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: номер квартиры (field_number_apartament) */
  $handler->display->display_options['filters']['field_number_apartament_value']['id'] = 'field_number_apartament_value';
  $handler->display->display_options['filters']['field_number_apartament_value']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['filters']['field_number_apartament_value']['field'] = 'field_number_apartament_value';
  $handler->display->display_options['filters']['field_number_apartament_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_number_apartament_value']['expose']['operator_id'] = 'field_number_apartament_value_op';
  $handler->display->display_options['filters']['field_number_apartament_value']['expose']['label'] = 'номер квартиры (field_number_apartament)';
  $handler->display->display_options['filters']['field_number_apartament_value']['expose']['operator'] = 'field_number_apartament_value_op';
  $handler->display->display_options['filters']['field_number_apartament_value']['expose']['identifier'] = 'field_number_apartament_value';
  $handler->display->display_options['filters']['field_number_apartament_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Квартира */
  $handler = $view->new_display('panel_pane', 'Квартира', 'apartment');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Дом (field_apartament_home) */
  $handler->display->display_options['relationships']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Дом */
  $handler->display->display_options['fields']['field_apartament_home']['id'] = 'field_apartament_home';
  $handler->display->display_options['fields']['field_apartament_home']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['fields']['field_apartament_home']['field'] = 'field_apartament_home';
  $handler->display->display_options['fields']['field_apartament_home']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Район */
  $handler->display->display_options['fields']['field_area']['id'] = 'field_area';
  $handler->display->display_options['fields']['field_area']['table'] = 'field_data_field_area';
  $handler->display->display_options['fields']['field_area']['field'] = 'field_area';
  $handler->display->display_options['fields']['field_area']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['fields']['field_area']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Общая площадь */
  $handler->display->display_options['fields']['field_gross_area_1']['id'] = 'field_gross_area_1';
  $handler->display->display_options['fields']['field_gross_area_1']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['fields']['field_gross_area_1']['field'] = 'field_gross_area';
  /* Field: Content: Балкон */
  $handler->display->display_options['fields']['field_balcony']['id'] = 'field_balcony';
  $handler->display->display_options['fields']['field_balcony']['table'] = 'field_data_field_balcony';
  $handler->display->display_options['fields']['field_balcony']['field'] = 'field_balcony';
  /* Field: Content: Главное изображение */
  $handler->display->display_options['fields']['field_main_photo']['id'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['table'] = 'field_data_field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['field'] = 'field_main_photo';
  $handler->display->display_options['fields']['field_main_photo']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['fields']['field_main_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_photo']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Лоджия */
  $handler->display->display_options['fields']['field_loggia']['id'] = 'field_loggia';
  $handler->display->display_options['fields']['field_loggia']['table'] = 'field_data_field_loggia';
  $handler->display->display_options['fields']['field_loggia']['field'] = 'field_loggia';
  /* Field: Taxonomy term: Жилой комплекс */
  $handler->display->display_options['fields']['field_home_complex']['id'] = 'field_home_complex';
  $handler->display->display_options['fields']['field_home_complex']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['fields']['field_home_complex']['field'] = 'field_home_complex';
  $handler->display->display_options['fields']['field_home_complex']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['fields']['field_home_complex']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Застройщик */
  $handler->display->display_options['fields']['field_complex_developer']['id'] = 'field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['field'] = 'field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['relationship'] = 'field_home_complex_target_id';
  /* Field: Content: Планировка квартиры */
  $handler->display->display_options['fields']['field_plan_apartment']['id'] = 'field_plan_apartment';
  $handler->display->display_options['fields']['field_plan_apartment']['table'] = 'field_data_field_plan_apartment';
  $handler->display->display_options['fields']['field_plan_apartment']['field'] = 'field_plan_apartment';
  $handler->display->display_options['fields']['field_plan_apartment']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_plan_apartment']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Документы */
  $handler->display->display_options['fields']['field_documents']['id'] = 'field_documents';
  $handler->display->display_options['fields']['field_documents']['table'] = 'field_data_field_documents';
  $handler->display->display_options['fields']['field_documents']['field'] = 'field_documents';
  $handler->display->display_options['fields']['field_documents']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['fields']['field_documents']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_documents']['type'] = 'file_default';
  $handler->display->display_options['fields']['field_documents']['group_column'] = '';
  $handler->display->display_options['fields']['field_documents']['delta_offset'] = '0';
  /* Field: Content: Этаж */
  $handler->display->display_options['fields']['field_apartment_floor']['id'] = 'field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['field'] = 'field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Общая площадь */
  $handler->display->display_options['fields']['field_gross_area']['id'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['field'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Жилая площадь */
  $handler->display->display_options['fields']['field_living_space']['id'] = 'field_living_space';
  $handler->display->display_options['fields']['field_living_space']['table'] = 'field_data_field_living_space';
  $handler->display->display_options['fields']['field_living_space']['field'] = 'field_living_space';
  $handler->display->display_options['fields']['field_living_space']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Стоимость */
  $handler->display->display_options['fields']['field_full_cost']['id'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['table'] = 'field_data_field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['field'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Цена за кв.м */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'apartament' => 'apartament',
  );
  /* Filter criterion: Content: Дом (field_apartament_home) */
  $handler->display->display_options['filters']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['filters']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_apartament_home_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['operator_id'] = 'field_apartament_home_tid_op';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['label'] = 'Дом (field_apartament_home)';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['operator'] = 'field_apartament_home_tid_op';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['identifier'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_apartament_home_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_apartament_home_tid']['vocabulary'] = 'homes';
  /* Filter criterion: Content: Количество комнат (field_number_rooms) */
  $handler->display->display_options['filters']['field_number_rooms_value']['id'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['table'] = 'field_data_field_number_rooms';
  $handler->display->display_options['filters']['field_number_rooms_value']['field'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['operator_id'] = 'field_number_rooms_value_op';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['label'] = 'Количество комнат (field_number_rooms)';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['operator'] = 'field_number_rooms_value_op';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['identifier'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Квартиры на этаже */
  $handler = $view->new_display('panel_pane', 'Квартиры на этаже', 'apartment_floor');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Предложения на этаже';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Дом (field_apartament_home) */
  $handler->display->display_options['relationships']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: номер квартиры */
  $handler->display->display_options['fields']['field_number_apartament']['id'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['field'] = 'field_number_apartament';
  /* Field: Content: Статус */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['argument'] = '00';
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
    'apartament' => 'apartament',
  );
  /* Filter criterion: Content: Этаж (field_apartment_floor) */
  $handler->display->display_options['filters']['field_apartment_floor_value']['id'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['filters']['field_apartment_floor_value']['field'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['value']['value'] = '3';
  /* Filter criterion: Content: Секция (field_section) */
  $handler->display->display_options['filters']['field_section_value']['id'] = 'field_section_value';
  $handler->display->display_options['filters']['field_section_value']['table'] = 'field_data_field_section';
  $handler->display->display_options['filters']['field_section_value']['field'] = 'field_section_value';
  $handler->display->display_options['filters']['field_section_value']['value'] = '1';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Квартиры в доме */
  $handler = $view->new_display('panel_pane', 'Квартиры в доме', 'apartment_home');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Предложения в этом доме';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Дом (field_apartament_home) */
  $handler->display->display_options['relationships']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Общая площадь */
  $handler->display->display_options['fields']['field_gross_area']['id'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['field'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Стоимость */
  $handler->display->display_options['fields']['field_full_cost']['id'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['table'] = 'field_data_field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['field'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: номер квартиры */
  $handler->display->display_options['fields']['field_number_apartament']['id'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['field'] = 'field_number_apartament';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['argument'] = '00';
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
    'apartament' => 'apartament',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['operator'] = '!=';
  $handler->display->display_options['filters']['nid']['value']['value'] = '0';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Результаты поиска */
  $handler = $view->new_display('panel_pane', 'Результаты поиска', 'result_search');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
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
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Дом (field_apartament_home) */
  $handler->display->display_options['relationships']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['relationship'] = 'field_apartament_home_tid';
  /* Relationship: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['relationship'] = 'field_home_complex_target_id';
  /* Relationship: Taxonomy term: Срок сдачи (field_home_deadline) */
  $handler->display->display_options['relationships']['field_home_deadline_value']['id'] = 'field_home_deadline_value';
  $handler->display->display_options['relationships']['field_home_deadline_value']['table'] = 'field_data_field_home_deadline';
  $handler->display->display_options['relationships']['field_home_deadline_value']['field'] = 'field_home_deadline_value';
  $handler->display->display_options['relationships']['field_home_deadline_value']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_home_deadline_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: номер квартиры */
  $handler->display->display_options['fields']['field_number_apartament']['id'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['field'] = 'field_number_apartament';
  /* Field: Content: Район */
  $handler->display->display_options['fields']['field_area']['id'] = 'field_area';
  $handler->display->display_options['fields']['field_area']['table'] = 'field_data_field_area';
  $handler->display->display_options['fields']['field_area']['field'] = 'field_area';
  $handler->display->display_options['fields']['field_area']['relationship'] = 'field_home_complex_target_id';
  /* Field: Content: Застройщик */
  $handler->display->display_options['fields']['field_complex_developer']['id'] = 'field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['field'] = 'field_complex_developer';
  $handler->display->display_options['fields']['field_complex_developer']['relationship'] = 'field_home_complex_target_id';
  /* Field: Taxonomy term: Жилой комплекс */
  $handler->display->display_options['fields']['field_home_complex']['id'] = 'field_home_complex';
  $handler->display->display_options['fields']['field_home_complex']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['fields']['field_home_complex']['field'] = 'field_home_complex';
  $handler->display->display_options['fields']['field_home_complex']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['fields']['field_home_complex']['settings'] = array(
    'link' => 0,
  );
  /* Field: Taxonomy term: Адрес дома */
  $handler->display->display_options['fields']['field_address_house']['id'] = 'field_address_house';
  $handler->display->display_options['fields']['field_address_house']['table'] = 'field_data_field_address_house';
  $handler->display->display_options['fields']['field_address_house']['field'] = 'field_address_house';
  $handler->display->display_options['fields']['field_address_house']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['fields']['field_address_house']['label'] = 'Адрес';
  /* Field: Content: Количество комнат */
  $handler->display->display_options['fields']['field_number_rooms']['id'] = 'field_number_rooms';
  $handler->display->display_options['fields']['field_number_rooms']['table'] = 'field_data_field_number_rooms';
  $handler->display->display_options['fields']['field_number_rooms']['field'] = 'field_number_rooms';
  /* Field: Content: Этаж */
  $handler->display->display_options['fields']['field_apartment_floor']['id'] = 'field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['field'] = 'field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Общая площадь */
  $handler->display->display_options['fields']['field_gross_area']['id'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['field'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Цена за кв.м */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Стоимость */
  $handler->display->display_options['fields']['field_full_cost']['id'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['table'] = 'field_data_field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['field'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Статус */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['label'] = '';
  $handler->display->display_options['fields']['field_status']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Количество этажей */
  $handler->display->display_options['fields']['field_number_floor']['id'] = 'field_number_floor';
  $handler->display->display_options['fields']['field_number_floor']['table'] = 'field_data_field_number_floor';
  $handler->display->display_options['fields']['field_number_floor']['field'] = 'field_number_floor';
  $handler->display->display_options['fields']['field_number_floor']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['fields']['field_number_floor']['label'] = '';
  $handler->display->display_options['fields']['field_number_floor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_number_floor']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Квартал */
  $handler->display->display_options['fields']['field_home_deadline_quarter']['id'] = 'field_home_deadline_quarter';
  $handler->display->display_options['fields']['field_home_deadline_quarter']['table'] = 'field_data_field_home_deadline_quarter';
  $handler->display->display_options['fields']['field_home_deadline_quarter']['field'] = 'field_home_deadline_quarter';
  $handler->display->display_options['fields']['field_home_deadline_quarter']['relationship'] = 'field_home_deadline_value';
  /* Field: Field collection item: Год */
  $handler->display->display_options['fields']['field_home_deadline_year']['id'] = 'field_home_deadline_year';
  $handler->display->display_options['fields']['field_home_deadline_year']['table'] = 'field_data_field_home_deadline_year';
  $handler->display->display_options['fields']['field_home_deadline_year']['field'] = 'field_home_deadline_year';
  $handler->display->display_options['fields']['field_home_deadline_year']['relationship'] = 'field_home_deadline_value';
  $handler->display->display_options['fields']['field_home_deadline_year']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Балкон */
  $handler->display->display_options['fields']['field_balcony']['id'] = 'field_balcony';
  $handler->display->display_options['fields']['field_balcony']['table'] = 'field_data_field_balcony';
  $handler->display->display_options['fields']['field_balcony']['field'] = 'field_balcony';
  /* Field: Content: Лоджия */
  $handler->display->display_options['fields']['field_loggia']['id'] = 'field_loggia';
  $handler->display->display_options['fields']['field_loggia']['table'] = 'field_data_field_loggia';
  $handler->display->display_options['fields']['field_loggia']['field'] = 'field_loggia';
  /* Field: Content: Балкон и лоджия */
  $handler->display->display_options['fields']['field_balcony_loggia']['id'] = 'field_balcony_loggia';
  $handler->display->display_options['fields']['field_balcony_loggia']['table'] = 'field_data_field_balcony_loggia';
  $handler->display->display_options['fields']['field_balcony_loggia']['field'] = 'field_balcony_loggia';
  /* Field: Content: Высота потолка */
  $handler->display->display_options['fields']['field_apartment_ceiling_height']['id'] = 'field_apartment_ceiling_height';
  $handler->display->display_options['fields']['field_apartment_ceiling_height']['table'] = 'field_data_field_apartment_ceiling_height';
  $handler->display->display_options['fields']['field_apartment_ceiling_height']['field'] = 'field_apartment_ceiling_height';
  $handler->display->display_options['fields']['field_apartment_ceiling_height']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Этаж (field_apartment_floor) */
  $handler->display->display_options['sorts']['field_apartment_floor_value']['id'] = 'field_apartment_floor_value';
  $handler->display->display_options['sorts']['field_apartment_floor_value']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['sorts']['field_apartment_floor_value']['field'] = 'field_apartment_floor_value';
  $handler->display->display_options['sorts']['field_apartment_floor_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_apartment_floor_value']['expose']['label'] = 'Этаж (field_apartment_floor)';
  /* Sort criterion: Content: Общая площадь (field_gross_area) */
  $handler->display->display_options['sorts']['field_gross_area_value']['id'] = 'field_gross_area_value';
  $handler->display->display_options['sorts']['field_gross_area_value']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['sorts']['field_gross_area_value']['field'] = 'field_gross_area_value';
  $handler->display->display_options['sorts']['field_gross_area_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_gross_area_value']['expose']['label'] = 'Общая площадь (field_gross_area)';
  /* Sort criterion: Content: Цена за кв.м (field_price) */
  $handler->display->display_options['sorts']['field_price_value']['id'] = 'field_price_value';
  $handler->display->display_options['sorts']['field_price_value']['table'] = 'field_data_field_price';
  $handler->display->display_options['sorts']['field_price_value']['field'] = 'field_price_value';
  $handler->display->display_options['sorts']['field_price_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_price_value']['expose']['label'] = 'Цена за кв.м (field_price)';
  /* Sort criterion: Content: Стоимость (field_full_cost) */
  $handler->display->display_options['sorts']['field_full_cost_value']['id'] = 'field_full_cost_value';
  $handler->display->display_options['sorts']['field_full_cost_value']['table'] = 'field_data_field_full_cost';
  $handler->display->display_options['sorts']['field_full_cost_value']['field'] = 'field_full_cost_value';
  $handler->display->display_options['sorts']['field_full_cost_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_full_cost_value']['expose']['label'] = 'Стоимость (field_full_cost)';
  /* Sort criterion: Content: Количество комнат (field_number_rooms) */
  $handler->display->display_options['sorts']['field_number_rooms_value']['id'] = 'field_number_rooms_value';
  $handler->display->display_options['sorts']['field_number_rooms_value']['table'] = 'field_data_field_number_rooms';
  $handler->display->display_options['sorts']['field_number_rooms_value']['field'] = 'field_number_rooms_value';
  $handler->display->display_options['sorts']['field_number_rooms_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_number_rooms_value']['expose']['label'] = 'Количество комнат (field_number_rooms)';
  /* Sort criterion: Taxonomy term: Срок сдачи (field_deadline) */
  $handler->display->display_options['sorts']['field_deadline_value']['id'] = 'field_deadline_value';
  $handler->display->display_options['sorts']['field_deadline_value']['table'] = 'field_data_field_deadline';
  $handler->display->display_options['sorts']['field_deadline_value']['field'] = 'field_deadline_value';
  $handler->display->display_options['sorts']['field_deadline_value']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['sorts']['field_deadline_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_deadline_value']['expose']['label'] = 'Срок сдачи (field_deadline)';
  /* Sort criterion: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['sorts']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['sorts']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['sorts']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['sorts']['field_complex_developer_tid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['sorts']['field_complex_developer_tid']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_complex_developer_tid']['expose']['label'] = 'Застройщик (field_complex_developer)';
  /* Sort criterion: Taxonomy term: Жилой комплекс (field_home_complex) */
  $handler->display->display_options['sorts']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['sorts']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['sorts']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['sorts']['field_home_complex_target_id']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['sorts']['field_home_complex_target_id']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_home_complex_target_id']['expose']['label'] = 'Жилой комплекс (field_home_complex)';
  /* Sort criterion: Content: Высота потолка (field_apartment_ceiling_height) */
  $handler->display->display_options['sorts']['field_apartment_ceiling_height_value']['id'] = 'field_apartment_ceiling_height_value';
  $handler->display->display_options['sorts']['field_apartment_ceiling_height_value']['table'] = 'field_data_field_apartment_ceiling_height';
  $handler->display->display_options['sorts']['field_apartment_ceiling_height_value']['field'] = 'field_apartment_ceiling_height_value';
  $handler->display->display_options['sorts']['field_apartment_ceiling_height_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_apartment_ceiling_height_value']['expose']['label'] = 'Высота потолка (field_apartment_ceiling_height)';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
    'apartament' => 'apartament',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Район (field_area) */
  $handler->display->display_options['filters']['field_area_tid']['id'] = 'field_area_tid';
  $handler->display->display_options['filters']['field_area_tid']['table'] = 'field_data_field_area';
  $handler->display->display_options['filters']['field_area_tid']['field'] = 'field_area_tid';
  $handler->display->display_options['filters']['field_area_tid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_area_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_area_tid']['expose']['operator_id'] = 'field_area_tid_op';
  $handler->display->display_options['filters']['field_area_tid']['expose']['label'] = 'Район (field_area)';
  $handler->display->display_options['filters']['field_area_tid']['expose']['operator'] = 'field_area_tid_op';
  $handler->display->display_options['filters']['field_area_tid']['expose']['identifier'] = 'field_area_tid';
  $handler->display->display_options['filters']['field_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_area_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_area_tid']['vocabulary'] = 'area';
  /* Filter criterion: Content: Этаж (field_apartment_floor) */
  $handler->display->display_options['filters']['field_apartment_floor_value']['id'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['filters']['field_apartment_floor_value']['field'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_apartment_floor_value']['group'] = 1;
  $handler->display->display_options['filters']['field_apartment_floor_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['operator_id'] = 'field_apartment_floor_value_op';
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['label'] = 'Этаж (field_apartment_floor)';
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['operator'] = 'field_apartment_floor_value_op';
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['identifier'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Количество комнат (field_number_rooms) */
  $handler->display->display_options['filters']['field_number_rooms_value']['id'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['table'] = 'field_data_field_number_rooms';
  $handler->display->display_options['filters']['field_number_rooms_value']['field'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['group'] = 1;
  $handler->display->display_options['filters']['field_number_rooms_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['operator_id'] = 'field_number_rooms_value_op';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['label'] = 'Количество комнат (field_number_rooms)';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['operator'] = 'field_number_rooms_value_op';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['identifier'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Общая площадь (field_gross_area) */
  $handler->display->display_options['filters']['field_gross_area_value']['id'] = 'field_gross_area_value';
  $handler->display->display_options['filters']['field_gross_area_value']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['filters']['field_gross_area_value']['field'] = 'field_gross_area_value';
  $handler->display->display_options['filters']['field_gross_area_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_gross_area_value']['group'] = 1;
  $handler->display->display_options['filters']['field_gross_area_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['operator_id'] = 'field_gross_area_value_op';
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['label'] = 'Общая площадь (field_gross_area)';
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['operator'] = 'field_gross_area_value_op';
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['identifier'] = 'field_gross_area_value';
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Метро (field_complex_metro) */
  $handler->display->display_options['filters']['field_complex_metro_tid']['id'] = 'field_complex_metro_tid';
  $handler->display->display_options['filters']['field_complex_metro_tid']['table'] = 'field_data_field_complex_metro';
  $handler->display->display_options['filters']['field_complex_metro_tid']['field'] = 'field_complex_metro_tid';
  $handler->display->display_options['filters']['field_complex_metro_tid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_complex_metro_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_complex_metro_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_complex_metro_tid']['expose']['operator_id'] = 'field_complex_metro_tid_op';
  $handler->display->display_options['filters']['field_complex_metro_tid']['expose']['label'] = 'Метро (field_complex_metro)';
  $handler->display->display_options['filters']['field_complex_metro_tid']['expose']['operator'] = 'field_complex_metro_tid_op';
  $handler->display->display_options['filters']['field_complex_metro_tid']['expose']['identifier'] = 'field_complex_metro_tid';
  $handler->display->display_options['filters']['field_complex_metro_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_complex_metro_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_complex_metro_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_complex_metro_tid']['vocabulary'] = 'metro';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  /* Filter criterion: Taxonomy term: Город (field_city) */
  $handler->display->display_options['filters']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['filters']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['filters']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['filters']['field_city_tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_city_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_city_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_city_tid']['expose']['operator_id'] = 'field_city_tid_op';
  $handler->display->display_options['filters']['field_city_tid']['expose']['label'] = 'Город (field_city)';
  $handler->display->display_options['filters']['field_city_tid']['expose']['operator'] = 'field_city_tid_op';
  $handler->display->display_options['filters']['field_city_tid']['expose']['identifier'] = 'field_city_tid';
  $handler->display->display_options['filters']['field_city_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_city_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_city_tid']['vocabulary'] = 'cities';
  /* Filter criterion: Content: Статус (field_status) */
  $handler->display->display_options['filters']['field_status_value']['id'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['table'] = 'field_data_field_status';
  $handler->display->display_options['filters']['field_status_value']['field'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_status_value']['expose']['operator_id'] = 'field_status_value_op';
  $handler->display->display_options['filters']['field_status_value']['expose']['label'] = 'Статус (field_status)';
  $handler->display->display_options['filters']['field_status_value']['expose']['operator'] = 'field_status_value_op';
  $handler->display->display_options['filters']['field_status_value']['expose']['identifier'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Field collection item: Квартал (field_home_deadline_quarter) */
  $handler->display->display_options['filters']['field_home_deadline_quarter_value']['id'] = 'field_home_deadline_quarter_value';
  $handler->display->display_options['filters']['field_home_deadline_quarter_value']['table'] = 'field_data_field_home_deadline_quarter';
  $handler->display->display_options['filters']['field_home_deadline_quarter_value']['field'] = 'field_home_deadline_quarter_value';
  $handler->display->display_options['filters']['field_home_deadline_quarter_value']['relationship'] = 'field_home_deadline_value';
  $handler->display->display_options['filters']['field_home_deadline_quarter_value']['group'] = 1;
  $handler->display->display_options['filters']['field_home_deadline_quarter_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_home_deadline_quarter_value']['expose']['operator_id'] = 'field_home_deadline_quarter_value_op';
  $handler->display->display_options['filters']['field_home_deadline_quarter_value']['expose']['label'] = 'Квартал (field_home_deadline_quarter)';
  $handler->display->display_options['filters']['field_home_deadline_quarter_value']['expose']['operator'] = 'field_home_deadline_quarter_value_op';
  $handler->display->display_options['filters']['field_home_deadline_quarter_value']['expose']['identifier'] = 'field_home_deadline_quarter_value';
  $handler->display->display_options['filters']['field_home_deadline_quarter_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_home_deadline_quarter_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Field collection item: Год (field_home_deadline_year) */
  $handler->display->display_options['filters']['field_home_deadline_year_value']['id'] = 'field_home_deadline_year_value';
  $handler->display->display_options['filters']['field_home_deadline_year_value']['table'] = 'field_data_field_home_deadline_year';
  $handler->display->display_options['filters']['field_home_deadline_year_value']['field'] = 'field_home_deadline_year_value';
  $handler->display->display_options['filters']['field_home_deadline_year_value']['relationship'] = 'field_home_deadline_value';
  $handler->display->display_options['filters']['field_home_deadline_year_value']['operator'] = 'regular_expression';
  $handler->display->display_options['filters']['field_home_deadline_year_value']['group'] = 1;
  $handler->display->display_options['filters']['field_home_deadline_year_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_home_deadline_year_value']['expose']['operator_id'] = 'field_home_deadline_year_value_op';
  $handler->display->display_options['filters']['field_home_deadline_year_value']['expose']['label'] = 'Год (field_home_deadline_year)';
  $handler->display->display_options['filters']['field_home_deadline_year_value']['expose']['operator'] = 'field_home_deadline_year_value_op';
  $handler->display->display_options['filters']['field_home_deadline_year_value']['expose']['identifier'] = 'field_home_deadline_year_value';
  $handler->display->display_options['filters']['field_home_deadline_year_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Taxonomy term: парковка (field_parking) */
  $handler->display->display_options['filters']['field_parking_value']['id'] = 'field_parking_value';
  $handler->display->display_options['filters']['field_parking_value']['table'] = 'field_data_field_parking';
  $handler->display->display_options['filters']['field_parking_value']['field'] = 'field_parking_value';
  $handler->display->display_options['filters']['field_parking_value']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_parking_value']['group'] = 1;
  $handler->display->display_options['filters']['field_parking_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_parking_value']['expose']['operator_id'] = 'field_parking_value_op';
  $handler->display->display_options['filters']['field_parking_value']['expose']['label'] = 'парковка (field_parking)';
  $handler->display->display_options['filters']['field_parking_value']['expose']['operator'] = 'field_parking_value_op';
  $handler->display->display_options['filters']['field_parking_value']['expose']['identifier'] = 'field_parking_value';
  $handler->display->display_options['filters']['field_parking_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Taxonomy term: Материал стен (field_material) */
  $handler->display->display_options['filters']['field_material_tid']['id'] = 'field_material_tid';
  $handler->display->display_options['filters']['field_material_tid']['table'] = 'field_data_field_material';
  $handler->display->display_options['filters']['field_material_tid']['field'] = 'field_material_tid';
  $handler->display->display_options['filters']['field_material_tid']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_material_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_material_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_material_tid']['expose']['operator_id'] = 'field_material_tid_op';
  $handler->display->display_options['filters']['field_material_tid']['expose']['label'] = 'Материал стен (field_material)';
  $handler->display->display_options['filters']['field_material_tid']['expose']['operator'] = 'field_material_tid_op';
  $handler->display->display_options['filters']['field_material_tid']['expose']['identifier'] = 'field_material_tid';
  $handler->display->display_options['filters']['field_material_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_material_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_material_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_material_tid']['vocabulary'] = 'material';
  /* Filter criterion: Taxonomy term: Срок сдачи (field_deadline) */
  $handler->display->display_options['filters']['field_deadline_value']['id'] = 'field_deadline_value';
  $handler->display->display_options['filters']['field_deadline_value']['table'] = 'field_data_field_deadline';
  $handler->display->display_options['filters']['field_deadline_value']['field'] = 'field_deadline_value';
  $handler->display->display_options['filters']['field_deadline_value']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_deadline_value']['group'] = 1;
  $handler->display->display_options['filters']['field_deadline_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_deadline_value']['expose']['operator_id'] = 'field_deadline_value_op';
  $handler->display->display_options['filters']['field_deadline_value']['expose']['label'] = 'Срок сдачи (field_deadline)';
  $handler->display->display_options['filters']['field_deadline_value']['expose']['operator'] = 'field_deadline_value_op';
  $handler->display->display_options['filters']['field_deadline_value']['expose']['identifier'] = 'field_deadline_value';
  $handler->display->display_options['filters']['field_deadline_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_deadline_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_deadline_value']['group_info']['label'] = 'Срок сдачи (field_deadline)';
  $handler->display->display_options['filters']['field_deadline_value']['group_info']['identifier'] = 'field_deadline_value';
  $handler->display->display_options['filters']['field_deadline_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_deadline_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Taxonomy term: Категория (field_home_category) */
  $handler->display->display_options['filters']['field_home_category_tid_1']['id'] = 'field_home_category_tid_1';
  $handler->display->display_options['filters']['field_home_category_tid_1']['table'] = 'field_data_field_home_category';
  $handler->display->display_options['filters']['field_home_category_tid_1']['field'] = 'field_home_category_tid';
  $handler->display->display_options['filters']['field_home_category_tid_1']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_home_category_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_home_category_tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_home_category_tid_1']['expose']['operator_id'] = 'field_home_category_tid_1_op';
  $handler->display->display_options['filters']['field_home_category_tid_1']['expose']['label'] = 'Категория (field_home_category)';
  $handler->display->display_options['filters']['field_home_category_tid_1']['expose']['operator'] = 'field_home_category_tid_1_op';
  $handler->display->display_options['filters']['field_home_category_tid_1']['expose']['identifier'] = 'field_home_category_tid';
  $handler->display->display_options['filters']['field_home_category_tid_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_home_category_tid_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_home_category_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_home_category_tid_1']['vocabulary'] = 'categories';
  /* Filter criterion: Taxonomy term: Жилой комплекс (field_home_complex) */
  $handler->display->display_options['filters']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['filters']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_home_complex_target_id']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_home_complex_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_home_complex_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_home_complex_target_id']['expose']['operator_id'] = 'field_home_complex_target_id_op';
  $handler->display->display_options['filters']['field_home_complex_target_id']['expose']['label'] = 'Жилой комплекс (field_home_complex)';
  $handler->display->display_options['filters']['field_home_complex_target_id']['expose']['operator'] = 'field_home_complex_target_id_op';
  $handler->display->display_options['filters']['field_home_complex_target_id']['expose']['identifier'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_home_complex_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_home_complex_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['filters']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['filters']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_complex_developer_tid']['group'] = 1;
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
  /* Filter criterion: Content: Стоимость (field_full_cost) */
  $handler->display->display_options['filters']['field_full_cost_value']['id'] = 'field_full_cost_value';
  $handler->display->display_options['filters']['field_full_cost_value']['table'] = 'field_data_field_full_cost';
  $handler->display->display_options['filters']['field_full_cost_value']['field'] = 'field_full_cost_value';
  $handler->display->display_options['filters']['field_full_cost_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_full_cost_value']['group'] = 1;
  $handler->display->display_options['filters']['field_full_cost_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_full_cost_value']['expose']['operator_id'] = 'field_full_cost_value_op';
  $handler->display->display_options['filters']['field_full_cost_value']['expose']['label'] = 'Стоимость (field_full_cost)';
  $handler->display->display_options['filters']['field_full_cost_value']['expose']['operator'] = 'field_full_cost_value_op';
  $handler->display->display_options['filters']['field_full_cost_value']['expose']['identifier'] = 'field_full_cost_value';
  $handler->display->display_options['filters']['field_full_cost_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Цена за кв.м (field_price) */
  $handler->display->display_options['filters']['field_price_value']['id'] = 'field_price_value';
  $handler->display->display_options['filters']['field_price_value']['table'] = 'field_data_field_price';
  $handler->display->display_options['filters']['field_price_value']['field'] = 'field_price_value';
  $handler->display->display_options['filters']['field_price_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_price_value']['group'] = 1;
  $handler->display->display_options['filters']['field_price_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_price_value']['expose']['operator_id'] = 'field_price_value_op';
  $handler->display->display_options['filters']['field_price_value']['expose']['label'] = 'Цена за кв.м (field_price)';
  $handler->display->display_options['filters']['field_price_value']['expose']['operator'] = 'field_price_value_op';
  $handler->display->display_options['filters']['field_price_value']['expose']['identifier'] = 'field_price_value';
  $handler->display->display_options['filters']['field_price_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_price_value']['group_info']['label'] = 'Цена за кв.м (field_price)';
  $handler->display->display_options['filters']['field_price_value']['group_info']['identifier'] = 'field_price_value';
  $handler->display->display_options['filters']['field_price_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_price_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Высота потолка (field_apartment_ceiling_height) */
  $handler->display->display_options['filters']['field_apartment_ceiling_height_value']['id'] = 'field_apartment_ceiling_height_value';
  $handler->display->display_options['filters']['field_apartment_ceiling_height_value']['table'] = 'field_data_field_apartment_ceiling_height';
  $handler->display->display_options['filters']['field_apartment_ceiling_height_value']['field'] = 'field_apartment_ceiling_height_value';
  $handler->display->display_options['filters']['field_apartment_ceiling_height_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_apartment_ceiling_height_value']['group'] = 1;
  $handler->display->display_options['filters']['field_apartment_ceiling_height_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_apartment_ceiling_height_value']['expose']['operator_id'] = 'field_apartment_ceiling_height_value_op';
  $handler->display->display_options['filters']['field_apartment_ceiling_height_value']['expose']['label'] = 'Высота потолка (field_apartment_ceiling_height)';
  $handler->display->display_options['filters']['field_apartment_ceiling_height_value']['expose']['operator'] = 'field_apartment_ceiling_height_value_op';
  $handler->display->display_options['filters']['field_apartment_ceiling_height_value']['expose']['identifier'] = 'field_apartment_ceiling_height_value';
  $handler->display->display_options['filters']['field_apartment_ceiling_height_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Лоджия (field_loggia) */
  $handler->display->display_options['filters']['field_loggia_value']['id'] = 'field_loggia_value';
  $handler->display->display_options['filters']['field_loggia_value']['table'] = 'field_data_field_loggia';
  $handler->display->display_options['filters']['field_loggia_value']['field'] = 'field_loggia_value';
  $handler->display->display_options['filters']['field_loggia_value']['group'] = 2;
  $handler->display->display_options['filters']['field_loggia_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_loggia_value']['expose']['operator_id'] = 'field_loggia_value_op';
  $handler->display->display_options['filters']['field_loggia_value']['expose']['label'] = 'Лоджия (field_loggia)';
  $handler->display->display_options['filters']['field_loggia_value']['expose']['operator'] = 'field_loggia_value_op';
  $handler->display->display_options['filters']['field_loggia_value']['expose']['identifier'] = 'field_loggia_value';
  $handler->display->display_options['filters']['field_loggia_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Балкон (field_balcony) */
  $handler->display->display_options['filters']['field_balcony_value']['id'] = 'field_balcony_value';
  $handler->display->display_options['filters']['field_balcony_value']['table'] = 'field_data_field_balcony';
  $handler->display->display_options['filters']['field_balcony_value']['field'] = 'field_balcony_value';
  $handler->display->display_options['filters']['field_balcony_value']['group'] = 2;
  $handler->display->display_options['filters']['field_balcony_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_balcony_value']['expose']['operator_id'] = 'field_balcony_value_op';
  $handler->display->display_options['filters']['field_balcony_value']['expose']['label'] = 'Балкон (field_balcony)';
  $handler->display->display_options['filters']['field_balcony_value']['expose']['operator'] = 'field_balcony_value_op';
  $handler->display->display_options['filters']['field_balcony_value']['expose']['identifier'] = 'field_balcony_value';
  $handler->display->display_options['filters']['field_balcony_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Балкон и лоджия (field_balcony_loggia) */
  $handler->display->display_options['filters']['field_balcony_loggia_value']['id'] = 'field_balcony_loggia_value';
  $handler->display->display_options['filters']['field_balcony_loggia_value']['table'] = 'field_data_field_balcony_loggia';
  $handler->display->display_options['filters']['field_balcony_loggia_value']['field'] = 'field_balcony_loggia_value';
  $handler->display->display_options['filters']['field_balcony_loggia_value']['group'] = 2;
  $handler->display->display_options['filters']['field_balcony_loggia_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_balcony_loggia_value']['expose']['operator_id'] = 'field_balcony_loggia_value_op';
  $handler->display->display_options['filters']['field_balcony_loggia_value']['expose']['label'] = 'Балкон и лоджия (field_balcony_loggia)';
  $handler->display->display_options['filters']['field_balcony_loggia_value']['expose']['operator'] = 'field_balcony_loggia_value_op';
  $handler->display->display_options['filters']['field_balcony_loggia_value']['expose']['identifier'] = 'field_balcony_loggia_value';
  $handler->display->display_options['filters']['field_balcony_loggia_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Полученные пользователем */
  $handler = $view->new_display('panel_pane', 'Полученные пользователем', 'user_apartment');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_received_id_user']['id'] = 'reverse_field_received_id_user';
  $handler->display->display_options['relationships']['reverse_field_received_id_user']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_received_id_user']['field'] = 'reverse_field_received_id_user';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: id квартиры */
  $handler->display->display_options['fields']['field_id_appartament']['id'] = 'field_id_appartament';
  $handler->display->display_options['fields']['field_id_appartament']['table'] = 'field_data_field_id_appartament';
  $handler->display->display_options['fields']['field_id_appartament']['field'] = 'field_id_appartament';
  /* Field: Content: номер квартиры */
  $handler->display->display_options['fields']['field_number_apartament']['id'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['field'] = 'field_number_apartament';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'reverse_field_received_id_user';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
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
    'apartament' => 'apartament',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Квартиры жилого комплекса для плана жк */
  $handler = $view->new_display('panel_pane', 'Квартиры жилого комплекса для плана жк', 'apartments_complex_for_plan');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Дом (field_apartament_home) */
  $handler->display->display_options['relationships']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: номер квартиры */
  $handler->display->display_options['fields']['field_number_apartament']['id'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['field'] = 'field_number_apartament';
  /* Field: Content: Этаж */
  $handler->display->display_options['fields']['field_apartment_floor']['id'] = 'field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['field'] = 'field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['label'] = '';
  $handler->display->display_options['fields']['field_apartment_floor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_apartment_floor']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content revision: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node_revision';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'apartament' => 'apartament',
  );
  /* Filter criterion: Content: Статус (field_status) */
  $handler->display->display_options['filters']['field_status_value']['id'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['table'] = 'field_data_field_status';
  $handler->display->display_options['filters']['field_status_value']['field'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Квартиры застройщика */
  $handler = $view->new_display('panel_pane', 'Квартиры застройщика', 'apartment_developer');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
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
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Дом (field_apartament_home) */
  $handler->display->display_options['relationships']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['relationship'] = 'field_apartament_home_tid';
  /* Relationship: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: номер квартиры */
  $handler->display->display_options['fields']['field_number_apartament']['id'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['field'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['type'] = 'text_plain';
  /* Field: Taxonomy term: Адрес дома */
  $handler->display->display_options['fields']['field_address_house']['id'] = 'field_address_house';
  $handler->display->display_options['fields']['field_address_house']['table'] = 'field_data_field_address_house';
  $handler->display->display_options['fields']['field_address_house']['field'] = 'field_address_house';
  $handler->display->display_options['fields']['field_address_house']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['fields']['field_address_house']['label'] = 'Адрес';
  $handler->display->display_options['fields']['field_address_house']['type'] = 'text_plain';
  /* Field: Content: Секция */
  $handler->display->display_options['fields']['field_section']['id'] = 'field_section';
  $handler->display->display_options['fields']['field_section']['table'] = 'field_data_field_section';
  $handler->display->display_options['fields']['field_section']['field'] = 'field_section';
  $handler->display->display_options['fields']['field_section']['type'] = 'text_plain';
  /* Field: Content: Количество комнат */
  $handler->display->display_options['fields']['field_number_rooms']['id'] = 'field_number_rooms';
  $handler->display->display_options['fields']['field_number_rooms']['table'] = 'field_data_field_number_rooms';
  $handler->display->display_options['fields']['field_number_rooms']['field'] = 'field_number_rooms';
  /* Field: Content: Этаж */
  $handler->display->display_options['fields']['field_apartment_floor']['id'] = 'field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['field'] = 'field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['label'] = '';
  $handler->display->display_options['fields']['field_apartment_floor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_apartment_floor']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_apartment_floor']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Общая площадь */
  $handler->display->display_options['fields']['field_gross_area']['id'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['field'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_gross_area']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Цена за кв.м */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Стоимость */
  $handler->display->display_options['fields']['field_full_cost']['id'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['table'] = 'field_data_field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['field'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Статус */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  /* Field: Taxonomy term: Количество этажей */
  $handler->display->display_options['fields']['field_number_floor']['id'] = 'field_number_floor';
  $handler->display->display_options['fields']['field_number_floor']['table'] = 'field_data_field_number_floor';
  $handler->display->display_options['fields']['field_number_floor']['field'] = 'field_number_floor';
  $handler->display->display_options['fields']['field_number_floor']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['fields']['field_number_floor']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_number_floor']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_home_complex_target_id';
  /* Field: Content: Балкон */
  $handler->display->display_options['fields']['field_balcony']['id'] = 'field_balcony';
  $handler->display->display_options['fields']['field_balcony']['table'] = 'field_data_field_balcony';
  $handler->display->display_options['fields']['field_balcony']['field'] = 'field_balcony';
  /* Field: Content: Лоджия */
  $handler->display->display_options['fields']['field_loggia']['id'] = 'field_loggia';
  $handler->display->display_options['fields']['field_loggia']['table'] = 'field_data_field_loggia';
  $handler->display->display_options['fields']['field_loggia']['field'] = 'field_loggia';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Этаж (field_apartment_floor) */
  $handler->display->display_options['sorts']['field_apartment_floor_value']['id'] = 'field_apartment_floor_value';
  $handler->display->display_options['sorts']['field_apartment_floor_value']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['sorts']['field_apartment_floor_value']['field'] = 'field_apartment_floor_value';
  $handler->display->display_options['sorts']['field_apartment_floor_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_apartment_floor_value']['expose']['label'] = 'Этаж (field_apartment_floor)';
  /* Sort criterion: Content: Общая площадь (field_gross_area) */
  $handler->display->display_options['sorts']['field_gross_area_value']['id'] = 'field_gross_area_value';
  $handler->display->display_options['sorts']['field_gross_area_value']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['sorts']['field_gross_area_value']['field'] = 'field_gross_area_value';
  $handler->display->display_options['sorts']['field_gross_area_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_gross_area_value']['expose']['label'] = 'Общая площадь (field_gross_area)';
  /* Sort criterion: Content: Цена за кв.м (field_price) */
  $handler->display->display_options['sorts']['field_price_value']['id'] = 'field_price_value';
  $handler->display->display_options['sorts']['field_price_value']['table'] = 'field_data_field_price';
  $handler->display->display_options['sorts']['field_price_value']['field'] = 'field_price_value';
  $handler->display->display_options['sorts']['field_price_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_price_value']['expose']['label'] = 'Цена за кв.м (field_price)';
  /* Sort criterion: Content: Стоимость (field_full_cost) */
  $handler->display->display_options['sorts']['field_full_cost_value']['id'] = 'field_full_cost_value';
  $handler->display->display_options['sorts']['field_full_cost_value']['table'] = 'field_data_field_full_cost';
  $handler->display->display_options['sorts']['field_full_cost_value']['field'] = 'field_full_cost_value';
  $handler->display->display_options['sorts']['field_full_cost_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_full_cost_value']['expose']['label'] = 'Стоимость (field_full_cost)';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['sorts']['random']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['random']['expose']['label'] = 'Случайно';
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
    'apartament' => 'apartament',
  );
  /* Filter criterion: Content: Дом (field_apartament_home) */
  $handler->display->display_options['filters']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['filters']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_apartament_home_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['operator_id'] = 'field_apartament_home_tid_op';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['label'] = 'Дом (field_apartament_home)';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['operator'] = 'field_apartament_home_tid_op';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['identifier'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_apartament_home_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_apartament_home_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_apartament_home_tid']['vocabulary'] = 'homes';
  /* Filter criterion: Content: Количество комнат (field_number_rooms) */
  $handler->display->display_options['filters']['field_number_rooms_value']['id'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['table'] = 'field_data_field_number_rooms';
  $handler->display->display_options['filters']['field_number_rooms_value']['field'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['operator_id'] = 'field_number_rooms_value_op';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['label'] = 'Количество комнат (field_number_rooms)';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['operator'] = 'field_number_rooms_value_op';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['identifier'] = 'field_number_rooms_value';
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_number_rooms_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Этаж (field_apartment_floor) */
  $handler->display->display_options['filters']['field_apartment_floor_value']['id'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['filters']['field_apartment_floor_value']['field'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_apartment_floor_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['operator_id'] = 'field_apartment_floor_value_op';
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['label'] = 'Этаж (field_apartment_floor)';
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['operator'] = 'field_apartment_floor_value_op';
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['identifier'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_apartment_floor_value']['group_info']['label'] = 'Этаж (field_apartment_floor)';
  $handler->display->display_options['filters']['field_apartment_floor_value']['group_info']['identifier'] = 'field_apartment_floor_value';
  $handler->display->display_options['filters']['field_apartment_floor_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_apartment_floor_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Общая площадь (field_gross_area) */
  $handler->display->display_options['filters']['field_gross_area_value']['id'] = 'field_gross_area_value';
  $handler->display->display_options['filters']['field_gross_area_value']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['filters']['field_gross_area_value']['field'] = 'field_gross_area_value';
  $handler->display->display_options['filters']['field_gross_area_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_gross_area_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['operator_id'] = 'field_gross_area_value_op';
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['label'] = 'Общая площадь (field_gross_area)';
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['operator'] = 'field_gross_area_value_op';
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['identifier'] = 'field_gross_area_value';
  $handler->display->display_options['filters']['field_gross_area_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Секция (field_section) */
  $handler->display->display_options['filters']['field_section_value']['id'] = 'field_section_value';
  $handler->display->display_options['filters']['field_section_value']['table'] = 'field_data_field_section';
  $handler->display->display_options['filters']['field_section_value']['field'] = 'field_section_value';
  $handler->display->display_options['filters']['field_section_value']['operator'] = 'regular_expression';
  $handler->display->display_options['filters']['field_section_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_section_value']['expose']['operator_id'] = 'field_section_value_op';
  $handler->display->display_options['filters']['field_section_value']['expose']['label'] = 'Секция (field_section)';
  $handler->display->display_options['filters']['field_section_value']['expose']['operator'] = 'field_section_value_op';
  $handler->display->display_options['filters']['field_section_value']['expose']['identifier'] = 'field_section_value';
  $handler->display->display_options['filters']['field_section_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_section_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  /* Filter criterion: Content: Статус (field_status) */
  $handler->display->display_options['filters']['field_status_value']['id'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['table'] = 'field_data_field_status';
  $handler->display->display_options['filters']['field_status_value']['field'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_status_value']['expose']['operator_id'] = 'field_status_value_op';
  $handler->display->display_options['filters']['field_status_value']['expose']['label'] = 'Статус (field_status)';
  $handler->display->display_options['filters']['field_status_value']['expose']['operator'] = 'field_status_value_op';
  $handler->display->display_options['filters']['field_status_value']['expose']['identifier'] = 'field_status_value';
  $handler->display->display_options['filters']['field_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Забронированные */
  $handler = $view->new_display('panel_pane', 'Забронированные', 'booking_apartment');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_booking_user_target_id']['id'] = 'field_booking_user_target_id';
  $handler->display->display_options['relationships']['field_booking_user_target_id']['table'] = 'field_data_field_booking_user';
  $handler->display->display_options['relationships']['field_booking_user_target_id']['field'] = 'field_booking_user_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_booking_apartment_target_id']['id'] = 'field_booking_apartment_target_id';
  $handler->display->display_options['relationships']['field_booking_apartment_target_id']['table'] = 'field_data_field_booking_apartment';
  $handler->display->display_options['relationships']['field_booking_apartment_target_id']['field'] = 'field_booking_apartment_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: id квартиры */
  $handler->display->display_options['fields']['field_id_appartament']['id'] = 'field_id_appartament';
  $handler->display->display_options['fields']['field_id_appartament']['table'] = 'field_data_field_id_appartament';
  $handler->display->display_options['fields']['field_id_appartament']['field'] = 'field_id_appartament';
  $handler->display->display_options['fields']['field_id_appartament']['relationship'] = 'field_booking_apartment_target_id';
  /* Field: Content: Номер брони */
  $handler->display->display_options['fields']['field_booking_numbers']['id'] = 'field_booking_numbers';
  $handler->display->display_options['fields']['field_booking_numbers']['table'] = 'field_data_field_booking_numbers';
  $handler->display->display_options['fields']['field_booking_numbers']['field'] = 'field_booking_numbers';
  $handler->display->display_options['fields']['field_booking_numbers']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: номер квартиры */
  $handler->display->display_options['fields']['field_number_apartament']['id'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['field'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['relationship'] = 'field_booking_apartment_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'field_booking_user_target_id';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
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
    'booking' => 'booking',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Сравнение */
  $handler = $view->new_display('panel_pane', 'Сравнение', 'comprassion_apartment');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Дом (field_apartament_home) */
  $handler->display->display_options['relationships']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['relationship'] = 'field_apartament_home_tid';
  /* Relationship: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['relationship'] = 'field_home_complex_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_apartment_comparison_user']['id'] = 'reverse_field_apartment_comparison_user';
  $handler->display->display_options['relationships']['reverse_field_apartment_comparison_user']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_apartment_comparison_user']['field'] = 'reverse_field_apartment_comparison_user';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: номер квартиры */
  $handler->display->display_options['fields']['field_number_apartament']['id'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['field'] = 'field_number_apartament';
  /* Field: Content: Количество комнат */
  $handler->display->display_options['fields']['field_number_rooms']['id'] = 'field_number_rooms';
  $handler->display->display_options['fields']['field_number_rooms']['table'] = 'field_data_field_number_rooms';
  $handler->display->display_options['fields']['field_number_rooms']['field'] = 'field_number_rooms';
  /* Field: Content: Общая площадь */
  $handler->display->display_options['fields']['field_gross_area']['id'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['table'] = 'field_data_field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['field'] = 'field_gross_area';
  $handler->display->display_options['fields']['field_gross_area']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Стоимость */
  $handler->display->display_options['fields']['field_full_cost']['id'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['table'] = 'field_data_field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['field'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_home_complex_target_id';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_complex_developer_tid';
  /* Field: Taxonomy term: Срок сдачи */
  $handler->display->display_options['fields']['field_deadline']['id'] = 'field_deadline';
  $handler->display->display_options['fields']['field_deadline']['table'] = 'field_data_field_deadline';
  $handler->display->display_options['fields']['field_deadline']['field'] = 'field_deadline';
  $handler->display->display_options['fields']['field_deadline']['relationship'] = 'field_apartament_home_tid';
  /* Field: Taxonomy term: парковка */
  $handler->display->display_options['fields']['field_parking']['id'] = 'field_parking';
  $handler->display->display_options['fields']['field_parking']['table'] = 'field_data_field_parking';
  $handler->display->display_options['fields']['field_parking']['field'] = 'field_parking';
  $handler->display->display_options['fields']['field_parking']['relationship'] = 'field_apartament_home_tid';
  /* Field: Content: Балкон */
  $handler->display->display_options['fields']['field_balcony']['id'] = 'field_balcony';
  $handler->display->display_options['fields']['field_balcony']['table'] = 'field_data_field_balcony';
  $handler->display->display_options['fields']['field_balcony']['field'] = 'field_balcony';
  /* Field: Content: Лоджия */
  $handler->display->display_options['fields']['field_loggia']['id'] = 'field_loggia';
  $handler->display->display_options['fields']['field_loggia']['table'] = 'field_data_field_loggia';
  $handler->display->display_options['fields']['field_loggia']['field'] = 'field_loggia';
  /* Field: Content: Этаж */
  $handler->display->display_options['fields']['field_apartment_floor']['id'] = 'field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['table'] = 'field_data_field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['field'] = 'field_apartment_floor';
  $handler->display->display_options['fields']['field_apartment_floor']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Район */
  $handler->display->display_options['fields']['field_area']['id'] = 'field_area';
  $handler->display->display_options['fields']['field_area']['table'] = 'field_data_field_area';
  $handler->display->display_options['fields']['field_area']['field'] = 'field_area';
  $handler->display->display_options['fields']['field_area']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['fields']['field_area']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Цена за кв.м */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Taxonomy term: Количество этажей */
  $handler->display->display_options['fields']['field_number_floor']['id'] = 'field_number_floor';
  $handler->display->display_options['fields']['field_number_floor']['table'] = 'field_data_field_number_floor';
  $handler->display->display_options['fields']['field_number_floor']['field'] = 'field_number_floor';
  $handler->display->display_options['fields']['field_number_floor']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['fields']['field_number_floor']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Статус */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  /* Field: Taxonomy term: Материал стен */
  $handler->display->display_options['fields']['field_material']['id'] = 'field_material';
  $handler->display->display_options['fields']['field_material']['table'] = 'field_data_field_material';
  $handler->display->display_options['fields']['field_material']['field'] = 'field_material';
  $handler->display->display_options['fields']['field_material']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'reverse_field_apartment_comparison_user';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['apartments'] = array(
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
    t('term from field_apartament_home'),
    t('Content entity referenced from field_home_complex'),
    t('term from field_complex_developer'),
    t('User referencing Content from field_apartment_comparison'),
    t('Главное изображение'),
    t('Все'),
    t('Дом (field_apartament_home)'),
    t('Количество комнат (field_number_rooms)'),
    t('Квартиры жилого комплекса'),
    t('more'),
    t('номер квартиры'),
    t('Адрес'),
    t('Секция'),
    t('Количество комнат'),
    t('Общая площадь'),
    t('Цена за кв.м'),
    t('Стоимость'),
    t('Статус'),
    t('Количество этажей'),
    t('Балкон'),
    t('Лоджия'),
    t('Этаж (field_apartment_floor)'),
    t('Общая площадь (field_gross_area)'),
    t('Цена за кв.м (field_price)'),
    t('Стоимость (field_full_cost)'),
    t('Случайно'),
    t('Секция (field_section)'),
    t('Статус (field_status)'),
    t('номер квартиры (field_number_apartament)'),
    t('Представления-Фрагменты'),
    t('Квартира'),
    t('Дом'),
    t('Район'),
    t('Жилой комплекс'),
    t('Застройщик'),
    t('Планировка квартиры'),
    t('Документы'),
    t('Этаж'),
    t('Жилая площадь'),
    t('Квартиры на этаже'),
    t('Предложения на этаже'),
    t('Квартиры в доме'),
    t('Предложения в этом доме'),
    t('Результаты поиска'),
    t('field collection item from field_home_deadline'),
    t('Квартал'),
    t('Год'),
    t('Балкон и лоджия'),
    t('Высота потолка'),
    t('Срок сдачи (field_deadline)'),
    t('Застройщик (field_complex_developer)'),
    t('Жилой комплекс (field_home_complex)'),
    t('Высота потолка (field_apartment_ceiling_height)'),
    t('Район (field_area)'),
    t('Метро (field_complex_metro)'),
    t('Город (field_city)'),
    t('Квартал (field_home_deadline_quarter)'),
    t('Год (field_home_deadline_year)'),
    t('парковка (field_parking)'),
    t('Материал стен (field_material)'),
    t('Категория (field_home_category)'),
    t('Лоджия (field_loggia)'),
    t('Балкон (field_balcony)'),
    t('Балкон и лоджия (field_balcony_loggia)'),
    t('Полученные пользователем'),
    t('User referencing Content from field_received_id'),
    t('id квартиры'),
    t('Квартиры жилого комплекса для плана жк'),
    t('Квартиры застройщика'),
    t('Title'),
    t('Забронированные'),
    t('User entity referenced from field_booking_user'),
    t('Content entity referenced from field_booking_apartment'),
    t('Номер брони'),
    t('Сравнение'),
    t('Name'),
    t('Срок сдачи'),
    t('парковка'),
    t('Материал стен'),
  );
  $export['apartments'] = $view;

  return $export;
}
