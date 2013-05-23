<?php
/**
 * @file
 * takepart_rotator_slide.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function takepart_rotator_slide_ctools_plugin_api() {
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
 * Implements hook_views_api().
 */
function takepart_rotator_slide_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function takepart_rotator_slide_image_default_styles() {
  $styles = array();

  // Exported image style: takepart_rotator_slide.
  $styles['takepart_rotator_slide'] = array(
    'name' => 'takepart_rotator_slide',
    'effects' => array(
      31 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '640',
          'height' => '370',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function takepart_rotator_slide_node_info() {
  $items = array(
    'takepart_slide' => array(
      'name' => t('Rotator Slide'),
      'base' => 'node_content',
      'description' => t('Used for slides that will be contained in the TakePart Rotator'),
      'has_title' => '1',
      'title_label' => t('Slide Name'),
      'help' => t('Enter a unique name to identify this slide when searching through content.'),
    ),
  );
  return $items;
}
