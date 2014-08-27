<?php

class TakePartVideoPlayerConfiguration {

  public $id = NULL;
  public $name = NULL;

  /* Promo */
  public $show_promo_title = NULL;
  public $promo_image = NULL;
  public $promo_title = NULL;

  /* Layout */
  public $show_controls = NULL;
  public $responsive = NULL;
  public $width = NULL;
  public $height = NULL;
  public $skin = NULL;
  public $stretching = NULL;

  /* Playback */
  public $auto_start = NULL;
  public $fallback = NULL;
  public $mute_playback = NULL;
  public $repeat_playback = NULL;
  public $primary_player = NULL;

  /* Playlist */
  public $playlist_position = NULL;
  public $playlist_size = NULL;
  public $playlist_layout = NULL;

  /* Sharing */
  public $enable_share = NULL;
  public $share_heading = NULL;
  public $share_url = NULL;
  public $embed_code = NULL;

  /* Analytics */
  public $enable_jwplayer_analytics = NULL;
  public $google_analytics_object = NULL;
  public $google_analytics_title = NULL;
  public $site_catalyst_media_name = NULL;
  public $site_catalyst_player_name = NULL;

  /* Advertising */
  public $ad_frequency = NULL;
  public $ad_client = NULL;
  public $ad_tag = NULL;
  public $ad_message = NULL;

  public function __construct($values) {
    $this->applyOverrides($values);
    $this->id = $values['id'];
  }

  public function applyOverrides($values) {
    // Update all attributes for which a non-null value is provided.
    foreach ($values as $name => $value) {
      // Also skip the id attribute to preserve this configuration's identity.
      if ($name !== 'id' && !is_null($value)) {
        $this->{$name} = $value;
      }
    }
  }

  public function values() {
    // Convert the object to an array.
    $values = (array) $this;
    // Remove the id element if it does not have a real value.
    if (is_null($this->id)) { unset($values['id']); }
    return $values;
  }
}
