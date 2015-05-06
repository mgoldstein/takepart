<?php

/**
 * DDL for autoloaded nodes
 * This is temporary while we refactor tp_digital_data
 */


function tp_auto_scroll_build_ddl_event($id, $ddl){
  $data = array();

  $data['eventName'] = 'Page Auto Load';
  $data['eventInstanceID'] = $id;
  $data['eventInfo'] = $ddl;

  return $data;
}



function tp_auto_scroll_build_ddl_content($node){
  $data = array();
  $pageID = $node->nid;

  //authors
  $ids = array();
  if($authors = field_get_items('node', $node, 'field_author')){
    foreach($authors as $id){
      $ids[] = $id['nid'];
    }

    /* page: pageInfo: authors */
    $author_entities = entity_load('node', $ids);
    $author_names = array();
    foreach($author_entities as $author){
      $author_names[] = $author->title;
    }
    $author_names = implode(', ', $author_names);
    $data['page']['pageInfo']['authors'] = $author_names;

    /* page: pageInfo: author */
    $author = reset($author_entities);
    $author = $author->title;
    $data['page']['pageInfo']['author'] = $author;
  }

  /*page: pageInfo: issueDate */
  $publish_date = $node->published_at;
  $publish_date = date('Y/m/d', $publish_date);
  $data['page']['pageInfo']['issueDate'] = $publish_date;

  /* Category Section */

  //Field Topic
  $topic_instance = field_info_instance('node', 'field_topic', $node->type);
  if($topic_instance != NULL && $topics = field_get_items('node', $node, 'field_topic')){
    $primary_topic = $topics[0]['taxonomy_term']->name;
    $topic_names = array();
    foreach($topics as $topic){
      $topic_names[] = $topic['taxonomy_term']->name;
    }
    $topic_names = implode(',', $topic_names);
    $data['category']['primaryTopic'] = $primary_topic;
    $data['category']['topics'] = $topic_names;
  }

  //Field Series
  $series_instance = field_info_instance('node', 'field_series', $node->type);
  if($series_instance != NULL){
    $series_terms = field_get_items('node', $node, 'field_series');
    $series_names = array();
    foreach($series_terms as $series){
      $series = taxonomy_term_load($series['tid']);
      $series_names[] = $series->name;
    }
    $series_names = implode(',', $series_names);
    $data['category']['series'] = $series_names;
  }

  //Field Free Tags
  $free_tags_instance = field_info_instance('node', 'field_free_tag', $node->type);
  if($free_tags_instance != NULL){
    $free_tags = field_get_items('node', $node, 'field_free_tag');
    $free_tag_names = array();
    foreach($free_tags as $free_tag){
      $free_tag_names[] = $free_tag['taxonomy_term']->name;
    }
    $free_tag_names = implode(',', $free_tag_names);
    $data['category']['freeTags'] = $free_tag_names;
  }

  //URL (pageURL, pageUrlAlias, siteSection)
  global $base_url;

  $path = drupal_get_path_alias('node/'. $node->nid);
  $full_path = $base_url. '/'. $path;
  $site_section = explode('/', $path);
  $site_section = $site_section[0];

  //Permanent Title
  if($permanent_title = field_get_items('node', $node, 'field_permanent_title')){
    $data['page']['pageInfo']['permanentTitle'] = $permanent_title[0]['value'];
  }

  $data['page']['pageInfo']['pageId'] = $pageID;
  $data['page']['pageInfo']['pageTitle'] = $node->title;
  $data['page']['pageInfo']['pageUrl'] = $full_path;
  $data['page']['pageInfo']['pageUrlAlias'] = $path;  //first part of the URL
  $data['page']['pageInfo']['siteSection'] = $site_section;
  $data['page']['pageInfo']['template'] = node_type_get_name($node);

  return $data;

}