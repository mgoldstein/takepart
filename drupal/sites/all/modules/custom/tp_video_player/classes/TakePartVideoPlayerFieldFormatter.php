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
    return $elements;
  }

  public function settingsSummary() {
    $summary = array();
    if (!empty($this->_settings['global_default'])) {
      $summary[] = t('Default settings: @name', array(
        '@name' => $this->_settings['global_default']));
    }
    else {
      $summary[] = t('No default settings selected');
    }
    return implode('<br />', $summary);
  }

  public function viewItems($entity_type, $entity, $langcode, $items) {

    $elements = array();

    if (count($items) > 0) {

      // Pick the appropriate field builder.
      if ($this->_field['type'] === 'file') {
        // Direct reference to a Youtube video, JWPlatform video,
        // or JWPlatform playlist.
        $builder = new TakePartVideoPlayerFileFieldBuilder(
          $entity_type, $entity, $langcode, $items);
      }
      elseif ($this->_field['type'] === 'node_reference') {
        // Reference(s) to video or playlist node(s)
        $builder = new TakePartVideoPlayerNodeReferenceFieldBuilder(
          $entity_type, $entity, $langcode, $items);
      }

      $elements[] = $this->viewItem(0,
        $builder->settings($this->_settings['global_default']),
        $builder->allowedRegions());
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
