<?php
/**
 * @file
 * realty_feature_term_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function realty_feature_term_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'term_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Термины';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Жилые комплексы';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Филиалы (field_bank_affiliates) */
  $handler->display->display_options['relationships']['field_bank_affiliates_value']['id'] = 'field_bank_affiliates_value';
  $handler->display->display_options['relationships']['field_bank_affiliates_value']['table'] = 'field_data_field_bank_affiliates';
  $handler->display->display_options['relationships']['field_bank_affiliates_value']['field'] = 'field_bank_affiliates_value';
  $handler->display->display_options['relationships']['field_bank_affiliates_value']['delta'] = '-1';
  /* Relationship: Taxonomy term: Ипотечные программы (field_bank_mortgage_program) */
  $handler->display->display_options['relationships']['field_bank_mortgage_program_value']['id'] = 'field_bank_mortgage_program_value';
  $handler->display->display_options['relationships']['field_bank_mortgage_program_value']['table'] = 'field_data_field_bank_mortgage_program';
  $handler->display->display_options['relationships']['field_bank_mortgage_program_value']['field'] = 'field_bank_mortgage_program_value';
  $handler->display->display_options['relationships']['field_bank_mortgage_program_value']['delta'] = '-1';
  /* Relationship: Taxonomy term: Taxonomy term using Банки */
  $handler->display->display_options['relationships']['reverse_field_banks_taxonomy_term']['id'] = 'reverse_field_banks_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_banks_taxonomy_term']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_banks_taxonomy_term']['field'] = 'reverse_field_banks_taxonomy_term';
  /* Field: Taxonomy term: Логотип */
  $handler->display->display_options['fields']['field_developer_logo']['id'] = 'field_developer_logo';
  $handler->display->display_options['fields']['field_developer_logo']['table'] = 'field_data_field_developer_logo';
  $handler->display->display_options['fields']['field_developer_logo']['field'] = 'field_developer_logo';
  $handler->display->display_options['fields']['field_developer_logo']['label'] = '';
  $handler->display->display_options['fields']['field_developer_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_developer_logo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_developer_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_developer_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Taxonomy term: Филиалы (field_bank_affiliates) */
  $handler->display->display_options['arguments']['field_bank_affiliates_value']['id'] = 'field_bank_affiliates_value';
  $handler->display->display_options['arguments']['field_bank_affiliates_value']['table'] = 'field_data_field_bank_affiliates';
  $handler->display->display_options['arguments']['field_bank_affiliates_value']['field'] = 'field_bank_affiliates_value';
  $handler->display->display_options['arguments']['field_bank_affiliates_value']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_bank_affiliates_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_bank_affiliates_value']['summary']['format'] = 'default_summary';
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    20 => '20',
  );
  $handler->display->display_options['filters']['vid']['expose']['operator_id'] = 'vid_op';
  $handler->display->display_options['filters']['vid']['expose']['label'] = 'Словарь';
  $handler->display->display_options['filters']['vid']['expose']['operator'] = 'vid_op';
  $handler->display->display_options['filters']['vid']['expose']['identifier'] = 'vid';

  /* Display: Застройщик */
  $handler = $view->new_display('panel_pane', 'Застройщик', 'developer');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: Taxonomy term: Адрес Застройщика */
  $handler->display->display_options['fields']['field_address_developer']['id'] = 'field_address_developer';
  $handler->display->display_options['fields']['field_address_developer']['table'] = 'field_data_field_address_developer';
  $handler->display->display_options['fields']['field_address_developer']['field'] = 'field_address_developer';
  /* Field: Taxonomy term: Логотип */
  $handler->display->display_options['fields']['field_developer_logo']['id'] = 'field_developer_logo';
  $handler->display->display_options['fields']['field_developer_logo']['table'] = 'field_data_field_developer_logo';
  $handler->display->display_options['fields']['field_developer_logo']['field'] = 'field_developer_logo';
  $handler->display->display_options['fields']['field_developer_logo']['label'] = '';
  $handler->display->display_options['fields']['field_developer_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_developer_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_developer_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Описание ';
  /* Field: Taxonomy term: веб сайт */
  $handler->display->display_options['fields']['field_web_site']['id'] = 'field_web_site';
  $handler->display->display_options['fields']['field_web_site']['table'] = 'field_data_field_web_site';
  $handler->display->display_options['fields']['field_web_site']['field'] = 'field_web_site';
  $handler->display->display_options['fields']['field_web_site']['alter']['make_link'] = TRUE;
  /* Field: Taxonomy term: Номер телефона */
  $handler->display->display_options['fields']['field_number_phone']['id'] = 'field_number_phone';
  $handler->display->display_options['fields']['field_number_phone']['table'] = 'field_data_field_number_phone';
  $handler->display->display_options['fields']['field_number_phone']['field'] = 'field_number_phone';
  /* Field: Taxonomy term: Эл.почта */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  /* Field: Taxonomy term: Мини логотип */
  $handler->display->display_options['fields']['field_developer_mini_logo']['id'] = 'field_developer_mini_logo';
  $handler->display->display_options['fields']['field_developer_mini_logo']['table'] = 'field_data_field_developer_mini_logo';
  $handler->display->display_options['fields']['field_developer_mini_logo']['field'] = 'field_developer_mini_logo';
  $handler->display->display_options['fields']['field_developer_mini_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_developer_mini_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    3 => '3',
  );
  /* Filter criterion: Taxonomy term: Публикация (field_developer_public) */
  $handler->display->display_options['filters']['field_developer_public_value']['id'] = 'field_developer_public_value';
  $handler->display->display_options['filters']['field_developer_public_value']['table'] = 'field_data_field_developer_public';
  $handler->display->display_options['filters']['field_developer_public_value']['field'] = 'field_developer_public_value';
  $handler->display->display_options['filters']['field_developer_public_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Застройщики */
  $handler = $view->new_display('panel_pane', 'Застройщики', 'developers');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Город (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Логотип */
  $handler->display->display_options['fields']['field_developer_logo']['id'] = 'field_developer_logo';
  $handler->display->display_options['fields']['field_developer_logo']['table'] = 'field_data_field_developer_logo';
  $handler->display->display_options['fields']['field_developer_logo']['field'] = 'field_developer_logo';
  $handler->display->display_options['fields']['field_developer_logo']['label'] = '';
  $handler->display->display_options['fields']['field_developer_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_developer_logo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_developer_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_developer_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
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
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    3 => '3',
  );
  /* Filter criterion: Taxonomy term: Публикация (field_developer_public) */
  $handler->display->display_options['filters']['field_developer_public_value']['id'] = 'field_developer_public_value';
  $handler->display->display_options['filters']['field_developer_public_value']['table'] = 'field_data_field_developer_public';
  $handler->display->display_options['filters']['field_developer_public_value']['field'] = 'field_developer_public_value';
  $handler->display->display_options['filters']['field_developer_public_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Застройщики поиск */
  $handler = $view->new_display('panel_pane', 'Застройщики поиск', 'developers_search');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Застройщики';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Город (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_city_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['argument'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    3 => '3',
  );
  /* Filter criterion: Taxonomy term: Публикация (field_developer_public) */
  $handler->display->display_options['filters']['field_developer_public_value']['id'] = 'field_developer_public_value';
  $handler->display->display_options['filters']['field_developer_public_value']['table'] = 'field_data_field_developer_public';
  $handler->display->display_options['filters']['field_developer_public_value']['field'] = 'field_developer_public_value';
  $handler->display->display_options['filters']['field_developer_public_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Дома ЖК */
  $handler = $view->new_display('panel_pane', 'Дома ЖК', 'homes_complex');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Дома жк';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['required'] = TRUE;
  /* Relationship: Taxonomy term: Секции (field_home_section) */
  $handler->display->display_options['relationships']['field_home_section_value']['id'] = 'field_home_section_value';
  $handler->display->display_options['relationships']['field_home_section_value']['table'] = 'field_data_field_home_section';
  $handler->display->display_options['relationships']['field_home_section_value']['field'] = 'field_home_section_value';
  $handler->display->display_options['relationships']['field_home_section_value']['delta'] = '-1';
  /* Relationship: Taxonomy term: План этажей (field_plan_floor) */
  $handler->display->display_options['relationships']['field_plan_floor_value']['id'] = 'field_plan_floor_value';
  $handler->display->display_options['relationships']['field_plan_floor_value']['table'] = 'field_data_field_plan_floor';
  $handler->display->display_options['relationships']['field_plan_floor_value']['field'] = 'field_plan_floor_value';
  $handler->display->display_options['relationships']['field_plan_floor_value']['delta'] = '-1';
  /* Relationship: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['label'] = 'термин из field_complex_developer';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Адрес дома */
  $handler->display->display_options['fields']['field_address_house']['id'] = 'field_address_house';
  $handler->display->display_options['fields']['field_address_house']['table'] = 'field_data_field_address_house';
  $handler->display->display_options['fields']['field_address_house']['field'] = 'field_address_house';
  $handler->display->display_options['fields']['field_address_house']['label'] = '';
  $handler->display->display_options['fields']['field_address_house']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Номер секции */
  $handler->display->display_options['fields']['field_number_section']['id'] = 'field_number_section';
  $handler->display->display_options['fields']['field_number_section']['table'] = 'field_data_field_number_section';
  $handler->display->display_options['fields']['field_number_section']['field'] = 'field_number_section';
  $handler->display->display_options['fields']['field_number_section']['relationship'] = 'field_home_section_value';
  $handler->display->display_options['fields']['field_number_section']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_number_section']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Field collection item: Секция */
  $handler->display->display_options['fields']['field_plan_number_section']['id'] = 'field_plan_number_section';
  $handler->display->display_options['fields']['field_plan_number_section']['table'] = 'field_data_field_plan_number_section';
  $handler->display->display_options['fields']['field_plan_number_section']['field'] = 'field_plan_number_section';
  $handler->display->display_options['fields']['field_plan_number_section']['relationship'] = 'field_plan_floor_value';
  $handler->display->display_options['fields']['field_plan_number_section']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_plan_number_section']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  /* Field: Field collection item: Этаж */
  $handler->display->display_options['fields']['field_plan_number_floor']['id'] = 'field_plan_number_floor';
  $handler->display->display_options['fields']['field_plan_number_floor']['table'] = 'field_data_field_plan_number_floor';
  $handler->display->display_options['fields']['field_plan_number_floor']['field'] = 'field_plan_number_floor';
  $handler->display->display_options['fields']['field_plan_number_floor']['relationship'] = 'field_plan_floor_value';
  $handler->display->display_options['fields']['field_plan_number_floor']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Taxonomy term: Расположение на плане жк */
  $handler->display->display_options['fields']['field_lage_plan_complex']['id'] = 'field_lage_plan_complex';
  $handler->display->display_options['fields']['field_lage_plan_complex']['table'] = 'field_data_field_lage_plan_complex';
  $handler->display->display_options['fields']['field_lage_plan_complex']['field'] = 'field_lage_plan_complex';
  /* Field: Field collection item: План этажей */
  $handler->display->display_options['fields']['field_image_plan_floor']['id'] = 'field_image_plan_floor';
  $handler->display->display_options['fields']['field_image_plan_floor']['table'] = 'field_data_field_image_plan_floor';
  $handler->display->display_options['fields']['field_image_plan_floor']['field'] = 'field_image_plan_floor';
  $handler->display->display_options['fields']['field_image_plan_floor']['relationship'] = 'field_plan_floor_value';
  $handler->display->display_options['fields']['field_image_plan_floor']['label'] = 'Изображение плана';
  $handler->display->display_options['fields']['field_image_plan_floor']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_plan_floor']['type'] = 'image';
  $handler->display->display_options['fields']['field_image_plan_floor']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Номер дома в ЖК */
  $handler->display->display_options['fields']['field_number_home']['id'] = 'field_number_home';
  $handler->display->display_options['fields']['field_number_home']['table'] = 'field_data_field_number_home';
  $handler->display->display_options['fields']['field_number_home']['field'] = 'field_number_home';
  $handler->display->display_options['fields']['field_number_home']['label'] = 'Номер дома';
  /* Field: Taxonomy term: Расположение на плане жк */
  $handler->display->display_options['fields']['field_lage_plan_complex_1']['id'] = 'field_lage_plan_complex_1';
  $handler->display->display_options['fields']['field_lage_plan_complex_1']['table'] = 'field_data_field_lage_plan_complex';
  $handler->display->display_options['fields']['field_lage_plan_complex_1']['field'] = 'field_lage_plan_complex';
  /* Field: Taxonomy term: План дома */
  $handler->display->display_options['fields']['field_home_plan']['id'] = 'field_home_plan';
  $handler->display->display_options['fields']['field_home_plan']['table'] = 'field_data_field_home_plan';
  $handler->display->display_options['fields']['field_home_plan']['field'] = 'field_home_plan';
  $handler->display->display_options['fields']['field_home_plan']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_home_plan']['type'] = 'image';
  $handler->display->display_options['fields']['field_home_plan']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Field collection item: Расположение на плане дома */
  $handler->display->display_options['fields']['field_lage_plan_home']['id'] = 'field_lage_plan_home';
  $handler->display->display_options['fields']['field_lage_plan_home']['table'] = 'field_data_field_lage_plan_home';
  $handler->display->display_options['fields']['field_lage_plan_home']['field'] = 'field_lage_plan_home';
  $handler->display->display_options['fields']['field_lage_plan_home']['relationship'] = 'field_home_section_value';
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  /* Field: Field collection item: Квартиры */
  $handler->display->display_options['fields']['field_apartments']['id'] = 'field_apartments';
  $handler->display->display_options['fields']['field_apartments']['table'] = 'field_data_field_apartments';
  $handler->display->display_options['fields']['field_apartments']['field'] = 'field_apartments';
  $handler->display->display_options['fields']['field_apartments']['relationship'] = 'field_plan_floor_value';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Taxonomy term: Секции (field_home_section) */
  $handler->display->display_options['arguments']['field_home_section_value']['id'] = 'field_home_section_value';
  $handler->display->display_options['arguments']['field_home_section_value']['table'] = 'field_data_field_home_section';
  $handler->display->display_options['arguments']['field_home_section_value']['field'] = 'field_home_section_value';
  $handler->display->display_options['arguments']['field_home_section_value']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_home_section_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_home_section_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    6 => '6',
  );
  /* Filter criterion: Taxonomy term: Публикация (field_developer_public) */
  $handler->display->display_options['filters']['field_developer_public_value']['id'] = 'field_developer_public_value';
  $handler->display->display_options['filters']['field_developer_public_value']['table'] = 'field_data_field_developer_public';
  $handler->display->display_options['filters']['field_developer_public_value']['field'] = 'field_developer_public_value';
  $handler->display->display_options['filters']['field_developer_public_value']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_developer_public_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Дома Застройщика */
  $handler = $view->new_display('panel_pane', 'Дома Застройщика', 'homes_developer');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Дома жк';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['required'] = TRUE;
  /* Relationship: Taxonomy term: Секции (field_home_section) */
  $handler->display->display_options['relationships']['field_home_section_value']['id'] = 'field_home_section_value';
  $handler->display->display_options['relationships']['field_home_section_value']['table'] = 'field_data_field_home_section';
  $handler->display->display_options['relationships']['field_home_section_value']['field'] = 'field_home_section_value';
  $handler->display->display_options['relationships']['field_home_section_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_home_section_value']['delta'] = '-1';
  /* Relationship: Taxonomy term: План этажей (field_plan_floor) */
  $handler->display->display_options['relationships']['field_plan_floor_value']['id'] = 'field_plan_floor_value';
  $handler->display->display_options['relationships']['field_plan_floor_value']['table'] = 'field_data_field_plan_floor';
  $handler->display->display_options['relationships']['field_plan_floor_value']['field'] = 'field_plan_floor_value';
  $handler->display->display_options['relationships']['field_plan_floor_value']['delta'] = '-1';
  /* Relationship: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Адрес дома */
  $handler->display->display_options['fields']['field_address_house']['id'] = 'field_address_house';
  $handler->display->display_options['fields']['field_address_house']['table'] = 'field_data_field_address_house';
  $handler->display->display_options['fields']['field_address_house']['field'] = 'field_address_house';
  $handler->display->display_options['fields']['field_address_house']['label'] = '';
  $handler->display->display_options['fields']['field_address_house']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Номер секции */
  $handler->display->display_options['fields']['field_number_section']['id'] = 'field_number_section';
  $handler->display->display_options['fields']['field_number_section']['table'] = 'field_data_field_number_section';
  $handler->display->display_options['fields']['field_number_section']['field'] = 'field_number_section';
  $handler->display->display_options['fields']['field_number_section']['relationship'] = 'field_home_section_value';
  $handler->display->display_options['fields']['field_number_section']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_number_section']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Taxonomy term: Расположение на плане жк */
  $handler->display->display_options['fields']['field_lage_plan_complex']['id'] = 'field_lage_plan_complex';
  $handler->display->display_options['fields']['field_lage_plan_complex']['table'] = 'field_data_field_lage_plan_complex';
  $handler->display->display_options['fields']['field_lage_plan_complex']['field'] = 'field_lage_plan_complex';
  $handler->display->display_options['fields']['field_lage_plan_complex']['type'] = 'text_plain';
  /* Field: Field collection item: Номер секции */
  $handler->display->display_options['fields']['field_number_section_1']['id'] = 'field_number_section_1';
  $handler->display->display_options['fields']['field_number_section_1']['table'] = 'field_data_field_number_section';
  $handler->display->display_options['fields']['field_number_section_1']['field'] = 'field_number_section';
  $handler->display->display_options['fields']['field_number_section_1']['relationship'] = 'field_plan_floor_value';
  $handler->display->display_options['fields']['field_number_section_1']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_number_section_1']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Этаж */
  $handler->display->display_options['fields']['field_plan_number_floor']['id'] = 'field_plan_number_floor';
  $handler->display->display_options['fields']['field_plan_number_floor']['table'] = 'field_data_field_plan_number_floor';
  $handler->display->display_options['fields']['field_plan_number_floor']['field'] = 'field_plan_number_floor';
  $handler->display->display_options['fields']['field_plan_number_floor']['relationship'] = 'field_plan_floor_value';
  $handler->display->display_options['fields']['field_plan_number_floor']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_plan_number_floor']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: План этажей */
  $handler->display->display_options['fields']['field_image_plan_floor']['id'] = 'field_image_plan_floor';
  $handler->display->display_options['fields']['field_image_plan_floor']['table'] = 'field_data_field_image_plan_floor';
  $handler->display->display_options['fields']['field_image_plan_floor']['field'] = 'field_image_plan_floor';
  $handler->display->display_options['fields']['field_image_plan_floor']['relationship'] = 'field_plan_floor_value';
  $handler->display->display_options['fields']['field_image_plan_floor']['label'] = 'Изображение плана';
  $handler->display->display_options['fields']['field_image_plan_floor']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_plan_floor']['type'] = 'image';
  $handler->display->display_options['fields']['field_image_plan_floor']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Номер дома в ЖК */
  $handler->display->display_options['fields']['field_number_home']['id'] = 'field_number_home';
  $handler->display->display_options['fields']['field_number_home']['table'] = 'field_data_field_number_home';
  $handler->display->display_options['fields']['field_number_home']['field'] = 'field_number_home';
  $handler->display->display_options['fields']['field_number_home']['label'] = 'Номер дома';
  $handler->display->display_options['fields']['field_number_home']['type'] = 'text_plain';
  /* Field: Taxonomy term: Расположение на плане жк */
  $handler->display->display_options['fields']['field_lage_plan_complex_1']['id'] = 'field_lage_plan_complex_1';
  $handler->display->display_options['fields']['field_lage_plan_complex_1']['table'] = 'field_data_field_lage_plan_complex';
  $handler->display->display_options['fields']['field_lage_plan_complex_1']['field'] = 'field_lage_plan_complex';
  $handler->display->display_options['fields']['field_lage_plan_complex_1']['type'] = 'text_plain';
  /* Field: Taxonomy term: План дома */
  $handler->display->display_options['fields']['field_home_plan']['id'] = 'field_home_plan';
  $handler->display->display_options['fields']['field_home_plan']['table'] = 'field_data_field_home_plan';
  $handler->display->display_options['fields']['field_home_plan']['field'] = 'field_home_plan';
  $handler->display->display_options['fields']['field_home_plan']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_home_plan']['type'] = 'image';
  $handler->display->display_options['fields']['field_home_plan']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Field collection item: Расположение на плане дома */
  $handler->display->display_options['fields']['field_lage_plan_home']['id'] = 'field_lage_plan_home';
  $handler->display->display_options['fields']['field_lage_plan_home']['table'] = 'field_data_field_lage_plan_home';
  $handler->display->display_options['fields']['field_lage_plan_home']['field'] = 'field_lage_plan_home';
  $handler->display->display_options['fields']['field_lage_plan_home']['relationship'] = 'field_home_section_value';
  $handler->display->display_options['fields']['field_lage_plan_home']['type'] = 'text_plain';
  /* Field: Field collection item: Секция */
  $handler->display->display_options['fields']['field_plan_number_section']['id'] = 'field_plan_number_section';
  $handler->display->display_options['fields']['field_plan_number_section']['table'] = 'field_data_field_plan_number_section';
  $handler->display->display_options['fields']['field_plan_number_section']['field'] = 'field_plan_number_section';
  $handler->display->display_options['fields']['field_plan_number_section']['relationship'] = 'field_plan_floor_value';
  $handler->display->display_options['fields']['field_plan_number_section']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_plan_number_section']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  /* Field: Field collection item: Квартиры */
  $handler->display->display_options['fields']['field_apartments']['id'] = 'field_apartments';
  $handler->display->display_options['fields']['field_apartments']['table'] = 'field_data_field_apartments';
  $handler->display->display_options['fields']['field_apartments']['field'] = 'field_apartments';
  $handler->display->display_options['fields']['field_apartments']['relationship'] = 'field_plan_floor_value';
  $handler->display->display_options['fields']['field_apartments']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
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
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    6 => '6',
  );
  /* Filter criterion: Taxonomy term: Публикация (field_developer_public) */
  $handler->display->display_options['filters']['field_developer_public_value']['id'] = 'field_developer_public_value';
  $handler->display->display_options['filters']['field_developer_public_value']['table'] = 'field_data_field_developer_public';
  $handler->display->display_options['filters']['field_developer_public_value']['field'] = 'field_developer_public_value';
  $handler->display->display_options['filters']['field_developer_public_value']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_developer_public_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Галерея Застройщика */
  $handler = $view->new_display('panel_pane', 'Галерея Застройщика', 'developer_gallery');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Галерея (field_developer_gallery) */
  $handler->display->display_options['relationships']['field_developer_gallery_value']['id'] = 'field_developer_gallery_value';
  $handler->display->display_options['relationships']['field_developer_gallery_value']['table'] = 'field_data_field_developer_gallery';
  $handler->display->display_options['relationships']['field_developer_gallery_value']['field'] = 'field_developer_gallery_value';
  $handler->display->display_options['relationships']['field_developer_gallery_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Изображение */
  $handler->display->display_options['fields']['field_developer_gallery_image']['id'] = 'field_developer_gallery_image';
  $handler->display->display_options['fields']['field_developer_gallery_image']['table'] = 'field_data_field_developer_gallery_image';
  $handler->display->display_options['fields']['field_developer_gallery_image']['field'] = 'field_developer_gallery_image';
  $handler->display->display_options['fields']['field_developer_gallery_image']['relationship'] = 'field_developer_gallery_value';
  /* Field: Field collection item: Название */
  $handler->display->display_options['fields']['field_developer_gallery_title']['id'] = 'field_developer_gallery_title';
  $handler->display->display_options['fields']['field_developer_gallery_title']['table'] = 'field_data_field_developer_gallery_title';
  $handler->display->display_options['fields']['field_developer_gallery_title']['field'] = 'field_developer_gallery_title';
  $handler->display->display_options['fields']['field_developer_gallery_title']['relationship'] = 'field_developer_gallery_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Партнеры для главной */
  $handler = $view->new_display('panel_pane', 'Партнеры для главной', 'partners');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Логотип */
  $handler->display->display_options['fields']['field_partners_logo']['id'] = 'field_partners_logo';
  $handler->display->display_options['fields']['field_partners_logo']['table'] = 'field_data_field_partners_logo';
  $handler->display->display_options['fields']['field_partners_logo']['field'] = 'field_partners_logo';
  $handler->display->display_options['fields']['field_partners_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_partners_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    10 => '10',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Все партнеры */
  $handler = $view->new_display('panel_pane', 'Все партнеры', 'all_partners');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Логотип */
  $handler->display->display_options['fields']['field_partners_logo']['id'] = 'field_partners_logo';
  $handler->display->display_options['fields']['field_partners_logo']['table'] = 'field_data_field_partners_logo';
  $handler->display->display_options['fields']['field_partners_logo']['field'] = 'field_partners_logo';
  $handler->display->display_options['fields']['field_partners_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_partners_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    10 => '10',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Партнер */
  $handler = $view->new_display('panel_pane', 'Партнер', 'partner');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  /* Field: Taxonomy term: Логотип */
  $handler->display->display_options['fields']['field_partners_logo']['id'] = 'field_partners_logo';
  $handler->display->display_options['fields']['field_partners_logo']['table'] = 'field_data_field_partners_logo';
  $handler->display->display_options['fields']['field_partners_logo']['field'] = 'field_partners_logo';
  $handler->display->display_options['fields']['field_partners_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_partners_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Менеджеры застройщика */
  $handler = $view->new_display('panel_pane', 'Менеджеры застройщика', 'managers_developer');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Менеджер (field_manager) */
  $handler->display->display_options['relationships']['field_manager_value']['id'] = 'field_manager_value';
  $handler->display->display_options['relationships']['field_manager_value']['table'] = 'field_data_field_manager';
  $handler->display->display_options['relationships']['field_manager_value']['field'] = 'field_manager_value';
  $handler->display->display_options['relationships']['field_manager_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: e-mail */
  $handler->display->display_options['fields']['field_manager_e_mail']['id'] = 'field_manager_e_mail';
  $handler->display->display_options['fields']['field_manager_e_mail']['table'] = 'field_data_field_manager_e_mail';
  $handler->display->display_options['fields']['field_manager_e_mail']['field'] = 'field_manager_e_mail';
  $handler->display->display_options['fields']['field_manager_e_mail']['relationship'] = 'field_manager_value';
  /* Field: Field collection item: Номер телефона */
  $handler->display->display_options['fields']['field_manager_number_phone']['id'] = 'field_manager_number_phone';
  $handler->display->display_options['fields']['field_manager_number_phone']['table'] = 'field_data_field_manager_number_phone';
  $handler->display->display_options['fields']['field_manager_number_phone']['field'] = 'field_manager_number_phone';
  $handler->display->display_options['fields']['field_manager_number_phone']['relationship'] = 'field_manager_value';
  /* Field: Field collection item: Ф.И.О */
  $handler->display->display_options['fields']['field_manager_name']['id'] = 'field_manager_name';
  $handler->display->display_options['fields']['field_manager_name']['table'] = 'field_data_field_manager_name';
  $handler->display->display_options['fields']['field_manager_name']['field'] = 'field_manager_name';
  $handler->display->display_options['fields']['field_manager_name']['relationship'] = 'field_manager_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Дом для плана жк */
  $handler = $view->new_display('panel_pane', 'Дом для плана жк', 'home_plan_complex');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Дома жк';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Секции (field_home_section) */
  $handler->display->display_options['relationships']['field_home_section_value']['id'] = 'field_home_section_value';
  $handler->display->display_options['relationships']['field_home_section_value']['table'] = 'field_data_field_home_section';
  $handler->display->display_options['relationships']['field_home_section_value']['field'] = 'field_home_section_value';
  $handler->display->display_options['relationships']['field_home_section_value']['delta'] = '-1';
  /* Relationship: Taxonomy term: План этажей (field_plan_floor) */
  $handler->display->display_options['relationships']['field_plan_floor_value']['id'] = 'field_plan_floor_value';
  $handler->display->display_options['relationships']['field_plan_floor_value']['table'] = 'field_data_field_plan_floor';
  $handler->display->display_options['relationships']['field_plan_floor_value']['field'] = 'field_plan_floor_value';
  $handler->display->display_options['relationships']['field_plan_floor_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Адрес дома */
  $handler->display->display_options['fields']['field_address_house']['id'] = 'field_address_house';
  $handler->display->display_options['fields']['field_address_house']['table'] = 'field_data_field_address_house';
  $handler->display->display_options['fields']['field_address_house']['field'] = 'field_address_house';
  $handler->display->display_options['fields']['field_address_house']['label'] = '';
  $handler->display->display_options['fields']['field_address_house']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Номер секции */
  $handler->display->display_options['fields']['field_number_section']['id'] = 'field_number_section';
  $handler->display->display_options['fields']['field_number_section']['table'] = 'field_data_field_number_section';
  $handler->display->display_options['fields']['field_number_section']['field'] = 'field_number_section';
  $handler->display->display_options['fields']['field_number_section']['relationship'] = 'field_home_section_value';
  $handler->display->display_options['fields']['field_number_section']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_number_section']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Field collection item: Секция */
  $handler->display->display_options['fields']['field_plan_number_section']['id'] = 'field_plan_number_section';
  $handler->display->display_options['fields']['field_plan_number_section']['table'] = 'field_data_field_plan_number_section';
  $handler->display->display_options['fields']['field_plan_number_section']['field'] = 'field_plan_number_section';
  $handler->display->display_options['fields']['field_plan_number_section']['relationship'] = 'field_plan_floor_value';
  $handler->display->display_options['fields']['field_plan_number_section']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_plan_number_section']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 0,
  );
  /* Field: Field collection item: Этаж */
  $handler->display->display_options['fields']['field_plan_number_floor']['id'] = 'field_plan_number_floor';
  $handler->display->display_options['fields']['field_plan_number_floor']['table'] = 'field_data_field_plan_number_floor';
  $handler->display->display_options['fields']['field_plan_number_floor']['field'] = 'field_plan_number_floor';
  $handler->display->display_options['fields']['field_plan_number_floor']['relationship'] = 'field_plan_floor_value';
  $handler->display->display_options['fields']['field_plan_number_floor']['type'] = 'number_integer';
  $handler->display->display_options['fields']['field_plan_number_floor']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Taxonomy term: Расположение на плане жк */
  $handler->display->display_options['fields']['field_lage_plan_complex']['id'] = 'field_lage_plan_complex';
  $handler->display->display_options['fields']['field_lage_plan_complex']['table'] = 'field_data_field_lage_plan_complex';
  $handler->display->display_options['fields']['field_lage_plan_complex']['field'] = 'field_lage_plan_complex';
  /* Field: Field collection item: План этажей */
  $handler->display->display_options['fields']['field_image_plan_floor']['id'] = 'field_image_plan_floor';
  $handler->display->display_options['fields']['field_image_plan_floor']['table'] = 'field_data_field_image_plan_floor';
  $handler->display->display_options['fields']['field_image_plan_floor']['field'] = 'field_image_plan_floor';
  $handler->display->display_options['fields']['field_image_plan_floor']['relationship'] = 'field_plan_floor_value';
  $handler->display->display_options['fields']['field_image_plan_floor']['label'] = 'Изображение плана';
  $handler->display->display_options['fields']['field_image_plan_floor']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_plan_floor']['type'] = 'image';
  $handler->display->display_options['fields']['field_image_plan_floor']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Номер дома в ЖК */
  $handler->display->display_options['fields']['field_number_home']['id'] = 'field_number_home';
  $handler->display->display_options['fields']['field_number_home']['table'] = 'field_data_field_number_home';
  $handler->display->display_options['fields']['field_number_home']['field'] = 'field_number_home';
  $handler->display->display_options['fields']['field_number_home']['label'] = 'Номер дома';
  /* Field: Taxonomy term: Расположение на плане жк */
  $handler->display->display_options['fields']['field_lage_plan_complex_1']['id'] = 'field_lage_plan_complex_1';
  $handler->display->display_options['fields']['field_lage_plan_complex_1']['table'] = 'field_data_field_lage_plan_complex';
  $handler->display->display_options['fields']['field_lage_plan_complex_1']['field'] = 'field_lage_plan_complex';
  /* Field: Taxonomy term: План дома */
  $handler->display->display_options['fields']['field_home_plan']['id'] = 'field_home_plan';
  $handler->display->display_options['fields']['field_home_plan']['table'] = 'field_data_field_home_plan';
  $handler->display->display_options['fields']['field_home_plan']['field'] = 'field_home_plan';
  $handler->display->display_options['fields']['field_home_plan']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_home_plan']['type'] = 'image';
  $handler->display->display_options['fields']['field_home_plan']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Field collection item: Расположение на плане дома */
  $handler->display->display_options['fields']['field_lage_plan_home']['id'] = 'field_lage_plan_home';
  $handler->display->display_options['fields']['field_lage_plan_home']['table'] = 'field_data_field_lage_plan_home';
  $handler->display->display_options['fields']['field_lage_plan_home']['field'] = 'field_lage_plan_home';
  $handler->display->display_options['fields']['field_lage_plan_home']['relationship'] = 'field_home_section_value';
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  /* Field: Field collection item: Квартиры */
  $handler->display->display_options['fields']['field_apartments']['id'] = 'field_apartments';
  $handler->display->display_options['fields']['field_apartments']['table'] = 'field_data_field_apartments';
  $handler->display->display_options['fields']['field_apartments']['field'] = 'field_apartments';
  $handler->display->display_options['fields']['field_apartments']['relationship'] = 'field_plan_floor_value';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    6 => '6',
  );
  /* Filter criterion: Field collection item: Секция (field_plan_number_section) */
  $handler->display->display_options['filters']['field_plan_number_section_value']['id'] = 'field_plan_number_section_value';
  $handler->display->display_options['filters']['field_plan_number_section_value']['table'] = 'field_data_field_plan_number_section';
  $handler->display->display_options['filters']['field_plan_number_section_value']['field'] = 'field_plan_number_section_value';
  $handler->display->display_options['filters']['field_plan_number_section_value']['relationship'] = 'field_plan_floor_value';
  $handler->display->display_options['filters']['field_plan_number_section_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_plan_number_section_value']['expose']['operator_id'] = 'field_plan_number_section_value_op';
  $handler->display->display_options['filters']['field_plan_number_section_value']['expose']['label'] = 'Секция (field_plan_number_section)';
  $handler->display->display_options['filters']['field_plan_number_section_value']['expose']['operator'] = 'field_plan_number_section_value_op';
  $handler->display->display_options['filters']['field_plan_number_section_value']['expose']['identifier'] = 'field_plan_number_section_value';
  $handler->display->display_options['filters']['field_plan_number_section_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Field collection item: Номер секции (field_number_section) */
  $handler->display->display_options['filters']['field_number_section_value']['id'] = 'field_number_section_value';
  $handler->display->display_options['filters']['field_number_section_value']['table'] = 'field_data_field_number_section';
  $handler->display->display_options['filters']['field_number_section_value']['field'] = 'field_number_section_value';
  $handler->display->display_options['filters']['field_number_section_value']['relationship'] = 'field_home_section_value';
  $handler->display->display_options['filters']['field_number_section_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_number_section_value']['expose']['operator_id'] = 'field_number_section_value_op';
  $handler->display->display_options['filters']['field_number_section_value']['expose']['label'] = 'Номер секции (field_number_section)';
  $handler->display->display_options['filters']['field_number_section_value']['expose']['operator'] = 'field_number_section_value_op';
  $handler->display->display_options['filters']['field_number_section_value']['expose']['identifier'] = 'field_number_section_value';
  $handler->display->display_options['filters']['field_number_section_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Список банков для ипотеки */
  $handler = $view->new_display('panel_pane', 'Список банков для ипотеки', 'bank_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Список банков';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Логотип */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'field_data_field_logo';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Ипотечные программы */
  $handler->display->display_options['fields']['field_bank_mortgage_program']['id'] = 'field_bank_mortgage_program';
  $handler->display->display_options['fields']['field_bank_mortgage_program']['table'] = 'field_data_field_bank_mortgage_program';
  $handler->display->display_options['fields']['field_bank_mortgage_program']['field'] = 'field_bank_mortgage_program';
  $handler->display->display_options['fields']['field_bank_mortgage_program']['settings'] = array(
    'edit' => 'Правка',
    'delete' => 'Удалить',
    'add' => 'Добавить',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_bank_mortgage_program']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  /* Contextual filter: Field collection item: Город (field_bank_mp_city) */
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['id'] = 'field_bank_mp_city_tid';
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['table'] = 'field_data_field_bank_mp_city';
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['field'] = 'field_bank_mp_city_tid';
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['relationship'] = 'field_bank_mortgage_program_value';
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id_1']['id'] = 'item_id_1';
  $handler->display->display_options['arguments']['item_id_1']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id_1']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id_1']['relationship'] = 'field_bank_mortgage_program_value';
  $handler->display->display_options['arguments']['item_id_1']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['item_id_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['item_id_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Список банков для главной */
  $handler = $view->new_display('panel_pane', 'Список банков для главной', 'mortgage_program');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Список банков';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Логотип */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'field_data_field_logo';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Город (field_bank_mp_city) */
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['id'] = 'field_bank_mp_city_tid';
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['table'] = 'field_data_field_bank_mp_city';
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['field'] = 'field_bank_mp_city_tid';
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['relationship'] = 'field_bank_mortgage_program_value';
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_bank_mp_city_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Филиалы банка */
  $handler = $view->new_display('panel_pane', 'Филиалы банка', 'bank_affiliate');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Логотип */
  $handler->display->display_options['fields']['field_developer_logo']['id'] = 'field_developer_logo';
  $handler->display->display_options['fields']['field_developer_logo']['table'] = 'field_data_field_developer_logo';
  $handler->display->display_options['fields']['field_developer_logo']['field'] = 'field_developer_logo';
  $handler->display->display_options['fields']['field_developer_logo']['label'] = '';
  $handler->display->display_options['fields']['field_developer_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_developer_logo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_developer_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_developer_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Field collection item: Название */
  $handler->display->display_options['fields']['field_bank_affiliates_name']['id'] = 'field_bank_affiliates_name';
  $handler->display->display_options['fields']['field_bank_affiliates_name']['table'] = 'field_data_field_bank_affiliates_name';
  $handler->display->display_options['fields']['field_bank_affiliates_name']['field'] = 'field_bank_affiliates_name';
  $handler->display->display_options['fields']['field_bank_affiliates_name']['relationship'] = 'field_bank_affiliates_value';
  /* Field: Field collection item: Адрес */
  $handler->display->display_options['fields']['field_bank_affiliates_address']['id'] = 'field_bank_affiliates_address';
  $handler->display->display_options['fields']['field_bank_affiliates_address']['table'] = 'field_data_field_bank_affiliates_address';
  $handler->display->display_options['fields']['field_bank_affiliates_address']['field'] = 'field_bank_affiliates_address';
  $handler->display->display_options['fields']['field_bank_affiliates_address']['relationship'] = 'field_bank_affiliates_value';
  /* Field: Field collection item: Электронная почта */
  $handler->display->display_options['fields']['field_bank_affiliates_email']['id'] = 'field_bank_affiliates_email';
  $handler->display->display_options['fields']['field_bank_affiliates_email']['table'] = 'field_data_field_bank_affiliates_email';
  $handler->display->display_options['fields']['field_bank_affiliates_email']['field'] = 'field_bank_affiliates_email';
  $handler->display->display_options['fields']['field_bank_affiliates_email']['relationship'] = 'field_bank_affiliates_value';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    20 => '20',
  );
  /* Filter criterion: Field collection item: Город (field_bank_affiliates_city) */
  $handler->display->display_options['filters']['field_bank_affiliates_city_tid']['id'] = 'field_bank_affiliates_city_tid';
  $handler->display->display_options['filters']['field_bank_affiliates_city_tid']['table'] = 'field_data_field_bank_affiliates_city';
  $handler->display->display_options['filters']['field_bank_affiliates_city_tid']['field'] = 'field_bank_affiliates_city_tid';
  $handler->display->display_options['filters']['field_bank_affiliates_city_tid']['relationship'] = 'field_bank_affiliates_value';
  $handler->display->display_options['filters']['field_bank_affiliates_city_tid']['value'] = '';
  $handler->display->display_options['filters']['field_bank_affiliates_city_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_bank_affiliates_city_tid']['expose']['operator_id'] = 'field_bank_affiliates_city_tid_op';
  $handler->display->display_options['filters']['field_bank_affiliates_city_tid']['expose']['label'] = 'Город (field_bank_affiliates_city)';
  $handler->display->display_options['filters']['field_bank_affiliates_city_tid']['expose']['operator'] = 'field_bank_affiliates_city_tid_op';
  $handler->display->display_options['filters']['field_bank_affiliates_city_tid']['expose']['identifier'] = 'field_bank_affiliates_city_tid';
  $handler->display->display_options['filters']['field_bank_affiliates_city_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_bank_affiliates_city_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_bank_affiliates_city_tid']['vocabulary'] = 'cities';
  /* Filter criterion: Taxonomy term: Term ID */
  $handler->display->display_options['filters']['tid_raw']['id'] = 'tid_raw';
  $handler->display->display_options['filters']['tid_raw']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid_raw']['field'] = 'tid_raw';
  $handler->display->display_options['filters']['tid_raw']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_raw']['expose']['operator_id'] = 'tid_raw_op';
  $handler->display->display_options['filters']['tid_raw']['expose']['label'] = 'ID термина';
  $handler->display->display_options['filters']['tid_raw']['expose']['operator'] = 'tid_raw_op';
  $handler->display->display_options['filters']['tid_raw']['expose']['identifier'] = 'tid_raw';
  $handler->display->display_options['filters']['tid_raw']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Галерея Застройщика - Видео */
  $handler = $view->new_display('panel_pane', 'Галерея Застройщика - Видео', 'developer_gallery_video');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Галерея (field_developer_gallery) */
  $handler->display->display_options['relationships']['field_developer_gallery_value']['id'] = 'field_developer_gallery_value';
  $handler->display->display_options['relationships']['field_developer_gallery_value']['table'] = 'field_data_field_developer_gallery';
  $handler->display->display_options['relationships']['field_developer_gallery_value']['field'] = 'field_developer_gallery_value';
  $handler->display->display_options['relationships']['field_developer_gallery_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Видео */
  $handler->display->display_options['fields']['field_developer_video']['id'] = 'field_developer_video';
  $handler->display->display_options['fields']['field_developer_video']['table'] = 'field_data_field_developer_video';
  $handler->display->display_options['fields']['field_developer_video']['field'] = 'field_developer_video';
  $handler->display->display_options['fields']['field_developer_video']['click_sort_column'] = 'input';
  $handler->display->display_options['fields']['field_developer_video']['settings'] = array(
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['term_view'] = array(
    t('Master'),
    t('Жилые комплексы'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('field collection item from field_bank_affiliates'),
    t('field collection item from field_bank_mortgage_program'),
    t('field_banks'),
    t('Все'),
    t('Словарь'),
    t('Застройщик'),
    t('more'),
    t('Name'),
    t('Адрес Застройщика'),
    t('Описание '),
    t('веб сайт'),
    t('Номер телефона'),
    t('Эл.почта'),
    t('Мини логотип'),
    t('Представления-Фрагменты'),
    t('Застройщики'),
    t('term from field_city'),
    t('Застройщики поиск'),
    t('Дома ЖК'),
    t('Дома жк'),
    t('Content entity referenced from field_home_complex'),
    t('field collection item from field_home_section'),
    t('field collection item from field_plan_floor'),
    t('термин из field_complex_developer'),
    t('.'),
    t(','),
    t('Номер секции'),
    t('Секция'),
    t('Этаж'),
    t('Расположение на плане жк'),
    t('Изображение плана'),
    t('Номер дома'),
    t('План дома'),
    t('Расположение на плане дома'),
    t('Term description'),
    t('Квартиры'),
    t('Дома Застройщика'),
    t('term from field_complex_developer'),
    t('Галерея Застройщика'),
    t('field collection item from field_developer_gallery'),
    t('Изображение'),
    t('Название'),
    t('Партнеры для главной'),
    t('Логотип'),
    t('Все партнеры'),
    t('Элементов на страницу'),
    t('- Все -'),
    t('Пропустить'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
    t('Партнер'),
    t('Менеджеры застройщика'),
    t('field collection item from field_manager'),
    t('e-mail'),
    t('Ф.И.О'),
    t('Дом для плана жк'),
    t('Секция (field_plan_number_section)'),
    t('Номер секции (field_number_section)'),
    t('Список банков для ипотеки'),
    t('Список банков'),
    t('Ипотечные программы'),
    t('Список банков для главной'),
    t('Филиалы банка'),
    t('Адрес'),
    t('Электронная почта'),
    t('Город (field_bank_affiliates_city)'),
    t('ID термина'),
    t('Галерея Застройщика - Видео'),
    t('Видео'),
  );
  $export['term_view'] = $view;

  return $export;
}
