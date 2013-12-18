<?php
/**
 * @file
 * takepart_omniture.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function takepart_omniture_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function takepart_omniture_node_info() {
  $items = array(
    'petition_action' => array(
      'name' => t('Petition Action'),
      'base' => 'node_content',
      'description' => t('Used to add petitions to the site.'),
      'has_title' => '1',
      'title_label' => t('Page Title'),
      'help' => '',
    ),
    'pledge_action' => array(
      'name' => t('Pledge Action'),
      'base' => 'node_content',
      'description' => t('Used to add pledges to the site.'),
      'has_title' => '1',
      'title_label' => t('Page Title'),
      'help' => '',
    ),
    'profile' => array(
      'name' => t('Profile'),
      'base' => 'node_content',
      'description' => t('Create a profile for a person, which may be an author, a staff member, or even a business.'),
      'has_title' => '1',
      'title_label' => t('Full Name'),
      'help' => t('This is the name used as the title of this content. This may be comprised of the First and Last names, or of the Organization name, or any other name that you choose.'),
    ),
    'venue' => array(
      'name' => t('Venue'),
      'base' => 'node_content',
      'description' => t('Content that applies to a physical location, such as a business or event place.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
