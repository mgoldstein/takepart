<?php
/**
 * @file
 * Newsletter signup inline content controller.
 */

class InlineContentNewsletter extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {

    // Grab the  newsletter's title.
    $newsletter = field_get_items('inline_content', $replacement, 'field_ic_newsletter');
    if ($newsletter !== FALSE && count($newsletter) > 0) {
      $data = reset($newsletter);
      $entity = entity_load_single('newsletter_campaign', $data['target_id']);
      $title = $entity->title;
    }
    else {
      $title = t('[No Newsletter]');
    }

    // Format the label.
    $replacement->label = t('Newsletter Signup: !title', array(
      '!title' => $title,
    ));
  }

  /**
   * Return the replacement content.
   */
  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {

    $markup = '';

    $newsletter = field_get_items('inline_content', $replacement, 'field_ic_newsletter');
    if ($newsletter !== FALSE && count($newsletter) > 0) {
      $data = reset($newsletter);

      $block = block_load('newsletter_campaign', $data['target_id']);
      $block->region = 'inline_content';

      $delta = "newsletter_campaign_{$data['target_id']}";
      $rendered = _block_render_blocks(array($delta => $block));

      return _block_get_renderable_array($rendered);
    }

    // Show nothing if no newsletter was available.
    return array(
      '#type' => 'markup',
      '#markup' => '',
    );
  }
}
