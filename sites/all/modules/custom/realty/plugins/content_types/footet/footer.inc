<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_footer_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Footer'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_footer_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_footer_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_footer');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_footer_content_type_theme(&$theme, $plugin) {
  $theme['realty_footer'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-footer',
  );
}

/**
 * Process variables for realty-footer.tpl.php.
 */
function template_preprocess_realty_footer(&$vars) {

  $img_facebook = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/facebook.svg');
  $img_instagram =  file_get_contents(REALTY_FRONT_THEME_PATH . '/images/instagram.svg');
  $img_vk = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/vk.svg');
  $img_twitter = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/twitter.svg');
  $img_google = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/google.svg');

  $vars['link_facebook'] = l($img_facebook, 'http://facebook.com/', array(
      'external' => TRUE,
      'html' => TRUE,
      'attributes' => array(
        'target'=>'_blank'
      )
    )
  );

  $vars['link_instagram'] = l($img_instagram, 'http://instagram.com/', array(
      'external' => TRUE,
      'html' => TRUE,
      'attributes' => array(
        'target'=>'_blank'
      )
    )
  );

  $vars['link_vk'] = l($img_vk, 'http://vk.com/findome', array(
      'external' => TRUE,
      'html' => TRUE,
      'attributes' => array(
        'target'=>'_blank'
      )
    )
  );

  $vars['link_twitter'] = l($img_twitter, 'http://twitter.com/', array(
      'external' => TRUE,
      'html' => TRUE,
      'attributes' => array(
        'target'=>'_blank'
      )
    )
  );

  $vars['link_google'] = l($img_google, 'http://google.com/', array(
      'external' => TRUE,
      'html' => TRUE,
      'attributes' => array(
        'target'=>'_blank'
      )
    )
  );

  $vars['ic_phone'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/ic_phone.svg');

  $vars['ic_mail'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/ic_mail.svg');



  /*** Формирование ссылок подвала ***/

  // Раздел Политика
  $taxonomy_vocubulary = taxonomy_vocabulary_machine_name_load('taxonomy_policy');
  $terms_pages = taxonomy_get_tree($taxonomy_vocubulary->vid);

  foreach ($terms_pages as $key => $term_page) {
    $vars['footer_links']['policy'][$term_page->tid] = $term_page->name;
  }

  // Раздел Сотрудничество
  $taxonomy_vocubulary = taxonomy_vocabulary_machine_name_load('taxonomy_cooperation');
  $terms_pages = taxonomy_get_tree($taxonomy_vocubulary->vid);

  foreach ($terms_pages as $key => $term_page) {
    $vars['footer_links']['cooperation'][$term_page->tid] = $term_page->name;
  }

  // Раздел Контакты
  $taxonomy_vocubulary = taxonomy_vocabulary_machine_name_load('taxonomy_contacts');
  $terms_pages = taxonomy_get_tree($taxonomy_vocubulary->vid);

  foreach ($terms_pages as $key => $term_page) {
    $vars['footer_links']['contacts'][$term_page->tid] = $term_page->name;
  }


  $logo_findome = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/minilogo.svg',
    )
  );

  $vars['footer_logo'] = l($logo_findome, 'http://findome.ru/', array(
      'external' => TRUE,
      'html' => TRUE,
      'attributes' => array(
        'target'=>'_blank',
        'class' => 'footer-logo'
      )
    )
  );

  $city = taxonomy_term_load(arg(2));

  //if (arg(0) == 'taxonomy' && $city->tid == 1) {
  //  $vars['page'] = 'index';
  //}
  if (arg(0) == 'complexes') {
    $vars['page'] = 'complexes';
  }

  if (arg(0) == 'developers') {
    $vars['page'] = 'developers';
  }

  if ($_GET['q'] == "<front>") {
    $vars['city_name'] = '';
    $vars['city_page'] = TRUE;
  } else {
    $vars['city_name'] = ' Новосибирска';
  }
}