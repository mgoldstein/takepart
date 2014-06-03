<?php
/**
 * @file
 * Drush commands for JWPlatform module
 */

/**
 * Implements hook_drush_command().
 */
function pm_jwplatform_drush_command() {
  return array(
    'jwplatform-video-import' => array(
      'description' => dt('Import tagged videos from JWPlatform/BotR.'),
      'arguments' => array(),
      'examples' => array(
        'Standard example' => 'drush jwplatform-video-import',
      ),
      'aliases' => array(
        'jwpvi',
      ),
    ),
  );
}

/**
 * Drush import videos from JWPlatform/BotR.
 */
function drush_pm_jwplatform_jwplatform_video_import() {
  pm_jwplatform_import_videos();
}
