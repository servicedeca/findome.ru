<?php
/**
 * @file
 * realty_feature_view_import_home.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function realty_feature_view_import_home_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'view_import_home';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Импорт дома';
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
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Термин таксономии: Имя */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;

  /* Display: Фрагмент панели */
  $handler = $view->new_display('panel_pane', 'Фрагмент панели', 'panel_import_home');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: Имя */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Поле: Термин таксономии: ID термина */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Словарь таксономии: Машинное имя */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'homes' => 'homes',
  );
  /* Критерий фильтра: Термин таксономии: Улица (field_street) */
  $handler->display->display_options['filters']['field_street_value']['id'] = 'field_street_value';
  $handler->display->display_options['filters']['field_street_value']['table'] = 'field_data_field_street';
  $handler->display->display_options['filters']['field_street_value']['field'] = 'field_street_value';
  $handler->display->display_options['filters']['field_street_value']['value'] = '111';
  $handler->display->display_options['filters']['field_street_value']['expose']['operator_id'] = 'field_street_value_op';
  $handler->display->display_options['filters']['field_street_value']['expose']['label'] = 'Улица (field_street)';
  $handler->display->display_options['filters']['field_street_value']['expose']['operator'] = 'field_street_value_op';
  $handler->display->display_options['filters']['field_street_value']['expose']['identifier'] = 'field_street_value';
  $handler->display->display_options['filters']['field_street_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Критерий фильтра: Термин таксономии: Номер дома по улице (field_number_home_street) */
  $handler->display->display_options['filters']['field_number_home_street_value']['id'] = 'field_number_home_street_value';
  $handler->display->display_options['filters']['field_number_home_street_value']['table'] = 'field_data_field_number_home_street';
  $handler->display->display_options['filters']['field_number_home_street_value']['field'] = 'field_number_home_street_value';
  $handler->display->display_options['filters']['field_number_home_street_value']['value'] = '111';
  $handler->display->display_options['filters']['field_number_home_street_value']['expose']['operator_id'] = 'field_number_home_street_value_op';
  $handler->display->display_options['filters']['field_number_home_street_value']['expose']['label'] = 'Номер дома по улице (field_number_home_street)';
  $handler->display->display_options['filters']['field_number_home_street_value']['expose']['operator'] = 'field_number_home_street_value_op';
  $handler->display->display_options['filters']['field_number_home_street_value']['expose']['identifier'] = 'field_number_home_street_value';
  $handler->display->display_options['filters']['field_number_home_street_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['view_import_home'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Фрагмент панели'),
    t('ID термина'),
    t('.'),
    t(','),
    t('Улица (field_street)'),
    t('Номер дома по улице (field_number_home_street)'),
    t('Представления-Фрагменты'),
  );
  $export['view_import_home'] = $view;

  return $export;
}
