<?php
/**
 * @file
 * realty_admin_feature_booking_mortgage.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function realty_admin_feature_booking_mortgage_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'booking_mortgage_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Бронирования и заявки для администратора';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_booking_user_target_id']['id'] = 'field_booking_user_target_id';
  $handler->display->display_options['relationships']['field_booking_user_target_id']['table'] = 'field_data_field_booking_user';
  $handler->display->display_options['relationships']['field_booking_user_target_id']['field'] = 'field_booking_user_target_id';
  /* Поле: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Поле: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  /* Критерий сортировки: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерий фильтра: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Бронирования */
  $handler = $view->new_display('panel_pane', 'Бронирования', 'bookings_admin');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_booking_user_target_id']['id'] = 'field_booking_user_target_id';
  $handler->display->display_options['relationships']['field_booking_user_target_id']['table'] = 'field_data_field_booking_user';
  $handler->display->display_options['relationships']['field_booking_user_target_id']['field'] = 'field_booking_user_target_id';
  $handler->display->display_options['relationships']['field_booking_user_target_id']['label'] = 'Сущность Пользователь связана через поле field_booking_user';
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_booking_apartment_target_id']['id'] = 'field_booking_apartment_target_id';
  $handler->display->display_options['relationships']['field_booking_apartment_target_id']['table'] = 'field_data_field_booking_apartment';
  $handler->display->display_options['relationships']['field_booking_apartment_target_id']['field'] = 'field_booking_apartment_target_id';
  $handler->display->display_options['relationships']['field_booking_apartment_target_id']['label'] = 'Сущность Содержимое связана через поле field_booking_apartment';
  /* Связь: Content: Дом (field_apartament_home) */
  $handler->display->display_options['relationships']['field_apartament_home_tid']['id'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['table'] = 'field_data_field_apartament_home';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['field'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['relationship'] = 'field_booking_apartment_target_id';
  $handler->display->display_options['relationships']['field_apartament_home_tid']['label'] = 'термин из field_apartament_home';
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['label'] = 'Сущность Содержимое связана через поле field_home_complex';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Поле: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Дата публикации';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Поле: User: ФИО */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['relationship'] = 'field_booking_user_target_id';
  /* Поле: Content: Имя на кого бронируется */
  $handler->display->display_options['fields']['field_booking_name']['id'] = 'field_booking_name';
  $handler->display->display_options['fields']['field_booking_name']['table'] = 'field_data_field_booking_name';
  $handler->display->display_options['fields']['field_booking_name']['field'] = 'field_booking_name';
  /* Поле: Content: номер квартиры */
  $handler->display->display_options['fields']['field_number_apartament']['id'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['table'] = 'field_data_field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['field'] = 'field_number_apartament';
  $handler->display->display_options['fields']['field_number_apartament']['relationship'] = 'field_booking_apartment_target_id';
  /* Поле: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'field_booking_apartment_target_id';
  /* Поле: Content: Менеджер */
  $handler->display->display_options['fields']['field_booking_manager']['id'] = 'field_booking_manager';
  $handler->display->display_options['fields']['field_booking_manager']['table'] = 'field_data_field_booking_manager';
  $handler->display->display_options['fields']['field_booking_manager']['field'] = 'field_booking_manager';
  /* Поле: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_booking_user_target_id';
  /* Поле: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Заголовок';
  /* Поле: Content: Nid */
  $handler->display->display_options['fields']['nid_2']['id'] = 'nid_2';
  $handler->display->display_options['fields']['nid_2']['table'] = 'node';
  $handler->display->display_options['fields']['nid_2']['field'] = 'nid';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'booking' => 'booking',
  );
  /* Критерий фильтра: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Дата публикации';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Критерий фильтра: Taxonomy term: Жилой комплекс (field_home_complex) */
  $handler->display->display_options['filters']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['filters']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_home_complex_target_id']['relationship'] = 'field_apartament_home_tid';
  $handler->display->display_options['filters']['field_home_complex_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_home_complex_target_id']['expose']['operator_id'] = 'field_home_complex_target_id_op';
  $handler->display->display_options['filters']['field_home_complex_target_id']['expose']['label'] = 'Жилой комплекс (field_home_complex)';
  $handler->display->display_options['filters']['field_home_complex_target_id']['expose']['operator'] = 'field_home_complex_target_id_op';
  $handler->display->display_options['filters']['field_home_complex_target_id']['expose']['identifier'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_home_complex_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Ипотека */
  $handler = $view->new_display('panel_pane', 'Ипотека', 'mortgage_admin');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_target_id']['id'] = 'field_user_target_id';
  $handler->display->display_options['relationships']['field_user_target_id']['table'] = 'field_data_field_user';
  $handler->display->display_options['relationships']['field_user_target_id']['field'] = 'field_user_target_id';
  $handler->display->display_options['relationships']['field_user_target_id']['label'] = 'Сущность Пользователь связана через поле field_user';
  /* Связь: Content: Банк (field_bank) */
  $handler->display->display_options['relationships']['field_bank_tid']['id'] = 'field_bank_tid';
  $handler->display->display_options['relationships']['field_bank_tid']['table'] = 'field_data_field_bank';
  $handler->display->display_options['relationships']['field_bank_tid']['field'] = 'field_bank_tid';
  $handler->display->display_options['relationships']['field_bank_tid']['label'] = 'термин из field_bank';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Поле: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Дата публикации';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d H:i:s';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Поле: User: ФИО */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['relationship'] = 'field_user_target_id';
  /* Поле: Content: ФИО */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  /* Поле: Content: Банк */
  $handler->display->display_options['fields']['field_bank']['id'] = 'field_bank';
  $handler->display->display_options['fields']['field_bank']['table'] = 'field_data_field_bank';
  $handler->display->display_options['fields']['field_bank']['field'] = 'field_bank';
  /* Поле: Content: Филиал */
  $handler->display->display_options['fields']['field_mortgage_bank_affiliate']['id'] = 'field_mortgage_bank_affiliate';
  $handler->display->display_options['fields']['field_mortgage_bank_affiliate']['table'] = 'field_data_field_mortgage_bank_affiliate';
  $handler->display->display_options['fields']['field_mortgage_bank_affiliate']['field'] = 'field_mortgage_bank_affiliate';
  /* Поле: Content: Название ипотека */
  $handler->display->display_options['fields']['field_mortgage_name']['id'] = 'field_mortgage_name';
  $handler->display->display_options['fields']['field_mortgage_name']['table'] = 'field_data_field_mortgage_name';
  $handler->display->display_options['fields']['field_mortgage_name']['field'] = 'field_mortgage_name';
  /* Поле: Content: Требуемая сумма */
  $handler->display->display_options['fields']['field_required_amount']['id'] = 'field_required_amount';
  $handler->display->display_options['fields']['field_required_amount']['table'] = 'field_data_field_required_amount';
  $handler->display->display_options['fields']['field_required_amount']['field'] = 'field_required_amount';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'mortgage' => 'mortgage',
  );
  /* Критерий фильтра: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Дата публикации';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Критерий фильтра: Content: Банк (field_bank) */
  $handler->display->display_options['filters']['field_bank_tid']['id'] = 'field_bank_tid';
  $handler->display->display_options['filters']['field_bank_tid']['table'] = 'field_data_field_bank';
  $handler->display->display_options['filters']['field_bank_tid']['field'] = 'field_bank_tid';
  $handler->display->display_options['filters']['field_bank_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_bank_tid']['expose']['operator_id'] = 'field_bank_tid_op';
  $handler->display->display_options['filters']['field_bank_tid']['expose']['label'] = 'Банк (field_bank)';
  $handler->display->display_options['filters']['field_bank_tid']['expose']['operator'] = 'field_bank_tid_op';
  $handler->display->display_options['filters']['field_bank_tid']['expose']['identifier'] = 'field_bank_tid';
  $handler->display->display_options['filters']['field_bank_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_bank_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_bank_tid']['vocabulary'] = 'banks';
  $translatables['booking_mortgage_admin'] = array(
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
    t('User entity referenced from field_booking_user'),
    t('Nid'),
    t('Post date'),
    t('Бронирования'),
    t('Сущность Пользователь связана через поле field_booking_user'),
    t('Сущность Содержимое связана через поле field_booking_apartment'),
    t('термин из field_apartament_home'),
    t('Сущность Содержимое связана через поле field_home_complex'),
    t('Дата публикации'),
    t('ФИО'),
    t('Имя на кого бронируется'),
    t('номер квартиры'),
    t('Менеджер'),
    t('Uid'),
    t('Заголовок'),
    t('Жилой комплекс (field_home_complex)'),
    t('View panes'),
    t('Ипотека'),
    t('Сущность Пользователь связана через поле field_user'),
    t('термин из field_bank'),
    t('Банк'),
    t('Филиал'),
    t('Название ипотека'),
    t('Требуемая сумма'),
    t('Банк (field_bank)'),
  );
  $export['booking_mortgage_admin'] = $view;

  return $export;
}
