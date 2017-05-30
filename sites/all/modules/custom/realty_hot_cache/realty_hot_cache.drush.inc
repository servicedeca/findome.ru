
<?php

/**
 * Implements hook_drush_command().
 */
function realty_hot_cache_drush_command(){
    $items['run-hot-cache'] = array(
        'aliases' => array('rhc'),
        'callback' => 'realty_hot_cache_run',
    );
    return $items;
}

/**
 * Callback for 'apartment-update'drush command.
 */
function realty_hot_cache_run() {
    $complexes = db_query("SELECT node.nid, node.title FROM node WHERE node.type = 'complex'")->fetchAll();

    foreach ($complexes as $key => $complex) {
        $data = file_get_contents("http://novosibirsk.findome.dev/node/$complex->nid");
        print "$key\n";
    }

}

