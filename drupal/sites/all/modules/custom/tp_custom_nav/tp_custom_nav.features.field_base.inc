<?php
/**
 * @file
 * tp_custom_nav.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function tp_custom_nav_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_slim_nav_bg_color'
  $field_bases['field_slim_nav_bg_color'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_slim_nav_bg_color',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'jquery_colorpicker',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'jquery_colorpicker',
  );

  // Exported field_base: 'field_slim_nav_font_color'
  $field_bases['field_slim_nav_font_color'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_slim_nav_font_color',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'jquery_colorpicker',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'jquery_colorpicker',
  );

  // Exported field_base: 'field_slim_nav_logo'
  $field_bases['field_slim_nav_logo'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_slim_nav_logo',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_slim_nav_logo_url'
  $field_bases['field_slim_nav_logo_url'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_slim_nav_logo_url',
    'indexes' => array(),
    'locked' => 0,
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
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_slim_nav_menu'
  $field_bases['field_slim_nav_menu'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_slim_nav_menu',
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
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_slim_nav_mobile_bg'
  $field_bases['field_slim_nav_mobile_bg'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_slim_nav_mobile_bg',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'jquery_colorpicker',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'jquery_colorpicker',
  );

  // Exported field_base: 'field_slim_nav_social_menu'
  $field_bases['field_slim_nav_social_menu'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_slim_nav_social_menu',
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
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
