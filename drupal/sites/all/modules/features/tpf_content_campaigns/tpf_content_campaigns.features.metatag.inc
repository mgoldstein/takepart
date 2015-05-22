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
        'value' => '[tp4_support_tokens:campaign:field_article_subhead]',
      ),
      'og:title' => array(
        'value' => '[tp4_support_tokens:campaign:field_promo_headline][f:bool:{node:field_sponsored}: (Promoted):] ',
      ),
      'og:description' => array(
        'value' => '[tp4_support_tokens:campaign:field_article_subhead]',
      ),
      'og:image' => array(
        'value' => '[tp_og_image:thumbnail:{tp4_support_tokens:campaign_thumbnail}]',
      ),
      'twitter:title' => array(
        'value' => '[tp4_support_tokens:campaign:field_promo_headline][f:bool:{node:field_sponsored}: (Promoted):] ',
      ),
      'twitter:description' => array(
        'value' => '[tp4_support_tokens:campaign:field_article_subhead]',
      ),
      'twitter:image:src' => array(
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
