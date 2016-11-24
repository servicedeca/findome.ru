<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_complex_rating_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Complex rating'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_complex_rating_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_complex_rating_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_complex_rating');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_complex_rating_content_type_theme(&$theme, $plugin) {
  $theme['realty_complex_rating'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-complex-rating',
  );
}


/**
 * Process variables for realty-info-complex.tpl.php.
 */
function template_preprocess_realty_complex_rating(&$vars) {

  $node_id_complex = arg(1);
  $node_complex = node_load($node_id_complex);

  // Фоновое изображение
  $vars['background'] = '/' . realty_file_directory_path() . '/' . $node_complex->field_main_photo[LANGUAGE_NONE][0]['filename'];

  $term_id_developer = $node_complex->field_complex_developer['und'][0]['tid'];

  // Общая величина рейтинга Жилого комплекса
  $vars['complex_rating'] = $node_complex->field_complex_rating_val['und'][0]['value'] ?
    $node_complex->field_complex_rating_val['und'][0]['value'] : '0';

  // Общие величины рейтинга
  $vars['peoples_rating'] = $node_complex->field_complex_people_rating_valu['und'][0]['value'] ?
    $node_complex->field_complex_people_rating_valu['und'][0]['value'] : '0';
  $vars['finance_rating'] = $node_complex->field_complex_finance_rating_val['und'][0]['value'] ?
    $node_complex->field_complex_finance_rating_val['und'][0]['value'] : '0';
  $vars['contract_rating'] = $node_complex->field_complex_contr_rating_value['und'][0]['value'] ?
    $node_complex->field_complex_contr_rating_value['und'][0]['value'] : '0';
  $vars['infrastruct_rating'] = $node_complex->field_complex_infra_rating_value['und'][0]['value'] ?
    $node_complex->field_complex_infra_rating_value['und'][0]['value'] : '0';
  $vars['yard_rating'] = $node_complex->field_complex_yard_rating_value['und'][0]['value'] ?
    $node_complex->field_complex_yard_rating_value['und'][0]['value'] : '0';
  $vars['info_rating'] = $node_complex->field_omplex_info_rating_value['und'][0]['value'] ?
    $node_complex->field_omplex_info_rating_value['und'][0]['value'] : '0';


  /*** Подробные параметры рейтинга ***/

  // Народная рейтинг
  $term_developer = taxonomy_term_load($term_id_developer);

  $vars['review_developer_rating'] = $term_developer->field_developer_rating_ass_value['und'][0]['value'];
  $vars['review_complex_rating'] = $node_complex->field_complex_reviews_rating_val['und'][0]['value'] ?
    $node_complex->field_complex_reviews_rating_val['und'][0]['value'] : '0';

  $vars['review_developer_rating_question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Средняя оценка застройщика по 5-ти балльной шкале'),
    )
  ));

  $vars['review_complex_rating_question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Больше положительных отзывов на 50% и более – «+5б», менее, чем на 50% – «+2б», равное количество «+» и «-»  – «0б», больше отрицательных – «-3б»'),
    )
  ));

  // Рейтинг - Финансирование
  $rating_finance = 0;

  $entity = entity_load_single('field_collection_item', array(
    $node_complex->field_complex_finance_rating['und'][0]['value']
  ));

  // Собственные средства
  if ($entity->field_complex_finance_rating_own['und'][0]['value'] == 1) {

    $vars['finance_rating_own']['value'] = 10;
    $vars['finance_rating_own']['text'] = 'Да';
  } else {
    $vars['finance_rating_own']['value'] = 0;
    $vars['finance_rating_own']['text'] = 'Нет';
  }

  $vars['finance_rating_own_question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Нет – «0б», Да «+10б»'),
    )
  ));

  // Заемные средства
  if ($entity->field_complex_finance_rating_cre['und'][0]['value'] == '0') {

    $vars['finance_rating_cre']['value'] = 10;
    $vars['finance_rating_cre']['text'] = 'Банк в топ-100';
  } else if ($entity->field_complex_finance_rating_cre['und'][0]['value'] == '1') {

    $vars['finance_rating_cre']['value'] = 5;
    $vars['finance_rating_cre']['text'] = 'Банк не в топ-100';;
  } else if ($entity->field_complex_finance_rating_cre['und'][0]['value'] == '2') {

    $vars['finance_rating_cre']['value'] = 10;
    $vars['finance_rating_cre']['text'] = 'Инвесторы или юр. лица с рейтингом ААА';
  } else if ($entity->field_complex_finance_rating_cre['und'][0]['value'] == '3') {

    $vars['finance_rating_cre']['value'] = 5;
    $vars['finance_rating_cre']['text'] = 'Инвесторы или юр. лица с рейтингом АА и ниже';
  }  else {
    $vars['finance_rating_cre']['value'] = 0;
    $vars['finance_rating_cre']['text'] = 'Нет информации';
  }

  $vars['finance_rating_cre_question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Банк в топ-100  – «+10б», банк не в топ-100 – «+5б», инвесторы-юр.лица с рейтингом ААА – «+10б», инвесторы-юр.лица с рейтингом АА и ниже – «+5б»'),
    )
  ));

  // Средства участников долевого строительства больше 50%
  if ($entity->field_complex_finance_rating_pat['und'][0]['value'] == '1') {
    $vars['finance_rating_par']['value'] = -5;
    $vars['finance_rating_par']['text'] = 'Более 70%';
  } else if ($entity->field_complex_finance_rating_pat['und'][0]['value'] == '2') {
    $vars['finance_rating_par']['value'] = 0;
    $vars['finance_rating_par']['text'] = 'Менее 70%';
  } else {
    $vars['finance_rating_par']['value'] = 0;
    $vars['finance_rating_par']['text'] = 'Нет';
  }

  $vars['finance_rating_par_question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Более 70% в общей структуре – «-5б», Менее 70% в общей структуре – «0б»'),
    )
  ));


  // Рейтинг - Договор
  $entity = entity_load_single('field_collection_item', array(
    $node_complex->field_complex_contr_rating['und'][0]['value']
  ));

  // Тип договора
  if ($entity->field_complex_contr_rating_type['und'][0]['value'] == '0') {
    $vars['contr_rating_type']['value'] = 10;
    $vars['contr_rating_type']['text'] = 'ДДУ';
  } else {
    $vars['contr_rating_type']['value'] = 0;
    $vars['contr_rating_type']['text'] = 'Прочие';
  }

  $vars['contr_rating_type_question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Дду – «+10б», Нет – «0б»'),
    )
  ));


  // Рейтинг - Инфраструктура
  $entity = entity_load_single('field_collection_item', array(
    $node_complex->field_complex_infra_rating['und'][0]['value']
  ));

  // Транспортная доступность
  if ($entity->field_complex_infra_rating_trans['und'][0]['value'] != '') {

    $vars['infra_rating'][0]['value'] = (int)$entity->field_complex_infra_rating_trans['und'][0]['value'];
    $vars['infra_rating'][0]['text'] = '';
  } else {
    $vars['infra_rating'][0]['value'] = 0;
    $vars['infra_rating'][0]['text'] = '';
  }
  $vars['infra_rating'][0]['title'] = 'Транспортная доступность';
  $vars['infra_rating'][0]['question'] = '';

  // Метро
  if ((float)$entity->field_complex_infra_rating_metro['und'][0]['value'] < 1) {

    $vars['infra_rating'][1]['value'] = 2;
    $vars['infra_rating'][1]['text'] = 'до 1 км';
  } else if ((float)$entity->field_complex_infra_rating_metro['und'][0]['value'] >= 1 &&
    (float)$entity->field_complex_infra_rating_metro['und'][0]['value'] <= 2) {

    $vars['infra_rating'][1]['value'] = 1;
    $vars['infra_rating'][1]['text'] = '1-2 км';
  } else {
    $vars['infra_rating'][1]['value'] = 0;
    $vars['infra_rating'][1]['text'] = 'более 2 км';
  }
  $vars['infra_rating'][1]['title'] = 'Близость к метро';
  $vars['infra_rating'][1]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('До 1 км – «+2б», 1-2 км – «+1б», более 2 км – «0б»'),
    )
  ));

  // Школа
  if ((float)$entity->field_complex_infra_rating_schoo['und'][0]['value'] < 1) {

    $vars['infra_rating'][2]['value'] = 2;
    $vars['infra_rating'][2]['text'] = 'до 1 км';
  } else if ((float)$entity->field_complex_infra_rating_schoo['und'][0]['value'] >= 1 &&
              (float)$entity->field_complex_infra_rating_schoo['und'][0]['value'] <= 2){

    $vars['infra_rating'][2]['value'] = 1;
    $vars['infra_rating'][2]['text'] = '1-2 км';
  } else {
    $vars['infra_rating'][2]['value'] = 0;
    $vars['infra_rating'][2]['text'] = 'более 2 км';
  }
  $vars['infra_rating'][2]['title'] = 'Близость к школе';
  $vars['infra_rating'][2]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('До 1 км – «+2б», 1-2 км – «+1б», более 2 км – «0б»'),
    )
  ));

  // Детсад
  if ((float)$entity->field_complex_infra_rating_child['und'][0]['value'] < 1) {

    $vars['infra_rating'][3]['value'] = 2;
    $vars['infra_rating'][3]['text'] = 'до 1 км';
  } else if ((float)$entity->field_complex_infra_rating_child['und'][0]['value'] >= 1 &&
              (float)$entity->field_complex_infra_rating_child['und'][0]['value'] <= 2){

    $vars['infra_rating'][3]['value'] = 1;
    $vars['infra_rating'][3]['text'] = '1-2 км';
  } else {
    $vars['infra_rating'][3]['value'] = 0;
    $vars['infra_rating'][3]['text'] = 'более 2 км';
  }
  $vars['infra_rating'][3]['title'] = 'Близость к школе';
  $vars['infra_rating'][3]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('До 1 км – «+2б», 1-2 км – «+1б», более 2 км – «0б»'),
    )
  ));

  // ТРЦ
  if ((float)$entity->field_complex_infra_rating_trc['und'][0]['value'] < 2) {

    $vars['infra_rating'][4]['value'] = 2;
    $vars['infra_rating'][4]['text'] = 'до 2 км';
  } else if ((float)$entity->field_complex_infra_rating_trc['und'][0]['value'] >= 2 &&
    (float)$entity->field_complex_infra_rating_trc['und'][0]['value'] <= 4){

    $vars['infra_rating'][4]['value'] = 1;
    $vars['infra_rating'][4]['text'] = '2-4 км';
  } else {
    $vars['infra_rating'][4]['value'] = 0;
    $vars['infra_rating'[4]]['text'] = 'более 4 км';
  }
  $vars['infra_rating'][4]['title'] = 'Близость к ТРЦ/крупному продуктовому магазину';
  $vars['infra_rating'][4]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('До 2 км – «+2б», 2-4 км – «+1б», более 4 км – «0б»'),
    )
  ));


  // Автодорога
  if ((float)$entity->field_complex_infra_rating_road['und'][0]['value'] > 100) {

    $vars['infra_rating'][5]['value'] = 2;
    $vars['infra_rating'][5]['text'] = 'более 100 м';
  } else if ((float)$entity->field_complex_infra_rating_road['und'][0]['value'] >= 50 &&
              (float)$entity->field_complex_infra_rating_road['und'][0]['value'] <= 100){

    $vars['infra_rating'][5]['value'] = 1;
    $vars['infra_rating'][5]['text'] = '50-100 м';
  } else {
    $vars['infra_rating'][5]['value'] = 0;
    $vars['infra_rating'][5]['text'] = 'менее 50 м';
  }
  $vars['infra_rating'][5]['title'] = 'Близость к крупной автомобильной дороге';
  $vars['infra_rating'][5]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Более 100 м – «+2б», 50-100 м – «+1б», менее 50 м – «0б»'),
    )
  ));

  // Парк, лесная зона
  if ((float)$entity->field_complex_infra_rating_fores['und'][0]['value'] < 1) {

    $vars['infra_rating'][6]['value'] = 2;
    $vars['infra_rating'][6]['text'] = 'до 1 км';
  } else if ((float)$entity->field_complex_infra_rating_fores['und'][0]['value'] >= 1 &&
              (float)$entity->field_complex_infra_rating_fores['und'][0]['value'] <= 2){
    $vars['infra_rating'][6]['value'] = 1;
    $vars['infra_rating'][6]['text'] = '1-2 км';
  } else {
    $vars['infra_rating'][6]['value'] = 0;
    $vars['infra_rating'][6]['text'] = 'более 2 км';
  }
  $vars['infra_rating'][6]['title'] = 'Близость к парку/лесной зоне/прогулочной зоне';
  $vars['infra_rating'][6]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('До 1 км – «+2б», 1-2 км – «+1б», более 2 км – «0б»'),
    )
  ));


  // Железная дорога
  if ((float)$entity->field_complex_infra_rating_railw['und'][0]['value'] > 100) {

    $vars['infra_rating'][7]['value'] = 2;
    $vars['infra_rating'][7]['text'] = 'более 100 м';
  } else if ((float)$entity->field_complex_infra_rating_railw['und'][0]['value'] >= 50 &&
              (float)$entity->field_complex_infra_rating_railw['und'][0]['value'] <= 100){

    $vars['infra_rating'][7]['value'] = 1;
    $vars['infra_rating'][7]['text'] = '50-100 м';
  } else {
    $vars['infra_rating'][7]['value'] = 0;
    $vars['infra_rating'][7]['text'] = 'менее 50 м';
  }
  $vars['infra_rating'][7]['title'] = 'Близость к железной дороге';
  $vars['infra_rating'][7]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Более 100 м – «+2б», 50-100 м – «+1б», менее 50 м – «0б»'),
    )
  ));

  // ТЭЦ
  if ((float)$entity->field_complex_infra_rating_chp['und'][0]['value'] > 2) {

    $vars['infra_rating'][8]['value'] = 2;
    $vars['infra_rating'][8]['text'] = 'более 2 км';
  } else if ((float)$entity->field_complex_infra_rating_chp['und'][0]['value'] >= 1 &&
              (float)$entity->field_complex_infra_rating_chp['und'][0]['value'] <= 2){

    $vars['infra_rating'][8]['value'] = 1;
    $vars['infra_rating'][8]['text'] = '1-2 км';
  } else {
    $vars['infra_rating'][8]['value'] = 0;
    $vars['infra_rating'][8]['text'] = 'менее 1 км';
  }
  $vars['infra_rating'][8]['title'] = 'Близость к заводам/ТЭЦ';
  $vars['infra_rating'][8]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Более 2 км – «+2б», 1-2 км – «+1б», менее 1 км – «0б»'),
    )
  ));

  // Трамвай
  if ((float)$entity->field_complex_infra_rating_tramv['und'][0]['value'] > 100) {

    $vars['infra_rating'][9]['value'] = 2;
    $vars['infra_rating'][9]['text'] = 'более 100 м';
  } else if ((float)$entity->field_complex_infra_rating_tramv['und'][0]['value'] >= 50 &&
    (float)$entity->field_complex_infra_rating_tramv['und'][0]['value'] <= 100){

    $vars['infra_rating'][9]['value'] = 1;
    $vars['infra_rating'][9]['text'] = '50-100 м';
  } else {
    $vars['infra_rating'][9]['value'] = 0;
    $vars['infra_rating'][9]['text'] = 'менее 50 м';
  }
  $vars['infra_rating'][9]['title'] = 'Близость к трамвайным путям';
  $vars['infra_rating'][9]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Более 100 м – «+2б», 50-100 м – «+1б», менее 50 м – «0б»'),
    )
  ));

  // Рейтинг - Двор/Дом
  $entity = entity_load_single('field_collection_item', array(
    $node_complex->field_complex_yard_rating['und'][0]['value']
  ));

  // Парковка
  if ($entity->field_complex_yard_rating_parkin['und'][0]['value'] == '1') {
    $vars['yard_rating_all'][0]['value'] = 2;
    $vars['yard_rating_all'][0]['text'] = 'Да';
  } else {
    $vars['yard_rating_all'][0]['value'] = 0;
    $vars['yard_rating_all'][0]['text'] = 'Нет';
  }
  $vars['yard_rating_all'][0]['title'] = 'Подземная парковка';
  $vars['yard_rating_all'][0]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Да – «+2б», нет – «0б»'),
    )
  ));

  // Чистовая отделка
  if ($entity->field_complex_yard_rating_fine['und'][0]['value'] == '1') {
    $vars['yard_rating_all'][1]['value'] = 1;
    $vars['yard_rating_all'][1]['text'] = 'Частично';
  } else if ($entity->field_complex_yard_rating_fine['und'][0]['value'] == '2') {
    $vars['yard_rating_all'][1]['value'] = 2;
    $vars['yard_rating_all'][1]['text'] = 'Да';
  } else {
    $vars['yard_rating_all'][1]['value'] = 0;
    $vars['yard_rating_all'][1]['text'] = 'Нет';
  }
  $vars['yard_rating_all'][1]['title'] = 'Чистовая отделка';
  $vars['yard_rating_all'][1]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Нет – «0б», Частично – «+1б», Да – «+2б»'),
    )
  ));

  // Огороденная территория
  if ($entity->field_complex_yard_rating_fenced['und'][0]['value'] == '1') {
    $vars['yard_rating_all'][2]['value'] = 3;
    $vars['yard_rating_all'][2]['text'] = 'Да';
  } else {
    $vars['yard_rating_all'][2]['value'] = 0;
    $vars['yard_rating_all'][2]['text'] = 'Нет';
  }
  $vars['yard_rating_all'][2]['title'] = 'Огороженная территория';
  $vars['yard_rating_all'][2]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Да – «+3б», нет – «0б»'),
    )
  ));

  // Благоустройство двора
  if ($entity->field_complex_yard_rating_landsc['und'][0]['value'] == '1') {
    $vars['yard_rating_all'][3]['value'] = 3;
    $vars['yard_rating_all'][3]['text'] = 'Да';
  } else {
    $vars['yard_rating_all'][3]['value'] = 0;
    $vars['yard_rating_all'][3]['text'] = 'Нет';
  }
  $vars['yard_rating_all'][3]['title'] = 'Благоустройство двора';
  $vars['yard_rating_all'][3]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Да – «+3б», нет – «0б»'),
    )
  ));

  // Высота потолков
  if ((float)$entity->field_complex_yard_rating_height['und'][0]['value'] > 3) {
    $vars['yard_rating_all'][4]['value'] = 3;
    $vars['yard_rating_all'][4]['text'] = str_replace('.',',',$entity->field_complex_yard_rating_height['und'][0]['value']) . 'м';
  } else if ((float)$entity->field_complex_yard_rating_height['und'][0]['value'] >= 2.7 &&
    (float)$entity->field_complex_yard_rating_height['und'][0]['value'] <= 2.9){
    $vars['yard_rating_all'][4]['value'] = 2;
    $vars['yard_rating_all'][4]['text'] = str_replace('.',',',$entity->field_complex_yard_rating_height['und'][0]['value']) . 'м';
  } else {
    $vars['yard_rating_all'][4]['value'] = 0;
    $vars['yard_rating_all'][4]['text'] = str_replace('.',',',$entity->field_complex_yard_rating_height['und'][0]['value']) . 'м';
  }
  $vars['yard_rating_all'][4]['title'] = 'Высота потолков';
  $vars['yard_rating_all'][4]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('3м и выше – «+3б», 2,7-2,99м – «+2б», менее 2,7м – «0б»'),
    )
  ));

  // Охрана
  if ($entity->field_complex_yard_rating_securi['und'][0]['value'] == '1') {
    $vars['yard_rating_all'][5]['value'] = 3;
    $vars['yard_rating_all'][5]['text'] = 'Да';
  } else {
    $vars['yard_rating_all'][5]['value'] = 0;
    $vars['yard_rating_all'][5]['text'] = 'Нет';
  }
  $vars['yard_rating_all'][5]['title'] = 'Охрана';
  $vars['yard_rating_all'][5]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Да – «+3б», нет – «0б»'),
    )
  ));

  // Видеонаблюдение
  if ($entity->field_complex_yard_rating_videov['und'][0]['value'] == '1') {
    $vars['yard_rating_all'][6]['value'] = 2;
    $vars['yard_rating_all'][6]['text'] = 'Да';
  } else {
    $vars['yard_rating_all'][6]['value'] = 0;
    $vars['yard_rating_all'][6]['text'] = 'Нет';
  }
  $vars['yard_rating_all'][6]['title'] = 'Видеонаблюдение';
  $vars['yard_rating_all'][6]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Да – «+2б», нет – «0б»'),
    )
  ));

  // Грузовой лифт
  if ($entity->field_complex_yard_rating_freigh['und'][0]['value'] == '1') {
    $vars['yard_rating_all'][7]['value'] = 2;
    $vars['yard_rating_all'][7]['text'] = 'Да';
  } else {
    $vars['yard_rating_all'][7]['value'] = 0;
    $vars['yard_rating_all'][7]['text'] = 'Нет';
  }
  $vars['yard_rating_all'][7]['title'] = 'Грузовой лифт';
  $vars['yard_rating_all'][7]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Да – «+2б», нет – «0б»'),
    )
  ));

  // Рейтинг - Информационная открытость
  $entity = entity_load_single('field_collection_item', array(
    $node_complex->field_complex_info_rating['und'][0]['value']
  ));

  // Компания готова предоставлять актуальную информацию о квартирах в продаже на независимых ресурсах
  if ($entity->field_complex_info_rating_give['und'][0]['value'] == '1') {
    $vars['info_rating_all'][0]['value'] = 1;
    $vars['info_rating_all'][0]['text'] = '';
    $vars['info_rating_all'][0]['title'] = 'Компания готова предоставлять актуальную информацию о квартирах в продаже на независимых ресурсах';
  } else {
    $vars['info_rating_all'][0]['value'] = 0;
    $vars['info_rating_all'][0]['text'] = '';
    $vars['info_rating_all'][0]['title'] = 'Компания не готова предоставлять актуальную информацию о квартирах в продаже на независимых ресурсах';
  }


  // Сайт объекта
  if ($entity->field_complex_info_rating_site['und'][0]['value'] == '1') {
    $vars['info_rating_all'][1]['value'] = 2;
    $vars['info_rating_all'][1]['text'] = 'Да';
  } else {
    $vars['info_rating_all'][1]['value'] = 0;
    $vars['info_rating_all'][1]['text'] = 'Нет';
  }
  $vars['info_rating_all'][1]['title'] = 'Сайт объекта';
  $vars['info_rating_all'][1]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Да – «+2б», нет – «0б»'),
    )
  ));

  // Заголовок - Документация на сайте
  $vars['info_rating_all'][2]['title'] = '<span style="margin-left: 30px text-transform: uppercase; font-size: 22px; font-family:\'SegoeLight\';color:#eee;margin: 0px;padding: 0px;">Документация на сайте</span>';
  $vars['info_rating_all'][2]['value'] = '';
  $vars['info_rating_all'][2]['text'] = '';


  // Проектная декларация
  if ($entity->field_complex_info_rating_projec['und'][0]['value'] == '1') {
    $vars['info_rating_all'][3]['value'] = 2;
    $vars['info_rating_all'][3]['text'] = '<span style="margin-left: 30px;">Да</span>';
  } else {
    $vars['info_rating_all'][3]['value'] = 0;
    $vars['info_rating_all'][3]['text'] = '<span style="margin-left: 30px;">Нет</span>';
  }
  $vars['info_rating_all'][3]['title'] = '<span style="margin-left: 30px;">Проектная декларация</span>';
  $vars['info_rating_all'][3]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Да – «+2б», нет – «0б»'),
    )
  ));

  // Разрешение на строительство
  if ($entity->field_complex_info_rating_permit['und'][0]['value'] == '1') {
    $vars['info_rating_all'][4]['value'] = 2;
    $vars['info_rating_all'][4]['text'] = '<span style="margin-left: 30px;">Да</span>';
  } else {
    $vars['info_rating_all'][4]['value'] = 0;
    $vars['info_rating_all'][4]['text'] = '<span style="margin-left: 30px;">Нет</span>';
  }
  $vars['info_rating_all'][4]['title'] = '<span style="margin-left: 30px;">Разрешение на строительство</span>';
  $vars['info_rating_all'][4]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Да – «+2б», нет – «0б»'),
    )
  ));

  // Устав компании
  if ($entity->field_complex_info_rating_articl['und'][0]['value'] == '1') {
    $vars['info_rating_all'][5]['value'] = 2;
    $vars['info_rating_all'][5]['text'] = '<span style="margin-left: 30px;">Да</span>';
  } else {
    $vars['info_rating_all'][5]['value'] = 0;
    $vars['info_rating_all'][5]['text'] = '<span style="margin-left: 30px;">Нет</span>';
  }
  $vars['info_rating_all'][5]['title'] = '<span style="margin-left: 30px;">Устав компании</span>';
  $vars['info_rating_all'][5]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Да – «+2б», нет – «0б»'),
    )
  ));

  // Свидетельство о ГРЮЛ
  if ($entity->field_complex_info_rating_grul['und'][0]['value'] == '1') {
    $vars['info_rating_all'][6]['value'] = 1;
    $vars['info_rating_all'][6]['text'] = '<span style="margin-left: 30px;">Да</span>';
  } else {
    $vars['info_rating_all'][6]['value'] = 0;
    $vars['info_rating_all'][6]['text'] = '<span style="margin-left: 30px;">Нет</span>';
  }
  $vars['info_rating_all'][6]['title'] = '<span style="margin-left: 30px;">Свидетельство о ГРЮЛ</span>';
  $vars['info_rating_all'][6]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Да – «+1б», нет – «0б»'),
    )
  ));

  // Страхование
  if ($entity->field_complex_info_rating_insura['und'][0]['value'] == '1') {
    $vars['info_rating_all'][7]['value'] = 2;
    $vars['info_rating_all'][7]['text'] = '<span style="margin-left: 30px;">Да</span>';
  } else {
    $vars['info_rating_all'][7]['value'] = 0;
    $vars['info_rating_all'][7]['text'] = '<span style="margin-left: 30px;">Нет</span>';
  }
  $vars['info_rating_all'][7]['title'] = '<span style="margin-left: 30px;">Генеральный договор страхования гражданской ответственности</span>';
  $vars['info_rating_all'][7]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Да – «+2б», нет – «0б»'),
    )
  ));

  // Заголовок - Информация о квартирах на сайте
  $vars['info_rating_all'][8]['title'] = '<span style="margin-left: 30px text-transform: uppercase; font-size: 22px; font-family:\'SegoeLight\';color:#eee;margin: 0px;padding: 0px;">Информация о квартирах на сайте</span>';
  $vars['info_rating_all'][8]['value'] = '';
  $vars['info_rating_all'][8]['text'] = '';

  // Информация о наличии квартир
  if ($entity->field_complex_info_rating_apartm['und'][0]['value'] == '1') {
    $vars['info_rating_all'][9]['value'] = 1;
    $vars['info_rating_all'][9]['text'] = '<span style="margin-left: 30px;">Да</span>';
  } else {
    $vars['info_rating_all'][9]['value'] = 0;
    $vars['info_rating_all'][9]['text'] = '<span style="margin-left: 30px;">Нет</span>';
  }
  $vars['info_rating_all'][9]['title'] = '<span style="margin-left: 30px;">Информация о наличии квартир</span>';
  $vars['info_rating_all'][9]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Да – «+1б», нет – «0б»'),
    )
  ));

  // Информация о стоимости
  if ($entity->field_complex_info_rating_price['und'][0]['value'] == '1') {
    $vars['info_rating_all'][10]['value'] = 1;
    $vars['info_rating_all'][10]['text'] = '<span style="margin-left: 30px;">Да</span>';
  } else {
    $vars['info_rating_all'][10]['value'] = 0;
    $vars['info_rating_all'][10]['text'] = '<span style="margin-left: 30px;">Нет</span>';
  }
  $vars['info_rating_all'][10]['title'] = '<span style="margin-left: 30px;">Информация о стоимости квартир</span>';
  $vars['info_rating_all'][10]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Да – «+1б», нет – «0б»'),
    )
  ));


  // Подробная планировка каждой квартиры
  if ($entity->field_complex_info_rating_applan['und'][0]['value'] == '1') {
    $vars['info_rating_all'][11]['value'] = 1;
    $vars['info_rating_all'][11]['text'] = '<span style="margin-left: 30px;">Да</span>';
  } else {
    $vars['info_rating_all'][11]['value'] = 0;
    $vars['info_rating_all'][11]['text'] = '<span style="margin-left: 30px;">Нет</span>';
  }
  $vars['info_rating_all'][11]['title'] = '<span style="margin-left: 30px;">Подробная планировка каждой квартиры</span>';
  $vars['info_rating_all'][11]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Да – «+1б», нет – «0б»'),
    )
  ));

  // Подробная планировка каждого этажа
  if ($entity->field_complex_info_rating_flplan['und'][0]['value'] == '1') {
    $vars['info_rating_all'][12]['value'] = 1;
    $vars['info_rating_all'][12]['text'] = '<span style="margin-left: 30px;">Да</span>';
  }
  else {
    $vars['info_rating_all'][12]['value'] = 0;
    $vars['info_rating_all'][12]['text'] = '<span style="margin-left: 30px;">Нет</span>';
  }
  $vars['info_rating_all'][12]['title'] = '<span style="margin-left: 30px;">Подробная планировка каждого этажа</span>';
  $vars['info_rating_all'][12]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Да – «+1б», нет – «0б»'),
    )
  ));

  // Фотоотчет не реже 1 раза в месяц
  if ($entity->field_complex_info_rating_photo['und'][0]['value'] == '1') {
    $vars['info_rating_all'][13]['value'] = 2;
    $vars['info_rating_all'][13]['text'] = '<span style="margin-left: 30px;">Да</span>';
  } else {
    $vars['info_rating_all'][13]['value'] = 0;
    $vars['info_rating_all'][13]['text'] = '<span style="margin-left: 30px;">Нет</span>';
  }
  $vars['info_rating_all'][13]['title'] = '<span style="margin-left: 30px;">Фотоотчет не реже одного раза в месяц</span>';
  $vars['info_rating_all'][13]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Да – «+2б», нет – «0б»'),
    )
  ));

  // web-камера на объекте
  if ($entity->field_complex_info_rating_webcam['und'][0]['value'] == '1') {
    $vars['info_rating_all'][14]['value'] = 2;
    $vars['info_rating_all'][14]['text'] = '<span style="margin-left: 30px;">Да</span>';
  }
  else {
    $vars['info_rating_all'][14]['value'] = 0;
    $vars['info_rating_all'][14]['text'] = '<span style="margin-left: 30px;">Нет</span>';
  }
  $vars['info_rating_all'][14]['title'] = '<span style="margin-left: 30px;">Web-камера на объекте</span>';
  $vars['info_rating_all'][14]['question'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/complex-question-dark.svg',
    'attributes' => array(
      'class' => array('rating-ques rating-hint'),
      'rel' => array('tooltip'),
      'data-placement' => array('left'),
      'title' => array('Да – «+2б», нет – «0б»'),
    )
  ));
}