<?php
/**
 * @file
 * Output for FBIA feed page
 */

/**
 * Callback for fbia/feed
 */
function tp_fbia_page_feed() {
  //Get feed range from settings page
  $range = variable_get('tp_fbia_number_results_in_feed', 20);

  //Load updated nodes
  $fbia_nodes = new EntityFieldQuery();
  $fbia_nodes->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', array('openpublish_article', 'feature_article'))
    ->addTag('node_is_not_sponsored')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->propertyOrderBy('changed', 'DESC')
    ->range(0, $range);
  $fbia_nodes = $fbia_nodes->execute();
  $fbia_nodes = $fbia_nodes['node'];

   //Ads - Currently set to 4. The for loop below should get updated if we want to support more via admin.
   //Since we are displaying the same ad tags for all nodes, I'm adding this logic here to avoid redundancy.
    $ad_settings = array();
    for ($ad_ctr = 0; $ad_ctr <4; $ad_ctr++) {
      $ad_configuration = variable_get('tp_fbia_ads_config_'.$ad_ctr , '');
      if (!empty($ad_configuration['ad_slot'])) {
        $ad_settings[] = $ad_configuration;
      }
    }
    //Get the markup for Ads
    $fbia_ads = _tp_fbia_build_ads($ad_settings);

  //Items
  $items = array();
  foreach($fbia_nodes as $fbia_node) {
    $fbia_node = node_load($fbia_node->nid);
    $items[] = _tp_fbia_item_build($fbia_node, $fbia_ads);
  }

  //Build Date
  $buildDate = date('c', time());

  //Title
  $title = variable_get('fb_instant_articles_channel_title', variable_get('site_name', t('TakePart')));

  //Description
  $description = variable_get('tp_fbia_channel_description', variable_get('site_slogan', t('Stories That Matter, Action That Counts')));

  //Url
  global $base_url;

  //Return themed feed page
  $feed = theme('tp_fbia_feed_page', array(
    'title'       => $title,
    'description' => $description,
    'url'         => $base_url,
    'buildDate'   => $buildDate,
    'items'       => $items
  ));

  return $feed;
}

/**
 * Implements hook_query_TAG_alter()
 * Checks if sponsored field has a value
 */
function tp_fbia_query_node_is_not_sponsored_alter(QueryAlterableInterface $query) {
  $query->leftJoin('field_data_field_sponsored', 'o', 'node.nid = o.entity_id AND o.entity_type = :entity_type');
  $query->isNull('o.field_sponsored_tid');
}


/**
 * Delivery callback used to override html.tpl.php
 *
 * @param $page_callback_result
 */
function tp_fbia_html_feed($page_callback_result) {

  //Print results without using a theme template
  print $page_callback_result;

}

/**
 * Builds a feed item for the FBIA feed.rss page
 */
function _tp_fbia_item_build($node , $ad) {

  //Link
  global $base_url;
  $link = $base_url. '?cmpid=tp-rss-fbinstant';

  //Only 3 related content items are allowed
  $related_content_ctr = 0;
  $related_consolidated_links = '';

  //GUID
  $guid = $base_url. '/node/'. $node->nid;

  //Published
  $published = date('c', $node->published_at);

  //Authors
  $authors = array();
  if($author_refs = field_get_items('node', $node, 'field_author')) {
    foreach($author_refs as $author) {
      $author = node_load($author['nid']);
      $authors[] = $author->title;
    }
  }

  //Description
  if($description = field_get_items('node', $node, 'field_article_subhead')) {
    $description = $description[0]['value'];
  }


  //Content
  $content = _tp_fbia_item_content_build($node, $ad);

  //Return the themed item
  return theme('tp_fbia_feed_item', array(
    'title'       => $node->title,
    'link'        => $link,
    'guid'        => $guid,
    'pubDate'     => $published,
    'authors'      => $authors,
    'description' => $description,
    'content'     => $content
  ));

}

/**
 * Builds a feed item for the FBIA feed.rss page
 */
function _tp_fbia_item_content_build($node, $ad) {

  //URL
  global $base_url;
  $url_path = drupal_get_path_alias('node/'. $node->nid);
  $url = $base_url. '/'. $url_path;

  //Type
  switch ($node->type) {
    case 'openpublish_article':
      $type = 'article';
      break;
    case 'feature_article':
      $type = 'feature';
      break;
    default:
      $type = 'uh-oh';
  }

  //Subhead
  if($subhead = field_get_items('node', $node, 'field_article_subhead')) {
    $subhead = $subhead[0]['value'];
  }

  //Main Image
  if($main_image = field_get_items('node', $node, 'field_article_main_image')) {

    $main_image = file_load($main_image[0]['fid']);

    //caption
    if($image_caption = field_get_items('file', $main_image, 'field_media_caption')) {
      $image_caption = strip_tags($image_caption[0]['value']);
    }

    //path
    $image_url = image_style_url('landscape_main_image', $main_image->uri);

  }

  //Authors
  $authors = array();
  if($author_refs = field_get_items('node', $node, 'field_author')) {
    foreach($author_refs as $author) {
      $author = node_load($author['nid']);

      if($bio = field_get_items('node', $author, 'body')) {
        $bio = $bio[0]['summary'];
      }

      $authors[] = '<a>'. $author->title. '</a>'. $bio;
    }

  }

  //Body
  $ir_order = array();
  if ($body = field_get_items('node' , $node , 'body')) {
    $body = $body[0]['safe_value'];

    //Inline Replacements
    if ($inline_replacement = field_get_items('node' , $node , 'field_inline_replacements')) {
      //keep track of IR's postion and whether they qualify for FBIA
      $ir_order = _tp_fbia_inline_replacement_filter($inline_replacement);

      //Add domain & query params to the internal paths
      $body = tp_fbia_update_internal_links($body);

      //Insert Inline Replacement into body
      $body = _tp_fbia_search_and_replace($body, $ir_order);
    }
  }

  $related = tp_fbia_item_related_url($node);

  //Analytics Url
  $analytics_url = $base_url. '/fbia/'. $node->nid. '/analytics';

  return theme('tp_fbia_feed_item_content', array(
    'url'           => $url,
    'type'          => $type,
    'title'         => $node->title,
    'subhead'       => $subhead,
    'updatedDate'   => $node->changed,
    'pubDate'       => $node->published_at,
    'image_url'     => isset($image_url) ? $image_url : '',
    'image_caption' => isset($image_caption) ? $image_caption : '',
    'body'          => isset($body) ? $body : '',
    'authors'       => $authors,
    'related_title' => $related['title'],
    'related_url'   => $related['url'],
    'ads'           => $ad,
    'analytics_url' => $analytics_url
  ));

}


/*
 * Loops through the inline replacements allowed for FBIA feed
 */
function _tp_fbia_inline_replacement_filter($inline_replacement) {
  $ir_order = $inline_replacement;
  foreach ($inline_replacement as $key => $ir_id) {
    //Get the IR Type
    $ir_fields = entity_load('inline_content', $ir_id);
    $ir_fields = $ir_fields[$ir_id['target_id']];
    $ir_type = $ir_fields -> type;

    //Check whether the IR type will be used in FBIA feed.
    switch ($ir_type) {
      case 'social_embed':
      case 'youtube_embed':
        $feed_element = $ir_fields->field_ic_fia_embed['und'][0]['safe_value'];
        $ir_order[$key]['fbia_feed'] = _tp_fbia_social_embed($feed_element, $ir_type);
        $ir_order[$key]['type'] = $ir_type;
        break;
      case 'interactive_iframe':
        $ir_order[$key]['fbia_feed'] = _tp_fbia_interactive_iframe($ir_fields);
        $ir_order[$key]['type'] = $ir_type;
        break;
      case 'image':
        $ir_order[$key]['fbia_feed'] = _tp_fbia_inline_image($ir_fields);
        $ir_order[$key]['type'] = $ir_type;
        break;
      case 'video':
        $ir_order[$key]['fbia_feed'] = _tp_fbia_video($ir_fields->field_ic_video['und'][0]['nid']);
        $ir_order[$key]['type'] = $ir_type;
        break;
      case 'nodes':
        $ir_order[$key]['fbia_feed'] = _tp_fbia_related_articles($ir_fields->field_ic_content,$related_content_ctr,$related_consolidated_links);
        $ir_order[$key]['type'] = $ir_type;
        break;
    }
  }
  //Consolidate the related articles
  $ir_order = _tp_fbia_consolidate_related_articles($ir_order,$related_content_ctr,$related_consolidated_links);
  return $ir_order;
}

/*
 * Create the feed output for social_embed, youtube embed,
 */

function _tp_fbia_social_embed($ir_embed, $ir_type) {
  $NL = "\r\n";
  $feed  = '<figure class="op-social">' . $NL;
  if ($ir_type == 'social_embed') {
    $feed .= '  <iframe>' . $NL;
    $feed .= '    ' . $ir_embed . $NL;
    $feed .= '  </iframe>' . $NL;
  }
  elseif($ir_type == 'youtube_embed') {
    //remove whitespace from beginning and end of embed code
    $ir_embed = trim($ir_embed);
    //Youtube Embed code should be wrapped with iframe
    if (strpos($ir_embed, '<iframe') !== 0) {
      return false;
    }
    //remove the width and height attributes
    $ir_youtube_embed = preg_replace('/(width|height)=\"\d*\"\s/', '', $ir_embed);
    $feed .= '  ' . $ir_youtube_embed . $NL;
  }
  $feed .= '</figure>';

  return $feed;
}

/*
 * Create the feed output for the interactive iframe
 */
function _tp_fbia_interactive_iframe($ir_field) {
  $NL = "\r\n";
  $ir_embed = $ir_field->field_ic_fia_embed['und'][0]['safe_value'];
  //remove whitespace from beginning and end of embed code
  $ir_embed = trim($ir_embed);
  //Embed code should be wrapped with iframe
  if (strpos($ir_embed, '<iframe') !== 0) {
    return false;
  }
  //Add no-magin class
  $ir_iframe_embed = substr_replace($ir_embed, '<iframe class="no-margin"', 0 , 7);
  //Remove the wdith attributes
  //$ir_iframe_embed = preg_replace('/width=\"[0-9]*\"/', '' , $ir_iframe_embed);

  $feed  = '<figure class="op-interactive">' . $NL;
  $feed .= '  ' . $ir_iframe_embed . $NL;
  if(!empty($ir_field->field_ic_citation)) {
    $ir_iframe_caption = $ir_field->field_ic_citation['und'][0]['safe_value'];
    $feed .= '  <figcaption>' . $ir_iframe_caption . '</figcaption>' .$NL;
  }
  $feed .= '</figure>';
  return $feed;

}

/*
 * Create the feed output for the interactive iframe
 */
function _tp_fbia_inline_image($ir_field) {
  $NL = "\r\n";
  if ($ir_image = $ir_field->field_ic_image['und'][0]['fid']) {
    $ir_image = file_load($ir_image);
    //Using the large_reponsive_mobile image style.
    //This can be removed if we ever move toward high res images and tap-to-exapnd for inline replacements
    $ir_image_src = image_style_url('large_responsive_mobile', $ir_image->uri);
    $feed  = '<figure>' . $NL;
    $feed .= '  <img src="' . $ir_image_src . '"/>' . $NL;
    if ($ir_image_caption = $ir_image->field_media_caption) {
      $ir_image_caption = $ir_image_caption['und'][0]['safe_value'];
      $feed .= '  <figcaption>' . $ir_image_caption . '</figcaption>' . $NL;
    }
    $feed .= '</figure>';
    return $feed;
  }
  else {
    return false;
  }
}

/*
 * Create the feed output for the related articles inside cotent area
 */
function _tp_fbia_related_articles($ir_fields, &$related_content_ctr, &$related_consolidated_links) {
  $NL = "\r\n";

  $related_content_links = array();
  $ir_fields = $ir_fields['und'];
  //Only 3 related links allowed
  if ($related_content_ctr > 2) {
      return false;
  }
  foreach ($ir_fields as $val) {
    if ($related_content_ctr > 2) {
      break;
    }
    $ir_nid = $val['nid'];
    //Grab absolute path and add the query param
    $url = l('', 'node/'.$ir_nid, array('query' => array('cmpid' => 'tp-rss-fbinstant') ,'absolute' => TRUE));
    $related_content_links[] = $url;
    $related_consolidated_links .= '  <li>' . $url . '</li>' . $NL;
    $related_content_ctr++;
  }
  return $related_content_links;

}

/*
 * Create the feed output for the related articles inside content
 */
function _tp_fbia_consolidate_related_articles($ir_fields, &$related_content_ctr, &$related_consolidated_links) {

  $NL = "\r\n";
  $related_ctr = 0;
  $feed = '<ul class="op-related-articles" title="RELATED">' . $NL;
  $feed .= $related_consolidated_links;
  $feed .= '</ul>' . $NL;
  foreach ($ir_fields as $key => $val) {
    if (isset($val['type']) && $val['type'] == 'nodes') {
      //The first embedded content gets all the links/feed
      if ($related_ctr == 0) {
        $ir_fields[$key]['fbia_feed'] = $feed;
      }
      else {
        $ir_fields[$key]['fbia_feed'] = FALSE;
      }
      $related_ctr ++;
    }
  }
  //Reset the related article global variables to keep track of the next node
  $related_consolidated_links = '';
  $related_content_ctr = 0;
  return $ir_fields;
}

/*
 * Create the feed output for video
 */
function _tp_fbia_video($ir_nid) {
  $NL = "\r\n";
  $node = node_load($ir_nid);
  //Get the original url
  $vid_url = $node->field_video['und'][0]['uri'];
  $vid_url = file_create_url($vid_url);
  $vid_title = $node->title;
  //JW player hosted videos
  if (strpos($vid_url , 'jwplatform') !== FALSE) {
    $feed  = '<figure>' . $NL;
    $feed .= '  <video>' . $NL;
    $feed .= '    <source src="' . $vid_url . '" type="video/mp4" />' . $NL;
    $feed .= '  </video>' . $NL;
    $feed .= '  <figcaption>' . $vid_title . '</figcaption>' . $NL;
    $feed .= '</figure>' . $NL;
  }
  else if (strpos($vid_url , 'youtube') !== FALSE) {
    //Youtube hosted video uses the embedded code
    $embed_code = $node->field_video['und'][0]['tp_videos_metadata']->embed_code;
    //remove width/height params
    $embed_code = preg_replace('/(width|height)=\"\d*\"\s/', '', $embed_code);
    //remove ?feature=oembed query param
    $embed_code = str_replace('?feature=oembed', '', $embed_code);

    $feed  = '<figure class="op-social">' . $NL;
    $feed .= '  ' . $embed_code . $NL;
    $feed .= '</figure>';
  }
  else {
    return fasle;
  }
  return $feed;
}

/*
 * Replace all instances of <hr> with the inline replcament feed elements
 * @param $search - the string that contains <hr>
 * @param $replace - array of inline replacements to replace <hr>
 */
function _tp_fbia_search_and_replace($search,$replace) {
  $offset = 0;
  $ctr = 0;
  while(($pos = strpos($search, '<hr>' , $offset)) !== FALSE) {
    $offset = $pos +1;
    //Replace the qualified <hr> with the feed IR
    if ($replace[$ctr]['fbia_feed']) {
      $search = substr_replace($search, $replace[$ctr]['fbia_feed'], $pos , 4);
    }
    else {
      //Remove the <hr>
      $search = substr_replace($search, '', $pos , 4);
    }
    $ctr ++;
  }
  return $search;
}

/**
 * Get the related url
 */
function tp_fbia_item_related_url($node) {
  //Get the sponsored node in the same topic within 90 days
  $related = tb_fbia_related_url_topic($node);

  $n = array();
  if(isset($related['node']) && !empty($related['node'])) {
    foreach($related['node'] AS $tmpnode) {
      $n = node_load($tmpnode->nid);
      //There should only be 1 returned so it is ok to just break;
      break;
    }
  }

  if(empty($n)) {
    //Go get a new node
    $related = tb_tbia_related_url_sponsored();
    if(isset($related['node']) && !empty($related['node'])) {
      foreach($related['node'] AS $tmpnode) {
        $n = node_load($tmpnode->nid);
        //It is ok to break because only 1 is returned
        break;
      }
    }
  }

  //Return the node found if it exists
  if(!empty($n)) {
    return array('url' => url('node/'.$n->nid, array('absolute' => TRUE)), 'title' => $n->title);
  } else {
    //This means there is no sponsored content that exists that is not good
    return array('url' => '', 'title' => '');
  }
}


/**
 * Returns a node of the most recent sponsored content within a specific topic
 */
function tb_fbia_related_url_topic($node) {
  //Grabbing the most recent published article/feature that is sponsored
  //AND has the same topic
  $related = new EntityFieldQuery();
  $related->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', array('openpublish_article', 'feature_article'))
    ->addTag('related_url_topic')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->addMetaData('node', $node)
    ->range(0, 1);
  $related = $related->execute();
  return $related;
}

/**
 * Implements hook_query_TAG_alter()
 * Gets the node that is sponsored and correct topic
 */
function tp_fbia_query_related_url_topic_alter(QueryAlterableInterface $query) {
  $node = $query->getMetaData('node');
  if($topic = field_get_items('node', $node, 'field_topic')) {
    $topic = $topic[0]['tid'];
  }
  //Only get content that was published in past 90 days
  $time_check = 24 * 60 * 60 * 90;
  $query->join('publication_date', 'pa', 'node.nid = pa.nid AND (UNIX_TIMESTAMP() - pa.published_at) < '.$time_check);
  $query->join('field_data_field_topic', 't', 'node.nid = t.entity_id AND t.entity_type = :entity_type AND t.delta = 0 AND t.field_topic_tid = '.$topic);
  $query->join('field_data_field_sponsored', 's', 'node.nid = s.entity_id AND s.entity_type = :entity_type');
  $query->orderBy('pa.published_at', 'DESC');
}

/**
 * Returns a node of the most recent sponsored content
 */
function tb_tbia_related_url_sponsored() {
  //Go get a new node
  $related = new EntityFieldQuery();
  $related->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', array('openpublish_article', 'feature_article'))
    ->addTag('related_url_sponsored')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->range(0, 1);
  $related = $related->execute();
  return $related;
}

/**
 * Implements hook_query_TAG_alter()
 * Gets the node that is just sponsored
 */
function tp_fbia_query_related_url_sponsored_alter(QueryAlterableInterface $query) {
  $query->join('publication_date', 'pa', 'node.nid = pa.nid');
  $query->join('field_data_field_sponsored', 's', 'node.nid = s.entity_id AND s.entity_type = :entity_type');
  $query->orderBy('pa.published_at', 'DESC');
}

/*
 * Builds the feed element for Ads
 */
function _tp_fbia_build_ads ($fbia_ads) {
  $feed = '';
  $NL = "\r\n";
  $feed .= '<section class="op-ad-template">' . $NL;
  foreach ($fbia_ads as $key) {
    $ad_slot = $key['ad_slot'];
    $gpd_id = $key['gpd_id'];
    $ad_width = $key['ad_width'];
    $ad_height = $key['ad_height'];
    $multiple_ads = $key['multiple_ads_check'];

    $feed .= '  <figure class="op-ad' . ($multiple_ads ? ' op-ad-default' : '') . '">' . $NL;
    $feed .= '    <iframe height ="' . $ad_height . '" width="' . $ad_width . '">' . $NL;
    $feed .= '      ' . _tp_fbia_ad_load_js() . $NL;
    $feed .= '      ' . _tp_fbia_ad_define_slot($ad_width, $ad_height, $ad_slot, $gpd_id) . $NL;
    $feed .= '      <div id="' . $gpd_id . '">' . $NL;
    $feed .= '        ' . _tp_fbia_ad_display($gpd_id);
    $feed .= '      </div>' . $NL;
    $feed .= '    </iframe>' .$NL;
    $feed .= '  </figure>' .$NL;
  }
  $feed .= '</section>';
  return $feed;
}

/*
 * Markup to Load the Google services
 */
function _tp_fbia_ad_load_js() {
  $src =  '(function() {
          var useSSL = \'https:\' == document.location.protocol;
          var src = (useSSL ? \'https:\' : \'http:\') +
            \'//www.googletagservices.com/tag/js/gpt.js\';
          document.write(\'<scr\' + \'ipt src="\' + src + \'"><\' +\'/scr\' + \'ipt>\');
        })();';

  $markup = theme('html_tag', array(
  'element' => array(
      '#tag' => 'script',
      '#attributes' => array(
        'type' => 'text/javascript'
      ),
      '#value' => $src
    )
  ));
  return $markup;
}

/*
 * Markup to define Ad Slot
 */
function _tp_fbia_ad_define_slot($width, $height, $slot, $gpd_id) {
  $src = "googletag.defineSlot('/4355895/"  . $slot . "', [" . $width . "," . $height . "], '" . $gpd_id . "').addService(googletag.pubads());
        googletag.enableServices();";

  $markup = theme('html_tag', array(
  'element' => array(
      '#tag' => 'script',
      '#attributes' => array(
        'type' => 'text/javascript'
      ),
      '#value' => $src
    )
  ));

  return $markup;
}

/*
 * Markup for displaying the Ad
 */
function _tp_fbia_ad_display($gpd_id) {
  $src = "googletag.display('" . $gpd_id . "');";
  $markup = theme('html_tag', array(
  'element' => array(
      '#tag' => 'script',
      '#attributes' => array(
        'type' => 'text/javascript'
      ),
      '#value' => $src
    )
  ));

  return $markup;
}

/*
 * Update the internal links to include the domain name if link value doens't start with http, //
 * OR it doesn't include takepart.com.
 * Also append any takepart link with CMPID query param.
 */
function tp_fbia_update_internal_links ($body) {
  $match = array();
  $links = preg_match_all('/href=["\']?([^"\'>]+)["\']?/', $body, $match);
  global $base_url;
  if (count($match)) {
    foreach ($match[1] as $link_val) {

      $cmpid = strpos($link_val, '?') === FALSE ? '?cmpid=tp-rss-fbinstant' : '&cmpid=tp-rss-fbinstant';
      //This logic should catch links created using the internal link option in the wysiwyg
      if (substr($link_val, 0, 4) != 'http' && substr($link_val, 0, 2) != '//' && strpos($link_val, "takepart.com") === FALSE) {
        //Prepend the domain name to the link & append the query param
        $new_link_val = '"' . $base_url . $link_val . $cmpid . '"';
        $link_val = '"' . $link_val . '"';
        //Catch any duplicate links in the body
        if (strpos($body, $new_link_val) === FALSE) {
          $body = str_replace($link_val, $new_link_val, $body);
        }
      }
      else if (strpos($link_val, "takepart.com") !== FALSE) {
        //The else should catch any takepart.com links that have been created as absolute in the wysiwyg
        $new_link_val = '"' . $link_val . $cmpid . '"';
        $link_val = '"' . $link_val . '"';
        if (strpos($body, $new_link_val) === FALSE) {
          $body = str_replace($link_val, $new_link_val, $body);
        }
      }
    }
  }

  return $body;
}
