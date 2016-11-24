<?php
/**
 * @file
 * realty_features_view_reviews_developers.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function realty_features_view_reviews_developers_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'view_reviews_developer';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Отзывы о застройщиках';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'автор';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Имя';
  /* Field: Content: Оценка */
  $handler->display->display_options['fields']['field_review_developer_assessmen']['id'] = 'field_review_developer_assessmen';
  $handler->display->display_options['fields']['field_review_developer_assessmen']['table'] = 'field_data_field_review_developer_assessmen';
  $handler->display->display_options['fields']['field_review_developer_assessmen']['field'] = 'field_review_developer_assessmen';
  $handler->display->display_options['fields']['field_review_developer_assessmen']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Содержимое';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Дата публикации';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'j.d.Y - H:i ';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Застройщик (field_review_developer_developer) */
  $handler->display->display_options['arguments']['field_review_developer_developer_target_id']['id'] = 'field_review_developer_developer_target_id';
  $handler->display->display_options['arguments']['field_review_developer_developer_target_id']['table'] = 'field_data_field_review_developer_developer';
  $handler->display->display_options['arguments']['field_review_developer_developer_target_id']['field'] = 'field_review_developer_developer_target_id';
  $handler->display->display_options['arguments']['field_review_developer_developer_target_id']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_review_developer_developer_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_review_developer_developer_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_review_developer_developer_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_review_developer_developer_target_id']['summary_options']['items_per_page'] = '25';
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
    'review_developer' => 'review_developer',
  );

  /* Display: Отзывы о застройщике */
  $handler = $view->new_display('panel_pane', 'Отзывы о застройщике', 'reviews_developer');
  $translatables['view_reviews_developer'] = array(
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
    t('автор'),
    t('Имя'),
    t('Оценка'),
    t('Содержимое'),
    t('Дата публикации'),
    t('Все'),
    t('Отзывы о застройщике'),
    t('View panes'),
  );
  $export['view_reviews_developer'] = $view;

  return $export;
}
