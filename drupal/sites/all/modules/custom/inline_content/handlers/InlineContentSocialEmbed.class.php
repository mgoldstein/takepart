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

    if (!$validated) {
       form_error($form['field_ic_fia_embed'] ,t('Only embeds from Twitter, Vine and Instagram are supported at this time.'));
    }

   //Catch any emojis on the embed
   if (preg_match('/([0-9#][\x{20E3}])|[\x{00ae}\x{00a9}\x{203C}\x{2047}\x{2048}\x{2049}\x{3030}\x{303D}\x{2139}\x{2122}\x{3297}\x{3299}][\x{FE00}-\x{FEFF}]?|[\x{2190}-\x{21FF}][\x{FE00}-\x{FEFF}]?|[\x{2300}-\x{23FF}][\x{FE00}-\x{FEFF}]?|[\x{2460}-\x{24FF}][\x{FE00}-\x{FEFF}]?|[\x{25A0}-\x{25FF}][\x{FE00}-\x{FEFF}]?|[\x{2600}-\x{27BF}][\x{FE00}-\x{FEFF}]?|[\x{2900}-\x{297F}][\x{FE00}-\x{FEFF}]?|[\x{2B00}-\x{2BF0}][\x{FE00}-\x{FEFF}]?|[\x{1F000}-\x{1F6FF}][\x{FE00}-\x{FEFF}]?/u', $embed_code)) {
      form_error($form['field_ic_fia_embed'] , t('There were emojis detected in your embed field. Please manually delete the emojis from the field.'));
    }

  }

}
