<?php
/**
 * @file
 * HTML block inline content controller.
 */

class InlineContentHorizontalRule extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {

    // Format the label.
    $replacement->label = t('Horizontal Rule');
  }

  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {

    $content['#replacements'][] = array(
      '#type' => 'markup',
      '#markup' => '<hr />',
    );

    return $content;
  }
}
