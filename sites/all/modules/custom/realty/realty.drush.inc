  <?php

/**
 * Implements hook_drush_command().
 */
function realty_drush_command(){
  $items['realty-node-update'] = array(
    'description' => 'Update node',
    'aliases' => array('rnu'),
    'callback' => 'realty_node_update_drush',
  );

  return $items;
}

/**
 * Callback for 'apartment-update' drush command.
 */
function realty_node_update_drush(){

  $complexes = db_query("SELECT node.nid, node.title FROM node WHERE node.type = 'complex'")->fetchAll();

  foreach ($complexes as $key => $complex) {
    printf ("[%s] %s \n", $key, $complex->title);
  }
  printf ("\n");
  printf ("Выберите ЖК:  ");

  fscanf(STDIN, "%d\n", $num);

  $apartments = db_query("SELECT node.nid FROM node
                          LEFT JOIN field_data_field_apartament_home ON node.nid = field_data_field_apartament_home.entity_id
                          LEFT JOIN field_data_field_home_complex ON field_data_field_apartament_home.field_apartament_home_tid = field_data_field_home_complex.entity_id
                          WHERE node.type = 'apartament'
                            AND field_data_field_home_complex.field_home_complex_target_id = :complex_nid",
                            array(':complex_nid' => $complexes[$num]->nid))->fetchAll();


  if ($apartments) {
    foreach ($apartments as $apartment) {
      $node = node_load($apartment->nid);
      //$node->status = 1;
      node_save($node);
      printf ("save - %s \n", $apartment->nid);
    }
  }

/*
  $query = "SELECT node.nid
            FROM node
            LEFT JOIN field_data_field_apartament_home ON field_data_field_apartament_home.entity_id = node.nid
            WHERE field_data_field_apartament_home.field_apartament_home_tid = :home_tid";

  $db_args = array (
    ':home_tid' => '104'
  );

  $query_apartments = db_query($query, $db_args)->fetchAll();

  foreach($query_apartments as $result_node) {
    $node = node_load($result_node->nid);
    $node->field_apartament_home['und'][0]['tid'] = '176';
    node_save($node);
    print ('Update nid ' . $result_node->nid);
  }*/
}