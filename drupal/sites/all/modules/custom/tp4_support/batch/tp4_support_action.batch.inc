<?php

/**
 *  @function:
 *    retrieve the file
 */
function _tp4_support_retrieve_file(&$context) {
  //default variable
  $url = variable_get('tp4_support_action_url', 'http://takeaction.takepart.com/api/actions');

  //retrieve the file
  $file = file_get_contents($url);
  
  //adds the file into results
  $context['results']['file'] = $file;
  
  //marks this batch op as finish
  $context['finished'] = 1;
}

/**
 *  @Function:
 *    Action processor for tp4
 */
function _tp4_support_action_processor(&$context) {
  //sets variable for file
  $file = $context['results']['file'];
  
  //ensures that the file is not empty
  if (!empty($file)) {
    $file_json = json_decode($file);
    
    //preps data
    $action_id = array();
    foreach ($file_json as $key => $value) {
      //only adds published
      if ($value->published) {
        $action_id[] = $value->action_id;
      }
    }
    
    //grabs all nids from drupal
    $db_result = db_select('signature_node', 'sn')
      ->fields('sn', array('nid'))
      ->condition('sn.tap_id', $action_id, 'IN')
      ->execute()->fetchAll();
    
    //preps data
    $tap_action_id = array();
    foreach ($db_result as $key => $value) {
      $tap_action_id[$value->nid] = $value->nid;
    }
    
    //grabs all nodes
    $db_result = db_select('node_revision', 'nr')
      ->fields('nr', array('nid'));
    $db_result->leftJoin('node', 'n', 'n.nid = nr.nid');
    $db_result->condition('n.type', 'action', '=')
      ->condition('nr.status', 1, '=');
    $db_result = $db_result->execute()->fetchAll();
      
    //preps data
    $action_nid = array();
    foreach ($db_result as $key => $value) {
      $action_nid[$value->nid] = $value->nid;
    }
    
    //compares the diff
    $disable = array_diff($action_nid, $tap_action_id);
    
    //adds to results for processing
    $context['results']['disable_nid'] = $disable;
  }
  
  //marks this batch op as finish
  $context['finished'] = 1;
}

/**
 *  @function:
 *    Function is used to unpublish the nodes
 */
function _tp4_support_db_unpublisher(&$context) {
  $disable = $context['results']['disable_nid'];
  
  //ensures that it only continues if its not empty
  if (!empty($disable)) {
    $disable = array_values($disable);
    $db_update = db_update('node')
      ->fields(array(
        'status' => 0, //changes status to 0
      ))
      ->condition('type', 'action', '=')
      ->condition('nid', $disable, 'IN')
      ->execute();
      
    //disables the revision
    $db_revision_update = db_update('node_revision')
      ->fields(array(
        'status' => 0, //changes status to 0
      ))
      ->condition('nid', $disable, 'IN')
      ->execute();
  }
  //gives a default message for disabled
  elseif (empty($disable)) {
    $disable = 'None';
  }

  watchdog('action_disabled', 'Disabled nid <pre>' . print_r($disable, 1) . '</pre>');
  
  //marks this batch op as finish
  $context['finished'] = 1;
}

/**
 *  @function:
 *    batch operation for the finish portion
 */
function _tp4_support_action_finished($success, $results, $operations) {
  drupal_set_message('Batch Operation for action unpublishing is complete');
}