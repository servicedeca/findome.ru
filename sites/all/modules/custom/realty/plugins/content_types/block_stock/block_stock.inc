<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_block_stock_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Block stock'),
    'all contexts' => TRUE,
    'category' => t('Realty'),
    'hook theme' => 'realty_block_stock_content_type_theme',
  );
}

/**
 * Implements hook_content_type_render().
 */
function realty_block_stock_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = theme('realty_block_stock');

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function realty_block_stock_content_type_theme(&$theme, $plugin) {
  $theme['realty_block_stock'] = array(
    'path' => $plugin['path'],
    'template' => 'realty-block-stock',
  );
}

/**
 * Process variables for realty-block-stock.tpl.php.
 */
function template_preprocess_realty_block_stock(&$vars) {

  $city = menu_get_object('taxonomy_term', 2);

  $stock = views_get_view_result('stock', 'stock');

  if ($stock) {
    $i = 0;
    foreach ($stock as $key => $val) {
      if ($val->field_field_priority[0]['raw']['value'] == '0') {
        $image = theme('image', array(
            'path' => $val->field_field_image[0]['raw']['uri'],
            'attributes' => array(
              'class' => array('title-image'),
            ),
          )
        );
        $vars['stock'][$i] = array(
          'title' => l($val->node_title, 'stock/city/' . $city->tid, array('html' => true, 'query' => array('stock' => $val->nid))),
          'description' => $val->field_field_mini_description[0]['raw']['safe_value'],
          'developer' => $val->taxonomy_term_data_field_data_field_complex_developer_name,
          'image' => l($image, 'stock/city/' . $city->tid, array('html' => true, 'query' => array('stock' => $val->nid))),
          'details' => l(t('details'), 'stock/city/' . $city->tid,
            array('attributes' => array('class' => array('button-info', 'stock-button', 'cb-b-stock')),
              'query' => array('stock' => $val->nid),
            )
          ),
        );
        $i++;
      }
      elseif($val->field_field_priority[0]['raw']['value'] == '1') {
        $image = theme('image', array(
            'path' => $val->field_field_image[0]['raw']['uri'],
            'attributes' => array(
              'class' => array('title-image'),
            ),
          )
        );
        $vars['priority_stock'] = array(
          'title' => l($val->node_title, 'stock/city/' . $city->tid, array('html' => true, 'query' => array('stock' => $val->nid))),
          'description' => $val->field_field_mini_description[0]['raw']['safe_value'],
          'developer' => $val->taxonomy_term_data_field_data_field_complex_developer_name,
          'image' => l($image, 'stock/city/' . $city->tid, array('html' => true, 'query' => array('stock' => $val->nid))),
          'details' => l(t('details'), 'stock/city/' . $city->tid,
            array('attributes' => array('class' => array('button-info', 'stock-button', 'cb-b-stock')),
              'query' => array('stock' => $val->nid),
            )
          ),
        );
      }
    }
  }

  $vars['micro_logo'] = realty_get_image_micro_logo();

  $vars['all_stock'] = '/stock/city/' . $city->tid;
}