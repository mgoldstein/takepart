<?php
/**
 * @file
 * tpf_feature_homepage.features.inc
 */

/**
 * Implements hook_ccl_features_preset().
 */
function tpf_feature_homepage_ccl_features_preset() {
  return array(
    'Edit Homepage Columns' => array(
      'type' => 'block',
      'title' => 'Edit Homepage Columns',
      'link' => 'admin/structure/taxonomy/series',
      'options' => 'a:8:{s:12:"advanced_css";s:0:"";s:14:"advanced_query";s:0:"";s:15:"advanced_target";s:7:"default";s:12:"node_options";s:4:"node";s:9:"node_type";s:6:"action";s:7:"node_id";s:7:" [nid:]";s:12:"block_global";i:0;s:12:"block_select";a:1:{s:28:"views|homepage_columns-block";s:28:"views|homepage_columns-block";}}',
    ),
    'Edit Overrides' => array(
      'type' => 'block',
      'title' => 'Edit Overrides',
      'link' => 'admin/structure/nodequeue/1/view/1',
      'options' => 'a:8:{s:12:"advanced_css";s:0:"";s:14:"advanced_query";s:0:"";s:15:"advanced_target";s:7:"default";s:12:"node_options";s:4:"node";s:9:"node_type";s:6:"action";s:7:"node_id";s:42:" [nid: [nid: [nid: [nid: [nid: [nid:]]]]]]";s:12:"block_global";i:0;s:12:"block_select";a:1:{s:28:"views|latest_headlines-block";s:28:"views|latest_headlines-block";}}',
    ),
    'Edit Photo Galleries Panel' => array(
      'type' => 'block',
      'title' => 'Edit Photo Galleries Panel',
      'link' => 'admin/structure/nodequeue/11/view/11',
      'options' => 'a:8:{s:12:"advanced_css";s:0:"";s:14:"advanced_query";s:0:"";s:15:"advanced_target";s:7:"default";s:12:"node_options";s:4:"node";s:9:"node_type";s:6:"action";s:7:"node_id";s:21:" [nid: [nid: [nid:]]]";s:12:"block_global";i:0;s:12:"block_select";a:1:{s:33:"views|photo_galleries_promo-block";s:33:"views|photo_galleries_promo-block";}}',
    ),
  );
}

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_feature_homepage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function tpf_feature_homepage_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function tpf_feature_homepage_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: latest_headlines
  $nodequeues['latest_headlines'] = array(
    'name' => 'latest_headlines',
    'title' => 'Latest Headlines',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'feature_article',
      1 => 'openpublish_article',
      2 => 'openpublish_photo_gallery',
      3 => 'video',
      4 => 'video_playlist',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: photo_galleries_promo
  $nodequeues['photo_galleries_promo'] = array(
    'name' => 'photo_galleries_promo',
    'title' => 'Photo Galleries Promo',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'openpublish_photo_gallery',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: takeaction_promo
  $nodequeues['takeaction_promo'] = array(
    'name' => 'takeaction_promo',
    'title' => 'TakeAction Promo',
    'subqueue_title' => '',
    'size' => 13,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'action',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function tpf_feature_homepage_image_default_styles() {
  $styles = array();

  // Exported image style: homepage_featured_image.
  $styles['homepage_featured_image'] = array(
    'name' => 'homepage_featured_image',
    'label' => 'Homepage Featured Image',
    'effects' => array(
      57 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 425,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
