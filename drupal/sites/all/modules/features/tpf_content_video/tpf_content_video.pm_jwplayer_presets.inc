<?php
/**
 * @file
 * tpf_content_video.pm_jwplayer_presets.inc
 */

/**
 * Implements hook_default_pm_jwplayer_presets().
 */
function tpf_content_video_default_pm_jwplayer_presets() {
  $export = array();

  $pm_jwplayer_preset = new stdClass();
  $pm_jwplayer_preset->disabled = FALSE; /* Edit this to true to make a default pm_jwplayer_preset disabled initially */
  $pm_jwplayer_preset->api_version = 1;
  $pm_jwplayer_preset->preset_name = 'Embedded';
  $pm_jwplayer_preset->machine_name = 'embedded';
  $pm_jwplayer_preset->description = 'Embedded content';
  $pm_jwplayer_preset->settings = array(
    'promo' => array(
      'image' => '',
      'title' => '[node:title]',
      'displaytitle' => 'false',
    ),
    'players' => array(
      'flashplayer' => '',
      'html5player' => '',
    ),
    'layout' => array(
      'controls' => 'true',
      'responsive' => 'tur',
      'aspectratio' => '16:9',
      'width' => '',
      'height' => '',
      'skin' => 'glow',
      'stretching' => 'uniform',
    ),
    'playback' => array(
      'autostart' => 'false',
      'fallback' => 'false',
      'mute' => 'false',
      'primary' => 'html5',
      'repeat' => 'false',
    ),
    'region_limits' => array(
      'allowed_regions' => '',
    ),
    'listbar' => array(
      'position' => '',
      'size' => '',
      'layout' => '',
    ),
    'sharing' => array(
      'enabled' => '',
      'link' => '',
      'code' => '',
      'heading' => '',
    ),
    'related' => array(
      'file' => '',
      'onclick' => '',
      'oncomplete' => '',
      'heading' => '',
      'dimensions' => '',
    ),
    'advertising' => array(
      'client' => '',
      'tag' => '',
      'admessage' => '',
    ),
    'jwplayer_analytics' => array(
      'enabled' => 'true',
    ),
    'google_analytics' => array(
      'idstring' => '',
      'trackingobject' => '',
    ),
    'sitecatalyst' => array(
      'mediaName' => '[node:title]',
      'playerName' => 'Full Conent',
    ),
  );
  $export['embedded'] = $pm_jwplayer_preset;

  $pm_jwplayer_preset = new stdClass();
  $pm_jwplayer_preset->disabled = FALSE; /* Edit this to true to make a default pm_jwplayer_preset disabled initially */
  $pm_jwplayer_preset->api_version = 1;
  $pm_jwplayer_preset->preset_name = 'Full Content';
  $pm_jwplayer_preset->machine_name = 'full_content';
  $pm_jwplayer_preset->description = 'Configuration for player on video node pages.';
  $pm_jwplayer_preset->settings = array(
    'promo' => array(
      'image' => '',
      'title' => '[node:title]',
      'displaytitle' => 'false',
    ),
    'players' => array(
      'flashplayer' => '',
      'html5player' => '',
    ),
    'layout' => array(
      'controls' => 'true',
      'responsive' => 'true',
      'aspectratio' => '16:9',
      'width' => '',
      'height' => '',
      'skin' => 'glow',
      'stretching' => 'uniform',
    ),
    'playback' => array(
      'autostart' => 'false',
      'fallback' => 'false',
      'mute' => 'false',
      'primary' => 'html5',
      'repeat' => 'false',
    ),
    'region_limits' => array(
      'allowed_regions' => '',
    ),
    'listbar' => array(
      'position' => '',
      'size' => '',
      'layout' => '',
    ),
    'sharing' => array(
      'enabled' => '',
      'link' => '',
      'code' => '',
      'heading' => '',
    ),
    'related' => array(
      'file' => '',
      'onclick' => '',
      'oncomplete' => '',
      'heading' => '',
      'dimensions' => '',
    ),
    'advertising' => array(
      'client' => '',
      'tag' => '',
      'admessage' => '',
    ),
    'jwplayer_analytics' => array(
      'enabled' => 'true',
    ),
    'google_analytics' => array(
      'idstring' => '',
      'trackingobject' => '',
    ),
    'sitecatalyst' => array(
      'mediaName' => '[node:title]',
      'playerName' => 'Full Conent',
    ),
  );
  $export['full_content'] = $pm_jwplayer_preset;

  $pm_jwplayer_preset = new stdClass();
  $pm_jwplayer_preset->disabled = FALSE; /* Edit this to true to make a default pm_jwplayer_preset disabled initially */
  $pm_jwplayer_preset->api_version = 1;
  $pm_jwplayer_preset->preset_name = 'Teaser';
  $pm_jwplayer_preset->machine_name = 'teaser';
  $pm_jwplayer_preset->description = 'Teaser player configuration';
  $pm_jwplayer_preset->settings = array(
    'promo' => array(
      'image' => '',
      'title' => '[node:title]',
      'displaytitle' => 'false',
    ),
    'players' => array(
      'flashplayer' => '',
      'html5player' => '',
    ),
    'layout' => array(
      'controls' => 'true',
      'responsive' => 'tur',
      'aspectratio' => '16:9',
      'width' => '',
      'height' => '',
      'skin' => 'glow',
      'stretching' => 'uniform',
    ),
    'playback' => array(
      'autostart' => 'false',
      'fallback' => 'false',
      'mute' => 'false',
      'primary' => 'html5',
      'repeat' => 'false',
    ),
    'region_limits' => array(
      'allowed_regions' => '',
    ),
    'listbar' => array(
      'position' => '',
      'size' => '',
      'layout' => '',
    ),
    'sharing' => array(
      'enabled' => '',
      'link' => '',
      'code' => '',
      'heading' => '',
    ),
    'related' => array(
      'file' => '',
      'onclick' => '',
      'oncomplete' => '',
      'heading' => '',
      'dimensions' => '',
    ),
    'advertising' => array(
      'client' => '',
      'tag' => '',
      'admessage' => '',
    ),
    'jwplayer_analytics' => array(
      'enabled' => 'true',
    ),
    'google_analytics' => array(
      'idstring' => '',
      'trackingobject' => '',
    ),
    'sitecatalyst' => array(
      'mediaName' => '[node:title]',
      'playerName' => 'Full Conent',
    ),
  );
  $export['teaser'] = $pm_jwplayer_preset;

  return $export;
}
