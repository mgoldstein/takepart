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

    // Format the label.
    $replacement->label = t('Feature Image');
  }

  /**
   * Render the replacement content.
   */
  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {

    // grab the file object from the replacement's image field
    $file = field_get_items('inline_content', $replacement, 'field_ic_image');
    $file = $file[0]['file'];

    // get the caption, and alt values for theming
    $image_caption = field_view_field('file', $file, 'field_media_caption', array('label' => 'hidden'), LANGUAGE_NONE);
    $image_alt_items = field_get_items('file', $file, 'field_media_alt');
    $image_alt = field_view_value('file', $file, 'field_media_alt', $image_alt_items[0], array('label' => 'hidden'), LANGUAGE_NONE);

    // Grab the format
    $format = field_get_items('inline_content', $replacement, 'field_ic_image_format');
    $format = $format[0]['value'];
    $alignment = field_get_items('inline_content', $replacement, 'field_ic_alignment');
    $alignment = $alignment[0]['value'];

    // build up image array for theming
    $image = array(
      'path' => $file->uri,
      'alt' => drupal_render($image_alt),
    );
    if ($format != 'none') {
      $image['style_name'] = 'feature_article_' . $format;
      $image_markup = theme('image_style', $image);
    } else {
      $image_markup = theme('image', $image);
    }

    // wrap image caption in figcaption
    $image_caption['#prefix'] = '<figcaption>';
    $image_caption['#suffix'] = '</figcaption>';

    // generate attributes for the wrapping <figure> element
    $attributes = array();

    $attributes['class'][] = 'inline-content-image';
    $attributes['class'][] = 'image-' . $format;
    $attributes['class'][] = 'align-' . $alignment;

    if ($alignment == 'center') {
      $image_info = image_get_info($file->uri);
      if (is_array($image_info)) {
        if ($format != 'none') {
          image_style_transform_dimensions('feature_article_' . $format, $image_info);
        }
        $attributes['style'][] = 'width: ' . $image_info['width'] . 'px;';          
      }
    }

    $content['#replacements'][] = array(
      '#prefix' => '<figure' . drupal_attributes($attributes) . '>',
      '#suffix' => '</figure>',
      '0' => array(
        '#weight' => -10,
        '#markup' => $image_markup,
      ),
      '1' => $image_caption,
    );

    return $content;
  }
}
