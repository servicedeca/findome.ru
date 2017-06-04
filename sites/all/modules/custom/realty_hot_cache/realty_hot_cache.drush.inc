
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
    //ЖК
    print "ЖК\n\n\n\n";
    $complexes = db_query("SELECT node.nid, node.title FROM node WHERE node.type = 'complex'")->fetchAll();
    $complex_page = [
        'plan',
        'gallery',
        'mortgage',
        'stock',
        'reviews',
        'rating'
    ];

    foreach ($complexes as $key => $complex) {
        $data = file_get_contents("http://novosibirsk.findome.ru/node/$complex->nid");
        print "http://novosibirsk.findome.ru/node/$complex->nid\n";

        foreach ($complex_page as $page) {
            file_get_contents("http://novosibirsk.findome.ru/node/$complex->nid/$page");
            print "http://novosibirsk.findome.ru/node/$complex->nid/$page\n";
        }
    }

    //Застройщики
    print "Застройщики\n\n\n";
    $developers = db_query("SELECT taxonomy_term_data.tid, taxonomy_term_data.name FROM node WHERE taxonomy_term_data.vid = '3'")->fetchAll();

    foreach ($developers as $key => $developer) {
        $data = file_get_contents("http://novosibirsk.findome.ru/taxonomy/term/$developer->tid");
        print "http://novosibirsk.findome.ru/taxonomy/term/$developer->tid\n";
    }

    $developer_page = [
        'complexes',
        'gallery',
        'stock',
        'reviews',
    ];

    foreach ($developer_page as $page) {
        file_get_contents("http://novosibirsk.findome.ru/taxonomy/term/$developer->tid/$page");
        print "http://novosibirsk.findome.ru/taxonomy/term/$developer->tid/$page\n";
    }

    print "квартиры:\n";
    //квартиры
    $apartments = db_query("SELECT node.nid, node.title FROM node WHERE node.type = 'apartament' and status=1")->fetchAll();
    $apartments_page = [
        'plan',
        'purchase_terms',
        'mortgage',
    ];

    foreach ($apartments as $key => $apartment) {
        $data = file_get_contents("http://novosibirsk.findome.ru/node/$apartment->nid");
        print "http://novosibirsk.findome.ru/node/$apartment->nid\n";

        foreach ($apartments_page as $page) {
            file_get_contents("http://novosibirsk.findome.ru/node/$apartment->nid/$page");
            print "http://novosibirsk.findome.ru/node/$apartment->nid/$page\n";
        }
    }
}

