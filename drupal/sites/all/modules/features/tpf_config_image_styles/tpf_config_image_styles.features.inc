<?php
/**
 * @file
 * tpf_config_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function tpf_config_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: 70x70_thumbnail.
  $styles['70x70_thumbnail'] = array(
    'label' => '70x70_thumbnail',
    'effects' => array(
      13 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 70,
          'height' => 70,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: action_header_image.
  $styles['action_header_image'] = array(
    'label' => 'action_header_image',
    'effects' => array(
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 640,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: action_main_image.
  $styles['action_main_image'] = array(
    'label' => 'action_main_image',
    'effects' => array(
      47 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 330,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: action_medium_preview.
  $styles['action_medium_preview'] = array(
    'label' => 'action_medium_preview',
    'effects' => array(
      51 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 270,
          'height' => 156,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: action_summary_group.
  $styles['action_summary_group'] = array(
    'label' => 'action_summary_group',
    'effects' => array(
      37 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 172,
          'height' => 172,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: campaign_news_3x2.
  $styles['campaign_news_3x2'] = array(
    'label' => 'campaign_news_3x2',
    'effects' => array(
      57 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 900,
          'height' => 600,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: embed_gallery_thumb.
  $styles['embed_gallery_thumb'] = array(
    'label' => 'embed_gallery_thumb',
    'effects' => array(
      15 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 107,
          'height' => 76,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: feature_article_full.
  $styles['feature_article_full'] = array(
    'label' => 'Feature Article: Full',
    'effects' => array(
      66 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 912,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: feature_article_hero.
  $styles['feature_article_hero'] = array(
    'label' => 'Feature Article: Hero',
    'effects' => array(
      67 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 980,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: feature_article_landscape.
  $styles['feature_article_landscape'] = array(
    'label' => 'Feature Article: Landscape',
    'effects' => array(
      68 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 480,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: feature_article_portrait.
  $styles['feature_article_portrait'] = array(
    'label' => 'Feature Article: Portrait',
    'effects' => array(
      69 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 400,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: inline_thumbnail.
  $styles['inline_thumbnail'] = array(
    'label' => 'inline_thumbnail',
    'effects' => array(
      60 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 320,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: landscape_main_image.
  $styles['landscape_main_image'] = array(
    'label' => 'landscape_main_image',
    'effects' => array(
      58 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 583,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: portrait_main_image.
  $styles['portrait_main_image'] = array(
    'label' => 'portrait_main_image',
    'effects' => array(
      59 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 400,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: right-sidebar-thumbnails.
  $styles['right-sidebar-thumbnails'] = array(
    'label' => 'right-sidebar-thumbnails',
    'effects' => array(
      39 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 80,
          'height' => 80,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rss_images.
  $styles['rss_images'] = array(
    'label' => 'rss_images',
    'effects' => array(
      29 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 480,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: square_thumbnail.
  $styles['square_thumbnail'] = array(
    'label' => 'square_thumbnail',
    'effects' => array(
      11 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 140,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: takepart_rotator_slide.
  $styles['takepart_rotator_slide'] = array(
    'label' => 'takepart_rotator_slide',
    'effects' => array(
      31 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 370,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: thumbnail_v2.
  $styles['thumbnail_v2'] = array(
    'label' => 'Thumbnail V2',
    'effects' => array(
      57 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: topic_feature.
  $styles['topic_feature'] = array(
    'label' => 'Topic Feature',
    'effects' => array(
      70 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 477,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: topic_thumbnail.
  $styles['topic_thumbnail'] = array(
    'label' => 'Topic Thumbnail',
    'effects' => array(
      71 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 96,
          'height' => 64,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: tp_100_wide.
  $styles['tp_100_wide'] = array(
    'label' => 'tp_100_wide',
    'effects' => array(
      60 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 100,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: tp_250_wide.
  $styles['tp_250_wide'] = array(
    'label' => 'tp_250_wide',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: tp_272.
  $styles['tp_272'] = array(
    'label' => 'tp_272',
    'effects' => array(
      25 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 272,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: tp_actions_impact_thumbnail.
  $styles['tp_actions_impact_thumbnail'] = array(
    'label' => 'tp_actions_impact_thumbnail',
    'effects' => array(
      60 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 151,
          'height' => 90,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: tp_alliances_thumbnail.
  $styles['tp_alliances_thumbnail'] = array(
    'label' => 'tp_alliances_thumbnail',
    'effects' => array(
      61 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 45,
          'height' => 45,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: tp_campaign_cover.
  $styles['tp_campaign_cover'] = array(
    'label' => 'tp_campaign_cover',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 150,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: tp_content_wide.
  $styles['tp_content_wide'] = array(
    'label' => 'tp_content_wide',
    'effects' => array(
      45 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 640,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: tp_embed_video_thumb.
  $styles['tp_embed_video_thumb'] = array(
    'label' => 'tp_embed_video_thumb',
    'effects' => array(
      33 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 360,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: tp_gallery_photo_thumbnail.
  $styles['tp_gallery_photo_thumbnail'] = array(
    'label' => 'tp_gallery_photo_thumbnail',
    'effects' => array(
      27 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 94,
          'height' => 70,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: tp_large_rail_wide.
  $styles['tp_large_rail_wide'] = array(
    'label' => 'tp_large_rail_wide',
    'effects' => array(
      23 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 272,
          'height' => 204,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: tp_page_wide.
  $styles['tp_page_wide'] = array(
    'label' => 'tp_page_wide',
    'effects' => array(
      62 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 980,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: tp_popular_gallery_thumbnail.
  $styles['tp_popular_gallery_thumbnail'] = array(
    'label' => 'tp_popular_gallery_thumbnail',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 207,
          'height' => 155,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: tp_promo_feature_thumbnail.
  $styles['tp_promo_feature_thumbnail'] = array(
    'label' => 'tp_promo_feature_thumbnail',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 298,
          'height' => 222,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: tp_quick_study_wide.
  $styles['tp_quick_study_wide'] = array(
    'label' => 'tp_quick_study_wide',
    'effects' => array(
      63 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 218,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: tp_secondary_feature_thumbnail.
  $styles['tp_secondary_feature_thumbnail'] = array(
    'label' => 'tp_secondary_feature_thumbnail',
    'effects' => array(
      64 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 194,
          'height' => 160,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: tp_sponsored_by_wide.
  $styles['tp_sponsored_by_wide'] = array(
    'label' => 'tp_sponsored_by_wide',
    'effects' => array(
      65 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 90,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: venue_main.
  $styles['venue_main'] = array(
    'label' => 'venue_main',
    'effects' => array(
      35 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 380,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: video_navigation_thumb_155x87.
  $styles['video_navigation_thumb_155x87'] = array(
    'label' => 'Video Navigation Thumb 155x87',
    'effects' => array(
      60 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 208,
          'height' => 117,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
