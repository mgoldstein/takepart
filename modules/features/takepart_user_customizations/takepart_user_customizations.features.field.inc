<?php
/**
 * @file
 * takepart_user_customizations.features.field.inc
 */

/**
 * Implementation of hook_field_default_fields().
 */
function takepart_user_customizations_field_default_fields() {
  $fields = array();

  // Exported field: 'user-user-field_account_dateofbirth'
  $fields['user-user-field_account_dateofbirth'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_account_dateofbirth',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'date',
      'settings' => array(
        'granularity' => array(
          'day' => 'day',
          'month' => 'month',
          'year' => 'year',
        ),
        'repeat' => 0,
        'timezone_db' => '',
        'todate' => '',
        'tz_handling' => 'none',
      ),
      'translatable' => '1',
      'type' => 'date',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'deleted' => '0',
      'description' => 'You must be 18 years of age.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'medium',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_medium',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'user',
      'field_name' => 'field_account_dateofbirth',
      'label' => 'Date of Birth',
      'required' => 1,
      'settings' => array(
        'default_format' => 'medium',
        'default_value' => 'blank',
        'default_value2' => 'blank',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => 1,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'increment' => '1',
          'input_format' => 'M j Y - g:i:sa',
          'input_format_custom' => '',
          'label_position' => 'none',
          'repeat_collapsed' => 0,
          'text_parts' => array(),
          'year_range' => '-100:+0',
        ),
        'type' => 'date_select',
        'weight' => '7',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Date of Birth');
  t('You must be 18 years of age.');

  return $fields;
}
