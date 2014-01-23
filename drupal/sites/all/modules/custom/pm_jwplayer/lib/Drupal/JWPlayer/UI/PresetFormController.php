<?php

class JWPlayerUIPresetFormController {

  protected $_preset;

  public static function defaultValues() {
    return array(
      'preset_name' => '',
      'machine_name' => '',
      'description' => '',
    );
  }

  public function __construct($preset) {
    if (is_null($preset)) { $preset = new StdClass(); }
    foreach (self::defaultValues() as $property => $value) {
      if (!isset($preset->{$property})) {
        $preset->{$property} = $value;
      }
    }
    $this->_preset = $preset;
  }

  public function presetNameField() {
    return array(
      '#type' => 'textfield',
      '#size' => 20,
      '#maxlength' => 255,
      '#title' => t('Preset name'),
      '#description' => t('Human readable name for the preset.'),
      '#default_value' => $this->_preset->preset_name,
      '#required' => TRUE,
      '#weight' => 0,
    );
  }

  public function machineNameField($source) {
    return array(
      '#type' => 'machine_name',
      '#machine_name' => array(
        'exists' => 'pm_jwplayer_preset_load',
        'source' => array($source),
      ),
      '#title' => t('Machine name'),
      '#description' => t('Machine readable name for the preset. It must be unique and contain only alphanumeric characters and underscores.'),
      '#default_value' => $this->_preset->machine_name,
      '#weight' => 1,
    );
  }

  public function descriptionField() {
    return array(
      '#type' => 'textarea',
      '#title' => t('Description'),
      '#description' => t('Descriptive summary of the preset.'),
      '#default_value' => $this->_preset->description,
      '#weight' => 2,
    );
  }

  public function form($form, &$form_state) {
    $form_state['JWPlayerUIPresetFormController'] = $this;
    $form['preset_name'] = $this->presetNameField();
    unset($form['info']);
    $form['info']['machine_name'] = $this->machineNameField('preset_name');
    $form['description'] = $this->descriptionField();
    return $form;
  }
}
