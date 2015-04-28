<?php

/**
 * Implements hook_preprocess_HOOK
 */
function fresh_preprocess_fresh_author_teaser(&$variables){

  if($account = $variables['author']){

    /* Format the image */
    if($image = field_get_items('node', $account, 'field_profile_photo')){
      $image = image_style_url('70x70_thumbnail', $image[0]['uri']);
      $variables['image'] =  $image;
    }

    /* Format the About Text */
    if($about = field_get_items('node', $account, 'body')){
      $about = $about[0]['summary'];
      $variables['about'] = $about;
    }

    /* Format the links */
    $options = array(
      'html' => true,
      'attributes' => array(
        'class' => array('btn', 'btn-secondary'),
        'target' => '_blank',
      )
    );
    $links = array();
    $bio_path = drupal_get_path_alias('node/'. $account->nid);
    $bio_options = array_merge_recursive($options, array('attributes' => array('id'=>'author_bio')));
    $links[] = l('Bio', $bio_path, $bio_options);
    $twitter = field_get_items('node', $account, 'field_follow_twitter');
    if($twitter[0]['url']){
      $links[] = l('<span class="icon i-twitter"></span>', $twitter[0]['url'], $options);
    }
    $google = field_get_items('node', $account, 'field_follow_google');
    if($google[0]['url']){
      $links[] = l('<span class="icon i-google_plusone_share"></span>', $google[0]['url'], $options);
    }
    $variables['links'] = $links;
  }

  if($date = $variables['published_at']){
    /* Format the date */
    $variables['date'] = date('M j, Y', $date);
  }

}