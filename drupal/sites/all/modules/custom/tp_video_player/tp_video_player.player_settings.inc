<?php
/**
 * @file
 * TakePart custom video player JavaScript settings converter.
 */

function tp_video_player_build_settings($configuration, $files) {
  return array_merge(
    tp_video_player_build_content_settings($files),
    tp_video_player_build_promo_settings($configuration),
    tp_video_player_build_layout_settings($configuration),
    tp_video_player_build_playback_settings($configuration),
    tp_video_player_build_sharing_settings($configuration),
    tp_video_player_build_advertising_settings($configuration),
    tp_video_player_build_jwplayer_analytics_settings($configuration),
    tp_video_player_build_google_analytics_settings($configuration),
    tp_video_player_build_site_catalyst_settings($configuration)
  );
}

function tp_video_player_build_content_settings($files) {

  $sources = array();
  $regions = array();

  foreach ($files as $file) {
    $wrapper = file_stream_wrapper_get_instance_by_uri($file['uri']);
    $url = $wrapper->getExternalUrl();
    $sources[] = array(
      'file' => $url,
    );
    $regions[] = $file['allowed_regions'];

    // JWPlatform channels are not supported in playlists. If a channel is
    // found it must be the only source.
    $scheme = file_uri_scheme($file['uri']);
    if ($scheme === 'jwplatform-channel') {
      return array(
        'allowed_regions' => array($file['allowed_regions']),
        'playlist' => $url,
      );
    }
  }

  return array(
    'allowed_regions' => $regions,
    'playlist' => array(
      array(
        'sources' => $sources,
      ),
    ),
  );
}

function tp_video_player_build_promo_settings($configuration) {
  $values = array(
    'displaytitle' => $configuration->show_promo_title != 0,
  );
  if (!empty($configuration->promo_title)) {
    $values['title'] = $configuration->promo_title;
  }
  if (!empty($configuration->promo_image)) {
    $values['image'] = $configuration->promo_image;
  }
  return $values;
}

function tp_video_player_build_layout_settings($configuration) {
  $values = array(
    'controls' => $configuration->show_controls,
    'skin' => $configuration->skin,
    'stretching' => $configuration->stretching,
  );
  if ($configuration->responsive != 0) {
    $values['width'] = '100%';
    $values['aspectratio'] = implode(':', array(
      $configuration->width,
      $configuration->height,
    ));
  }
  else {
    $values['width'] = $configuration->width;
    $values['height'] = $configuration->height;
  }
  return $values;
}

function tp_video_player_build_playback_settings($configuration) {
  return array(
    'autostart' => $configuration->auto_start != 0,
    'fallback' => $configuration->fallback != 0,
    'mute' => $configuration->mute_playback != 0,
    'primary' => $configuration->primary_player,
    'repeat' => $configuration->repeat_playback != 0,
  );
}

function tp_video_player_build_sharing_settings($configuration) {
  $values = array();
  if (!empty($configuration->enable_share)) {
    if (!empty($configuration->share_url)) {
      $values['link'] = $configuration->share_url;
    }
    if (!empty($configuration->share_heading)) {
      $values['heading'] = $configuration->share_heading;
    }
    if (!empty($configuration->embed_code)) {
      $values['code'] = rawurlencode($configuration->embed_code);
    }
  }
  return count($values) > 0 ? array('sharing' => $values) : $values;
}

function tp_video_player_build_advertising_settings($configuration) {
  $values = array();
  if (!empty($configuration->ad_tag)) {
    $values['tag'] = $configuration->ad_tag;
    $values['client'] = $configuration->ad_client;
    if (!empty($configuration->ad_message)) {
      $values['admessage'] = $configuration->ad_message;
    }
  }
  return count($values) > 0 ? array('advertising' => $values) : $values;
}

function tp_video_player_build_jwplayer_analytics_settings($configuration) {
  $values = array('analytics' => array(
    'enabled' => $configuration->enable_jwplayer_analytics == 1,
  ));
  return $values;
}

function tp_video_player_build_google_analytics_settings($configuration) {
  $values = array();
  if (!is_null($configuration->google_analytics_object)) {
    $values['trackingobject'] = $configuration->google_analytics_object;
  }
  if (!is_null($configuration->google_analytics_title)) {
    $values['idstring'] = $configuration->google_analytics_title;
  }
  return count($values) > 0 ? array('ga' => $values) : $values;
}

function tp_video_player_build_site_catalyst_settings($configuration) {
  $values = array();
  if (!is_null($configuration->site_catalyst_media_name)) {
    $values['mediaName'] = $configuration->site_catalyst_media_name;
  }
  if (!is_null($configuration->site_catalyst_player_name)) {
    $values['playerName'] = $configuration->site_catalyst_player_name;
  }
  return count($values) > 0 ? array('sitecatalyst' => $values) : $values;
}
