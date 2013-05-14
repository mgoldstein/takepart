<?php
/**
 * @file
 * Base inline content controller.
 */

abstract class InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {
    // Make sure the replacement has a label.
    if (!isset($replacement->label)) {
      $replacement->label = t('Inline Content');
    }
  }

  /**
   * Return the replacement content.
   */
  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {
    return $content;
  }
}
