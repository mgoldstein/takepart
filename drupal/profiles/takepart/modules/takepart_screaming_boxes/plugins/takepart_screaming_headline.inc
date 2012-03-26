<?php
// $Id$
/* @file
 *  Extends boxes_box to provide additional fields for screaming headline
 * @author alphageekboy
 * @date 05/10/2011
 * @company Phase2 Technology
 */
  $path = drupal_get_path("module", 'takepart_screaming_boxes');
  drupal_add_css($path . '/plugins/takepart_screaming_headline.css');
/**
 * Custom Features box.
 */
class boxes_headline extends boxes_box {

  /*
   * we use fancy ajax on our options form and this brakes with the context ui
   */
  function use_multistep_create() {
    return TRUE;
  }
/*
 * Display Screaming Headline - Checkbox
 * Capitalization Style
 */

/**
 * Implementation of boxes_content::options_defaults().
 */
  public function options_defaults() {
    $default['tp_screaming_headline_text']        = '';
    $default['tp_screaming_headline_link']        = '';
    $default['tp_screaming_headline_enable']      = '';
    $default['tp_screaming_headline_caps_style']  = '';
    $default['tp_screaming_headline_preview']     = '';
    return $default;
  }

  public function options_submit($form, &$form_state) {
  }
/**
 * Implementation of boxes_content::options_form().
 */
  public function options_form(&$form_state) {
    $form = array();
    foreach ($form_state['values'] AS $key => $value) {
      $this->options[$key] = $value;
    }
    $box    = $this->render();
    $markup = $box['content'];
    $form['tp_screaming_headline_preview'] = array(
      '#markup' => $markup,
      '#prefix' => '<div id="screaming-markup-wrapper">',
      '#suffix' => '</div>',
      );
    $form['tp_screaming_headline_enable'] = array(
      '#title' => t('Display / Preview Screaming Headline'),
      '#description' => t('If selected then the screaming headline will be displayed.'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['tp_screaming_headline_enable'],
      '#ajax' => array(
        'callback' => 'takepart_screaming_boxes_preview_callback',
        'wrapper' => 'screaming-markup-wrapper',
        'method' => 'replace',
        'effect' => 'fade',
      ),
    );
    $form['tp_screaming_headline_text'] = array(
      '#title' => t('Screaming headline text'),
      '#description' => t('Text to be displayed for the screaming headline on the homepage. Limited to 50 characters.'),
      '#type' => 'textfield',
      '#default_value' => $this->options['tp_screaming_headline_text'],
      '#maxlength' => 50,
      '#size' => 50,
      '#ajax' => array(
        'callback' => 'takepart_screaming_boxes_preview_callback',
        'wrapper' => 'screaming-markup-wrapper',
        'method' => 'replace',
        'effect' => 'fade',
      ),
    );
    $form['tp_screaming_headline_link'] = array(
      '#title' => t('Screaming headline URL'),
      '#description' => t('Optional link to an on-site or off-site page. If off-site, enter a full URL (http://www.example.com), otherwise use a site internal link (without the initial slash).'),
      '#type' => 'textfield',
      '#default_value' => $this->options['tp_screaming_headline_link'],
      '#maxlength' => 255,
      '#size' => 80,

    );
    $form['tp_screaming_headline_caps_style'] = array(
      '#title' => t('Capitalization Style'),
      '#description' => '',
      '#type' => 'radios',
      '#options' => array(t('none (display as entered)'), t('ALL CAPS'), t('Sentence cased')),
      '#default_value' => $this->options['tp_screaming_headline_caps_style'],
      '#ajax' => array(
        'callback' => 'takepart_screaming_boxes_preview_callback',
        'wrapper' => 'screaming-markup-wrapper',
        'method' => 'replace',
        'effect' => 'fade',
      ),
    );
    
  return $form;
}
/**
 * Implementation of boxes_content::options_form().
 */
  public function render() {
    $content = '';
    switch ($this->options['tp_screaming_headline_caps_style']) {
      case 1: // All Caps
          $text = drupal_strtoupper($this->options['tp_screaming_headline_text']);
          break;
      case 2: // Sentence Cased
          $text = drupal_ucfirst(drupal_strtolower($this->options['tp_screaming_headline_text']));
          break;
      case 0: // display as entered
      default:
          $text = $this->options['tp_screaming_headline_text'];
          break;
    }
    if ($this->options['tp_screaming_headline_link']) {
      $options = array();
      if (url_is_external($this->options['tp_screaming_headline_link'])) {    // External link
        $options = array('attributes' => array('target' => '_blank'));
      }
      $text = l($text, $this->options['tp_screaming_headline_link'], $options);
    }

    if (($text) && $this->options['tp_screaming_headline_enable'] == 1) {
        $content .= '<h2 id="screaming-headline">' . $text . '</h2>';
    }
    else {
        $content = '';
    }
    $title = isset($this->title) ? check_plain($this->title) : NULL;
    $box = array(
      'delta' => $this->delta, // Crucial.
      'title' => NULL,
      'subject' => NULL,
      'content' => render($content),
    );
    return $box;
  }
}