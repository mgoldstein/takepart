<?php
/**
 * @file
 * tpf_taxonomy_blog.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
/*
function tpf_taxonomy_blog_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-blog-field_blog_branding_image'
  $field_instances['taxonomy_term-blog-field_blog_branding_image'] = array(
    'bundle' => 'blog',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'mediafield',
        'settings' => array(
          'file_view_mode' => 'default',
        ),
        'type' => 'media',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'media_image_formatter',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'our_blogs_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'summary' => array(
        'label' => 'hidden',
        'module' => 'media_image_formatter',
        'settings' => array(
          'image_link' => 'content',
          'image_style' => 'tp_blog_branding_thumb',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'mediafield',
        'settings' => array(
          'file_view_mode' => 'default',
        ),
        'type' => 'media',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_blog_branding_image',
    'label' => 'Branding Image',
    'required' => 0,
    'settings' => array(
      'file_extensions' => 'jpg jpeg gif png txt doc docx xls xlsx pdf ppt pptx pps ppsx odt ods odp mp3 mov m4v mp4 mpeg avi ogg oga ogv wmv ico css',
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
          'video' => 0,
        ),
        'browser_plugins' => array(),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => 1,
    ),
  );
*/
  // Exported field_instance: 'taxonomy_term-blog-field_blog_override'
  $field_instances['taxonomy_term-blog-field_blog_override'] = array(
    'bundle' => 'blog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(
          'code' => 301,
        ),
        'type' => 'node_reference_default',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(
          'code' => 301,
        ),
        'type' => 'node_reference_default',
        'weight' => 3,
      ),
      'our_blogs_summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'summary' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_blog_override',
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
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-blog-field_blog_view'
  $field_instances['taxonomy_term-blog-field_blog_view'] = array(
    'bundle' => 'blog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'views_field',
        'settings' => array(
          'view' => 'blog_posts block',
        ),
        'type' => 'views_field_formatter',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'views_field',
        'settings' => array(
          'view' => 'blog_posts block_1',
        ),
        'type' => 'views_field_formatter',
        'weight' => 2,
      ),
      'our_blogs_summary' => array(
        'label' => 'hidden',
        'module' => 'views_field',
        'settings' => array(
          'view' => 'blog_posts block_2',
        ),
        'type' => 'views_field_formatter',
        'weight' => 0,
      ),
      'summary' => array(
        'label' => 'hidden',
        'module' => 'views_field',
        'settings' => array(
          'view' => 'blog_posts block',
        ),
        'type' => 'views_field_formatter',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_blog_view',
    'label' => 'Blog View',
    'required' => 0,
    'settings' => array(
      'local' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'views_field',
      'settings' => array(
        'widget_setting' => 'bob',
      ),
      'type' => 'views_field',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Blog View');
  t('Branding Image');
  t('Override');

  return $field_instances;
}
