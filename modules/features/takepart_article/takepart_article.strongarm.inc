<?php
/**
 * @file
 * takepart_article.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function takepart_article_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_openpublish_article_pattern';
  $strongarm->value = 'article/[node:created:custom:Y]/[node:created:custom:m]/[node:created:custom:d]/[node:title]';
  $export['pathauto_node_openpublish_article_pattern'] = $strongarm;

  return $export;
}
