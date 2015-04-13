<?php
/**
 * @file
 * HTML block inline content controller.
 */

class InlineContentImage extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {

    $label = field_get_items('inline_content', $replacement, 'field_ic_image_label');
    $format = field_get_items('inline_content', $replacement, 'field_ic_image_format');
    $alignment = field_get_items('inline_content', $replacement, 'field_ic_alignment');

    // Format the label.
    $replacement->label = t('Feature Image: @label (format: @format; alignment: @alignment)', array(
      '@label' => $label[0]['value'],
      '@format' => $format[0]['value'],
      '@alignment' => $alignment[0]['value'],
    ));

  }

  /**
   * Render the replacement content.
   */
  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {

    /* If an image exists render it, otherwise return nothing */
    if($file = field_get_items('inline_content', $replacement, 'field_ic_image')){
      $file = $file[0]['file'];

      /* Use image style based on format selection */
      if($format = field_get_items('inline_content', $replacement, 'field_ic_image_format')){
        /* Have to do it this way based on the way this was originally setup */
        $format = $format[0]['value'];
        if($format != 'none'){
          $image_url = image_style_url('feature_article_' . $format, $file->uri);
        }else{
          $image_url = image_style_url('large', $file->uri);
        }
      }else{
        /* If no format exists, use the default 'large' image style */
        $image_url = image_style_url('large', $file->uri);
      }

      /* Setup the image */
      $img_vars = array(
        'path' => $image_url,
        'attributes' => array(
          'class' => array('inline-image')
        ),
        'title' => $file->title,
        'alt' => $file->alt
      );
      $image =  theme('image', $img_vars);

      /* Render caption if it exists */
      if($caption = field_get_items('file', $file, 'field_media_caption')){
        $caption = $caption[0]['value'];
      }

      /* Deprecated: Image alignment */
      if($alignment = field_get_items('inline_content', $replacement, 'field_ic_alignment')){
        $alignment = 'align-'. $alignment[0]['value'];
      }
    }

    $markup = theme('inline_content_image', array('img' => $image, 'caption' => $caption, 'alignment' => $alignment));
    $content['#replacements'][] = array(
      '#type' => 'markup',
      '#markup' => $markup,
    );
    return $content;
  }
}