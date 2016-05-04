<?php
/**
 * @file
 * tpf_responsive_images.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function tpf_responsive_images_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Campaign News Image';
  $picture_mapping->machine_name = 'campaign_news_image';
  $picture_mapping->breakpoint_group = 'large';
  $picture_mapping->mapping = array(
    'breakpoints.theme.base.base_large_desktop' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'campaign_news_3x2',
      ),
    ),
    'breakpoints.theme.base.base_large_tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'campaign_news_3x2',
      ),
    ),
    'breakpoints.theme.base.base_large_mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'campaign_news_3x2_mobile',
      ),
    ),
  );
  $export['campaign_news_image'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Feature Article: Full';
  $picture_mapping->machine_name = 'feature_article_full';
  $picture_mapping->breakpoint_group = 'large';
  $picture_mapping->mapping = array(
    'breakpoints.theme.base.base_large_desktop' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'feature_article_full',
      ),
    ),
    'breakpoints.theme.base.base_large_tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_responsive_tablet',
      ),
    ),
    'breakpoints.theme.base.base_large_mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_responsive_mobile',
      ),
    ),
  );
  $export['feature_article_full'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Feature Article: Hero';
  $picture_mapping->machine_name = 'feature_article_hero';
  $picture_mapping->breakpoint_group = 'large';
  $picture_mapping->mapping = array(
    'breakpoints.theme.base.base_large_desktop' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'feature_article_hero',
      ),
    ),
    'breakpoints.theme.base.base_large_tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_responsive_tablet',
      ),
    ),
    'breakpoints.theme.base.base_large_mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_responsive_mobile',
      ),
    ),
  );
  $export['feature_article_hero'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Feature Article: Landscape';
  $picture_mapping->machine_name = 'feature_article_landscape';
  $picture_mapping->breakpoint_group = 'large';
  $picture_mapping->mapping = array(
    'breakpoints.theme.base.base_large_desktop' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'feature_article_landscape',
      ),
    ),
    'breakpoints.theme.base.base_large_tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_responsive_tablet',
      ),
    ),
    'breakpoints.theme.base.base_large_mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_responsive_mobile',
      ),
    ),
  );
  $export['feature_article_landscape'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Feature Article: Portrait';
  $picture_mapping->machine_name = 'feature_article_portrait';
  $picture_mapping->breakpoint_group = 'large';
  $picture_mapping->mapping = array(
    'breakpoints.theme.base.base_large_desktop' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'feature_article_portrait',
      ),
    ),
    'breakpoints.theme.base.base_large_tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_responsive_tablet',
      ),
    ),
    'breakpoints.theme.base.base_large_mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_responsive_mobile',
      ),
    ),
  );
  $export['feature_article_portrait'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Feature Main Image';
  $picture_mapping->machine_name = 'feature_main_image';
  $picture_mapping->breakpoint_group = 'large';
  $picture_mapping->mapping = array(
    'breakpoints.theme.base.base_large_desktop' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '_original image_',
      ),
    ),
    'breakpoints.theme.base.base_large_tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_responsive_tablet',
      ),
    ),
    'breakpoints.theme.base.base_large_mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_responsive_mobile',
      ),
    ),
  );
  $export['feature_main_image'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Inline Feature Image';
  $picture_mapping->machine_name = 'inline_feature_image';
  $picture_mapping->breakpoint_group = 'large';
  $picture_mapping->mapping = array(
    'breakpoints.theme.base.base_large_desktop' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '_original image_',
      ),
    ),
    'breakpoints.theme.base.base_large_tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_responsive_tablet',
      ),
    ),
    'breakpoints.theme.base.base_large_mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_responsive_mobile',
      ),
    ),
  );
  $export['inline_feature_image'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'large';
  $picture_mapping->machine_name = 'large';
  $picture_mapping->breakpoint_group = 'large';
  $picture_mapping->mapping = array(
    'breakpoints.theme.base.base_large_desktop' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_responsive_desktop',
      ),
    ),
    'breakpoints.theme.base.base_large_tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_responsive_tablet',
      ),
    ),
    'breakpoints.theme.base.base_large_mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'large_responsive_mobile',
      ),
    ),
  );
  $export['large'] = $picture_mapping;

  return $export;
}
