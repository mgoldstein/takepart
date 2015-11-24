<?php
/**
 * @file
 * tpf_taxonomy.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function tpf_taxonomy_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-free_tags-field_free_tag_context'
  $field_instances['taxonomy_term-free_tags-field_free_tag_context'] = array(
    'bundle' => 'free_tags',
    'default_value' => array(
      0 => array(
        'context' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'context_field',
        'settings' => array(),
        'type' => 'context_field_context',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_free_tag_context',
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
        'boxes' => 0,
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
        'search_api_sorts' => 0,
        'shortcut' => 0,
        'system' => 0,
        'takepart_custom' => 0,
        'twitter_pull' => 0,
        'user' => 0,
        'views' => 0,
      ),
      'default_context' => 'free_tags_default_context',
      'required_for_pub' => FALSE,
      'use_default' => 1,
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
      'type' => 'context_field_default',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Context');

  return $field_instances;
}
