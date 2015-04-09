<?php
/**
 * @file
 * Inline Pull Quote Controller.
 */

class InlineContentPullQuote extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {
    $quote = field_get_items('inline_content', $replacement, 'field_ic_quotation');
    $quote_label = $quote ? implode(' ', array_slice(explode(' ', $quote[0]['value']), 0, 7)) . '…' : '[No Content]';

    // using @quote so that unsanitized user input will be
    // run through check_plain before it's displayed
    $replacement->label = t('Pull Quote: @quote', array('@quote' => $quote_label ));
  }

  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {

    $quote = field_get_items('inline_content', $replacement, 'field_ic_quotation');
    $quote = $quote[0]['value'];
    $cite = field_get_items('inline_content', $replacement, 'field_ic_citation');
    $cite = $cite[0]['value'];

    $markup = theme('inline_content_pullquote', array('quote' => $quote, 'cite' => $cite));
    $content['#replacements'][] = array(
      '#type' => 'markup',
      '#markup' => $markup,
    );

    return $content;
  }
}
