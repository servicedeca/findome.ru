<?php

/**
 * @file.
 */

/**
 * Preprocess for realty-user-profile-form.tpl.php.
 */
function realty_preprocess_realty_user_profile_form(&$vars) {
  $a = 1;
  unset($vars['form']['timezone']);
  unset($vars['form']['metatags']);
  unset($vars['form']['locale']);

}

/**
 * Process for realty-edit-user-pass
 */
function realty_preprocess_realty_edit_user_pass(&$vars) {
  unset($vars['form']['name']['#title']);

  $vars['form']['name']['#attributes']['class'][] = 'input-modal';
  $vars['form']['actions']['submit']['#attributes']['class'][] = 'ok-button';

  $vars['image_mail'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/mail.svg',
    )
  );

}

/**
 * Preprocess for realty-user-pass-reset.tpl.php
 */
function realty_preprocess_realty_user_pass_reset(&$vars) {
  $vars['user'] = user_load(arg(2));
  $vars['time'] = date('m/d/Y - H:i', arg(3));
  unset($vars['form']['message']);
  unset($vars['form']['help']);
  $vars['form']['actions']['submit']['#attributes']['class'][] = 'ok-button';
}


/**
 * Preprocess for realty-apartment-complex-filter-modal.tpl.php
 */
function realty_preprocess_apartment_complex_filter_modal (&$vars) {
  $homes = realty_get_homes();

  $vars['homes'] = $homes['homes'];
  $vars['sections'] = $homes['homes'];

  $vars['img_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
    'title' => t('Close'),
  ));
}

/**
 * Preprocess for realty-id-apartment-pdf.tpl.php.
 */
function realty_preprocess_realty_id_apartment_pdf(&$vars) {
  $vars['logo'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/findome.svg',
      'attribute' => array(
        'data-brackets-id' => 1565,
      ),
    )
  );
  $vars['number'] = $vars['node']->field_number_apartament[LANGUAGE_NONE][0]['safe_value'];
  $home = taxonomy_term_load($vars['node']->field_apartament_home[LANGUAGE_NONE][0]['tid']);
  $vars['home_address'] = $home->field_address_house[LANGUAGE_NONE][0]['safe_value'];
  $complex = node_load($home->field_home_complex[LANGUAGE_NONE][0]['target_id']);
  $dev = taxonomy_term_load($complex->field_complex_developer[LANGUAGE_NONE][0]['tid']);
  $home_view = taxonomy_term_view($home);
  $node_view = node_view($vars['node']);

  $vars['plan'] = theme('image', array(
      //'style_name' => 'pdf',
      'path' => $vars['node']->field_plan_apartment[LANGUAGE_NONE][0]['uri']
    )
  );

  $vars['deadline'] = $home_view['field_deadline'][0]['#markup'];
  $vars['complex'] = $complex->title;
  $vars['coast'] = number_format($vars['node']->field_full_cost[LANGUAGE_NONE][0]['value'] / 1000, 0, ',', ' ') . ' т.р';
  $vars['rooms'] = $node_view['field_number_rooms'][0]['#markup'];
  $vars['floor'] = $vars['node']->field_apartment_floor[LANGUAGE_NONE][0]['value'];
  $vars['section'] = $vars['node']->field_section[LANGUAGE_NONE][0]['value'];
  $vars['price'] = $node_view['field_price'][0]['#markup'];
  $vars['sq'] = $vars['node']->field_gross_area['und'][0]['value'];
  !empty($vars['node']->field_living_space) ? $vars['living_sq'] = $vars['node']->field_living_space[LANGUAGE_NONE][0]['value'] :
    $vars['living_sq'] = '-';
  $vars['developer'] = $dev->name;

}

/**
 * Preprocess for realty-sending-messages.tpl.php
 */
function realty_preprocess_realty_sending_messages(&$vars) {

}

/**
 * Preprocess for realty-main-search-form.tpl.php.
 */
function realty_preprocess_realty_main_search_form(&$vars) {

  drupal_add_js(REALTY_FRONT_THEME_PATH . '/js/realty_main_search_form.js');
  $city = menu_get_object('taxonomy_term', 2);
  $vars['form']['field_city_tid']['#value'] = $city->tid;
  $vars['form']['field_apartment_floor_value']['#maxlength'] = 2;
  $vars['form']['field_apartment_floor_value']['#attributes'] = array(
    'class' => array('search-input', 'mini-width', 'floor'),
  );
  $vars['form']['field_masonry_value']['#attributes']['class'] = array('ss');
  $vars['form']['field_category_value']['#attributes']['class'] = array('ss', 'mini-ss');
  $vars['form']['field_home_deadline_quarter_value']['#attributes']['class'] = array('ss', 'mini-ss');
  $vars['form']['field_home_deadline_year_value']['#attributes'] = array(
    'class' => array('search-input', 'ear', 'ss', 'mini-ss'),
    'placeholder' => t('Year'),
    'maxlength' => '4',
  );

  $vars['form']['submit']['#value'] = '';
  $vars['form']['submit']['#attributes']['class'] = array('search-input');

  $vars['img_plus'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/plus.svg',
    )
  );

  $vars['img_search'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/search.svg',
    )
  );

  foreach (realty_get_list_city() as $city) {
    $vars['cities'][] = l($city->name, 'taxonomy/term/' . $city->tid);
  }

  $city = realty_get_current_city();
  $vars['city'] = $city->name;
  $vars['city_id'] = $city->tid;

  $vars['default_value'] = t('Все');

  $vars['img_cross'] = file_get_contents( REALTY_FRONT_THEME_PATH . '/images/cross_main_filter.svg');
}

/**
 * Process variables for realty-user-login-form.tpl.php
 */
function realty_preprocess_realty_user_login_form(&$vars) {
  $vars['form'] = $vars[''];
  $vars['form']['name']['#attributes']['class'] = array('input-modal');

  $vars['form']['pass']['#attributes']['class'] = array('input-modal');
  unset($vars['form']['name']['#title']);
  unset($vars['form']['name']['#description']);
  unset($vars['form']['pass']['#title']);
  unset($vars['form']['pass']['#description']);
  $vars['form']['name']['#attributes']['placeholder'] = t('e-mail');
  $vars['form']['pass']['#attributes']['placeholder'] = t('Пароль');
  $vars['form']['actions']['submit']['#attributes']['class'] = array('ok-button');

  $vars['image_mail'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/mail.svg',
    )
  );

  $vars['image_pass'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/pass.svg',
    )
  );
}

/**
 * Process variables for realty-user-register-form.tpl.php
 */
function realty_preprocess_realty_user_register_form(&$vars) {
  $vars['form'] = $vars[''];
  $vars['form']['account']['mail']['#attributes']['class'] = array('input-modal');
  unset($vars['form']['account']['mail']['#description']);
  unset($vars['form']['account']['mail']['#title']);
  $vars['form']['account']['mail']['#attributes']['placeholder'] = t('e-mail');
  unset( $vars['form']['account']['pass']['pass1']['#title']);
  unset( $vars['form']['account']['pass']['pass2']['#title']);
  unset($vars['form']['account']['pass']['pass1']['#attributes']['class']);
  unset($vars['form']['account']['pass']['pass2']['#attributes']['class']);
  $vars['form']['account']['pass']['pass1']['#attributes']['class'][] = 'input-modal';
  $vars['form']['account']['pass']['pass1']['#attributes']['placeholder'] = t('Пароль');
  $vars['form']['account']['pass']['pass2']['#attributes']['class'][] = 'input-modal';
  $vars['form']['account']['pass']['pass2']['#attributes']['placeholder'] = t('Повторите пароль');
  $vars['form']['actions']['submit']['#attributes']['class'][] = 'ok-button';
  unset($vars['form']['field_user_name']['und'][0]['value']['#title']);
  $vars['form']['field_user_name'][LANGUAGE_NONE][0]['value']['#attributes']['class'] = array('input-modal');
  $vars['form']['field_user_name'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('Ф.И.О');

  $terms_use = l(t('условиями пользовательского соглашения '), 'policy', array(
      'query' => array('p' => 114),
      'attributes' => array('target' => '_blank',),
    )
  );

  $vars['form']['field_conditions'][LANGUAGE_NONE]['#title'] = t('Я соглашаюсь с ');
  $vars['form']['field_conditions'][LANGUAGE_NONE]['#title'] .= $terms_use;
  $vars['form']['field_conditions'][LANGUAGE_NONE]['#title'] .= t('и подтверждаю достоверность введенных данных.');


  $vars['image_mail'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/mail.svg',
    )
  );
  $vars['image_pass'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/pass.svg',
    )
  );
  $vars['image_profile'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/profile.svg',
    )
  );

}

/**
 * Process variables for realty-booking-request.tpl.php
 */
function realty_preprocess_realty_booking_request(&$vars) {
  $site = $GLOBALS['base_root'];
  $vars['site'] = $site;

  $img_logo = theme('image', array(
      'path' => theme_get_setting('logo_path'),
      'alt' => t(variable_get('site_name')),
      'title' => t(variable_get('site_name')),
      'width' => '150px',
    )
  );

  $vars['logo'] = l($img_logo, $site, array(
      'external' => TRUE,
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
      )
    )
  );

  $vars['name'] = $vars['node']->field_booking_name[LANGUAGE_NONE][0]['value'];

  if (!empty($vars['node']->field_booking_entity)) {
    $entity = node_load($vars['node']->field_booking_entity[LANGUAGE_NONE][0]['target_id']);
    if ($entity->type == 'complex') {
      $complex = $entity;
    }
    elseif ($entity->type == 'apartament') {
      $vars['link_apartment'] = $site . '/node/' . $entity->nid;
      $home = taxonomy_term_load($entity->field_apartament_home[LANGUAGE_NONE][0]['tid']);
      $complex = node_load($home->field_home_complex[LANGUAGE_NONE][0]['target_id']);
      $vars['number_home'] = $home->field_number_home[LANGUAGE_NONE][0]['value'];
      $vars['section'] = $entity->field_section[LANGUAGE_NONE][0]['value'];
      $vars['apartment_number'] = $entity->field_number_apartament[LANGUAGE_NONE][0]['value'];
    }
    $vars['complex'] = $complex->title;
  }

  $method_pay = $vars['node']->field_method_purchase[LANGUAGE_NONE][0]['value'];
  switch($method_pay) {
    case 0 :
      $vars['method_pay'] = t('Наличный');
      break;
    case 1 :
      $vars['method_pay'] = t('Рассрочка(по условиям застройщика)');
      break;
    case 2 :
      $vars['method_pay'] = t('Ипотека');
      break;
  }

  if (isset($vars['user']) && $vars['user'] = TRUE) {
    if (isset($complex)) {
      $dev_id = $complex->field_complex_developer[LANGUAGE_NONE][0]['tid'];
    }
    else{
      $dev_id = $vars['node']->field_booking_developer[LANGUAGE_NONE][0]['tid'];
    }

    $vars['developer'] = taxonomy_term_load($dev_id);
    $vars['manager'] = $vars['node']->field_booking_manager[LANGUAGE_NONE][0]['safe_value'];
  }

}

/**
 * Process variables for realty-mortgage-request.tpl.php
 */
function realty_preprocess_realty_mortgage_request(&$vars) {

  //$vars['apt'] = $vars['options']->

}

/**
 * Process variables for realty-comparison-apartment-table.tpl.php
 */
function realty_preprocess_realty_comparison_apartment_table(&$vars) {

  if (!empty($vars['apartments'])) {
    foreach ($vars['apartments'] as $key => $val) {
      $vars['number_apartment'][$val->nid]['number'] = $val->field_field_number_apartament[0]['rendered']['#markup'];
      $vars['number_apartment'][$val->nid]['link'] = '/node/' . $val->nid;
      $vars['number_apartment'][$val->nid]['nid'] = $val->nid;

      $vars['complex'][$val->nid]['complex'] = $val->node_field_data_field_home_complex_title;
      $vars['complex'][$val->nid]['link'] = '/node/' . $val->node_field_data_field_home_complex_nid;

      $vars['developer'][$val->nid]['developer'] = $val->taxonomy_term_data_field_data_field_complex_developer_name;
      $vars['developer'][$val->nid]['link'] = '/taxonomy/term/' . $val->taxonomy_term_data_field_data_field_complex_developer_tid;

      $vars['address'][$val->nid] = $val->field_field_address_house[0]['rendered']['#markup'];
      $vars['deadline'][$val->nid] = $val->field_field_deadline[0]['rendered']['#markup'];
      $vars['masonry'][$val->nid] = $val->field_field_masonry[0]['rendered']['#markup'];
      $vars['statuses'][$val->nid] = $val->field_field_status[0]['rendered']['#markup'];
      $vars['masonry'][$val->nid] = $val->field_field_material[0]['rendered']['#title'];

      $vars['sections'][$val->nid] = $val->field_field_section[0]['rendered']['#markup'];
      $vars['rooms'][$val->nid] = $val->field_field_number_rooms[0]['rendered']['#markup'];
      $vars['floor'][$val->nid] = $val->field_field_apartment_floor[0]['raw']['value']  . '/' .
        $val->field_field_number_floor[0]['raw']['value'];

      $vars['sq'][$val->nid] = $val->field_field_gross_area[0]['raw']['value'];
      $vars['price'][$val->nid] = $val->field_field_price[0]['raw']['value'];
      $vars['coast'][$val->nid] = $val->field_field_full_cost[0]['raw']['value'];
      $vars['balcony'][$val->nid] = $val->field_field_balcony[0]['raw']['value'] == '1' ? 'Балкон' : 'Нет';
      $vars['balcony'][$val->nid] = $val->field_field_loggia[0]['raw']['value'] == '1' ? 'Лоджия' : 'Нет';
      $vars['area'][$val->nid] = $val->field_field_area[0]['rendered']['#markup'];
      $vars['parking'][$val->nid] = $val->field_field_parking[0]['raw']['value'] == '1' ? 'Есть' : 'Нет';
      /*      $vars['booking'][$val->nid] = l(t('Отправить заявку застройщику'), 'node/' . $val->nid, array(
                'query' => array('booking' => 1),
                'attributes' => array("target" => "_blank"),
              )
            );*/
    }
  } else {
    $vars['empty'] = TRUE;
    $vars['search_link'] = l('Перейти к подбору квартир', '/',
      array(
        'attributes' => array(
          'class' => array('need-reg'),
        )
      )
    );
  }

  $vars['img_close'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/mini_close.svg');
}

/**
 * Process variables for realty-mortgage-request.tpl.php
 */
function realty_preprocess_realty_booking_apartment_table(&$vars) {

  if(!empty($vars['apartments'])) {
    foreach($vars['apartments'] as $key => $booking) {
      $vars['bookings'][$key]  = array(
        'apartment' => $booking->field_field_number_apartament[0]['raw']['value'],
        'app_nid' => $booking->node_field_data_field_booking_apartment_nid,
        'booking_id' => $booking->nid,
      );
      if(!empty($booking->field_field_booking_status)) {
        $vars['bookings'][$key]['status']['title'] = $booking->field_field_booking_status[0]['rendered']['#markup'];
        if ($booking->field_field_booking_status[0]['raw']['value'] == '0') {
          $vars['bookings'][$key]['status']['img']  = theme('image', array(
              'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/table-ready.svg',
              'title' => $booking->field_field_booking_status[0]['rendered']['#markup'],
            )
          );
          $vars['bookings'][$key]['but'] = '<td class="prize-button prize-button-active but-get-certificate"
            data-booking-id=" ' . $booking->nid . ' ">
            Получить сертификат
            </td>';
        }
        else {
          $vars['bookings'][$key]['status']['img']  = theme('image', array(
              'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/table-time.svg',
              'title' => $booking->field_field_booking_status[0]['rendered']['#markup'],
            )
          );
          $vars['bookings'][$key]['but'] = '<td class="prize-button but-get-certificate"> Получить сертификат
            </td>';
        }
      }
      else {
        $vars['bookings'][$key]['but'] = '<td class="prize-button but-get-certificate" id="but-get-certificate-' . $booking->nid . '"
          data-booking-id="' . $booking->nid . '">
            Отправить данные
          </td>';
      }
    }
  }
  else {
    $vars['empty'] = TRUE;
    $vars['search_link'] = l('Перейти к подбору квартир', '/',
      array(
        'attributes' => array(
          'class' => array('need-reg'),
        )
      )
    );
  }
}

/**
 * Process variables for realty-mortgage-request.tpl.php
 */
function realty_preprocess_realty_mortgage_apartment_table(&$vars) {

  if(!empty($vars['apartments'])) {
    foreach($vars['apartments'] as $key => $val) {
      $vars['mortgage'][] = array(
        'number' => $val->nid,
        'num_apartment' => $val->field_field_number_apartament[0]['raw']['value'],
        'bank' => $val->taxonomy_term_data_field_data_field_bank_name,
        'program' => $val->field_field_mortgage_name[0]['raw']['safe_value'],
        'sum' => $vars['view']->result[0]->field_field_required_amount[0]['raw']['safe_value'],
      );
    }
  } else {
    $vars['empty'] = TRUE;
    $vars['search_link'] = l('Перейти к подбору квартир', '/',
      array(
        'attributes' => array(
          'class' => array('need-reg'),
        )
      )
    );
  }

  $vars['img_close'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/mini_close.svg');
}

/**
 * Process variables for realty-edit-user-profile-form.tpl.php
 */
function realty_preprocess_realty_edit_user_profile_form(&$vars) {
  $vars['img_mail'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/mail.svg',
    )
  );

  $vars['img_pass'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/pass.svg',
    )
  );

  $vars['img_profile'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/profile.svg',
    )
  );

  $vars['img_phone'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/phone.svg',
    )
  );

  $vars['img_password'] = theme('image', array(
      'path' => '/' . REALTY_FRONT_THEME_PATH . '/images/pass.svg',
    )
  );

  $vars['img_close'] = realty_get_image_close();

}

/**
 * Process variables for realty-mortgage-request-user.tpl.php
 */
function realty_preprocess_realty_mortgage_request_user(&$vars) {
  $bank = taxonomy_term_load($vars['node']->field_bank[LANGUAGE_NONE][0]['tid']);
  $vars['bank'] = $bank->name;
  $vars['name'] = $vars['node']->field_full_name[LANGUAGE_NONE][0]['value'];
  $vars['project'] = $_SERVER['SERVER_NAME'] . '/about_project';;
  $vars['guide'] = $_SERVER['SERVER_NAME'] . '/guide';

  $vars['bank_mass'] = theme('realty_email_template_mortgage_request', array('node' => $vars['node']));

}

/**
 * Process variables for realty-booking-request-user.tpl.php.
 */
function realty_preprocess_realty_booking_request_user(&$vars) {
  global $user;

  $account = user_load($user->uid);
  $vars['name'] = $account->field_user_name[LANGUAGE_NONE][0]['safe_value'];

  $vars['project'] = $_SERVER['SERVER_NAME'] . '/about_project';;
  $vars['guide'] = $_SERVER['SERVER_NAME'] . '/guide';

  $vars['dev_mass'] = theme('booking_request', array(
      'node' => $vars['node'],
      'user' => TRUE,
    )
  );
}