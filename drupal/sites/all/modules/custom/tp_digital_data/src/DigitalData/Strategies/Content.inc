<?php

class ddContent extends ddDefaultPage {

  public static function claim($path, $page) {
    // Claim node pages.
    if (preg_match('/^node\/[0-9]+/', $path) || preg_match('/^entity_iframe\/node\/[0-9]+/', $path)) {
	 return 1;
    }
    return FALSE;
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
	 foreach ($items as $item) {
	   $nids[] = $item['nid'];
	 }
	 $author_nodes = entity_load('node', $nids);
	 foreach ($author_nodes as $node) {
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

  protected function getNodefromPath() {
    // Returns a node for node pages and iframe pages
    $path = current_path();
    if (preg_match('/^node\/[0-9]+/', $path)) {
	 $node = menu_get_object();
    } elseif (preg_match('/^entity_iframe\/node\/[0-9]+/', $path)) {
	 $node = node_load(arg(2));
    }
    return $node;
  }

  public function build($page) {

    $data = array();
    $node = $this->getNodefromPath();
    $pageID = $node->nid;
    $element_impression = array();

    //authors
    $ids = array();
    if ($authors = field_get_items('node', $node, 'field_author')) {
	 foreach ($authors as $id) {
	   $ids[] = $id['nid'];
	 }

	 /* page: pageInfo: authors */
	 $author_entities = entity_load('node', $ids);
	 $author_names = array();
	 foreach ($author_entities as $author) {
	   $author_names[] = $author->title;
	 }
	 $author_names = implode(', ', $author_names);
	 $data['page']['pageInfo']['authors'] = $author_names;

	 /* page: pageInfo: author */
	 $author = reset($author_entities);
	 $author = $author->title;
	 $data['page']['pageInfo']['author'] = $author;
    }

    /* page: pageInfo: issueDate */
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
    if ($free_tags_instance != NULL) {

	 $free_tags = field_get_items('node', $node, 'field_free_tag');
	 $free_tag_names = array();

	 foreach ($free_tags as $free_tag) {
	   if (isset($free_tag['tid']) && is_numeric($free_tag['tid'])) {
		$tax_obj = taxonomy_term_load($free_tag['tid']);
		$free_tag_names[] = $tax = $tax_obj->name;
	   } else {
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
    $url = $base_url . '/' . $request_path;
    $site_section = explode('/', $request_path);
    $site_section = $site_section[0];

    //Permanent Title
    if ($permanent_title = field_get_items('node', $node, 'field_permanent_title')) {
	 $data['page']['pageInfo']['permanentTitle'] = $permanent_title[0]['value'];
    }

    // Field Campaign Type
    if (node_type_get_name($node) === "Campaign Page") {
	 $parent_campaign_nid = field_get_items('node', $node, 'field_campaign_reference');
	 $parent_campaign = node_load($parent_campaign_nid[0]['target_id']);
	 $cam_type_tid = field_get_items('node', $parent_campaign, 'field_campaign_type');
	 $campaign_type_term = taxonomy_term_load($cam_type_tid[0]['tid']);
	 $data['category']['campaignType'] = $campaign_type_term->name;
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

    //Field pageNumber for autoloaded content only
    $is_autoloaded = field_get_items('node' , $node , 'field_autoload');
    $is_autoloaded = $is_autoloaded[0]['value'];
    $autoloaded_content = array('openpublish_article' ,'video', 'video_playlist' , 'feature_article' , 'fresh_gallery');
    if (in_array($node->type , $autoloaded_content) && $is_autoloaded) {
        $data['page']['pageNumber'] = "page 1";
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

    if($show_influence) {
      $data['page']['pageInfo']['influenceBanner'] =  "Influence Banner";
    } else {
      $data['page']['pageInfo']['influenceBanner'] =  "No Influence Banner";
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

    //Time to read
    if($timeRead = field_get_items('node', $node, 'field_time_to_read')) {
      $data['page']['pageInfo']['timeToRead'] = $timeRead[0]['value'];
    }

     //Element Impression
    if (!empty($element_impression)) {
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
    $data['page']['pageInfo']['pageUrl'] = $url;
    $data['page']['pageInfo']['pageUrlAlias'] = $request_path;  //first part of the URL
    $data['page']['pageInfo']['referringURL'] = '%document.referrer';
    $data['page']['pageInfo']['siteSection'] = $site_section;
    $data['page']['pageInfo']['template'] = node_type_get_name($node);
    $data['page']['category']['primaryCategory'] = $this->categoryForContentType($node->type);
    $data += parent::build($page);

    return $data;
  }

}
