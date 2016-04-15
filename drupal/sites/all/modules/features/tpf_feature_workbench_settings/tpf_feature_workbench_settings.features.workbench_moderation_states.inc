<?php
/**
 * @file
 * tpf_feature_workbench_settings.features.workbench_moderation_states.inc
 */

/**
 * Implements hook_workbench_moderation_export_states().
 */
function tpf_feature_workbench_settings_workbench_moderation_export_states() {
  $items = array(
    'draft' => array(
      'name' => 'draft',
      'label' => 'Draft',
      'description' => 'Work in progress',
      'weight' => -10,
    ),
    'needs_review' => array(
      'name' => 'needs_review',
      'label' => 'Ready for Publish',
      'description' => 'Ready for publishing',
      'weight' => -6,
    ),
    'published' => array(
      'name' => 'published',
      'label' => 'Published',
      'description' => 'Make this version live',
      'weight' => -5,
    ),
    'ready_for_copyedit' => array(
      'name' => 'ready_for_copyedit',
      'label' => 'Ready for copyedit',
      'description' => 'Needs copyediting',
      'weight' => -7,
    ),
    'ready_for_edit' => array(
      'name' => 'ready_for_edit',
      'label' => 'Ready for edit',
      'description' => 'Needs editorial review',
      'weight' => -9,
    ),
    'ready_for_photo' => array(
      'name' => 'ready_for_photo',
      'label' => 'Ready for photo',
      'description' => 'Needs photo assets',
      'weight' => -8,
    ),
  );
  return $items;
}
