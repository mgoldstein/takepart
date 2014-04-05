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
        'value' => '[node:field_campaign_seo_title] | [site:name]',
      ),
    ),
  );

  return $config;
}
