<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_apartment_comprassion_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Apartment comprassion'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_apartment_comprassion_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_apartment_comprassion_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $block->content = theme('realty_apartment_comprassion');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_apartment_comprassion_content_type_theme(&$theme, $plugin) {
  $theme['realty_apartment_comprassion'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-apartment-comprassion',
  );
}

/**
 * Process variables for realty-apartment-comprassion.tpl.php.
 */
function template_preprocess_realty_apartment_comprassion(&$vars) {
  global $user;

  drupal_add_library('system', 'jquery.cookie');

  $comparison_from_cookie = FALSE;
  $vars['comparison_empty'] = TRUE;

  // Формирование списка квартир добавленных в сравнение
  // Если пользователь не авторизован
  if($user->uid == 0) {

    if ($_COOKIE['comparison']) {
      $comparison = json_decode($_COOKIE['comparison']);

      $comparison_from_cookie = TRUE;
      $vars['comparison_empty'] = FALSE;
    }
  }
  // Если пользователь авторизован
  else {

    $user_account = user_load ($user->uid);

    if (!empty ($user_account->field_apartment_comparison)) {

      foreach ($user_account->field_apartment_comparison['und'] as $apartment) {
        $comparison[] = (int)$apartment['target_id'];
      }

      $vars['comparison_empty'] = FALSE;
    }
  }

  // Формирование списка с информацией о квартирах
  // Извлечение информации о первых двух квартирах в массиве
  foreach ($comparison as $key => $apartment_id) {

    $node_apartment = node_load($apartment_id);
    $apartment_info = realty_get_info_apartment($apartment_id);

    $taxonomy_home = taxonomy_term_load($apartment_info['home_nid']);
    $taxonomy_material = taxonomy_term_load($taxonomy_home->field_material['und'][0]['tid']);
    $taxonomy_developer = taxonomy_term_load($apartment_info['developer_tid']);

    $apartments_info[$node_apartment->nid] = array(
      'nid' => $node_apartment->nid,
      'number' => $node_apartment->field_number_apartament[LANGUAGE_NONE][0]['value'],
      'status' => $node_apartment->field_status['und'][0]['value'],
      'sq' => $node_apartment->field_gross_area['und'][0]['value'],
      'coast' => $node_apartment->field_full_cost['und'][0]['value'],
      'address' => $taxonomy_home->field_address_house['und'][0]['value'],
      'rooms' => $node_apartment->field_number_rooms['und'][0]['value'],
      'complex' => $apartment_info['complex_name'],
      'floor' => $node_apartment->field_apartment_floor['und'][0]['value'],
      'section' => $node_apartment->field_section['und'][0]['value'],
      'price' => $node_apartment->field_price['und'][0]['value'],
      'material' => $taxonomy_material->name,
      'deadline_year' => intval($taxonomy_home->field_deadline['und'][0]['value'] / 10),
      'deadline_quarter' => $taxonomy_home->field_deadline['und'][0]['value'] % 10,
      'ceiling_height' => $node_apartment->field_apartment_ceiling_height['und'][0]['value'],
      'parking' => $taxonomy_home->field_parking['und'][0]['value'],
      'loggia' => $node_apartment->field_loggia['und'][0]['value'],
      'balkon' => $node_apartment->field_balcony['und'][0]['value'],
      'balkon_loggia' => $node_apartment->field_balcony_loggia['und'][0]['value'],
      'developer' => $taxonomy_developer->name,

      'plan_300x200' => theme('image', array(
          'path' => $node_apartment->field_plan_apartment['und'][0]['uri'],
          'attributes' => array (
            'data-toggle' => 'modal',
            'data-target' => '.flat_modal',
            'data-id' => $node_apartment->nid,
            'class' => 'realty-appartment-info'
          )
        )
      ),
      'plan_170x130' => theme('image', array(
          'path' => $node_apartment->field_plan_apartment['und'][0]['uri'],
        )
      ),
    );
  }

  drupal_add_js(array(
    'comparison_from_cookie' => $comparison_from_cookie,
    'apartments_info' => $apartments_info,
  ), 'setting');

  drupal_add_js('/sites/all/themes/realty_theme/js/realty_comparison.js');

  $vars['modal'] = theme('realty_apartment_modal');
}