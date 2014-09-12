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

  public static function globalDefaultNames() {
    return array(
      'full_page' => t('Full Page'),
      'block' => t('Block (Right Rail)'),
      'teaser' => t('Teaser'),
      'iframe' => t('iFrame Embed'),
      'inline_content' => t('Inline Content'),
      'embed' => t('Embedded'),
      'feature_main' => t('Front Page Feature'),
      'feature_main_tpl' => t('Front Page Feature (TPL)'),
      'feature_topic' => t('Topic Page Feature'),
    );
  }

  public static function globalDefaultValues($name = NULL) {
    return array(

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
    );
  }

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
