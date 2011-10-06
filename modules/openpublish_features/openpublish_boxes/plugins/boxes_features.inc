<?php

/**
 * Custom Features box.
 */
class boxes_features extends boxes_box {

  /*
   * we use fancy ajax on our options form and this brakes with the context ui
   */
  function use_multistep_create() {
    return TRUE;
  }

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $i = 0;
    for ($i = 0; $i < 15; $i ++) {
      $tab['featured_node_' . $i] = '';
      $tab['featured_node_weight_' . $i] = '';
    }
    $tab['featured_style'] = 'list_titles';
    $tab['featured_more_text'] = '';
    $tab['featured_more_link'] = '';
    $tab['additional_classes'] = '';
    return $tab;
  }  
  
  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(&$form_state) {
    $path = drupal_get_path("module", 'openpublish_boxes');
    drupal_add_js($path . '/plugins/boxes_features.js', array('type' => 'file', 'weight' => 50)); 
    drupal_add_css($path . '/plugins/boxes_features.css');
    $form = array();
    $i = 0;
    
    for ($i = 0; $i < 15; $i ++) {
      // If any field after the first one is empty, do not display it
      if ($i > 0 && empty($this->options['featured_node_' . $i])) {
        $empty_field = 'hidden';
      }
      else {
        $empty_field = '';
      }
      $form['featured_container_start'] = array(
        '#markup' => '<div id="sortable">'
      );
      $form['featured_node_' . $i] = array(
        '#title' => t('Featured Content Node'),
        '#type' => 'textfield',
        '#size' => 40,
        '#prefix' => '<div class="featured_node clearfix ' . $empty_field . '">',
        '#default_value' => $this->options['featured_node_' . $i],
        '#autocomplete_path' => 'openpublish_boxes/autocomplete/node',
        '#attributes' => array('class' => array('featured-node')),
      );
      $form['featured_node_weight_' . $i] = array(
        '#title' => t('Weight'),
        '#type' => 'textfield',
        '#size' => 2,
        '#default_value' => $this->options['featured_node_weight_' . $i],
        '#prefix' => '<div class="hide-weight">',
        '#suffix' => '</div><div class="handle">&nbsp;</div></div>',
        '#attributes' => array('class' => array('featured-node-weight')),
      );
    }
    $form['featured_container_end'] = array(
      '#markup' => '</div>'
    );
    $form['featured_more_text'] = array(
      '#title' => t('More link text'),
      '#description' => t('Optional text for a custom link that follows the listing.'),
      '#type' => 'textfield',
      '#default_value' => $this->options['featured_more_text'],
    );
    $form['featured_more_link'] = array(
      '#title' => t('More link URL'),
      '#description' => t('Optional URL for a custom link that follows the listing. Need to be a valid URL.'),
      '#type' => 'textfield',
      '#default_value' => $this->options['featured_more_link'],
    );
    $form['featured_style'] = array(
      '#type' => 'radios',
      '#title' => t('Style'),
      '#default_value' => $this->options['featured_style'],
      '#options' => array(
        'single_feature' => t('Single Feature'),
        'list_titles' => t('List (Titles)'),
        'list_images' => t('List (Titles and Main Images)'),
        'carousel' => t('Carousel / Strip'),
      ),
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
   * Implementation of boxes_content::options_form().
   */
  public function render() {
    $content = '';
    $display_nodes = array();
    
    for ($i = 0; $i < 15; $i++) {
      if (!isset($this->options['featured_node_' . $i])) {
        continue;
      }
      $featured_node = $this->options['featured_node_' . $i];
      if (!empty($featured_node)) {
        if (preg_match('/\[nid:(?P<digit>\d+)\]/', $featured_node, $matches)) {
          $nid = $matches['digit'];
          $display_nodes[] = $nid;
        }
      }
    }
    if (!empty($display_nodes)) {
      $nodes = node_load_multiple($display_nodes);
      foreach($display_nodes as $nid) {
        // TODO: implement different style themes
        $content .= '<p>' . l($nodes[$nid]->title, 'node/' . $nodes[$nid]->nid) . '</p>';
      }
    }
    if ($this->options['featured_more_text']) {
      if (valid_url($this->options['featured_more_link'])) {
        $content .= '<div class="box-more-link">' . 
          l($this->options['featured_more_text'], $this->options['featured_more_link']) . '</div>';
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
}
