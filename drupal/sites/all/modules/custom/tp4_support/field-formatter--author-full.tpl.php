<?php
  $authors = '';
  $number_of_authors = count($variables['items']);
  $authors .= '<span' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $authors .= '<span class="byline-author"' . $variables['item_attributes'][$delta] . '>';
    $author_node = node_load($item['nid']);
    $authors .= $author_node->title;
    $authors .= '</span>';
    // add commas for lists of 3 or greater ($delta is zero-indexed)
    $authors .= ($number_of_authors > 2 && $delta < $number_of_authors - 2 ) ? ', ' :'';
    // add 'and' for lists of 2 or greater ($delta is zero-indexed)
    $authors .= ($number_of_authors > 1 && $delta == $number_of_authors - 2 ) ? 'and ' :'';
  }
  $authors .= '</span>';
  // Render the top-level div.
  $output .= '<div class="date">'. date('F d, Y',$entity->created). '</div>';
  $output .= '<div class="byline author ' . $variables['classes'] . '"' . $variables['attributes'] . '>By ' . $authors . '</div>';

  // Get first Author image  field_profile_photo
  $author_node = node_load($variables['items'][0]['nid']);

  $output .= '<div class="bio-inner">';
    $thumb = file_load($author_node->field_profile_photo['und'][0]['fid']);
    $output .= '<div class="profile-photo"><img src="'. image_style_url('thumbnail_v2', $thumb->uri). '"></div>';  //TODO: what image style are authors using?
    $author_path = drupal_get_path_alias('node/'. $author_node->nid);
    $output .= '<div class="bio">'. $author_node->body['und'][0]['value'];
      $output .= '<div class="more-links">';
        $output .= l('full bio', $author_path, array('attributes' => array('class' => array('more'))));
        $output .= l($author_node->field_follow_twitter['und'][0]['title']. '<span class="social-twitter-black"></span>', $author_node->field_follow_twitter['und'][0]['url'], array('html' => true, 'attributes' => array('target' => '_blank', 'class' => array('more'))));
    $output .= '</div></div>';
  $output .= '</div>';

  print $output;

  ?>