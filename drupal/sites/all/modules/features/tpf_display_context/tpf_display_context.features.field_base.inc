<?php
/**
 * @file
 * tpf_display_context.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function tpf_display_context_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_blog_context'
  $field_bases['field_blog_context'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_blog_context',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'context_field',
    'settings' => array(
      'global_setting' => 255,
    ),
    'translatable' => 1,
    'type' => 'context_field',
  );

  // Exported field_base: 'field_blog_front_context'
  $field_bases['field_blog_front_context'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_blog_front_context',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'context_field',
    'settings' => array(
      'global_setting' => 255,
    ),
    'translatable' => 1,
    'type' => 'context_field',
  );

  // Exported field_base: 'field_blogpost_featured_action'
  $field_bases['field_blogpost_featured_action'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_blogpost_featured_action',
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
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'action' => 'action',
        'blog_front' => 0,
        'openpublish_article' => 0,
        'openpublish_blog_post' => 0,
        'openpublish_photo' => 0,
        'openpublish_photo_gallery' => 0,
        'openpublish_site_page' => 0,
        'openpublish_video' => 0,
        'profile' => 0,
        'section_front' => 0,
        'takepart_quick_study' => 0,
        'video_series' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 1,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_blogpost_main_image'
  $field_bases['field_blogpost_main_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_blogpost_main_image',
    'foreign keys' => array(
      'file_managed' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'mediafield',
    'settings' => array(),
    'translatable' => 1,
    'type' => 'media',
  );

  // Exported field_base: 'field_blogpost_subhead'
  $field_bases['field_blogpost_subhead'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_blogpost_subhead',
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
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 1,
    'type' => 'text',
  );

  return $field_bases;
}
