<?php
/**
 * @file
 * TAP Embed inline content controller.
 */

class InlineContentTapEmbed extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {

    // Grab the action override's title.
    //TODO: use a simple query for the title instead of loading the entire node
    $action = field_get_items('inline_content', $replacement, 'field_ic_action');
    if ($action !== FALSE && count($action) > 0) {
      $data = reset($action);
      $node = node_load($data['nid']);
      $title = $node->title;
    }
    else {
      $title = t('[No Action]');
    }

    // Grab the form style.
    $form_style = field_get_items('inline_content', $replacement, 'field_ic_expanded');
    if ($form_style !== FALSE && count($form_style) > 0) {
      $data = reset($form_style);
      $state = (!empty($data['value'])) ? t('Expanded') : t('Collapsed');
    }
    else {
      $state = t('Collapsed');
    }

    // Format the label.
    $replacement->label = t('TAP Embed: !title (!state)', array(
      '!title' => $title,
      '!state' => $state,
    ));
  }

  /**
   * Return the replacement content.
   */
  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {

    //Set default attributes
    $attributes = array();
    $attributes['class'][] = 'tap-action';

    //Expanded
    if ($form_style = field_get_items('inline_content', $replacement, 'field_ic_expanded')) {
      if ($form_style[0]['value']) {
        $attributes['data-expanded'] = 'TRUE';
      }
    }

    //Action Override
    if($action = field_get_items('inline_content', $replacement, 'field_ic_action')) {
      $action = reset($action);
      $mapping = SignatureActionMapping::loadByNodeId($action['nid']);
      if ($mapping !== FALSE) {
        $attributes['data-action-id'] = $mapping->tapID();
      }
    }

    //Title Override
    if ($title = field_get_items('inline_content', $replacement, 'field_ic_label')) {
      $title = reset($title);
      $attributes['data-widget-title'] = $title['value'];
    }

    //Action URL
    if ($article_url = field_get_items('inline_content', $replacement, 'field_ic_article_url')) {
      $article_url = reset($article_url);
      $attributes['data-article-url'] = $article_url['url'];
    }

    //Alignment
    if ($align = field_get_items('inline_content', $replacement, 'field_ic_tap_widget_alignment')) {
      $align = reset($align);
      $wrapper_attr = array(
        'class' => array('tap-action-wrapper')
      );
      $wrapper_attr['class'][] = 'align-' . $align['value'];
    } else {
      $wrapper_attr['class'][] = 'align-center';
    }

    //Generate tap-embed div
    $tapEmbed = theme('html_tag', array(
      'element' => array(
        '#tag' => 'div',
        '#value' => '',
        '#attributes' => $attributes
      )
    ));

    //Generate Wrapper
    $markup = theme('html_tag', array(
      'element' => array(
        '#tag' => 'div',
        '#value' => $tapEmbed,
        '#attributes' => $wrapper_attr
      )
    ));



    //Return the replacement
    $content['#replacements'][] = array(
      '#type' => 'markup',
      '#markup' => $markup,
    );

    return $content;
  }
}
