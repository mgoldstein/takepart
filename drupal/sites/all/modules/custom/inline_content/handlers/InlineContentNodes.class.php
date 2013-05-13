<?php
/**
 * @file
 * Embedded node(s) inline content controller.
 */

class InlineContentNodes extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {

    // Grab the content list.
    $content = field_get_items('inline_content', $replacement, 'field_ic_content');
    $titles = array();
    if ($content !== FALSE) {

      // Grab the title of each node.
      $nids = array();
      foreach ($content as $data) {
        $nids[] = (int) $data['nid'];
      }
      foreach (node_load_multiple($nids) as $node) {
        $titles[] = $node->title;
      }
    }

    // Collapse the titles into a single title.
    $title = count($titles) ? implode(', ', $titles) : t('[No Content]');

    // Determine the display orientation.
    $orientation = t('Horizontal');
    $items = field_get_items('inline_content', $replacement, 'field_ic_orientation');
    if ($items !== FALSE && count($items) > 0) {
      $data = reset($items);
      if ($data['value'] == 'vertical') {
        $orientation = t('Vertical');
      }
    }

    // Format the label.
    $replacement->label = t('Embedded Content: !title (!orientation)', array(
      '!title' => $title,
      '!orientation' => $orientation,
    ));
  }

  /**
   * Return the replacement content.
   */
  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {
    return $content;
  }
}
