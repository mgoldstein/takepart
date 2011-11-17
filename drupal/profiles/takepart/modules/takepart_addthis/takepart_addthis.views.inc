<?php

/**
 * @file
 * PRovide views data and handlers for addthis.module
 */

//hook_views_data_alter
function takepart_addthis_views_data_alter(&$data){
 $data['views']['addthis'] = array(
    'title' => 'AddThis',
    'help' => 'Inserts an AddThis toolbox linking to the node',
    'field' => array(
      'handler' => 'views_handler_addthis',
    ),
  );
}
