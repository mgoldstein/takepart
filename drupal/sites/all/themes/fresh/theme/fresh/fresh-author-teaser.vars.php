<?php

/**
 * Implements hook_preprocess_HOOK
 */
function fresh_preprocess_fresh_author_teaser(&$variables){

	foreach($variables['author'] as $account) {

		$author = array();

    /* Format the image */
    if($image = field_get_items('node', $account, 'field_profile_photo')){
      $image = image_style_url('70x70_thumbnail', $image[0]['uri']);
      $author['image'] =  $image;
    }

    /* Format the About Text */
    if($about = field_get_items('node', $account, 'body')){
      $about = $about[0]['summary'];
      $author['about'] = $about;
    }

    /* Format the links */
    $options = array(
      'html' => true,
      'attributes' => array(
        'class' => array('btn', 'btn-secondary'),
      )
    );
    $links = array();
    $bio_path = drupal_get_path_alias('node/'. $account->nid);
    $bio_options = array_merge_recursive($options, array('attributes' => array('id'=>'author_bio')));
    $links[] = l('Bio', $bio_path, $bio_options);

    // Social links target a new window
    $options['attributes']['target'] = '_blank';

    $twitter = field_get_items('node', $account, 'field_follow_twitter');
    if($twitter[0]['url']){
      $links[] = l('<span class="icon i-twitter"></span>', $twitter[0]['url'], $options);
    }
    $google = field_get_items('node', $account, 'field_follow_google');
    if($google[0]['url']){
      $links[] = l('<span class="icon i-google_plusone_share"></span>', $google[0]['url'], $options);
    }
    $author['links'] = $links;

		$variables['authors'][] = $author;
  }

  if($date = $variables['published_at']){
    /* Format the date */
    $variables['date'] = date('M j, Y', $date);
  }

	if($variables['timetoread']) {

		$str_time = preg_replace("/^([\d]{1,2})\:([\d]{2})$/", "00:$1:$2", $variables['timetoread'][0]['value']);

		sscanf($str_time, "%d:%d:%d", $hours, $minutes, $seconds);

		$variables['timetoreadminutes'] = $hours * 60 + $minutes;
	}

	$variables['url'] = url('node/'.$variables['nid']);

}
