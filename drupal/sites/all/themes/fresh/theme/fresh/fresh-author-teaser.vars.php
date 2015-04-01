<?php

/**
 * Implements hook_preprocess_HOOK
 */
function fresh_preprocess_fresh_author_teaser(&$variables){

  if($account = $variables['author']){

    /* Format the image */
    $variables['image'] =  'image';

    /* Format the headline */
    $variables['headline'] = 'headline';

    /* Format the links */
    $variables['links'] = 'links';
  }
  if($date = $variables['date']){
    /* Format the date */
    $variables['date'] = $date;
  }

}