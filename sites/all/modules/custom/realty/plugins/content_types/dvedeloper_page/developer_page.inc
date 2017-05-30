<?php
/**
 * @file
 * Ctools content type new_message.
 */

/**
 * Implements hook_ctools_content_types().
 */
function realty_developer_page_ctools_content_types() {
    return array(
        'single' => TRUE,
        'title' => t('Developer page'),
        'all contexts' => TRUE,
        'category' => t('Realty'),
       // 'hook theme' => 'realty_developer_page_content_type_theme',
    );
}

/**
 * Implements hook_content_type_render().
 */
function realty_developer_page_content_type_render($subtype, $conf, $panel_args, $context) {
    $account = reset($context)->data;
    $block = new stdClass();
    $block->content = '<div class="download-container-dev container-cap">
            <img src="http://novosibirsk.findome.ru/sites/all/themes/realty_theme/images/minilogo.svg">
            <p>Уважаемые пользователи сервиса Findome!<br>
                Данный раздел находится в стадии разработки.<br>
                Раздел будет доступен 20.06.2017
            </p>
        </div>';

    return $block;
}
