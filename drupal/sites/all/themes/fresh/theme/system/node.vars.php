<?php

/**
 * Implements hook_preprocess_node();
 */
function fresh_preprocess_node(&$variables, $hook) {

  /* Template suggestions for view mode */
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['view_mode'];

  /* Run view-mode-specific preprocess functions */
  $function = __FUNCTION__ . '__' . $variables['view_mode'];
  if (function_exists($function)) {
    $function($variables, $hook);
  }

  /* Run node-type-specific preprocess functions */
  $function = __FUNCTION__ . '__' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}

/**
 * Article Node Preprocess
 * @see base/theme/node.vars.php
 * Implements hook_preprocess_node__NODE-TYPE()
 */
function fresh_preprocess_node__openpublish_article(&$variables) {

  /* Set variables for node--openpublish-article.tpl.php (Full View) */
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
    if ($media = field_get_items('node', $variables['node'], 'field_article_main_image')) {
	 $file = $media[0]['file'];
	 $image_url = image_style_url('large', $file->uri);
	 $variables['media'] = '<div id="main-image">';
	 $variables['media'] .= theme('image', array(
	   'path' => $image_url, 'attributes' => array(
		'class' => 'main-media'
	     )
	   )
	 );

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

    /* Author */
    $author_vars = array();
    if ($authors = field_get_items('node', $variables['node'], 'field_author')) {
	 foreach ($authors as $author) {
	   $author_vars['author'][] = node_load($author['nid']);
	 }
    }
    $author_vars['published_at'] = $variables['node']->published_at;
    $variables['author_teaser'] = theme('fresh_author_teaser', $author_vars);

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
    $url = url('node/' . $variables['node']->nid, array('absolute' => true));
    $variables['comments'] = theme('fresh_fb_comments', array('url' => $url));

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

    //loading the module view from more on takepart
    $more_block = module_invoke('tp_more_on_takepart', 'block_view', 'more_on_takepart');

    //add if empty
    if (!empty($more_block['content'])) {
	 $variables['more_on_takepart'] = $more_block['content'];
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
