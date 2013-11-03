<?php
/**
 * @file
 * tp_feature_taxonomy_topic.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function tp_feature_taxonomy_topic_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_taxonomy_term_topic';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_taxonomy_term_topic'] = $strongarm;

  return $export;
}
