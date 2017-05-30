<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_reference_book_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Reference book'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_reference_book_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_reference_book_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_reference_book');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_reference_book_content_type_theme(&$theme, $plugin) {
  $theme['realty_reference_book'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-reference_book',
  );
}

/**
 * Process variables for realty-menu-helper.tpl.php.
 */
function template_preprocess_realty_reference_book(&$vars) {

  switch (arg(0)) {
    // Если запрошена страница Путеводитель
    case 'guide': {
      $taxonomy_vocubulary = taxonomy_vocabulary_machine_name_load('taxonomy_guide');
      $terms_pages = taxonomy_get_tree($taxonomy_vocubulary->vid);
      break;
    }
    case 'policy': {
      // Если запрошена страница Политика
      $taxonomy_vocubulary = taxonomy_vocabulary_machine_name_load('taxonomy_policy');
      $terms_pages = taxonomy_get_tree($taxonomy_vocubulary->vid);
      break;
    }
    case 'cooperation': {
      // Если запрошена страница Сотрудничество
      $taxonomy_vocubulary = taxonomy_vocabulary_machine_name_load('taxonomy_cooperation');
      $terms_pages = taxonomy_get_tree($taxonomy_vocubulary->vid);
      break;
    }
    case 'contacts': {
      // Если запрошена страница Контакты
      $taxonomy_vocubulary = taxonomy_vocabulary_machine_name_load('taxonomy_contacts');
      $terms_pages = taxonomy_get_tree($taxonomy_vocubulary->vid);
      break;
    }
    case 'remunerations': {
      drupal_goto('/');
      // Если запрошена страница Вознаграждения
      $taxonomy_vocubulary = taxonomy_vocabulary_machine_name_load('taxonomy_remunerations');
      $terms_pages = taxonomy_get_tree($taxonomy_vocubulary->vid);
      break;
    }
  }

  // Формирование содержимого для страницы Помощника
      foreach ($terms_pages as $term_page) {

    // Если запрошен определенный раздел
    if ($_GET['p'] == $term_page->tid) {
      // Раздел делается активным
      $vars['content']['active'] = $term_page->tid;
    }
    //Формируется ссылка и содержимое
    $vars['content']['sections'][$term_page->tid]['title'] = $term_page->name;
    $vars['content']['sections'][$term_page->tid]['text'] = $term_page->description;
  }
  $vars['img_pointer'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/pointer.svg');
}