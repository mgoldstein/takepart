<?php
/**
 * @file
 * tpf_display_context.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_display_context_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tpf_display_context_node_info() {
  $items = array(
    'takepart_list' => array(
      'name' => t('List'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'takepart_quick_study' => array(
      'name' => t('Quick Study'),
      'base' => 'node_content',
      'description' => t('A Quick info page to be attached to topics'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'takepart_slide' => array(
      'name' => t('Rotator Slide'),
      'base' => 'node_content',
      'description' => t('Used for slides that will be contained in the TakePart Rotator'),
      'has_title' => '1',
      'title_label' => t('Slide Name'),
      'help' => t('Enter a unique name to identify this slide when searching through content.'),
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
