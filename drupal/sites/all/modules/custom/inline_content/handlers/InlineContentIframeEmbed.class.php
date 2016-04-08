<?php
/**
 * @file
 * Interactive Iframe inline content controller.
 */

class InlineContentIframeEmbed extends InlineContentReplacementController {

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
    $replacement->label = t('Interactive Iframe Embed: !title', array(
      '!title' => $title,
    ));
  }

  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {
    $items = field_get_items('inline_content', $replacement, 'field_ic_fia_embed');
    $caption = "";
    if ($items !== FALSE && count($items) > 0) {
      $item = reset($items);
      if (isset($item['safe_value'])) {
        $iframe = $item['safe_value'];
      }
      else {
        $iframe = check_markup($item['value'], $item['format'], $langcode);
      }

    if ($caption = field_get_items('inline_content', $replacement, 'field_ic_citation')) {
      $caption  = $caption[0]['value'];
    }

    $markup = theme('inline_content_iframe', array('iframe' => $iframe, 'caption' => $caption));
      $content['#replacements'][] = array(
        '#type' => 'markup',
        '#markup' => $markup,
      );
    }
    return $content;
  }

  /*public function validate($form, &$form_state, $replacement) {

    $embed_code = $form['#entity']->field_ic_fia_embed['und'][0]['value'];
    if (strpos($embed_code , 'iframe') === FALSE) {
       form_error($form['field_ic_fia_embed'] ,t('Only Iframe Player embeds are supported in this Inline Replacement.'));
    }
  }*/

}
