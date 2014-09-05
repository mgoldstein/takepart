<?php

class TakePartVideoPlayerFileFieldFormatter {

  protected $_field;
  protected $_instance;
  protected $_display;
  protected $_settings;

  public static function info() {
    return array(
      'label' => t('TakePart Video Player (File Field)'),
      'field types' => array('file'),
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
    $element = array();
    $element['global_default'] = array(
      '#type' => 'select',
      '#title' => t('Global Default'),
      '#default_value' => $this->_settings['global_default'],
      '#options' => TakePartVideoPlayerConfiguration::globalDefaultNames(),
    );
    return $element;
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

    if ($entity_type === 'node') {

      $controller = new TakePartVideoPlayerNodeOverrideController();

      // Get the allowed regions for the video/playlist.
      // TODO: Move the allowed regions field to the media entity.
      $allowed_regions = $this->allowedRegions($entity);

      // Load the global defaults for the entity view mode.
      $configuration = $controller->loadByName($this->_settings['global_default']);

      // Get the configuration overrides for full page nodes.
      if ($this->_settings['global_default'] === 'full_page') {
        $override = $controller->loadOverrideForNode($entity->nid, 'full_page');
        if (!is_null($override)) {
          // Merge the defaults with the overrides.
          $configuration = $controller->merge(array($configuration, $override));
        }
      }

      // The configuration can contain tokens, wrap it in a token resolver
      // object.
      $resolved_configuration =  new TakePartTokenizedObject($configuration,
        array('node' => $entity), array('language' => $langcode));

      // Build all items in the field
      foreach ($items as $delta => $item) {
        $elements[$delta] = $this->viewItem($item, $delta,
          $resolved_configuration, $allowed_regions);
      }
    }

    return $elements;
  }

  public function viewItem($item, $delta, $configuration, $allowed_regions) {
    $builder = new TakePartVideoPlayerVideoNodeSettingsBuilder($configuration);
    $settings = $builder->build($item);
    return array(
      '#theme' => 'tp_video_player',
      '#item' => $item,
      '#settings' => $settings,
      '#allowed_regions' => $allowed_regions,
      '#id' => drupal_html_id('tp_video_player'),
    );
  }
}
