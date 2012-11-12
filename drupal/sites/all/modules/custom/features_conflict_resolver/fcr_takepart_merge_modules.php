<?php

drupal_flush_all_caches();
$cmap = features_conflict_resolver_get_cmap();

// Media-related thingies.
$cmap = features_conflict_resolver_cmap_module_merge($cmap, array(
  'openpublish_media',
  'takepart_audio',
  'takepart_gallery',
  'takepart_rotator_slide',
  'takepart_video',
), 'media', TRUE);

// Content-related thingies.
$cmap = features_conflict_resolver_cmap_module_merge($cmap, array(
  'openpublish_article',
  'openpublish_section_fronts',
  'takepart_action',
  'takepart_article',
  'takepart_blog',
  'takepart_campaign',
  'takepart_group',
  'takepart_list',
  'takepart_quick_study',
  'takepart_page',
  'takepart_topic_front',
), 'content', TRUE);

print_r($cmap);
