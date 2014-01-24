<?php
/**
 * @file
 * of_the_day.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function of_the_day_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'of_the_day';
  $bean_type->label = 'Of the Day';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['of_the_day'] = $bean_type;

  return $export;
}
