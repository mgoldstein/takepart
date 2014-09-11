<?php

class TakePartVideoPlayerSettingsBuilder {

  private $configuration;

  public function __construct($configuration) {
    $this->configuration = $configuration;
  }

  protected function contentSettings($uri) {
    $scheme = file_uri_scheme($uri);
    $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
    $url = $wrapper->getExternalUrl();
    if ($scheme === 'jwplatform-channel' || $scheme === 'jwplatform-video') {
      return array('playlist' => $url);
    }
    return array('file' => $url);
  }

  protected function promoSettings() {
    $values = array(
      'displaytitle' => $this->configuration->show_promo_title != 0,
    );
    if (!empty($this->configuration->promo_title)) {
      $values['title'] = $this->configuration->promo_title;
    }
    if (!empty($this->configuration->promo_image)) {
      $values['image'] = $this->configuration->promo_image;
    }
    return $values;
  }

  protected function layoutSettings() {
    $values = array(
      'controls' => $this->configuration->show_controls,
      'skin' => $this->configuration->skin,
      'stretching' => $this->configuration->stretching,
    );
    if ($this->configuration->responsive != 0) {
      $values['width'] = '100%';
      $values['aspectratio'] = implode(':', array(
        $this->configuration->width,
        $this->configuration->height,
      ));
    }
    else {
      $values['width'] = $this->configuration->width;
      $values['height'] = $this->configuration->height;
    }
    return $values;
  }

  protected function playbackSettings() {
    return array(
      'autostart' => $this->configuration->auto_start != 0,
      'fallback' => $this->configuration->fallback != 0,
      'mute' => $this->configuration->mute_playback != 0,
      'primary' => $this->configuration->primary_player,
      'repeat' => $this->configuration->repeat_playback != 0,
    );
  }

  protected function listbarSettings($show_listbar) {
    $values = array();
    if ($show_listbar) {
      $values['position'] = $this->configuration->playlist_position;
      $values['size'] = $this->configuration->playlist_size;
      $values['layout'] = $this->configuration->playlist_layout;
    }
    return count($values) > 0 ? array('listbar' => $values) : $values;
  }

  protected function sharingSettings() {
    $values = array();
    if (!empty($this->configuration->enable_share)) {
      if (!empty($this->configuration->share_url)) {
        $values['link'] = $this->configuration->share_url;
      }
      if (!empty($this->configuration->share_heading)) {
        $values['heading'] = $this->configuration->share_heading;
      }
      if (!empty($this->configuration->embed_code)) {
        $values['code'] = rawurlencode($this->configuration->embed_code);
      }
    }
    return count($values) > 0 ? array('sharing' => $values) : $values;
  }

  protected function advertisingSettings() {
    $values = array();
    if (!empty($this->configuration->ad_tag)) {
      $values['tag'] = $this->configuration->ad_tag;
      $values['client'] = $this->configuration->ad_client;
      if (!empty($this->configuration->ad_message)) {
        $values['admessage'] = $this->configuration->ad_message;
      }
    }
    return count($values) > 0 ? array('advertising' => $values) : $values;
  }

  protected function jwplayerAnalyticsSettings() {
    $settings = $this->_settings['jwplayer_analytics'];
    $values = array('analytics' => array(
      'enabled' => $this->configuration->enable_jwplayer_analytics == 1,
    ));
    return $values;
  }

  protected function googleAnalyticsSettings() {
    $values = array();
    if (!is_null($this->configuration->google_analytics_object)) {
      $values['trackingobject'] = $this->configuration->google_analytics_object;
    }
    if (!is_null($this->configuration->google_analytics_title)) {
      $values['idstring'] = $this->configuration->google_analytics_title;
    }
    return count($values) > 0 ? array('ga' => $values) : $values;
  }

  protected function siteCatalystSettings() {
    $values = array();
    if (!is_null($this->configuration->site_catalyst_media_name)) {
      $values['mediaName'] = $this->configuration->site_catalyst_media_name;
    }
    if (!is_null($this->configuration->site_catalyst_player_name)) {
      $values['playerName'] = $this->configuration->site_catalyst_player_name;
    }
    return count($values) > 0 ? array('sitecatalyst' => $values) : $values;
  }

  public function build($video) {
    $scheme = file_uri_scheme($video['uri']);
    return array_merge(
      $this->contentSettings($video['uri']),
      $this->promoSettings(),
      $this->layoutSettings(),
      $this->playbackSettings(),
      $this->sharingSettings(),
      $this->advertisingSettings(),
      $this->jwplayerAnalyticsSettings(),
      $this->googleAnalyticsSettings(),
      $this->siteCatalystSettings()
    );
  }
}
