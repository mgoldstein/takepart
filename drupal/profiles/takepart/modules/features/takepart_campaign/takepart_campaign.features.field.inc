<?php
/**
 * @file
 * takepart_campaign.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function takepart_campaign_field_default_fields() {
  $fields = array();

  // Exported field: 'node-action-field_multi_page_campaign'.
  $fields['node-action-field_multi_page_campaign'] = array(
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
      'bundle' => 'action',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'action_summary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'context_field',
          'settings' => array(),
          'type' => 'context_field_context',
          'weight' => '6',
        ),
        'embed' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '27',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '28',
        ),
        'medium_preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '34',
        ),
        'vidpop_map' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_multi_page_campaign',
      'label' => 'Campaign Page of',
      'required' => 0,
      'settings' => array(
        'allowed_blocks' => array(
          'Boxes for Box' => 0,
          'Boxes for Screaming Headline' => 0,
          'Boxes for View Box' => 0,
          'addthis' => 0,
          'boxes' => 0,
          'comment' => 0,
          'context_related_menu' => 0,
          'context_ui' => 0,
          'devel' => 0,
          'diff' => 0,
          'menu' => 0,
          'node' => 0,
          'search' => 0,
          'search_api_facets' => 0,
          'shortcut' => 0,
          'system' => 0,
          'user' => 0,
          'views' => 0,
        ),
        'default_context' => 'multi_page_comapaign_default_context',
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
        'weight' => '12',
      ),
    ),
  );

  // Exported field: 'node-blog_front-field_multi_page_campaign'.
  $fields['node-blog_front-field_multi_page_campaign'] = array(
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
      'bundle' => 'blog_front',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'context_field',
          'settings' => array(),
          'type' => 'context_field_context',
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
      'field_name' => 'field_multi_page_campaign',
      'label' => 'Multi Page Campaign',
      'required' => 0,
      'settings' => array(
        'allowed_blocks' => array(
          'Boxes for Box' => 0,
          'Boxes for Screaming Headline' => 0,
          'Boxes for View Box' => 0,
          'addthis' => 0,
          'boxes' => 0,
          'comment' => 0,
          'context_related_menu' => 0,
          'context_ui' => 0,
          'devel' => 0,
          'diff' => 0,
          'menu' => 0,
          'node' => 0,
          'search' => 0,
          'search_api_facets' => 0,
          'shortcut' => 0,
          'system' => 0,
          'user' => 0,
          'views' => 0,
        ),
        'default_context' => 'multi_page_comapaign_default_context',
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
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-openpublish_article-field_multi_page_campaign'.
  $fields['node-openpublish_article-field_multi_page_campaign'] = array(
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
      'bundle' => 'openpublish_article',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'context_field',
          'settings' => array(),
          'type' => 'context_field_context',
          'weight' => '7',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'context_field',
          'settings' => array(),
          'type' => 'context_field_context',
          'weight' => '2',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '9',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_multi_page_campaign',
      'label' => 'Multi Page Campaign',
      'required' => 0,
      'settings' => array(
        'allowed_blocks' => array(
          'Boxes for Box' => 0,
          'Boxes for Screaming Headline' => 0,
          'Boxes for View Box' => 0,
          'addthis' => 0,
          'boxes' => 0,
          'comment' => 0,
          'context_related_menu' => 0,
          'context_ui' => 0,
          'devel' => 0,
          'diff' => 0,
          'menu' => 0,
          'node' => 0,
          'search' => 0,
          'search_api_facets' => 0,
          'shortcut' => 0,
          'system' => 0,
          'user' => 0,
          'views' => 0,
        ),
        'default_context' => 'multi_page_comapaign_default_context',
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
        'weight' => '15',
      ),
    ),
  );

  // Exported field: 'node-openpublish_blog_post-field_multi_page_campaign'.
  $fields['node-openpublish_blog_post-field_multi_page_campaign'] = array(
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
      'bundle' => 'openpublish_blog_post',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'context_field',
          'settings' => array(),
          'type' => 'context_field_context',
          'weight' => '19',
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
      ),
      'entity_type' => 'node',
      'field_name' => 'field_multi_page_campaign',
      'label' => 'Multi Page Campaign',
      'required' => 0,
      'settings' => array(
        'allowed_blocks' => array(
          'Boxes for Box' => 0,
          'Boxes for Screaming Headline' => 0,
          'Boxes for View Box' => 0,
          'addthis' => 0,
          'boxes' => 0,
          'comment' => 0,
          'context_related_menu' => 0,
          'context_ui' => 0,
          'devel' => 0,
          'diff' => 0,
          'menu' => 0,
          'node' => 0,
          'search' => 0,
          'search_api_facets' => 0,
          'shortcut' => 0,
          'system' => 0,
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
        'weight' => '16',
      ),
    ),
  );

  // Exported field: 'node-openpublish_photo_gallery-field_multi_page_campaign'.
  $fields['node-openpublish_photo_gallery-field_multi_page_campaign'] = array(
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
      'bundle' => 'openpublish_photo_gallery',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'context_field',
          'settings' => array(),
          'type' => 'context_field_context',
          'weight' => '4',
        ),
        'embed' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'context_field',
          'settings' => array(),
          'type' => 'context_field_context',
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
      'field_name' => 'field_multi_page_campaign',
      'label' => 'Multi Page Campaign',
      'required' => 0,
      'settings' => array(
        'allowed_blocks' => array(
          'Boxes for Box' => 0,
          'Boxes for Screaming Headline' => 0,
          'Boxes for View Box' => 0,
          'addthis' => 0,
          'boxes' => 0,
          'comment' => 0,
          'context_related_menu' => 0,
          'context_ui' => 0,
          'devel' => 0,
          'diff' => 0,
          'menu' => 0,
          'node' => 0,
          'search' => 0,
          'search_api_facets' => 0,
          'shortcut' => 0,
          'system' => 0,
          'user' => 0,
          'views' => 0,
        ),
        'default_context' => 'multi_page_comapaign_default_context',
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
        'weight' => '45',
      ),
    ),
  );

  // Exported field: 'node-openpublish_video-field_multi_page_campaign'.
  $fields['node-openpublish_video-field_multi_page_campaign'] = array(
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
      'bundle' => 'openpublish_video',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'context_field',
          'settings' => array(),
          'type' => 'context_field_context',
          'weight' => '6',
        ),
        'embed' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'context_field',
          'settings' => array(),
          'type' => 'context_field_context',
          'weight' => '5',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'vidpop_map' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_multi_page_campaign',
      'label' => 'Multi Page Campaign',
      'required' => 0,
      'settings' => array(
        'allowed_blocks' => array(
          'Boxes for Box' => 0,
          'Boxes for Screaming Headline' => 0,
          'Boxes for View Box' => 0,
          'addthis' => 0,
          'boxes' => 0,
          'comment' => 0,
          'context_related_menu' => 0,
          'context_ui' => 0,
          'devel' => 0,
          'diff' => 0,
          'menu' => 0,
          'node' => 0,
          'search' => 0,
          'search_api_facets' => 0,
          'shortcut' => 0,
          'system' => 0,
          'user' => 0,
          'views' => 0,
        ),
        'default_context' => 'multi_page_comapaign_default_context',
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

  // Exported field: 'node-takepart_campaign-body'.
  $fields['node-takepart_campaign-body'] = array(
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
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '3',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
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
      'field_name' => 'body',
      'label' => 'Body',
      'required' => FALSE,
      'settings' => array(
        'display_summary' => TRUE,
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 20,
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '2',
      ),
      'widget_type' => 'text_textarea_with_summary',
    ),
  );

  // Exported field: 'node-takepart_campaign-field_google_map'.
  $fields['node-takepart_campaign-field_google_map'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_google_map',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'gmapfield',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'gmapfield',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'gmapfield',
          'settings' => array(),
          'type' => 'gmapfield_formatter',
          'weight' => '33',
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
      'field_name' => 'field_google_map',
      'label' => 'Google Map',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'gmapfield',
        'settings' => array(),
        'type' => 'gmapfield_formatter',
        'weight' => '32',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_html_title'.
  $fields['node-takepart_campaign-field_html_title'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_html_title',
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
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '31',
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
      'field_name' => 'field_html_title',
      'label' => 'HTML title tag',
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
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_main_image'.
  $fields['node-takepart_campaign-field_main_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_main_image',
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
      'bundle' => 'takepart_campaign',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'media_image_formatter',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => '32',
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
      'field_name' => 'field_main_image',
      'label' => 'Main Image',
      'required' => 0,
      'settings' => array(
        'file_extensions' => 'jpg jpeg gif png txt doc docx xls xlsx pdf ppt pptx pps ppsx odt ods odp mp3 mov m4v mp4 mpeg avi ogg oga ogv wmv ico',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            'private' => 'private',
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
        ),
        'type' => 'media_generic',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_multi_page_campaign'.
  $fields['node-takepart_campaign-field_multi_page_campaign'] = array(
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
      'bundle' => 'takepart_campaign',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'context_field',
          'settings' => array(),
          'type' => 'context_field_context',
          'weight' => '28',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'context_field',
          'settings' => array(),
          'type' => 'context_field_context',
          'weight' => '1',
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
          'Boxes for Screaming Headline' => 0,
          'Boxes for View Box' => 0,
          'addthis' => 0,
          'boxes' => 0,
          'comment' => 0,
          'context_related_menu' => 0,
          'context_ui' => 0,
          'devel' => 0,
          'diff' => 0,
          'menu' => 0,
          'node' => 0,
          'search' => 0,
          'search_api_facets' => 0,
          'shortcut' => 0,
          'system' => 0,
          'user' => 0,
          'views' => 0,
        ),
        'default_context' => 'multi_page_comapaign_default_context',
        'use_default' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'context_field',
        'settings' => array(
          'form_element' => array(
            'allow_create' => 1,
            'category' => 'campaign',
          ),
        ),
        'type' => 'context_field_autocomplete',
        'weight' => '7',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_related_actions'.
  $fields['node-takepart_campaign-field_related_actions'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_related_actions',
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
          'action' => 'action',
          'audio' => 0,
          'blog_front' => 0,
          'openpublish_article' => 0,
          'openpublish_blog_post' => 0,
          'openpublish_photo' => 0,
          'openpublish_photo_gallery' => 0,
          'openpublish_video' => 0,
          'profile' => 0,
          'section_front' => 0,
          'takepart_campaign' => 0,
          'takepart_group' => 0,
          'takepart_list' => 0,
          'takepart_page' => 0,
          'takepart_quick_study' => 0,
          'takepart_slide' => 0,
          'topic_front' => 0,
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
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '25',
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
      'field_name' => 'field_related_actions',
      'label' => 'Related Actions',
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
        'weight' => '30',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_suggest_actions'.
  $fields['node-takepart_campaign-field_suggest_actions'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_suggest_actions',
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
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '1',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
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
          'weight' => '26',
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
      'field_name' => 'field_suggest_actions',
      'label' => 'Suggest Related Actions?',
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
        'weight' => '28',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_thumbnail'.
  $fields['node-takepart_campaign-field_thumbnail'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_thumbnail',
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
      'bundle' => 'takepart_campaign',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => NULL,
          'settings' => array(),
          'type' => 'media_large',
          'weight' => 34,
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
      'field_name' => 'field_thumbnail',
      'label' => 'Thumbnail',
      'required' => 0,
      'settings' => array(
        'file_extensions' => 'jpg jpeg gif png txt doc docx xls xlsx pdf ppt pptx pps ppsx odt ods odp mp3 mov m4v mp4 mpeg avi ogg oga ogv wmv ico',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            'private' => 'private',
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
        ),
        'type' => 'media_generic',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_topic'.
  $fields['node-takepart_campaign-field_topic'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_topic',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'topic',
            'parent' => '0',
            'depth' => '',
          ),
        ),
        'options_list_callback' => 'content_taxonomy_allowed_values',
      ),
      'translatable' => '1',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '29',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '28',
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
      'field_name' => 'field_topic',
      'label' => 'Topic',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_4_things_link'.
  $fields['node-takepart_campaign-field_tp_campaign_4_things_link'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '5',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_4_things_link',
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
      'translatable' => '1',
      'type' => 'link_field',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Users can create a set of 5 links with custom labels and URLs to be overlaid on top of a full-width image atop the Campaign page.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => '4',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
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
      'field_name' => 'field_tp_campaign_4_things_link',
      'label' => '5 things Links',
      'required' => 0,
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'configurable_title' => 0,
          'rel' => '',
          'target' => '_self',
          'title' => '',
        ),
        'display' => array(
          'url_cutoff' => '80',
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => '128',
        'title_value' => '',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_5_things_head'.
  $fields['node-takepart_campaign-field_tp_campaign_5_things_head'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_5_things_head',
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
      'translatable' => '1',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '3',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
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
      'field_name' => 'field_tp_campaign_5_things_head',
      'label' => '5 things Header',
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
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_alliances'.
  $fields['node-takepart_campaign-field_tp_campaign_alliances'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_alliances',
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
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '20',
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
      'field_name' => 'field_tp_campaign_alliances',
      'label' => 'Alliances',
      'required' => 0,
      'settings' => array(
        'text_processing' => '1',
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

  // Exported field: 'node-takepart_campaign-field_tp_campaign_context'.
  $fields['node-takepart_campaign-field_tp_campaign_context'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_context',
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
      'bundle' => 'takepart_campaign',
      'default_value' => array(
        0 => array(
          'context' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'context_field',
          'settings' => array(),
          'type' => 'context_field_context',
          'weight' => '2',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'context_field',
          'settings' => array(),
          'type' => 'context_field_context',
          'weight' => '2',
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
      'field_name' => 'field_tp_campaign_context',
      'label' => 'Context',
      'required' => 0,
      'settings' => array(
        'allowed_blocks' => array(
          'Boxes for Box' => 0,
          'Boxes for Features Box' => 0,
          'Boxes for Field Box' => 0,
          'Boxes for Image Box' => 0,
          'Boxes for Screaming Headline' => 0,
          'Boxes for View Box' => 0,
          'addthis' => 0,
          'akamai' => 0,
          'boxes' => 'boxes',
          'comment' => 0,
          'comment_block_simple' => 0,
          'context_related_menu' => 0,
          'context_ui' => 0,
          'diff' => 0,
          'fb_connect' => 0,
          'menu' => 0,
          'newsletter_campaign' => 0,
          'node' => 0,
          'search' => 0,
          'search_api_facets' => 0,
          'search_api_page' => 0,
          'shortcut' => 0,
          'system' => 0,
          'takepart_custom' => 0,
          'twitter_pull' => 0,
          'user' => 0,
          'views' => 0,
        ),
        'default_context' => 'takepart_campaign_default',
        'use_default' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'context_field',
        'settings' => array(
          'form_element' => array(
            'user_toggle' => 0,
          ),
          'widget_setting' => 'bob',
        ),
        'type' => 'context_field',
        'weight' => '13',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_cover_image'.
  $fields['node-takepart_campaign-field_tp_campaign_cover_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_cover_image',
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
      'bundle' => 'takepart_campaign',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'media_image_formatter',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'tp_campaign_cover',
          ),
          'type' => 'image',
          'weight' => '19',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
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
      'field_name' => 'field_tp_campaign_cover_image',
      'label' => 'Image',
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
            'public' => 'public',
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
        'weight' => '11',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_cover_intro'.
  $fields['node-takepart_campaign-field_tp_campaign_cover_intro'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_cover_intro',
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
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '18',
        ),
        'full' => array(
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
      'field_name' => 'field_tp_campaign_cover_intro',
      'label' => 'More Info',
      'required' => 0,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '9',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_cover_link'.
  $fields['node-takepart_campaign-field_tp_campaign_cover_link'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_cover_link',
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
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
          'weight' => '17',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'link',
          'settings' => array(),
          'type' => 'link_default',
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
      'field_name' => 'field_tp_campaign_cover_link',
      'label' => 'More Info Link',
      'required' => 0,
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'configurable_title' => 0,
          'rel' => '',
          'target' => 'user',
          'title' => '',
        ),
        'display' => array(
          'url_cutoff' => '80',
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => '128',
        'title_value' => '',
        'url' => 0,
        'user_register_form' => FALSE,
        'validate_url' => 1,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_field',
        'weight' => '10',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_header'.
  $fields['node-takepart_campaign-field_tp_campaign_header'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_header',
      'foreign keys' => array(),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'media',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'media',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'media_image_formatter',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'tp_page_wide',
          ),
          'type' => 'image',
          'weight' => '16',
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
      'field_name' => 'field_tp_campaign_header',
      'label' => 'Multi Page Header',
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
            'brightcove' => 0,
            'public' => 'public',
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
        'weight' => '8',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_intro_html'.
  $fields['node-takepart_campaign-field_tp_campaign_intro_html'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_intro_html',
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
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '5',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
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
      'field_name' => 'field_tp_campaign_intro_html',
      'label' => 'Intro HTML',
      'required' => 0,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_intro_media'.
  $fields['node-takepart_campaign-field_tp_campaign_intro_media'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_intro_media',
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
      'bundle' => 'takepart_campaign',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'media',
          'settings' => array(
            'file_view_mode' => 'media_original',
          ),
          'type' => 'media',
          'weight' => '2',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
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
      'field_name' => 'field_tp_campaign_intro_media',
      'label' => 'Intro Media',
      'required' => 0,
      'settings' => array(
        'file_extensions' => 'jpg jpeg gif png txt doc docx xls xlsx pdf ppt pptx pps ppsx odt ods odp mp3 mov m4v mp4 mpeg avi ogg oga ogv wmv ico',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            'public' => 'public',
          ),
          'allowed_types' => array(
            'audio' => 0,
            'default' => 0,
            'image' => 'image',
            'video' => 'video',
          ),
          'progress_indicator' => 'throbber',
        ),
        'type' => 'media_generic',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_seg_1_html'.
  $fields['node-takepart_campaign-field_tp_campaign_seg_1_html'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_seg_1_html',
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
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
      'default_value' => array(
        0 => array(
          'value' => 'User enters some custom HTML to be displayed atop the list of nodes for this segment.',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '5',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '25',
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
      'field_name' => 'field_tp_campaign_seg_1_html',
      'label' => 'Segment 1 HTML',
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

  // Exported field: 'node-takepart_campaign-field_tp_campaign_seg_1_label'.
  $fields['node-takepart_campaign-field_tp_campaign_seg_1_label'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_seg_1_label',
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
      'translatable' => '1',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'User provides a name for this segment (equivalent to the label on the old tabs).',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '4',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '18',
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
      'field_name' => 'field_tp_campaign_seg_1_label',
      'label' => 'Segment 1 Label',
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

  // Exported field: 'node-takepart_campaign-field_tp_campaign_seg_1_rel'.
  $fields['node-takepart_campaign-field_tp_campaign_seg_1_rel'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_seg_1_rel',
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
          'action' => 'action',
          'audio' => 'audio',
          'blog_front' => 0,
          'openpublish_article' => 'openpublish_article',
          'openpublish_blog_post' => 'openpublish_blog_post',
          'openpublish_photo' => 0,
          'openpublish_photo_gallery' => 'openpublish_photo_gallery',
          'openpublish_video' => 'openpublish_video',
          'profile' => 0,
          'section_front' => 0,
          'takepart_campaign' => 'takepart_campaign',
          'takepart_group' => 'takepart_group',
          'takepart_list' => 'takepart_list',
          'takepart_page' => 'takepart_page',
          'takepart_quick_study' => 'takepart_quick_study',
          'takepart_slide' => 0,
          'topic_front' => 0,
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
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'User references one or more nodes to be listed within this segment, represented by promo headline/text.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '6',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '20',
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
      'field_name' => 'field_tp_campaign_seg_1_rel',
      'label' => 'Segment 1 Related Content',
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
        'weight' => '19',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_seg_2_html'.
  $fields['node-takepart_campaign-field_tp_campaign_seg_2_html'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_seg_2_html',
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
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
      'default_value' => array(
        0 => array(
          'value' => 'User enters some custom HTML to be displayed atop the list of nodes for this segment.',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '8',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '26',
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
      'field_name' => 'field_tp_campaign_seg_2_html',
      'label' => 'Segment 2 HTML',
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
        'weight' => '22',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_seg_2_label'.
  $fields['node-takepart_campaign-field_tp_campaign_seg_2_label'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_seg_2_label',
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
      'translatable' => '1',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'User provides a name for this segment (equivalent to the label on the old tabs).',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '7',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '17',
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
      'field_name' => 'field_tp_campaign_seg_2_label',
      'label' => 'Segment 2 Label',
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
        'weight' => '21',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_seg_2_rel'.
  $fields['node-takepart_campaign-field_tp_campaign_seg_2_rel'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_seg_2_rel',
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
          'action' => 'action',
          'audio' => 'audio',
          'blog_front' => 0,
          'openpublish_article' => 'openpublish_article',
          'openpublish_blog_post' => 'openpublish_blog_post',
          'openpublish_photo' => 0,
          'openpublish_photo_gallery' => 'openpublish_photo_gallery',
          'openpublish_video' => 'openpublish_video',
          'profile' => 0,
          'section_front' => 0,
          'takepart_campaign' => 'takepart_campaign',
          'takepart_group' => 'takepart_group',
          'takepart_list' => 'takepart_list',
          'takepart_page' => 'takepart_page',
          'takepart_quick_study' => 'takepart_quick_study',
          'takepart_slide' => 0,
          'topic_front' => 0,
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
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'User references one or more nodes to be listed within this segment, represented by promo headline/text.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '9',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '21',
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
      'field_name' => 'field_tp_campaign_seg_2_rel',
      'label' => 'Segment 2 Related Content',
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
        'weight' => '24',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_seg_3_html'.
  $fields['node-takepart_campaign-field_tp_campaign_seg_3_html'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_seg_3_html',
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
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
      'default_value' => array(
        0 => array(
          'value' => 'User enters some custom HTML to be displayed atop the list of nodes for this segment.',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '11',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '24',
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
      'field_name' => 'field_tp_campaign_seg_3_html',
      'label' => ' Segment 3 HTML',
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

  // Exported field: 'node-takepart_campaign-field_tp_campaign_seg_3_label'.
  $fields['node-takepart_campaign-field_tp_campaign_seg_3_label'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_seg_3_label',
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
      'translatable' => '1',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'User provides a name for this segment (equivalent to the label on the old tabs).',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '10',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '15',
        ),
        'teaser' => array(
          'label' => 'hidden',
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
      'field_name' => 'field_tp_campaign_seg_3_label',
      'label' => ' Segment 3 Label',
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

  // Exported field: 'node-takepart_campaign-field_tp_campaign_seg_3_rel'.
  $fields['node-takepart_campaign-field_tp_campaign_seg_3_rel'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_seg_3_rel',
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
          'action' => 'action',
          'audio' => 'audio',
          'blog_front' => 0,
          'openpublish_article' => 'openpublish_article',
          'openpublish_blog_post' => 'openpublish_blog_post',
          'openpublish_photo' => 0,
          'openpublish_photo_gallery' => 'openpublish_photo_gallery',
          'openpublish_video' => 'openpublish_video',
          'profile' => 0,
          'section_front' => 0,
          'takepart_campaign' => 'takepart_campaign',
          'takepart_group' => 'takepart_group',
          'takepart_list' => 'takepart_list',
          'takepart_page' => 'takepart_page',
          'takepart_quick_study' => 'takepart_quick_study',
          'takepart_slide' => 0,
          'topic_front' => 0,
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
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'User references one or more nodes to be listed within this segment, represented by promo headline/text.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '12',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '22',
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
      'field_name' => 'field_tp_campaign_seg_3_rel',
      'label' => ' Segment 3 Related Content',
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
        'weight' => '19',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_seg_4_html'.
  $fields['node-takepart_campaign-field_tp_campaign_seg_4_html'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_seg_4_html',
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
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
      'default_value' => array(
        0 => array(
          'value' => 'User enters some custom HTML to be displayed atop the list of nodes for this segment.',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '14',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '27',
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
      'field_name' => 'field_tp_campaign_seg_4_html',
      'label' => '  Segment 4 HTML',
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

  // Exported field: 'node-takepart_campaign-field_tp_campaign_seg_4_label'.
  $fields['node-takepart_campaign-field_tp_campaign_seg_4_label'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_seg_4_label',
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
      'translatable' => '1',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'User provides a name for this segment (equivalent to the label on the old tabs).',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '13',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '16',
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
      'field_name' => 'field_tp_campaign_seg_4_label',
      'label' => '  Segment 4 Label',
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

  // Exported field: 'node-takepart_campaign-field_tp_campaign_seg_4_rel'.
  $fields['node-takepart_campaign-field_tp_campaign_seg_4_rel'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_seg_4_rel',
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
          'action' => 'action',
          'audio' => 'audio',
          'blog_front' => 0,
          'openpublish_article' => 'openpublish_article',
          'openpublish_blog_post' => 'openpublish_blog_post',
          'openpublish_photo' => 0,
          'openpublish_photo_gallery' => 'openpublish_photo_gallery',
          'openpublish_video' => 'openpublish_video',
          'profile' => 0,
          'section_front' => 0,
          'takepart_campaign' => 'takepart_campaign',
          'takepart_group' => 'takepart_group',
          'takepart_list' => 'takepart_list',
          'takepart_page' => 'takepart_page',
          'takepart_quick_study' => 'takepart_quick_study',
          'takepart_slide' => 0,
          'topic_front' => 0,
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
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'User references one or more nodes to be listed within this segment, represented by promo headline/text.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '15',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '23',
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
      'field_name' => 'field_tp_campaign_seg_4_rel',
      'label' => '  Segment 4 Related Content',
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
        'weight' => '19',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_show_title'.
  $fields['node-takepart_campaign-field_tp_campaign_show_title'] = array(
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
      'bundle' => 'takepart_campaign',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => 'Check this box to remove the headline from the campaign page.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '27',
        ),
        'full' => array(
          'label' => 'hidden',
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
      'field_name' => 'field_tp_campaign_show_title',
      'label' => 'Remove Headline on Campaign Page',
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
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_sl_html'.
  $fields['node-takepart_campaign-field_tp_campaign_sl_html'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_sl_html',
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
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'User can populate custom HTML to be displayed in the Spotlight block instead of (or in addition to) Spotlight Nodes.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '24',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '14',
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
      'field_name' => 'field_tp_campaign_sl_html',
      'label' => 'Spotlight HTML',
      'required' => 0,
      'settings' => array(
        'text_processing' => '1',
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

  // Exported field: 'node-takepart_campaign-field_tp_campaign_sl_image'.
  $fields['node-takepart_campaign-field_tp_campaign_sl_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_sl_image',
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
      'bundle' => 'takepart_campaign',
      'deleted' => '0',
      'description' => 'User can create and/or reference a Photo to serve as the Spotlight Image.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'media_image_formatter',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'tp_272',
          ),
          'type' => 'image',
          'weight' => '22',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '12',
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
      'field_name' => 'field_tp_campaign_sl_image',
      'label' => 'Spotlight Image',
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
            'public' => 'public',
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
        'weight' => '11',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_sl_nodes'.
  $fields['node-takepart_campaign-field_tp_campaign_sl_nodes'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_sl_nodes',
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
          'action' => 'action',
          'audio' => 'audio',
          'blog_front' => 0,
          'openpublish_article' => 'openpublish_article',
          'openpublish_blog_post' => 'openpublish_blog_post',
          'openpublish_photo' => 0,
          'openpublish_photo_gallery' => 'openpublish_photo_gallery',
          'openpublish_video' => 'openpublish_video',
          'profile' => 0,
          'section_front' => 0,
          'takepart_campaign' => 'takepart_campaign',
          'takepart_group' => 'takepart_group',
          'takepart_list' => 'takepart_list',
          'takepart_page' => 'takepart_page',
          'takepart_quick_study' => 'takepart_quick_study',
          'takepart_slide' => 0,
          'topic_front' => 0,
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
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Users can choose a set of nodes to be displayed in the Spotlight block (Promo headline/text displayed for each).',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '23',
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '13',
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
      'field_name' => 'field_tp_campaign_sl_nodes',
      'label' => 'Spotlight Nodes',
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
        'weight' => '13',
      ),
    ),
  );

  // Exported field: 'node-takepart_campaign-field_tp_campaign_sponsors'.
  $fields['node-takepart_campaign-field_tp_campaign_sponsors'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_sponsors',
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
          'openpublish_article' => 0,
          'openpublish_blog_post' => 0,
          'openpublish_photo' => 0,
          'openpublish_photo_gallery' => 0,
          'openpublish_video' => 0,
          'profile' => 0,
          'section_front' => 0,
          'takepart_campaign' => 0,
          'takepart_group' => 'takepart_group',
          'takepart_page' => 0,
          'takepart_quick_study' => 0,
          'takepart_slide' => 0,
          'topic_front' => 0,
          'video_series' => 0,
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
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'User can reference one or more Group nodes that sponsor this Campaign. The Groups will be featured prominently on the Campaign page in order to indicate their affiliation.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'node_reference',
          'settings' => array(
            'view' => 'groups block',
          ),
          'type' => 'node_reference_default',
          'weight' => '21',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '10',
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
      'field_name' => 'field_tp_campaign_sponsors',
      'label' => 'Campaign Sponsors',
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

  // Exported field: 'node-takepart_campaign-field_tp_campaign_subheadline'.
  $fields['node-takepart_campaign-field_tp_campaign_subheadline'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tp_campaign_subheadline',
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
      'translatable' => '1',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'takepart_campaign',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'hidden',
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
      'field_name' => 'field_tp_campaign_subheadline',
      'label' => 'Sub Headline',
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
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'node-takepart_page-field_multi_page_campaign'.
  $fields['node-takepart_page-field_multi_page_campaign'] = array(
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
      'bundle' => 'takepart_page',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'context_field',
          'settings' => array(),
          'type' => 'context_field_context',
          'weight' => '16',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '6',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_multi_page_campaign',
      'label' => 'Multi Page Campaign',
      'required' => 0,
      'settings' => array(
        'allowed_blocks' => array(
          'Boxes for Box' => 0,
          'Boxes for Screaming Headline' => 0,
          'Boxes for View Box' => 0,
          'addthis' => 0,
          'boxes' => 0,
          'comment' => 0,
          'context_related_menu' => 0,
          'context_ui' => 0,
          'devel' => 0,
          'diff' => 0,
          'menu' => 0,
          'node' => 0,
          'search' => 0,
          'search_api_facets' => 0,
          'shortcut' => 0,
          'system' => 0,
          'user' => 0,
          'views' => 0,
        ),
        'default_context' => 'multi_page_comapaign_default_context',
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
        'weight' => '18',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('  Segment 4 HTML');
  t('  Segment 4 Label');
  t('  Segment 4 Related Content');
  t(' Segment 3 HTML');
  t(' Segment 3 Label');
  t(' Segment 3 Related Content');
  t('5 things Header');
  t('5 things Links');
  t('Alliances');
  t('Body');
  t('Campaign Page of');
  t('Campaign Sponsors');
  t('Check this box to remove the headline from the campaign page.');
  t('Context');
  t('Google Map');
  t('HTML title tag');
  t('Image');
  t('Intro HTML');
  t('Intro Media');
  t('Main Image');
  t('More Info');
  t('More Info Link');
  t('Multi Page Campaign');
  t('Multi Page Header');
  t('Related Actions');
  t('Remove Headline on Campaign Page');
  t('Segment 1 HTML');
  t('Segment 1 Label');
  t('Segment 1 Related Content');
  t('Segment 2 HTML');
  t('Segment 2 Label');
  t('Segment 2 Related Content');
  t('Spotlight HTML');
  t('Spotlight Image');
  t('Spotlight Nodes');
  t('Sub Headline');
  t('Suggest Related Actions?');
  t('Thumbnail');
  t('Topic');
  t('User can create and/or reference a Photo to serve as the Spotlight Image.');
  t('User can populate custom HTML to be displayed in the Spotlight block instead of (or in addition to) Spotlight Nodes.');
  t('User can reference one or more Group nodes that sponsor this Campaign. The Groups will be featured prominently on the Campaign page in order to indicate their affiliation.');
  t('User provides a name for this segment (equivalent to the label on the old tabs).');
  t('User references one or more nodes to be listed within this segment, represented by promo headline/text.');
  t('Users can choose a set of nodes to be displayed in the Spotlight block (Promo headline/text displayed for each).');
  t('Users can create a set of 5 links with custom labels and URLs to be overlaid on top of a full-width image atop the Campaign page.');

  return $fields;
}
