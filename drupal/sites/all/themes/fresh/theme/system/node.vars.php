<?php

/**
 * Implements hook_preprocess_node();
 */
function fresh_preprocess_node(&$variables, $hook) {

  /* Template suggestions for view mode.
  * Both Video and Article will use the same TPL & prepprocess function (autoload)
  */

  $node = $variables['node'];
  $variables['show_fb_comments'] = ($variables['status']) ? TRUE : FALSE;
  if ($variables['view_mode'] == 'full') {
    if (in_array($node->type , array('openpublish_article', 'video', 'video_playlist', 'feature_article', 'fresh_gallery'))) {
      //Feature Artcile will use its own template
      if ($node->type == 'feature_article') {
        $variables['theme_hook_suggestion'] = 'node__feature__article__' . $variables['view_mode'];
      } elseif ($node->type == 'fresh_gallery') {
        $variables['theme_hook_suggestion'] = 'node__fresh__gallery__' . $variables['view_mode'];
      } else {
        $variables['theme_hook_suggestion'] = 'node__autoload__' . $variables['view_mode'];
      }
      $function = __FUNCTION__ . '__autoload';
      if (function_exists($function)) {
        $function($variables, $hook);
      }
      /* will need ajax and form js for inline replacements */
      drupal_add_library('system', 'drupal.ajax');
      drupal_add_library('system', 'drupal.form');
    }
  }
  else {
    //inline-content mode
    $variables['theme_hook_suggestions'][] = 'node__' . $variables['view_mode'];
    $function = __FUNCTION__ . '__' . $variables['view_mode'];
    if (function_exists($function)) {
      $function($variables, $hook);
    }
  }
}

/**
 * Article & Video Node Preprocess
 * @see base/theme/node.vars.php
 * Implements hook_preprocess_node__NODE-TYPE()
 */
function fresh_preprocess_node__autoload(&$variables) {
  //determine the content type --artcile or video
  $node_type = $variables['node'] -> type;
  if ($node_type == 'openpublish_article') {
    $node_type = 'article';
  }
  /* Set variables for node--autoload.tpl.php (Full View) */
  if ($variables['view_mode'] == 'full') {

    /* Leader Ad */
    $variables['advertisement'] = theme('html_tag', array(
	 'element' => array(
	   '#tag' => 'div',
	   '#value' => '',
	   '#attributes' => array(
		'class' => 'mobile-article-ad',
    ))));

    /* Topic Box */
    if ($topic_box = field_get_items('node', $variables['node'], 'field_topic_box')) {
	 $variables['topic_box'] = theme('base_topic_box', array('tid' => $topic_box[0]['tid']));
    }

    /*Featured Link*/
    if ($node_type == 'feature_article') {
      if ($featured_link = field_get_items('node' , $variables['node'] , 'field_article_featured_link')) {
        $variables['field_article_featured_link'] = theme('fresh_featured_link' , $featured_link);
      }
      /* Feature Alternative Hero */
      if ($feature_alt_hero = field_get_items('node', $variables['node'], 'field_feature_hero')) {
        $variables['feature_alt_hero'] = theme('html_tag', array(
          'element' => array(
          '#tag' => 'div',
          '#attributes' => array(
            'class' => 'feature_alt_hero'
          ),
          '#value' => $feature_alt_hero[0]['value']
        )));
      }
    }

    /* Subheadline */
    if ($headline = field_get_items('node', $variables['node'], 'field_article_subhead')) {
	 $variables['headline'] = theme('html_tag', array(
	   'element' => array(
		'#tag' => 'div',
		'#attributes' => array(
		  'class' => 'headline'
		),
		'#value' => $headline[0]['value']
	 )));
    }

    /* Media */
    if ($node_type == 'article' || $node_type == 'feature_article') {
      if ($media = field_get_items('node', $variables['node'], 'field_article_main_image')) {
        $file = $media[0]['file'];

        $variables['media'] = '<div class="main-media">';
        if($node_type == 'feature_article') {
          //ambient video background for feature article
          if ($vid_bg = $variables['field_article_background_video']) {
            $vid_bg_src = $vid_bg[0]['uri'];
            $vid_bg_src = file_create_url($vid_bg_src);
            $variables['classes_array'][] = "has-videoBG";
            $variables['media'] .= '<div class = "feature-image has-videoBG" data-video-bg="' . $vid_bg_src . '">';
          }
          else {
            $variables['media'] .= '<div class = "feature-image">';
          }
        }
        if(module_exists('picture') && $node_type == 'feature_article') {
          //Featured articles require original file path
          $mapping = picture_mapping_load('feature_main_image');
          $file->breakpoints = picture_get_mapping_breakpoints($mapping);
          $file->attributes = array('class' => 'main-image');
          $file->alt = '';
          $variables['media'] .= theme('picture', (array) $file);
        } else {
          if($node_type == 'feature_article') {
            $image_url = file_create_url($file->uri);
            $variables['media'] .= theme('image', array(
              'path' => $image_url, 'attributes' => array(
                'class' => 'main-image'
              )
            ));
          } else {
            $derivative_uri = image_style_path('large', $file->uri);
            $img_vars['path']  = file_create_url($derivative_uri);
            $variables['media'] .= theme('lazyloader_image', $img_vars);
          }
        }
        if($node_type == 'feature_article') {
          $variables['media'] .= '</div>';
        }

        /* Render a caption if it exists */
        if ($caption = field_get_items('file', $file, 'field_media_caption')) {
         $caption = theme('html_tag', array(
           'element' => array(
             '#tag' => 'div',
             '#value' => $caption[0]['value'],
             '#attributes' => array(
               'class' => array('caption')
             )
           )
         ));
          $variables['media'] .= $caption . '</div>';
        }
      }
    }

    else if ($node_type == 'video') {
      $video = drupal_render(field_view_field('node', $variables['node'], 'field_video', 'playlist_full_page'));
      if (!empty($video)) {
        $variables['media'] = '<div class="main-media">';
        $variables['media'] .= $video;
        $variables['media'] .= '</div>';
      }
    }
    else if ($node_type == 'video_playlist') {
      $video_playlist = drupal_render(field_view_field('node', $variables['node'], 'field_video_list' , 'video_playlist'));
      if (!empty($video_playlist)) {
        $variables['media'] = '<div class="main-media">';
        $variables['media'] .= $video_playlist;
        $variables['media'] .= '</div>';
      }
    }

    /* Author */
    $author_vars = array();
    if ($authors = field_get_items('node', $variables['node'], 'field_author')) {
      foreach ($authors as $author) {
        $author_vars['author'][] = node_load($author['nid']);
	     }
    }
    $author_vars['published_at'] = $variables['node']->published_at;
    $author_vars['timetoread'] = field_get_items('node', $variables['node'], 'field_time_to_read');
    $author_vars['nid'] = $variables['node']->nid;
    $author_vars['type'] = $node_type;

    /*  FB Comment Count for the specifc node */
    $fb_comment_count = '';
    $url = url('node/' . $variables['node']->nid, array('absolute' => true));
    $fb_access_token = variable_get('facebook_access_token', '');
    $fb_graph_url = 'https://graph.facebook.com/v2.8/' . urlencode($url) . '?access_token=' . $fb_access_token;
    $json = json_decode(file_get_contents($fb_graph_url));
    if (isset($json) && !empty($json)) {
      $fb_comment_count = $json->share->comment_count;
      if ($fb_comment_count == 0) {
        $fb_comment_count = '';
      }
    }
    $author_vars['fb_comment_count'] = $fb_comment_count;

    if ($node_type == 'fresh_gallery') {
      $variables['author_teaser'] = theme('fresh_gallery_author_teaser', $author_vars);
    }
    else {
      $variables['author_teaser'] = theme('fresh_author_teaser', $author_vars);
    }

    /* Body */
    $body_display = array(
	 'label' => 'hidden',
	 'type' => 'text_with_inline_content',
	 'settings' => array(
	   'source' => 'field_inline_replacements'
	 )
    );
    $body = field_view_field('node', $variables['node'], 'body', $body_display);
    $variables['body'] = drupal_render($body);

    /* Series Navigation */
    if ($series = field_get_items('node', $variables['node'], 'field_series')) {
	 $entity = $variables['node'];
	 $series = (int) $series[0]['tid'];
	 $variables['series_navigation'] = theme('fresh_series_navigation', array('entity' => $entity, 'series' => $series));
    }

    /* Comments */
    $variables['comments'] = theme('fresh_fb_comments', array('url' => $url, 'nid' => $variables['node']->nid));

    $variables['fresh_fb_comments'] = ($variables['status']) ? TRUE : FALSE;

    /* Social Menu */
    $social_elements = array(
	 'share',
	 'action' => array(
	   'data-desktop-pos' => '0',
	 ),
	 'overlay'
    );

    $options = array('comments' => TRUE, 'overlay' => TRUE, 'class' => '');
    if (module_exists('tp_social_menu')) {
      //if disable is TRUE then exclude this
      if (!$variables['disable_social']) {
        $variables['social'] = theme('tp_social_menu', array('elements' => $social_elements, 'options' => $options));
      }
    }

    /* Enable AutoScroll */
    if (module_exists('tp_auto_scroll')) {
	 /* Don't need to run this for AJAX requested pages */
	 if (empty($_SERVER['HTTP_X_REQUESTED_WITH']) || strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) != 'xmlhttprequest') {
	   $variables['auto-scroll'] = tp_auto_scroll_pager($variables['node']);
	 }
    }

    /* Sponsored */
    $field_sponsored = field_get_items('node', $variables['node'], 'field_sponsored');
    $tid = $field_sponsored[0]['tid'];
    if ($tid) {
	 $variables['sponsored'] = theme('base_sponsor', array('tid' => $tid));
	 $variables['sponsor_disclosure'] = theme('base_sponsor_disclaimer', array('tid' => $tid));
    }
  }

  /* Sponsored */
  $field_sponsored = field_get_items('node', $variables['node'], 'field_sponsored');
  $tid = $field_sponsored[0]['tid'];
  if ($tid) {
    $variables['sponsored'] = theme('fresh_sponsor', array('tid' => $tid));
    $variables['sponsor_disclosure'] = theme('fresh_sponsor_disclaimer', array('tid' => $tid));
  }

  /* Campaign References */
  if($campaign_content = field_get_items('node', $variables['node'], 'field_editor_campaign_reference')){
    $cid = $campaign_content[0]['target_id'];
    //Grab the campaign info
    module_load_include('module' , 'tp_cic');
    $campaign_info = tp_cic_getCampInfo($cid);
    if (!empty($campaign_info)) {
      $variables['campaign_info']['nid'] = $cid;
      $variables['campaign_info']['url'] = isset($campaign_info['url']) ? $campaign_info['url'] : '';
      $variables['campaign_info']['banner'] = isset($campaign_info['banner']) ? $campaign_info['banner'] : '';
      $variables['campaign_info']['logo'] = isset($campaign_info['logo']) ? $campaign_info['logo'] : '';
      $variables['campaign_info']['vol'] = isset($campaign_info['vol']) ? $campaign_info['vol'] : '';
      $variables['campaign_info']['color'] = isset($campaign_info['color']) ? $campaign_info['color'] : '';
      $variables['campaign_info']['dark_logo'] = isset($campaign_info['dark_logo']) ? $campaign_info['dark_logo'] : '';

      //Add the carousel slider of promos in replace of MOT
      $more_block = module_invoke('tp_cic', 'block_view', 'tp_cic_bottom_promo');
    }
    else {
      //loading MOT if a sales camapign(suppress campaign visual is enabled on the campaign)
      $more_block = module_invoke('tp_more_on_takepart', 'block_view', 'more_on_takepart');
    }

  } else {
    //loading the module view from more on takepart if not campaign ref
    $more_block = module_invoke('tp_more_on_takepart', 'block_view', 'more_on_takepart');
  }
  //add if not empty
  if (!empty($more_block['content'])) {
    $variables['more_on_takepart'] = $more_block['content'];
  }

  /** Fresh Gallery  Specific fields **/
  if($node_type == 'fresh_gallery') {
    /* Json */
    $variables['gallery_json'] = tp_fresh_gallery_json($variables['node']);

    /* Gallery Prefix */
    if ($gallery_prefix = field_get_items('node' , $variables['node'] , 'field_fresh_gallery_prefix')) {
      $variables['gallery_prefix'] = theme('html_tag', array(
        'element' => array(
        '#tag' => 'div',
        '#attributes' => array(
          'class' => 'gallery-prefix'
        ),
        '#value' => $gallery_prefix[0]['value']
      )));
    }
  }

}

/**
 * Inline Content View Mode Preprocess
 * Implements hook_preprocess_node__VIEW-MODE()
 */
function fresh_preprocess_node__inline_content(&$variables) {
  global $base_url;
  $path = drupal_get_path_alias('node/' . $variables['nid']);
  $variables['url'] = $base_url . '/' . $path;

  // Replace the $title with the promo headline if there is one
  if ($field_promo_headline = field_get_items('node', $variables['node'], 'field_promo_headline')) {
    $variables['title'] = $field_promo_headline[0]['value'];
  }
  $variables['title'] .= _tp4_support_sponsor_flag($variables['node'], true);
}
