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

    $media = field_get_items('inline_content', $replacement, 'field_ic_media');
    if ($media !== FALSE && count($media) > 0) {
      $data = reset($media);
      $values = array(
        'type' => 'media',
        'view_mode' => 'media_large',
        'fid' => $data['fid'],
        'attributes' => array(
          'alt' => '',
          'class' => 'media-image',
          'style' => 'height: 270px; width: 480px;',
          'typeof' => 'foaf:Image',
        ),
      );
      $tag = '[[' . json_encode($values, JSON_FORCE_OBJECT) . ']]';
      $content['#replacements'][] = array(
        '#type' => 'markup',
        '#markup' => media_filter($tag),
      );
    }

    return $content;
  }
}
