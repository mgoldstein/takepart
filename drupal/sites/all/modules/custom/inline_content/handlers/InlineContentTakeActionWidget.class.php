<?php
/**
 * @file
 * TakeAction Widget inline content controller.
 */

class InlineContentTakeActionWidget extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {

    // Grab the action override's title.
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
      $state = ((string) $data['value'] == 'expanded') ? t('Expanded') : t('Collapsed');
    }
    else {
      $state = t('Collapsed');
    }

    // Format the label.
    $replacement->label = t('Take Action Widget: !title (!state)', array(
      '!title' => $title,
      '!state' => $state,
    ));
  }

  /**
   * Return the replacement content.
   */
  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {

    $attributes = array(
      'class' => array('takepart-take-action-widget'),
    );

    // Set the widget's initial state.
    $form_style = field_get_items('inline_content', $replacement, 'field_ic_expanded');
    if ($form_style !== FALSE && count($form_style) > 0) {
      $data = reset($form_style);
      if ($data['value'] == 'expanded') {
        $attributes['data-form-style'] = 'expanded';
      }
    }

    // Set the widget's recommendations override URL.
    $article_url = field_get_items('inline_content', $replacement, 'field_ic_article_url');
    if ($article_url !== FALSE && count($article_url) > 0) {
      $data = reset($article_url);
      $attributes['data-article-url'] = $data['url'];
    }

    // Set the widget's action id override.
    $action = field_get_items('inline_content', $replacement, 'field_ic_action');
    if ($action !== FALSE && count($action) > 0) {
      $data = reset($action);
      $attributes['data-action-id'] = $data['nid'];
    }

    $content['#replacements'][] = array(
      '#type' => 'markup',
      '#markup' => '<div' . drupal_attributes($attributes) . '></div>',
    );

    return $content;
  }
}
