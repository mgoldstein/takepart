<?php

$content['type']  = array (
  'name' => 'Newsletter Campaign',
  'type' => 'newsletter_campaign',
  'description' => 'This type is installed by the Newsletter Email Collector (takepart_newsletter_signup) and is used to create content that will appear in blocks to capture email addresses.',
  'title_label' => 'Title',
  'body_label' => '',
  'min_word_count' => '0',
  'help' => '',
  'node_options' => 
  array (
    'status' => true,
    'promote' => false,
    'sticky' => false,
    'revision' => false,
    'revision_moderation' => false,
  ),
  'new_revisions' => 0,
  'takepart_admin_revisions_auto_publish' => 0,
  'language_content_type' => '0',
  'upload' => '1',
  'old_type' => 'newsletter_campaign',
  'orig_type' => '',
  'module' => 'node',
  'custom' => '1',
  'modified' => '1',
  'locked' => '0',
  'nodewords_edit_metatags' => 1,
  'nodewords_metatags_generation_method' => '1',
  'nodewords_metatags_generation_source' => '3',
  'nodewords_use_alt_attribute' => 1,
  'nodewords_filter_modules_output' => 
  array (
    'imagebrowser' => false,
    'img_assist' => false,
  ),
  'nodewords_filter_regexp' => '',
  'comment' => '0',
  'comment_default_mode' => '4',
  'comment_default_order' => '1',
  'comment_default_per_page' => '50',
  'comment_controls' => '3',
  'comment_anonymous' => 0,
  'comment_subject_field' => '0',
  'comment_preview' => '1',
  'comment_form_location' => '0',
  'page_title' => 
  array (
    'show_field' => 
    array (
      'show_field' => false,
    ),
    'pattern' => '',
  ),
);
$content['fields']  = array (
  0 => 
  array (
    'label' => 'Header',
    'field_name' => 'field_newsletter_header',
    'type' => 'text',
    'widget_type' => 'text_textfield',
    'change' => 'Change basic information',
    'weight' => '-4',
    'rows' => '5',
    'size' => '60',
    'description' => 'This text will appear as the header of the block.',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_newsletter_header][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => NULL,
    'required' => 0,
    'multiple' => '0',
    'text_processing' => '0',
    'max_length' => '25',
    'allowed_values' => '',
    'op' => 'Save field settings',
    'module' => 'text',
    'widget_module' => 'text',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'varchar',
        'length' => '25',
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
    ),
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
  1 => 
  array (
    'label' => 'Promo Text',
    'field_name' => 'field_newsletter_promo_text',
    'type' => 'text',
    'widget_type' => 'text_textarea',
    'change' => 'Change basic information',
    'weight' => '-3',
    'rows' => '5',
    'size' => 60,
    'description' => 'This text will appear above the email input box.',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        'format' => '1',
        '_error_element' => 'default_value_widget][field_newsletter_promo_text][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => 
    array (
      'field_newsletter_promo_text' => 
      array (
        0 => 
        array (
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_newsletter_promo_text][0][value',
        ),
      ),
    ),
    'required' => 0,
    'multiple' => '0',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'op' => 'Save field settings',
    'module' => 'text',
    'widget_module' => 'text',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'text',
        'size' => 'big',
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
      'format' => 
      array (
        'type' => 'int',
        'unsigned' => true,
        'not null' => false,
        'views' => false,
      ),
    ),
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
  2 => 
  array (
    'label' => 'Pluris Email Campaign Code',
    'field_name' => 'field_newsletter_campaign_id',
    'type' => 'text',
    'widget_type' => 'text_textfield',
    'change' => 'Change basic information',
    'weight' => '-2',
    'rows' => 5,
    'size' => '10',
    'description' => 'Campaign Code generated from the Pluris system.',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_newsletter_campaign_id][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => 
    array (
      'field_newsletter_campaign_id' => 
      array (
        0 => 
        array (
          'value' => '',
          '_error_element' => 'default_value_widget][field_newsletter_campaign_id][0][value',
        ),
      ),
    ),
    'required' => 0,
    'multiple' => '0',
    'text_processing' => '0',
    'max_length' => '10',
    'allowed_values' => '',
    'op' => 'Save field settings',
    'module' => 'text',
    'widget_module' => 'text',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'varchar',
        'length' => '10',
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
    ),
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
  3 => 
  array (
    'label' => 'Unsubscribe Logo',
    'field_name' => 'field_newsletter_campaign_logo',
    'type' => 'filefield',
    'widget_type' => 'imagefield_widget',
    'change' => 'Change basic information',
    'weight' => '-1',
    'file_extensions' => 'png gif jpg jpeg',
    'progress_indicator' => 'bar',
    'file_path' => '',
    'max_filesize_per_file' => '',
    'max_filesize_per_node' => '',
    'max_resolution' => '400x200',
    'min_resolution' => 0,
    'custom_alt' => 0,
    'alt' => '',
    'custom_title' => 1,
    'title_type' => 'textfield',
    'title' => '',
    'use_default_image' => 0,
    'default_image_upload' => '',
    'default_image' => NULL,
    'description' => 'Logo to be used on the unsubscribe page.',
    'required' => 0,
    'multiple' => '0',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'op' => 'Save field settings',
    'module' => 'filefield',
    'widget_module' => 'imagefield',
    'columns' => 
    array (
      'fid' => 
      array (
        'type' => 'int',
        'not null' => false,
        'views' => true,
      ),
      'list' => 
      array (
        'type' => 'int',
        'size' => 'tiny',
        'not null' => false,
        'views' => true,
      ),
      'data' => 
      array (
        'type' => 'text',
        'serialize' => true,
        'views' => true,
      ),
    ),
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => 
      array (
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
  ),
  4 => 
  array (
    'label' => 'Thank You Text',
    'field_name' => 'field_newsletter_thanks_text',
    'type' => 'text',
    'widget_type' => 'text_textarea',
    'change' => 'Change basic information',
    'weight' => 0,
    'rows' => '5',
    'size' => 60,
    'description' => 'Text to display in signup block after a user has successfully submitted their email.',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_newsletter_thanks_text][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => 
    array (
      'field_newsletter_thanks_text' => 
      array (
        0 => 
        array (
          'value' => '',
          '_error_element' => 'default_value_widget][field_newsletter_thanks_text][0][value',
          'format' => 1,
        ),
      ),
    ),
    'required' => 0,
    'multiple' => '0',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'op' => 'Save field settings',
    'module' => 'text',
    'widget_module' => 'text',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'text',
        'size' => 'big',
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
      'format' => 
      array (
        'type' => 'int',
        'unsigned' => true,
        'not null' => false,
        'views' => false,
      ),
    ),
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
);
$content['extra']  = array (
  'title' => '-5',
  'revision_information' => '5',
  'comment_settings' => '7',
  'menu' => '1',
  'path' => '4',
  'attachments' => '3',
  'nodewords' => '2',
  'xmlsitemap' => '6',
);