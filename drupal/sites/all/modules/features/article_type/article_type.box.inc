<?php
/**
 * @file
 * article_type.box.inc
 */

/**
 * Implements hook_default_box().
 */
function article_type_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_articles_bottom_right';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Articles Bottom Right';
  $box->options = array(
    'ga_ad_slot' => 'TP3_Articles_RR_BTF_300x600',
    'ga_ad_gpt_id' => 'div-gpt-ad-1348078874566-0',
  );
  $export['ga_articles_bottom_right'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ga_articles_top_right';
  $box->plugin_key = 'ga_ad';
  $box->title = '';
  $box->description = 'GA: Articles Top Right';
  $box->options = array(
    'ga_ad_slot' => 'TP3_Articles_RR_ATF_300x250',
    'ga_ad_gpt_id' => 'div-gpt-ad-1348078720053-0',
  );
  $export['ga_articles_top_right'] = $box;

  return $export;
}
