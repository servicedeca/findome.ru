<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_info_developer_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Info developer'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_info_developer_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_info_developer_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_info_developer');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_info_developer_content_type_theme(&$theme, $plugin) {
  $theme['realty_info_developer'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-info-developer',
  );
}

/**
 * Process variables for realty-info-complex.tpl.php.
 */
function template_preprocess_realty_info_developer(&$vars) {

  $term_developer_id = arg(2);

  $term_developer = taxonomy_term_load($term_developer_id);
  $vars['developer'] = $term_developer;

  $vars['description'] = $term_developer->description;
  $vars['address'] = $term_developer->field_address_developer[LANGUAGE_NONE][0]['value'];
  $vars['phone'] = $term_developer->field_number_phone[LANGUAGE_NONE][0]['value'];
  $vars['email'] = l($term_developer->field_email[LANGUAGE_NONE][0]['value'], 'mailto:' . $term_developer->field_email['und'][0]['value'],
    array(
      'absolute' => TRUE
    )
  );
  $vars['website'] = $term_developer->field_web_site['und'][0]['value'];

  $complexes = views_get_view_result('complex', 'complex_developers', $term_developer_id);

  $index = rand (0, count($complexes) - 1);
  $vars['background'] = '/' . realty_file_directory_path() . '/' . $complexes[$index]->field_field_main_photo[0]['raw']['filename'];

  $cost = realty_analytics_get_max_cost_developer($term_developer_id);
  $vars['max_cost'] = number_format($cost[0]->max_cost, 0, ',', ' ' );
  $vars['min_cost'] = number_format($cost[0]->min_cost, 0, ',', ' ' );

  //Получаем информацию по кооличеству квартир из сохраненных данных
  $count_apartments = db_query("SELECT *
                                FROM realty_analytics_count_apartments
                                WHERE developer_tid = :developer_tid AND complex_nid IS NULL ORDER BY id DESC LIMIT 1",
                                array(':developer_tid' => $term_developer_id))->fetchAll();
  $apartment_active = json_decode($count_apartments[0]->apartment_active, TRUE);
  $apartment_all = json_decode($count_apartments[0]->apartment_all, TRUE);
  $vars['apartments_active'] = array (
    '1' => (int)$apartment_active['1'] + (int)$apartment_active['1с'],
    '2' => (int)$apartment_active['2'] + (int)$apartment_active['2c'],
    '3' => (int)$apartment_active['3'] + (int)$apartment_active['3c'],
    '4_5' => (int)$apartment_active['4'] + (int)$apartment_active['5'],
    'all' => $apartment_active['all']
  );
  $vars['apartments_all'] = $apartment_all['all'];
  $vars['procent_app'] = (int)(((int)$vars['apartments_active']['all'] * 100) / (int)$apartment_all['all']);

  $vars['average_price'] = realty_get_average_price_apartment_developer($term_developer_id);

  $tec_price = (int)str_replace(" ","", $vars['average_price']);

  $date = date('d-m-Y');
  $date = explode('-', $date);
  $date_1 = '1-' . $date['1'] . '-' . $date['2'];
  $date_str = strtotime($date_1);
  $price_1 = db_query("SELECT all_apartments, date
                        FROM realty_analytics_average_price_sq
                        WHERE developer_tid = :developer_tid
                        AND complex_nid IS NULL
                        AND date >= :date ORDER BY id LIMIT 1
                        ", array(':developer_tid' => $term_developer_id, ':date' => $date_str))->fetchAll();

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

  //Кол-во отзывово
  $node_rev = db_query("SELECT field_data_field_review_developer_developer.entity_id
                          FROM field_data_field_review_developer_developer
                          WHERE field_data_field_review_developer_developer.field_review_developer_developer_target_id = :tid",
    array(':tid' => $term_developer_id))->fetchAll();

  if ($node_rev) {
    $rev = realty_get_count_assessmen_review($node_rev[0]->entity_id);
    $vars['review'] = array (
      'positive' => $rev['positive'],
      'negative' => $rev['negative'],
    );
  }
  else {
    $vars['review'] = array (
      'positive' => 0,
      'negative' => 0,
    );
  }


  $vars['bad_finger'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/bad-finger.svg',
      'width' => '40px',
    )
  );

  $vars['good_finger'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/good-finger.svg',
      'width' => '40px',
    )
  );

}