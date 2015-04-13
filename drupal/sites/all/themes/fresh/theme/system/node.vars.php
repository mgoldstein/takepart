<?php

/**
 * Implements hook_preprocess_node();
 */
function fresh_preprocess_node(&$variables, $hook){

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
function fresh_preprocess_node__openpublish_article(&$variables){

  /* Set variables for node--openpublish-article.tpl.php (Full View)*/
  if($variables['view_mode'] == 'full'){

    /* Leader Ad */
    $variables['advertisement'] = theme('html_tag', array(
      'element' => array(
        '#tag' => 'div',
        '#value' => '',
        '#attributes' => array(
          'class' => 'mobile-article-ad',
    ))));

    /* Topic Box */
    if($topic_box = field_get_items('node', $variables['node'], 'field_topic_box')){
      $variables['topic_box'] = theme('base_topic_box', array('tid' => $topic_box[0]['tid']));
    }

    /* Subheadline */
    if($headline = field_get_items('node', $variables['node'], 'field_article_subhead')){
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
    if($media = field_get_items('node', $variables['node'], 'field_article_main_image')){
      $image_url = image_style_url('large', $media[0]['file']->uri);
      $variables['media'] =  theme('image', array('path' => $image_url, 'attributes' => array('class' => 'main-media')));
    }

    /* Author */
    $author_vars = array();
    if($authors = field_get_items('node', $variables['node'], 'field_author')){
      $author_vars['author'] =  node_load($authors[0]['nid']);
    }
    $author_vars['published_at'] = $variables['node']->published_at;
    $variables['author_teaser'] = theme('fresh_author_teaser', $author_vars);

    /* Body */
    $body_display = array(
      'label' => 'hidden',
      'type'  => 'text_with_inline_content',
      'settings' => array(
        'source' => 'field_inline_replacements'
      )
    );
    $body = field_view_field('node', $variables['node'], 'body', $body_display);
    $variables['body'] = drupal_render($body);

	$url = url('node/'.$variables['node']->nid, array('absolute' => true));
	$variables['comments'] = theme('fresh_fb_comments', array('url' => $url) );

  }
}

/**
 * Inline Content View Mode Preprocess
 * Implements hook_preprocess_node__VIEW-MODE()
 */
function fresh_preprocess_node__inline_content(&$variables){
  global $base_url;
  $path = drupal_get_path_alias('node/'. $variables['nid']);
  $variables['url'] = $base_url. '/'. $path;

  // Replace the $title with the promo headline if there is one
  if($field_promo_headline = field_get_items('node' ,$variables['node'], 'field_promo_headline')){
    $variables['title'] = $field_promo_headline[0]['value'];
  }
}
