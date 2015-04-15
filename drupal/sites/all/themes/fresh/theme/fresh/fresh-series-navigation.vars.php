<?php

/**
* Implements theme_preprocess_fresh_series_navigation()
*/
function fresh_preprocess_fresh_series_navigation(&$variables){
  /* Use the node to determine the previous and next articles and supply that to the template file */
  $timestamp = $variables['entity']->created;

  /* Get the previous article */
  if($previous = _series_navigation_get_article('previous', $timestamp, $variables['series'])){
    $variables['prev_title'] = _series_navigation_get_title($previous);
    $variables['prev_link'] = _series_navigation_get_path($previous);
  }

  /* Get the next article */
  if($next = _series_navigation_get_article('next', $timestamp, $variables['series'])){
    $variables['next_title'] = _series_navigation_get_title($next);
    $variables['next_link'] = _series_navigation_get_path($next);
  }

  /* Topic Box */
   $variables['topic_box'] = theme('base_topic_box', array('tid' => $variables['series']));
}


/**
 * Function to grab the next/prev article
 */
function _series_navigation_get_article($type, $timestamp, $series){
  /* Which content types to reference */
  $bundles = array(
    'openpublish_article',
    'feature_article',
    'video',
    'video_playlist'
  );
  /* Settings for Type */
  if($type == 'previous'){
    $direction = 'DESC';
    $operator = '<';
  }else{
    $direction = 'ASC';
    $operator = '>';
  }

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $bundles)
    ->propertyCondition('status', 1)
    ->propertyCondition('created', $timestamp, $operator)
    ->fieldCondition('field_series', 'tid', $series, '=')
    ->propertyOrderBy('created', $direction)
    ->range(0, 1);
  $results = $query->execute();
  $article = current($results['node']);
  if(!empty($article) && $article->nid){
    return $article->nid;
  }

}

/**
 * Function to grab the title w/o loading the entire node
 */
function _series_navigation_get_title($nid){
  return db_query('SELECT title FROM {node} WHERE nid = :nid', array(':nid' => $nid))->fetchField();
}

/**
 * Function to grab the path
 */
function _series_navigation_get_path($nid){
  global $base_url;
  $path = drupal_get_path_alias('node/'. $nid);
  return $base_url. '/'. $path;
}