<?php

/**
 * @file.
 */

function realty_data_update_views_data() {
  $data['realty_data_update_logs']['table']['group'] = t('Журнал обновлений информации о квартирах');

  // Базовый столбец для views
  $data['realty_data_update_logs']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Номер обновления'),
    'help' => t('Уникальный номер обновления'),
    'weight' => -10,
  );

  // Связывание с таблицей квартир
  $data['realty_data_update_logs']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  // ID обновления
  $data['realty_data_update_logs']['id'] = array(
    'title' => t('Номер обновления'),
    'help' => t('Уникальный номер обновления.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  // NID квартиры
  $data['realty_data_update_logs']['nid'] = array(
    'title' => t('Nid квартиры'),
    'help' => t('Nid квартиры.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'relationship' => array(
      'base' => 'node',
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Квартира'),
    ),
  );

  // Старый статус квартиры
  $data['realty_data_update_logs']['old_status'] = array(
    'title' => t('Старый статус'),
    'help' => t('Старый статус квартиры.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // Новый статус квартиры
  $data['realty_data_update_logs']['new_status'] = array(
    'title' => t('Новый статус'),
    'help' => t('Новый статус квартиры.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // Старая стоимость квартиры
  $data['realty_data_update_logs']['old_cost'] = array(
    'title' => t('Старая стоимость'),
    'help' => t('Старая стоимость квартиры.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // Новая стоимость квартиры
  $data['realty_data_update_logs']['new_cost'] = array(
    'title' => t('Новая стоимость'),
    'help' => t('Новая стоимость квартиры.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // Время начала обновления
  $data['realty_data_update_logs']['start_time'] = array(
    'title' => t('Время обновления'),
    'help' => t('Время начала обновления.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  return $data;
}