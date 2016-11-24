<?php
/**
 * @file
 * realty_features_view_news.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function realty_features_view_news_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Содержимое';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Поле: Содержимое: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Содержимое';
  /* Поле: Содержимое: Изображение */
  $handler->display->display_options['fields']['field_image_news']['id'] = 'field_image_news';
  $handler->display->display_options['fields']['field_image_news']['table'] = 'field_data_field_image_news';
  $handler->display->display_options['fields']['field_image_news']['field'] = 'field_image_news';
  $handler->display->display_options['fields']['field_image_news']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_news']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Поле: Содержимое: Логотип */
  $handler->display->display_options['fields']['field_news_logo']['id'] = 'field_news_logo';
  $handler->display->display_options['fields']['field_news_logo']['table'] = 'field_data_field_news_logo';
  $handler->display->display_options['fields']['field_news_logo']['field'] = 'field_news_logo';
  $handler->display->display_options['fields']['field_news_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Критерий сортировки: Глобальный: Случайно */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
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
    'news' => 'news',
  );

  /* Display: Информация на форме поиска */
  $handler = $view->new_display('panel_pane', 'Информация на форме поиска', 'information_form_search');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'information' => 'information',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Новости на странице города */
  $handler = $view->new_display('panel_pane', 'Новости на странице города', 'news_city');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Город (field_news_city) */
  $handler->display->display_options['relationships']['field_news_city_tid']['id'] = 'field_news_city_tid';
  $handler->display->display_options['relationships']['field_news_city_tid']['table'] = 'field_data_field_news_city';
  $handler->display->display_options['relationships']['field_news_city_tid']['field'] = 'field_news_city_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Поле: Содержимое: Краткое описание */
  $handler->display->display_options['fields']['field_news_description']['id'] = 'field_news_description';
  $handler->display->display_options['fields']['field_news_description']['table'] = 'field_data_field_news_description';
  $handler->display->display_options['fields']['field_news_description']['field'] = 'field_news_description';
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_news_city_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Все новости города */
  $handler = $view->new_display('panel_pane', 'Все новости города', 'all_new_city');
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
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Город (field_news_city) */
  $handler->display->display_options['relationships']['field_news_city_tid']['id'] = 'field_news_city_tid';
  $handler->display->display_options['relationships']['field_news_city_tid']['table'] = 'field_data_field_news_city';
  $handler->display->display_options['relationships']['field_news_city_tid']['field'] = 'field_news_city_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Поле: Содержимое: Краткое описание */
  $handler->display->display_options['fields']['field_news_description']['id'] = 'field_news_description';
  $handler->display->display_options['fields']['field_news_description']['table'] = 'field_data_field_news_description';
  $handler->display->display_options['fields']['field_news_description']['field'] = 'field_news_description';
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Поле: Содержимое: Изображение */
  $handler->display->display_options['fields']['field_news_image']['id'] = 'field_news_image';
  $handler->display->display_options['fields']['field_news_image']['table'] = 'field_data_field_news_image';
  $handler->display->display_options['fields']['field_news_image']['field'] = 'field_news_image';
  $handler->display->display_options['fields']['field_news_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_news_city_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['news'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Заголовок'),
    t('Содержимое'),
    t('Изображение'),
    t('Логотип'),
    t('Информация на форме поиска'),
    t('Представления-Фрагменты'),
    t('Новости на странице города'),
    t('термин из field_news_city'),
    t('Краткое описание'),
    t('Дата публикации'),
    t('Все'),
    t('Все новости города'),
    t('Элементов на страницу'),
    t('- Все -'),
    t('Пропустить'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
  );
  $export['news'] = $view;

  return $export;
}
