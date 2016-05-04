<?php
/**
 * @file
 * HTML block inline content controller.
 */

class InlineContentAmbientVideo extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {

    // Format the label.
    $replacement->label = t('Feature Ambient Video');

  }

  /**
   * Render the replacement content.
   */
  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {
    $img_bg = '';
    if($file = field_get_items('inline_content',$replacement,'field_article_bg_video_poster')) {
      $file = $file[0];
      if(module_exists('picture')) {
        //Featured articles require original file path
        $mapping = picture_mapping_load('feature_main_image');
        $file['breakpoints'] = picture_get_mapping_breakpoints($mapping);
        $file['attributes'] = array('class' => 'main-image');
        $file['alt'] = '';
        $img_bg = theme('picture', $file);
      } else {
        $image_url = file_create_url($file->uri);
        $img_bg = theme('image', array(
          'path' => $image_url, 'attributes' => array(
            'class' => 'main-image'
          )
        ));
      }
    }
    if($file = field_get_items('inline_content', $replacement, 'field_article_background_video')) {
      //ambient video background for feature article
      $vid_bg_src = $file[0]['uri'];
      $vid_bg_src = file_create_url($vid_bg_src);
      $vid_bg = '<div class = "feature-ambient-image has-videoBG" data-video-bg="' . $vid_bg_src . '">'.$img_bg.'</div>';
    }

    $content['#replacements'][] = array(
      '#type' => 'markup',
      '#markup' => $vid_bg,
    );
    return $content;
  }
}
