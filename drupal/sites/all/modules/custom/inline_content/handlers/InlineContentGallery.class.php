<?php
/**
 * @file
 * Related gallery inline content controller.
 */

class InlineContentGallery extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {

    // Grab the gallery's title.
    $gallery = field_get_items('inline_content', $replacement, 'field_ic_gallery');
    if ($gallery !== FALSE && count($gallery) > 0) {
      $data = reset($gallery);
      $node = node_load($data['nid']);
      $title = $node->title;
    }
    else {
      $title = t('[No Gallery]');
    }

    // Format the label.
    $replacement->label = t('Related Gallery: !title', array(
      '!title' => $title,
    ));
  }

  /**
   * Return the replacement content.
   */
  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {

    // Show the embedded view mode of the video.
    $gallery = field_get_items('inline_content', $replacement, 'field_ic_gallery');
    if ($gallery !== FALSE && count($gallery) > 0) {
      $data = reset($gallery);
      $node = node_load($data['nid']);
      return node_view($node, 'embed');
    }

    // Show nothing if no gallery was available.
    return array(
      '#type' => 'markup',
      '#markup' => '',
    );
  }
}
