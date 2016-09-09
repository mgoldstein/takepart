<?php
/**
 * @file
 * tpf_feature_homepage.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tpf_feature_homepage_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panelizer'.
  $permissions['administer panelizer'] = array(
    'name' => 'administer panelizer',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node action defaults'.
  $permissions['administer panelizer node action defaults'] = array(
    'name' => 'administer panelizer node action defaults',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node campaign_card_iframe defaults'.
  $permissions['administer panelizer node campaign_card_iframe defaults'] = array(
    'name' => 'administer panelizer node campaign_card_iframe defaults',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node campaign_card_media defaults'.
  $permissions['administer panelizer node campaign_card_media defaults'] = array(
    'name' => 'administer panelizer node campaign_card_media defaults',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node campaign_card_news defaults'.
  $permissions['administer panelizer node campaign_card_news defaults'] = array(
    'name' => 'administer panelizer node campaign_card_news defaults',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node campaign_card_social defaults'.
  $permissions['administer panelizer node campaign_card_social defaults'] = array(
    'name' => 'administer panelizer node campaign_card_social defaults',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node campaign_page defaults'.
  $permissions['administer panelizer node campaign_page defaults'] = array(
    'name' => 'administer panelizer node campaign_page defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node feature_article defaults'.
  $permissions['administer panelizer node feature_article defaults'] = array(
    'name' => 'administer panelizer node feature_article defaults',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node flashcard defaults'.
  $permissions['administer panelizer node flashcard defaults'] = array(
    'name' => 'administer panelizer node flashcard defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node openpublish_article defaults'.
  $permissions['administer panelizer node openpublish_article defaults'] = array(
    'name' => 'administer panelizer node openpublish_article defaults',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node openpublish_photo_gallery defaults'.
  $permissions['administer panelizer node openpublish_photo_gallery defaults'] = array(
    'name' => 'administer panelizer node openpublish_photo_gallery defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node takepart_page defaults'.
  $permissions['administer panelizer node takepart_page defaults'] = array(
    'name' => 'administer panelizer node takepart_page defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node video defaults'.
  $permissions['administer panelizer node video defaults'] = array(
    'name' => 'administer panelizer node video defaults',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node video_playlist defaults'.
  $permissions['administer panelizer node video_playlist defaults'] = array(
    'name' => 'administer panelizer node video_playlist defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term series defaults'.
  $permissions['administer panelizer taxonomy_term series defaults'] = array(
    'name' => 'administer panelizer taxonomy_term series defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term topic defaults'.
  $permissions['administer panelizer taxonomy_term topic defaults'] = array(
    'name' => 'administer panelizer taxonomy_term topic defaults',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term video_series defaults'.
  $permissions['administer panelizer taxonomy_term video_series defaults'] = array(
    'name' => 'administer panelizer taxonomy_term video_series defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer user user defaults'.
  $permissions['administer panelizer user user defaults'] = array(
    'name' => 'administer panelizer user user defaults',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'bypass access in place editing'.
  $permissions['bypass access in place editing'] = array(
    'name' => 'bypass access in place editing',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'administrator' => 'administrator',
      'layout editor' => 'layout editor',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  return $permissions;
}
