<?php

drupal_flush_all_caches();
$cmap = features_conflict_resolver_get_cmap();

// Audio-related thingies.
$cmap = features_conflict_resolver_cmap_component_merge($cmap, array(
  'comment_anonymous_audio',
  'comment_audio',
), TRUE);

// Imagery-related thingies.
$cmap = features_conflict_resolver_cmap_component_merge($cmap, array(
  'comment_anonymous_openpublish_photo',
  'comment_anonymous_openpublish_photo_gallery',
  'comment_anonymous_takepart_slide',
), TRUE);

// Wordy-content-related thingies.
$cmap = features_conflict_resolver_cmap_component_merge($cmap, array(
  'comment_action',
  'comment_anonymous_blog_front',
  'comment_anonymous_openpublish_article',
  'comment_anonymous_openpublish_blog_post',
  'comment_anonymous_section_front',
  'comment_anonymous_takepart_campaign',
  'comment_anonymous_takepart_group',
  'comment_anonymous_takepart_list',
  'comment_anonymous_takepart_quick_study',
  'comment_anonymous_takepart_page',
  'comment_anonymous_topic_front',
  'comment_anonymous_webform',
), TRUE);

// field 'node-profile-field_profile_job_title' is in conflict as both
// takepart_omniture and openpublish_author claim it. If we remove it
// from takepart_omniture, then openpublish_author will have no conflicts.
//
// field 'node-openpublish_article-field_tp_campaign_show_title' is in conflict
// as both takepart_ads and takepart_article claim it. It should probably
// be removed from takepart_ads.

print_r($cmap);
