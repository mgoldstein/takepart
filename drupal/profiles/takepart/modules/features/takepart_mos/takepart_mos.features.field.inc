<?php
/**
 * @file
 * takepart_mos.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function takepart_mos_field_default_fields() {
  $fields = array();

  // Exported field: 'node-mos_action-body'.
  $fields['node-mos_action-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'mos_action',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Describes the intent of the message.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Message Text',
      'required' => 1,
      'settings' => array(
        'display_summary' => 0,
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-mos_action-field_action_main_image'.
  $fields['node-mos_action-field_action_main_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_action_main_image',
      'foreign keys' => array(),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'media',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'media',
    ),
    'field_instance' => array(
      'bundle' => 'mos_action',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'media_image_formatter',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '5',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_action_main_image',
      'label' => 'Action Image',
      'required' => 0,
      'settings' => array(
        'file_extensions' => 'jpg jpeg gif png txt doc docx xls xlsx pdf ppt pptx pps ppsx odt ods odp mp3 mov m4v mp4 mpeg avi ogg oga ogv wmv ico',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'media_views_widget',
        'settings' => array(
          'allowed_schemes' => array(
            'private' => 0,
            'public' => 'public',
            'vimeo' => 0,
            'youtube' => 0,
          ),
          'allowed_types' => array(
            'audio' => 0,
            'default' => 0,
            'image' => 'image',
            'video' => 0,
          ),
          'progress_indicator' => 'throbber',
          'view' => 'media_views_widget_default--default',
        ),
        'type' => 'media_generic_alt',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'node-mos_action-field_action_organizer'.
  $fields['node-mos_action-field_action_organizer'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_action_organizer',
      'foreign keys' => array(
        'nid' => array(
          'columns' => array(
            'nid' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'nid' => array(
          0 => 'nid',
        ),
      ),
      'locked' => '0',
      'module' => 'node_reference',
      'settings' => array(
        'referenceable_types' => array(
          'action' => 0,
          'audio' => 0,
          'blog_front' => 0,
          'feed' => 0,
          'feed_item' => 0,
          'openpublish_article' => 0,
          'openpublish_blog_post' => 0,
          'openpublish_photo' => 0,
          'openpublish_photo_gallery' => 0,
          'openpublish_video' => 0,
          'petition_action' => 0,
          'pledge_action' => 0,
          'profile' => 0,
          'section_front' => 0,
          'section_front_wide' => 0,
          'takepart_campaign' => 0,
          'takepart_group' => 'takepart_group',
          'takepart_list' => 0,
          'takepart_page' => 0,
          'takepart_quick_study' => 0,
          'takepart_slide' => 0,
          'topic_front' => 0,
          'venue' => 0,
          'webform' => 0,
        ),
        'view' => array(
          'args' => array(),
          'display_name' => '',
          'view_name' => '',
        ),
      ),
      'translatable' => '0',
      'type' => 'node_reference',
    ),
    'field_instance' => array(
      'bundle' => 'mos_action',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '6',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_action_organizer',
      'label' => 'Action Organizer',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'node_reference',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'node_reference/autocomplete',
          'size' => 60,
        ),
        'type' => 'node_reference_autocomplete',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'node-mos_action-field_action_sponsor'.
  $fields['node-mos_action-field_action_sponsor'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_action_sponsor',
      'foreign keys' => array(
        'nid' => array(
          'columns' => array(
            'nid' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'nid' => array(
          0 => 'nid',
        ),
      ),
      'locked' => '0',
      'module' => 'node_reference',
      'settings' => array(
        'referenceable_types' => array(
          'action' => 0,
          'audio' => 0,
          'blog_front' => 0,
          'feed' => 0,
          'feed_item' => 0,
          'mos_action' => 0,
          'openpublish_article' => 0,
          'openpublish_blog_post' => 0,
          'openpublish_photo' => 0,
          'openpublish_photo_gallery' => 0,
          'openpublish_video' => 0,
          'petition_action' => 0,
          'pledge_action' => 0,
          'profile' => 0,
          'section_front' => 0,
          'section_front_wide' => 0,
          'takepart_campaign' => 0,
          'takepart_group' => 'takepart_group',
          'takepart_list' => 0,
          'takepart_page' => 0,
          'takepart_quick_study' => 0,
          'takepart_slide' => 0,
          'topic_front' => 0,
          'venue' => 0,
          'webform' => 0,
        ),
        'view' => array(
          'args' => array(),
          'display_name' => '',
          'view_name' => '',
        ),
      ),
      'translatable' => '1',
      'type' => 'node_reference',
    ),
    'field_instance' => array(
      'bundle' => 'mos_action',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '7',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_action_sponsor',
      'label' => 'Action Sponsor',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'node_reference',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'node_reference/autocomplete',
          'size' => '60',
        ),
        'type' => 'node_reference_autocomplete',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-mos_action-field_closed_heading'.
  $fields['node-mos_action-field_closed_heading'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_closed_heading',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'mos_action',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '10',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_closed_heading',
      'label' => 'Closed Heading',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '15',
      ),
    ),
  );

  // Exported field: 'node-mos_action-field_closed_message'.
  $fields['node-mos_action-field_closed_message'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_closed_message',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'mos_action',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '11',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_closed_message',
      'label' => 'Closed Message',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '16',
      ),
    ),
  );

  // Exported field: 'node-mos_action-field_complete_heading'.
  $fields['node-mos_action-field_complete_heading'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_complete_heading',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'mos_action',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '12',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_complete_heading',
      'label' => 'Complete Heading',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '17',
      ),
    ),
  );

  // Exported field: 'node-mos_action-field_complete_message'.
  $fields['node-mos_action-field_complete_message'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_complete_message',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'mos_action',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '13',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_complete_message',
      'label' => 'Complete Message',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '18',
      ),
    ),
  );

  // Exported field: 'node-mos_action-field_mos_about'.
  $fields['node-mos_action-field_mos_about'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mos_about',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'mos_action',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Additional information about the MOS campaign. It is support WYSIWYG formatting and video embedding.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mos_about',
      'label' => 'About The Message',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'node-mos_action-field_mos_recipient'.
  $fields['node-mos_action-field_mos_recipient'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mos_recipient',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => '0',
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'mos_action',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => '2',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mos_recipient',
      'label' => 'Recipient',
      'required' => 0,
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'configurable_title' => 0,
          'rel' => '',
          'target' => '_blank',
          'title' => '',
        ),
        'display' => array(
          'url_cutoff' => '80',
        ),
        'enable_tokens' => 1,
        'rel_remove' => 'default',
        'title' => 'required',
        'title_maxlength' => '128',
        'title_value' => '',
        'url' => 'optional',
        'user_register_form' => FALSE,
        'validate_url' => 1,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-mos_action-field_mos_user_message_label'.
  $fields['node-mos_action-field_mos_user_message_label'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mos_user_message_label',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'mos_action',
      'default_value' => array(
        0 => array(
          'value' => 'Customize your message',
        ),
      ),
      'deleted' => '0',
      'description' => 'Label displayed as an in-field label within the user message field.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '3',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_mos_user_message_label',
      'label' => 'Customize Label',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-mos_action-field_signed_heading'.
  $fields['node-mos_action-field_signed_heading'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_signed_heading',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'mos_action',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '15',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_signed_heading',
      'label' => 'Already Signed Heading',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '13',
      ),
    ),
  );

  // Exported field: 'node-mos_action-field_signed_message'.
  $fields['node-mos_action-field_signed_message'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_signed_message',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'mos_action',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '14',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_signed_message',
      'label' => 'Already Signed Message',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '14',
      ),
    ),
  );

  // Exported field: 'node-mos_action-field_social_share_bar'.
  $fields['node-mos_action-field_social_share_bar'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_social_share_bar',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'takepart_addthis',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'share_bar',
    ),
    'field_instance' => array(
      'bundle' => 'mos_action',
      'default_value' => array(
        0 => array(
          'alternate_url' => '',
          'twitter_message' => '',
          'email_message' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'takepart_addthis',
          'settings' => array(
            'orientation' => 'horizontal',
          ),
          'type' => 'button_bar',
          'weight' => '16',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_social_share_bar',
      'label' => 'Social Sharing',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'takepart_addthis',
        'settings' => array(),
        'type' => 'addthis_config',
        'weight' => '17',
      ),
    ),
  );

  // Exported field: 'node-mos_action-field_tab_call_to_action'.
  $fields['node-mos_action-field_tab_call_to_action'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tab_call_to_action',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'mos_action',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Displays within the main yellow sign-up form submit button.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '4',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_tab_call_to_action',
      'label' => 'Button Text',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-mos_action-field_thank_you_heading'.
  $fields['node-mos_action-field_thank_you_heading'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_thank_you_heading',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'mos_action',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '9',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_thank_you_heading',
      'label' => 'Thank You Heading',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-mos_action-field_thank_you_message'.
  $fields['node-mos_action-field_thank_you_message'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_thank_you_message',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'mos_action',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '8',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_thank_you_message',
      'label' => 'Thank You Message',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'signature-mos_signature-field_mos_user_custom_message'.
  $fields['signature-mos_signature-field_mos_user_custom_message'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_mos_user_custom_message',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'mos_signature',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 8,
        ),
      ),
      'entity_type' => 'signature',
      'field_name' => 'field_mos_user_custom_message',
      'label' => 'User Custom Message',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '19',
      ),
    ),
  );

  // Exported field: 'signature-mos_signature-field_sig_city'.
  $fields['signature-mos_signature-field_sig_city'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_sig_city',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'mos_signature',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 2,
        ),
      ),
      'entity_type' => 'signature',
      'field_name' => 'field_sig_city',
      'label' => 'City',
      'required' => 1,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '40',
        ),
        'type' => 'text_textfield',
        'weight' => '18',
      ),
    ),
  );

  // Exported field: 'signature-mos_signature-field_sig_country'.
  $fields['signature-mos_signature-field_sig_country'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_sig_country',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'Afghanistan' => 'Afghanistan',
          'Albania' => 'Albania',
          'Algeria' => 'Algeria',
          'American Samoa' => 'American Samoa',
          'Andorra' => 'Andorra',
          'Angola' => 'Angola',
          'Anguilla' => 'Anguilla',
          'Antarctica' => 'Antarctica',
          'Antigua and Barbuda' => 'Antigua and Barbuda',
          'Argentina' => 'Argentina',
          'Armenia' => 'Armenia',
          'Aruba' => 'Aruba',
          'Australia' => 'Australia',
          'Austria' => 'Austria',
          'Azerbaijan' => 'Azerbaijan',
          'Bahamas' => 'Bahamas',
          'Bahrain' => 'Bahrain',
          'Bangladesh' => 'Bangladesh',
          'Barbados' => 'Barbados',
          'Belarus' => 'Belarus',
          'Belgium' => 'Belgium',
          'Belize' => 'Belize',
          'Benin' => 'Benin',
          'Bermuda' => 'Bermuda',
          'Bhutan' => 'Bhutan',
          'Bolivia' => 'Bolivia',
          'Bosnia and Herzegovina' => 'Bosnia and Herzegovina',
          'Botswana' => 'Botswana',
          'Bouvet Island' => 'Bouvet Island',
          'Brazil' => 'Brazil',
          'British Indian Ocean Territory' => 'British Indian Ocean Territory',
          'Brunei Darussalam' => 'Brunei Darussalam',
          'Bulgaria' => 'Bulgaria',
          'Burkina Faso' => 'Burkina Faso',
          'Burundi' => 'Burundi',
          'Cambodia' => 'Cambodia',
          'Cameroon' => 'Cameroon',
          'Canada' => 'Canada',
          'Cape Verde' => 'Cape Verde',
          'Cayman Islands' => 'Cayman Islands',
          'Central African Republic' => 'Central African Republic',
          'Chad' => 'Chad',
          'Chile' => 'Chile',
          'China' => 'China',
          'Christmas Island' => 'Christmas Island',
          'Cocos (Keeling) Islands' => 'Cocos (Keeling) Islands',
          'Colombia' => 'Colombia',
          'Comoros' => 'Comoros',
          'Congo' => 'Congo',
          'Congo, The Democratic Republic of The' => 'Congo, The Democratic Republic of The',
          'Cook Islands' => 'Cook Islands',
          'Costa Rica' => 'Costa Rica',
          'Cote D\'ivoire' => 'Cote D\'ivoire',
          'Croatia' => 'Croatia',
          'Cuba' => 'Cuba',
          'Cyprus' => 'Cyprus',
          'Czech Republic' => 'Czech Republic',
          'Denmark' => 'Denmark',
          'Djibouti' => 'Djibouti',
          'Dominica' => 'Dominica',
          'Dominican Republic' => 'Dominican Republic',
          'Ecuador' => 'Ecuador',
          'Egypt' => 'Egypt',
          'El Salvador' => 'El Salvador',
          'Equatorial Guinea' => 'Equatorial Guinea',
          'Eritrea' => 'Eritrea',
          'Estonia' => 'Estonia',
          'Ethiopia' => 'Ethiopia',
          'Falkland Islands (Malvinas)' => 'Falkland Islands (Malvinas)',
          'Faroe Islands' => 'Faroe Islands',
          'Fiji' => 'Fiji',
          'Finland' => 'Finland',
          'France' => 'France',
          'French Guiana' => 'French Guiana',
          'French Polynesia' => 'French Polynesia',
          'French Southern Territories' => 'French Southern Territories',
          'Gabon' => 'Gabon',
          'Gambia' => 'Gambia',
          'Georgia' => 'Georgia',
          'Germany' => 'Germany',
          'Ghana' => 'Ghana',
          'Gibraltar' => 'Gibraltar',
          'Greece' => 'Greece',
          'Greenland' => 'Greenland',
          'Grenada' => 'Grenada',
          'Guadeloupe' => 'Guadeloupe',
          'Guam' => 'Guam',
          'Guatemala' => 'Guatemala',
          'Guinea' => 'Guinea',
          'Guinea-bissau' => 'Guinea-bissau',
          'Guyana' => 'Guyana',
          'Haiti' => 'Haiti',
          'Heard Island and Mcdonald Islands' => 'Heard Island and Mcdonald Islands',
          'Holy See (Vatican City State)' => 'Holy See (Vatican City State)',
          'Honduras' => 'Honduras',
          'Hong Kong' => 'Hong Kong',
          'Hungary' => 'Hungary',
          'Iceland' => 'Iceland',
          'India' => 'India',
          'Indonesia' => 'Indonesia',
          'Iran, Islamic Republic of' => 'Iran, Islamic Republic of',
          'Iraq' => 'Iraq',
          'Ireland' => 'Ireland',
          'Israel' => 'Israel',
          'Italy' => 'Italy',
          'Jamaica' => 'Jamaica',
          'Japan' => 'Japan',
          'Jordan' => 'Jordan',
          'Kazakhstan' => 'Kazakhstan',
          'Kenya' => 'Kenya',
          'Kiribati' => 'Kiribati',
          'Korea, Democratic People\'s Republic of' => 'Korea, Democratic People\'s Republic of',
          'Korea, Republic of' => 'Korea, Republic of',
          'Kuwait' => 'Kuwait',
          'Kyrgyzstan' => 'Kyrgyzstan',
          'Lao People\'s Democratic Republic' => 'Lao People\'s Democratic Republic',
          'Latvia' => 'Latvia',
          'Lebanon' => 'Lebanon',
          'Lesotho' => 'Lesotho',
          'Liberia' => 'Liberia',
          'Libyan Arab Jamahiriya' => 'Libyan Arab Jamahiriya',
          'Liechtenstein' => 'Liechtenstein',
          'Lithuania' => 'Lithuania',
          'Luxembourg' => 'Luxembourg',
          'Macao' => 'Macao',
          'Macedonia, The Former Yugoslav Republic of' => 'Macedonia, The Former Yugoslav Republic of',
          'Madagascar' => 'Madagascar',
          'Malawi' => 'Malawi',
          'Malaysia' => 'Malaysia',
          'Maldives' => 'Maldives',
          'Mali' => 'Mali',
          'Malta' => 'Malta',
          'Marshall Islands' => 'Marshall Islands',
          'Martinique' => 'Martinique',
          'Mauritania' => 'Mauritania',
          'Mauritius' => 'Mauritius',
          'Mayotte' => 'Mayotte',
          'Mexico' => 'Mexico',
          'Micronesia, Federated States of' => 'Micronesia, Federated States of',
          'Moldova, Republic of' => 'Moldova, Republic of',
          'Monaco' => 'Monaco',
          'Mongolia' => 'Mongolia',
          'Montserrat' => 'Montserrat',
          'Morocco' => 'Morocco',
          'Mozambique' => 'Mozambique',
          'Myanmar' => 'Myanmar',
          'Namibia' => 'Namibia',
          'Nauru' => 'Nauru',
          'Nepal' => 'Nepal',
          'Netherlands' => 'Netherlands',
          'Netherlands Antilles' => 'Netherlands Antilles',
          'New Caledonia' => 'New Caledonia',
          'New Zealand' => 'New Zealand',
          'Nicaragua' => 'Nicaragua',
          'Niger' => 'Niger',
          'Nigeria' => 'Nigeria',
          'Niue' => 'Niue',
          'Norfolk Island' => 'Norfolk Island',
          'Northern Mariana Islands' => 'Northern Mariana Islands',
          'Norway' => 'Norway',
          'Oman' => 'Oman',
          'Pakistan' => 'Pakistan',
          'Palau' => 'Palau',
          'Palestinian Territory, Occupied' => 'Palestinian Territory, Occupied',
          'Panama' => 'Panama',
          'Papua New Guinea' => 'Papua New Guinea',
          'Paraguay' => 'Paraguay',
          'Peru' => 'Peru',
          'Philippines' => 'Philippines',
          'Pitcairn' => 'Pitcairn',
          'Poland' => 'Poland',
          'Portugal' => 'Portugal',
          'Puerto Rico' => 'Puerto Rico',
          'Qatar' => 'Qatar',
          'Reunion' => 'Reunion',
          'Romania' => 'Romania',
          'Russian Federation' => 'Russian Federation',
          'Rwanda' => 'Rwanda',
          'Saint Helena' => 'Saint Helena',
          'Saint Kitts and Nevis' => 'Saint Kitts and Nevis',
          'Saint Lucia' => 'Saint Lucia',
          'Saint Pierre and Miquelon' => 'Saint Pierre and Miquelon',
          'Saint Vincent and The Grenadines' => 'Saint Vincent and The Grenadines',
          'Samoa' => 'Samoa',
          'San Marino' => 'San Marino',
          'Sao Tome and Principe' => 'Sao Tome and Principe',
          'Saudi Arabia' => 'Saudi Arabia',
          'Senegal' => 'Senegal',
          'Serbia and Montenegro' => 'Serbia and Montenegro',
          'Seychelles' => 'Seychelles',
          'Sierra Leone' => 'Sierra Leone',
          'Singapore' => 'Singapore',
          'Slovakia' => 'Slovakia',
          'Slovenia' => 'Slovenia',
          'Solomon Islands' => 'Solomon Islands',
          'Somalia' => 'Somalia',
          'South Africa' => 'South Africa',
          'South Georgia and The South Sandwich Islands' => 'South Georgia and The South Sandwich Islands',
          'Spain' => 'Spain',
          'Sri Lanka' => 'Sri Lanka',
          'Sudan' => 'Sudan',
          'Suriname' => 'Suriname',
          'Svalbard and Jan Mayen' => 'Svalbard and Jan Mayen',
          'Swaziland' => 'Swaziland',
          'Sweden' => 'Sweden',
          'Switzerland' => 'Switzerland',
          'Syrian Arab Republic' => 'Syrian Arab Republic',
          'Taiwan' => 'Taiwan',
          'Tajikistan' => 'Tajikistan',
          'Tanzania, United Republic of' => 'Tanzania, United Republic of',
          'Thailand' => 'Thailand',
          'Timor-leste' => 'Timor-leste',
          'Togo' => 'Togo',
          'Tokelau' => 'Tokelau',
          'Tonga' => 'Tonga',
          'Trinidad and Tobago' => 'Trinidad and Tobago',
          'Tunisia' => 'Tunisia',
          'Turkey' => 'Turkey',
          'Turkmenistan' => 'Turkmenistan',
          'Turks and Caicos Islands' => 'Turks and Caicos Islands',
          'Tuvalu' => 'Tuvalu',
          'Uganda' => 'Uganda',
          'Ukraine' => 'Ukraine',
          'United Arab Emirates' => 'United Arab Emirates',
          'United Kingdom' => 'United Kingdom',
          'United States' => 'United States',
          'United States Minor Outlying Islands' => 'United States Minor Outlying Islands',
          'Uruguay' => 'Uruguay',
          'Uzbekistan' => 'Uzbekistan',
          'Vanuatu' => 'Vanuatu',
          'Venezuela' => 'Venezuela',
          'Viet Nam' => 'Viet Nam',
          'Virgin Islands, British' => 'Virgin Islands, British',
          'Virgin Islands, U.S.' => 'Virgin Islands, U.S.',
          'Wallis and Futuna' => 'Wallis and Futuna',
          'Western Sahara' => 'Western Sahara',
          'Yemen' => 'Yemen',
          'Zambia' => 'Zambia',
          'Zimbabwe' => 'Zimbabwe',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'mos_signature',
      'default_value' => array(
        0 => array(
          'value' => 'United States',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 3,
        ),
      ),
      'entity_type' => 'signature',
      'field_name' => 'field_sig_country',
      'label' => 'Country',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '14',
      ),
    ),
  );

  // Exported field: 'signature-mos_signature-field_sig_first_name'.
  $fields['signature-mos_signature-field_sig_first_name'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_sig_first_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'mos_signature',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'signature',
      'field_name' => 'field_sig_first_name',
      'label' => 'First Name',
      'required' => 1,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '12',
      ),
    ),
  );

  // Exported field: 'signature-mos_signature-field_sig_last_name'.
  $fields['signature-mos_signature-field_sig_last_name'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_sig_last_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'mos_signature',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'signature',
      'field_name' => 'field_sig_last_name',
      'label' => 'Last Name',
      'required' => 1,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '13',
      ),
    ),
  );

  // Exported field: 'signature-mos_signature-field_sig_state_international'.
  $fields['signature-mos_signature-field_sig_state_international'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_sig_state_international',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'mos_signature',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 9,
        ),
      ),
      'entity_type' => 'signature',
      'field_name' => 'field_sig_state_international',
      'label' => 'State',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '17',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About The Message');
  t('Action Image');
  t('Action Organizer');
  t('Action Sponsor');
  t('Additional information about the MOS campaign. It is support WYSIWYG formatting and video embedding.');
  t('Already Signed Heading');
  t('Already Signed Message');
  t('Button Text');
  t('City');
  t('Closed Heading');
  t('Closed Message');
  t('Complete Heading');
  t('Complete Message');
  t('Country');
  t('Customize Label');
  t('Describes the intent of the message.');
  t('Displays within the main yellow sign-up form submit button.');
  t('First Name');
  t('Label displayed as an in-field label within the user message field.');
  t('Last Name');
  t('Message Text');
  t('Recipient');
  t('Social Sharing');
  t('State');
  t('Thank You Heading');
  t('Thank You Message');
  t('User Custom Message');

  return $fields;
}
