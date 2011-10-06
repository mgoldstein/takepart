<?php

/**
 * Simple custom text box.
 */
class boxes_image extends boxes_box {
  /**
   * Implementation of boxes_box::options_defaults().
   */
  public function options_defaults() {
    return array(
      'image_file' => '',
      'image_link' => '',
      'image_style' => '',
      'additional_classes' => '',
    );
  }

  /*
   * implements boxes_box::option_submit()
   * This needs a boxes patch
   */
  public function options_submit($form, &$form_state) {
    if (empty($form_state['values']['image_file'])) {
      return;
    }
    
    // Make the file upload permanent (it is a temp file otherwise)
    $fid = $form_state['values']['image_file'];
    $file = file_load($fid);
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    file_usage_add($file, 'openpublish_boxes', 'boxes_image', 1);
  }
  
  /**
   * Implementation of boxes_box::options_form().
   */
  public function options_form(&$form_state) {
    $form = array();
    
    $style_options[''] = t('None');
    $image_styles = array_keys(image_styles());
    foreach($image_styles as $style) {
      $style_options[$style] = $style;
    }
    
    if ($this->options['image_file']) {
      $image = file_load($this->options['image_file']);
      $form['image_display'] = array(
        '#markup' => theme_image_style(array(
          'style_name' => 'thumbnail',
          'path' => $image ? $image->uri : '',
          )),
      );
    }
    
    $form['image_file'] = array(
      '#type' => 'managed_file',
      '#title' => t('Attach image file'),
      '#size' => 40,
      '#default_value' => $this->options['image_file'],
      '#upload_location' => 'public://imagebox/',
    );

    $form['image_link'] = array(
      '#type' => 'textfield',
      '#title' => t('Link to URL'),
      '#size' => 60,
      '#default_value' => $this->options['image_link'],
      '#description' => t('Specify a valid URL that the image will link to.')
    );
    $form['image_style'] = array(
      '#type' => 'select',
      '#title' => t('Image style'),
      '#default_value' => !empty($this->options['image_style']) ? $this->options['image_style'] : '',
      '#options' => $style_options,
    );
    $form['view_advanced_settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Advanced Settings'),
      '#collapsed' => TRUE,
      '#collapsible' => TRUE
    );
    $form['view_advanced_settings']['additional_classes'] = array(
      '#title' => t('Additional CSS classes'),
      '#description' => t('Optional CSS classes that will be added to the top-level div container for this box. Separate them with spaces.'),
      '#type' => 'textfield',
      '#default_value' => $this->options['additional_classes'],
    );
    return $form;
  }

  /**
   * Implementation of boxes_box::render().
   */
  public function render() {
    $content = '';
    
    if ($this->options['image_file']) {
      $image = file_load($this->options['image_file']);
      
      if (!empty($image) && is_object($image)) {
        if (!empty($this->options['image_style'])) {
          $content .= theme_image_style(array('style_name' => $this->options['image_style'],'path' => $image->uri));
        }
        else {
          $content .= theme('image', array('path' => $image->uri));
        }
      }
      
      if ($this->options['image_link']) {
        if (valid_url($this->options['image_link'])) {
          $content = l($content, $this->options['image_link'], array('html' => TRUE));
        }
      }
    }
     
    $title = isset($this->title) ? check_plain($this->title) : NULL;
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
  
  function use_multistep_create() {
    return TRUE;
  }
}
