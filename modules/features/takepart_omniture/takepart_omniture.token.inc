<?php


function takepart_omniture_token_info() {
  $info['types']['tp_omniture'] = array(
    'name'=> t('TakePart Omniture'),
    'description' => t("Tokens used for setting omniture variables"),
  );
  $info['tokens']['tp_omniture']['test'] = array(
    'name' => t('Test'),
    'description' => t("Returns the first part sub folder of the url"),
    'dynamic' => TRUE,
    'function' => array(
      'file' => drupal_get_path("module", "takepart_omniture") . "/takepart_omniture.token.inc",
      'function' => "takepart_omniture_test",
    ),
  );
  $info['tokens']['tp_omniture']['value_or_empty'] = array(
    'name' => t('Value or Empty'),
    'description' => t("Returns the token or empty string"),
    'dynamic' => TRUE,
    'function' => array(
      'file' => drupal_get_path("module", "takepart_omniture") . "/takepart_omniture.token.inc",
      'function' => "takepart_omniture_value_or_empty",
    ),
  );
  $info['tokens']['tp_omniture']['get_author'] = array(
    'name' => t('Get Author'),
    'description' => t('Retrieve the node referenced authors for this node item'),
    'dynamic' => TRUE,
    'function' => array(
      'file' => drupal_get_path("module", "takepart_omniture") . "/takepart_omniture.token.inc",
      'function' => "takepart_omniture_get_author",
    ),
  );
  
  $info['tokens']['tp_omniture']['url_after_arg'] = array(
    'name' => t('Get URL after arg'),
    'description' => t('Retrieve the current URL beyond the arg provided.  e.g. http://example.com/article/1999/myblog/12'),
    'dynamic' => TRUE,
    'function' => array(
      'file' => drupal_get_path("module", "takepart_omniture") . "/takepart_omniture.token.inc",
      'function' => "takepart_omniture_url_after_arg",
    ),
  );
 
  $info['tokens']['tp_omniture']['str_decode'] = array(
    'name' => t('HTML entity decode'),
    'description' => t('Process token with html_entity_decode function.'),
    'dynamic' => TRUE,
    'function' => array(
      'file' => drupal_get_path("module", "takepart_omniture") . "/takepart_omniture.token.inc",
      'function' => "takepart_omniture_str_decode",
    ),
  );
 
  $info['tokens']['tp_omniture']['date'] = array(
    'name' => t('date YYYY/MM/DD'),
    'description' => t('Put date into YYYY/MM/DD format.'),
    'dynamic' => TRUE,
    'function' => array(
      'file' => drupal_get_path("module", "takepart_omniture") . "/takepart_omniture.token.inc",
      'function' => "takepart_omniture_date",
    ),
  );
  
  $info['tokens']['tp_omniture']['urldecode'] = array(
    'name' => t('urldecode'),
    'description' => t('call urldecode() on param.'),
    'dynamic' => TRUE,
    'function' => array(
      'file' => drupal_get_path("module", "takepart_omniture") . "/takepart_omniture.token.inc",
      'function' => "takepart_omniture_urldecode",
    ),
  );  
  return $info;
}

function takepart_omniture_test($param) {
  $test = $param;
  return "$param -> baseball '$test' baseball";
}

function takepart_omniture_value_or_empty($param) {
  // if param wrapped in brakets [], then token was not
  // found, just retuen empty string.  
  $param = html_entity_decode($param, ENT_QUOTES);
  return preg_replace('/^\[[\w].*\]$/', '', $param);
  
}

/**
 * $nid - the node id
 * since entity field kills the system, find our own authors
 */
function takepart_omniture_get_author($nid) {
  if (!is_numeric($nid) ) 
    return 'Not-A-Number';
  
  $query = db_select('field_data_field_author', 'a');
  $query->addField('a', 'field_author_nid');
  $query->condition('a.entity_id', $nid);
  
  $query->join('field_data_field_profile_last_name', 'fpl', 'a.field_author_nid = fpl.entity_id');
  $query->join('field_data_field_profile_first_name', 'fpf', 'a.field_author_nid = fpf.entity_id');
  $query->addField('fpl', 'field_profile_last_name_value', 'last_name');
  $query->addField('fpf', 'field_profile_first_name_value', 'first_name');
  $query->orderBy('last_name', 'ASC')->orderby('first_name', 'ASC');
  
  $result = $query->execute();
  
  $authors = array();
  foreach($result as $record) {
    //$authors[] = $record->last_name ."-". $record->first_name ."-". $record->field_author_nid;
    $authors[] = strtolower($record->first_name ." ". $record->last_name);
  }
  return implode(';', $authors);
}

/**
 * provide the current_path token as the path.
 * get the current path and based on the given arg position,  
 * skip those positions and return whats left of the url path.
 *       index:     0/   1/   2/   3/   4/      5
 * so, path: /article/blog/test/2011/1110/my-blog
 * 
 * called with index 3 would return: 1110/my-blog
 */
function takepart_omniture_url_after_arg($path, $index = 0) {
  if (!is_numeric($index)) {
    return $path;
  }
  
  $path_arr = explode("/", $path);
  
  if ($index > count($path_arr) ) {
    return $path;
  }
  
  for ($i = 0; $i <= $index; $i++) {
    $parts = array_shift($path_arr);
  }
  $clipped = implode('/', $path_arr);
  return $clipped;
}

/**
 * run string through html_entity_decode
 *
 */
function takepart_omniture_str_decode($str) {
  return html_entity_decode($str, ENT_QUOTES);
} 

/**
 * built in date token with custom formatter was not working.
 */
function takepart_omniture_date($date_str) {
  return date('Y/m/d', $date_str);
}

/**
 * run $url through urldecode()
 */
function takepart_omniture_urldecode($url) {
  return urldecode($url);
}
