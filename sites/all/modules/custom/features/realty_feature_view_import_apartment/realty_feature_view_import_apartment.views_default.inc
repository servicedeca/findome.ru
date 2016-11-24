<?php
/**
 * @file
 * realty_feature_view_import_apartment.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function realty_feature_view_import_apartment_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'view_import_apartment';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Импорт квартиры';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Связь: Содержимое: Дом (field_apartament_home) */
  $handler->display->display_options['relationships']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Поле: Содержимое: Статус */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  /* Поле: Содержимое: Цена за кв.м */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Стоимость */
  $handler->display->display_options['fields']['field_full_cost']['id'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['table'] = 'field_data_field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['field'] = 'field_full_cost';
  $handler->display->display_options['fields']['field_full_cost']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['argument'] = '77';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'apartament' => 'apartament',
  );
  /* Критерий фильтра: Содержимое: номер квартиры (field_number_apartament) */
  $handler->display->display_options['filters']['field_number_apartament_value']['id'] = 'field_number_apartament_value';
  $handler->display->display_options['filters']['field_number_apartament_value']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['filters']['field_number_apartament_value']['field'] = 'field_number_apartament_value';
  $handler->display->display_options['filters']['field_number_apartament_value']['value'] = '95';

  /* Display: Фрагмент панели */
  $handler = $view->new_display('panel_pane', 'Фрагмент панели', 'panel_import_apartment');
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['view_import_apartment'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('термин из field_apartament_home'),
    t('Nid'),
    t('Статус'),
    t('Цена за кв.м'),
    t('Стоимость'),
    t('Все'),
    t('Фрагмент панели'),
    t('Представления-Фрагменты'),
  );
  $export['view_import_apartment'] = $view;

  return $export;
}
