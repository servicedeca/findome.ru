
<?php

/**
 * Implements hook_drush_command().
 */
function realty_data_update_drush_command(){
    $items['apartment-update'] = array(
        'description' => 'Apartment update',
        'aliases' => array('aup'),
        'callback' => 'realty_data_update_drush_apartment_update',
    );

    $items['add_new_apartments'] = array(
        'description' => 'Add new Apartments',
        'aliases' => array('ana'),
        'callback' => 'realty_data_update_drush_add_new_apartments',
    );

    return $items;
}

/**
 * Callback for 'apartment-update'drush command.
 */
function realty_data_update_drush_apartment_update() {
    $met_st = FALSE;
    $methods = realty_data_update_method_update();
    realty_data_update_update_table_new_apartments();
    realty_data_update_delete_new_apartments_table();

    foreach ($methods as $method) {
        $log_data['start'] = date("m.d.y-H:i");
        if ($method->method == 'FTP' && $method->format == 'XML') {
            $log = realty_data_update_ftp_xml($method);
            if($log) {
                $log_data = $log_data + $log;
            }
        }
        if ($method->method == 'FTP' && $method->format == 'excel') {
            $log = realty_data_update_ftp_excel($method);
            if($log) {
                $log_data = $log_data + $log;
            }
        }
    }

    if (isset($log_data)) {
        $log_data['end'] = date("m.d.y-H:i");
        realty_data_update_writeLog($log_data);
        unset ($log_data);
    }
}

/**
 * Callback for 'add_new_apartments' drush command.
 */
function realty_data_update_drush_add_new_apartments() {
    $met_st = FALSE;
    $methods = realty_data_update_method_update();

    printf ("==================================================================================================== \n");
    foreach ($methods as $key => $method) {
        printf ("[%s] %s \n", $key, $method->name[0]);
    }
    printf ("\n");
    printf ("Введите номер файла:  ");

    while(1) {
        fscanf(STDIN, "%d\n", $number);
        if(isset($methods[$number])) {
            if ($methods[$number]->method == 'FTP' && $methods[$number]->format == 'XML') {
                realty_data_update_add_apartments_ftp_xml($methods[$number]);
                printf ("Exit\n");
                return;
            }
            if ($methods[$number]->method == 'FTP' && $methods[$number]->format == 'excel') {
                realty_data_update_add_apartments_ftp_excel($methods[$number]);
                printf ("Exit\n");
                return;
            }
            else {
                printf ("Error\n");
                printf ("Введите номер файла:  ");
            }
        }
    }
}

