<?php
/**
 * @file
 * realty_feature_view_field_collection.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function realty_feature_view_field_collection_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'field_collection';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Коллекции полей';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Связь: Field collection item: Entity with the Ипотечные программы (field_bank_mortgage_program) */
  $handler->display->display_options['relationships']['field_bank_mortgage_program_taxonomy_term']['id'] = 'field_bank_mortgage_program_taxonomy_term';
  $handler->display->display_options['relationships']['field_bank_mortgage_program_taxonomy_term']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_bank_mortgage_program_taxonomy_term']['field'] = 'field_bank_mortgage_program_taxonomy_term';
  $handler->display->display_options['relationships']['field_bank_mortgage_program_taxonomy_term']['required'] = TRUE;
  /* Поле: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_bank_mortgage_program_taxonomy_term';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Поле: Field collection item: Название */
  $handler->display->display_options['fields']['field_bank_mp_name']['id'] = 'field_bank_mp_name';
  $handler->display->display_options['fields']['field_bank_mp_name']['table'] = 'field_data_field_bank_mp_name';
  $handler->display->display_options['fields']['field_bank_mp_name']['field'] = 'field_bank_mp_name';
  $handler->display->display_options['fields']['field_bank_mp_name']['label'] = '';
  $handler->display->display_options['fields']['field_bank_mp_name']['element_label_colon'] = FALSE;
  /* Критерий фильтра: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['relationship'] = 'field_bank_mortgage_program_taxonomy_term';
  $handler->display->display_options['filters']['vid']['value'] = array(
    20 => '20',
  );

  /* Display: Список ипотечных программ */
  $handler = $view->new_display('entityreference', 'Список ипотечных программ', 'mortgage_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_bank_mp_name' => 'field_bank_mp_name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Список действующих ипотечных программ ЖК */
  $handler = $view->new_display('panel_pane', 'Список действующих ипотечных программ ЖК', 'current_mortgage');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Field collection item: Entity with the Ипотечные программы (field_bank_mortgage_program) */
  $handler->display->display_options['relationships']['field_bank_mortgage_program_taxonomy_term']['id'] = 'field_bank_mortgage_program_taxonomy_term';
  $handler->display->display_options['relationships']['field_bank_mortgage_program_taxonomy_term']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_bank_mortgage_program_taxonomy_term']['field'] = 'field_bank_mortgage_program_taxonomy_term';
  $handler->display->display_options['relationships']['field_bank_mortgage_program_taxonomy_term']['required'] = TRUE;
  /* Связь: Taxonomy term: Банки (field_banks) */
  $handler->display->display_options['relationships']['field_banks_tid']['id'] = 'field_banks_tid';
  $handler->display->display_options['relationships']['field_banks_tid']['table'] = 'field_data_field_banks';
  $handler->display->display_options['relationships']['field_banks_tid']['field'] = 'field_banks_tid';
  $handler->display->display_options['relationships']['field_banks_tid']['relationship'] = 'field_bank_mortgage_program_taxonomy_term';
  $handler->display->display_options['relationships']['field_banks_tid']['label'] = 'термин из field_banks';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Field collection item: Название */
  $handler->display->display_options['fields']['field_bank_mp_name']['id'] = 'field_bank_mp_name';
  $handler->display->display_options['fields']['field_bank_mp_name']['table'] = 'field_data_field_bank_mp_name';
  $handler->display->display_options['fields']['field_bank_mp_name']['field'] = 'field_bank_mp_name';
  $handler->display->display_options['fields']['field_bank_mp_name']['label'] = '';
  $handler->display->display_options['fields']['field_bank_mp_name']['element_label_colon'] = FALSE;
  /* Поле: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_bank_mortgage_program_taxonomy_term';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Поле: Field collection item: Категория */
  $handler->display->display_options['fields']['field_bank_mp_category']['id'] = 'field_bank_mp_category';
  $handler->display->display_options['fields']['field_bank_mp_category']['table'] = 'field_data_field_bank_mp_category';
  $handler->display->display_options['fields']['field_bank_mp_category']['field'] = 'field_bank_mp_category';
  /* Поле: Field collection item: Сводная информация */
  $handler->display->display_options['fields']['field_bank_mp_summary']['id'] = 'field_bank_mp_summary';
  $handler->display->display_options['fields']['field_bank_mp_summary']['table'] = 'field_data_field_bank_mp_summary';
  $handler->display->display_options['fields']['field_bank_mp_summary']['field'] = 'field_bank_mp_summary';
  $handler->display->display_options['fields']['field_bank_mp_summary']['settings'] = array(
    'edit' => 'Правка',
    'delete' => 'Удалить',
    'add' => 'Добавить',
    'description' => 1,
    'view_mode' => 'full',
  );
  /* Поле: Taxonomy term: Логотип */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'field_data_field_logo';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['relationship'] = 'field_bank_mortgage_program_taxonomy_term';
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['item_id']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $translatables['field_collection'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('field_bank_mortgage_program'),
    t('Список ипотечных программ'),
    t('Список действующих ипотечных программ ЖК'),
    t('термин из field_banks'),
    t('Категория'),
    t('Сводная информация'),
    t('Логотип'),
    t('Все'),
    t('View panes'),
  );
  $export['field_collection'] = $view;

  return $export;
}
