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
  
  
  
  return $info;
}

function takepart_omniture_test($param) {
  $test = $param;
  return "$param -> baseball '$test' baseball";
}

function takepart_omniture_value_or_empty($param) {
  // if param wrapped in brakets [], then token was not
  // found, just retuen empty string.  
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
    $authors[] = $record->last_name ."-". $record->first_name ."-". $record->field_author_nid;
  }
  return implode(',', $authors);
}







