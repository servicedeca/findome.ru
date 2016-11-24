<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_header_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('header'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_header_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_header_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_main_header');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_header_content_type_theme(&$theme, $plugin) {
  $theme['realty_main_header'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-main-header',
  );
}

/**
 * Process variables for realty-footer.tpl.php.
 */
function template_preprocess_realty_main_header(&$vars) {
  global $user;

  // Get site logo.
  if (!cache_get('realty_site_logo')) {
    $logo = theme('image', array(
        'path' => REALTY_FRONT_THEME_PATH . '/images/logotip.svg',
      )
    );

    $vars['logo'] = l($logo, '', array(
        'html' => TRUE,
        'attributes' => array('class' => 'logo',)
      )
    );
    cache_set('realty_site_logo', $vars['logo']);
  }
  else {
    $vars['logo'] = cache_get('realty_site_logo')->data;
  }

  $vars['notify_close'] = theme('image', array(
    'path' => REALTY_FRONT_THEME_PATH . '/images/crossnot.svg',
    'attributes' => array('class' => 'close-notification'),
  ));

  $city = realty_get_current_city();
  $vars['city'] = $city->name;

  if(!cache_get('realty_modal_cities')) {
    foreach(realty_get_list_city() as $city) {
      $cities[$city->name] = l($city->name, '/taxonomy/term/'.$city->tid, array (
          'external' => TRUE,
          'attributes' => array(
            'class' => array(
              'col-xs-4'
            ),
          ),
        )
      );
    }

    // Формирование списка городов
    $terms_cities = taxonomy_get_tree(1);
    foreach ($terms_cities as $city) {
      $vars['cities'][$city->tid] = $city->name;
    }

    $modals_city = theme('realty_modal_city', array(
        'city' => $vars['cities'],
      )
    );

    $vars['modals'] .= $modals_city;

    cache_set('realty_modal_cities', $modals_city);
  }
  else {
    $vars['modals'] .= cache_get('realty_modal_cities')->data;
  }

  if(!cache_get('realty_image_close')) {
    $vars['img_close'] = theme('image', array(
        'path' => REALTY_FRONT_THEME_PATH . '/images/close.png',
        'title' => t('Close'),
      )
    );

    cache_set('realty_image_close', $vars['img_close']);
  }
  else {
    $vars['img_close'] = cache_get('realty_image_close')->data;
  }

  /*** Меню ***/

  // Изображение для Сравнение
  if (!cache_get('realty_image_comparison')) {
    $vars['img_comparison'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/img_comparison.svg');

    cache_set('realty_image_comparison', $vars['img_comparison']);
  }
  else {
    $vars['img_comparison'] = cache_get('realty_image_comparison')->data;
  }

  // Изображение для Выбрать город
  if (!cache_get('realty_image_choose_city')) {
    $vars['img_choose_city'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/choose_city.svg');

    cache_set('realty_image_choose_city', $vars['img_choose_city']);
  }
  else {
    $vars['img_choose_city'] = cache_get('realty_image_choose_city')->data;
  }

  // Изображение для О проекте
  if (!cache_get('realty_image_about_project')) {
    $vars['img_main_menu'][] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/about_project.svg');

    cache_set('realty_image_about_project', end($vars['img_main_menu']));
  }
  else {
    $vars['img_main_menu'][] = cache_get('realty_image_about_project')->data;
  }

  // Изображение для Путеводитель
  if (!cache_get('realty_image_guide')) {
    $vars['img_main_menu'][] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/guide.svg');

    cache_set('realty_image_guide', end($vars['img_main_menu']));
  }
  else {
    $vars['img_main_menu'][] = cache_get('realty_image_guide')->data;
  }

  // Изображение для Вход, регистрация
  if (!cache_get('realty_image_login')) {
    $vars['img_login'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/login.svg');

    cache_set('realty_image_login', $vars['img_login']);
  }
  else {
    $vars['img_login'] = cache_get('realty_image_login')->data;
  }

  // Изображение для Профиль
  if (!cache_get('realty_image_user_profile')) {
    $vars['img_user_profile'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/login.svg');

    cache_set('realty_image_user_profile', $vars['img_user_profile']);
  }
  else {
    $vars['img_user_profile'] = cache_get('realty_image_user_profile')->data;
  }

  // Изображение для Выход
  if (!cache_get('realty_image_exit')) {
    $vars['img_exit'] = file_get_contents(REALTY_FRONT_THEME_PATH . '/images/exit.svg');

    cache_set('realty_image_exit', $vars['img_exit']);
  }
  else {
    $vars['img_exit'] = cache_get('realty_image_exit')->data;
  }

  // Главное меню
  if (!cache_get('realty_main_menu')) {
    $main_menu = menu_navigation_links('main-menu');

    unset($vars['main_menu']);

    $i = 0;
    foreach ($main_menu as $key => $item) {
      $vars['main_menu'][] = l($vars['img_main_menu'][$i++], $item['href'], array(
        'attributes' => array (
          'rel' => 'tooltip',
          'data-placement' => 'bottom',
          'title' => $item['title'],
        ),
        'html' => TRUE,
      ));
    }
    cache_set('realty_main_menu', $vars['main_menu']);
  }
  else {
    $vars['main_menu'] = cache_get('realty_main_menu')->data;
  }

  // Пользовательское меню
  if (user_is_logged_in()) {
    $vars['login_profile'] = l($vars['img_user_profile'], "user/$user->uid", array (
      'attributes' => array (
        'rel' => 'tooltip',
        'data-placement' => 'bottom',
        'title' => 'Личный кабинет',
        ),
      'html' => TRUE,
      )
    );

    $vars['logout_register'] = l($vars['img_exit'], 'user/logout', array (
      'attributes' => array (
        'rel' => 'tooltip',
        'data-placement' => 'bottom',
        'title' => 'Выход',
      ),
      'html' => TRUE,
    ));

  }
  else {
    $vars['login_profile'] =  l($vars['img_login'], '#href', array('external' => TRUE,
        'attributes' => array(
          'rel' => 'tooltip',
          'data-placement' => 'bottom',
          'title' => 'Вход/регистрация',
          'data-toggle' => 'modal',
          'data-target' => '.registration',
          'class' => array('head-reg'),
        ),
        'html' => TRUE,
      )
    );

    $vars['modals'] .= theme('realty_modal_user_login', array());
  }
  if ($_GET['q'] == "<front>") {
    $vars['link_search'] = '<a data-context="searchCon" data-toggle="modal" data-target=".modal_cities" class="contextCtr">Подбор квартир</a>';
    $vars['link_complexes'] = '<a data-context="complexCon" data-toggle="modal" data-target=".modal_cities" class="contextCtr">Новостройки</a>';
    $vars['link_developers'] = '<a data-context="developerCon" data-toggle="modal" data-target=".modal_cities" class="contextCtr">Застройщики</a>';
    $vars['link_mortgage'] = '<a data-context="mortageCon" data-toggle="modal" data-target=".modal_cities" class="contextCtr">Ипотека</a>';
  }
  if (isset($city)) {
    // Статические ссылки
    $vars['link_search'] = l(t('Подбор квартир'), 'search/' . $city->tid);
    $vars['link_complexes'] = l(t('Новостройки'), 'complexes/city/' . $city->tid);
    $vars['link_developers'] = l(t('Застройщики'), 'developers/city/' . $city->tid);
    $vars['link_mortgage'] = l(t('Ипотека'), 'mortgage/city/' . $city->tid);
  } else if ($_GET['q'] == "node/4629") {
    // Статические ссылки
    $vars['link_search'] = l(t('Подбор квартир'), 'search/1');
    $vars['link_complexes'] = l(t('Новостройки'), 'complexes/city/1');
    $vars['link_developers'] = l(t('Застройщики'), 'developers/city/1');
    $vars['link_mortgage'] = l(t('Ипотека'), 'mortgage/city/1');
  }

  /*** Раздел Как работает сервис ***/

  if (arg(0) == 'taxonomy') {

    $page = taxonomy_term_load(arg(2));

    $vars['class'] = 'container fin';

    if ($page->vocabulary_machine_name == 'cities') {

      $vars['how_it_works']  = TRUE;

      if (!cache_get('realty_how_works_img_hbi1')) {
        $vars['img_hbi1'] = theme('image', array(
          'path' => REALTY_FRONT_THEME_PATH . '/images/hbi1.svg',
        ));
        cache_set('realty_how_works_img_hbi1', $vars['img_hbi1']);
      }
      else {
        $vars['img_hbi1'] = cache_get('realty_how_works_img_hbi1')->data;
      }

      if (!cache_get('realty_how_works_img_hbi2')) {
        $vars['img_hbi2'] = theme('image', array(
          'path' => REALTY_FRONT_THEME_PATH . '/images/hbi2.svg',
        ));
        cache_set('realty_how_works_img_hbi2', $vars['img_hbi2']);
      }
      else {
        $vars['img_hbi2'] = cache_get('realty_how_works_img_hbi2')->data;
      }

      if (!cache_get('realty_how_works_img_hbi3')) {
        $vars['img_hbi3'] = theme('image', array(
          'path' => REALTY_FRONT_THEME_PATH . '/images/hbi3.svg',
        ));
        cache_set('realty_how_works_img_hbi3', $vars['img_hbi3']);
      }
      else {
        $vars['img_hbi3'] = cache_get('realty_how_works_img_hbi3')->data;
      }

      if (!cache_get('realty_how_works_img_hbi4')) {
        $vars['img_hbi4'] = theme('image', array(
          'path' => REALTY_FRONT_THEME_PATH . '/images/hbi4.svg',
        ));
        cache_set('realty_how_works_img_hbi4', $vars['img_hbi4']);
      }
      else {
        $vars['img_hbi4'] = cache_get('realty_how_works_img_hbi4')->data;
      }

      $vars['class'] = 'container-fluid';
    }
  }
  else if (arg(0) == 'search') {
    $vars['class'] = 'container-fluid';
  }
  else {
    $vars['class'] = 'container fin';
  }

  drupal_add_js(array(
    'not_comparison' => TRUE,
  ), 'setting');
}