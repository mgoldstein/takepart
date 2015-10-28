<?php

/**
 * Sailthru Feed Page
 */
function pm_sailthru_feed(){

  //Get the variables that makeup the feed
  $range = variable_get('pm_sailthru_range', '100');
  $order = variable_get('pm_sailthru_types', 'DESC');
  $types = variable_get('pm_sailthru_types', array());

  //Create the query
  $query = new EntityFieldQuery();
  $results = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $types, 'IN')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->propertyOrderBy('created', $order)
    ->range(0,$range);

  $results = $query->execute();
  $results = array_keys($results['node']);
  $results = node_load_multiple($results);

  //Generate data
  foreach($results as $key => $result){

    //Title - content title
    $title = $result->title;

    //Url - full url to content
    global $base_url;
    $url = $base_url. '/'. drupal_get_path_alias('node/'. $result->nid);

    //tags [array] - contents of the sailthru.tags metatag
    $free_tags_instance = field_info_instance('node', 'field_free_tag', $result->type);
    if($free_tags_instance != NULL) {

      $free_tags = field_get_items('node', $result, 'field_free_tag');
      $free_tag_names = array();

      foreach ($free_tags as $free_tag) {
        if (isset($free_tag['tid']) && is_numeric($free_tag['tid'])) {
          $tax_obj = taxonomy_term_load($free_tag['tid']);
          $free_tag_names[] = $tax = $tax_obj->name;
        }
        else {
          $free_tag_names[] = $free_tag['taxonomy_term']->name;
        }
      }
      $tags = implode(',', $free_tag_names);
    }


    //description - content subhead
    $sub_head = field_info_instance('node', 'field_article_subhead', $result->type);
    if($sub_head != NULL) {
      $sub_head = field_get_items('node', $result, 'field_article_subhead');
      $description = $sub_head[0]['value'];
    }

    //author - author, comma-delimited if multiple
    if($field_authors = field_get_items('node', $result, 'field_author')){
      $author_ids = array();
      foreach ($field_authors as $field_author) {
        $author_ids[] = $field_author['nid'];
      }
      $author_nodes = entity_load('node', $author_ids);
      foreach($author_nodes as $author_node){
        $authors[] = $author_node->title;
      }
      $author = implode(', ', $authors);
    }

    //image - full path to content image
    if($field_main_image = field_get_items('node', $result, 'field_author')){
      if($field_main_image = field_get_items('node', $result, 'field_article_main_image')){
        $field_main_image = file_load($field_main_image[0]['fid']);
        $image = file_create_url($field_main_image->uri);
      }
    }

    ///primary-topic - primary topic of content (should only be one)
    $topic_instance = field_info_instance('node', 'field_topic', $result->type);
    if($topic_instance != NULL && $topics = field_get_items('node', $result, 'field_topic')){
      $topic_names = array();
      foreach($topics as $topic){
        if (isset($topic['tid']) && is_numeric($topic['tid'])) {
          $tax_obj = taxonomy_term_load($topic['tid']);
          $topic_names[] = $tax = $tax_obj->name;
        }
        else {
          $topic_names[] = $topic['taxonomy_term']->name;
        }
      }
      $primary_topic = $topic_names[0];
    }

    //content-type - type of content (e.g. action, video, feature, article)
    $content_type = $result->type;

    //sponsor - sponsor/promoted info
    $field_sponsor = field_info_instance('node', 'field_sponsored', $result->type);
    if($field_sponsor != NULL){
      $field_sponsor = field_get_items('node', $result, 'field_sponsored');
      $sponsor_term = taxonomy_term_load($field_sponsor[0]['tid']);
      if($sponsor_term->name) {
        $sponsor = $sponsor_term->name;
      }
    }

    $content[] = array(
      'title' => $title,
      'url' => $url,
      'tags' => (isset($tags) ? $tags : ''),
      'description' => (isset($description) ? $description : ''),
      'author' => (isset($author) ? $author : ''),
      'image' => (isset($image) ? $image : ''),
      'primary-topic' => (isset($primary_topic) ? $primary_topic : ''),
      'content-type' => $content_type,
      'sponsor' => (isset($sponsor) ? $sponsor : ''),
    );
  }

  /* Return encoded json */
  print drupal_json_encode(array('content' => $content));
  drupal_exit();

  return 'testing';
}