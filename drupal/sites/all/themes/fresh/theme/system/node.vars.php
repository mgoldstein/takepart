<?php

/**
 * Implements hook_preprocess_node();
 */
function fresh_preprocess_node(&$variables, $hook){
  // Run node-type-specific preprocess functions, like
  // fresh_preprocess_node__page() or fresh_preprocess_node__story().
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
    /* TODO: Roger, change this how you want */
    $variables['advertisement'] = theme('fresh_ad');

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
    if($body = field_get_items('node', $variables['node'], 'body')){
      $variables['body'] =  $body[0]['value']; /* TODO: this won't make use of inline replacements */
    }
  }



}