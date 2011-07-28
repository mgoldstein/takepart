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
