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
      //Check the content type the image is getting inserted into
      if ($replacement->nid) {
        $node = node_load($replacement->nid);
        $node_type = $node->type;
      }
      /* Use image style based on format selection */
      if($format = field_get_items('inline_content', $replacement, 'field_ic_image_format')){
        /* Have to do it this way based on the way this was originally setup */
        $format = $format[0]['value'];
        if($format != 'none'){
          $mapping = picture_mapping_load('feature_article_' . $format);
        }else {
          //Don't use large image style on full width images on feature article
          if ($replacement->field_ic_alignment['und'][0]['value'] == 'full_width') {
            if (isset($node_type) && $node_type == 'feature_article') {
              $mapping = picture_mapping_load('feature_main_image');
              $file->breakpoints = picture_get_mapping_breakpoints($mapping);
              $file->attributes = array(
                'class' => array('inline-image')
              );
              $image = theme('picture', (array) $file);
            }
          }
          else {
            $derivative_uri = image_style_path('large', $file->uri);
            $img_vars['path']  = file_create_url($derivative_uri);
            $image = theme('lazyloader_image', $img_vars);
          }
        }
      }else{
        /* If no format exists, use the default 'large' image style */
        $derivative_uri = image_style_path('large', $file->uri);
        $img_vars['path']  = file_create_url($derivative_uri);
        $image = theme('lazyloader_image', $img_vars);
      }

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
