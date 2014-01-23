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
      'allowed_regions' => '[node:field-allowed-regions]',
    ),
    'listbar' => array(
      'position' => '[node:field-playlist-position]',
      'size' => '[node:field-playlist-size]',
      'layout' => '[node:field-playlist-layout]',
    ),
    'sharing' => array(
      'enabled' => '[node:field-sharing-enabled]',
      'link' => '[node:url:absolute]',
      'code' => '',
      'heading' => 'Share This Video',
    ),
    'related' => array(
      'file' => '',
      'onclick' => '',
      'oncomplete' => '',
      'heading' => '',
      'dimensions' => '',
    ),
    'advertising' => array(
      'client' => '[node:field-ads-client]',
      'tag' => '[node:field-ads-tag]',
      'admessage' => 'Your video will start in XX seconds',
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
      'playerName' => 'Embedded',
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
      'allowed_regions' => '[node:field-allowed-regions]',
    ),
    'listbar' => array(
      'position' => '[node:field-playlist-position]',
      'size' => '[node:field-playlist-size]',
      'layout' => '[node:field-playlist-layout]',
    ),
    'sharing' => array(
      'enabled' => '[node:field-sharing-enabled]',
      'link' => '[node:url:absolute]',
      'code' => '',
      'heading' => 'Share This Video',
    ),
    'related' => array(
      'file' => '',
      'onclick' => '',
      'oncomplete' => '',
      'heading' => '',
      'dimensions' => '',
    ),
    'advertising' => array(
      'client' => '[node:field-ads-client]',
      'tag' => '[node:field-ads-tag]',
      'admessage' => 'Your video will start in XX seconds',
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
      'allowed_regions' => '[node:field-allowed-regions]',
    ),
    'listbar' => array(
      'position' => '[node:field-playlist-position]',
      'size' => '[node:field-playlist-size]',
      'layout' => '[node:field-playlist-layout]',
    ),
    'sharing' => array(
      'enabled' => '[node:field-sharing-enabled]',
      'link' => '[node:url:absolute]',
      'code' => '',
      'heading' => 'Share This Video',
    ),
    'related' => array(
      'file' => '',
      'onclick' => '',
      'oncomplete' => '',
      'heading' => '',
      'dimensions' => '',
    ),
    'advertising' => array(
      'client' => '[node:field-ads-client]',
      'tag' => '[node:field-ads-tag]',
      'admessage' => 'Your video will start in XX seconds',
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
      'playerName' => 'Teaser',
    ),
  );
  $export['teaser'] = $pm_jwplayer_preset;

  return $export;
}
