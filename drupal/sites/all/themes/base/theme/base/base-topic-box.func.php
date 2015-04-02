<?php

/**
 * Overrides theme_hook()
 * Returns a topic box image or link w/ image
 */
function base_base_topic_box(&$variables){
  $topic = taxonomy_term_load($variables['tid']);
  if($image = field_get_items('taxonomy_term', $topic, 'field_topic_box_image')){
    $image_url = image_style_url('large', $image[0]['uri']);
    $image = theme('image', array('path' => $image_url));
    if($link = field_get_items('taxonomy_term', $topic, 'field_topic_box_link')){
      $path = ( substr($link, 0, 1) === "/") ? substr($link, 1) : $link;
      $image = l($image, $path, array('html' => true));
    }
    return $image;
  }
}