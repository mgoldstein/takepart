<?php
/**
 * @file
 * Video inline content controller.
 */

class InlineContentVideo extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {

    // Grab the content list.
    $content = field_get_items('inline_content', $replacement, 'field_ic_video');
    if ($content !== FALSE && count($content) > 0) {
      $item = reset($content);
      $node = node_load($item['nid']);
      $title = $node->title;
    }
    else {
      $title = t('[No Content]');
    }

    // Format the label.
    $replacement->label = t('Embedded Video: !title', array(
      '!title' => $title,
    ));
  }

  /**
   * Render the replacement content.
   */
  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {

    $video = array();
    $items = field_get_items('inline_content', $replacement, 'field_ic_video');
    if ($items !== FALSE && count($items) > 0) {

      // Limit to one reference for now.
      $item = reset($items);

      // Load the video node's active configuration
      $node = $item['node'];

      // Load any available replacement specific configuration.
      $configuration = tp_video_player_load_entity_configuration(
        'inline_content', $replacement->id, 'video_inline_content');
      if (is_null($configuration)) {
        $configuration = tp_video_player_clone_default_configuration(
          'video_inline_content');
      }

      $files = field_get_items('node', $node, 'field_video');

      // The path to the video node is stored in the MEDIAID to allow
      // the social share to change with each video.
      $uri = entity_uri('node', $node);
      $media_id = url($uri['path'], $uri['options']);

      // Get the allowed regions from the video node.
      $allowed_regions = tp_video_player_video_allowed_regions('node', $node);
      foreach ($files as $delta => $file) {
        $files[$delta]['allowed_regions'] = $allowed_regions;
        $files[$delta]['media_id'] = $media_id;
        $files[$delta]['pre_roll_ad_tag'] = $configuration->ad_tag;
      }

      $configuration = tp_video_player_resolve_entity_configuration('node',
        $node, $langcode, $configuration);

      $video = tp_video_player_player_view($configuration, $files, 'inline');
    }

    $alignment = field_get_items('inline_content', $replacement, 'field_ic_alignment');
    $alignment = $alignment[0]['value'];

    $attributes = array();

    $attributes['class'][] = 'inline-content-video';
    $attributes['class'][] = 'align-' . $alignment;

    $content['#replacements'][] = array(
      '#prefix' => '<figure' . drupal_attributes($attributes) . '>',
      '#suffix' => '</figure>',
      '0' => $video,
    );

    return $content;
  }

  public function form($form, &$form_state, $replacement) {

    $storage_key = implode(":", $form['#parents']);
    if (isset($form_state['storage'][$storage_key])) {
      $configuration = $form_state['storage'][$storage_key];
    }
    else {
      // Load any available replacement specific configuration.
      $configuration = tp_video_player_load_entity_configuration(
        'inline_content', $replacement->id, 'video_inline_content');
      if (is_null($configuration)) {
        $configuration = tp_video_player_clone_default_configuration(
          'video_inline_content');
      }
      $form_state['storage'][$storage_key] = $configuration;
    }

    // Pull in the configuration form from the admin.
    module_load_include('inc', 'tp_video_player', 'tp_video_player.admin');
    $form['tp_video_player'] = tp_video_player_configuration_form(array(
      '#title' => t('Player Configuration'),
      '#tree' => TRUE,
    ), $form_state, $configuration, 'video');

    return $form;
  }

  public function submit($form, &$form_state, $replacement) {

    $storage_key = implode(":", $form['#parents']);
    $configuration = $form_state['storage'][$storage_key];

    $parents = $form['tp_video_player']['#parents'];
    $values = drupal_array_get_nested_value($form_state['values'], $parents);

    // Pull in the configuration form from the admin.
    module_load_include('inc', 'tp_video_player', 'tp_video_player.admin');

    // Update, save and attach the node specific configuration.
    tp_video_player_update_configuration($configuration, $values);
    $form_state['storage'][$storage_key] = $configuration;

    $replacement->tp_video_player = $configuration;
  }

  public function save($replacement) {
    tp_video_player_save_configuration($replacement->tp_video_player);
    tp_video_player_attach_entity_configuration('inline_content',
      $replacement->id, 'video_inline_content', $replacement->tp_video_player);
  }
}
