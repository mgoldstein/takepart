<?php
/**
 * @file
 * HTML block inline content controller.
 */

class InlineContentAdBlock extends InlineContentReplacementController {

  /**
   * Keep track of how many ads we've shown
   * @var integer
   */
  private $index = 0;

  /**
   * An array containing the boxes module delts
   * for the ad slots we're going to display
   * @var array
   */
  private $ad_slots = array(
    'ga_features_ad2',
    'ga_features_ad3',
    'ga_features_ad4',
  );

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {

    // Format the label.
    $replacement->label = t('Ad Block');
  }

  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {

    $replacement = array(
      '#type' => 'markup',
      '#markup' => '',
    );

    // We will render a maximum of 3 ads
    if ($this->index < 3) {
      $ad_box = block_load('boxes', $this->ad_slots[$this->index]);
      $replacement = _block_get_renderable_array(_block_render_blocks(array($ad_box)));
      $this->index++;
    }

    $content['#replacements'][] = $replacement;

    return $content;
  }
}
