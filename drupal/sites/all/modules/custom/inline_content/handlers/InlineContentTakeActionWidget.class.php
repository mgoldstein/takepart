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
      $state = (!empty($data['value'])) ? t('Expanded') : t('Collapsed');
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

    //Return if takeaction module isn't enabled
    if(!module_exists('takeaction')) {
      return;
    }

    // Set the article-id attribute (to scope widgets for each article in autoscroll)
    if ( isset( $replacement->nid ) ) {
      $nid = $replacement->nid;
      $overrides['data-article-id'] = $nid;
    }

    // Set the widget's initial state.
    $form_style = field_get_items('inline_content', $replacement, 'field_ic_expanded');
    if ($form_style !== FALSE && count($form_style) > 0) {
      $data = reset($form_style);
      if (!empty($data['value'])) {
        $overrides['data-form-style'] = 'expanded';
      }
    }

    // Set the widget's recommendations override URL.
    $article_url = field_get_items('inline_content', $replacement, 'field_ic_article_url');
    if ($article_url !== FALSE && count($article_url) > 0) {
      $data = reset($article_url);
      $overrides['data-article-url'] = $data['url'];
    }

    // Set the widget's action id override.
    $action = field_get_items('inline_content', $replacement, 'field_ic_action');
    if ($action !== FALSE && count($action) > 0) {
      $data = reset($action);
      $mapping = SignatureActionMapping::loadByNodeId($data['nid']);
      if ($mapping !== FALSE) {
        $overrides['data-action-id'] = $mapping->tapID();
      }
    }

    // Set the widget's action title override.
    $title = field_get_items('inline_content', $replacement, 'field_ic_label');
    if ($title !== FALSE && count($title) > 0) {
      $data = reset($title);
      $overrides['data-action-title'] = $data['value'];
    }

    // Set the widget's type, defaulting to actions_widget.
    $type = field_get_items('inline_content', $replacement, 'field_ic_tap_widget_type');
    if ($type !== FALSE && count($type) > 0) {
      $data = reset($type);
      $overrides['data-widget-type'] = $data['value'];
    } else {
      $overrides['data-widget-type'] = 'actions_widget';
    }

    // Set the widget's sponsor name.
    if ($sponsor_name = field_get_items('inline_content', $replacement, 'field_ic_tap_widget_sponsor_name')) {
      $data = reset($sponsor_name);
      $overrides['data-sponsor-name'] = $data['value'];
    }

    // Set the widget's sponsor url.
    if ($sponsor_url = field_get_items('inline_content', $replacement, 'field_ic_tap_widget_sponsor_url')) {
      $data = reset($sponsor_url);
      $overrides['data-sponsor-url'] = $data['url'];
    }

    //Alignment
    $alignment = '';
    if ($align = field_get_items('inline_content', $replacement, 'field_ic_tap_widget_alignment')) {
      $align = reset($align);
      $alignment = $align['value'];
    }

    //Generate TAP Embed
    $tap_widget = takeaction_view_tap_widget($overrides, $alignment);

    $content['#replacements'][] = array(
      '#type' => 'markup',
      '#markup' => $tap_widget
    );

    return $content;
  }
}
