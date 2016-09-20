<?php

/**
 * Helper function for building the DDL for a node
 * @param bool $is_fbia if the call is coming from fbia module. Filter some analytics for fbia
 */
function tp_digital_data_build_ddl_content($node , $is_fbia){
  $data = array();
  $pageID = $node->nid;
  $element_impression = array();
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
  if ($topic_instance != NULL && $topics = field_get_items('node', $node, 'field_topic')) {
    $topic_names = array();
    foreach ($topics as $topic) {
      if (isset($topic['tid']) && is_numeric($topic['tid'])) {
        $tax_obj = taxonomy_term_load($topic['tid']);
        $topic_names[] = $tax = $tax_obj->name;
      } else {
        $topic_names[] = $topic['taxonomy_term']->name;
      }
    }
    $primary_topic = $topic_names[0];
    $topic_names = implode(',', $topic_names);
    $data['category']['primaryTopic'] = $primary_topic;
    $data['category']['topics'] = $topic_names;
  }

  //Field Series
  if ($field_series = field_get_items('node', $node, 'field_series')) {
    $series_tid = $field_series[0]['tid'];
    $series = taxonomy_term_load($series_tid);
    $series_name = $series ->name;
    $element_impression[] = "series nav";
    $data['category']['series'] = $series_name;
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
  global $theme;

  //Permanent Title
  if($permanent_title = field_get_items('node', $node, 'field_permanent_title')){
    $data['page']['pageInfo']['permanentTitle'] = $permanent_title[0]['value'];
  }

  //Field Sponsor
  $field_sponsor = field_info_instance('node', 'field_sponsored', $node->type);
  if ($field_sponsor != NULL) {
    $sponsor = field_get_items('node', $node, 'field_sponsored');
    $sponsor_term = taxonomy_term_load($sponsor[0]['tid']);
    if ($sponsor_term->name) {
      $data['page']['pageInfo']['sponsor'] = $sponsor_term->name;
    }
    $data['page']['pageInfo']['sponsored'] = ($sponsor_term->tid ? "" : "Not ") . "Sponsored";
  }

  //Field Topic Box
  if ($field_series = field_get_items('node', $node, 'field_topic_box')) {
    $element_impression[] = "topic box";
  }

  //Inline Replacements
  $show_influence = false;
  if($inline = field_get_items('node', $node, 'field_inline_replacements')) {
    foreach($inline as $i) {
      $load = entity_load('inline_content', array($i['target_id']));
      //Is there an influence Banner
      if(is_object($load[$i['target_id']]) && isset($load[$i['target_id']]->field_ic_tap_widget_type)) {
        if($tap_widget = field_get_items('inline_content', $load[$i['target_id']], 'field_ic_tap_widget_type')) {
          if($tap_widget[0]['value'] == 'influence_widget') {
            $show_influence = true;
          }
        }
      }
      //Embedded content
      if ($load[$i['target_id']]->type == 'nodes') {
        $element_impression[] = "embedded related story";
      }
      //Campaign promo
      if ($load[$i['target_id']]->type == 'campaign_promo') {
        $element_impression[] = "campaign promo";
      }
    }
  }
  if (!$is_fbia) {
    if($show_influence) {
      $data['page']['pageInfo']['influenceBanner'] =  "Influence Banner";
    } else {
      $data['page']['pageInfo']['influenceBanner'] =  "No Influence Banner";
    }
  }

  //Campaign reference
  if($campaignContent = field_get_items('node', $node, 'field_editor_campaign_reference')) {
    $campaign_id = $campaignContent[0]['target_id'];
    //Get the campaign title
    $campaign = node_load($campaign_id);
    $campaign_title = $campaign -> title;
    $data['page']['pageInfo']['campaignContent'] = $campaign_title;
    //Campaign related content carousel - automatically gets added to any node tagged with a campaign
    $element_impression[] = 'campaign content carousel';
  }
  elseif($theme == 'fresh') {
    //MOT is displayed if the node is not tagged with a campaign
    //MOT video is displayed automatically
    $element_impression[] = 'more on takepart - video';
    if ($field_related_stories = field_get_items('node', $node, 'field_related_stories')) {
      $element_impression[] = 'more on takepart - related';
      $element_impression[] = 'more on takepart - promoted';
      $element_impression[] = 'more on takepart - ad';
    }
  }

  //Time to read
  if($timeRead = field_get_items('node', $node, 'field_time_to_read')) {
    $data['page']['pageInfo']['timeToRead'] = $timeRead[0]['value'];
  }


  //Element Impression
  if (!empty($element_impression) && !$is_fbia) {
    $element_impression = implode(',', $element_impression);
    $data['page']['pageInfo']['elementImpressions'] = $element_impression;
  }

  //Gallery Analytics
  if ($node->type == 'fresh_gallery') {
    //Number of images
    if ($gallery_photos = field_get_items('node' , $node , 'field_fresh_photos')) {
      $slide_count = sizeof($gallery_photos);
      $data['page']['pageInfo']['gallery']['slideCount'] = $slide_count;
    }
    $data['page']['pageInfo']['gallery']['viewType'] = 'single page';
    $data['page']['pageInfo']['gallery']['shareType'] = 'slide';
  }

  $data['page']['pageInfo']['pageId'] = $pageID;
  $data['page']['pageInfo']['pageTitle'] = $node->title;
  $data['page']['pageInfo']['pageUrl'] = $full_path;
  $data['page']['pageInfo']['pageUrlAlias'] = $path;  //first part of the URL
  $data['page']['pageInfo']['siteSection'] = $site_section;
  $data['page']['pageInfo']['template'] = node_type_get_name($node);

  return $data;

}
