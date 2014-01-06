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
    $cite = field_get_items('inline_content', $replacement, 'field_ic_citation');

    $attributes = array();
    $attributes['class'][] = 'pull-quote-alt';
    $attributes['class'][] = 'align-left';

    // build up the markup string. We know we'll have a quote;
    // not sure whether we'll have a cite.
    $markup = '<p class="quotation">' . $quote[0]['safe_value'] . '</p>';
    if ($cite) {
      $markup .= '<cite>&mdash; ' . $cite[0]['safe_value'] . '</cite>';
    }

    $content['#replacements'][] = array(
      '#type' => 'markup',
      '#markup' => '<blockquote' . drupal_attributes($attributes) . '>' . $markup . '</blockquote>',
    );

    return $content;
  }
}
