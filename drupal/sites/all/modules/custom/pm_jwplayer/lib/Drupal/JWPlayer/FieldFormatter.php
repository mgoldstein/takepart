<?php

class JWPlayerFieldFormatter {

  protected $_field;
  protected $_instance;
  protected $_display;
  protected $_settings;

  protected $_preset;

  public static function info() {
    return array(
      'label' => t('Custom JW Player'),
      'field types' => array('file'),
      'settings' => array(
        'pm_jwplayer_preset' => '',
      ),
    );
  }

  public function __construct($field, $instance, $display) {
    $this->_field = $field;
    $this->_instance = $instance;
    $this->_display = $display;
    $this->_settings = $display['settings'];
    $this->_preset = $this->loadPreset($this->_settings['pm_jwplayer_preset']);
  }

  protected function loadPreset($machine_name) {
    $presets = pm_jwplayer_preset_load();
    if (isset($presets[$machine_name])) {
      return $presets[$machine_name];
    }
    return FALSE;
  }

  public static function presetOptions() {
    $options = array();
    $presets = pm_jwplayer_preset_load();
    foreach ($presets as $machine_name => $preset) {
      $options[$machine_name] = $preset->preset_name;
    }
    return $options;
  }

  public function settingsForm($form, &$form_state) {
    $element = array();
    $options = self::presetOptions();
    if (!empty($options)) {
      $element['pm_jwplayer_preset'] = array(
        '#type' => 'select',
        '#title' => t('Preset'),
        '#default_value' => $this->_settings['pm_jwplayer_preset'],
        '#options' => $options,
      );
    }
    else {
      $create_url = url('admin/config/media/pm_jwplayer/add');
      $format = 'No presets are available.'
        . ' You must <a href="@create">create a preset</a> to proceed.';
      $message = t($format, array('@create' => $create_url));
      $element['no_preset_message'] = array(
        '#markup' => '<div>' . $message . '</div>',
      );
    }
    return $element;
  }

  public function settingsSummary() {
    $summary = array();
    if ($this->_preset !== FALSE) {
      $summary[] = t('Preset: @name', array(
        '@name' => $this->_preset->preset_name
      ));
      $summary[] = t('Description: @description', array(
        '@description' => $this->_preset->description
      ));
    }
    else {
      $summary[] = t('No preset selected');
    }
    return implode('<br />', $summary);
  }

  public function viewItems($entity_type, $entity, $langcode, $items) {
    $elements = array();
    if ($this->_preset !== FALSE) {
      foreach ($items as $delta => $item) {
        drupal_set_message(print_r($entity_type, TRUE));
        drupal_set_message(print_r($entity, TRUE));
        $settings = JWPlayerConfiguration::replaceTokens($entity_type, $entity,
          $langcode, $this->_preset->settings);
        $configuration = new JWPlayerConfiguration($settings);
        $elements[$delta] = $this->viewItem($item, $delta, $configuration);
      }
    }
    return $elements;
  }

  public function viewItem($item, $delta, $configuration) {
    return array(
      '#theme' => 'pm_jwplayer',
      '#item' => $item,
      '#configuration' => $configuration->setupHash($item['uri']),
      '#allowed_regions' => $configuration->allowedRegions(),
      '#player_id' => drupal_html_id('pm_jwplayer'),
    );
  }
}
