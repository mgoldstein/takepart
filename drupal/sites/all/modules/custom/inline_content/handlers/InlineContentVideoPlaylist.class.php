<?php
/**
 * @file
 * Video inline content controller.
 */

class InlineContentVideoPlaylist extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {

    // Grab the content list.
    $content = field_get_items('inline_content', $replacement, 'field_ic_playlist');
    if ($content !== FALSE && count($content) > 0) {
      $item = reset($content);
      $node = node_load($item['nid']);
      $title = $node->title;
    }
    else {
      $title = t('[No Content]');
    }

    // Format the label.
    $replacement->label = t('Embedded Playlist: !title', array(
      '!title' => $title,
    ));
  }

  /**
   * Render the replacement content.
   */
  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {

    $content = array();
    $items = field_get_items('inline_content', $replacement, 'field_ic_playlist');
    if ($items !== FALSE && count($items) > 0) {

      // Limit to one reference for now.
      $item = reset($items);
      $node = $item['entity'];

      $view_mode = tp_videos_playlist_view_mode('inline_content', $replacement, 'basic');

      $title = tp_videos_playlist_title('inline_content', $replacement, $node->title);

      $items = field_get_items('node', $node, 'field_video_list');
      $videos = tp_videos_playlist_ordered_videos($node, $items);

      // Load the playlist's player configuration
      $player_configuration = tp_video_player_load_entity_configuration(
        'inline_content', $replacement->id, 'playlist_inline_content');

      if (!empty($videos) && !empty($player_configuration)) {

        // The configuration can contain tokens, resolve them now.
        $player_configuration = tp_video_player_resolve_entity_configuration(
          'node', $node, $langcode, $player_configuration);

        // Build the playlist content.
        $playlist = tp_videos_build_playlist($player_configuration,
          $videos, $view_mode, $langcode);

        $content = array(
          '#theme' => 'tp_videos_wrapper',
          '#title' => $title,
          '#playlist' => $playlist,
        );
      }
    }

    $alignment = field_get_items('inline_content', $replacement, 'field_ic_alignment');
    $alignment = $alignment[0]['value'];

    $attributes = array();

    $attributes['class'][] = 'inline-content-playlist';
    $attributes['class'][] = 'align-' . $alignment;

    $content['#replacements'][] = array(
      '#prefix' => '<figure' . drupal_attributes($attributes) . '>',
      '#suffix' => '</figure>',
      '0' => $content,
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
        'inline_content', $replacement->id, 'playlist_inline_content');
      if (is_null($configuration)) {
        $configuration = tp_video_player_clone_default_configuration('playlist_inline_content');
      }
      $form_state['storage'][$storage_key] = $configuration;
    }

    // Pull in the configuration form from the admin.
    module_load_include('inc', 'tp_video_player', 'tp_video_player.admin');
    $form['tp_video_player'] = tp_video_player_configuration_form(array(
      '#title' => t('Player Configuration'),
      '#tree' => TRUE,
    ), $form_state, $configuration, 'playlist');

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
      $replacement->id, 'playlist_inline_content', $replacement->tp_video_player);
  }
}
