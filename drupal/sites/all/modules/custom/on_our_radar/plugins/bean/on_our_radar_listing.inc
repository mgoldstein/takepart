<?php

class OnOurRadarBean extends BeanPlugin
{

  /**
  * Items in Link grouping:
  */
  private $radar_lnk_cnt = 3;


  /**
   * Returns proper link count.
   */
  public function get_link_count($radar_links) {
    foreach(array_reverse($radar_links) as $key => $value) {
      list($column, $index) = preg_split('#(?<=[a-z](?=\d))#i', $key);
      if ($column != 'remove_link' && !empty($value)) {
        return (int)($index+1);
      }
    }

    return 0;
  }

  /**
   * Declares default block settings.
   */
  public function values()
  {
    $values = array(
      'settings' => array(
        'node_view_mode' => FALSE,
        'records_shown' => FALSE
      ),
      'radar_links' => array(
        'text' => '',
        'path' => ''
      )
    );
    return array_merge(parent::values(), $values);
  }


  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state)
  {

    drupal_add_css(drupal_get_path('module', 'on_our_radar') . '/css/admin.css', array(
      'group' => CSS_DEFAULT,
      'type' => 'file'
    ));

    $form = array();

    if ($form_state['triggering_element']['#name'] == 'add') {
      $form_state['storage']['linkcount']++;
    }

    $form_state['storage']['linkcount'] = isset($form_state['storage']['linkcount']) ? $form_state['storage']['linkcount'] : $this->get_link_count($bean->radar_links);

    $form['radar_links'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#prefix' => '<div id="radar_links_wrapper">',
      '#suffix' => '</div>',
      '#title' => t('Links')
    );

    if (substr($form_state['triggering_element']['#name'], 0, 6) == 'remove') {
      $itemnum = substr($form_state['triggering_element']['#name'], 6, strlen($form_state['triggering_element']['#name']));
      for ($x = $itemnum; $x <= $form_state['storage']['linkcount']; $x++) {
          $form_state['values']['radar_links']['link' . $x] = $form_state['values']['radar_links']['link' . ($x+1)];
          $form_state['values']['radar_links']['title' . $x] = $form_state['values']['radar_links']['title' . ($x+1)];
          $form_state['values']['radar_links']['topic' . $x] = $form_state['values']['radar_links']['topic' . ($x+1)];
      }

      $form_state['storage']['linkcount']--;
    }

    $linkcount = $form_state['storage']['linkcount'];

    for ($x = 0; $x <= $linkcount; $x++) {
      $form['radar_links']['link' . $x]  = array(
        '#type' => 'textfield',
        '#title' => t('Link ' . ($x+1)),
        '#default_value' => $bean->radar_links['link' . $x],
      );
      if(isset($form_state['values']['radar_links']['link' . $x])) {
        $form['radar_links']['link' . $x]['#value'] =  $form_state['values']['radar_links']['link' . $x];
      }
      $form['radar_links']['title' . $x] = array(
        '#type' => 'textfield',
        '#title' => t('Title ' . ($x+1)),
        '#default_value' => $bean->radar_links['title' . $x],
      );
      if(isset($form_state['values']['radar_links']['title' . $x])) {
        $form['radar_links']['title' . $x]['#value'] =  $form_state['values']['radar_links']['title' . $x];
      }
      $form['radar_links']['topic' . $x] = array(
        '#type' => 'textfield',
        '#title' => t('Topic ' . ($x+1)),
        '#default_value' => $bean->radar_links['topic' . $x],
      );
      if(isset($form_state['values']['radar_links']['topic' . $x])) {
        $form['radar_links']['topic' . $x]['#value'] =  $form_state['values']['radar_links']['topic' . $x];
      }
      if ($x > 0) {
        $form['radar_links']['remove_link' . $x] = array(
          '#type' => 'button',
          '#value' => t('Remove'),
          '#name' => 'remove' . $x,
          '#href' => '',
          '#ajax' => array(
            'callback' => 'on_our_radar_ajax_remove_link',
            'wrapper' => 'radar_links_wrapper'
          ),
          '#attributes' => array(
          'class' => array(
            'last'
          )
        )
        );
      }
    }

    $form['add_link'] = array(
      '#type' => 'button',
      '#value' => t('Add a Link'),
      '#name' => 'add',
      '#href' => '',
      '#ajax' => array(
        'callback' => 'on_our_radar_ajax_add_link',
        'wrapper' => 'radar_links_wrapper'
      )
    );

    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL)
  {
    $elements = array();
    $linkcount = $this->get_link_count($bean->radar_links);
    for ($i = 0; $i <= $linkcount; $i++) {
      $elements[$i]          = array();
      $elements[$i]['topic'] = $bean->radar_links['topic' . $i];
      $elements[$i]['link']  = $bean->radar_links['link' . $i];
      $elements[$i]['title'] = $bean->radar_links['title' . $i];
    }
    $content['radar_links']['#markup'] = theme('on_our_radar', array(
      'links' => $elements
    ));
    return $content;
  }
}

function on_our_radar_ajax_add_link($form, $form_state)
{
  return $form['radar_links'];
}

function on_our_radar_ajax_remove_link($form, $form_state)
{
  return $form['radar_links'];
}
