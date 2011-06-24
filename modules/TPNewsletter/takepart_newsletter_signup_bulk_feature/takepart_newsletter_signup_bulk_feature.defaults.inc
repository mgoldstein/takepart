<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _takepart_newsletter_signup_bulk_feature_content_default_fields() {
  $fields = array();

  // Exported field: field_ebl_action
  $fields[] = array(
    'field_name' => 'field_ebl_action',
    'type_name' => 'email_batch_load',
    'display_settings' => array(
      'weight' => '15',
      'parent' => 'group_ebl_defaults',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 's|Subscribe
u|Unsubscribe',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 's',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Action Value',
      'weight' => '2',
      'description' => 'WARNING: Selecting "Unsubscribe" will remove all emails in your list from the campaign.',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ebl_action_index
  $fields[] = array(
    'field_name' => 'field_ebl_action_index',
    'type_name' => 'email_batch_load',
    'display_settings' => array(
      'weight' => '11',
      'parent' => 'group_ebl_upload_details',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'none|Not In File
0|1
1|2
2|3
3|4
4|5
5|6
6|7
7|8
8|9
9|10',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Optional Action Column',
      'weight' => '3',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ebl_campaign
  $fields[] = array(
    'field_name' => 'field_ebl_campaign',
    'type_name' => 'email_batch_load',
    'display_settings' => array(
      'weight' => '13',
      'parent' => 'group_ebl_defaults',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'newsletter_campaign' => 'newsletter_campaign',
      'takepart_action' => 0,
      'takepart_article' => 0,
      'blog' => 0,
      'takepart_campaign' => 0,
      'takepart_category' => 0,
      'email_batch_load' => 0,
      'takepart_audio_embedded' => 0,
      'takepart_video_embedded' => 0,
      'takepart_group' => 0,
      'takepart_homepage_slide' => 0,
      'takepart_issue' => 0,
      'takepart_list' => 0,
      'takepart_photo' => 0,
      'takepart_photo_gallery' => 0,
      'takepart_page' => 0,
      'takepart_url' => 0,
      'takepart_audio' => 0,
      'takepart_video' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Campaign',
      'weight' => '8',
      'description' => 'Select an active Campaign to use for this batch import.',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_ebl_campaign_id_index
  $fields[] = array(
    'field_name' => 'field_ebl_campaign_id_index',
    'type_name' => 'email_batch_load',
    'display_settings' => array(
      'weight' => '9',
      'parent' => 'group_ebl_upload_details',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'none|Not In File
0|1
1|2
2|3
3|4
4|5
5|6
6|7
7|8
8|9
9|10',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 'none',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Optional Campaign Column',
      'weight' => '10',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ebl_csv_file
  $fields[] = array(
    'field_name' => 'field_ebl_csv_file',
    'type_name' => 'email_batch_load',
    'display_settings' => array(
      'weight' => '5',
      'parent' => 'group_ebl_upload_details',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'csv',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Input File',
      'weight' => '5',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_ebl_detail_file
  $fields[] = array(
    'field_name' => 'field_ebl_detail_file',
    'type_name' => 'email_batch_load',
    'display_settings' => array(
      'weight' => '22',
      'parent' => 'group_ebl_results',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'csv',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'Detail Report',
      'weight' => '22',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_ebl_email_index
  $fields[] = array(
    'field_name' => 'field_ebl_email_index',
    'type_name' => 'email_batch_load',
    'display_settings' => array(
      'weight' => '7',
      'parent' => 'group_ebl_upload_details',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '0|1
1|2
2|3
3|4
4|5
5|6
6|7
7|8
8|9
9|10',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Email Column',
      'weight' => '7',
      'description' => 'Select the column in the .csv file that contains the email addresses.<br><b>This column must exist in your file or an error will occur.</b> ',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ebl_error_count
  $fields[] = array(
    'field_name' => 'field_ebl_error_count',
    'type_name' => 'email_batch_load',
    'display_settings' => array(
      'weight' => '20',
      'parent' => 'group_ebl_results',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_ebl_error_count][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Error Records Processed',
      'weight' => '20',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ebl_error_summary
  $fields[] = array(
    'field_name' => 'field_ebl_error_summary',
    'type_name' => 'email_batch_load',
    'display_settings' => array(
      'weight' => '21',
      'parent' => 'group_ebl_results',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '2',
          '_error_element' => 'default_value_widget][field_ebl_error_summary][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Error Summary',
      'weight' => '21',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_ebl_has_header
  $fields[] = array(
    'field_name' => 'field_ebl_has_header',
    'type_name' => 'email_batch_load',
    'display_settings' => array(
      'weight' => '6',
      'parent' => 'group_ebl_upload_details',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '1|Yes
0|No',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '1',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'File Includes Header Row',
      'weight' => '6',
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ebl_processed_count
  $fields[] = array(
    'field_name' => 'field_ebl_processed_count',
    'type_name' => 'email_batch_load',
    'display_settings' => array(
      'weight' => '18',
      'parent' => 'group_ebl_results',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_ebl_processed_count][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Total Records Processed',
      'weight' => '18',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ebl_send_welcome
  $fields[] = array(
    'field_name' => 'field_ebl_send_welcome',
    'type_name' => 'email_batch_load',
    'display_settings' => array(
      'weight' => '16',
      'parent' => 'group_ebl_defaults',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'N|Do Not Send Welcome Email
Y|Send Welcome Email
',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 'N',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Send Welcome Email Value',
      'weight' => '10',
      'description' => 'WARNING: If checked, each email subscribed to the campaign will receive an email welcoming them to the list.',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ebl_send_welcome_index
  $fields[] = array(
    'field_name' => 'field_ebl_send_welcome_index',
    'type_name' => 'email_batch_load',
    'display_settings' => array(
      'weight' => '10',
      'parent' => 'group_ebl_upload_details',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'none|Not In File
0|1
1|2
2|3
3|4
4|5
5|6
6|7
7|8
8|9
9|10',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Optional Send Welcome Email Column',
      'weight' => '11',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ebl_source
  $fields[] = array(
    'field_name' => 'field_ebl_source',
    'type_name' => 'email_batch_load',
    'display_settings' => array(
      'weight' => '12',
      'parent' => 'group_ebl_defaults',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_ebl_source][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Source Value',
      'weight' => '9',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ebl_source_index
  $fields[] = array(
    'field_name' => 'field_ebl_source_index',
    'type_name' => 'email_batch_load',
    'display_settings' => array(
      'weight' => '8',
      'parent' => 'group_ebl_upload_details',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'none|Not In File
0|1
1|2
2|3
3|4
4|5
5|6
6|7
7|8
8|9
9|10',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Optional Source Column',
      'weight' => '10',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ebl_success_count
  $fields[] = array(
    'field_name' => 'field_ebl_success_count',
    'type_name' => 'email_batch_load',
    'display_settings' => array(
      'weight' => '19',
      'parent' => 'group_ebl_results',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_ebl_success_count][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Successful Records Processed',
      'weight' => '19',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Translatables
  array(
    t('Action Value'),
    t('Campaign'),
    t('Detail Report'),
    t('Email Column'),
    t('Error Records Processed'),
    t('Error Summary'),
    t('File Includes Header Row'),
    t('Input File'),
    t('Optional Action Column'),
    t('Optional Campaign Column'),
    t('Optional Send Welcome Email Column'),
    t('Optional Source Column'),
    t('Send Welcome Email Value'),
    t('Source Value'),
    t('Successful Records Processed'),
    t('Total Records Processed'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_fieldgroup_default_groups().
 */
function _takepart_newsletter_signup_bulk_feature_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_ebl_field_action
  $groups[] = array(
    'group_type' => 'standard',
    'type_name' => 'email_batch_load',
    'group_name' => 'group_ebl_field_action',
    'label' => 'Action (Advanced Users Only)',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => 'Select the Action you would like to use for your batch import, or, select the column in your input file where the Action value can be found.<br/><br/>',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '-1',
    'fields' => array(
      '0' => 'field_ebl_action',
      '1' => 'field_ebl_action_index',
    ),
  );

  // Exported group: group_ebl_field_campaign
  $groups[] = array(
    'group_type' => 'standard',
    'type_name' => 'email_batch_load',
    'group_name' => 'group_ebl_field_campaign',
    'label' => 'Alternate Campaign Field (Advanced Users Only)',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => 'Under normal circumstances, the batch load process should use the Campaign you selected above in General Settings.  You do, however, have the option to use a Campaign code from your input file.  If your input file contains a column with a valid Campaign code that you would like to use, select it here.  Else, leave as "Not In File."  If you select a column here, and the record from your input file still does not contain a valid Campaign code, then the Campaign you selected above will be used.  <br/><br/>
<b>Note, this option is only useful if you are intentionally loading emails from multiple campaigns in a single input file. </b><br/><br/>
',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '1',
    'fields' => array(
      '0' => 'field_ebl_campaign_id_index',
    ),
  );

  // Exported group: group_ebl_field_source
  $groups[] = array(
    'group_type' => 'standard',
    'type_name' => 'email_batch_load',
    'group_name' => 'group_ebl_field_source',
    'label' => 'Source',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => 'Enter the Source value you would like to use for your batch import, or, select the column in your input file where the Source value can be found.<br/><br/>',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '-2',
    'fields' => array(
      '0' => 'field_ebl_source',
      '1' => 'field_ebl_source_index',
    ),
  );

  // Exported group: group_ebl_results
  $groups[] = array(
    'group_type' => 'standard',
    'type_name' => 'email_batch_load',
    'group_name' => 'group_ebl_results',
    'label' => 'Results',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => 'These fields will populate after the file has run. ',
      ),
      'display' => array(
        'weight' => '-2',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '-4',
    'fields' => array(
      '0' => 'field_ebl_processed_count',
      '1' => 'field_ebl_success_count',
      '2' => 'field_ebl_error_count',
      '3' => 'field_ebl_error_summary',
      '4' => 'field_ebl_detail_file',
    ),
  );

  // Exported group: group_ebl_upload_details
  $groups[] = array(
    'group_type' => 'standard',
    'type_name' => 'email_batch_load',
    'group_name' => 'group_ebl_upload_details',
    'label' => 'General Settings',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => 'Enter some basic information about your batch import and upload the input file here.<br/><br/>',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '-3',
    'fields' => array(
      '0' => 'field_ebl_csv_file',
      '1' => 'field_ebl_has_header',
      '2' => 'field_ebl_email_index',
      '3' => 'field_ebl_campaign',
    ),
  );

  // Exported group: group_ebl_welcome_email
  $groups[] = array(
    'group_type' => 'standard',
    'type_name' => 'email_batch_load',
    'group_name' => 'group_ebl_welcome_email',
    'label' => 'Send Welcome Email (Advanced Users Only)',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => 'Choose whether or not you would like to send a Welcome Email or not, or, select the column in your input file where the Send Welcome Email value can be found.<br/><br/>',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '0',
    'fields' => array(
      '0' => 'field_ebl_send_welcome',
      '1' => 'field_ebl_send_welcome_index',
    ),
  );

  // Translatables
  array(
    t('Action (Advanced Users Only)'),
    t('Alternate Campaign Field (Advanced Users Only)'),
    t('General Settings'),
    t('Results'),
    t('Send Welcome Email (Advanced Users Only)'),
    t('Source'),
  );

  return $groups;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _takepart_newsletter_signup_bulk_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: create email_batch_load content
  $permissions[] = array(
    'name' => 'create email_batch_load content',
    'roles' => array(),
  );

  // Exported permission: delete own email_batch_load content
  $permissions[] = array(
    'name' => 'delete own email_batch_load content',
    'roles' => array(),
  );

  // Exported permission: edit any email_batch_load content
  $permissions[] = array(
    'name' => 'edit any email_batch_load content',
    'roles' => array(
      '0' => 'site developer',
    ),
  );

  return $permissions;
}
