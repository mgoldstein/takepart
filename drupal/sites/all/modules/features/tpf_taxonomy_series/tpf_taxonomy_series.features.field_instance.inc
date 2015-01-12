<?php
/**
 * @file
 * tpf_taxonomy_series.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function tpf_taxonomy_series_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-series-field_html_title'
  $field_instances['taxonomy_term-series-field_html_title'] = array(
    'bundle' => 'series',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_html_title',
    'label' => 'HTML title tag',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'taxonomy_term-series-field_series_context'
  $field_instances['taxonomy_term-series-field_series_context'] = array(
    'bundle' => 'series',
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
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_series_context',
    'label' => 'Context',
    'required' => 0,
    'settings' => array(
      'allowed_blocks' => array(
        'Boxes for Box' => 0,
        'Boxes for Field Box' => 0,
        'Boxes for View Box' => 0,
        'addthis' => 0,
        'boxes' => 0,
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
        'views' => 0,
      ),
      'default_context' => 'series_default_context',
      'use_default' => 1,
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'taxonomy_term-series-field_series_graphic_header'
  $field_instances['taxonomy_term-series-field_series_graphic_header'] = array(
    'bundle' => 'series',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'file_entity',
        'settings' => array(
          'file_view_mode' => 'media_original',
        ),
        'type' => 'file_rendered',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_series_graphic_header',
    'label' => 'Series Graphic Header',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'action_header_image',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'taxonomy_term-series-field_series_graphic_header_link'
  $field_instances['taxonomy_term-series-field_series_graphic_header_link'] = array(
    'bundle' => 'series',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If left blank, the Series graphic header will automatically link back to the Series landing page. Otherwise, the header image will link back to the URL provided in this field.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_series_graphic_header_link',
    'label' => 'Series Graphic Header Link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'none',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
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
      'weight' => 9,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Context');
  t('HTML title tag');
  t('If left blank, the Series graphic header will automatically link back to the Series landing page. Otherwise, the header image will link back to the URL provided in this field.');
  t('Series Graphic Header');
  t('Series Graphic Header Link');

  return $field_instances;
}
