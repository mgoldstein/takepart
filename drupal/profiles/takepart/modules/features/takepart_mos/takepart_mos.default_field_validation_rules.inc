<?php
/**
 * @file
 * takepart_mos.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function takepart_mos_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = '600 characters max';
  $rule->name = 'field_mos_message_max_length';
  $rule->field_name = 'field_mos_user_custom_message';
  $rule->col = 'value';
  $rule->entity_type = 'signature';
  $rule->bundle = 'mos_signature';
  $rule->validator = 'field_validation_length_validator';
  $rule->settings = array(
    'min' => '',
    'max' => '600',
    'bypass' => 0,
    'roles' => array(
      2 => 0,
      3 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = '600 characters max';
  $export['field_mos_message_max_length'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = '70 characters max';
  $rule->name = 'field_sig_city_max_length';
  $rule->field_name = 'field_sig_city';
  $rule->col = 'value';
  $rule->entity_type = 'signature';
  $rule->bundle = 'mos_signature';
  $rule->validator = 'field_validation_length_validator';
  $rule->settings = array(
    'min' => '',
    'max' => '70',
    'bypass' => 0,
    'roles' => array(
      2 => 0,
      3 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = '70 characters max';
  $export['field_sig_city_max_length'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = '35 characters max';
  $rule->name = 'field_sig_first_name_max_length';
  $rule->field_name = 'field_sig_first_name';
  $rule->col = 'value';
  $rule->entity_type = 'signature';
  $rule->bundle = 'mos_signature';
  $rule->validator = 'field_validation_length_validator';
  $rule->settings = array(
    'min' => '',
    'max' => '35',
    'bypass' => 0,
    'roles' => array(
      2 => 0,
      3 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = '35 characters max length';
  $export['field_sig_first_name_max_length'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = '35 characters max';
  $rule->name = 'field_sig_last_name_max_length';
  $rule->field_name = 'field_sig_last_name';
  $rule->col = 'value';
  $rule->entity_type = 'signature';
  $rule->bundle = 'mos_signature';
  $rule->validator = 'field_validation_length_validator';
  $rule->settings = array(
    'min' => '',
    'max' => '35',
    'bypass' => 0,
    'roles' => array(
      2 => 0,
      3 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = '35 characters max';
  $export['field_sig_last_name_max_length'] = $rule;

  return $export;
}
