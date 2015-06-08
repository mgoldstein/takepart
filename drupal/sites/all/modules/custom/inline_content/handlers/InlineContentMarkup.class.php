<?php
/**
 * @file
 * HTML block inline content controller.
 */

class InlineContentMarkup extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {

    // Grab the  markups's label.
    $label = field_get_items('inline_content', $replacement, 'field_ic_label');
    if ($label !== FALSE && count($label) > 0) {
      $data = reset($label);
      $title = $data['value'];
    }
    else {
      $title = t('Unlabeled :(');
    }

    // Format the label.
    $replacement->label = t('Custom Markup: !title', array(
      '!title' => $title,
    ));
  }

  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {

    $items = field_get_items('inline_content', $replacement, 'field_ic_markup');
    if ($items !== FALSE && count($items) > 0) {
      $item = reset($items);
      if (isset($item['safe_value'])) {
        $markup = $item['safe_value'];
      }
      else {
        $markup = check_markup($item['value'], $item['format'], $langcode);
      }
      $markup = theme('html_tag', array(
        'element' => array(
          '#tag' => 'div',
          '#attributes' => array(
            'class' => 'inline-html-wrapper'
          ),
          '#value' => $markup
        )
      ));
      $content['#replacements'][] = array(
        '#type' => 'markup',
        '#markup' => $markup,
      );
    }

    return $content;
  }
}
