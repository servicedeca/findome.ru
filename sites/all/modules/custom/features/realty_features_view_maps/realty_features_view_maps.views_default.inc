<?php
/**
 * @file
 * realty_features_view_maps.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function realty_features_view_maps_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Карты';
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
  $handler->display->display_options['style_plugin'] = 'default_map';
  $handler->display->display_options['style_options']['yandex_map_field'] = 'field_map';
  $handler->display->display_options['style_options']['yamaps_center_options'] = array(
    'map_center_type' => 'mini_map',
    'map_center_geolocation' => '',
    'zoom' => '11',
    'map_container' => array(
      'coords' => '{"center":[60.573531622367696,87.61726745557797],"zoom":4}',
    ),
  );
  $handler->display->display_options['style_options']['placemark_title'] = '';
  $handler->display->display_options['style_options']['baloon_title'] = 'field_map';
  $handler->display->display_options['style_options']['baloon_body'] = array(
    '' => '',
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  /* Field: Taxonomy term: Карта */
  $handler->display->display_options['fields']['field_map']['id'] = 'field_map';
  $handler->display->display_options['fields']['field_map']['table'] = 'field_data_field_map';
  $handler->display->display_options['fields']['field_map']['field'] = 'field_map';
  $handler->display->display_options['fields']['field_map']['click_sort_column'] = 'coords';
  $handler->display->display_options['fields']['field_map']['settings'] = array(
    'yamaps_display_options' => array(
      'display_type' => 'map',
      'open_button_text' => 'Open map',
      'close_button_text' => 'Close map',
    ),
    'controls' => 0,
    'traffic' => 0,
    'behaviors' => array(
      'clickZoom' => 'clickZoom',
      'dblClickZoom' => 'dblClickZoom',
      'drag' => 'drag',
      'multiTouch' => 'multiTouch',
      'rightMouseButtonMagnifier' => 'rightMouseButtonMagnifier',
      'scrollZoom' => 0,
      'ruler' => 0,
    ),
    'width' => '100%',
    'height' => '100%',
  );
  /* Contextual filter: Taxonomy term: Жилой комплекс (field_home_complex) */
  $handler->display->display_options['arguments']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    6 => '6',
  );
  /* Filter criterion: Content: Архивный жилой комплекс (field_archive) */
  $handler->display->display_options['filters']['field_archive_value']['id'] = 'field_archive_value';
  $handler->display->display_options['filters']['field_archive_value']['table'] = 'field_data_field_archive';
  $handler->display->display_options['filters']['field_archive_value']['field'] = 'field_archive_value';
  $handler->display->display_options['filters']['field_archive_value']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_archive_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_archive_value']['value'] = array(
    1 => '1',
  );

  /* Display: Карта жилого комплекса */
  $handler = $view->new_display('panel_pane', 'Карта жилого комплекса', 'map_complex');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Карта */
  $handler->display->display_options['fields']['field_map']['id'] = 'field_map';
  $handler->display->display_options['fields']['field_map']['table'] = 'field_data_field_map';
  $handler->display->display_options['fields']['field_map']['field'] = 'field_map';
  $handler->display->display_options['fields']['field_map']['click_sort_column'] = 'coords';
  $handler->display->display_options['fields']['field_map']['settings'] = array(
    'yamaps_display_options' => array(
      'display_type' => 'map',
      'open_button_text' => 'Open map',
      'close_button_text' => 'Close map',
    ),
    'controls' => 0,
    'traffic' => 0,
    'behaviors' => array(
      'clickZoom' => 'clickZoom',
      'dblClickZoom' => 'dblClickZoom',
      'drag' => 'drag',
      'rightMouseButtonMagnifier' => 'rightMouseButtonMagnifier',
      'scrollZoom' => 0,
      'multiTouch' => 0,
      'ruler' => 0,
    ),
    'width' => '100%',
    'height' => '350px',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Жилой комплекс (field_home_complex) */
  $handler->display->display_options['arguments']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_home_complex_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Карта застройщика */
  $handler = $view->new_display('panel_pane', 'Карта застройщика', 'developer_map');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['required'] = TRUE;
  /* Relationship: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    6 => '6',
  );
  /* Filter criterion: Content: Архивный жилой комплекс (field_archive) */
  $handler->display->display_options['filters']['field_archive_value']['id'] = 'field_archive_value';
  $handler->display->display_options['filters']['field_archive_value']['table'] = 'field_data_field_archive';
  $handler->display->display_options['filters']['field_archive_value']['field'] = 'field_archive_value';
  $handler->display->display_options['filters']['field_archive_value']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_archive_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_archive_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Карта для квартиры */
  $handler = $view->new_display('panel_pane', 'Карта для квартиры', 'apartment_map');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Content using Дом */
  $handler->display->display_options['relationships']['reverse_field_apartament_home_node']['id'] = 'reverse_field_apartament_home_node';
  $handler->display->display_options['relationships']['reverse_field_apartament_home_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_apartament_home_node']['field'] = 'reverse_field_apartament_home_node';
  $handler->display->display_options['relationships']['reverse_field_apartament_home_node']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_apartament_home_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Карта города */
  $handler = $view->new_display('panel_pane', 'Карта города', 'map_city');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  /* Relationship: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['label'] = 'термин из field_complex_developer';
  /* Relationship: Taxonomy term: Город (field_city) */
  $handler->display->display_options['relationships']['field_city_tid']['id'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['table'] = 'field_data_field_city';
  $handler->display->display_options['relationships']['field_city_tid']['field'] = 'field_city_tid';
  $handler->display->display_options['relationships']['field_city_tid']['relationship'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_city_tid']['label'] = 'термин из field_city';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Карта */
  $handler->display->display_options['fields']['field_map']['id'] = 'field_map';
  $handler->display->display_options['fields']['field_map']['table'] = 'field_data_field_map';
  $handler->display->display_options['fields']['field_map']['field'] = 'field_map';
  $handler->display->display_options['fields']['field_map']['click_sort_column'] = 'coords';
  $handler->display->display_options['fields']['field_map']['settings'] = array(
    'yamaps_display_options' => array(
      'display_type' => 'map',
      'open_button_text' => 'Open map',
      'close_button_text' => 'Close map',
    ),
    'controls' => 0,
    'traffic' => 0,
    'behaviors' => array(
      'clickZoom' => 'clickZoom',
      'dblClickZoom' => 'dblClickZoom',
      'drag' => 'drag',
      'multiTouch' => 'multiTouch',
      'rightMouseButtonMagnifier' => 'rightMouseButtonMagnifier',
      'scrollZoom' => 0,
      'ruler' => 0,
    ),
    'width' => '100%',
    'height' => '100%',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
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
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    6 => '6',
  );
  $handler->display->display_options['filters']['vid']['group'] = 1;
  $handler->display->display_options['filters']['vid']['expose']['operator_id'] = 'vid_op';
  $handler->display->display_options['filters']['vid']['expose']['label'] = 'Словарь';
  $handler->display->display_options['filters']['vid']['expose']['operator'] = 'vid_op';
  $handler->display->display_options['filters']['vid']['expose']['identifier'] = 'vid';
  $handler->display->display_options['filters']['vid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Акция (field_stock) */
  $handler->display->display_options['filters']['field_stock_value']['id'] = 'field_stock_value';
  $handler->display->display_options['filters']['field_stock_value']['table'] = 'field_data_field_stock';
  $handler->display->display_options['filters']['field_stock_value']['field'] = 'field_stock_value';
  $handler->display->display_options['filters']['field_stock_value']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_stock_value']['group'] = 1;
  $handler->display->display_options['filters']['field_stock_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_stock_value']['expose']['operator_id'] = 'field_stock_value_op';
  $handler->display->display_options['filters']['field_stock_value']['expose']['label'] = 'Акция (field_stock)';
  $handler->display->display_options['filters']['field_stock_value']['expose']['operator'] = 'field_stock_value_op';
  $handler->display->display_options['filters']['field_stock_value']['expose']['identifier'] = 'field_stock_value';
  $handler->display->display_options['filters']['field_stock_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Taxonomy term: Категория (field_home_category) */
  $handler->display->display_options['filters']['field_home_category_tid']['id'] = 'field_home_category_tid';
  $handler->display->display_options['filters']['field_home_category_tid']['table'] = 'field_data_field_home_category';
  $handler->display->display_options['filters']['field_home_category_tid']['field'] = 'field_home_category_tid';
  $handler->display->display_options['filters']['field_home_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_home_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_home_category_tid']['expose']['operator_id'] = 'field_home_category_tid_op';
  $handler->display->display_options['filters']['field_home_category_tid']['expose']['label'] = 'Категория (field_home_category)';
  $handler->display->display_options['filters']['field_home_category_tid']['expose']['operator'] = 'field_home_category_tid_op';
  $handler->display->display_options['filters']['field_home_category_tid']['expose']['identifier'] = 'field_home_category_tid';
  $handler->display->display_options['filters']['field_home_category_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_home_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_home_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_home_category_tid']['vocabulary'] = 'categories';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Архивный жилой комплекс (field_archive) */
  $handler->display->display_options['filters']['field_archive_value']['id'] = 'field_archive_value';
  $handler->display->display_options['filters']['field_archive_value']['table'] = 'field_data_field_archive';
  $handler->display->display_options['filters']['field_archive_value']['field'] = 'field_archive_value';
  $handler->display->display_options['filters']['field_archive_value']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_archive_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_archive_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_archive_value']['group'] = 1;
  /* Filter criterion: Content: Район (field_area) */
  $handler->display->display_options['filters']['field_area_tid']['id'] = 'field_area_tid';
  $handler->display->display_options['filters']['field_area_tid']['table'] = 'field_data_field_area';
  $handler->display->display_options['filters']['field_area_tid']['field'] = 'field_area_tid';
  $handler->display->display_options['filters']['field_area_tid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_area_tid']['group'] = 2;
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
  $handler->display->display_options['filters']['field_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_area_tid']['vocabulary'] = 'area';
  /* Filter criterion: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['filters']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['filters']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['filters']['field_complex_developer_tid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_complex_developer_tid']['group'] = 2;
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
  /* Filter criterion: Taxonomy term: Жилой комплекс (field_home_complex) */
  $handler->display->display_options['filters']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['filters']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_home_complex_target_id']['group'] = 2;
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
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Карта архивных ЖК застройщика */
  $handler = $view->new_display('panel_pane', 'Карта архивных ЖК застройщика', 'archive_developer_map');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_home_complex_target_id']['id'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['table'] = 'field_data_field_home_complex';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['field'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_home_complex_target_id']['required'] = TRUE;
  /* Relationship: Content: Застройщик (field_complex_developer) */
  $handler->display->display_options['relationships']['field_complex_developer_tid']['id'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['table'] = 'field_data_field_complex_developer';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['field'] = 'field_complex_developer_tid';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['relationships']['field_complex_developer_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    6 => '6',
  );
  /* Filter criterion: Content: Архивный жилой комплекс (field_archive) */
  $handler->display->display_options['filters']['field_archive_value']['id'] = 'field_archive_value';
  $handler->display->display_options['filters']['field_archive_value']['table'] = 'field_data_field_archive';
  $handler->display->display_options['filters']['field_archive_value']['field'] = 'field_archive_value';
  $handler->display->display_options['filters']['field_archive_value']['relationship'] = 'field_home_complex_target_id';
  $handler->display->display_options['filters']['field_archive_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['map'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Content entity referenced from field_home_complex'),
    t('Карта'),
    t('Все'),
    t('Карта жилого комплекса'),
    t('more'),
    t('Представления-Фрагменты'),
    t('Карта застройщика'),
    t('term from field_complex_developer'),
    t('Карта для квартиры'),
    t('field_apartament_home'),
    t('Карта города'),
    t('термин из field_complex_developer'),
    t('термин из field_city'),
    t('Словарь'),
    t('Акция (field_stock)'),
    t('Категория (field_home_category)'),
    t('Район (field_area)'),
    t('Застройщик (field_complex_developer)'),
    t('Жилой комплекс (field_home_complex)'),
    t('Карта архивных ЖК застройщика'),
  );
  $export['map'] = $view;

  $view = new view();
  $view->name = 'maps';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Карты';
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
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  $translatables['maps'] = array(
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
  );
  $export['maps'] = $view;

  return $export;
}
