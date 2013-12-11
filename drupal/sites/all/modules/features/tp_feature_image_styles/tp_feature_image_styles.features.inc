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

  // Exported image style: feature_article_hero.
  $styles['feature_article_hero'] = array(
    'name' => 'feature_article_hero',
    'label' => 'Feature Article: Hero',
    'effects' => array(
      57 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '980',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: feature_article_landscape.
  $styles['feature_article_landscape'] = array(
    'name' => 'feature_article_landscape',
    'label' => 'Feature Article: Landscape',
    'effects' => array(
      59 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '480',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: feature_article_portrait.
  $styles['feature_article_portrait'] = array(
    'name' => 'feature_article_portrait',
    'label' => 'Feature Article: Portrait',
    'effects' => array(
      58 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '400',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

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
