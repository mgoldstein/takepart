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
  return $info;
}

function takepart_omniture_test($param) {
  return "baseball $param baseball";
}
