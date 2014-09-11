<?php
/**
 * @file
 * tpf_content_flashcard.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function tpf_content_flashcard_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_flashcard_main_image'
  $field_bases['field_flashcard_main_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_flashcard_main_image',
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
    'translatable' => 0,
    'type' => 'media',
  );

  return $field_bases;
}
