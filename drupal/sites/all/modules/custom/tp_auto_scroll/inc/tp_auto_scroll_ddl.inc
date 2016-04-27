<?php

/**
 * DDL for autoloaded nodes
 * This is temporary while we refactor tp_digital_data
 */


function tp_auto_scroll_build_ddl_event($id, $ddl){
  $data = array();

  $data['eventName'] = 'Page Auto Load';
  $data['eventInstanceID'] = $id;
  $data['eventInfo'] = $ddl;

  return $data;
}
