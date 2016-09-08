<?php
/**
 * @file
 * Inline Sharing text block
 */

class InlineContentInlineSharing extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {

    // Grab the  markups's label.
    $author_quote = field_get_items('inline_content', $replacement, 'field_ic_author_quote');

    // Format the label.
    $replacement->label = t('Inline Sharing Block: @author_quote', array(
      '@author_quote' => truncate_utf8($author_quote[0]['value'], 40, FALSE, TRUE),
    ));
  }

  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {
    $author_quote = field_get_items('inline_content', $replacement, 'field_ic_author_quote');
    $author_name = field_get_items('inline_content', $replacement, 'field_ic_author_name');
    $anchor_tag = field_get_items('inline_content', $replacement, 'field_ic_anchor');
    $unique_id = $replacement->id;

    if($sharing_title = field_get_items('inline_content', $replacement, 'field_ic_sharing_title')){
      $sharing_title = $sharing_title[0]['value'];
    }
    $content['#replacements'][] = array(
      '#type' => 'markup',
      '#markup' => "<div data-title=\"$sharing_title\" data-anchor=\"".$anchor_tag[0]['value']."\" data-author-name=\"".$author_name[0]['value']."\" data-unique-id=\"".$unique_id."\" class=\"inlineSharingContainer\">
        <div class=\"inlineSharingQuote\">".$author_quote[0]['value']."</div>
        <div class=\"inlineSharingButtons inlineSharingUnique-".$unique_id."\"></div></div>",
    );

    return $content;
  }

  public function validate($form, &$form_state, $replacement) {


  }

}
