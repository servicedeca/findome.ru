<?php
/**
 * @file
 * realty_feature_page_news.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function realty_feature_page_news_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'all_news';
  $page->task = 'page';
  $page->admin_title = 'Все новости';
  $page->admin_description = '';
  $page->path = 'news/city/%tid';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'tid' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
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
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_all_news__panel_context_dfd99691-d2ff-4b8e-9a18-60c73dd4b751';
  $handler->task = 'page';
  $handler->subtask = 'all_news';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Новости';
  $display->uuid = 'c6e83a5b-93c5-4511-893f-d68999af1f38';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e3fa7964-8085-46c5-bccb-17294a875627';
    $pane->panel = 'middle';
    $pane->type = 'page_breadcrumb';
    $pane->subtype = 'page_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e3fa7964-8085-46c5-bccb-17294a875627';
    $display->content['new-e3fa7964-8085-46c5-bccb-17294a875627'] = $pane;
    $display->panels['middle'][0] = 'new-e3fa7964-8085-46c5-bccb-17294a875627';
    $pane = new stdClass();
    $pane->pid = 'new-c09ac551-baa6-4d86-9740-3aa12105fc4a';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'news-all_new_city';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c09ac551-baa6-4d86-9740-3aa12105fc4a';
    $display->content['new-c09ac551-baa6-4d86-9740-3aa12105fc4a'] = $pane;
    $display->panels['middle'][1] = 'new-c09ac551-baa6-4d86-9740-3aa12105fc4a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['all_news'] = $page;

  return $pages;

}
