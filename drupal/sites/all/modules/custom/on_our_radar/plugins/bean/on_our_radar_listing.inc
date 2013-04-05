<?php

class OnOurRadarBean extends BeanPlugin {

  /**
   * Declares default block settings.
   */
  public function values() {
    $values = array(
      'settings' => array(
        'node_view_mode' => FALSE,
        'records_shown' => FALSE,
      ),
      'radar_links' => array(
        'text' => '',
        'path' => '',
      ),
    );
    return array_merge(parent::values(), $values);
  }

  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $form = array();

    $form_state['storage']['linkcount'] = isset($form_state['storage']['linkcount']) ? $form_state['storage']['linkcount'] : 0;

    $form['radar_links'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#prefix' => '<div id="radar_links_wrapper">',
      '#suffix' => '</div>',
      '#title' => t('Test Link'),
    );

    $radar_link_count = (count($bean->radar_links)/3 < $form_state['storage']['linkcount']) ? $form_state['storage']['linkcount'] : (count($bean->radar_links)-1)/3;

    for ($i = 0; $i <= $radar_link_count; $i++) {
      $form['radar_links']['link'.$i] = array(
        '#type' => 'textfield',
        '#title' => t($i+1 . ' Link'),
        '#default_value' => $bean->radar_links['link'.$i],
      );
      $form['radar_links']['title'.$i] = array(
        '#type' => 'textfield',
        '#title' => t($i+1 . ' Title'),
        '#default_value' => $bean->radar_links['title'.$i],
      );
      $form['radar_links']['topic'.$i] = array(
        '#type' => 'textfield',
        '#title' => t($i+1 . ' Topic'),
        '#default_value' => $bean->radar_links['topic'.$i],
      );
    }

    $form['add_link'] = array(
      '#type' => 'button',
      '#value' => t('Add A Link'),
      '#href' => '',
      '#ajax' => array(
        'callback' => 'on_our_radar_ajax_add_link',
        'wrapper' => 'radar_links_wrapper',
       ),
     );

    $form_state['storage']['linkcount']++;
    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $content['radar_links']['#markup'] = "<ol>";
    for ($i = 0; $i <= count($bean->radar_links)/3-1; $i++) {
      $content['radar_links']['#markup'] .= theme('on_our_radar_link', array('link' => $bean->radar_links['link'.$i], 'title' => $bean->radar_links['title'.$i], 'topic' => $bean->radar_links['topic'.$i]));
    }
    $content['radar_links']['#markup'] .= "</ol>";
    return $content;
  }
}

function on_our_radar_ajax_add_link($form, $form_state) {
  return $form['radar_links'];
}
