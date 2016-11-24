<?php
/**
 * @file
 * realty_feature_breadcrumbs.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function realty_feature_breadcrumbs_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_all_news';
  $path_breadcrumb->name = 'Хлебные крошки - все новости';
  $path_breadcrumb->path = 'news/city/%name';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%name:name',
      1 => 'Новости',
    ),
    'paths' => array(
      0 => '<front>',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'name' => array(
        'position' => 2,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vids' => array(
            1 => '1',
            11 => 0,
            6 => 0,
            3 => 0,
            9 => 0,
            14 => 0,
            12 => 0,
            8 => 0,
            10 => 0,
            5 => 0,
            13 => 0,
          ),
          'breadcrumb' => 1,
          'transform' => 0,
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['breadcrumbs_all_news'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_all_stock';
  $path_breadcrumb->name = 'Хлебные крошки - Все Акции';
  $path_breadcrumb->path = 'stock/city/%city';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%city:name',
      1 => 'Акции',
    ),
    'paths' => array(
      0 => '<front>',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'city' => array(
        'position' => 2,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vids' => array(
            1 => '1',
            11 => 0,
            6 => 0,
            3 => 0,
            9 => 0,
            14 => 0,
            15 => 0,
            12 => 0,
            8 => 0,
            10 => 0,
            18 => 0,
            17 => 0,
            5 => 0,
            16 => 0,
            13 => 0,
          ),
          'breadcrumb' => 1,
          'transform' => 0,
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['breadcrumbs_all_stock'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_apartment_other_pages';
  $path_breadcrumb->name = 'Хлебные крошки - Квартира остальные страницы';
  $path_breadcrumb->path = 'apartment/%node/%page';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%node:breadcrumbs_appartment_city',
      1 => 'Жилые комплексы',
      2 => '%node:breadcrumbs_appartment_complex',
      3 => '%node:breadcrumbs_appartment_title',
    ),
    'paths' => array(
      0 => '<front>',
      1 => 'complexes/city/%node:breadcrumbs_appartment_city_id',
      2 => 'node/%node:breadcrumbs_appartment_complex_id',
      3 => 'node/%node:nid',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Содержимое: ID',
        ),
      ),
      'page' => array(
        'position' => 2,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'Строка',
          'use_tail' => 1,
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -97;
  $export['breadcrumbs_apartment_other_pages'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_appartment_page';
  $path_breadcrumb->name = 'Хлебные крошки - Квартира';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%node:breadcrumbs_appartment_city',
      1 => 'Новостройки',
      2 => '%node:breadcrumbs_appartment_complex',
      3 => '%node:breadcrumbs_appartment_title',
    ),
    'paths' => array(
      0 => '<front>',
      1 => 'complexes/city/%node:breadcrumbs_appartment_city_id',
      2 => 'node/%node:breadcrumbs_appartment_complex_id',
      3 => 'node/%node:nid',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Содержимое: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'apartament' => 'apartament',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -92;
  $export['breadcrumbs_appartment_page'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_article';
  $path_breadcrumb->name = 'Хлебные крошки - Статья';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Главная',
      1 => 'Статьи',
      2 => '%node:title',
    ),
    'paths' => array(
      0 => '<front>',
      1 => '/articles',
      2 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Содержимое: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'myarticle' => 'myarticle',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['breadcrumbs_article'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_articles';
  $path_breadcrumb->name = 'Хлебные крошки - Все статьи';
  $path_breadcrumb->path = 'articles';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Главная',
      1 => 'Статьи',
    ),
    'paths' => array(
      0 => '<front>',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['breadcrumbs_articles'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_basic_page';
  $path_breadcrumb->name = 'Хлебные крошки - базовая страница';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Главная',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '<front>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'node_add',
        'settings' => array(
          'identifier' => 'Node add form: node type',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'basic_page' => 'basic_page',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['breadcrumbs_basic_page'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_comparison';
  $path_breadcrumb->name = 'Хлебные крошки - Сравнение';
  $path_breadcrumb->path = 'comparison';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Главная',
      1 => 'Сравнение',
    ),
    'paths' => array(
      0 => '<front>',
      1 => 'comparison',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['breadcrumbs_comparison'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_complex_list';
  $path_breadcrumb->name = 'Хлебные крошки - Новостройки';
  $path_breadcrumb->path = 'complexes/city/%taxonomy';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%taxonomy:name',
      1 => 'Новостройки',
    ),
    'paths' => array(
      0 => '<front>',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'taxonomy' => array(
        'position' => 2,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vids' => array(
            1 => '1',
            11 => 0,
            6 => 0,
            3 => 0,
            9 => 0,
            12 => 0,
            8 => 0,
            10 => 0,
            5 => 0,
          ),
          'breadcrumb' => 0,
          'transform' => 0,
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -99;
  $export['breadcrumbs_complex_list'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_complex_main_page';
  $path_breadcrumb->name = 'Хлебные крошки - ЖК основная страница';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Новосибирск',
      1 => 'Новостройки',
      2 => '%node:title',
    ),
    'paths' => array(
      0 => '<front>',
      1 => 'complexes/city/%node:breadcrumbs_city_id',
      2 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'node_edit',
        'settings' => array(
          'identifier' => 'Node edit form: node ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'complex' => 'complex',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -95;
  $export['breadcrumbs_complex_main_page'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_complex_other_pages';
  $path_breadcrumb->name = 'Хлебные крошки - ЖК остальные страницы';
  $path_breadcrumb->path = 'complexes/%node/%page';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%node:breadcrumbs_city',
      1 => 'Новостройки',
      2 => '%node:title',
    ),
    'paths' => array(
      0 => '<front>',
      1 => 'complexes/city/%node:breadcrumbs_city_id',
      2 => 'node/%node:nid',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Содержимое: ID',
        ),
      ),
      'page' => array(
        'position' => 2,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'Строка',
          'use_tail' => 1,
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -96;
  $export['breadcrumbs_complex_other_pages'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_contacts';
  $path_breadcrumb->name = 'Хлебные крошки - Контакты';
  $path_breadcrumb->path = 'contacts';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Главная',
      1 => 'Помощник',
      2 => 'Контакты',
    ),
    'paths' => array(
      0 => '<front>',
      1 => '/about',
      2 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['breadcrumbs_contacts'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_cooperation';
  $path_breadcrumb->name = 'Хлебные крошки - Сотрудничество';
  $path_breadcrumb->path = 'cooperation';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Главная',
      1 => 'Помощник',
      2 => 'Сотрудничество',
    ),
    'paths' => array(
      0 => '<front>',
      1 => '/about',
      2 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['breadcrumbs_cooperation'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_developer_list';
  $path_breadcrumb->name = 'Хлебные крошки - Застройщики';
  $path_breadcrumb->path = 'developers/city/%taxonomy';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%taxonomy:name',
      1 => 'Застройщики',
    ),
    'paths' => array(
      0 => '<front>',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'taxonomy' => array(
        'position' => 2,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vids' => array(
            1 => '1',
            11 => 0,
            6 => 0,
            3 => 0,
            9 => 0,
            12 => 0,
            8 => 0,
            10 => 0,
            5 => 0,
          ),
          'breadcrumb' => 0,
          'transform' => 0,
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -98;
  $export['breadcrumbs_developer_list'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_developer_main_page';
  $path_breadcrumb->name = 'Хлебные крошки - Застройщик основная страница';
  $path_breadcrumb->path = 'taxonomy/term/%taxonomy_term';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%taxonomy_term:breadcrumbs_city',
      1 => 'Застройщики',
      2 => '%taxonomy_term:title',
    ),
    'paths' => array(
      0 => '<front>',
      1 => 'developers/city/%taxonomy_term:breadcrumbs_city_id',
      2 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'taxonomy_term' => array(
        'position' => 2,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vids' => array(
            3 => '3',
            11 => 0,
            6 => 0,
            9 => 0,
            12 => 0,
            8 => 0,
            10 => 0,
            5 => 0,
            7 => 0,
            1 => 0,
          ),
          'breadcrumb' => 0,
          'transform' => 0,
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -93;
  $export['breadcrumbs_developer_main_page'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_developer_other_pages';
  $path_breadcrumb->name = 'Хлебные крошки - Застройщики остальные страницы';
  $path_breadcrumb->path = 'developer/%taxonomy_term/%page';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%taxonomy_term:breadcrumbs_city',
      1 => 'Застройщики',
      2 => '%taxonomy_term:title',
    ),
    'paths' => array(
      0 => '<front>',
      1 => 'developers/city/%taxonomy_term:breadcrumbs_city_id',
      2 => 'taxonomy/term/%taxonomy_term:tid',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'taxonomy_term' => array(
        'position' => 1,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vids' => array(
            3 => '3',
            11 => 0,
            6 => 0,
            9 => 0,
            12 => 0,
            8 => 0,
            10 => 0,
            5 => 0,
            7 => 0,
            1 => 0,
          ),
          'breadcrumb' => 1,
          'transform' => 0,
        ),
      ),
      'page' => array(
        'position' => 2,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'Строка',
          'use_tail' => 1,
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -94;
  $export['breadcrumbs_developer_other_pages'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_faq';
  $path_breadcrumb->name = 'Хлебные крошки - FAQ';
  $path_breadcrumb->path = 'faq';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Главная',
      1 => 'Помощник',
      2 => 'FAQ',
    ),
    'paths' => array(
      0 => '<front>',
      1 => '/guide',
      2 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['breadcrumbs_faq'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_guide';
  $path_breadcrumb->name = 'Хлебные крошки - Путеводитель';
  $path_breadcrumb->path = 'guide';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Главная',
      1 => 'Помощник',
      2 => 'Путеводитель',
    ),
    'paths' => array(
      0 => '<front>',
      1 => '/guide',
      2 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['breadcrumbs_guide'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_helper_about_project';
  $path_breadcrumb->name = 'Хлебные крошки - Помощник о проекте';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Главная',
      1 => 'Помощник',
      2 => 'О проекте',
    ),
    'paths' => array(
      0 => '<front>',
      1 => '/about',
      2 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'node_edit',
        'settings' => array(
          'identifier' => 'Node edit form: node ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'presentation' => 'presentation',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -95;
  $export['breadcrumbs_helper_about_project'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_mortgage_program';
  $path_breadcrumb->name = 'Хлебные крошки - Ипотека';
  $path_breadcrumb->path = 'mortgage/city/%taxonomy_term';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%taxonomy_term:name',
      1 => 'Ипотека',
    ),
    'paths' => array(
      0 => '<front>',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'taxonomy_term' => array(
        'position' => 2,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vids' => array(
            1 => '1',
            11 => 0,
            6 => 0,
            3 => 0,
            9 => 0,
            14 => 0,
            12 => 0,
            8 => 0,
            10 => 0,
            5 => 0,
            13 => 0,
          ),
          'breadcrumb' => 1,
          'transform' => 0,
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -97;
  $export['breadcrumbs_mortgage_program'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_mortgage_program_bank';
  $path_breadcrumb->name = 'Хлебные крошки - Ипотека банка';
  $path_breadcrumb->path = 'city/%taxonomy_term/mortgage/%term';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%taxonomy_term:name',
      1 => 'Ипотека',
    ),
    'paths' => array(
      0 => '<front>',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'taxonomy_term' => array(
        'position' => 1,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vids' => array(
            1 => '1',
            11 => 0,
            6 => 0,
            3 => 0,
            9 => 0,
            14 => 0,
            12 => 0,
            8 => 0,
            10 => 0,
            5 => 0,
            13 => 0,
          ),
          'breadcrumb' => 1,
          'transform' => 0,
        ),
      ),
      'term' => array(
        'position' => 3,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vids' => array(
            11 => '11',
            6 => 0,
            3 => 0,
            9 => 0,
            14 => 0,
            12 => 0,
            8 => 0,
            10 => 0,
            5 => 0,
            13 => 0,
            1 => 0,
          ),
          'breadcrumb' => 1,
          'transform' => 0,
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -97;
  $export['breadcrumbs_mortgage_program_bank'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_policy';
  $path_breadcrumb->name = 'Хлебные крошки - Политика';
  $path_breadcrumb->path = 'policy';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Главная',
      1 => 'Помощник',
      2 => 'Политика',
    ),
    'paths' => array(
      0 => '<front>',
      1 => '/about',
      2 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['breadcrumbs_policy'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumbs_remunerations';
  $path_breadcrumb->name = 'Хлебные крошки - Вознаграждения';
  $path_breadcrumb->path = 'remunerations';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Главная',
      1 => 'Помощник',
      2 => 'Вознаграждения',
    ),
    'paths' => array(
      0 => '<front>',
      1 => '/guide',
      2 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['breadcrumbs_remunerations'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'breadcrumds_user_profile';
  $path_breadcrumb->name = 'Хлебные крошки - профиль пользователя';
  $path_breadcrumb->path = 'user/%user';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Главная',
      1 => 'Личный кабинет',
    ),
    'paths' => array(
      0 => '<front>',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'user' => array(
        'position' => 1,
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['breadcrumds_user_profile'] = $path_breadcrumb;

  return $export;
}
