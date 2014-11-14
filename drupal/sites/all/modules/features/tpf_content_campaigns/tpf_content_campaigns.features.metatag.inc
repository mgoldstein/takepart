<?php
/**
 * @file
 * tpf_content_campaigns.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function tpf_content_campaigns_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:campaign_page.
  $config['node:campaign_page'] = array(
    'instance' => 'node:campaign_page',
    'config' => array(
      'title' => array(
        'value' => '[node:seo-title] | [site:name]',
      ),
      'description' => array(
        'value' => '[node:field_article_subhead]',
      ),
      'og:image' => array(
        'value' => '[tp_og_image:thumbnail:{tp4_support_tokens:campaign_thumbnail}]',
      ),
      'tp:node_id' => array(
        'value' => '[node:nid]',
      ),
      'tp:content_title' => array(
        'value' => '[node:title]',
      ),
      'tp:content_type' => array(
        'value' => 'campaign',
      ),
      'tp:content_authors' => array(
        'value' => '[tp_omniture:get_author:{node:nid}]',
      ),
      'tp:published_date' => array(
        'value' => '[node:published:custom:Y/m/d]',
      ),
      'tp:campaign' => array(
        'value' => '[node:campaign-name]',
      ),
      'tp:series' => array(
        'value' => '[node:campaign-series]',
      ),
      'tp:topic' => array(
        'value' => '[node:campaign-topic]',
      ),
    ),
  );

  return $config;
}
