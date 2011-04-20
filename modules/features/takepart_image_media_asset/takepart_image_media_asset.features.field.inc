<?php
/**
 * @file
 * takepart_image_media_asset.features.field.inc
 */

/**
 * Implementation of hook_field_default_fields().
 */
function takepart_image_media_asset_field_default_fields() {
  $fields = array();

  // Exported field: 'media-image-field_agency'
  $fields['media-image-field_agency'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_agency',
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
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'agency',
          ),
        ),
      ),
      'translatable' => '1',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'image',
      'default_value' => array(
        0 => array(
          'tid' => '1',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 4,
        ),
        'media_large' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_link' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_original' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_small' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'media',
      'field_name' => 'field_agency',
      'label' => 'Agency',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'media-image-field_caption'
  $fields['media-image-field_caption'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_caption',
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
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '1',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'image',
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
        'media_large' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_link' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_original' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_small' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'media',
      'field_name' => 'field_caption',
      'label' => 'Caption',
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

  // Exported field: 'media-image-field_credits'
  $fields['media-image-field_credits'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_credits',
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
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'parent' => '0',
            'vocabulary' => 'photo_credit',
          ),
        ),
      ),
      'translatable' => '1',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'image',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 3,
        ),
        'media_large' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_link' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_original' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_small' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'media',
      'field_name' => 'field_credits',
      'label' => 'Credits',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'media-image-field_rights'
  $fields['media-image-field_rights'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_rights',
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
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '1',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'image',
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
        'media_large' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_link' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_original' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_preview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'media_small' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'media',
      'field_name' => 'field_rights',
      'label' => 'Rights',
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
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'media-image-file'
  $fields['media-image-file'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'file',
      'foreign keys' => array(
        'fid' => array(
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
      'module' => 'file',
      'settings' => array(
        'display_default' => 0,
        'display_field' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'image',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
          'weight' => 0,
        ),
        'media_large' => array(
          'label' => 'above',
          'module' => 'styles',
          'settings' => array(),
          'type' => 'styles_file_large',
          'weight' => 0,
        ),
        'media_link' => array(
          'label' => 'above',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
          'weight' => 0,
        ),
        'media_original' => array(
          'label' => 'hidden',
          'module' => 'styles',
          'settings' => array(),
          'type' => 'styles_file_original',
          'weight' => -5,
        ),
        'media_preview' => array(
          'label' => 'hidden',
          'module' => 'styles',
          'settings' => array(),
          'type' => 'styles_file_square_thumbnail',
          'weight' => -5,
        ),
        'media_small' => array(
          'label' => 'above',
          'module' => 'file',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'media',
      'field_name' => 'file',
      'label' => 'File',
      'locked' => TRUE,
      'required' => TRUE,
      'settings' => array(
        'description_field' => 0,
        'file_directory' => '',
        'file_extensions' => 'txt',
        'max_filesize' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'file',
        'settings' => array(
          'progress_indicator' => 'throbber',
        ),
        'type' => 'file_generic',
        'weight' => '0',
      ),
      'widget_type' => 'file_file',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Agency');
  t('Caption');
  t('Credits');
  t('File');
  t('Rights');

  return $fields;
}
