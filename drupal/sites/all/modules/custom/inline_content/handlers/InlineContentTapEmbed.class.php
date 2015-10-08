<?php
/**
 * @file
 * TAP Embed inline content controller.
 */

class InlineContentTapEmbed extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {

  }

  /**
   * Return the replacement content.
   */
  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {

    $attributes = array(
      'class' => array('takepart-tap-embed')
    );

    $content['#replacements'][] = array(
      '#type' => 'markup',
      '#markup' => '<div' . drupal_attributes($attributes) . '></div>',
    );

    return $content;
  }
}
