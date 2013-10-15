<?php
/**
 * @file
 * tp_feature_homepage.features.inc
 */

/**
 * Implements hook_ccl_features_preset().
 */
function tp_feature_homepage_ccl_features_preset() {
  return array(
    'Edit Overrides' => array(
      'type' => 'block',
      'title' => 'Edit Overrides',
      'link' => 'admin/structure/nodequeue/2/view/2',
      'options' => 'a:11:{s:12:"advanced_css";s:0:"";s:14:"advanced_query";s:0:"";s:15:"advanced_target";s:7:"default";s:12:"node_options";s:4:"node";s:9:"node_type";s:6:"action";s:7:"node_id";s:35:" [nid: [nid: [nid: [nid: [nid:]]]]]";s:12:"block_global";i:0;s:12:"block_select";a:1:{s:28:"views|latest_headlines-block";s:28:"views|latest_headlines-block";}s:12:"view_options";s:1:"0";s:12:"view_display";s:22:"latest_headlines|block";s:9:"view_view";s:9:"campaigns";}',
    ),
  );
}

/**
 * Implements hook_ctools_plugin_api().
 */
function tp_feature_homepage_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function tp_feature_homepage_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function tp_feature_homepage_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: latest_headlines
  $nodequeues['latest_headlines'] = array(
    'name' => 'latest_headlines',
    'title' => 'Latest Headlines',
    'subqueue_title' => '',
    'size' => '0',
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '0',
    'reference' => '0',
    'reverse' => '0',
    'i18n' => '0',
    'subqueues' => '1',
    'types' => array(
      0 => 'openpublish_article',
      1 => 'openpublish_photo_gallery',
      2 => 'openpublish_video',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
