<?php

class JWPlayerConfiguration {

  protected $_settings;

  public static function valueLabels() {
    return array(
      'promo' => array(
        'image' => t('Image'),
        'title' => t('Title'),
        'displaytitle' => t('Display Title'),
      ),
      'players' => array(
        'flashplayer' => t('Flash Player'),
        'html5player' => t('HTML5 Player'),
      ),
      'layout' => array(
        'controls' => t('Controls'),
        'responsive' => t('Responsive'),
        'aspectratio' => t('Aspect Ratio'),
        'width' => t('Width'),
        'height' => t('Height'),
        'skin' => t('Skin'),
        'stretching' => t('Stretching'),
      ),
      'playback' => array(
        'autostart' => t('Auto Start'),
        'fallback' => t('Fallback'),
        'mute' => t('Mute'),
        'primary' => t('Primary'),
        'repeat' => t('Repeat'),
      ),
      'region_limits' => array(
        'allowed_regions' => t('Allowed Regions'),
      ),
      'listbar' => array(
        'position' => t('Position'),
        'size' => t('Size'),
        'layout' => t('Layout'),
      ),
      'sharing' => array(
        'enabled' => t('Enabled'),
        'link' => t('Link'),
        'embeddable' => t('Embeddable'),
        'code' => t('iFrame Embed Code'),
        'heading' => t('Heading'),
      ),
      'related' => array(
        'file' => t('File'),
        'onclick' => t('On Click'),
        'oncomplete' => t('On Complete'),
        'heading' => t('Heading'),
        'dimensions' => t('Dimensions'),
      ),
      'advertising' => array(
        'client' => t('Client'),
        'tag' => t('Tag'),
        'admessage' => t('Ad Message'),
      ),
      'jwplayer_analytics' => array(
        'enabled' => t('Enabled'),
      ),
      'google_analytics' => array(
        'idstring' => t('ID String'),
        'trackingobject' => t('Tracking Object'),
      ),
      'sitecatalyst' => array(
        'mediaName' => t('Media Name'),
        'playerName' => t('Player Name'),
      ),
    );
  }

  public function __construct($settings) {
    if (is_null($settings)) { $settings = array(); }
    $this->_settings = $settings;
  }

  public static function replaceTokens($type, $entity, $langcode, $settings) {
    foreach ($settings as $key => $item) {
      if (is_array($item)) {
        $settings[$key] = self::replaceTokens($type, $entity, $langcode, $item);
      }
      else {
        $settings[$key] = token_replace($item, array($type => $entity), array(
          'clear' => TRUE,
          'sanitize' => FALSE,
        ));
      }
    }
    return $settings;
  }

  public static function booleanValue($value) {
    return strtolower($value) == 'true' ? TRUE : FALSE;
  }

  public static function intValue($value) {
    return (int) $value;
  }

  public function allowedRegions() {
    $regions = array();
    if (isset($this->_settings['region_limits']['allowed_regions'])) {
      $t = explode(' ', $this->_settings['region_limits']['allowed_regions']);
      $i = array_map('trim', $t);
      $d = array_filter($i, 'strlen');
      $y = array_map('strtolower', $d);
      $regions = $y;
    }
    return $regions;
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
    $values = array();
    $settings = $this->_settings['promo'];
    if (!empty($settings['image'])) {
      $values['image'] = $settings['image'];
    }
    if (!empty($settings['title'])) {
      $values['title'] = $settings['title'];
    }
    if (!empty($settings['displaytitle'])) {
      $values['displaytitle'] = self::booleanValue($settings['displaytitle']);
    }
    return $values;
  }

  protected function playerSettings() {
    $values = array();
    $settings = $this->_settings['players'];
    if (!empty($settings['flashplayer'])) {
      $values['flashplayer'] = $settings['flashplayer'];
    }
    if (!empty($settings['html5player'])) {
      $values['html5player'] = $settings['html5player'];
    }
    return $values;
  }

  protected function layoutSettings() {
    $values = array();
    $settings = $this->_settings['layout'];
    if (!empty($settings['controls'])) {
      $values['controls'] = self::booleanValue($settings['controls']);
    }
    $values['skin'] = 'glow';
    if (!empty($settings['skin'])) {
      $values['skin'] = $settings['skin'];
    }
    if (!empty($settings['stretching'])) {
      $values['stretching'] = $settings['stretching'];
    }
    if (self::booleanValue($settings['responsive'])) {
      $values['width'] = '100%';
      if (!empty($settings['aspectratio'])) {
        $values['aspectratio'] = $settings['aspectratio'];
      }
    }
    else {
      if (!empty($settings['width']) || $settings['width'] == '0') {
        $values['width'] = self::intValue($settings['width']);
      }
      if (!empty($settings['height']) || $settings['height'] == '0') {
        $values['height'] = self::intValue($settings['height']);
      }
    }
    return $values;
  }

  protected function playbackSettings() {
    $values = array();
    $settings = $this->_settings['playback'];
    if (!empty($settings['autostart'])) {
      $values['autostart'] = self::booleanValue($settings['autostart']);
    }
    if (!empty($settings['fallback'])) {
      $values['fallback'] = self::booleanValue($settings['fallback']);
    }
    $values['mute'] = 'false';
    if (!empty($settings['mute'])) {
      $values['mute'] = self::booleanValue($settings['mute']);
    }
    if (!empty($settings['primary'])) {
      $values['primary'] = $settings['primary'];
    }
    if (!empty($settings['repeat'])) {
      $values['repeat'] = self::booleanValue($settings['repeat']);
    }
    return $values;
  }

  protected function listbarSettings($uri) {
    $values = array();
    $scheme = file_uri_scheme($uri);
    if ($scheme === 'jwplatform-channel') {
      $settings = $this->_settings['listbar'];
      if (!empty($settings['position'])) {
        $values['position'] = $settings['position'];
      }
      if (!empty($settings['size']) || $settings['size'] == '0') {
        $values['size'] = self::intValue($settings['size']);
      }
      if (!empty($settings['layout']) && $settings['layout'] == 'basic') {
        $values['layout'] = $settings['layout'];
      }
    }
    return count($values) > 0 ? array('listbar' => $values) : $values;
  }

  protected function sharingSettings() {
    $values = array();
    $settings = $this->_settings['sharing'];
    if (self::booleanValue($settings['enabled'])) {
      if (!empty($settings['link'])) {
        $values['link'] = $settings['link'];
      }
      if (self::booleanValue($settings['embeddable'])) {
        if (!empty($settings['code'])) {
          $values['code'] = rawurlencode($settings['code']);
        }
      }
      if (!empty($settings['heading'])) {
        $values['heading'] = $settings['heading'];
      }
    }
    return count($values) > 0 ? array('sharing' => $values) : $values;
  }

  protected function relatedSettings() {
    $values = array();
    $settings = $this->_settings['related'];
    if (!empty($settings['file'])) {
      $values['file'] = $settings['file'];
    }
    if (!empty($settings['onclick'])) {
      $values['onclick'] = $settings['onclick'];
    }
    if (!empty($settings['oncomplete'])) {
      $values['oncomplete'] = self::booleanValue($settings['oncomplete']);
    }
    if (!empty($settings['heading'])) {
      $values['heading'] = $settings['heading'];
    }
    if (!empty($settings['dimensions'])) {
      $values['dimensions'] = $settings['dimensions'];
    }
    return count($values) > 0 ? array('related' => $values) : $values;
  }

  protected function advertisingSettings() {
    $values = array();
    $settings = $this->_settings['advertising'];
    if (!empty($settings['tag'])) {
      if (!empty($settings['client'])) {
        $values['client'] = $settings['client'];
      }
      if (!empty($settings['tag'])) {
        $values['tag'] = $settings['tag'];
      }
      if (!empty($settings['admessage'])) {
        $values['admessage'] = $settings['admessage'];
      }
    }
    return count($values) > 0 ? array('advertising' => $values) : $values;
  }

  protected function jwplayerAnalyticsSettings() {
    $settings = $this->_settings['jwplayer_analytics'];
    $values = array('analytics' => array(
      'enabled' => self::booleanValue($settings['enabled']),
    ));
    return $values;
  }

  protected function googleAnalyticsSettings() {
    $values = array();
    $settings = $this->_settings['google_analytics'];
    if (!empty($settings['idstring'])) {
      $values['idstring'] = $settings['idstring'];
    }
    if (!empty($settings['trackingobject'])) {
      $values['trackingobject'] = $settings['trackingobject'];
    }
    return count($values) > 0 ? array('ga' => $values) : $values;
  }

  protected function siteCatalystSettings() {
    $values = array();
    $settings = $this->_settings['sitecatalyst'];
    if (!empty($settings['mediaName'])) {
      $values['mediaName'] = $settings['mediaName'];
    }
    if (!empty($settings['playerName'])) {
      $values['playerName'] = $settings['playerName'];
    }
    return count($values) > 0 ? array('sitecatalyst' => $values) : $values;
  }

  public function setupHash($uri) {
    return array_merge(
      $this->contentSettings($uri),
      $this->promoSettings(),
      $this->playerSettings(),
      $this->layoutSettings(),
      $this->playbackSettings(),
      $this->listbarSettings($uri),
      $this->sharingSettings(),
      $this->relatedSettings(),
      $this->advertisingSettings(),
      $this->jwplayerAnalyticsSettings(),
      $this->googleAnalyticsSettings(),
      $this->siteCatalystSettings()
    );
  }
}
