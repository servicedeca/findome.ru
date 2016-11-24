<?php
/**
 * @file
 * realty_feature_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function realty_feature_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'area' => array(
      'name' => 'Районы',
      'machine_name' => 'area',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'banks' => array(
      'name' => 'Банки',
      'machine_name' => 'banks',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'categories' => array(
      'name' => 'Категории домов',
      'machine_name' => 'categories',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'cities' => array(
      'name' => 'Города',
      'machine_name' => 'cities',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 5,
    ),
    'deadline' => array(
      'name' => 'Срок сдачи',
      'machine_name' => 'deadline',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'developers' => array(
      'name' => 'Застройщики',
      'machine_name' => 'developers',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'homes' => array(
      'name' => 'Дома',
      'machine_name' => 'homes',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'material' => array(
      'name' => 'Материал стен',
      'machine_name' => 'material',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'metro' => array(
      'name' => 'Метро',
      'machine_name' => 'metro',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'mortgage_category' => array(
      'name' => 'Категории ипотеки',
      'machine_name' => 'mortgage_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'partners' => array(
      'name' => 'Партнеры',
      'machine_name' => 'partners',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'taxonomy_contacts' => array(
      'name' => 'Контакты',
      'machine_name' => 'taxonomy_contacts',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'taxonomy_cooperation' => array(
      'name' => 'Сотрудничество',
      'machine_name' => 'taxonomy_cooperation',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'taxonomy_guide' => array(
      'name' => 'Путеводитель',
      'machine_name' => 'taxonomy_guide',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'taxonomy_policy' => array(
      'name' => 'Политика',
      'machine_name' => 'taxonomy_policy',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'taxonomy_remunerations' => array(
      'name' => 'Вознаграждения',
      'machine_name' => 'taxonomy_remunerations',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
