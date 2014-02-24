<?php

class JWPlayerUIPresetSettingsFormController {

  protected $_settings;

  public function __construct($settings) {
    if (is_null($settings)) { $settings = array(); }
    $this->_settings = $settings;
  }

  public function groupFieldset($title) {
    return array(
      '#type' => 'fieldset',
      '#title' => $title,
      '#collapsible' => TRUE,
      '#tree' => TRUE,
    );
  }

  public function tokenField($title, $default_value) {
    return array(
      '#type' => 'textfield',
      '#title' => $title,
      '#default_value' => $default_value,
    );
  }

  public function tokenTree() {
    return array(
      '#title' => t('Replacement patterns'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      'help' => array(
        '#theme' => 'token_tree',
        '#token_types' => array('node'),
      ),
    );
  }

  public function form($form, &$form_state) {
    $form_state['JWPlayerUIPresetSettingsFormController'] = $this;

    foreach (JWPlayerConfiguration::valueLabels() as $group => $values) {
      $group_label = strtr($group, '_', ' ');
      $form[$group] = $this->groupFieldset($group_label);
      foreach ($values as $name => $label) {
        $default_value = '';
        if (isset($this->_settings[$group])) {
          if (isset($this->_settings[$group][$name])) {
            $default_value = $this->_settings[$group][$name];
          }
        }
        $form[$group][$name] = $this->tokenField($label, $default_value);
      }
    }

    $form['token_help'] = $this->tokenTree();

    return $form;
  }
}
