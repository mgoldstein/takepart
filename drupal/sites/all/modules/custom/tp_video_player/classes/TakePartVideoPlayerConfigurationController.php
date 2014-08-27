<?php

class TakePartVideoPlayerConfigurationController {

  public function create($values = array()) {
    return new TakePartVideoPlayerConfiguration($values);
  }

  public function createGlobalDefaults($name = NULL) {
    return $this->create(array(

      /* Allow access by name */
      'name' => $name,

      /* Promo */
      'show_promo_title' => 1,
      'promo_image' => NULL,
      'promo_title' => NULL,

      /* Layout */
      'show_controls' => 1,
      'responsive' => 1,
      'width' => 16,
      'height' => 9,
      'skin' => 'glow',
      'stretching' => 'uniform',

      /* Playback */
      'auto_start' => 0,
      'fallback' => 0,
      'mute_playback' => 0,
      'repeat_playback' => 0,
      'primary_player' => 'html5',

      /* Playlist */
      'playlist_position' => 'none',
      'playlist_size' => 270,
      'playlist_layout' => 'extended',

      /* Sharing */
      'enable_share' => 1,
      'share_heading' => NULL,
      'share_url' => NULL,
      'embed_code' => NULL,

      /* Analytics */
      'enable_jwplayer_analytics' => 1,
      'google_analytics_object' => '_gaq',
      'google_analytics_title' => 'title',
      'site_catalyst_media_name' => NULL,
      'site_catalyst_player_name' => NULL,

      /* Advertising */
      'ad_frequency' => 1,
      'ad_client' => 'googima',
      'ad_tag' => NULL,
      'ad_message' => NULL,
    ));
  }

  public function loadByName($name) {
    $values = db_select('tp_video_player_configuration', 'c')
      ->fields('c')
      ->condition('name', $name, '=')
      ->range(0, 1)
      ->execute()
      ->fetchAssoc();
    if ($values !== FALSE) {
      return new TakePartVideoPlayerConfiguration($values);
    }
    return NULL;
  }

  public function save($configuration) {
    $values = $configuration->values();
    if (isset($values['id'])) {
      $configuration->updated_at = $values['updated_at'] = REQUEST_TIME;
      db_update('tp_video_player_configuration')
        ->fields($values)
        ->condition('id', $values['id'], '=')
        ->execute();
    }
    else {
      $configuration->created_at = $values['created_at'] = REQUEST_TIME;
      $configuration->updated_at = $values['updated_at'] = REQUEST_TIME;
      db_insert('tp_video_player_configuration')
        ->fields($values)
        ->execute();
      $configuration->id = Database::getConnection()->lastInsertId();
    }
  }

  public function merge($configurations) {
    $merged = new TakePartVideoPlayerConfiguration();
    foreach ($configurations as $configuration) {
      $merged->applyOverrides($configuration->values());
    }
    return $merged;
  }
}
