<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_front_page_ctools_content_types()
{
  return array(
    'single' => TRUE,
    'title' => t('Front page'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_front_page_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_front_page_content_type_render($subtype, $conf, $panel_args, $context)
{
  $block = new stdClass();
  $block->content = theme('realty_front_page');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_front_page_content_type_theme(&$theme, $plugin)
{
  $theme['realty_front_page'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-front-page',
  );
}

/**
 * Process variables for realty-block-stock.tpl.php.
 */
function template_preprocess_realty_front_page(&$vars)
{
  /*
    $page = arg(0);

    switch ($page) {
      case 'complexes': {
        $complex_nid = arg(1);

        $vars['stock'] = views_embed_view('stock', 'stock_complex', $complex_nid);

        $node = node_load($complex_nid);
        $vars['background'] = '/' . realty_file_directory_path() . '/' . $node->field_main_photo[LANGUAGE_NONE][0]['filename'];

        break;
      }
      case 'developer': {
        $developer_tid = arg(1);

        $vars['stock'] = views_embed_view('stock', 'stock_developer', $developer_tid);

        $complexes = views_get_view_result('complex', 'complex_developers', $developer_tid);

        $index = rand (0, count($complexes) - 1);
        $vars['background'] = '/' . realty_file_directory_path() . '/' . $complexes[$index]->field_field_main_photo[0]['raw']['filename'];

        break;
      }
    }*/

  $vars['img_white_logo'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/white_logo.svg',
      'attributes' => array(
        'class' => array('white-logo'),
      ),
    )
  );

  $vars['img_houses'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/houses_main.svg',
      'attributes' => array(
        'class' => array('houses'),
      ),
    )
  );

  $vars['img_houses_mobile'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/mobile_header-01.png',
      'attributes' => array(
        'class' => array('houses_mobile'),
      ),
    )
  );

  $vars['img_flats_main'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/flats_main.svg',
      'attributes' => array(
        'class' => array('flats-main'),
      ),
    )
  );

  $vars['img_net_main'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/net_main.svg',
      'attributes' => array(
        'class' => array('net-main'),
      ),
    )
  );

  $vars['img_line1'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/line1.svg',
      'attributes' => array(
        'class' => array('line1'),
      ),
    )
  );
  $vars['img_line2'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/line_2.svg',
      'attributes' => array(
        'class' => array('line2'),
      ),
    )
  );

  $vars['img_mtf'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/mtf.png',
      'attributes' => array(
        'class' => array('mtf'),
      ),
    )
  );

  $vars['img_mtf2'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/mtf2.png',
      'attributes' => array(
        'class' => array('mtf2'),
      ),
    )
  );

  $vars['img_fmi_1'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/fmi-1.svg',
      'attributes' => array(
        'class' => array('fmi-icon'),
      ),
    )
  );

  $vars['img_fmi_2'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/fmi-2.svg',
      'attributes' => array(
        'class' => array('fmi-icon'),
      ),
    )
  );

  $vars['img_fmi_3'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/fmi-3.svg',
      'attributes' => array(
        'class' => array('fmi-icon'),
      ),
    )
  );

  $vars['img_fmi_4'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/fmi-4.svg',
      'attributes' => array(
        'class' => array('fmi-icon'),
        'style' => array('margin-top:-80px;')
      ),
    )
  );

  $vars['img_fm_flatmodal'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/fm_flatmodal.png',
      'attributes' => array(
        'class' => array('flatmodal'),
      ),
    )
  );

  $vars['img_fm_flatplane'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/fm_flatplane.png',
      'attributes' => array(
        'class' => array('flatplane'),
      ),
    )
  );

  $vars['img_fm_iconsnake'] = theme('image', array(
      'path' => REALTY_FRONT_THEME_PATH . '/images/fm_iconsnake.svg',
      'attributes' => array(
        'class' => array('iconsnake'),
      ),
    )
  );

  // Формирование списка городов
  $terms_cities = taxonomy_get_tree(1);
  foreach ($terms_cities as $city) {
    $vars['cities'][$city->tid] = $city->name;
  }

  $vars['types'] = realty_options_search('room');
  $vars['img_mlogo'] = theme ('image', array(
    'path' => REALTY_FRONT_THEME_PATH . "/images/findome_m.png"
  ));
}