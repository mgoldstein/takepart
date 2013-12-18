<?php
/**
 * @file
 * tp_feature_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function tp_feature_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: topic_feature.
  $styles['topic_feature'] = array(
    'name' => 'topic_feature',
    'label' => 'Topic Feature',
    'effects' => array(
      59 => array(
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
          'height' => '477',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: topic_thumbnail.
  $styles['topic_thumbnail'] = array(
    'name' => 'topic_thumbnail',
    'label' => 'Topic Thumbnail',
    'effects' => array(
      58 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '96',
          'height' => '64',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
