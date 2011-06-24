<?php
/*
 * implimentation of hook_nodeapi()
 *
 * On inserting the node we are recording that the node is ready for queueing
 */
function takepart_newsletter_signup_bulk_feature_nodeapi(&$node, $op) {
  if ($node->type == "email_batch_load") {
    if ($op =='insert') {
      $nodes_to_queue = variable_get('takepart_newsletter_signup_bulk_feature_nodes_to_queue', array());
      $nodes_to_queue[] = $node->nid;
      variable_set('takepart_newsletter_signup_bulk_feature_nodes_to_queue', $nodes_to_queue);
    }
  }
}

/*
 * Find the nex node ready for queueing parse its csv file and load it in the queue
 */
function takepart_newsletter_signup_bulk_feature_populate_queue_next_node() {
  $lock_timeout = variable_get("takepart_newsletter_signup_bulk_feature_populate_queue_next_node_timeout", 7200);
  $lock_id = "takepart_newsletter_signup_bulk_feature_populate_queue_next_node";
  if (lock_acquire($lock_id, $lock_timeout)) {
    // Have issue with varirables being cached so we are going to pull the queue from the db
    $nodes_to_queue = unserialize(db_result(db_query("select value from variable where name like 'takepart_newsletter_signup_bulk_feature_nodes_to_queue'")));
    //$nodes_to_queue = variable_get('takepart_newsletter_signup_bulk_feature_nodes_to_queue', array());
    $nodes_to_queue = $nodes_to_queue ? $nodes_to_queue: array();
    $next_nid = array_shift($nodes_to_queue);
    if ($node = node_load($next_nid)) {

      // populate the queue
      takepart_newsletter_signup_bulk_feature_populate_queue($node);
      //preprocess the queue entries
      takepart_newletter_signup_bulk_feature_preprocess($node);
      watchdog('takepart_newsletter_signup_bulk_feature',"Ran queue next node for node $next_nid");
    }
    else {
      watchdog('takepart_newsletter_signup_bulk_feature',"Skipped queue next node as there is no node to queue.");
    }
    // remove node from nodes_to_queue and release lock
    $nodes_to_queue = variable_get('takepart_newsletter_signup_bulk_feature_nodes_to_queue', array());
    //having issue with create_function so doing this nonfunctional
    //$nodes_to_queue = array_filter($nodes_to_queue, create_function('$a', 'return $a !='.$next_nid.';'));
    foreach ($nodes_to_queue as $nid) {
      if ($nid != $next_nid) {
        $nodes_to_queue_new[] = $nid;
      }
    }
    variable_set('takepart_newsletter_signup_bulk_feature_nodes_to_queue', $nodes_to_queue_new);
    lock_release($lock_id);
  }
  else {
    watchdog('takepart_newsletter_signup_bulk_feature',"Shipping queue next node as there is a lock");
  }
}

/*
 * Using a email_batch_load node
 * Will populate the tp_newsletter_signups_queue table with records
 * from the cvs file in the node.S
 *
 * NOTE: It Does the inserts in batches so that we do not load the
 * whole csv file into memory at one time
 */
function takepart_newsletter_signup_bulk_feature_populate_queue($node) {
  $campaign_node = node_load($node->field_ebl_campaign[0]['nid']);

  $parse_options = array(
    'load_nid'            => $node->nid,
    'campaign_code'       => $campaign_node->field_newsletter_campaign_id[0]['value'],
    'source'              => $node->field_ebl_source[0]['value'],
    'send_welcome'        => $node->field_ebl_send_welcome[0]['value'],
    'action'              => $node->field_ebl_action[0]['value'],
    'action_index'        => $node->field_ebl_action_index[0]['value'],
    'email_index'         => $node->field_ebl_email_index[0]['value'],
    'source_index'        => $node->field_ebl_source_index[0]['value'],
    'send_welcome_index'  => $node->field_ebl_send_welcome_index[0]['value'],
    'campaign_code_index' => $node->field_ebl_campaign_id_index[0]['value']
  );
  $has_header        = $node->field_ebl_has_header[0]['value'];
  $file_path         = $node->field_ebl_csv_file[0]['filepath'];
  $batch_size        = variable_get("email_batch_load_queue_batch_size", 10000);

  $queue_insert_fields = array('email', 'source', 'campaign_code', 'load_nid', 'send_welcome', 'action');

  // Build insert_placeholders.
  // should be able to do this with map but did not happen
  // we are building the placeholder sting to be used for the fields
  // we want to insert into tp_newsletter_signups_queue
  $queue_schema = drupal_get_schema("tp_newsletter_signup_bulk_queue");
  $placeholders_array = array();
  foreach ($queue_insert_fields as $field) {
    $placeholders_array[] = 
      db_type_placeholder($queue_schema["fields"][$field]["type"]);
  }
  $insert_placeholders = "(". implode(", ", $placeholders_array) .")";

  // We are going to open the file start processing it until we are finished 
  // with it
  ini_set('auto_detect_line_endings',TRUE);
  $handler = fopen($file_path, "r");
  ini_restore($setting);

  // Currently not using header info but just pulling it out of the file
  if (!$handler) {
    watchdog('takepart_newsletter_signup_bulk_feature',
      "Can''t open file $file_path for node ".$node->nid.'.'
      );
    return;  
  }
  if ($has_header) {
    $headers = fgetcsv($handler);
  }
  while(!feof($handler)) {
    // grab a chunk of data formated for insertion 
    $data = _takepart_newsletter_signup_bulk_feature_get_batch_queue_data($handler, $parse_options, $batch_size);
    $query_data = array(); 
    $query_placeholders = array();

    //for each row of data we need to add a new set of place holders
    //as well as adding each field to the query data
    foreach ($data as $row) {
      $query_placeholders[] = $insert_placeholders;
      foreach ($queue_insert_fields as $field) {
        $query_data[] = $row[$field];
      }
      
    }

    $query = "INSERT INTO {tp_newsletter_signup_bulk_queue}" .
             " (".implode(",", $queue_insert_fields).")".
             " VALUES ".implode(",", $query_placeholders);
    $a = db_query($query, $query_data);
  }

}

/*
 * returns an array of items of no bigger the batch_size that can be parsed
 * to be imported into the queue table
 */
function _takepart_newsletter_signup_bulk_feature_get_batch_queue_data(&$handler, $parse_options, $batch_size) {

  $data = array();
  $i = 0;
  while ($i < $batch_size && ($row = fgetcsv($handler)) !== FALSE) {
    static $campaign_codes;
    $campaign_codes = $campaign_codes ? $campaign_codes :
     _takepart_newsletter_signup_bulk_feature_get_campaign_codes();

    # if we are using the sorce from the file lets trim it
    $source = 
      $parse_options['source_index'] != 'none' &&   
        ($c = trim($row[$parse_options['source_index']])) ?
      $c :
      $parse_options['source'];

    # if we are to use the code from the file trim it and lower it
    # and insure it is a real code
    $campaign_code = 
      $parse_options['campaign_code_index'] != 'none' &&   
        ($c = trim(strtolower($row[$parse_options['campaign_code_index']]))) &&
        in_array($c, $campaign_codes) ?
      $c :
      $parse_options['campaign_code'];


    // Parse Action insure it is formated correctly
    $action = 
      $parse_options['action_index'] != 'none' &&
        ($c = strtolower(trim($row[$parse_options['action_index']]))) &&
        in_array($c, array('s', 'u')) ?
      $c :
      $parse_options['action'];

    // Parse Action Send Welcome email it is formated correctly
    $send_welcome = 
      $parse_options['send_welcome_index'] != 'none' &&
        ($c = strtolower(trim($row[$parse_options['send_welcome_index']]))) &&
        in_array($c, array('y', 'n')) ?
      $c :
      $parse_options['send_welcome'];
    // turn welcome intoa bool
    $send_welcome = $send_welcome == 'y' ? 1 : 0;

    $data[] = array(
      "campaign_code" => $campaign_code,
      "source"        => $source,
      "action"        => $action,
      "send_welcome"  => $send_welcome,
      "email"         => $row[$parse_options['email_index']],
      "load_nid"      => $parse_options['load_nid']
    );
    $i ++;
  }
  return $data;
}

/*
 * Preprocess queued emails to insure
 * 1) they are not already in the email table
 * 2) the email is relatively well formed.
 * When done we set the is_preprocess flag
 */
function takepart_newletter_signup_bulk_feature_preprocess($node) {
  
  $exists_err_msg = "Email is already subscribed";
  $unsubscribed_err_msg = "Email is unsubscribed";
  $email_err_msg = "Email is not well formed";
  $exist_query= <<<EXIST
  UPDATE tp_newsletter_signup_bulk_queue q, tp_newsletter_signups e 
  SET error_msg = CASE WHEN e.status = 'u' THEN '%s' ELSE '%s' END,
      has_error = 1,
      is_processed = 1,
      is_preprocessed =1
  WHERE q.email = e.mail AND q.campaign_code = e.campaign_id AND q.load_nid = %d
EXIST;
  $email_check_query= <<<EMAIL
  UPDATE tp_newsletter_signup_bulk_queue q 
  SET error_msg = '%s',
      has_error =1,
      is_processed = 1,
      is_preprocessed = 1
  WHERE q.email not like '%@%.%' AND q.load_nid = %d
EMAIL;
  $done_preprocess_query= <<<DONE
  UPDATE tp_newsletter_signup_bulk_queue q 
  SET is_preprocessed = 1
  WHERE is_preprocessed <> 1 AND q.load_nid = %d
DONE;
  $results = db_query($exist_query, $unsubscribed_err_msg, $exists_err_msg, $node->nid);
  $results = db_query($email_check_query, $email_err_msg, $node->nid);
  $results = db_query($done_preprocess_query, $node->nid);
}

/*
 * This function will process the next X items that our in the queue
 */
function takepart_newsletter_signup_bulk_feature_process_items() {
  $process_limit = variable_get('takepart_newsletter_signup_bulk_feature_process_limit', 10000);
  $process_timeout = variable_get('takepart_newsletter_signup_bulk_feature_process_timeout', 10000);
  $process_items_query = <<<ITEMS
    SELECT * 
    FROM tp_newsletter_signup_bulk_queue 
    WHERE is_processed = 0 AND is_preprocessed = 1 
    ORDER BY queue_id 
    LIMIT %d
ITEMS;
 
  if (lock_acquire('takepart_newsletter_signup_bulk_feature_process_items', $process_timeout)) {
    $results = db_query($process_items_query, $process_limit);
    $process_count =0;
    while ($row = db_fetch_object($results) ) {
      _takepart_newsletter_signup_bulk_feature_process_item($row);
      $process_count ++;
    }
    lock_release('takepart_newsletter_signup_bulk_feature_process_items');
    watchdog('takepart_newsletter_signup_bulk_feature',"Ran Process items for $process_count items." );
  }
  else {
    watchdog('takepart_newsletter_signup_bulk_feature',"Skipped process items as there is a lock" );
  }
  
 
} 

/*
 * given a row from the queue call newsletter save and record if there 
 * is an error
 */
function _takepart_newsletter_signup_bulk_feature_process_item($row) {
  $response = takepart_newsletter_save_campaign($row->email, $row->campaign_code, $row->action, $row->source, $row->send_welcome);
  if ($response['status'] == 0) {
    $row->has_error = 1;
    $row->error_msg = "Pluris: ". $response['message'];
  }
  $row->is_processed = 1;
  drupal_write_record('tp_newsletter_signup_bulk_queue', $row, 'queue_id');
}

/*
 * find a load that is read to have its report generated and do it!
 */
function takepart_newsletter_signup_bulk_feature_generate_next_report() {
  $candidates = _takepart_newsletter_signup_bulk_feature_get_report_canidates();
  $lock_key = "takepart_newsletter_signup_bulk_feature_generate_next_report";
  $lock_timeout = variable_get("takepart_newsletter_signup_bulk_feature_generate_next_report_timeout", 5000);
  if ( 
    ($load_nid = $candidates[0]) && 
    ($load_node = node_load($load_nid)) &&
    lock_acquire($lock_key, $lock_timeout) ) {
      takepart_newsletter_signup_bulk_feature_generate_report($load_node);
      lock_release($lock_key);

      watchdog('takepart_newsletter_signup_bulk_feature',"Ran generate report for node $load_nid." );

  }
  else if (!$candidate) {
   watchdog('takepart_newsletter_signup_bulk_feature',"Skipped generate report no node is ready." );
  }
  else {
   watchdog('takepart_newsletter_signup_bulk_feature',"Skipped generate report there is a lock." );
  }
}

/*
 * return an array of nid for nodes that have all of there emails in 
 * the queue processed
 */
function _takepart_newsletter_signup_bulk_feature_get_report_canidates() {

  $candidate_query = <<<CANDIDATE
    SELECT load_nid 
    FROM {tp_newsletter_signup_bulk_queue} 
    GROUP BY load_nid 
    HAVING sum(is_processed) = count(load_nid)
CANDIDATE;
  $results = db_query($candidate_query);
  $candidates = array();
  while ($row = db_fetch_object($results)) {
    $candidates[] = $row->load_nid;
  }
  return $candidates;
}

/*
 * Pull from the queue and populate the cck report fields for a bulk email noe
 */
function takepart_newsletter_signup_bulk_feature_generate_report($node, $clean_queue = TRUE) {

  //Generate Totals
  $total_query = <<<TOTAL
    SELECT sum(has_error) errors, sum(is_processed) total
    FROM {tp_newsletter_signup_bulk_queue} 
    WHERE is_processed = 1 and load_nid = %d
TOTAL;
  $totals = db_fetch_object(db_query($total_query, $node->nid));
  $node->field_ebl_error_count[0]['value'] = $totals->errors;
  $node->field_ebl_success_count[0]['value'] = $totals->total - $totals->errors;
  $node->field_ebl_processed_count[0]['value'] = $totals->total;

  //Generate Summary
  $summary_query = <<<SUMMARY
    SELECT sum(has_error) errors, error_msg 
    FROM {tp_newsletter_signup_bulk_queue} 
    WHERE is_processed = 1 and load_nid = %d
    GROUP BY error_msg HAVING sum(has_error) > 0
SUMMARY;
  $summary_handle = db_query($summary_query, $node->nid);
  $s_rows = array();
  while ($row = db_fetch_object($summary_handle)) {
    $s_rows[] = array($row->error_msg, $row->errors); 
  }
  $summary = theme('table', array("error", "count"), $s_rows);
  $node->field_ebl_error_summary[0]['value'] = $summary;
  // set the format to full html
  $node->field_ebl_error_summary[0]['format'] = 2;


  //Generate Details
  $detail_query = <<<DETAIL
    SELECT * 
    FROM {tp_newsletter_signup_bulk_queue} 
    WHERE is_processed = 1 and load_nid = %d
DETAIL;
  $db_handle = db_query($detail_query, $node->nid);
  $file = new StdClass();
  $file->filename = "details-". $node->nid .".csv";
  $file->filepath = file_directory_path() ."/". $file->filename;
  try {
    $file_handle = fopen($file->filepath, 'w');
  }
  catch(Exception $e) {
    watchdog('akepart_newsletter_signup_bulk_feature',
      'Can not write details for '.$node->nid.'.'
      );
    return;  
  }
  fputcsv(
    $file_handle,
      array(
        'email',
        'source',
        'campaign_code',
        'action',
        'send_welcome',
        'has_error',
        'error_msg'
     )
  );
  while ($row = db_fetch_object($db_handle) ){
    fputcsv(
      $file_handle, 
      array(
        $row->email,
        $row->source,
        $row->campaign_code,
        $row->action,
        $row->send_welcome ? 'y' : 'n',
        $row->has_error ? 'y' : 'n',
        $row->error_msg
      )
    );
  }
  fclose($file_handle);
  $file->filesize = filesize($file->filepath);
  $file->filemime = 'text/cvs';
  $file->status = FILE_STATUS_PERMANENT;
  $file->timestamp = time();
  $file->uid = 0;
  drupal_write_record('files', $file);
  $file->list = 1;
  $file->title = basename($file->filename);
  $node->field_ebl_detail_file = array( get_object_vars($file));

  //save node 
  node_save($node);

  //Clean queue of record associated with this node
  if ($clean_queue) {
  db_query("DELETE FROM {tp_newsletter_signup_bulk_queue} WHERE load_nid = %d", $node->nid);
  }
  //Notify user
  $email_user = user_load($node->uid);
  drupal_mail("takepart_newsletter_signup_bulk_feature", "report_mail", $email_user->mail, language_default(), array("node"=>$node));
}

/*
 * retrun all campaign codes that are currently in the system
 */
function _takepart_newsletter_signup_bulk_feature_get_campaign_codes() {
  $codes = array();
  $results = db_query("SELECT nid from {node} WHERE type = 'newsletter_campaign'");
  while ($row = db_fetch_object($results)) {
    $c_node = node_load($row->nid);
    $codes[] = $c_node->field_newsletter_campaign_id[0]['value'];
  }
  return $codes;
}


