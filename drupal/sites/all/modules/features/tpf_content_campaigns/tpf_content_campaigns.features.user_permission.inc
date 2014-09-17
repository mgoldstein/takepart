<?php
/**
 * @file
 * tpf_content_campaigns.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tpf_content_campaigns_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'clone node'.
  $permissions['clone node'] = array(
    'name' => 'clone node',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'clone',
  );

  // Exported permission: 'clone own nodes'.
  $permissions['clone own nodes'] = array(
    'name' => 'clone own nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'clone',
  );

  // Exported permission: 'create campaign content'.
  $permissions['create campaign content'] = array(
    'name' => 'create campaign content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create campaign_card_ad content'.
  $permissions['create campaign_card_ad content'] = array(
    'name' => 'create campaign_card_ad content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create campaign_card_branding content'.
  $permissions['create campaign_card_branding content'] = array(
    'name' => 'create campaign_card_branding content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create campaign_card_empty content'.
  $permissions['create campaign_card_empty content'] = array(
    'name' => 'create campaign_card_empty content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create campaign_card_iframe content'.
  $permissions['create campaign_card_iframe content'] = array(
    'name' => 'create campaign_card_iframe content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create campaign_card_media content'.
  $permissions['create campaign_card_media content'] = array(
    'name' => 'create campaign_card_media content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create campaign_card_multi_column content'.
  $permissions['create campaign_card_multi_column content'] = array(
    'name' => 'create campaign_card_multi_column content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create campaign_card_news content'.
  $permissions['create campaign_card_news content'] = array(
    'name' => 'create campaign_card_news content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create campaign_card_social content'.
  $permissions['create campaign_card_social content'] = array(
    'name' => 'create campaign_card_social content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create campaign_card_tap_widget content'.
  $permissions['create campaign_card_tap_widget content'] = array(
    'name' => 'create campaign_card_tap_widget content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create campaign_card_text content'.
  $permissions['create campaign_card_text content'] = array(
    'name' => 'create campaign_card_text content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create campaign_card_twitter content'.
  $permissions['create campaign_card_twitter content'] = array(
    'name' => 'create campaign_card_twitter content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create campaign_page content'.
  $permissions['create campaign_page content'] = array(
    'name' => 'create campaign_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create campaign_tray content'.
  $permissions['create campaign_tray content'] = array(
    'name' => 'create campaign_tray content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any campaign content'.
  $permissions['delete any campaign content'] = array(
    'name' => 'delete any campaign content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any campaign_card_ad content'.
  $permissions['delete any campaign_card_ad content'] = array(
    'name' => 'delete any campaign_card_ad content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any campaign_card_branding content'.
  $permissions['delete any campaign_card_branding content'] = array(
    'name' => 'delete any campaign_card_branding content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any campaign_card_empty content'.
  $permissions['delete any campaign_card_empty content'] = array(
    'name' => 'delete any campaign_card_empty content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any campaign_card_iframe content'.
  $permissions['delete any campaign_card_iframe content'] = array(
    'name' => 'delete any campaign_card_iframe content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any campaign_card_media content'.
  $permissions['delete any campaign_card_media content'] = array(
    'name' => 'delete any campaign_card_media content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any campaign_card_multi_column content'.
  $permissions['delete any campaign_card_multi_column content'] = array(
    'name' => 'delete any campaign_card_multi_column content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any campaign_card_news content'.
  $permissions['delete any campaign_card_news content'] = array(
    'name' => 'delete any campaign_card_news content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any campaign_card_social content'.
  $permissions['delete any campaign_card_social content'] = array(
    'name' => 'delete any campaign_card_social content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any campaign_card_tap_widget content'.
  $permissions['delete any campaign_card_tap_widget content'] = array(
    'name' => 'delete any campaign_card_tap_widget content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any campaign_card_text content'.
  $permissions['delete any campaign_card_text content'] = array(
    'name' => 'delete any campaign_card_text content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any campaign_card_twitter content'.
  $permissions['delete any campaign_card_twitter content'] = array(
    'name' => 'delete any campaign_card_twitter content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any campaign_page content'.
  $permissions['delete any campaign_page content'] = array(
    'name' => 'delete any campaign_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any campaign_tray content'.
  $permissions['delete any campaign_tray content'] = array(
    'name' => 'delete any campaign_tray content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own campaign content'.
  $permissions['delete own campaign content'] = array(
    'name' => 'delete own campaign content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own campaign_card_ad content'.
  $permissions['delete own campaign_card_ad content'] = array(
    'name' => 'delete own campaign_card_ad content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own campaign_card_branding content'.
  $permissions['delete own campaign_card_branding content'] = array(
    'name' => 'delete own campaign_card_branding content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own campaign_card_empty content'.
  $permissions['delete own campaign_card_empty content'] = array(
    'name' => 'delete own campaign_card_empty content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own campaign_card_iframe content'.
  $permissions['delete own campaign_card_iframe content'] = array(
    'name' => 'delete own campaign_card_iframe content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own campaign_card_media content'.
  $permissions['delete own campaign_card_media content'] = array(
    'name' => 'delete own campaign_card_media content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own campaign_card_multi_column content'.
  $permissions['delete own campaign_card_multi_column content'] = array(
    'name' => 'delete own campaign_card_multi_column content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own campaign_card_news content'.
  $permissions['delete own campaign_card_news content'] = array(
    'name' => 'delete own campaign_card_news content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own campaign_card_social content'.
  $permissions['delete own campaign_card_social content'] = array(
    'name' => 'delete own campaign_card_social content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own campaign_card_tap_widget content'.
  $permissions['delete own campaign_card_tap_widget content'] = array(
    'name' => 'delete own campaign_card_tap_widget content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own campaign_card_text content'.
  $permissions['delete own campaign_card_text content'] = array(
    'name' => 'delete own campaign_card_text content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own campaign_card_twitter content'.
  $permissions['delete own campaign_card_twitter content'] = array(
    'name' => 'delete own campaign_card_twitter content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own campaign_page content'.
  $permissions['delete own campaign_page content'] = array(
    'name' => 'delete own campaign_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own campaign_tray content'.
  $permissions['delete own campaign_tray content'] = array(
    'name' => 'delete own campaign_tray content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any campaign content'.
  $permissions['edit any campaign content'] = array(
    'name' => 'edit any campaign content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any campaign_card_ad content'.
  $permissions['edit any campaign_card_ad content'] = array(
    'name' => 'edit any campaign_card_ad content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any campaign_card_branding content'.
  $permissions['edit any campaign_card_branding content'] = array(
    'name' => 'edit any campaign_card_branding content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any campaign_card_empty content'.
  $permissions['edit any campaign_card_empty content'] = array(
    'name' => 'edit any campaign_card_empty content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any campaign_card_iframe content'.
  $permissions['edit any campaign_card_iframe content'] = array(
    'name' => 'edit any campaign_card_iframe content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any campaign_card_media content'.
  $permissions['edit any campaign_card_media content'] = array(
    'name' => 'edit any campaign_card_media content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any campaign_card_multi_column content'.
  $permissions['edit any campaign_card_multi_column content'] = array(
    'name' => 'edit any campaign_card_multi_column content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any campaign_card_news content'.
  $permissions['edit any campaign_card_news content'] = array(
    'name' => 'edit any campaign_card_news content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any campaign_card_social content'.
  $permissions['edit any campaign_card_social content'] = array(
    'name' => 'edit any campaign_card_social content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any campaign_card_tap_widget content'.
  $permissions['edit any campaign_card_tap_widget content'] = array(
    'name' => 'edit any campaign_card_tap_widget content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any campaign_card_text content'.
  $permissions['edit any campaign_card_text content'] = array(
    'name' => 'edit any campaign_card_text content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any campaign_card_twitter content'.
  $permissions['edit any campaign_card_twitter content'] = array(
    'name' => 'edit any campaign_card_twitter content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any campaign_page content'.
  $permissions['edit any campaign_page content'] = array(
    'name' => 'edit any campaign_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any campaign_tray content'.
  $permissions['edit any campaign_tray content'] = array(
    'name' => 'edit any campaign_tray content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own campaign content'.
  $permissions['edit own campaign content'] = array(
    'name' => 'edit own campaign content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own campaign_card_ad content'.
  $permissions['edit own campaign_card_ad content'] = array(
    'name' => 'edit own campaign_card_ad content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own campaign_card_branding content'.
  $permissions['edit own campaign_card_branding content'] = array(
    'name' => 'edit own campaign_card_branding content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own campaign_card_empty content'.
  $permissions['edit own campaign_card_empty content'] = array(
    'name' => 'edit own campaign_card_empty content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own campaign_card_iframe content'.
  $permissions['edit own campaign_card_iframe content'] = array(
    'name' => 'edit own campaign_card_iframe content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own campaign_card_media content'.
  $permissions['edit own campaign_card_media content'] = array(
    'name' => 'edit own campaign_card_media content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own campaign_card_multi_column content'.
  $permissions['edit own campaign_card_multi_column content'] = array(
    'name' => 'edit own campaign_card_multi_column content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own campaign_card_news content'.
  $permissions['edit own campaign_card_news content'] = array(
    'name' => 'edit own campaign_card_news content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own campaign_card_social content'.
  $permissions['edit own campaign_card_social content'] = array(
    'name' => 'edit own campaign_card_social content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own campaign_card_tap_widget content'.
  $permissions['edit own campaign_card_tap_widget content'] = array(
    'name' => 'edit own campaign_card_tap_widget content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own campaign_card_text content'.
  $permissions['edit own campaign_card_text content'] = array(
    'name' => 'edit own campaign_card_text content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own campaign_card_twitter content'.
  $permissions['edit own campaign_card_twitter content'] = array(
    'name' => 'edit own campaign_card_twitter content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own campaign_page content'.
  $permissions['edit own campaign_page content'] = array(
    'name' => 'edit own campaign_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own campaign_tray content'.
  $permissions['edit own campaign_tray content'] = array(
    'name' => 'edit own campaign_tray content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'use text format campaign_full_html'.
  $permissions['use text format campaign_full_html'] = array(
    'name' => 'use text format campaign_full_html',
    'roles' => array(
      'administrator' => 'administrator',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'layout editor' => 'layout editor',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
