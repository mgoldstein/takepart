<?php
/**
 * @file
 * takepart_topic_front.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function takepart_topic_front_field_default_fields() {
  $fields = array();

  // Exported field: 'comment-comment_node_topic_front-comment_body'.
  $fields['comment-comment_node_topic_front-comment_body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'comment',
      ),
      'field_name' => 'comment_body',
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
      'bundle' => 'comment_node_topic_front',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'comment',
      'field_name' => 'comment_body',
      'label' => 'Comment',
      'required' => TRUE,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'node-topic_front-field_html_title'.
  $fields['node-topic_front-field_html_title'] = array(
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
      'bundle' => 'topic_front',
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
        'feature_main' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'feature_secondary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'feature_video' => array(
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
      'field_name' => 'field_html_title',
      'label' => 'HTML title Tag',
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

  // Exported field: 'node-topic_front-field_topic_front_context'.
  $fields['node-topic_front-field_topic_front_context'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_topic_front_context',
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
      'bundle' => 'topic_front',
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
          'weight' => '0',
        ),
        'feature_main' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'feature_secondary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'feature_video' => array(
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
      'field_name' => 'field_topic_front_context',
      'label' => 'Context',
      'required' => 0,
      'settings' => array(
        'allowed_blocks' => array(
          'Boxes for Field Box' => 0,
          'Boxes for View Box' => 0,
          'addthis' => 0,
          'boxes' => 'boxes',
          'comment' => 0,
          'context_ui' => 0,
          'devel' => 0,
          'diff' => 0,
          'menu' => 0,
          'node' => 0,
          'search' => 0,
          'shortcut' => 0,
          'system' => 0,
          'user' => 0,
          'views' => 0,
        ),
        'default_context' => 'context_field_default_context',
        'use_default' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'context_field',
        'settings' => array(
          'form_element' => array(
            'user_toggle' => 0,
          ),
          'widget_setting' => 'bob',
        ),
        'type' => 'context_field',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-topic-field_topic_context'.
  $fields['taxonomy_term-topic-field_topic_context'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_topic_context',
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
      'bundle' => 'topic',
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
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'context_field',
          'settings' => array(),
          'type' => 'context_field_context',
          'weight' => '2',
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_topic_context',
      'label' => 'Context',
      'required' => 0,
      'settings' => array(
        'allowed_blocks' => array(
          'Boxes for Field Box' => 0,
          'Boxes for View Box' => 0,
          'addthis' => 0,
          'boxes' => 'boxes',
          'comment' => 0,
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
          'views' => 'views',
        ),
        'default_context' => 'topic_default_context',
        'use_default' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'context_field',
        'settings' => array(
          'form_element' => array(
            'user_toggle' => 0,
          ),
          'widget_setting' => 'bob',
        ),
        'type' => 'context_field',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-topic-field_topic_override'.
  $fields['taxonomy_term-topic-field_topic_override'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_topic_override',
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
          'article' => 0,
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
          'takepart_group' => 0,
          'takepart_list' => 0,
          'takepart_page' => 0,
          'takepart_quick_study' => 0,
          'takepart_slide' => 0,
          'topic_front' => 'topic_front',
          'venue' => 0,
          'webform' => 0,
        ),
        'view' => array(
          'args' => array(
            0 => '',
          ),
          'display_name' => '',
          'view_name' => '',
        ),
      ),
      'translatable' => '1',
      'type' => 'node_reference',
    ),
    'field_instance' => array(
      'bundle' => 'topic',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '3',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_topic_override',
      'label' => 'Override',
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
        'weight' => '4',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Comment');
  t('Context');
  t('HTML title Tag');
  t('Override');

  return $fields;
}
