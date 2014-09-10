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
    $summary = array();
    if (!empty($this->_settings['one_to_one'])) {
      $summary[] = t('Individual video players');
    }
    else {
      $summary[] = t('Single player with playlist');
    }
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

    if ($this->_field->type === 'file') {
      $builder = new TakePartVideoPlayerFileFieldBuilder(
        $entity_type, $entity, $langcode);
    }
    elseif ($this->_field->type === 'node_reference') {
      $builder = new TakePartVideoPlayerNodeReferenceFieldBuilder(
        $entity_type, $entity, $langcode);
    }

    // Build the player render arrays.
    if ($this->_settings['one_to_one']) {
      foreach ($items as $delta => $item) {
        $elements[$delta] = $this->viewItem($delta,
          $builder->buildForOne($item),
          $builder->allowedRegions());
      }
    }
    else {
      $elements[] = $this->viewItem(0,
        $builder->buildForMany($items),
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
