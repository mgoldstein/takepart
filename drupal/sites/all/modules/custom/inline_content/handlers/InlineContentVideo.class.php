<?php
/**
 * @file
 * Inline video node controller.
 */

class InlineContentVideo extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {

    // Grab the video's title.
    $video = field_get_items('inline_content', $replacement, 'field_ic_video');
    if ($video !== FALSE && count($video) > 0) {
      $data = reset($video);
      $node = node_load($data['nid']);
      $title = $node->title;
    }
    else {
      $title = t('[No Video]');
    }

    // Format the label.
    $replacement->label = t('Video Modal: !title', array(
      '!title' => $title,
    ));
  }

  /**
   * Return the replacement content.
   */
  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {

    // Show the embedded view mode of the video.
    $video = field_get_items('inline_content', $replacement, 'field_ic_video');
    if ($video !== FALSE && count($video) > 0) {
      $data = reset($video);
      $node = node_load($data['nid']);
      return node_view($node, 'embed');
    }

    // Show nothing if no video was available.
    return array(
      '#type' => 'markup',
      '#markup' => '',
    );
  }
}
