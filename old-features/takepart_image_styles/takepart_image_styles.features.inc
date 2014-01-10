<?php
/**
 * @file
 * takepart_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function takepart_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: 70x70_thumbnail.
  $styles['70x70_thumbnail'] = array(
    'name' => '70x70_thumbnail',
    'label' => '70x70_thumbnail',
    'effects' => array(
      13 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '70',
          'height' => '70',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: action_header_image.
  $styles['action_header_image'] = array(
    'name' => 'action_header_image',
    'label' => 'action_header_image',
    'effects' => array(
      7 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '640',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: action_main_image.
  $styles['action_main_image'] = array(
    'name' => 'action_main_image',
    'label' => 'action_main_image',
    'effects' => array(
      47 => array(
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
          'height' => '330',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: action_medium_preview.
  $styles['action_medium_preview'] = array(
    'name' => 'action_medium_preview',
    'label' => 'action_medium_preview',
    'effects' => array(
      51 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '270',
          'height' => '156',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: action_summary_group.
  $styles['action_summary_group'] = array(
    'name' => 'action_summary_group',
    'label' => 'action_summary_group',
    'effects' => array(
      37 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '172',
          'height' => '172',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: embed_gallery_thumb.
  $styles['embed_gallery_thumb'] = array(
    'name' => 'embed_gallery_thumb',
    'label' => 'embed_gallery_thumb',
    'effects' => array(
      15 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '107',
          'height' => '76',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: inline_thumbnail.
  $styles['inline_thumbnail'] = array(
    'name' => 'inline_thumbnail',
    'effects' => array(
      52 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '150',
          'height' => '100',
        ),
        'weight' => '1',
      ),
    ),
    'label' => 'inline_thumbnail',
  );

  // Exported image style: landscape_main_image.
  $styles['landscape_main_image'] = array(
    'name' => 'landscape_main_image',
    'label' => 'landscape_main_image',
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
	  'width' => '583',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: portrait_main_image.
  $styles['portrait_main_image'] = array(
    'name' => 'portrait_main_image',
    'label' => 'portrait_main_image',
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

  // Exported image style: right-sidebar-thumbnails.
  $styles['right-sidebar-thumbnails'] = array(
    'name' => 'right-sidebar-thumbnails',
    'label' => 'right-sidebar-thumbnails',
    'effects' => array(
      39 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '80',
          'height' => '80',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: rss_images.
  $styles['rss_images'] = array(
    'name' => 'rss_images',
    'label' => 'rss_images',
    'effects' => array(
      29 => array(
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
          'height' => '480',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: square_thumbnail_small.
  $styles['square_thumbnail_small'] = array(
    'name' => 'square_thumbnail_small',
    'label' => 'square_thumbnail_small',
    'effects' => array(
      11 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '140',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: thumbnail_v2.
  $styles['thumbnail_v2'] = array(
    'name' => 'thumbnail_v2',
    'effects' => array(
      54 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '100',
          'height' => '100',
        ),
        'weight' => '1',
      ),
    ),
    'label' => 'thumbnail_v2',
  );

  // Exported image style: tp_250_wide.
  $styles['tp_250_wide'] = array(
    'name' => 'tp_250_wide',
    'label' => 'tp_250_wide',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '250',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: tp_272.
  $styles['tp_272'] = array(
    'name' => 'tp_272',
    'label' => 'tp_272',
    'effects' => array(
      25 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '272',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: tp_actions_impact_thumbnail.
  $styles['tp_actions_impact_thumbnail'] = array(
    'name' => 'tp_actions_impact_thumbnail',
    'effects' => array(
      5 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '151',
          'height' => '90',
        ),
        'weight' => '1',
      ),
    ),
    'label' => 'tp_actions_impact_thumbnail',
  );

  // Exported image style: tp_alliances_thumbnail.
  $styles['tp_alliances_thumbnail'] = array(
    'name' => 'tp_alliances_thumbnail',
    'effects' => array(
      12 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '45',
          'height' => '45',
        ),
        'weight' => '1',
      ),
    ),
    'label' => 'tp_alliances_thumbnail',
  );

  // Exported image style: tp_campaign_cover.
  $styles['tp_campaign_cover'] = array(
    'name' => 'tp_campaign_cover',
    'label' => 'tp_campaign_cover',
    'effects' => array(
      3 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '150',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: tp_content_wide.
  $styles['tp_content_wide'] = array(
    'name' => 'tp_content_wide',
    'label' => 'tp_content_wide',
    'effects' => array(
      45 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '640',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: tp_embed_video_thumb.
  $styles['tp_embed_video_thumb'] = array(
    'name' => 'tp_embed_video_thumb',
    'label' => 'tp_embed_video_thumb',
    'effects' => array(
      33 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '480',
          'height' => '360',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: tp_gallery_photo_thumbnail.
  $styles['tp_gallery_photo_thumbnail'] = array(
    'name' => 'tp_gallery_photo_thumbnail',
    'label' => 'tp_gallery_photo_thumbnail',
    'effects' => array(
      27 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '94',
          'height' => '70',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: tp_large_rail_wide.
  $styles['tp_large_rail_wide'] = array(
    'name' => 'tp_large_rail_wide',
    'label' => 'tp_large_rail_wide',
    'effects' => array(
      23 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '272',
          'height' => '204',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: tp_page_wide.
  $styles['tp_page_wide'] = array(
    'name' => 'tp_page_wide',
    'effects' => array(
      8 => array(
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
    'label' => 'tp_page_wide',
  );

  // Exported image style: tp_popular_gallery_thumbnail.
  $styles['tp_popular_gallery_thumbnail'] = array(
    'name' => 'tp_popular_gallery_thumbnail',
    'label' => 'tp_popular_gallery_thumbnail',
    'effects' => array(
      9 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '207',
          'height' => '155',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: tp_promo_feature_thumbnail.
  $styles['tp_promo_feature_thumbnail'] = array(
    'name' => 'tp_promo_feature_thumbnail',
    'label' => 'tp_promo_feature_thumbnail',
    'effects' => array(
      4 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '298',
          'height' => '222',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: tp_quick_study_wide.
  $styles['tp_quick_study_wide'] = array(
    'name' => 'tp_quick_study_wide',
    'effects' => array(
      14 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '218',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
    'label' => 'tp_quick_study_wide',
  );

  // Exported image style: tp_secondary_feature_thumbnail.
  $styles['tp_secondary_feature_thumbnail'] = array(
    'name' => 'tp_secondary_feature_thumbnail',
    'effects' => array(
      13 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '194',
          'height' => '160',
        ),
        'weight' => '1',
      ),
    ),
    'label' => 'tp_secondary_feature_thumbnail',
  );

  // Exported image style: tp_sponsored_by_wide.
  $styles['tp_sponsored_by_wide'] = array(
    'name' => 'tp_sponsored_by_wide',
    'effects' => array(
      10 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '90',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
    'label' => 'tp_sponsored_by_wide',
  );

  // Exported image style: venue_main.
  $styles['venue_main'] = array(
    'name' => 'venue_main',
    'label' => 'venue_main',
    'effects' => array(
      35 => array(
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
          'height' => '380',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}