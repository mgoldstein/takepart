<?php

/**
 * Simple custom text box.
 */
class boxes_simple extends boxes_box {
  const BOXES_EDIT_IN_PLACE = 1;

  /**
   * Implementation of boxes_box::options_defaults().
   */
  public function options_defaults() {
    return array(
      'body' => array(
        'value' => '',
        'format' => filter_default_format(),
      ),
      'additional_classes' => '',
    );
  }

  /**
   * Implementation of boxes_box::options_form().
   */
  public function options_form(&$form_state) {
    $option_format = isset($this->options['body']['format']) ? $this->options['body']['format'] : 'plain_text';
    $format = filter_format_load($option_format);

    // TODO: this currently breaks if you switch mode and try to edit existing
    // simple boxes in the other mode. DO NOT USE IN PRODUCTION /!\
    if (variable_get('boxes_edit_location', BOXES_EDIT_IN_PLACE) == BOXES_EDIT_IN_PLACE) {
      $form['body'] = array(
        '#type' => 'textarea',
        '#title' => t('Box body'),
        '#default_value' => $this->options['body'],
        '#rows' => 6,
        '#format' => '',
        '#description' => t('The content of the block as shown to the user.'),
      );
    }
    elseif (filter_access($format)) {
      $form = array();
      $form['body'] = array(
        '#type' => 'text_format',
        '#base_type' => 'textarea',
        '#title' => t('Box body'),
        '#default_value' => $this->options['body']['value'],
        '#rows' => 6,
        '#format' => $this->options['body']['format'] ? $this->options['body']['format'] : NULL,
        '#description' => t('The content of the block as shown to the user.'),
      );
      $form['view_advanced_settings'] = array(
        '#type' => 'fieldset',
        '#title' => t('Advanced settings'),
        '#collapsed' => TRUE,
        '#collapsible' => TRUE
      );
      $form['view_advanced_settings']['additional_classes'] = array(
        '#title' => t('Additional CSS classes'),
        '#description' => t('Optional CSS classes that will be added to the top-level div container for this box. Separate them with spaces.'),
        '#type' => 'textfield',
        '#default_value' => $this->options['additional_classes'],
      );
    }

    return $form;
  }

  /**
   * Implementation of boxes_box::render().
   */
  public function render() {
    $content = '';

    if (!empty($this->options['body']['value'])) {
      if (isset($this->options['body']['format']) && !$this->options['body']['format']) {
        $content = check_markup($this->options['body']['value'], $this->options['body']['format'], $langcode = '' /* TODO Set this variable. */, FALSE);
      }
      else {
        $content = $this->options['body'];
      }
    }

    $title = isset($this->title) ? $this->title : NULL;
    $box = array(
      'delta' => $this->delta, // Crucial.
      'title' => $title,
      'subject' => $title,
      'content' => $content,
    );

    // Additional Classes
    if (!empty($this->options['additional_classes'])) {
      $box['additional_classes'] = $this->options['additional_classes'];
    }

    return $box;
  }
}
