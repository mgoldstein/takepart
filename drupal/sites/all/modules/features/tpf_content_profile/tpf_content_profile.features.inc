<?php
/**
 * @file
 * tpf_content_profile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_profile_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tpf_content_profile_node_info() {
  $items = array(
    'profile' => array(
      'name' => t('Profile'),
      'base' => 'node_content',
      'description' => t('Create a profile for a person, which may be an author, a staff member, or even a business.'),
      'has_title' => '1',
      'title_label' => t('Full Name'),
      'help' => t('This is the name used as the title of this content. This may be comprised of the First and Last names, or of the Organization name, or any other name that you choose.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
