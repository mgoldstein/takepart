<?php

/**
 * Overrides theme_hook()
 * Returns a topic box image or link w/ image
 */
function base_base_topic_box(&$variables){
  $topic = taxonomy_term_load($variables['tid']);
  $term = $topic->vocabulary_machine_name;
  /* Series and Topic Boxes have different fields */
  /* Todo: consolidate down to two fields */
  if($term == 'topic_box'){
    $image_field_name = 'field_topic_box_image';
    $link_field_name = 'field_topic_box_link';
  }elseif($term == 'series'){
    $image_field_name = 'field_series_graphic_header';
    $link_field_name = 'field_series_graphic_header_link';
  }else{
    return;
  }
  if($image = field_get_items('taxonomy_term', $topic, $image_field_name)){
    $image_url = image_style_url('large', $image[0]['uri']);
    $image = theme('image', array('path' => $image_url, 'attributes' => array('class' => 'topic-box')));
    if($link = field_get_items('taxonomy_term', $topic, $link_field_name)){
      $link = $link[0]['url'];
      $path = ( substr($link, 0, 1) === "/") ? substr($link, 1) : $link;
    }
    else if ($term == 'series'){
      //If Series Graphic Header Link is empty, default to series page.
      $path = drupal_get_path_alias('taxonomy/term/' . $variables['tid']);
    }
    $image = l($image, $path, array('html' => true));
    $topic_box = theme('html_tag', array(
      'element' => array(
        '#tag' => 'div',
        '#value' => $image,
        '#attributes' => array(
          'class' => 'topic-box-wrapper',
        )
    )));
    return $topic_box;
  }
}
