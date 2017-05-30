<?php

/**
 * Implements hook_css_alter().
 */
function realty_theme_css_alter(&$css) {
  unset($css['modules/system/system.menus.css']);
  unset($css['modules/system/system.theme.css']);
}

function realty_theme_html_head_alter(&$head_elements) {
  $head_elements['device_width'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array('name' => 'viewport', 'content' => 'width=device-width'),
  );
}

/**
 * Process variables for page.tpl.php.
 */
function realty_theme_preprocess_html(&$vars, $hook) {
  global $user;

  drupal_add_library('system', 'jquery.cookie');
}

/**
 * Preprocess variables for node.
 */
function realty_preprocess_node(&$vars, $hook) {
  $node = $vars['node'];
  $view_mode = $vars['view_mode'];

  $vars['theme_hook_suggestions'][] = 'node__' . $view_mode;
  $vars['theme_hook_suggestions'][] = 'node__' . $node->type . '_' . str_replace('-', '_', $view_mode);

  $preprocesses[] = 'realty_preprocess_node__' . $view_mode;
  $preprocesses[] = 'realty_preprocess_node__' . $node->type;
  $preprocesses[] = 'realty_preprocess_node__' . $node->type . '_' . str_replace('-', '_', $view_mode);

  foreach ($preprocesses as $preprocess) {
    if (function_exists($preprocess)) {
      $preprocess($vars, $hook);
    }
  }
}

/**
 * Process variables for views-exposed-form.tpl.php.
 */
function realty_preprocess_views_exposed_form(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'realty_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view.tpl.php.
 */
function realty_preprocess_views_view(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'realty_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-unformatted.tpl.php.
 */
function realty_preprocess_views_view_unformatted(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'realty_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-fields.tpl.php.
 */
function realty_preprocess_views_view_fields(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'realty_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-grid.tpl.php.
 */
function realty_preprocess_views_view_grid(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'realty_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-table.tpl.php.
 */
function realty_preprocess_views_view_table(&$vars) {
  if (isset($vars['theme_hook_suggestion'])) {
    $function = 'realty_preprocess_' . $vars['theme_hook_suggestion'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/*
 * Process variables for views-view-unformatted--complex--complexs.tpl.php.
 */
function realty_preprocess_views_view_unformatted__complex__complexs(&$vars) {
  $city_id = arg(2);
  $city = taxonomy_term_load($city_id);
  $vars['city'] = l($city->name, 'taxonomy/term/'.$city->tid);
  $vars['complexes_link'] = l(t('complexes'), 'complexes/city/'.$city->tid);

  foreach($vars['view']->result as $k => $value) {
    $vars['complexes'][$k] = array(
      'name' => $value->node_title,
      'developer' => l($value->field_field_complex_developer[0]['raw']['taxonomy_term']->name, 'taxonomy/term/'. $value->field_field_complex_developer[0]['raw']['tid'],
        array (
          'attributes' => array(
            'target' => '_blank',
            'class' => array(''),
          ),
        )
      ),
      'logo' => theme('image', array(
          'path' => $value->field_field_complex_logo[0]['raw']['uri'],
          'title' => $value->node_title,
        )
      ),
      'complex_link' => drupal_get_path_alias('/node/'. $value->nid, ''),
      'rating' => isset($value->field_field_complex_rating_val[0]['raw']['value']) ?
        $value->field_field_complex_rating_val[0]['raw']['value'] : '0',
    );

    $vars['complexes'][$k]['price'] = realty_get_average_price_apartment_complex($value->nid);
    $vars['complexes'][$k]['apartments'] = realty_get_apartment_active_complex($value->nid);

    $cf = $value->field_field_complex_deadline[0]['raw']['value'];
    $vars['complexes'][$k]['queue'] = $value->field_field_complex_deadline[0]['rendered']['entity']['field_collection_item'][$cf]['field_number_queue'][0]['#markup'];
    $vars['complexes'][$k]['quarter'] = $value->field_field_complex_deadline[0]['rendered']['entity']['field_collection_item'][$cf]['field_queue_quarter'][0]['#markup'];
    $vars['complexes'][$k]['year'] = $value->field_field_complex_deadline[0]['rendered']['entity']['field_collection_item'][$cf]['field_queue_year'][0]['#markup'];

    if (!empty($value->field_field_main_photo)) {
      $vars['complexes'][$k]['photo'] = theme('image', array(
        'path' => $value->field_field_main_photo[0]['raw']['uri'],
        'alt' => $value->node_title,
        'title' => $value->node_title,
      ));
    }

    $vars['complexes'][$k]['complex_id'] = $value->nid;
    $vars['complexes'][$k]['apartment_count'] = realty_get_apartment_active_complex($value->nid);

  }

  $file = REALTY_FRONT_THEME_PATH . '/images/arrow.svg';
  $vars['img_arrow'] = file_get_contents($file);

  $vars['img_starz'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/starz-all.svg',
  ));
}

/*
 * Process variables for views-view-unformatted--complex--complex.tpl.php.
 */
function realty_preprocess_views_view_unformatted__complex__complex(&$vars) {
  $a = 1;
  $image_path = $vars['view']->result[0]->field_field_pano[0]['rendered']['entity']['field_collection_item'][4]['field_image_pano']['#items'][0]['uri'];
  $image_pano =  theme('image_style', array(
      'style_name' => 'medium',
      'path' => $image_path,
      'attributes' => array(
      ),
    )
  );
  $vars['complex'] = array(
    'title' => $vars['view']->result[0]->node_title,
    'area' => $vars['view']->result[0]->field_field_area[0]['rendered']['#title'],
    'developer' => $vars['view']->result[0]->field_field_complex_developer[0]['rendered'],
    'deadline' => $vars['view']->result[0]->field_field_deadline[0]['rendered'],
    'main_photo' => $vars['view']->result[0]->field_field_main_photo[0]['rendered'],
    'body'=> $vars['view']->result[0]->field_body[0]['rendered'],
    'pano' => $vars['view']->result[0]->field_field_pano[0]['rendered']['entity']['field_collection_item'][4]['field_pano_complex']['#items'][0]['value'],
    'image_pano' => l($image_pano,'#modal-pano', array('external' => TRUE,
        'html' =>TRUE,
        'attributes'=> array(
          'data-toggle' => 'modal',
        ),
      )
    ),
  );
}

/*
 * Process variables for views-view-unformatted--complex--gallery-video.tpl.php.
 */
function realty_preprocess_views_view_unformatted__complex__gallery_video(&$vars) {

  $img_cap = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/cap_video.svg',
    )
  );

  foreach ($vars['view']->result[0]->field_field_video as $video) {
    $vars['videos'][] = $video['raw']['video_id'];
  }

  $count = count($vars['videos']);
  for($i = $count; $i < 6; $i++) {
    $vars['caps'][] = '<div class="col-xs-4 gallery-item visual-item">'. $img_cap .'</div>';
  }
}

/*
 * Process variables for views-view-unformatted--term-view--developer-gallery-video.tpl.php.
 */
function realty_preprocess_views_view_unformatted__term_view__developer_gallery_video(&$vars) {

  $img_cap = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/cap_video.svg',
    )
  );

  foreach ($vars['view']->result[0]->field_field_developer_video as $video) {
    $vars['videos'][] = $video['raw']['video_id'];
  }

  $count = count($vars['videos']);
  for($i = $count; $i < 6; $i++) {
    $vars['caps'][] = '<div class="col-xs-4 gallery-item visual-item">'. $img_cap .'</div>';
  }
}

/*
 * Process variables for views-view-unformatted--view-articles--all_articles.tpl.php.
 */
function realty_preprocess_views_view_unformatted__view_articles__all_articles(&$vars) {
  $a=1;

  foreach ($vars['view']->result as $article) {
    $vars['articles'][$article->nid]['title'] = $article->node_title;
    $vars['articles'][$article->nid]['body'] = $article->field_body[0]['rendered']['#markup'];
    $vars['articles'][$article->nid]['image'] = theme('image', array('path' => $article->field_field_article_image[0]['raw']['uri']));
  }
}

/*
 * Process variables for views-view-unformatted--term-view--developers.tpl.php.
 */
function realty_preprocess_views_view_unformatted__term_view__developers(&$vars) {

  $city_id = arg(2);
  $city = taxonomy_term_load($city_id);
  $vars['city'] = l($city->name, 'taxonomy/term/'.$city->tid);
  $vars['developers_link'] = l(t('developers'), 'developers/city/'.$city->tid);

  $vars['img_quest'] = theme('image', array(
          'path' => REALTY_FRONT_THEME_PATH . '/images/quest-main.svg',
      )
  );

  foreach($vars['view']->result as $k => $value){
    $vars['developers'][$k] = array(
      'name' => $value->taxonomy_term_data_name,
      'developer_link' => '/taxonomy/term/'. $value->tid,
    );

    if (!empty($value->field_field_developer_logo)) {
      $vars['developers'][$k]['logo'] = theme('image', array(
          'path' => $value->field_field_developer_logo[0]['raw']['uri'],
        )
      );
    }

    // Поиск средней стоимости квадратного метра
    $query_avg_price = "SELECT AVG(field_data_field_price.field_price_value) AS apartment_avg_price
                        FROM field_data_field_price
                          LEFT JOIN node ON node.nid = field_data_field_price.entity_id
                          LEFT JOIN field_data_field_status ON field_data_field_status.entity_id = node.nid
                          LEFT JOIN field_data_field_apartament_home ON field_data_field_apartament_home.entity_id = node.nid
                          LEFT JOIN field_data_field_home_complex ON field_data_field_home_complex.entity_id = field_data_field_apartament_home.field_apartament_home_tid
                          LEFT JOIN field_data_field_complex_developer ON field_data_field_complex_developer.entity_id = field_data_field_home_complex.field_home_complex_target_id
                        WHERE node.type = 'apartament'
                            AND field_data_field_status.field_status_value = 1
                            AND node.status = 1
                            AND field_data_field_complex_developer.field_complex_developer_tid = :developer_tid";

    $args = array (
      ':developer_tid' => $value->tid,
    );

    $query_avg_price = db_query($query_avg_price, $args)->fetchAll();
    $price_clean = str_replace(" ","", $query_avg_price[0]->apartment_avg_price);
    $price_render = number_format($price_clean, 0, ',', ' ' );
    $vars['developers'][$k]['price_from'] = $price_render;
    $vars['developers'][$k]['apt_count'] = realty_get_apartment_active_developer($value->tid);

    $complexes = views_get_view_result('complex', 'complex_developer', $value->tid);

    // Если Жилые комплексы имеются
    if (count($complexes) > 0) {
      $vars['developers'][$k]['complex_count'] = count($complexes)-2;

      $index = rand(0, count($complexes)-1);

      $vars['developers'][$k]['photo'] = theme('image', array(
        'path' => $complexes[$index]->field_field_main_photo[0]['raw']['uri'],
        'alt' => $complexes[$index]->field_field_main_photo[0]['raw']['alt'],
        'title' => $complexes[$index]->field_field_main_photo[0]['raw']['title'],
      ));

      foreach ($complexes as $key => $val) {
        $vars['developers'][$k]['complexes'][]['complex']= l($val->node_title, 'node/' . $val->nid,
          array (
            'attributes' => array(
              'target' => '_blank',
              'class' => array(''),
            ),
          )
        );
      }
    }
  }

  $file = REALTY_FRONT_THEME_PATH . '/images/arrow.svg';
  $vars['img_arrow'] = file_get_contents($file);
}

/*
 * Process variables for views-view-table--apartments--developer-apartment.tpl.php.
 */
function realty_preprocess_views_view_table__apartments__developer_apartment(&$vars){
  $a = 1;
}

/**
 * Process variables for views-view-unformatted--apartments--apartment-complex.tpl.php.
 */
function realty_preprocess_views_view_unformatted__apartments__apartment_complex(&$vars) {
  global $user;

  $vars['apartment_count'] = $vars['view']->total_rows;

  $account = user_load($user->uid);

  $dindon = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/dingdong.svg',
    'attributes' => array(
      'class' => array('dingdong','z-but'),
    ),
  ));

  $dindon_h = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/dingdongh.svg',
    'attributes' => array(
      'class' => array('dingdong','z-but-h'),
    ),
  ));

  $vars['apt_count'] = $vars['view']->total_rows;

  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $key => $val) {
      $vars['apartments'][$key] = array(
        'nid' => $val->nid,
        'number' => $val->field_field_number_apartament[0]['rendered']['#markup'],
        'apartment_path' => '/node/' . $val->nid,
        'address' => $val->field_field_address_house[0]['rendered']['#markup'],
        'section' => !empty($val->field_field_section) ? $val->field_field_section[0]['rendered']['#markup'] : '',
        'floor' => !empty($val->field_field_apartment_floor) ? $val->field_field_apartment_floor[0]['raw']['value'] : '',
        'room' => !empty($val->field_field_number_rooms) ? $val->field_field_number_rooms[0]['raw']['value'] : '',
        'sq' => !empty($val->field_field_gross_area) ? $val->field_field_gross_area[0]['rendered']['#markup'] : '',
        'home_floor' =>  $val->field_field_number_floor[0]['raw']['value'],
        'price' => !empty($val->field_field_price) ? $val->field_field_price[0]['rendered']['#markup'] :'',
        'coast' => !empty($val->field_field_full_cost) ? $val->field_field_full_cost[0]['rendered']['#markup'] : '',
        'status' => $val->field_field_status[0]['raw']['value'],
        'balkon' => $val->field_field_balcony[0]['raw']['value'],
        'logia' => $val->field_field_loggia[0]['raw']['value'],
      );
      if(!empty($val->field_field_balcony_loggia)) {
        $vars['apartments'][$key]['balcony_loggia'] = $val->field_field_balcony_loggia[0]['raw']['value'];
      }

      $add = theme('image', array(
        'path' => REALTY_FRONT_THEME_PATH . '/images/add.svg',
        'attributes' => array(
          'class' => array('add','z-but'),
        ),
      ));

      $add_h = theme('image', array(
        'path' => REALTY_FRONT_THEME_PATH . '/images/addh.svg',
        'attributes' => array(
          'class' => array('add','z-but-h'),
        ),
      ));
      if ($user->uid != 0) {
        $vars['apartments'][$key]['comparison'] = '<div class="apartment-comparison" data-node-id='.$val->nid.'>' .
          l($add . $add_h , '#href', array(
            'html' => TRUE,
            'external' => TRUE,
            'attributes' => array(
              'title' => t('Add an apartment to Compare'),
              'data-placement' => 'right',
              'rel' => 'tooltip',
            ),
          )) .
          '</div>';

        if($val->field_field_status[0]['raw']['value'] == 0) {
          $vars['apartments'][$key]['dindong'] = '<div class="apartment-signal" data-node-id='.$val->nid.'>'.
            l($dindon . $dindon_h , '#href', array(
              'html' => TRUE,
              'external' => TRUE,
              'attributes' => array(
                'title' => t('Send a notice of withdrawal of the reservation'),
                'data-placement' => 'right',
                'rel' => 'tooltip',
              ),
            )).'</div>';

          if (!empty($val->_field_data['nid']['entity']->field_user_signal)) {
            foreach ($val->_field_data['nid']['entity']->field_user_signal[LANGUAGE_NONE] as $value) {
              if ($value['target_id'] == $user->uid) {

                $dindon_r = theme('image', array(
                  'path' => REALTY_FRONT_THEME_PATH . '/images/dingdongr.svg',
                  'attributes' => array(
                    'class' => array('dingdong'),
                  ),
                ));

                $vars['apartments'][$key]['dindong'] = l($dindon_r , '#href', array(
                  'html' => TRUE,
                  'external' => TRUE,
                  'attributes' => array(
                    'rel' => 'tooltip',
                    'data-placement' => 'right',
                    'title' => t('Notification will be sent to the withdrawal of reservations'),
                  ),
                ));
              }
            }

          }
        }
      }

      else {
        $vars['apartments'][$key]['comparison'] = '<div class="comparison">' .
          l($add . $add_h , '#href', array(
              'html' => TRUE,
              'external' => TRUE,
              'attributes' => array(
                'title' => t('Add an apartment to Compare'),
                'data-placement' => 'right',
                'rel' => 'tooltip',
                'data-toggle' => 'modal',
                'data-target' => '.registration',
              ),
            )
          ) .
          '</div>';

        if($val->field_field_status[0]['raw']['value'] == 0) {
          $vars['apartments'][$key]['dindong'] = '<div>'.
            l($dindon . $dindon_h , '#href', array(
              'html' => TRUE,
              'external' => TRUE,
              'attributes' => array(
                'title' => t('Send a notice of withdrawal of the reservation'),
                'data-placement' => 'right',
                'rel' => 'tooltip',
                'data-toggle' => 'modal',
                'data-target' => '.registration',
              ),
            )).'</div>';
        }
      }

      if (!empty($account->field_apartment_comparison)) {
        foreach ($account->field_apartment_comparison[LANGUAGE_NONE] as $id) {

          if($id['target_id'] == $val->nid ) {

            $add_r = theme('image', array (
              'path' => REALTY_FRONT_THEME_PATH . '/images/ready.svg',
              'attributes' => array(
                'class' => array('add'),
              ),
            ));

            $vars['apartments'][$key]['comparison'] = l($add_r , '#href', array(
              'html' => TRUE,
              'external' => TRUE,
              'attributes' => array(
                'title' => t('Apartment in comparison'),
                'data-placement' => 'right',
                'rel' => 'tooltip',
              ),
            ));

          }
        }
      }
    }
  }
}

/**
 * Process variables for views-view-unformatted--apartments--result-search.tpl.php.
 */
function realty_preprocess_views_view_unformatted__apartments__result_search(&$vars) {
  global $user;
  if ($user->uid != 0) {
    $account = user_load($user->uid);
  }
  $dingdong = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/dingdong.svg',
    'attributes' => array(
      'class' => array('dingdong', 'z-but'),
    ),
  ));
  $dingdongh = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/dingdongh.svg',
    'attributes' => array(
      'class' => array('dingdong', 'z-but-h'),
    ),
  ));

  if (!empty($vars['view']->result)) {

    $vars['apt_count'] = $vars['view']->total_rows;

    foreach ($vars['view']->result as $key => $val) {
      $vars['apartments'][$key] = array(
        'nid' =>  $val->nid,
        'apartment_path' => '/node/' . $val->nid,
        //'number' => l('<div class="flat-number flat-number-booked">' . $val->field_field_number_apartament[0]['raw']['value'] . '</div>',
        //'node/' . $val->nid, array('html'=> TRUE)),
        'number' => $val->field_field_number_apartament[0]['raw']['value'],
        'area' => $val->field_field_area[0]['raw']['taxonomy_term']->name,
        'developer_path' => '/taxonomy/term/'.$val->field_field_complex_developer[0]['raw']['tid'],
        'developer' => $val->field_field_complex_developer[0]['raw']['taxonomy_term']->name,
        'complex' => $val->field_field_home_complex[0]['raw']['entity']->title,
        'complex_path' => '/node/' . $val->field_field_home_complex[0]['raw']['target_id'],
        'address' => $val->field_field_address_house[0]['raw']['value'],
        'quarter' => $val->field_field_home_deadline_quarter[0]['raw']['value'],
        'year' => $val->field_field_home_deadline_year[0]['raw']['value'],
        'rooms' => $val->field_field_number_rooms[0]['raw']['value'],
        'floor' => $val->field_field_apartment_floor[0]['raw']['value'],
        'home_floor' =>  $val->field_field_number_floor[0]['raw']['value'],
        'sq' => $val->field_field_gross_area[0]['raw']['value'],
        'price' => !empty($val->field_field_price) ? $val->field_field_price[0]['rendered']['#markup'] : 0,
        'coast' => !empty($val->field_field_full_cost) ? $val->field_field_full_cost[0]['rendered']['#markup'] : 0,
        'status' => $val->field_field_status[0]['raw']['value'],
        'balkon' => $val->field_field_balcony[0]['raw']['value'],
        'logia' => $val->field_field_loggia[0]['raw']['value'],
        'ceiling' => $val->field_field_apartment_ceiling_height[0]['raw']['value']
      );
      if(!empty($val->field_field_balcony_loggia)) {
        $vars['apartments'][$key]['balcony_loggia'] = $val->field_field_balcony_loggia[0]['raw']['value'];
      }

      $add = theme('image', array(
        'path' => REALTY_FRONT_THEME_PATH . '/images/add.svg',
        'attributes' => array(
          'class' => array('add','z-but'),
        ),
      ));

      $add_h = theme('image', array(
        'path' => REALTY_FRONT_THEME_PATH . '/images/addh.svg',
        'attributes' => array(
          'class' => array('add','z-but-h'),
        ),
      ));

      if ($user->uid != 0) {

        $vars['apartments'][$key]['apartment_comparison'] = '<div class="apartment-comparison" data-node-id='.$val->nid.'>' .
          l($add . $add_h , '#href', array(
            'html' => TRUE,
            'external' => TRUE,
            'attributes' => array(
              'title' => t('Add an apartment to Compare'),
              'data-placement' => 'right',
              'rel' => 'tooltip',
            ),
          )) .
          '</div>';

        foreach ($account->field_apartment_comparison[LANGUAGE_NONE] as $id) {

          if($id['target_id'] == $val->nid ) {

            $add_r = theme('image', array (
              'path' => REALTY_FRONT_THEME_PATH . '/images/ready.svg',
              'attributes' => array(
                'class' => array('add'),
              ),
            ));

            $vars['apartments'][$key]['apartment_comparison']= l($add_r , '#href', array(
                'html' => TRUE,
                'external' => TRUE,
                'attributes' => array(
                  'title' => t('Apartment in comparison'),
                  'data-placement' => 'right',
                  'rel' => 'tooltip',
                ),
              )
            );

          }
        }

        $vars['apartments'][$key]['apartment_signal'] = '<div class="apartment-signal" data-node-id='.$val->nid.'>'.
          l($dingdong . $dingdongh , '#href', array(
              'html' => TRUE,
              'external' => TRUE,
              'attributes' => array(
                'title' => t('Send a notice of withdrawal of the reservation'),
                'data-placement' => 'right',
                'rel' => 'tooltip',
              ),
            )
          ).'</div>';

        if (realty_check_status_apartment_user($user->uid, $val->nid) == TRUE) {

          $dindon_r = theme('image', array(
            'path' => REALTY_FRONT_THEME_PATH . '/images/dingdongr.svg',
            'attributes' => array(
              'class' => array('dingdong'),
            ),
          ));

          $vars['apartments'][$key]['apartment_signal'] = l($dindon_r , '#href', array(
            'html' => TRUE,
            'external' => TRUE,
            'attributes' => array(
              'rel' => 'tooltip',
              'data-placement' => 'right',
              'title' => 'Notification will be sent to the withdrawal of reservations',
            ),
          ));
        }
      }

      else {
        $vars['apartments'][$key]['apartment_comparison'] = '<div class="comparison">' .
          l($add . $add_h , '#href', array(
              'html' => TRUE,
              'external' => TRUE,
              'attributes' => array(
                'title' => t('Add an apartment to Compare'),
                'data-placement' => 'right',
                'rel' => 'tooltip',
                'data-toggle' => 'modal',
                'data-target' => '.registration',
              ),
            )
          ) .
          '</div>';

        $vars['apartments'][$key]['apartment_signal'] = '<div class="">'.
          l($dingdong . $dingdongh , '#href', array(
              'html' => TRUE,
              'external' => TRUE,
              'attributes' => array(
                'title' => t('Send a notice of withdrawal of the reservation'),
                'data-placement' => 'right',
                'rel' => 'tooltip',
                'data-toggle' => 'modal',
                'data-target' => '.registration',
              ),
            )
          ).'</div>';

      }

    }
  }

}

/*
 * theme_pager();
 */

function realty_theme_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total, $theme;

  // Add js code for Ctrl+arrows navigation
  drupal_add_js(drupal_get_path('theme', $theme) . '/js/paginator.js');

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? '←' : NULL), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? '→' : NULL), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));

  $li_first = theme('pager_first', array('text' => 1, 'element' => $element, 'parameters' => $parameters));
  $li_last = theme('pager_last', array('text' => $pager_max, 'element' => $element, 'parameters' => $parameters));

  // First-page link display condition
  $show_first = ($i > 1) ? true : false;

  if ($pager_total[$element] > 1) {
    if ($li_previous) {
      $items[] = array(
        'class' => array('pager-previous'),
        'data' => $li_previous,
      );
    }

    if ($show_first && $li_first) {
      $items[] = array(
        'class' => array('pager-first'),
        'data' => $li_first,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 2) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-current'),
            'data' => '<span>' . $i . '</span>',
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
    }

    // Last-page link display condition
    $show_last = ($pager_max > ($i-1)) ? true : false;

    // End generation.
    if ($show_last && $li_last) {
      $items[] = array(
        'class' => 'pager-last',
        'data' => $li_last,
      );
    }

    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next'),
        'data' => $li_next,
      );
    }
    return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pager')),
    ));
  }
}

/*
 * theme_pager_previous()
 */

function realty_theme_pager_previous($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $interval = $variables['interval'];
  $parameters = $variables['parameters'];
  global $pager_page_array;
  $output = '';

  // If we are anywhere but the first page
  if ($pager_page_array[$element] > 0) {
    $page_new = pager_load_array($pager_page_array[$element] - $interval, $element, $pager_page_array);

    // If the previous page is the first page, mark the link as such.
    if ($page_new[$element] == 0) {
      $output = theme('pager_first', array('text' => $text, 'element' => $element, 'parameters' => $parameters));
    }
    // The previous page is not the first page.
    else {
      $output = theme('pager_link', array('text' => $text, 'page_new' => $page_new, 'element' => $element, 'parameters' => $parameters));
    }
  } elseif ($pager_page_array[$element] == 0) {
    $output = theme('pager_link', array('text' => $text, 'element' => $element, 'parameters' => $parameters));
  }
  return $output;
}

/*
 * theme_pager_next()
 */

function realty_theme_pager_next($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $interval = $variables['interval'];
  $parameters = $variables['parameters'];
  global $pager_page_array, $pager_total;
  $output = '';

  // If we are anywhere but the last page
  if ($pager_page_array[$element] < ($pager_total[$element] - 1)) {
    $page_new = pager_load_array($pager_page_array[$element] + $interval, $element, $pager_page_array);
    // If the next page is the last page, mark the link as such.
    if ($page_new[$element] == ($pager_total[$element] - 1)) {
      $output = theme('pager_last', array('text' => $text, 'element' => $element, 'parameters' => $parameters));
    }
    // The next page is not the last page.
    else {
      $output = theme('pager_link', array('text' => $text, 'page_new' => $page_new, 'element' => $element, 'parameters' => $parameters));
    }
  } elseif ($pager_page_array[$element] == $pager_total[$element] - 1) {
    $output = theme('pager_link', array('text' => $text, 'element' => $element, 'parameters' => $parameters));
  }

  return $output;
}

/**
 * Process variables for search-form.tpl.php
 */
function realty_theme_preprocess_search_form(&$vars) {

  $vars['micro_logo'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/micrologo.png',
    'attributes' => array(
      'class' => array('search-head-logo'),
    ),
  ));

  foreach(realty_get_list_city() as $city) {
    $vars['cities'][] = l($city->name, 'taxonomy/term/'.$city->tid);
  }

  $city = realty_get_current_city();
  $vars['city'] = $city->name;

  unset($vars['form']['masonry']['#title']);
  unset($vars['form']['category']['#title']);
  unset($vars['form']['quarter']['#title']);
  unset($vars['form']['year']['#title']);
  unset($vars['form']['sq']['#title']);
  unset($vars['form']['price']['#title']);
  unset($vars['form']['coast']['#title']);
  unset($vars['form']['parking']['#title']);
  unset($vars['form']['balcony']['#title']);
  unset($vars['form']['floor']['#title']);



}

/**
 * Process variables realty-modal-search-form.tpl.php
 */
function realty_preprocess_realty_modal_search_form(&$vars) {

  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));

  $vars['img_mp'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/mp.svg',
    'attributes' => array(
      'class' => array('mplus'),
    ),

  ));
}

/**
 *  implement hook_theme_registry_alter().
 */
/*function realty_theme_registry_alter(&$theme_registry) {
  $theme_path = path_to_theme();
  // Checkboxes.
 if (isset($theme_registry['checkbox'])) {
    $theme_registry['checkbox']['type'] = 'theme';
    $theme_registry['checkbox']['theme path'] = $theme_path;
    $theme_registry['checkbox']['template'] = $theme_path. '/templates/field--type-checkbox';
    unset($theme_registry['checkbox']['function']);
  }
}*/

function realty_theme_theme_registry_alter(&$theme_registry) {
  global $theme_key;

  $theme_path = path_to_theme();
  $theme_registry['breadcrumb']['theme path'] = $theme_path;

  unset($theme_registry['breadcrumb']['function']);

  $theme_registry['breadcrumb']['template'] = $theme_path . '/templates/realty-breadcrumbs';
  $theme_registry['breadcrumb']['preprocess functions'] = array (
    0 => 'realty_theme_preprocess_realty_breadcrumbs',
  );
}

/**
 * Process variables for realty-developer-page.tpl.php.
 */
function realty_theme_preprocess_realty_user_menu(&$vars) {
  global $user;
  $uid = $user->uid;

  $menu_items = array(
    0 => array(
      'path' => l(t('Profile'), "user/$uid"),
      'title' => 'user',
    ),
    1 => array(
      'path' => l(t('Comparison'), "/comparison"),
      'title' => 'comparison',
    ),
    2 => array(
      'path' => l(t('Get id'), "/apartment_id"),
      'title' => 'apartment_id',
    ),

    3 => array(
      'path' => l(t('Reward'), "/reward"),
      'title' => 'reward',
    ),
  );

  $url = arg(0);
  foreach($menu_items as $key => $item) {
    if($url == $item['title']) {
      $vars['menu'][$key] = '<li class="active-menu">'.$item['path'].'</li>';
      $vars['page'] = $item['path'];
    }
    else {
      $vars['menu'][$key] = '<li>'.$item['path'].'</li>';
    }
  }
}

/**
 * Process variables for realty-user-recovery-password.tpl.php
 */
function realty_theme_preprocess_realty_user_recovery_password(&$vars) {
  $breadcrumb = array('<a href="/">Главная</a>', '<a href="#">Восстановление пароля</a>');
  $vars['breadcrumbs'] = theme('realty_breadcrumbs', array('breadcrumb'=> $breadcrumb));
  $vars['form'] = drupal_get_form('user_pass');
}

/**
 * Process variables for realty-user-reset-password.tpl.php
 */
function realty_theme_preprocess_realty_user_reset_password(&$vars) {
  $breadcrumb = array('<a href="/">Главная</a>', '<a href="#">Восстановление пароля</a>');
  $vars['breadcrumbs'] = theme('realty_breadcrumbs', array('breadcrumb'=> $breadcrumb));
  $vars['form'] = drupal_get_form('user_pass_reset', arg(2), arg(3), arg(4));
}


/**
 * Process variables for realty-breadcumbs.tpl.php.
 */
function realty_theme_preprocess_realty_breadcrumbs (&$vars) {

  switch (arg(2)) {
    case 'plan' : {

      if (arg(0) == 'complexes') {
        $vars['page_title'] = 'План ЖК';
      }
      if (arg(0) == 'apartment') {
        $vars['page_title'] = 'Расположение';
      }

      break;
    }
    case 'stock' : {
      $vars['page_title'] = 'Акции';
      break;
    }
    case 'visualization' : {
      $vars['page_title'] = 'Визуализация';
      break;
    }
    case 'purchase_terms' : {
      $vars['page_title'] = 'Условия покупки';
      break;
    }
    case 'documents' : {
      $vars['page_title'] = 'Документы';
      break;
    }
    case 'gallery' : {
      $vars['page_title'] = 'Галерея';
      break;
    }
    case 'mortgage' : {
      $vars['page_title'] = 'Ипотека';
      break;
    }
    case 'complexes' : {
      $vars['page_title'] = 'Объекты';
    }
  }
}

/**
 * Process variables for field--type-checkbox.tpl.php.
 */
function realty_theme_preprocess_field__type_checkbox(&$vars) {
  $a = 1;
}

/**
 * Process variables for realty-map-complex.tpl.php.
 */
function realty_theme_preprocess_realty_map_complex(&$vars) {

  if ($vars['nid']) {
    $vars['node'] = node_load($vars['nid']);
    $vars['image'] = theme('image', array(
        'path' => $vars['node']->field_main_photo[LANGUAGE_NONE][0]['uri'],
        'attributes' => array(
          'class' => array('title-image'),
        ),
      )
    );

    $vars['logo'] = theme('image', array(
        'path' => $vars['node']->field_complex_logo[LANGUAGE_NONE][0]['uri'],
        'attributes' => array(
          'class' => array('logo-z', 'vertical-logo'),
        ),
      )
    );

    $vars['details'] = l('details', 'node/' . $vars['node']->nid, array(
        'attributes' => array('class' => array('button-info','button-info-top'))
      )
    );

  }
}

/**
 * Process variables for views-view-unformatted--news--news-city.tpl.php
 */
function realty_preprocess_views_view_unformatted__news__news_city(&$vars) {
  $city_tid = arg('2');

  foreach ($vars['view']->result as $key => $value) {
    $vars['news'][$key] = array(
      'title' => $value->node_title,
      'description' => $value->field_field_news_description[0]['raw']['value'],
      'details' => l(t('details'), 'news/city/' . $city_tid, array('query' => array('new-id' => $value->nid))),
      'date' => format_date($value->node_created, 'm/d/Y'),
    );
  }
}

/**
 * Process variables for comment.tpl.php
 */
function realty_theme_preprocess_comment(&$vars) {
  $account = user_load($vars['comment']->uid);
  $vars['comments'] = $vars['comment']->field_body[LANGUAGE_NONE][0]['safe_value'];
  $vars['name'] = $account->name;
  $vars['date'] = gmdate("m-d-Y", $vars['comment']->created);

  $vars['image_finger'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/finger.svg',
    'attributes' => array('class' => array('recall-img')),
  ));
}

/**
 * Process variables for comment_wrapper.tpl.php
 */
function realty_theme_preprocess_comment_wrapper(&$vars) {
  $vars['realty_comment_form'] = drupal_get_form('realty_comment_form');
  unset($vars['content']['comments']['pager']);

}

/**
 * Process variables for comment-form.tpl.php
 */
function realty_theme_preprocess_realty_comment_form(&$vars) {
  $vars['node'] = menu_get_object('node', 1);

  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));

  $vars['image'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/c-pen.svg',
  ));
}

/**
 * Process variables for views-view-unformatted--comments-complex--comments-complex.tpl.php
 */

function realty_preprocess_views_view_unformatted__comments_complex(&$vars) {
  global $user;
  $account = user_load($user->uid);

  $vars['bad_finger'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/bad-finger.svg'
    )
  );

  $vars['good_finger'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/good-finger.svg'
    )
  );

  if (!empty($vars['view']->result)) {
    $developer = db_query("SELECT field_complex_developer_tid
                                FROM field_data_field_complex_developer
                                WHERE field_data_field_complex_developer.entity_id = :nid",
      array(':nid' => $vars['view']->result[0]->comment_nid))->fetchField();

    foreach ($vars['view']->result as $comment) {
      $comment_user = user_load($comment->comment_uid);

      if($comment->_field_data['cid']['entity']->pid == 0) {
        $vars['comments'][$comment->cid]['author'] = $comment_user->field_user_name[LANGUAGE_NONE][0]['value'];
        $vars['comments'][$comment->cid]['date'] = gmdate("m-d-Y", $comment->comment_created);
        $vars['comments'][$comment->cid]['assessment'] = $comment->field_field_comment_assessment[0]['raw']['value'];
        $vars['comments'][$comment->cid]['comment'] = $comment->field_field_body_1  [0]['rendered']['#markup'];
        if (strlen($comment->field_field_body[0]['rendered']['#markup']) > 1300) {
          $vars['comments'][$comment->cid]['long'] = TRUE;
        }

        if (!empty($account->field_user_developer) && $developer == $account->field_user_developer[LANGUAGE_NONE][0]['tid']) {
          $vars['comments'][$comment->cid]['link_answer'] = TRUE;
        }
      }
      else {
        $cid = $comment->_field_data['cid']['entity']->pid;
        $vars['comments'][$cid]['answer'][$comment->cid] = array(
          'author' => $comment_user->field_user_name[LANGUAGE_NONE][0]['value'],
          'date' => gmdate("m-d-Y", $comment->comment_created),
          'assessment' => $comment->field_field_comment_assessment[0]['raw']['value'],
          'comment' =>$comment->field_field_body_1  [0]['rendered']['#markup']
        );
        if (strlen($comment->field_field_body[0]['rendered']['#markup']) > 1300) {
          $vars['comments'][$cid]['answer'][$comment->cid]['long'] = TRUE;
        }
      }
    }
  }
}

/**
 * Process variables for views-view-unformatted--comments-complex--comments-developer.tpl.php
 */

function realty_preprocess_views_view_unformatted__comments_complex__comments_developer(&$vars) {
  global $user;

  $account = user_load($user->uid);

  $vars['bad_finger'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/bad-finger.svg'
    )
  );

  $vars['good_finger'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/good-finger.svg'
    )
  );

  if (!empty($vars['view']->result)) {
    $developer = db_query("SELECT field_review_developer_developer_target_id
                                FROM field_data_field_review_developer_developer
                                WHERE field_data_field_review_developer_developer.entity_id = :nid",
      array(':nid' => $vars['view']->result[0]->comment_nid))->fetchField();

    foreach ($vars['view']->result as $comment) {
      $comment_user = user_load($comment->comment_uid);

      if($comment->_field_data['cid']['entity']->pid == 0) {
        $vars['comments'][$comment->cid]['author'] = $comment_user->field_user_name[LANGUAGE_NONE][0]['value'];
        $vars['comments'][$comment->cid]['date'] = gmdate("m-d-Y", $comment->comment_created);
        $vars['comments'][$comment->cid]['assessment'] = $comment->field_field_comment_assessment[0]['raw']['value'];
        $vars['comments'][$comment->cid]['comment'] = $comment->field_field_body_1  [0]['rendered']['#markup'];
        if (strlen($comment->field_field_body[0]['rendered']['#markup']) > 1300) {
          $vars['comments'][$comment->cid]['long'] = TRUE;
        }

        if (!empty($account->field_user_developer) && $developer == $account->field_user_developer[LANGUAGE_NONE][0]['tid']) {
          $vars['comments'][$comment->cid]['link_answer'] = TRUE;
        }
      }
      else {
        $cid = $comment->_field_data['cid']['entity']->pid;
        $vars['comments'][$cid]['answer'][$comment->cid] = array(
          'author' => $comment_user->field_user_name[LANGUAGE_NONE][0]['value'],
          'date' => gmdate("m-d-Y", $comment->comment_created),
          'assessment' => $comment->field_field_comment_assessment[0]['raw']['value'],
          'comment' =>$comment->field_field_body_1  [0]['rendered']['#markup']
        );
        if (strlen($comment->field_field_body[0]['rendered']['#markup']) > 1300) {
          $vars['comments'][$cid]['answer'][$comment->cid]['long'] = TRUE;
        }
      }
    }
  }
}

/**
 * Preprocess variables for node--apartament-full.tpl.php
 */
function realty_preprocess_node__apartament_full(&$vars) {
  global $user;

  $img_id = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/but2.svg',
    'attributes' => array(
      'class' => array('but1'),
    ),
  ));

  $img_id_h = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/but2h.svg',
      'attributes' => array(
        'class' => array('but1h', 'bankh'),
      ),
    )
  );

  $add = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/but1.svg',
    'attributes' => array(
      'class' => array('but1'),
    ),
  ));

  $addh = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/but1h.svg',
      'attributes' => array(
        'class' => array('but1h', 'comparisonh'),
      ),
    )
  );

  $b33 = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/b33.svg',
      'attributes' => array(
        'class' => array('but1', 'bfix'),
      ),
    )
  );
  $b33h = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/b33h.svg',
      'attributes' => array(
        'class' => array('but1h', 'bfix', 'bookh'),
      ),
    )
  );

  $vars['b22'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/b22.svg',
      'attributes' => array(
        'class' => array('but1', 'bfix'),
      ),
    )
  );
  $vars['b22h'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/b22h.svg',
      'attributes' => array(
        'class' => array('but1h', 'bfix', 'pdfh'),
      ),
    )
  );

  if ($user->uid != 0) {
    $account = user_load($user->uid);
    $vars['name'] = $account->field_user_name[LANGUAGE_NONE][0]['safe_value'];
    if (!empty($account->field_phone_number)) {
      $vars['number'] = $account->field_phone_number[LANGUAGE_NONE][0]['safe_value'];
    }

    $vars['get_id'] = l($img_id . $img_id_h . '<div class="tip-button" id="bank">'.t('Get id apartment').'</div>',
      '#href', array(
        'external' => TRUE,
        'html' => TRUE,
        'attributes' => array(
          'id' => 'download-id-apartment',
          'data-nid-apartment' => $vars['nid'],
          'class' => array(),
        )
      )
    );

    if (realty_checking_apartments_comparison($vars['nid']) == TRUE) {
      $redy = theme('image', array (
          'path' => REALTY_FRONT_THEME_PATH . '/images/ready_comprasion.svg',
          'attributes' => array(
            'class' => array('but1', 'bfix', 'butfix'),
          ),
        )
      );

      $vars['add_comparison'] = '<div class="col-xs-4 ap-button">' . $redy .
        '<div class="ap-text comparison">в сравнении</div></div>';
    }
    else {

      $b11 = theme('image', array(
          'path' => REALTY_FRONT_THEME_PATH . '/images/b11.svg',
          'attributes' => array(
            'class' => array('but1', 'bfix'),
          ),
        )
      );
      $b11h = theme('image', array(
          'path' => REALTY_FRONT_THEME_PATH . '/images/b11h.svg',
          'attributes' => array(
            'class' => array('but1h', 'bfix', 'comparisonh'),
          ),
        )
      );

      $vars['add_comparison'] ='<div class="col-xs-4 ap-button apartment-comparison" data-apartment="1" data-node-id=' . $vars['node']->nid .'>'
        . $b11 . $b11h .
        '<div class="ap-text comparison">сравнить</div>
        </div>';

    }

    if ($vars['field_status'][0]['value'] == 1) {
      $vars['booking'] = '<div class="col-xs-4 ap-button" data-toggle="modal" data-target=".modal_free">' . $b33 . $b33h .
        '<div class="ap-text book">Забронировать</div></div>';
    }
    else {
      $vars['booking'] = '<div class="col-xs-4 ap-button apartment-signal" data-node-id="' . $vars['node']->nid . '">
        <div class="ap-text book">Оповестить о снятии брони</div></div>';
    }
  }

  else {
    $b11 = theme('image', array(
        'path' => REALTY_FRONT_THEME_PATH . '/images/b11.svg',
        'attributes' => array(
          'class' => array('but1', 'bfix'),
        ),
      )
    );
    $b11h = theme('image', array(
        'path' => REALTY_FRONT_THEME_PATH . '/images/b11h.svg',
        'attributes' => array(
          'class' => array('but1h', 'bfix', 'comparisonh'),
        ),
      )
    );

    $vars['add_comparison'] ='<div class="col-xs-4 ap-button" data-toggle="modal" data-target=".registration">'
      . $b11 . $b11h .
      '<div class="ap-text comparison">сравнить</div>
    </div>';

    if ($vars['field_status'][0]['value'] == 1) {
      $vars['booking'] = '<div class="col-xs-4 ap-button" data-toggle="modal" data-target=".registration">' . $b33 . $b33h .
        '<div class="ap-text book">Забронировать</div></div>';
    }
    else {
      $vars['booking'] = '<div class="col-xs-4 ap-button" data-toggle="modal" data-target=".registration">
        <div class="ap-text book">Оповестить о снятии брони</div></div>';
    }

  }

  if ($vars['field_status'][0]['value'] == 1) {

    $path_image = REALTY_FRONT_THEME_PATH . '/images/free.svg';

    $vars['status_text'] = t('The apartment is available');

    $vars['b33'] = theme('image', array(
        'path' => REALTY_FRONT_THEME_PATH . '/images/b33.svg',
        'attributes' => array(
          'class' => array('but1', 'bfix'),
        ),
      )
    );
    $vars['b33h'] = theme('image', array(
        'path' => REALTY_FRONT_THEME_PATH . '/images/b33h.svg',
        'attributes' => array(
          'class' => array('but1h', 'bfix'),
          'id' => 'bookh',
        ),
      )
    );
  }

  else {
    $path_image = REALTY_FRONT_THEME_PATH . '/images/booked.svg';
    $vars['status_text'] = t('The apartment is booked');

    $vars['lock'] = theme('image', array(
        'path' => REALTY_FRONT_THEME_PATH . '/images/lock.svg',
      )
    );

    $call = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/call.svg',
      'attributes' => array(
        'class' => array('but1', 'bad-button-fix'),
      ),
    ));

    $callh = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/callh.svg',
      'attributes' => array(
        'class' => array('but1h', 'bad-button-fix'),
        'id' => 'callh'
      ),
    ));
    if ($user->uid == 0) {
      $vars['link_modal_book'] = '<div class=""АF>'.
        l($call . $callh . '<span class="new-tip-button" id="call">
        '. t('Send notification if your will act') .'
        </span>', '#href', array(
            'external' => TRUE,
            'html' => TRUE,
            'attributes' => array(
              'data-toggle' => 'modal',
              'data-target' => '.registration',
            )
          )
        ).'</div>';
    }
    else {
      $vars['link_modal_book'] = '<div class="apartment-signal" data-apartment="1" data-node-id='.$vars['nid'].'>'.
        l($call . $callh . '<span class="new-tip-button" id="call">
        '. t('Send notification if your will act') .'
        </span>', '#href', array(
            'external' => TRUE,
            'html' => TRUE,
            'attributes' => array(
              'data-toggle' => 'modal',
              'data-target' => '.modal_booking',
            )
          )
        ).'</div>';
    }

    if (realty_check_status_apartment_user($user->uid, $vars['nid']) == TRUE) {
      $call = theme('image', array(
        'path' => REALTY_FRONT_THEME_PATH . '/images/dingdong_big.svg',
        'attributes' => array(
          'class' => array('bad-button-fix'),
        ),
      ));

      $vars['link_modal_book'] = l($call. '<span class="new-tip-button">
        '. t('Send notification if your removed') .'
        </span>', '#href', array(
          'external' => TRUE,
          'html' => TRUE,
          'attributes' => array(
          )
        )
      );
    }

  }

  $img_doc = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/but3.svg',
    'attributes' => array(
      'class' => array('but1'),
    ),
  ));

  $img_doc_h = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/but3h.svg',
    'attributes' => array(
      'class' => array('but1h'),
      'id' => 'documentsh',
    ),
  ));

  $vars['get_doc'] = l($img_doc . $img_doc_h . '<div class="tip-button" id="documents">'.t('Get documents').'</div>',
    '#href', array(
      'external' => TRUE,
      'html' => TRUE,
      'attributes' => array(
        'data-toggle' => 'modal',
        'data-target' => '.modal_docs',
        'class' => array('apartment-comparison'),
      )
    )
  );


  empty($vars['field_plan_apartment']) ? $path_apartment_plan = $vars['field_location_floor'][0]['uri'] :
    $path_apartment_plan = $vars['field_plan_apartment'][0]['uri'];

  $vars['apartment_plan'] = theme('image_style', array(
      'style_name' => 'apartment_plan',
      'path' => $path_apartment_plan,
      'title' => 'plan apartment',
      'attributes' => array(
        'class' => array('apartment-image-vertical'),
      ),
    )
  );

  if (!empty($vars['field_location_home'])) {
    $vars['home_plan'] = theme('image_style', array(
      'style_name' => '960x600',
      'path' => $vars['field_location_home'][0]['uri'],
      'title' => 'plan apartment',
      'attributes' => array(
        'class' => array('apartment-image-vertical'),
      ),
    ));
  }

  if (!empty($vars['field_location_floor'])) {
    $vars['floor_plan'] = theme('image_style', array(
      'style_name' => '960x600',
      'path' => $vars['field_location_floor'][0]['uri'],
      'title' => 'plan apartment',
      'attributes' => array(
        'class' => array('apartment-image-vertical'),
      ),
    ));
  }

  if (!empty($vars['field_apartment_vizual'])) {
    $vars['vizual'] = theme('image_style', array(
      'style_name' => '667x450',
      'path' => $vars['field_apartment_vizual'][0]['uri'],
      'title' => 'plan apartment',
      'attributes' => array(
        'class' => array('apartment-image-vertical'),
      ),
    ));
  }

  $vars['image_status'] = theme('image', array(
      'path' => $path_image,
    )
  );
  $vars['image_close'] = realty_get_image_close();

  $vars['image_doc'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/doc.svg'
  ));


  $vars['address'] = $vars['field_apartament_home'][0]['taxonomy_term']->field_address_house[LANGUAGE_NONE][0]['value'];
  $complex = node_load($vars['field_apartament_home'][0]['taxonomy_term']->field_home_complex[LANGUAGE_NONE][0]['target_id']);

  $vars['background'] = '/' . realty_file_directory_path() . '/' . $complex->field_main_photo[LANGUAGE_NONE][0]['filename'];

  if ($vars['field_status'][0]['value'] == '1') {

  }
  else if ($vars['field_status'][0]['value'] == '0') {

  }

  $logo = theme('image', array(
    'path' => $complex->field_complex_logo['und'][0]['uri'],
    'title' => $complex->field_complex_logo['und'][0]['title'],
    'alt' => $complex->field_complex_logo['und'][0]['alt'],
  ));

  $vars['complex_logo'] = l($logo, 'node/' . $vars['field_apartament_home'][0]['taxonomy_term']->field_home_complex[LANGUAGE_NONE][0]['target_id'],
    array(
      'html' => TRUE,
    )
  );

  $vars['complex'] = l($complex->title, 'node/' . $complex->nid,
    array (
      'attributes' => array(
        'target' => '_blank',
        'class' => array(''),
      ),
    )
  );

  $deadline_year = intval((int)$vars['field_apartament_home'][0]['taxonomy_term']->field_deadline['und'][0]['value'] / 10);
  $deadline_quearter = (int)$vars['field_apartament_home'][0]['taxonomy_term']->field_deadline['und'][0]['value'] % 10;

  $vars['deadline'] = $deadline_quearter . ' квартал 20' . $deadline_year . ' год';

  $area = taxonomy_term_load($complex->field_area[LANGUAGE_NONE][0]['tid']);
  $vars['area'] = $area->name;
  $developer = taxonomy_term_load($complex->field_complex_developer[LANGUAGE_NONE][0]['tid']);
  $vars['developer'] = l($developer->name, 'taxonomy/term/' . $developer->tid,
    array (
      'attributes' => array(
        'target' => '_blank',
        'class' => array(''),
      ),
    )
  );

  $vars['cieling_height'] = $vars['field_apartment_ceiling_height']['und'][0]['value'];

  $vars['full_cost'] = $vars['field_full_cost'][LANGUAGE_NONE][0]['value'];

  $vars['image_man'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/c-man.svg'
    )
  );

  $vars['image_phone'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/c-phone.svg'
    )
  );

  if ($vars['node']->status == 0) {
    $vars['out'] = theme('image', array(
        'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/out.svg'
      )
    );
  }

  foreach ($developer->field_banks[LANGUAGE_NONE] as $key => $bank_tid) {
    $bank_term = taxonomy_term_load($bank_tid['tid']);

    $bank_logo = theme('image', array(
        'path' => $bank_term->field_logo['und'][0]['uri'],
        'height' => '100%',
      )
    );

    $vars['banks'][$key]['tid'] = $bank_tid['tid'];

    $vars['banks'][$key]['logo'] = l($bank_logo,
      $bank_term->field_website['und'][0]['value'], array(
        'html' => TRUE,
        'title' => $bank_term->name,
        'attributes' => array(
          'target' => '_blank',
          'class' => array('col-xs-6 payment-item-left'),
        ),
      ));
  }

  drupal_add_js(array(
    'current_home_id' => $vars['field_apartament_home'][0]['tid'],
    'current_section_id' => $vars['field_section'][0]['value'],
    'current_floor_value' => $vars['node']->field_apartment_floor['und'][0]['value'],
    'current_apartment_id' => arg(1)
  ), 'setting');

  $vars['home_id'] = $vars['field_apartament_home'][0]['tid'];
  $vars['complex_id'] = $vars['field_apartament_home'][0]['taxonomy_term']->field_home_complex['und'][0]['target_id'];

  $term_home = taxonomy_term_load($vars['field_apartament_home'][0]['tid']);

  $vars['section'] = $vars['field_section'][0]['value'];
  $vars['home'] = $term_home->field_number_home['und'][0]['value'];

  $term_material = taxonomy_term_load($term_home->field_material['und'][0]['tid']);
  $vars['material'] = $term_material->name;

  $node = node_load($vars['complex_id']);
  if (!empty($node->field_plan_complex)) {
    $file = realty_file_directory_path() . '/' . $node->field_plan_complex[LANGUAGE_NONE][0]['filename'];
    $vars['complex_plan'] = file_get_contents($file);
  }

  $vars['modal'] = theme('realty_apartment_modal', array('plan' => TRUE ));

  $file = REALTY_FRONT_THEME_PATH . '/images/cmp_hover.svg';
  $vars['img_hover'] = file_get_contents($file);

  $vars['img_flat_legend'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/flat-legend.svg'
    )
  );
}

/**
 * Preprocess variables for views-view-unformatted--term-view--bank-list.tpl.php
 */
function realty_preprocess_views_view_unformatted__term_view__bank_list(&$vars) {
  global $user;

  $vars['user'] = $user;

  $vars['img_bt'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/bt.svg',
      'attributes' => array(
        'class' => 'bank-triangle'
      )
    )
  );

  $vars['img_bankq'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/bank-q.svg',
    )
  );

  // Если это главная страница Ипотеки
  if (arg(0) == 'mortgage') {
    // То выводим заголок Ипотеки
    $vars['wrapper'] = TRUE;
  }
  else {
    // Иначе не выводим заголовок
    $vars['wrapper'] = FALSE;
  }

  // Формирование массива банков
  foreach($vars['view']->result as $bank) {

    // Формирование логотипа
    $vars['banks'][$bank->tid]['logo'] = theme('image', array(
      'path' => $bank->field_field_logo[0]['raw']['uri'],
    ));

    if (isset($_GET['p']) && $bank->tid == $_GET['p']) {
      $vars['banks'][$bank->tid]['class'] = 'active';
      $vars['bank_active'] = TRUE;
    }

    // Формирование ипотечной программы банка
    $mortgage_programs = &$bank->field_field_bank_mortgage_program;

    // Перебор ипотек банка
    foreach ($mortgage_programs as $program) {


      // Извлечение entity id ипотеки
      $program_entity = $program['raw']['value'];

      /*** Формирование массива для раздела Банки ***/

      $vars['banks'][$bank->tid]['program'][$program_entity]['id'] = $program_entity;

      // Извлечение Названия ипотеки
      $vars['banks'][$bank->tid]['program'][$program_entity]['name'] = $program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_name']['#items'][0]['value'];

      // Извлечение Сводной информации
      $program_summary_entity = $program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_summary']['#items'][0]['value'];

      // Извлечение Ставки
      $vars['banks'][$bank->tid]['program'][$program_entity]['rate'] = $program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_summary'][0]['entity']['field_collection_item'][$program_summary_entity]['field_bank_mp_sum_rate']['#items'][0]['value'];

      // Извлечение Суммы кредита
      $vars['banks'][$bank->tid]['program'][$program_entity]['amount_max'] = $program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_summary'][0]['entity']['field_collection_item'][$program_summary_entity]['field_bank_mp_sum_amount']['#items'][0]['value'];

      // Извлечение Первоначального взноса
      $vars['banks'][$bank->tid]['program'][$program_entity]['payment_min'] = $program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_summary'][0]['entity']['field_collection_item'][$program_summary_entity]['field_bank_mp_sum_payment']['#items'][0]['value'];

      // Извлечение Срока кредита
      $vars['banks'][$bank->tid]['program'][$program_entity]['period_max'] = $program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_summary'][0]['entity']['field_collection_item'][$program_summary_entity]['field_bank_mp_sum_period']['#items'][0]['value'];


      /*** Формирование массива для раздела Ипотечные программы ***/

      //[категория ипотеки][название банка][название ипотека][параметр]

      // ID банка
      $vars['categories'][$program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_category']['#items'][0]['taxonomy_term']->name][$bank->_field_data['tid']['entity']->name][$program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_name']['#items'][0]['value']]['bankId'] = $bank->tid;

      // Ставка
      $vars['categories'][$program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_category']['#items'][0]['taxonomy_term']->name][$bank->_field_data['tid']['entity']->name][$program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_name']['#items'][0]['value']]['rate'] = $vars['banks'][$bank->tid]['program'][$program_entity]['rate'];

      // Срок кредита
      $vars['categories'][$program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_category']['#items'][0]['taxonomy_term']->name][$bank->_field_data['tid']['entity']->name][$program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_name']['#items'][0]['value']]['period_max'] = $vars['banks'][$bank->tid]['program'][$program_entity]['period_max'];

      // Первоначальный взнос
      $vars['categories'][$program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_category']['#items'][0]['taxonomy_term']->name][$bank->_field_data['tid']['entity']->name][$program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_name']['#items'][0]['value']]['payment_min'] = $vars['banks'][$bank->tid]['program'][$program_entity]['payment_min'];

      // Сумма кредита
      $vars['categories'][$program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_category']['#items'][0]['taxonomy_term']->name][$bank->_field_data['tid']['entity']->name][$program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_name']['#items'][0]['value']]['amount_max'] = $vars['banks'][$bank->tid]['program'][$program_entity]['amount_max'];

      // ID ипотеки
      $vars['categories'][$program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_category']['#items'][0]['taxonomy_term']->name][$bank->_field_data['tid']['entity']->name][$program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_name']['#items'][0]['value']]['id'] = $program_entity;

      // ID категории ипотеки
      $vars['categories'][$program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_category']['#items'][0]['taxonomy_term']->name][$bank->_field_data['tid']['entity']->name][$program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_name']['#items'][0]['value']]['category_id'] = $program['rendered']['entity']['field_collection_item'][$program_entity]['field_bank_mp_category']['#items'][0]['tid'];
    }
  }
}

/**
 * Preprocess variables for views-view-unformatted--term-view--bank-list.tpl.php
 */
function realty_preprocess_views_view_unformatted__field_collection__current_mortgage(&$vars) {
  global $user;

  // Иначе не выводим заголовок
  $vars['wrapper'] = FALSE;
  $vars['user'] = $user;

  $vars['img_bt'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/bt.svg',
      'attributes' => array(
        'class' => 'bank-triangle'
      )
    )
  );

  $vars['img_bankq'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/bank-q.svg',
    )
  );

  // Формирование массива банков
  foreach($vars['view']->result as $mortgage) {

    $bankId = $mortgage->field_bank_mortgage_program_field_collection_item_tid;
    $bankName = $mortgage->field_bank_mortgage_program_field_collection_item_name;

    $mortgageId = $mortgage->item_id;
    $mortgageName = $mortgage->field_field_bank_mp_name[0]['raw']['value'];

    $mortgageCategoryId = $mortgage->field_field_bank_mp_category[0]['raw']['tid'];
    $mortgageCategoryName = $mortgage->field_field_bank_mp_category[0]['raw']['taxonomy_term']->name;

    // Формирование логотипа
    $vars['banks'][$bankId]['logo'] = theme('image', array(
      'path' => $mortgage->field_field_logo[0]['raw']['uri'],
    ));

    // ID ипотечной программы
    $vars['banks'][$bankId]['program'][$mortgageId]['id'] = $mortgageId;

    // Извлечение Названия ипотеки
    $vars['banks'][$bankId]['program'][$mortgageId]['name'] = $mortgage->field_field_bank_mp_name[0]['raw']['value'];

    // Извлечение Сводной информации
    $program_summary_entity = $mortgage->field_field_bank_mp_summary[0]['raw']['value'];

    // Извлечение Ставки
    $vars['banks'][$bankId]['program'][$mortgageId]['rate'] = $mortgage->field_field_bank_mp_summary[0]['rendered']['entity']['field_collection_item'][$program_summary_entity]['field_bank_mp_sum_rate']['#items'][0]['value'];

    // Извлечение Суммы кредита
    $vars['banks'][$bankId]['program'][$mortgageId]['amount_max'] = $mortgage->field_field_bank_mp_summary[0]['rendered']['entity']['field_collection_item'][$program_summary_entity]['field_bank_mp_sum_amount']['#items'][0]['value'];

    // Извлечение Первоначального взноса
    $vars['banks'][$bankId]['program'][$mortgageId]['payment_min'] = $mortgage->field_field_bank_mp_summary[0]['rendered']['entity']['field_collection_item'][$program_summary_entity]['field_bank_mp_sum_payment']['#items'][0]['value'];

    // Извлечение Срока кредита
    $vars['banks'][$bankId]['program'][$mortgageId]['period_max'] = $mortgage->field_field_bank_mp_summary[0]['rendered']['entity']['field_collection_item'][$program_summary_entity]['field_bank_mp_sum_period']['#items'][0]['value'];

    /*** Формирование массива для раздела Ипотечные программы ***/

    //[категория ипотеки][название банка][название ипотека][параметр]

    // ID банка
    $vars['categories'][$mortgageCategoryName][$bankName][$mortgageName]['bankId'] = $bankId;

    // Ставка
    $vars['categories'][$mortgageCategoryName][$bankName][$mortgageName]['rate'] = $vars['banks'][$bankId]['program'][$mortgageId]['rate'];

    // Срок кредита
    $vars['categories'][$mortgageCategoryName][$bankName][$mortgageName]['period_max'] = $vars['banks'][$bankId]['program'][$mortgageId]['period_max'];

    // Первоначальный взнос
    $vars['categories'][$mortgageCategoryName][$bankName][$mortgageName]['payment_min'] = $vars['banks'][$bankId]['program'][$mortgageId]['payment_min'];

    // Сумма кредита
    $vars['categories'][$mortgageCategoryName][$bankName][$mortgageName]['amount_max'] = $vars['banks'][$bankId]['program'][$mortgageId]['amount_max'];

    // ID ипотеки
    $vars['categories'][$mortgageCategoryName][$bankName][$mortgageName]['id'] = $mortgageId;

    // ID категории ипотеки
    $vars['categories'][$mortgageCategoryName][$bankName][$mortgageName]['category_id'] = $mortgageCategoryId;
  }
}

/**
 * Preprocess variables for views-view-unformatted--complex--gallery-photo.tpl.php.
 */
function realty_preprocess_views_view_unformatted__complex__gallery_photo(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $key => $album) {
      if (isset($album->field_field_image_gallery[0])) {
        $vars['albums'][$key]['title'] = $album->field_field_name_gallery[0]['raw']['value'];


        $image_album = theme('image', array(
            'path' => $album->field_field_image_gallery[0]['raw']['uri'],
            'width' => '100%',
            'height' => '100%',
            'attributes' => array(
              'class' => array('thump-gallery'),
            ),
          )
        );

        $vars['albums'][$key]['image_album'] = l($image_album,
          file_create_url($album->field_field_image_gallery[0]['raw']['uri']), array(
            'html' => TRUE,
            'title' => $album->field_field_image_gallery[0]['raw']['title'],
            'attributes' => array(
            )
          )
        );
        foreach ($album->field_field_image_gallery as $photo) {
          $vars['albums'][$key]['photos'][] = l('',file_create_url($photo['raw']['uri']), array(
            'title' => $photo['raw']['title'],
          ));
        }
      }
    }
  }
  $img_cap = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/cap_photo.svg',
    )
  );

  $count = count($vars['albums']);
  for($i = $count; $i < 6; $i++) {
    $vars['caps'][] = '<div class="col-xs-4 gallery-item visual-item">'. $img_cap .'<p></p></div>';
  }
}

/*
 * Preprocess variables views-view-unformatted--complex--gallery-visualization.tpl.php.
 */
function realty_preprocess_views_view_unformatted__complex__gallery_visualization(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result[0]->field_field_visualization as $val) {
      $photo = theme('image', array(
          'path' => $val['raw']['uri'],
          'width' => '100%',
          'height' => '100%',
        )
      );
      $vars['photos'][] = l($photo, file_create_url($val['raw']['uri']), array(
        'html' => TRUE,
        'attributes' => array(
        ),
      ));
    }
  }

  $img_cap = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/cap_photo.svg',
    )
  );

  $count = count($vars['photos']);
  for($i = $count; $i < 6; $i++) {
    $vars['caps'][] = '<div class="col-xs-4 gallery-item visual-item">'. $img_cap .'</div>';
  }


  $nid = arg(1);
  $node = node_load($nid);

  $vars['background'] = '/' . realty_file_directory_path() . '/' . $node->field_main_photo[LANGUAGE_NONE][0]['filename'];
}

/**
 * Preprocess variables views-view-unformatted--complex--gallery-tours.tpl.php.
 */
function realty_preprocess_views_view_unformatted__complex__gallery_tours(&$vars) {
  if (!empty($vars['view']->result)) {
    $vars['image_pano'] = theme('image', array(
      'path' => $vars['view']->result[0]->field_field_image_pano[0]['raw']['uri'],
    ));
    $vars['pano'] = $vars['view']->result[0]->field_field_pano_complex[0]['raw']['value'];
  }
  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));
}

/**
 * Preprocess variables views-view-unformatted--complex--complex-documents.tpl.php.
 */
function realty_preprocess_views_view_unformatted__complex__complex_documents(&$vars) {
  if (!empty($vars['view']->result[0]->field_field_title)) {
    foreach ($vars['view']->result as $document) {
      $vars['documents'][] = array(
        'title' => $document->field_field_title[0]['rendered']['#markup'],
        'link_download' => l(t('Посмотреть'), file_create_url($document->field_field_document[0]['raw']['uri'])),
      );
    }
  }

  $nid = arg(1);
  if(arg(0) == 'apartment') {
    $apartment_info = realty_get_info_apartment($nid);
    $complex_id = $apartment_info['complex_nid'];
    $node = node_load($complex_id);
  }
  else {
    $node = node_load($nid);
  }

  $vars['background'] = '/' . realty_file_directory_path() . '/' . $node->field_main_photo[LANGUAGE_NONE][0]['filename'];

  $vars['image'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/doc.svg'
  ));
}

/**
 * Preprocess variables views-view-unformatted--stock--stock-complex.tpl.php.
 */
function realty_preprocess_views_view_unformatted__stock__stock_complex(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $key => $stock) {
      $vars['stocks'][$key] = array(
        'title' => $stock->node_title,
        'description' => $stock->field_body[0]['rendered']['#markup'],
        'nid' => $stock->nid
      );
      if (!empty($stock->field_field_image)) {
        $vars['stocks'][$key]['image'] = theme('image', array(
          'path' => $stock->field_field_image[0]['raw']['uri'],
        ));
      }
    }
  }
  $vars['img_stock'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/stock.svg');

  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));

  $nid = arg(1);
  $node = node_load($nid);

  $vars['background'] = '/' . realty_file_directory_path() . '/' . $node->field_main_photo[LANGUAGE_NONE][0]['filename'];
}

/**
 * Preprocess variables views-view-unformatted--term-view--developer.tpl.php.
 */
function realty_preprocess_views_view_unformatted__term_view__developer(&$vars) {

  $vars['img_close'] = realty_get_image_close();
  $vars['findome_logo'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/findome-gray.svg',
    'attributes' => array(
      'class' => array('margin-left-15')
    )));
}

/**
 * Preprocess variables views-view-unformatted--apartments--apartment-developer.tpl.php.
 */
function realty_preprocess_views_view_unformatted__apartments__apartment_developer(&$vars) {
  global $user;
  $vars['apartment_count'] = $vars['view']->total_rows;

  $account = user_load($user->uid);

  $dindon = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/dingdong.svg',
    'attributes' => array(
      'class' => array('dingdong','z-but'),
    ),
  ));

  $dindon_h = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/dingdongh.svg',
    'attributes' => array(
      'class' => array('dingdong','z-but-h'),
    ),
  ));

  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $key => $val) {
      $vars['apartments'][$key] = array(
        /*'number' => l('<div class="flat-number flat-number-booked">'
          .$val->field_field_number_apartament[0]['rendered']['#markup'].'</div>', 'node/' . $val->nid, array(
            'attributes' => array(
              'title' => t('View apartment'),
            ),
            'html' => TRUE,
        )),
        */
        'nid' => $val->nid,
        'number' => $val->field_field_number_apartament[0]['rendered']['#markup'],
        'apartment_path' => '/node/' . $val->nid,
        'complex' => $val->node_field_data_field_home_complex_title,
        'complex_path' => '/node/' . $val->node_field_data_field_home_complex_nid,
        'address' => !empty($val->field_field_address_house) ? $val->field_field_address_house[0]['rendered']['#markup'] : 0,
        'section' => !empty($val->field_field_section) ? $val->field_field_section[0]['rendered']['#markup'] : '',
        'floor' => !empty($val->field_field_apartment_floor) ? $val->field_field_apartment_floor[0]['raw']['value'] : '',
        'room' => !empty($val->field_field_number_rooms) ? $val->field_field_number_rooms[0]['raw']['value'] : '',
        'sq' => !empty($val->field_field_gross_area) ? $val->field_field_gross_area[0]['rendered']['#markup'] : 0,
        'home_floor' => !empty($val->field_field_number_floor) ? $val->field_field_number_floor[0]['raw']['value'] : 0,
        'price' => !empty($val->field_field_price) ? $val->field_field_price[0]['rendered']['#markup'] : 0,
        'coast' => !empty($val->field_field_full_cost) ? $val->field_field_full_cost[0]['rendered']['#markup'] : 0,
        'status' => $val->field_field_status[0]['raw']['value'],
        'balkon' => $val->field_field_balcony[0]['raw']['value'],
        'logia' => $val->field_field_loggia[0]['raw']['value'],
      );

      if(!empty($val->field_field_balcony_loggia)) {
        $vars['apartments'][$key]['balcony_loggia'] = $val->field_field_balcony_loggia[0]['raw']['value'];
      }

      $add = theme('image', array(
        'path' => REALTY_FRONT_THEME_PATH . '/images/add.svg',
        'attributes' => array(
          'class' => array('add','z-but'),
        ),
      ));

      $add_h = theme('image', array(
        'path' => REALTY_FRONT_THEME_PATH . '/images/addh.svg',
        'attributes' => array(
          'class' => array('add','z-but-h'),
        ),
      ));
      if ($user->uid != 0) {
        $vars['apartments'][$key]['comparison'] = '<div class="apartment-comparison" data-node-id='.$val->nid.'>' .
          l($add . $add_h , '#href', array(
            'html' => TRUE,
            'external' => TRUE,
            'attributes' => array(
              'title' => t('Add an apartment to Compare'),
              'data-placement' => 'right',
              'rel' => 'tooltip',
            ),
          )) .
          '</div>';

        if($val->field_field_status[0]['raw']['value'] == 0) {
          $vars['apartments'][$key]['dindong'] = '<div class="apartment-signal" data-node-id='.$val->nid.'>'.
            l($dindon . $dindon_h , '#href', array(
              'html' => TRUE,
              'external' => TRUE,
              'attributes' => array(
                'title' => t('Send a notice of withdrawal of the reservation'),
                'data-placement' => 'right',
                'rel' => 'tooltip',
              ),
            )).'</div>';

          if (!empty($val->_field_data['nid']['entity']->field_user_signal)) {
            foreach ($val->_field_data['nid']['entity']->field_user_signal[LANGUAGE_NONE] as $value) {
              if ($value['target_id'] == $user->uid) {

                $dindon_r = theme('image', array(
                  'path' => REALTY_FRONT_THEME_PATH . '/images/dingdongr.svg',
                  'attributes' => array(
                    'class' => array('dingdong'),
                  ),
                ));

                $vars['apartments'][$key]['dindong'] = l($dindon_r , '#href', array(
                  'html' => TRUE,
                  'external' => TRUE,
                  'attributes' => array(
                    'rel' => 'tooltip',
                    'data-placement' => 'right',
                    'title' => t('Notification will be sent to the withdrawal of reservations'),
                  ),
                ));
              }
            }

          }
        }
      }

      else {
        $vars['apartments'][$key]['comparison'] = '<div class="comparison">' .
          l($add . $add_h , '#href', array(
              'html' => TRUE,
              'external' => TRUE,
              'attributes' => array(
                'title' => t('Add an apartment to Compare'),
                'data-placement' => 'right',
                'rel' => 'tooltip',
                'data-toggle' => 'modal',
                'data-target' => '.registration',
              ),
            )
          ) .
          '</div>';

        if($val->field_field_status[0]['raw']['value'] == 0) {
          $vars['apartments'][$key]['dindong'] = '<div>'.
            l($dindon . $dindon_h , '#href', array(
              'html' => TRUE,
              'external' => TRUE,
              'attributes' => array(
                'title' => t('Send a notice of withdrawal of the reservation'),
                'data-placement' => 'right',
                'rel' => 'tooltip',
                'data-toggle' => 'modal',
                'data-target' => '.registration',
              ),
            )).'</div>';
        }
      }

      if (!empty($account->field_apartment_comparison)) {
        foreach ($account->field_apartment_comparison[LANGUAGE_NONE] as $id) {

          if($id['target_id'] == $val->nid ) {

            $add_r = theme('image', array (
              'path' => REALTY_FRONT_THEME_PATH . '/images/ready.svg',
              'attributes' => array(
                'class' => array('add'),
              ),
            ));

            $vars['apartments'][$key]['comparison'] = l($add_r , '#href', array(
              'html' => TRUE,
              'external' => TRUE,
              'attributes' => array(
                'title' => t('Apartment in comparison'),
                'data-placement' => 'right',
                'rel' => 'tooltip',
              ),
            ));

          }
        }
      }
    }
  }
}

/**
 * Process variables for views-view-unformatted--complex--complex-developer.tpl.php.
 */
function realty_preprocess_views_view_unformatted__complex__complex_developer(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $key => $val) {
      $logo = theme('image', array(
        'path' => $val->field_field_complex_logo[0]['raw']['uri'],
        'title' => $val->node_title,
        'alt' => $val->node_title,
      ));
      $vars['complexes'][] = l($logo, '/node/' . $val->nid, array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('col-xs-4', 'develop-complex-item'),
        ),
      ));
    }
  }
}

/**
 * Process variables for views-view-unformatted--complexes-archiv--archiv-complexes-developer.tpl.php.
 */
function realty_preprocess_views_view_unformatted__complexes_archiv__archiv_complexes_developer(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $key => $val) {
      $logo = theme('image', array(
        'path' => $val->field_field_archiv_complex_logo[0]['raw']['uri'],
        'title' => $val->node_title,
        'alt' => $val->node_title,
      ));
      $vars['complexes'][] = l($logo, '/node/' . $val->nid, array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('col-xs-4', 'develop-complex-item'),
        ),
      ));
    }
  }
}

/**
 * Process variables for views-view-unformatted--term-view--developer-gallery.tpl.php.
 */
function realty_preprocess_views_view_unformatted__term_view__developer_gallery(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $key => $album) {
      if (isset($album->field_field_developer_gallery_image[0])) {
        $vars['albums'][$key]['title'] = $album->field_field_developer_gallery_title[0]['raw']['value'];

        $image_album = theme('image', array(
            'path' => $album->field_field_developer_gallery_image[0]['raw']['uri'],
            'width' => '100%',
            'height' => '100%',
          )
        );

        $vars['albums'][$key]['image_album'] = l($image_album,
          file_create_url($album->field_field_developer_gallery_image[0]['raw']['uri']), array(
            'html' => TRUE,
            'title' => $album->field_field_developer_gallery_image[0]['raw']['title'],
            'attributes' => array(
            )
          )
        );

        foreach ($album->field_field_developer_gallery_image as $photo) {
          $vars['albums'][$key]['photos'][] = l('',file_create_url($photo['raw']['uri']), array(
              'title' => $photo['raw']['title'],
            )
          );
        }
      }
    }
  }
  $img_cap = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/cap_photo.svg',
    )
  );

  $count = count($vars['albums']);
  for($i = $count; $i < 6; $i++) {
    $vars['caps'][] = '<div class="col-xs-4 gallery-item visual-item">'. $img_cap .'<p></p></div>';
  }
}

/**
 * Process variables views-view-unformatted--stock--stock-developer.tpl.php.
 */
function realty_preprocess_views_view_unformatted__stock__stock_developer(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $key => $stock) {
      $vars['stocks'][$key] = array(
        'title' => $stock->node_title,
        'description' => $stock->field_body[0]['rendered']['#markup'],
        'nid' => $stock->nid
      );
      if (!empty($stock->field_field_image)) {
        $vars['stocks'][$key]['image'] = theme('image', array(
          'path' => $stock->field_field_image[0]['raw']['uri'],
        ));
      }
    }
  }

  $vars['img_stock'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/stock.svg');
}

/**
 * Process variables views-view-unformatted--stock--all-stock-city.tpl.php
 */
function realty_preprocess_views_view_unformatted__stock__all_stock_city(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $stock) {
      $node_stock = node_load($stock->nid);
      $node_complex = node_load($node_stock->field_complex_stock['und'][0]['target_id']);

      $vars['stocks'][] = array(
        'nid' => $stock->nid,
        'title' => $stock->node_title,
        'complex' => l($node_complex->title, '/node/' . $node_complex->nid, array('attributes' => array('class' => 'slink_c'))),
        'description' => $stock->field_field_mini_description[0]['rendered']['#markup'],
        'body' =>  $stock->field_body[0]['rendered']['#markup'],
        'image' => theme('image', array(
          'path' => $stock->field_field_image[0]['raw']['uri'],
          'title' => $stock->node_title,
          'alt' => $stock->node_title,
        ))
      );
    }
  }
}

/**
 * Process variables views-view-unformatted--news--all-new-city.tpl.php.
 */
function realty_preprocess_views_view_unformatted__news__all_new_city(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $key => $new) {
      $vars['news'][$key] = array(
        'link' => '/node/'. $new->nid,
        'title' => $new->node_title,
        'desc' => $new->field_field_news_description[0]['rendered']['#markup'],
        'nid' => $new->nid,
        'date' => format_date($new->node_created, 'medium', 'j F o г.'),
      );


      if (!empty($new->field_field_news_image)) {
        $vars['news'][$key]['image'] = theme('image', array(
            'path' => $new->field_field_news_image[0]['raw']['uri'],
          )
        );
      }
    }
  }
}

/**
 * Process variables views-view-unformatted--term-view--partners.tpl.php.
 */
function realty_preprocess_views_view_unformatted__term_view__partners(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $partner) {
      $logo = theme('image', array(
        'path' => $partner->field_field_partners_logo[0]['raw']['uri'],
        'title' => $partner->taxonomy_term_data_name,
        'alt' => $partner->taxonomy_term_data_name,
      ));

      $vars['partners'][] = l('<div class="col-xs-2 z-item">'. $logo .'</div>', '/taxonomy/term/' . $partner->tid,
        array('html' => TRUE));
    }
  }
}

/**
 * Process variables views-view-unformatted--term-view--mortgage-program.tpl.php.
 */
function realty_preprocess_views_view_unformatted__term_view__mortgage_program(&$vars) {
  $img_findome = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/fglush.png',
    )
  );
  $city_id = arg(2);

  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $bank) {
      $logo = theme('image', array(
          'path' => $bank->field_field_logo[0]['raw']['uri'],
          'title' => $bank->field_field_logo[0]['raw']['title'],
          'alt' => $bank->field_field_logo[0]['raw']['alt'],
        )
      );

      $vars['banks'][] = l('<div class="col-xs-4 b-item">'. $logo .'</div>', 'mortgage/city/' . $city_id,
        array(
          'html' => TRUE,
          'query' => array (
            'p' => $bank->tid,
          )
        )
      );
    }

    $count = count($vars['banks']);
    for($i = $count; $i < 3; $i++) {
      $vars['banks'][] = l('<div class="col-xs-4 b-item">'. $img_findome .'</div>', '#href',
        array(
          'html' => TRUE,
          'external' => TRUE
        )
      );
    }
  }
}

/**
 * Process variables views-view-unformatted--term-view--all-partners.tpl.php.
 */
function realty_preprocess_views_view_unformatted__term_view__all_partners(&$vars) {
  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $partner) {
      $logo = theme('image', array(
        'path' => $partner->field_field_partners_logo[0]['raw']['uri'],
        'title' => $partner->taxonomy_term_data_name,
        'alt' => $partner->taxonomy_term_data_name,
      ));

      $vars['partners'][] = l($logo, '/taxonomy/term/' . $partner->tid,
        array('html' => TRUE,
          'attributes' => array('class' => array('col-xs-4','develop-complex-item'))
        ));
    }
  }
}

/**
 * Process variables views-view-unformatted--term-view--partner.tpl.php.
 */
function realty_preprocess_views_view_unformatted__term_view__partner(&$vars) {
  $vars['name'] = $vars['view']->result[0]->taxonomy_term_data_name;
  $vars['body'] = $vars['view']->result[0]->taxonomy_term_data_description;
  $vars['logo'] = theme('image', array(
      'path' => $vars['view']->result[0]->field_field_partners_logo[0]['raw']['uri'],
      'title' => $vars['view']->result[0]->taxonomy_term_data_name,
      'alt' => $vars['view']->result[0]->taxonomy_term_data_name,
    )
  );
}

/**
 * Process variables for realty-modal-user-login.tpl.php
 */
function realty_preprocess_realty_modal_user_login(&$vars) {
  global $user;

  if ($user->uid == 0) {
    $vars['register_form'] = drupal_get_form('user_register_form');
    $vars['login_form'] = drupal_get_form('user_login');
  }

  $vars['image_close'] = realty_get_image_close();

  $vars['logo'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/findome-gray.svg',
      'attributes' => array(
        'class' => array('margin-left-15'),
      ),
    )
  );
}

/**
 * Process variables for realty-modal-notification.tpl.php
 */
function realty_preprocess_realty_modal_notify(&$vars) {
  $vars['img_close'] = realty_get_image_close();
}

/**
 * Process variables for realty-modal-city.tpl.php
 */
function realty_preprocess_realty_modal_city(&$vars) {
  $vars['img_close'] = realty_get_image_close();
}

/**
 * Process variables for views-view-unformatted--apartments--comprassion-apartment.tpl.php
 */
function realty_preprocess_views_view_unformatted__apartments__comprassion_apartment(&$vars) {

  if (!empty($vars['view']->result)) {
    foreach ($vars['view']->result as $key => $val) {
      $vars['number_apartment'][$key]['number'] = $val->field_field_number_apartament[0]['rendered']['#markup'];
      $vars['number_apartment'][$key]['link'] = '/node/' . $val->nid;
      $vars['number_apartment'][$key]['nid'] = $val->nid;

      $vars['complex'][$key]['complex'] = $val->node_field_data_field_home_complex_title;
      $vars['complex'][$key]['link'] = '/node/' . $val->node_field_data_field_home_complex_nid;

      $vars['developer'][$key]['developer'] = $val->taxonomy_term_data_field_data_field_complex_developer_name;
      $vars['developer'][$key]['link'] = '/taxonomy/term/' . $val->taxonomy_term_data_field_data_field_complex_developer_tid;

      $vars['address'][$key] = $val->field_field_address_house[0]['rendered']['#markup'];
      $vars['deadline'][$key] = $val->field_field_deadline[0]['rendered']['#markup'];
      $vars['masonry'][$key] = $val->field_field_masonry[0]['rendered']['#markup'];

      $vars['sections'][$key] = $val->field_field_section[0]['rendered']['#markup'];
      $vars['rooms'][$key] = $val->field_field_number_rooms[0]['rendered']['#markup'];
      $vars['floor'][$key] = $val->field_field_apartment_floor[0]['raw']['value']  . '/' .
        $val->field_field_number_floor[0]['raw']['value'];

      $vars['sq'][$key] = $val->field_field_gross_area[0]['raw']['value'];
      $vars['price'][$key] = $val->field_field_price[0]['raw']['value'];
      $vars['coast'][$key] = $val->field_field_full_cost[0]['raw']['value'];
      $vars['balcony'][$key] = $val->field_field_balcony[0]['raw']['value'] == '1' ? 'Балкон' : 'Нет';
      $vars['balcony'][$key] = $val->field_field_loggia[0]['raw']['value'] == '1' ? 'Лоджия' : 'Нет';
      $vars['area'][$key] = $val->field_field_area[0]['rendered']['#markup'];
      $vars['parking'][$key] = $val->field_field_parking[0]['raw']['value'] == '1' ? 'Есть' : 'Нет';
      $vars['booking'][$key] = l(t('Связаться с застройщиком'), 'node/' . $val->nid, array(
          'query' => array('booking' => 1),
          'attributes' => array("target" => "_blank"),
        )
      );
    }

    $vars['img_close'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/mini_close.svg');

  }
}

/**
 * Process variables for realty_modal_mortgage_request_form
 */
function realty_theme_preprocess_realty_modal_mortgage_request_form(&$vars) {

  $vars['img_close']= realty_get_image_close();

  // Извлечение логотипа банка
  $term_bank = taxonomy_term_load($_REQUEST['bankId']);
  $vars['img_bank_logo'] = theme('image', array(
    'path' => $term_bank->field_logo['und'][0]['uri'],
    'alt' => $term_bank->field_logo['und'][0]['alt'],
    'title' => $term_bank->field_logo['und'][0]['title'],
  ));


}

/**
 * Returns HTML for a form element
 */
function realty_theme_form_element($variables) {
  $element = &$variables['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item');

  // Добавление классов для модального окна Заявка на ипотеку
  if ($element['#id'] == "edit-last-experience-0" ||
    $element['#id'] == "edit-total-experience-0" ||
    $element['#id'] == "edit-confirmation-0") {
    $attributes['class'][] = 'first-div';
  }

  if ($element['#id'] == "edit-last-experience-1" ||
    $element['#id'] == "edit-total-experience-1" ||
    $element['#id'] == "edit-confirmation-1") {
    $attributes['class'][] = 'second-div';
  }

  // Далее следует оригинальный код функции
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}

/**
 * Process variables for realty-booking-apartment-form.tpl.php
 */
function realty_theme_preprocess_realty_booking_apartment_form(&$vars) {
  $vars['image_man'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/profile.svg'
    )
  );

  $vars['image_phone'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/phone.svg'
    )
  );

  $vars['image_mail'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/mail.svg',
    )
  );

  $vars['img_close'] = realty_get_image_close();
}

/**
 * Process variables for realty-apartment-modal.tpl.php
 */
function realty_theme_preprocess_realty_apartment_modal(&$vars) {
  $vars['img_close']= realty_get_image_close();

  $vars['img_goto'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/goto.svg',
      'title' => t('Close'),
    )
  );
}

/**
 * Process variables for realty-email-template-mortgage-request.
 */
function realty_theme_preprocess_realty_email_template_mortgage_request(&$vars) {
  $site = $GLOBALS['base_root'];

  $node = &$vars['node'];

  $img_logo = theme('image', array(
    'path' => theme_get_setting('logo_path'),
    'alt' => t(variable_get('site_name')),
    'title' => t(variable_get('site_name')),
    'width' => '150px',
  ));

  $vars['logo'] = l($img_logo, $site, array(
      'external' => TRUE,
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      )
    )
  );

  $vars['mortgage_name'] = $node->field_mortgage_name['und'][0]['value'];
  $vars['name'] = $node->field_full_name['und'][0]['value'];
  $vars['age'] = $node->field_morgage_age_applican['und'][0]['value'];
  $vars['email'] = $node->field_applicant_email['und'][0]['value'];
  $vars['phone'] = $node->field_phone['und'][0]['value'];
  $vars['amount'] = $node->field_required_amount['und'][0]['value'];
  $vars['period'] = $node->field_mortgage_period['und'][0]['value'];
  $vars['payment'] = $node->field_mortgage_payment['und'][0]['value'];
  $vars['income'] = $node->field_mortgage_income['und'][0]['value'];
  $vars['confirm_form'] = $node->field_mortgage_confirm_form['und'][0]['value'];
  $vars['last_experience'] = $node->field_mortgage_last_experience[LANGUAGE_NONE][0]['value'];
  $vars['total_experience'] = $node->field_mortgage_total_experience[LANGUAGE_NONE][0]['value'];
  $vars['passport_id'] = $node->field_mortgage_passport_id[LANGUAGE_NONE][0]['value'];
  $vars['passport_series'] = $node->field_mortgage_passport_series[LANGUAGE_NONE][0]['value'];
  $vars['date_issue'] = $node->field_mortgage_date_issue[LANGUAGE_NONE][0]['value'];
  $vars['issued_by'] = $node->field_mortgage_issued_by[LANGUAGE_NONE][0]['value'];


  if(!empty($node->field_apartment['und'])) {
    $link = drupal_get_path_alias('node/' . $node->field_apartment[LANGUAGE_NONE][0]['target_id']);
    $vars['apt_link'] = l($site . '/' . $link, $site . '/' . $link);
  }

  $term_city = taxonomy_term_load($node->field_mortgage_city[LANGUAGE_NONE][0]['tid']);
  $vars['city'] = $term_city->name;

  $vars['affiliate'] = $node->field_mortgage_bank_affiliate[LANGUAGE_NONE][0]['value'];

}

/**
 * Process variables for realty-email-template-register-verification.
 */
function realty_theme_preprocess_realty_email_template_register_verification(&$vars) {
  $a=1;
}


/**
 * Process variables for realty-modal-bank-info.tpl.php
 */
function realty_theme_preprocess_realty_modal_bank_info(&$vars) {

  // Извлечение информации о банке
  $term_bank = taxonomy_term_load($_GET['bankId']);

  // Извлечение содержимого колекции полей
  $field_requisites = field_view_field('taxonomy_term', $term_bank, 'field_bank_requisites');
  $entity_id = $field_requisites['#object']->field_bank_requisites['und'][0]['value'];


  /*** Вкладка о банке ***/

  $vars['name'] = $term_bank->name;

  // Описание банка
  $vars['description'] = $term_bank->description;

  // Реквизиты банка
  $vars['requisites']['license'] = l($field_requisites[0]['entity']['field_collection_item'][$entity_id]['field_bank_license']['#items'][0]['value'],
    $field_requisites[0]['entity']['field_collection_item'][$entity_id]['field_bank_cb_link']['#items'][0]['value'],
    array (
      'attributes' => array (
        'target' => '_blank')
    )
  );

  $vars['requisites']['cbr'] = $field_requisites[0]['entity']['field_collection_item'][$entity_id]['field_bank_cb_link']['#items'][0]['value'];
  $vars['requisites']['ogrn'] = $field_requisites[0]['entity']['field_collection_item'][$entity_id]['field_bank_ogrn']['#items'][0]['value'];
  $vars['requisites']['bik'] = $field_requisites[0]['entity']['field_collection_item'][$entity_id]['field_bank_bik']['#items'][0]['value'];
  $vars['requisites']['office'] = $field_requisites[0]['entity']['field_collection_item'][$entity_id]['field_bank_head_office']['#items'][0]['value'];
  $vars['requisites']['phone'] = $field_requisites[0]['entity']['field_collection_item'][$entity_id]['field_bank_phone']['#items'][0]['value'];

  $vars['requisites']['website'] = l($field_requisites[0]['entity']['field_collection_item'][$entity_id]['field_bank_website']['#items'][0]['value'],
    $field_requisites[0]['entity']['field_collection_item'][$entity_id]['field_bank_website']['#items'][0]['value'],
    array (
      'attributes' => array (
        'target' => '_blank')
    )
  );

  // Изображения
  $vars['img_close']= realty_get_image_close();

  // Извлечение логотипа банка
  $term_bank = taxonomy_term_load($_REQUEST['bankId']);
  $vars['img_bank_logo'] = theme('image', array(
    'path' => $term_bank->field_logo['und'][0]['uri'],
    'alt' => $term_bank->field_logo['und'][0]['alt'],
    'title' => $term_bank->field_logo['und'][0]['title'],
  ));
}

/**
 * Process variables for realty-modal-mortgage-info.tpl.php
 */
function realty_theme_preprocess_realty_modal_mortgage_info(&$vars) {

  // ID
  $mortgageId = $_GET['mortgageId'];
  $bankId = $_GET['bankId'];

  // Извлечение содержимого сущности ипотеки
  $mortgage = entity_load('field_collection_item', array($mortgageId));

  // Извлечение иформации об ипотеке
  $vars['name'] = $mortgage[$mortgageId]->field_bank_mp_name['und'][0]['value'];
  $vars['description'] = $mortgage[$mortgageId]->field_bank_mp_description['und'][0]['value'];

  // Извлечение детальной информации об ипотеке
  $mortgage_mp_detailed_entity = $mortgage[$mortgageId]->field_bank_mp_detailed['und'][0]['value'];
  $mortgage_mp_detailed = entity_load('field_collection_item', array($mortgage_mp_detailed_entity));

  // Ставки кредита
  foreach ($mortgage_mp_detailed[$mortgage_mp_detailed_entity]->field_bank_mp_det_rate['und'] as $key => $rate) {
    $vars['rates'][$key] = $rate['value'];
  }
  // Суммы кредита
  foreach ($mortgage_mp_detailed[$mortgage_mp_detailed_entity]->field_bank_mp_det_amount['und'] as $key => $amount) {
    $vars['amounts'][$key] = $amount['value'];
  }
  // Первоначальные взносы
  foreach ($mortgage_mp_detailed[$mortgage_mp_detailed_entity]->field_bank_mp_det_payment['und'] as $key => $payment) {
    $vars['payments'][$key] = $payment['value'];
  }
  // Скроки кредита
  foreach ($mortgage_mp_detailed[$mortgage_mp_detailed_entity]->field_bank_mp_det_period['und'] as $key => $period) {
    $vars['periods'][$key] = $period['value'];
  }

  // Извлечение Требований по ипотеки
  $mortgage_requirements_entity = $mortgage_mp_detailed[$mortgage_mp_detailed_entity]->field_bank_mp_det_requirements['und'][0]['value'];
  $mortgage_requirements = entity_load('field_collection_item', array($mortgage_requirements_entity));

  // Возраст заемщика от
  $vars['requirement']['age'] = $mortgage_requirements[$mortgage_requirements_entity]->field_bank_mp_det_req_age['und'][0]['value'];
  // Возраст в момент погашения кредита (для мужчин)
  $vars['requirement']['age_men'] = $mortgage_requirements[$mortgage_requirements_entity]->field_bank_mp_det_req_age_men['und'][0]['value'];
  // Возраст в момент погашения кредита (для женщин)
  $vars['requirement']['age_women'] = $mortgage_requirements[$mortgage_requirements_entity]->field_bank_mp_det_req_age_women['und'][0]['value'];
  // Стаж на последнем месте работы от
  $vars['requirement']['last_experience'] = $mortgage_requirements[$mortgage_requirements_entity]->field_bank_mp_det_req_last_senio['und'][0]['value'];
  // Общий стаж работы от
  $vars['requirement']['total_experience'] = $mortgage_requirements[$mortgage_requirements_entity]->field_bank_mp_det_req_total_seni['und'][0]['value'];
  // Наличие гражданства РФ
  $vars['requirement']['citizenship'] = $mortgage_requirements[$mortgage_requirements_entity]->field_bank_mp_det_req_citizenshi['und'][0]['value'];
  // Наличие постоянной или временной регистрации в регионе обращения
  $vars['requirement']['living_place'] = $mortgage_requirements[$mortgage_requirements_entity]->field_bank_mp_det_req_living_pla['und'][0]['value'];
  // Наличие постоянного дохода
  $vars['requirement']['fixed_income'] = $mortgage_requirements[$mortgage_requirements_entity]->field_bank_mp_det_req_fixed_inco['und'][0]['value'];
  // Форма подтверждения платёжеспособности
  $vars['requirement']['confirm'] = $mortgage_requirements[$mortgage_requirements_entity]->field_bank_mp_det_req_confirm_in['und'][0]['value'];
  // Необходимые документы
  foreach ($mortgage_requirements[$mortgage_requirements_entity]->field_bank_mp_det_req_documents['und'] as $document) {
    $vars['requirement']['documents'][] = $document['value'];
  }

  // Извлечение Условий ипотеки
  $mortgage_conditions_entity = $mortgage_mp_detailed[$mortgage_mp_detailed_entity]->field_bank_mp_det_conditions['und'][0]['value'];
  $mortgage_conditions = entity_load('field_collection_item', array($mortgage_conditions_entity));

  // Обеспечение кредита
  foreach ($mortgage_conditions[$mortgage_conditions_entity]->field_bank_mp_det_con_guarantees['und'] as $key => $guarante) {
    $vars['conditions']['guarantees'][$key] = $guarante['value'];
  }
  // Досрочное погашение
  $vars['conditions']['early_rep'] = $mortgage_conditions[$mortgage_conditions_entity]->field_bank_mp_det_con_early_repa['und'][0]['value'];
  // Страхование
  $vars['conditions']['insurance'] = $mortgage_conditions[$mortgage_conditions_entity]->field_bank_mp_det_con_insurance['und'][0]['value'];

  // Извлечение Дополнительных параметров ипотеки
  $mortgage_additionally_entity = $mortgage_mp_detailed[$mortgage_mp_detailed_entity]->field_bank_mp_det_additionally['und'][0]['value'];
  $mortgage_additionally = entity_load('field_collection_item', array($mortgage_additionally_entity));

  // Штрафы
  $vars['additionally']['fines'] = $mortgage_additionally[$mortgage_additionally_entity]->field_bank_mp_det_add_fines['und'][0]['value'];
  // Дополнительные условия
  $vars['additionally']['conditions'] = $mortgage_additionally[$mortgage_additionally_entity]->field_bank_mp_det_add_conditions['und'][0]['value'];

  // Изображения
  $vars['img_close']= realty_get_image_close();

  // Извлечение логотипа банка
  $term_bank = taxonomy_term_load($_REQUEST['bankId']);
  $vars['img_bank_logo'] = theme('image', array(
    'path' => $term_bank->field_logo['und'][0]['uri'],
    'alt' => $term_bank->field_logo['und'][0]['alt'],
    'title' => $term_bank->field_logo['und'][0]['title'],
  ));
}

/**
 * Process variables for realty-modal-mortgage-category-info.tpl.php
 */
function realty_theme_preprocess_realty_modal_mortgage_category_info(&$vars) {

  // Извлечение термина таксономии Категория ипотеки
  $term_mortgage_category = taxonomy_term_load ($_GET['mortgageCategoryId']);

  // Извлечение информации об ипотеки
  $vars['name'] = $term_mortgage_category->name;
  $vars['description'] = $term_mortgage_category->description;

  // Изображения
  $vars['img_close']= realty_get_image_close();
}

/**
 * Process variables for realty-complex-home-plan.tpl.php
 */
function realty_theme_preprocess_realty_complex_home_plan(&$vars) {
  $vars['arrow_blue'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/arrow-gray.svg',
      'attributes' => array(
        'class' => array('plan-arrow'),
      )
    )
  );

  $vars['area_legend'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/area-legend.svg',
      'attributes' => array(
        'class' => array('plan-arrow'),
      )
    )
  );
}

/**
 * Process variables for realty-modal-new.tpl.php
 */
function realty_theme_preprocess_realty_modal_new(&$vars){
  $vars['image'] = theme('image', array(
      'path' => $vars['node']->field_news_image[LANGUAGE_NONE][0]['uri'],
    )
  );

  $vars['date'] = gmdate("m-d-Y", $vars['node']->created);

  $vars['img_close'] = realty_get_image_close();
}

/**
 * Process variables for realty-modal-stock.tpl.php
 */
function realty_theme_preprocess_realty_modal_stock(&$vars){
  $vars['image'] = theme('image', array(
      'path' => $vars['node']->field_image[LANGUAGE_NONE][0]['uri'],
    )
  );

  $vars['img_close'] = realty_get_image_close();
}

/**
 * Process variables for node--basic_page-full.tpl.php
 */
function realty_theme_node__basic_page_full(&$vars) {

}

/**
 * Process variables for node--myarticle-full.tpl.php
 */
function realty_preprocess_node__myarticle_full(&$vars) {

  $node = node_load($vars['nid']);
  $vars['article_title'] = $node->title;
}

/**
 * Process variables for node--presentation-full.tpl.php
 */
function realty_preprocess_node__presentation_full(&$vars) {

  $sliders = $vars['node']->content['field_presentation_slides'];

  for ($i = 0; isset($sliders[$i]); $i++) {
    $entity_id = $vars['node']->field_presentation_slides[LANGUAGE_NONE][$i]['value'];
    $image_path = file_create_url($sliders[$i]['entity']['field_collection_item'][$entity_id]['field_pr_slide_image'][0]['#item']['uri']);

    $vars['slides'][$i]['image'] = $image_path;
    $vars['slides'][$i]['title'] = $sliders[$i]['entity']['field_collection_item'][$entity_id]['field_pr_slide_title']['#items'][0]['value'];
    $vars['slides'][$i]['text'] = $sliders[$i]['entity']['field_collection_item'][$entity_id]['field_pr_slide_text']['#items'][0]['value'];
    $vars['slides'][$i]['class'] = $sliders[$i]['entity']['field_collection_item'][$entity_id]['field_pr_slide_class']['#items'][0]['value'];
  }
}

/**
 * Process variables for realty-email-template-request-feedback.
 */
function realty_theme_preprocess_realty_email_template_request_feedback(&$vars) {
  $a = 1;
  if ($vars['options']['type'] == 'callback') {
    $vars['title'] = t('Заявка на обратный звонок');
  }

  if ($vars['options']['type'] == 'excur') {
    $vars['title'] = t('Заявка на экскурсию');
  }

  if ($vars['options']['type'] == 'question') {
    $vars['title'] = t('Вопрос или предложение');
  }

  if ($vars['options']['type'] == 'selection') {
    $vars['selection'] = 'selection';
  }

  $vars['name'] = $vars['options']['name'];

  if ($vars['options']['phone']) {
    $vars['phone'] = $vars['options']['phone'];
  }

  if ($vars['options']['email']) {
    $vars['email'] = $vars['options']['email'];
  }

  if ($vars['options']['date_time']) {
    $vars['date_time'] = $vars['options']['date_time'];
  }

  if ($vars['options']['complexes']) {
    $node = node_load($vars['options']['complexes']);
    $vars['complex'] = $node->title;
  }

  if ($vars['options']['question']) {
    $vars['question'] = $vars['options']['question'];
  }

}

/**
 * Process variables for realty-feedback-form.
 */
function realty_theme_process_realty_feedback_form(&$vars) {
  $a = 1;
  unset($vars['form']['name']['#title']);
  unset($vars['form']['email']['#title']);
  unset($vars['form']['phone']['#title']);
  unset($vars['form']['date_time']['#title']);
  unset($vars['form']['complexes']['#title']);

  $vars['img_close'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/close-feedback.svg',
      'attributes' => array(
        'class' => array('close_feed')
      ),
    )
  );
}


/**
 * Process variables for realty-feedback-block.
 */
function realty_theme_process_realty_feedback_block(&$vars) {

  $vars['img_close'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/close-feedback.svg',
      'attributes' => array(
        'class' => array('close_feed_menu')
      ),
    )
  );


  $vars['request_callback_form'] = drupal_get_form('realty_request_callback_form', 'callback');
  $vars['request_excur_form'] = drupal_get_form('realty_request_callback_form', 'excur');
  $vars['request_question_form'] = drupal_get_form('realty_request_callback_form', 'question');
  $vars['request_selection_form'] = drupal_get_form('realty_request_callback_form', 'selection');
}