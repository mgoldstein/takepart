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
      'skin' => '[node:field_player_skin]',
      'stretching' => 'uniform',
    ),
    'playback' => array(
      'autostart' => '[node:field_auto_play]',
      'fallback' => 'true',
      'mute' => '[node:field_mute_playback]',
      'primary' => 'html5',
      'repeat' => 'false',
    ),
    'region_limits' => array(
      'allowed_regions' => '[node:field_allowed_regions]',
    ),
    'listbar' => array(
      'position' => '[node:field_playlist_position]',
      'size' => '[node:field_playlist_size]',
      'layout' => '[node:field_playlist_layout]',
    ),
    'sharing' => array(
      'enabled' => '[node:field_sharing_enabled]',
      'link' => '[f:bool:{node:field_share_url}:{node:field_share_url}:{node:url:absolute}]?cmpid=longtailshare',
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
      'client' => '[node:field_ads_client]',
      'tag' => '[node:field_ads_tag]',
      'admessage' => 'Your video will start in XX seconds',
    ),
    'jwplayer_analytics' => array(
      'enabled' => 'true',
    ),
    'google_analytics' => array(
      'idstring' => 'title',
      'trackingobject' => '_gaq',
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
      'skin' => '[node:field_player_skin]',
      'stretching' => 'uniform',
    ),
    'playback' => array(
      'autostart' => '[node:field_auto_play]',
      'fallback' => 'true',
      'mute' => '[node:field_mute_playback]',
      'primary' => 'html5',
      'repeat' => 'false',
    ),
    'region_limits' => array(
      'allowed_regions' => '[node:field_allowed_regions]',
    ),
    'listbar' => array(
      'position' => '[node:field_playlist_position]',
      'size' => '[node:field_playlist_size]',
      'layout' => '[node:field_playlist_layout]',
    ),
    'sharing' => array(
      'enabled' => '[node:field_sharing_enabled]',
      'link' => '[f:bool:{node:field_share_url}:{node:field_share_url}:{node:url:absolute}]?cmpid=longtailshare',
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
      'client' => '[node:field_ads_client]',
      'tag' => '[node:field_ads_tag]',
      'admessage' => 'Your video will start in XX seconds',
    ),
    'jwplayer_analytics' => array(
      'enabled' => 'true',
    ),
    'google_analytics' => array(
      'idstring' => 'title',
      'trackingobject' => '_gaq',
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
      'skin' => '[node:field_player_skin]',
      'stretching' => 'uniform',
    ),
    'playback' => array(
      'autostart' => '[node:field_auto_play]',
      'fallback' => 'true',
      'mute' => '[node:field_mute_playback]',
      'primary' => 'html5',
      'repeat' => 'false',
    ),
    'region_limits' => array(
      'allowed_regions' => '[node:field_allowed_regions]',
    ),
    'listbar' => array(
      'position' => '[node:field_playlist_position]',
      'size' => '[node:field_playlist_size]',
      'layout' => '[node:field_playlist_layout]',
    ),
    'sharing' => array(
      'enabled' => '[node:field_sharing_enabled]',
      'link' => '[f:bool:{node:field_share_url}:{node:field_share_url}:{node:url:absolute}]?cmpid=longtailshare',
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
      'client' => '[node:field_ads_client]',
      'tag' => '[node:field_ads_tag]',
      'admessage' => 'Your video will start in XX seconds',
    ),
    'jwplayer_analytics' => array(
      'enabled' => 'true',
    ),
    'google_analytics' => array(
      'idstring' => 'title',
      'trackingobject' => '_gaq',
    ),
    'sitecatalyst' => array(
      'mediaName' => '[node:title]',
      'playerName' => 'Teaser',
    ),
  );
  $export['teaser'] = $pm_jwplayer_preset;

  return $export;
}
