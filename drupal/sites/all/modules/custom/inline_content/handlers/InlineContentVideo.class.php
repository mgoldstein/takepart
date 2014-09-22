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

    $display = array(
      'label' => 'hidden',
      'type' => 'tp_video_player',
      'settings' => array(
        'global_default' => 'inline_content',
      ),
    );
    $video = field_view_field('inline_content', $replacement,
      'field_ic_video', $display, $langcode);

    $alignment = field_get_items('inline_content', $replacement, 'field_ic_alignment');
    $alignment = $alignment[0]['value'];

    $attributes = array();

    $attributes['class'][] = 'inline-content-video';
    $attributes['class'][] = 'align-' . $alignment;

    $content['#replacements'][] = array(
      '#prefix' => '<div' . drupal_attributes($attributes) . '>',
      '#suffix' => '</div>',
      '0' => $video,
    );

    return $content;
  }

  public function form($form, &$form_state, $replacement) {

    $configurations = array();

    // Load the full page defaults.
    $defaults = tp_video_player_load_default_configuration('inline_content');
    if (!is_null($defaults)) {
      $configurations[] = $defaults;
    }

    // Load any available node specific configuration.
    $override = tp_video_player_load_entity_configuration('inline_content',
      $replacement->id);
    if (is_null($override)) {
      $override = tp_video_player_create_configuration();
    }
    $configurations[] = $override;

    $storage_key = implode(":", $form['#parents']);
    if (isset($form_state['storage'][$storage_key])) {
      $active = $form_state['storage'][$storage_key];
    }
    else {
      // Merge the two configurations into the active configuration.
      $active = tp_video_player_merge_configurations($configurations);
      $form_state['storage'][$storage_key] = $active;
    }

    // Pull in the configuration form from the admin.
    module_load_include('inc', 'tp_video_player', 'tp_video_player.admin');
    $form['tp_video_player'] = tp_video_player_defaults_form(array(
      '#title' => t('Player Configuration'),
      '#tree' => TRUE,
    ), $form_state, $active);

    return $form;
  }

  public function submit($form, &$form_state, $replacement) {

    $parents = $form['tp_video_player']['#parents'];
    $values = drupal_array_get_nested_value($form_state['values'], $parents);

    // Load the full page defaults.
    $defaults = tp_video_player_load_default_configuration('inline_content');
    if (is_null($defaults)) {
      $defaults = tp_video_player_create_configuration();
    }

    // Load any available inline content specific configuration.
    $override = tp_video_player_load_entity_configuration('inline_content',
      $replacement->id);
    if (is_null($override)) {
      $override = tp_video_player_create_configuration();
    }

    // Update the active configuration.
    $storage_key = implode(":", $form['#parents']);
    tp_video_player_update_override($defaults, $override, $values);
    $active = tp_video_player_merge_configurations(array($defaults, $override));
    $form_state['storage'][$storage_key] = $active;

    $replacement->tp_video_player = $override;
  }

  public function save($replacement) {
    tp_video_player_save_configuration($replacement->tp_video_player);
    tp_video_player_attach_entity_configuration('inline_content',
      $replacement->id, $replacement->tp_video_player);
  }
}
