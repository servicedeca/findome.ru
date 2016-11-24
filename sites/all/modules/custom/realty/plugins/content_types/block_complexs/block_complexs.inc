<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_block_complexs_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Block complexs'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_block_complexs_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_block_complexs_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_block_complexs');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_block_complexs_content_type_theme(&$theme, $plugin) {
  $a = 1;
  $theme['realty_block_complexs'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-block-complexs',
  );
}

/**
 * Process variables for realty-block-complexes.tpl.php.
 */
function template_preprocess_realty_block_complexs(&$vars) {

  $city = menu_get_object('taxonomy_term', 2);

  $vars['city_tid'] = $city->tid;

  $result = realty_get_nid_all_complexes_city($city->tid);
  $count_complex = count($result);
  $complex = rand(0, $count_complex-1);

  $node = node_load($result[$complex]->nid);

  $vars['next'] = isset($result[$complex + 1]) ? $result[$complex + 1]->nid : $result[0]->nid;
  $vars['prev'] = isset($result[$complex - 1]) ? $result[$complex - 1]->nid : $result[$count_complex-1]->nid;

  $vars['complex'] = array(
    'title' => $node->title,
    'image' => l(theme('image', array (
        'path' => $node->field_main_photo[LANGUAGE_NONE][0]['uri'],
        'alt' => $node->title,
        'title' => $node->title,
        'attributes' => array(
          'class' => array('photo'),
          ),
        )
      ),
      'node/' . $node->nid,
      array(
        'html' => TRUE
      )
    ),

    'details' => l(t('Подробнее о комплексе'), 'node/' . $node->nid),
    'plan' => l(t('Посмотреть планировки'), 'complexes/' . $node->nid . '/plan'),
  );

  if (!empty($node->field_slogan)) {
    $vars['complex']['description'] = $node->field_slogan[LANGUAGE_NONE][0]['safe_value'];
  }

  if (!empty($node->field_complex_logo)) {
    $vars['complex']['logo'] = l(theme('image', array(
        'path' => $node->field_complex_logo[LANGUAGE_NONE][0]['uri'],
        'alt' => $node->title,
        'title' => $node->title,
        'attributes' => array(
          'class' => array('logo-c'),
        ),
      )
    ), 'node/' . $node->nid, array('html' => TRUE));
  }

  $vars['all_complexes'] = 'complexes/city/' . $city->tid;

  $vars['micro_logo'] = realty_get_image_micro_logo();

  $vars['image_complexes'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/cork.jpg',
      'alt' => t('Residential complexes'),
      'title' => t('Residential complexes'),
    )
  );

  $vars['complex']['floor'] = $node->field_complex_floor[LANGUAGE_NONE][0]['safe_value'];

  $developer = taxonomy_term_load($node->field_complex_developer[LANGUAGE_NONE][0]['tid']);
  $vars['complex']['developer'] = l($developer->name, 'taxonomy/term/' . $developer->tid, array(
      'attributes' => array('target' => '_blank')
    )
  );

  $vars['complex']['apartments'] = realty_get_apartment_active_complex($node->nid);

  if($avg_price = realty_get_average_price_apartment_complex($node->nid)) {
    $vars['complex']['avg_price'] = $avg_price;
  }

  $vars['img_right'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/right.svg',
    )
  );

  $vars['img_left'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/left.svg',
    )
  );

}