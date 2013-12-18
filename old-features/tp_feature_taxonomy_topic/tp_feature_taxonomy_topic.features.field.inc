<?php
/**
 * @file
 * tp_feature_taxonomy_topic.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function tp_feature_taxonomy_topic_field_default_fields() {
  $fields = array();

  // Exported field: 'field_collection_item-field_promo_content_collection-field_promo_content'.
  $fields['field_collection_item-field_promo_content_collection-field_promo_content'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_promo_content',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'action' => 'action',
            'openpublish_article' => 'openpublish_article',
            'openpublish_photo_gallery' => 'openpublish_photo_gallery',
            'openpublish_video' => 'openpublish_video',
            'petition_action' => 'petition_action',
            'pledge_action' => 'pledge_action',
            'section_front' => 'section_front',
            'takepart_campaign' => 'takepart_campaign',
          ),
        ),
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'field_promo_content_collection',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Reference to promotional content.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_promo_content',
      'label' => 'Promo Content',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '0',
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_promo_content_collection-field_promo_headline'.
  $fields['field_collection_item-field_promo_content_collection-field_promo_headline'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_promo_headline',
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
      'bundle' => 'field_promo_content_collection',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Override the Promo Headline that is being referenced.  If left blank, the Promo Headline from the content that is being referenced will be used.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 2,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_promo_headline',
      'label' => 'Promo Headline',
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

  // Exported field: 'field_collection_item-field_promo_content_collection-field_promo_label'.
  $fields['field_collection_item-field_promo_content_collection-field_promo_label'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_promo_label',
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
      'bundle' => 'field_promo_content_collection',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Override for the promo label.
Text that labels what the promo is ("Most Popular"  "Trending").',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 3,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_promo_label',
      'label' => 'Promo Label',
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

  // Exported field: 'taxonomy_term-topic-field_promo_content_collection'.
  $fields['taxonomy_term-topic-field_promo_content_collection'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_promo_content_collection',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'field_collection',
      'settings' => array(
        'hide_blank_items' => 1,
        'path' => '',
      ),
      'translatable' => '0',
      'type' => 'field_collection',
    ),
    'field_instance' => array(
      'bundle' => 'topic',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'tp4_support',
          'settings' => array(),
          'type' => 'tp4_promo_content',
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'tp4_support',
          'settings' => array(),
          'type' => 'tp4_promo_content',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_promo_content_collection',
      'label' => 'Promo Content',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'field_collection',
        'settings' => array(),
        'type' => 'field_collection_embed',
        'weight' => '7',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Override for the promo label.
Text that labels what the promo is ("Most Popular"  "Trending").');
  t('Override the Promo Headline that is being referenced.  If left blank, the Promo Headline from the content that is being referenced will be used.');
  t('Promo Content');
  t('Promo Headline');
  t('Promo Label');
  t('Reference to promotional content.');

  return $fields;
}
