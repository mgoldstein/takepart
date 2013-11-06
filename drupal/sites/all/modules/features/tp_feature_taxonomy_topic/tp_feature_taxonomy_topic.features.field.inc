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

  // Exported field: 'taxonomy_term-topic-field_promo_content'.
  $fields['taxonomy_term-topic-field_promo_content'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
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
            'openpublish_article' => 'openpublish_article',
            'openpublish_photo_gallery' => 'openpublish_photo_gallery',
            'openpublish_video' => 'openpublish_video',
            'section_front' => 'section_front',
          ),
        ),
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'topic',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 5,
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'entityreference',
          'settings' => array(
            'links' => 0,
            'view_mode' => 'feature_topic',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'taxonomy_term',
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
        'weight' => '6',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Promo Content');

  return $fields;
}
