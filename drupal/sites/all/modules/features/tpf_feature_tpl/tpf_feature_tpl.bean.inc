<?php
/**
 * @file
 * tpf_feature_tpl.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function tpf_feature_tpl_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'tpl_long';
  $bean_type->label = 'TPL Long';
  $bean_type->options = '';
  $bean_type->description = 'Long Promo Block for TPL.';
  $export['tpl_long'] = $bean_type;

  return $export;
}
