<?php

class ddContent extends ddDefaultPage {

  public static function claim($path, $page) {
    // Claim node pages.
    return preg_match('/^node\/[0-9]+/', $path);
  }

  protected function termList($node, $field_name) {
    $items = field_get_items('node', $node, $field_name);
    $terms = array();
    if ($items !== FALSE && count($items) > 0) {
      foreach ($items as $item) {
        if (isset($item['taxonomy_term'])) {
          $terms[] = $item['taxonomy_term']->name;
        }
      }
    }
    return $terms;
  }

  protected function authorList($node, $field_name) {
    $items = field_get_items('node', $node, $field_name);
    $authors = array();
    if ($items !== FALSE && count($items) > 0) {
      $nids = array();
      foreach ($items as $item) { $nids[] = $item['nid']; }
      $author_nodes = entity_load('node', $nids);
      foreach($author_nodes as $node){
        $authors[] = $node->title;
      }
    }
    return $authors;
  }
  protected function categoryForContentType($type) {
    $categories = array(
      'openpublish_article' => 'Article',
      'campaign_page' => 'Campaign',
      'page' => 'Page',
    );
    return array_key_exists($type, $categories) ? $categories[$type] : $type;
  }

  public function build($page) {

    $data = array();
    $node = menu_get_object();

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
        if (isset($free_tag['tid']) && is_numeric($free_tag['tid'])) {
          $tax_obj = taxonomy_term_load($free_tag['tid']);
          $free_tag_names[] = $tax = $tax_obj->name;
        }
        else {
          $free_tag_names[] = $free_tag['taxonomy_term']->name;
        }
      }
      
      
      $free_tag_names = implode(',', $free_tag_names);
      $data['category']['freeTags'] = $free_tag_names;
    }

    //URL (pageURL, pageUrlAlias, siteSection)
    global $base_url;
    $request_path = request_path();
    $request_path = drupal_parse_url($request_path);
    $request_path = $request_path['path'];
    $url = $base_url. '/'. $request_path;
    $site_section = explode('/', $request_path);
    $site_section = $site_section[0];

    //Permanent Title
    if($permanent_title = field_get_items('node', $node, 'field_permanent_title')){
      $data['page']['pageInfo']['permanentTitle'] = $permanent_title[0]['value'];
    }

    //Field Sponsor
    $field_sponsor = field_info_instance('node', 'field_sponsored', $node->type);
    if($field_sponsor != NULL){
      $sponsor = field_get_items('node', $node, 'field_sponsored');
      $sponsor_term = taxonomy_term_load($sponsor[0]['tid']);
			if($sponsor_term->name) {
	      $data['page']['pageInfo']['sponsor'] = $sponsor_term->name;
			}
      $data['page']['pageInfo']['sponsored'] = ($sponsor_term->tid ? "":"Not ")."Sponsored";
    }

    $data['page']['pageInfo']['pageId'] = $pageID;
    $data['page']['pageInfo']['pageTitle'] = $node->title;
    $data['page']['pageInfo']['pageUrl'] = $url;
    $data['page']['pageInfo']['pageUrlAlias'] = $request_path;  //first part of the URL
    $data['page']['pageInfo']['siteSection'] = $site_section;
    $data['page']['pageInfo']['template'] = node_type_get_name($node);
    $data['page']['category']['primaryCategory'] = $this->categoryForContentType($node->type);
    $data += parent::build($page);

    return $data;
  }
}
