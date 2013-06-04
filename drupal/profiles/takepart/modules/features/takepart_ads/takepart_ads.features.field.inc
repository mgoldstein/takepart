<?php
/**
 * @file
 * takepart_ads.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function takepart_ads_field_default_fields() {
  $fields = array();

  // Exported field: 'node-openpublish_blog_post-field_tp_campaign_show_title'.
  $fields['node-openpublish_blog_post-field_tp_campaign_show_title'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_show_title',
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
          0 => '0',
          1 => '1',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'openpublish_blog_post',
      'default_value' => array(
        0 => array(
          'value' => 0,
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
          'weight' => '22',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'vidpop_map' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_tp_campaign_show_title',
      'label' => 'Remove Headline from Display',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-openpublish_photo_gallery-field_tp_campaign_show_title'.
  $fields['node-openpublish_photo_gallery-field_tp_campaign_show_title'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_show_title',
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
          0 => '0',
          1 => '1',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'openpublish_photo_gallery',
      'default_value' => array(
        0 => array(
          'value' => 0,
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
          'weight' => '11',
        ),
        'embed' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
        'inline_content' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'of_the_day' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'vidpop_map' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_tp_campaign_show_title',
      'label' => 'Remove Headline from Display',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_calendar'.
  $fields['node-takepart_campaign-field_calendar'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_calendar',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'takepart_calendar',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'takepart_calendar',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'takepart_calendar',
          'settings' => array(),
          'type' => 'takepart_calendar_formatter',
          'weight' => '30',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'vidpop_map' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_calendar',
      'label' => 'calendar',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'takepart_calendar',
        'settings' => array(),
        'type' => 'takepart_calendar',
        'weight' => '19',
      ),
    ),
  );

  // Exported field: 'node-takepart_list-field_multi_page_campaign'.
  $fields['node-takepart_list-field_multi_page_campaign'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_multi_page_campaign',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'context_field',
      'settings' => array(
        'global_setting' => 255,
      ),
      'translatable' => '1',
      'type' => 'context_field',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_list',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'context_field',
          'settings' => array(),
          'type' => 'context_field_context',
          'weight' => 4,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'vidpop_map' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_multi_page_campaign',
      'label' => 'Multi Page Campaign',
      'required' => 0,
      'settings' => array(
        'allowed_blocks' => array(
          'Boxes for Box' => 0,
          'Boxes for Features Box' => 0,
          'Boxes for Field Box' => 0,
          'Boxes for GA Ad' => 0,
          'Boxes for Image Box' => 0,
          'Boxes for Screaming Headline' => 0,
          'Boxes for View Box' => 0,
          'akamai' => 0,
          'boxes' => 0,
          'comment' => 0,
          'comment_block_simple' => 0,
          'context_related_menu' => 0,
          'context_ui' => 0,
          'devel' => 0,
          'diff' => 0,
          'fb_connect' => 0,
          'menu' => 0,
          'newsletter_campaign' => 0,
          'node' => 0,
          'search' => 0,
          'search_api_facets' => 0,
          'search_api_page' => 0,
          'search_api_sorts' => 0,
          'shortcut' => 0,
          'system' => 0,
          'takepart_addthis' => 0,
          'takepart_custom' => 0,
          'twitter_pull' => 0,
          'user' => 0,
          'views' => 0,
        ),
        'default_context' => 'context_field_default_context',
        'use_default' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'context_field',
        'settings' => array(
          'form_element' => array(
            'allow_create' => 0,
            'category' => 'campaign',
          ),
        ),
        'type' => 'context_field_select',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-takepart_list-field_tp_campaign_show_title'.
  $fields['node-takepart_list-field_tp_campaign_show_title'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_show_title',
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
          0 => '0',
          1 => '1',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_list',
      'default_value' => array(
        0 => array(
          'value' => 0,
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
          'weight' => 5,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'vidpop_map' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_tp_campaign_show_title',
      'label' => 'Remove Headline from Display',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '2',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Multi Page Campaign');
  t('Remove Headline from Display');
  t('calendar');

  return $fields;
}
