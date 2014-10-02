<?php
/**
 * @file
 * TakePart custom video player JavaScript settings converter.
 */

function tp_video_player_build_settings($configuration, $files) {

  $first = reset($files);

  // Load the media wrapper for the first file.
  $wrapper = file_stream_wrapper_get_instance_by_uri($first['uri']);
  $url = $wrapper->getExternalUrl();

  // JWPlatform channels are not supported in multi-cardinality fields. If a
  // channel is found it must be the only source.
  $scheme = file_uri_scheme($first['uri']);
  if ($scheme === 'jwplatform-channel') {
    $content_settings = array(
      'allowed_regions' => array($first['allowed_regions']),
      'playlist' => $url,
    );
    // Reset the files array so only the channel file is considered in the
    // remaining configuration.
    $files = array($first);
    $listbar_settings = tp_video_player_build_listbar_settings($configuration);
  }
  else {
    $content_settings = tp_video_player_build_content_settings(
      $configuration, $files);
    $listbar_settings = array();
  }

  return array_merge(
    $content_settings,
    tp_video_player_build_promo_settings($configuration),
    tp_video_player_build_layout_settings($configuration),
    tp_video_player_build_playback_settings($configuration),
    $listbar_settings,
    tp_video_player_build_sharing_settings($configuration),
    tp_video_player_build_advertising_settings($configuration, $files),
    tp_video_player_build_jwplayer_analytics_settings($configuration),
    tp_video_player_build_google_analytics_settings($configuration),
    tp_video_player_build_site_catalyst_settings($configuration)
  );
}

function tp_video_player_build_content_settings($configuration, $files) {

  $playlist = array();
  $regions = array();

  foreach ($files as $delta => $file) {

    // Load the media wrapper for the file.
    $wrapper = file_stream_wrapper_get_instance_by_uri($file['uri']);
    $url = $wrapper->getExternalUrl();

    // JWPlatform channels are not supported in playlists, skip them.
    $scheme = file_uri_scheme($file['uri']);
    if ($scheme === 'jwplatform-channel') { continue; }

    $regions[] = $file['allowed_regions'];

    $item = array('sources' => array(array('file' => $url)));

    // Ads should not be added to Youtube videos.
    if ($file['filemime'] !== 'video/youtube') {

      if ($configuration->ad_schedule == TP_VIDEO_PLAYER_VIDEO_SCHEDULE) {
        $tag_url = takepart_ads_tag_url($file['pre_roll_ad_tag'] . '');
        if (!empty($tag_url)) {
          $item['adschedule'] = array(
            "prerollad{$delta}" => array(
              'offset' => 'pre',
              'tag' => $tag_url,
            ),
          );
        }
      }
      elseif($configuration->ad_schedule == TP_VIDEO_PLAYER_PLAYLIST_SCHEDULE) {
        $tag_url = takepart_ads_tag_url($configuration->ad_tag . '');
        if (!empty($tag_url) && ($delta % $configuration->ad_frequency) == 0) {
          $item['adschedule'] = array(
            "prerollad{$delta}" => array(
              'offset' => 'pre',
              'tag' => $tag_url,
            ),
          );
        }
      }
    }

    // Add the file to the playlist.
    $playlist[] = $item;
  }

  return array(
    'allowed_regions' => $regions,
    'playlist' => $playlist,
  );
}

function tp_video_player_build_ad_schedule_settings($configuration, $delta, $file) {
  $settings = array();
  return $settings;
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

function tp_video_player_build_listbar_settings($configuration) {
  $values = array();
  if (!empty($configuration->playlist_position)) {
    $values['position'] = $configuration->playlist_position;
  }
  if (!empty($configuration->playlist_size) ||
    $configuration->playlist_size == '0') {
    $values['size'] = (int) $configuration->playlist_size;
  }
  if (!empty($configuration->playlist_layout)
    && $configuration->playlist_layout == 'basic') {
    $values['layout'] = $configuration->playlist_layout;
  }
  return count($values) > 0 ? array('listbar' => $values) : $values;
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

function tp_video_player_build_advertising_settings($configuration, $files) {
  $values = array();
  $ads_used = FALSE;
  if ($configuration->ad_schedule == TP_VIDEO_PLAYER_VIDEO_SCHEDULE) {
    if (count($files) === 1) {
      // There is only one file, the ad tag can be set in the
      // advertising section of the configuration.
      $file = reset($files);
      $tag_url = takepart_ads_tag_url($file['pre_roll_ad_tag'] . '');
      if (!empty($tag_url) && $file['filemime'] !== 'video/youtube') {
        $ads_used = TRUE;
        $values['tag'] = $tag_url;
      }
    }
    else {
      // Search the files to determine if any have a pre-roll ad, the ad tags
      // will need to be added to the playlist section of the settings.
      foreach ($files as $file) {
        $tag_url = takepart_ads_tag_url($file['pre_roll_ad_tag'] . '');
        if (!empty($tag_url) && $file['filemime'] !== 'video/youtube') {
          $ads_used = TRUE;
          break;
        }
      }
    }
  }
  elseif ($configuration->ad_schedule == TP_VIDEO_PLAYER_PLAYLIST_SCHEDULE) {
    $tag_url = takepart_ads_tag_url($configuration->ad_tag . '');
    if (!empty($tag_url)) {
      // Ads will only be used if at least one of the files is not a Youtube
      // video.
      foreach ($files as $file) {
        if ($file['filemime'] !== 'video/youtube') {
          $ads_used = TRUE;
        }
      }
      // If there is only one file and it is not a Youtube video (ads are being
      // used), then the ad tag can be set in the advertising section of the
      // settings.
      if ($ads_used && count($files) === 1) {
        $values['tag'] = $tag_url;
      }
    }
  }

  // If ads are used, the the client and message should be set.
  if ($ads_used) {
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
