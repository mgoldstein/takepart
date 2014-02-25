<?php
/**
 * @file
 * tpf_content_campaigns.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tpf_content_campaigns_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tpf_content_campaigns_node_info() {
  $items = array(
    'campaign' => array(
      'name' => t('campaign'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'campaign_card_iframe' => array(
      'name' => t('Campaign Card Iframe'),
      'base' => 'node_content',
      'description' => t('Iframes that are hosted by 3rd parties.'),
      'has_title' => '1',
      'title_label' => t('Admin Card Title'),
      'help' => '',
    ),
    'campaign_card_media' => array(
      'name' => t('Campaign Card Media'),
      'base' => 'node_content',
      'description' => t('Card that hold media content (image and videos).'),
      'has_title' => '1',
      'title_label' => t('Admin Card Title'),
      'help' => '',
    ),
    'campaign_card_news' => array(
      'name' => t('Campaign Card News'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Admin Card Title'),
      'help' => '',
    ),
    'campaign_card_social' => array(
      'name' => t('Campaign Card Social'),
      'base' => 'node_content',
      'description' => t('Social Follow Card for the Campaign pages.'),
      'has_title' => '1',
      'title_label' => t('Admin Card Title'),
      'help' => '',
    ),
    'campaign_page' => array(
      'name' => t('Campaign Page'),
      'base' => 'node_content',
      'description' => t('A campaign page that can hold one or multiple \'trays\'.  Each Campaign page references the campaign that it belongs to.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'campaign_tray' => array(
      'name' => t('Campaign Tray'),
      'base' => 'node_content',
      'description' => t('A tray can hold one or many cards of various types.  A tray of many cards appears as a gallery whereas a tray of one card appears as a single card.  Trays hold information such as static backgrounds and titles, permalinks and more.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
