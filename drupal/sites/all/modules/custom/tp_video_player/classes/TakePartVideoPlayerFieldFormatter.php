<?php

class TakePartVideoPlayerFieldFormatter {

  protected $_field;
  protected $_instance;
  protected $_display;
  protected $_settings;

  public static function info() {
    return array(
      'label' => t('TakePart Video Player'),
      'field types' => array('file', 'node_reference'),
      'settings' => array(
        'global_default' => 'full_page',
        'one_to_one' => FALSE,
      ),
    );
  }

  public function __construct($field, $instance, $display) {
    $this->_field = $field;
    $this->_instance = $instance;
    $this->_display = $display;
    $this->_settings = $display['settings'];
  }

  public function settingsForm($form, &$form_state) {
    $elements = array();

    $elements['global_default'] = array(
      '#type' => 'select',
      '#title' => t('Global Default'),
      '#default_value' => $this->_settings['global_default'],
      '#options' => TakePartVideoPlayerConfiguration::globalDefaultNames(),
    );

    $elements['one_to_one'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use separate player for each video'),
      '#default_value' => $this->_settings['one_to_one'],
    );

    return $elements;
  }

  public function settingsSummary() {
    if (!empty($this->_settings['global_default'])) {
      return t('Default settings: @name', array(
        '@name' => $this->_settings['global_default']));
    }
    return t('No default settings selected');
  }

  private function allowedRegions($node) {

    $regions = array();
    $items = field_get_items('node', $node, 'field_allowed_regions');
    if ($items !== FALSE && count($items) > 0) {
      foreach ($items as $item) {
        $value = str_replace(array(','), ' ', $item['value']);
        $chunks = explode(' ', $value);
        $trimmed = array_map('trim', $chunks);
        $list = array_filter($trimmed, 'strlen');
        $regions += array_map('strtolower', $list);
      }
    }
    return $regions;
  }

  public function viewItems($entity_type, $entity, $langcode, $items) {

    $elements = array();

    $allowed_regions = array();
    $settings_builder = NULL;

    if ($entity_type === 'node') {
      // The field is attached to the video or playlist is
      $node = $entity;
    }
    elseif ($entity_type === 'inline_content') {

    }


    // Select the appropriate settings builder
    if ($entity_type === 'node') {

      $node = $entity;

      if ($node->type === 'video') {

      }
      elseif ($node->type === 'video_playlist') {

      }

      // Get the allowed regions for the video/playlist.
      $allowed_regions = $this->allowedRegions($node);
    }
    elseif ($entity_type === 'inline_content') {

      $allowed_regions =
    }

    if (!is_null($settings_builder)) {

      // Build the player render arrays.
      if ($this->_settings['one_to_one']) {
        foreach ($items as $delta => $item) {
          $settings = $settings_builder->build($item);
          $elements[$delta] = $this->viewItem($delta, $settings, $allowed_regions);
        }
      }
      else {
        $settings = $settings_builder->buildPlaylist($items)
        $elements[] = $this->viewItem(0, $settings, $allowed_regions);
      }
    }

    return $elements;
  }

  public function viewItem($delta, $settings, $allowed_regions) {
    return array(
      '#theme' => 'tp_video_player',
      '#delta' => $delta,
      '#settings' => $settings,
      '#allowed_regions' => $allowed_regions,
      '#id' => drupal_html_id('tp_video_player'),
    );
  }
}
