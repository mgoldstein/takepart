<?php
/**
 * @file
 * takepart_gallery.box.inc
 */

/**
 * Implements hook_default_box().
 */
function takepart_gallery_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-3981ef30';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Ad - Right Rail Top';
  $box->options = array(
    'body' => '<script type=\'text/javascript\'>
GA_googleFillSlot("TP3_Home_RR_ATF_300x250");
</script>',
  );
  $export['box-3981ef30'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-7d1ce087';
  $box->plugin_key = 'view';
  $box->title = 'Popular Galleries';
  $box->description = 'Popular Galleries';
  $box->options = array(
    'view' => 'photo_galleries--block',
    'settings' => array(
      'nid' => '169+66+105',
    ),
    'view_object' => NULL,
    'view_more_text' => '',
    'view_more_link' => '',
    'additional_classes' => '',
  );
  $export['box-7d1ce087'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'box-7fdc48e2';
  $box->plugin_key = 'field';
  $box->title = '';
  $box->description = 'Gallery Header';
  $box->options = array(
    'entity_type' => 'node',
    'entity_id' => '',
    'bundle' => 'openpublish_photo_gallery',
    'field' => array(
      'field_subhead' => 'field_subhead',
      'field_author' => 'field_author',
      'body' => 0,
      'field_gallery_images' => 0,
      'field_gallery_main_image' => 0,
      'field_free_tag' => 0,
      'field_thumbnail' => 0,
      'field_topic' => 0,
      'field_display_tag' => 0,
      'field_promo_headline' => 0,
      'field_promo_text' => 0,
      'field_series' => 0,
      'field_related_content' => 0,
      'field_related_actions' => 0,
      'field_suggest_content' => 0,
      'field_suggest_actions' => 0,
      'field_multi_page_campaign' => 0,
      'field_photo_gallery_slideshow' => 0,
    ),
    'use_page' => 1,
    'exclude_from_content' => 0,
    'view_mode' => 'default',
  );
  $export['box-7fdc48e2'] = $box;

  return $export;
}
