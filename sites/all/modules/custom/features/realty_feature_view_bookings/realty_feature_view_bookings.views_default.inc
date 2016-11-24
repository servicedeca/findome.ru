<?php
/**
 * @file
 * realty_feature_view_bookings.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function realty_feature_view_bookings_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'booking';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'бронирования';
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
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
    'booking' => 'booking',
  );

  /* Display: Все бронирования */
  $handler = $view->new_display('panel_pane', 'Все бронирования', 'all_booking');
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Бронирования пользователя */
  $handler = $view->new_display('panel_pane', 'Бронирования пользователя', 'bookings_user');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Entity Reference: Связанная Сущность */
  $handler->display->display_options['relationships']['field_booking_user_target_id']['id'] = 'field_booking_user_target_id';
  $handler->display->display_options['relationships']['field_booking_user_target_id']['table'] = 'field_data_field_booking_user';
  $handler->display->display_options['relationships']['field_booking_user_target_id']['field'] = 'field_booking_user_target_id';
  $handler->display->display_options['relationships']['field_booking_user_target_id']['required'] = TRUE;
  /* Связь: Entity Reference: Связанная Сущность */
  $handler->display->display_options['relationships']['field_booking_apartment_target_id']['id'] = 'field_booking_apartment_target_id';
  $handler->display->display_options['relationships']['field_booking_apartment_target_id']['table'] = 'field_data_field_booking_apartment';
  $handler->display->display_options['relationships']['field_booking_apartment_target_id']['field'] = 'field_booking_apartment_target_id';
  $handler->display->display_options['relationships']['field_booking_apartment_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Поле: Содержимое: номер квартиры */
  $handler->display->display_options['fields']['field_number_apartament']['id'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['field'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['relationship'] = 'field_booking_apartment_target_id';
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'field_booking_apartment_target_id';
  /* Поле: Содержимое: Номер брони */
  $handler->display->display_options['fields']['field_booking_numbers']['id'] = 'field_booking_numbers';
  $handler->display->display_options['fields']['field_booking_numbers']['table'] = 'field_data_field_booking_numbers';
  $handler->display->display_options['fields']['field_booking_numbers']['field'] = 'field_booking_numbers';
  $handler->display->display_options['fields']['field_booking_numbers']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Статус */
  $handler->display->display_options['fields']['field_booking_status']['id'] = 'field_booking_status';
  $handler->display->display_options['fields']['field_booking_status']['table'] = 'field_data_field_booking_status';
  $handler->display->display_options['fields']['field_booking_status']['field'] = 'field_booking_status';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Пользователь: Uid */
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
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Ипотеки пользователя */
  $handler = $view->new_display('panel_pane', 'Ипотеки пользователя', 'mortgage_user');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Entity Reference: Связанная Сущность */
  $handler->display->display_options['relationships']['field_user_target_id']['id'] = 'field_user_target_id';
  $handler->display->display_options['relationships']['field_user_target_id']['table'] = 'field_data_field_user';
  $handler->display->display_options['relationships']['field_user_target_id']['field'] = 'field_user_target_id';
  /* Связь: Содержимое: Банк (field_bank) */
  $handler->display->display_options['relationships']['field_bank_tid']['id'] = 'field_bank_tid';
  $handler->display->display_options['relationships']['field_bank_tid']['table'] = 'field_data_field_bank';
  $handler->display->display_options['relationships']['field_bank_tid']['field'] = 'field_bank_tid';
  /* Связь: Термин таксономии: Ипотечная программа (field_bank_mortgage_program) */
  $handler->display->display_options['relationships']['field_bank_mortgage_program_value']['id'] = 'field_bank_mortgage_program_value';
  $handler->display->display_options['relationships']['field_bank_mortgage_program_value']['table'] = 'field_data_field_bank_mortgage_program';
  $handler->display->display_options['relationships']['field_bank_mortgage_program_value']['field'] = 'field_bank_mortgage_program_value';
  $handler->display->display_options['relationships']['field_bank_mortgage_program_value']['relationship'] = 'field_bank_tid';
  $handler->display->display_options['relationships']['field_bank_mortgage_program_value']['delta'] = '-1';
  /* Связь: Entity Reference: Связанная Сущность */
  $handler->display->display_options['relationships']['field_apartment_target_id']['id'] = 'field_apartment_target_id';
  $handler->display->display_options['relationships']['field_apartment_target_id']['table'] = 'field_data_field_apartment';
  $handler->display->display_options['relationships']['field_apartment_target_id']['field'] = 'field_apartment_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Термин таксономии: Имя */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_bank_tid';
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Поле: Содержимое: номер квартиры */
  $handler->display->display_options['fields']['field_number_apartament']['id'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['field'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['relationship'] = 'field_apartment_target_id';
  /* Поле: Содержимое: Название ипотека */
  $handler->display->display_options['fields']['field_mortgage_name']['id'] = 'field_mortgage_name';
  $handler->display->display_options['fields']['field_mortgage_name']['table'] = 'field_data_field_mortgage_name';
  $handler->display->display_options['fields']['field_mortgage_name']['field'] = 'field_mortgage_name';
  /* Поле: Содержимое: Требуемая сумма */
  $handler->display->display_options['fields']['field_required_amount']['id'] = 'field_required_amount';
  $handler->display->display_options['fields']['field_required_amount']['table'] = 'field_data_field_required_amount';
  $handler->display->display_options['fields']['field_required_amount']['field'] = 'field_required_amount';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Пользователь: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'field_user_target_id';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['booking'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Все бронирования'),
    t('Представления-Фрагменты'),
    t('Бронирования пользователя'),
    t('Сущность Пользователь связана через поле field_booking_user'),
    t('Сущность Содержимое связана через поле field_booking_apartment'),
    t('Nid'),
    t('номер квартиры'),
    t('Номер брони'),
    t('Статус'),
    t('Все'),
    t('Ипотеки пользователя'),
    t('Сущность Пользователь связана через поле field_user'),
    t('термин из field_bank'),
    t('field collection item from field_bank_mortgage_program'),
    t('Сущность Содержимое связана через поле field_apartment'),
    t('Имя'),
    t('Название ипотека'),
    t('Требуемая сумма'),
  );
  $export['booking'] = $view;

  return $export;
}
