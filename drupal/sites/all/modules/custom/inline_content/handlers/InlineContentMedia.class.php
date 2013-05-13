<?php
/**
 * @file
 * General media inline content controller.
 */

class InlineContentMedia extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {

    // Grab the media's title.
    $media = field_get_items('inline_content', $replacement, 'field_ic_media');
    if ($media !== FALSE && count($media) > 0) {
      $data = reset($media);
      $file = file_load($data['fid']);
      $title = t('!name [!mime]', array(
        '!name' => $file->filename,
        '!mime' => $file->filemime,
      ));
    }
    else {
      $title = t('[No Media]');
    }

    // Format the label.
    $replacement->label = t('Embedded Media: !title', array(
      '!title' => $title,
    ));
  }

  /**
   * Return the replacement content.
   */
  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {
    return $content;
  }
}
