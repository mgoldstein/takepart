<?php
/**
 * @file
 * Social Embed inline content controller.
 */

class InlineContentSocialEmbed extends InlineContentReplacementController {

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
    $replacement->label = t('Social Media Embed: !title', array(
      '!title' => $title,
    ));
  }

  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {

    $items = field_get_items('inline_content', $replacement, 'field_ic_fia_embed');
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
            'class' => 'inline-social-embed-wrapper'
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

  public function validate($form, &$form_state, $replacement) {

    $embed_code = $form['#entity']->field_ic_fia_embed['und'][0]['value'];
    $validated = FALSE;
    if (strpos($embed_code , 'twitter') !== FALSE) {
      $validated = TRUE;
    }
    else if (strpos($embed_code , 'instagram') !== FALSE) {
      $validated = TRUE;
    }
    else if (strpos($embed_code , 'vine') !== FALSE) {
      $validated = TRUE;
    }
    else if (strpos($embed_code , 'facebook') !== FALSE) {
      $validated = TRUE;
    }

    if (!$validated) {
       form_error($form['field_ic_fia_embed'] ,t('Only embeds from Twitter, Vine, Facebook, and Instagram are supported at this time.'));
    }

  }
}
