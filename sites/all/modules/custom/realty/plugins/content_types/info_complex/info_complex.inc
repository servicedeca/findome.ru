<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_info_complex_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Info complex'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_info_complex_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_info_complex_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_info_complex');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_info_complex_content_type_theme(&$theme, $plugin) {
  $theme['realty_info_complex'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-info-complex',
  );
}


/**
 * Process variables for realty-info-complex.tpl.php.
 */
function template_preprocess_realty_info_complex(&$vars) {



  $node = menu_get_object('node', 1);

  // Главное изоброжение на странице
  $photos = field_get_items('node', $node, 'field_photos_complex');
  if (!empty($photos)) {
    foreach ($photos as $key => $photo) {
      $vars['photos'][$key] = theme('image', array(
        'path' => $photo['uri'],
        'alt' => $photo['alt'],
        'title' => $photo['title'],
      ));
    }
  }

  // Выбор произвольного изображения для ЖК
  $vars['img'] = $vars['photos'][rand (0, count($vars['photos']) - 1)];

  // Фоновое изображение
  $vars['background'] = '/' . realty_file_directory_path() . '/' . $node->field_main_photo[LANGUAGE_NONE][0]['filename'];

  // Подсказки
  $vars['img_cost'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('meter-question'),
      'rel' => array('tooltip'),
      'data-placement' => array('right'),
      'title' => array('Средняя цена за кв.м. в продаже и изменение относительно первого числа текущего месяца.'),
    )
  ));

  $vars['img_finance'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('fin-question'),
      'rel' => array('tooltip'),
      'data-placement' => array('right'),
      'title' => array('Финансирование (СС – собственные средства, ЗС – заемные средства, СУДС – средства участников долевого строительства, П – прочее)'),
    )
  ));

  $vars['img_contract'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('tip-question'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Тип договора (ДДУ - договор долевого участия, ДКП – договор купли-продажи, ПДДУ – предварительный договор купли-продажи, П – прочее)'),
    )
  ));

  // Финансирование
  $entity_id_financing = $node->field_complex_financing['und'][0]['value'];
  $entity_financing = entity_load('field_collection_item', array($entity_id_financing));

  // Финансирование СС
  $vars['financing'] = $entity_financing[$entity_id_financing]->field_complex_financing_ss['und'][0]['value'] == "1" ? "СС" : '';

  // Финансирование ЗС
  if ($entity_financing[$entity_id_financing]->field_complex_financing_zs['und'][0]['value'] == "1") {
    if ($vars['financing'] != '') {
      $vars['financing'] .= ', ';
    }
    $vars['financing'] .= 'ЗС';
  }

  // Финансирование СУДС
  if ($entity_financing[$entity_id_financing]->field_complex_financing_suds['und'][0]['value'] == "1") {
    if ($vars['financing'] != '') {
      $vars['financing'] .= ', ';
    }
    $vars['financing'] .= 'СУДС';
  }

  // Финансирование П
  if ($entity_financing[$entity_id_financing]->field_complex_financing_p['und'][0]['value'] == "1") {
    if ($vars['financing'] != '') {
      $vars['financing'] .= ', ';
    }
    $vars['financing'] .= 'П';
  }

  // Готовность
  $vars['readiness'] = $node->field_complex_readiness['und'][0]['value'] != '' ? $node->field_complex_readiness['und'][0]['value'] : 0;

  // Тип договора
  $entity_id_contract = $node->field_complex_contract['und'][0]['value'];
  $entity_contract = entity_load('field_collection_item', array($entity_id_contract));

  // Тип договора ДДУ
  $vars['contract'] = $entity_contract[$entity_id_contract]->field_complex_contract_ddu['und'][0]['value'] == "1" ? 'ДДУ' : '';

  // Тип договора ПДДУ
  if ($entity_contract[$entity_id_contract]->field_complex_contract_pddu['und'][0]['value'] == "1") {
    if ($vars['contract'] != '') {
      $vars['contract'] .= ', ';
    }
    $vars['contract'] .= 'ПУУ';
  }

  // Тип договора ДКП
  if ($entity_contract[$entity_id_contract]->field_complex_contract_dkp['und'][0]['value'] == "1") {
    if ($vars['contract'] != '') {
      $vars['contract'] .= ', ';
    }
    $vars['contract'] .= 'ДКП';
  }

  // Тип договора ЖСК
  if ($entity_contract[$entity_id_contract]->field_complex_contract_zhsk['und'][0]['value'] == "1") {
    if ($vars['contract'] != '') {
      $vars['contract'] .= ', ';
    }
    $vars['contract'] .= 'ЖСК';
  }

  // Видеонаблюдение
  $vars['img_videovision'] = theme('image', array(
    'path' => $node->field_complex_videovision['und'][0]['value'] == '1' ?
        REALTY_FRONT_THEME_PATH . '/images/nice.svg' : REALTY_FRONT_THEME_PATH . '/images/bad.svg',
  ));

  // Парковка
  $vars['img_parking'] = theme('image', array(
    'path' => $node->field_complex_parking['und'][0]['value'] == '1' ?
        REALTY_FRONT_THEME_PATH . '/images/nice.svg' : REALTY_FRONT_THEME_PATH . '/images/bad.svg',
  ));

  // Огороженная территория
  $vars['img_fenced'] = theme('image', array(
    'path' => $node->field_complex_fenced['und'][0]['value'] == '1' ?
        REALTY_FRONT_THEME_PATH . '/images/nice.svg' : REALTY_FRONT_THEME_PATH . '/images/bad.svg',
  ));

  // Охрана
  $vars['img_security'] = theme('image', array(
    'path' =>$node->field_complex_security['und'][0]['value'] == '1' ?
        REALTY_FRONT_THEME_PATH . '/images/nice.svg' : REALTY_FRONT_THEME_PATH . '/images/bad.svg',
  ));

  // Чистовая отделка
  $vars['img_fine_finishing'] = theme('image', array(
    'path' => $node->field_complex_fine_finishing['und'][0]['value'] == '1' ?
        REALTY_FRONT_THEME_PATH . '/images/nice.svg' : REALTY_FRONT_THEME_PATH . '/images/bad.svg',
  ));

  // Материал стен
  foreach ($node->field_complex_material['und'] as $taxonomy_tid_material) {
    $taxonomy_material = taxonomy_term_load($taxonomy_tid_material['tid']);
    $vars['material'] .= $vars['material'] != '' ? ', ' . $taxonomy_material->name : $taxonomy_material->name;
  }

  // Начало строительства
  $vars['start_building'] = $node->field_complex_start['und'][0]['value'];

  // Высота потолков
  $vars['ceiling_height'] = $node->field_complex_ceiling_height['und'][0]['value'];

  // Минимальная и максимальная стоимость квартир в продаже
  $vars['cost'] = realty_get_min_max_cost_active_apartment_complex($node->nid);

  // Этажность
  $vars['complex_floor'] = $node->field_complex_floor['und'][0]['value'];

  $dead_line = field_view_field('node', $node, 'field_complex_deadline');
  $dead_line_entity = $dead_line['#object']->field_complex_deadline[LANGUAGE_NONE][0]['value'];

  if (isset($dead_line[0]['entity']['field_collection_item'][$dead_line_entity]['field_number_queue'])) {
    $vars['field_number_queue'] = $dead_line[0]['entity']['field_collection_item'][$dead_line_entity]['field_number_queue']['#items'][0]['value'];
  }

  if (isset($dead_line[0]['entity']['field_collection_item'][$dead_line_entity]['field_queue_year'])) {
    $vars['field_queue_year'] = $dead_line[0]['entity']['field_collection_item'][$dead_line_entity]['field_queue_year']['#items'][0]['value'];
  }

  if (isset($dead_line[0]['entity']['field_collection_item'][$dead_line_entity]['field_queue_quarter'])) {
    $vars['field_queue_quarter'] = $dead_line[0]['entity']['field_collection_item'][$dead_line_entity]['field_queue_quarter']['#items'][0]['value'];
  }

  $term_developer =  taxonomy_term_load($node->field_complex_developer['und'][0]['tid']);

  $vars['developer'] = l($term_developer->name, 'taxonomy/term/' . $term_developer->tid,
    array (
      'attributes' => array(
        'target' => '_blank',
        'class' => array(''),
      ),
    )
  );

  $vars['complex_name'] = $node->title;

  $description =  field_view_field('node', $node, 'field_description');
  $desc_entity = $description['#object']->field_description['und'][0]['value'];

  //Общая информация
  if (isset($description[0]['entity']['field_collection_item'][$desc_entity]['field_location'])) {
    $vars['mini_description'] = $description[0]['entity']['field_collection_item'][$desc_entity]['field_location'][0]['#markup'];
    $vars['location_description'] = $description[0]['entity']['field_collection_item'][$desc_entity]['field_location']['#items'][0]['value'];
  }

  //Подробная информация
  if (isset($description[0]['entity']['field_collection_item'][$desc_entity]['field_detailed'])) {
    $vars['detailed_description'] = $description[0]['entity']['field_collection_item'][$desc_entity]['field_detailed'][0]['#markup'];
  }

  //Инфраструктура
  if (isset($description[0]['entity']['field_collection_item'][$desc_entity]['field_infrastructure'])) {
    $vars['infrastructure_description'] = $description[0]['entity']['field_collection_item'][$desc_entity]['field_infrastructure'][0]['#markup'];
  }

  //Условия покупки
  if (isset($description[0]['entity']['field_collection_item'][$desc_entity]['field_service'])) {
    $vars['service_description'] = $description[0]['entity']['field_collection_item'][$desc_entity]['field_service'][0]['#markup'];
  }
  $address =  field_get_items('node', $node, 'field_address');
  $vars['address'] = $address[0]['value'];

  // Количество квартир
  $vars['count_1'] = realty_get_apartment_active_complex($node->nid, array('1c', '1'));
  $vars['count_2'] = realty_get_apartment_active_complex($node->nid, array('2c', '2'));
  $vars['count_3'] = realty_get_apartment_active_complex($node->nid, array('3c', '3'));
  $vars['count_other'] = realty_get_apartment_active_complex($node->nid) - ($vars['count_1'] + $vars['count_2'] + $vars['count_3']);

  $vars['count_active_apartments'] = $vars['count_1'] + $vars['count_2'] + $vars['count_3'] + $vars['count_other'];

  // Поиск средней стоимости квадратного метра
  $price_render = realty_get_average_price_apartment_complex($node->nid);

  $vars['price_from'] = $price_render;

  // Поиск средней стоимости квадратного метра на первое число текущего месяца
  $tec_price = (int)str_replace(" ","",$price_render);

  $date = date('d-m-Y');
  $date = explode('-', $date);
  $date_1 = '1-' . $date['1'] . '-' . $date['2'];
  $date_str = strtotime($date_1);
  $price_1 = db_query("SELECT all_apartments, date
                        FROM realty_analytics_average_price_sq
                        WHERE complex_nid = :complex_nid
                        AND date >= :date ORDER BY id LIMIT 1
                        ", array(':complex_nid' => $node->nid, ':date' => $date_str))->fetchAll();

  if(!empty($price_1)) {
    $x = 100 - (($tec_price * 100) / str_replace(" ","", $price_1[0]->all_apartments));
    $vars['x'] = round($x, 3);
  }
  else{
    $x = 0;
    $vars['x'] = 0;
  }
  if($x >= 0) {
    $vars['img_x'] = theme('image', array(
        'path' => REALTY_FRONT_THEME_PATH . '/images/tr-top.svg'
      )
    );
  }
  else {
    $vars['img_x'] = theme('image', array (
        'path' => REALTY_FRONT_THEME_PATH . '/images/tr-bottom.svg'
      )
    );
  }

  // Подсчет общего количества квартир в ЖК
  $count_apartments = realty_get_count_apartment_complex($node->nid);

  $vars['count_apartments'] = $count_apartments[0]->count_1_rooms +
    $count_apartments[0]->count_2_rooms +
    $count_apartments[0]->count_3_rooms +
    $count_apartments[0]->count_other_rooms;

  // Доля проданнных квартир
  $vars['procent'] = $vars['count_active_apartments'] * 100 / $vars['count_apartments'];

  // Изображения для шаблона
  $vars['findome_logo'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/findome-gray.svg',
    'attributes' => array(
      'class' => array('margin-left-15')
    )));

  // Расположение Жилого комплекса
  $vars['map'] = views_embed_view('map', 'map_complex', arg(1));

  /*$vars['plan_complex'] = theme('realty_plan_complex');*/

  /*** План ЖК ***/

  // Это не страница планировки
  $vars['plan'] = FALSE;

  $nid = arg(1);
  $node = node_load($nid);
  $vars['complex_id'] = $nid;
  if (!empty($node->field_plan_complex)) {
    $file = realty_file_directory_path() . '/' . $node->field_plan_complex[LANGUAGE_NONE][0]['filename'];
    $vars['complex_plan'] = file_get_contents($file);

    drupal_add_js(array(
      'complex_plan_theme' => TRUE,
      'bug_fix' => TRUE,
    ), 'setting');
  }
  else {
    $home_tid = realty_get_home_complex($node->nid);
    drupal_add_js(array(
      'complex_plan_theme' => TRUE,
      'complex_plan_none' => TRUE,
      'bug_fix' => TRUE,
      'home_tid' => $home_tid[0]->tid
    ), 'setting');
  }

  $vars['modal'] = theme('realty_apartment_modal', array('plan' => TRUE ));

  $file = REALTY_FRONT_THEME_PATH . '/images/cmp_hover.svg';
  $vars['img_hover'] = file_get_contents($file);

  $vars['background'] = '/' . realty_file_directory_path() . '/' . $node->field_main_photo[LANGUAGE_NONE][0]['filename'];

  $vars['img_legend'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/area-legend.svg',
  ));

  /*Документы*/
  $vars['views_documents'] = views_embed_view('complex', 'complex_documents', $node->nid);

  drupal_add_js(REALTY_FRONT_THEME_PATH . '/js/realty_search_form.js');
}
