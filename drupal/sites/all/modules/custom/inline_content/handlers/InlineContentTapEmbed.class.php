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

    //Return if takeaction module isn't enabled
    if(!module_exists('takeaction')) {
      return;
    }


    //Expanded
    if ($form_style = field_get_items('inline_content', $replacement, 'field_ic_expanded')) {
      if ($form_style[0]['value']) {
        $overrides['data-expanded'] = 'TRUE';
      }
    }

    //Action Override
    if($action = field_get_items('inline_content', $replacement, 'field_ic_action')) {
      $action = reset($action);
      $mapping = SignatureActionMapping::loadByNodeId($action['nid']);
      if ($mapping !== FALSE) {
        $overrides['data-action-id'] = $mapping->tapID();
      }
    }

    //Title Override
    if ($title = field_get_items('inline_content', $replacement, 'field_ic_label')) {
      $title = reset($title);
      $overrides['data-widget-title'] = $title['value'];
    }

    //Action URL
    if ($article_url = field_get_items('inline_content', $replacement, 'field_ic_article_url')) {
      $article_url = reset($article_url);
      $overrides['data-article-url'] = $article_url['url'];
    }

    //Alignment
    $alignment = '';
    if ($align = field_get_items('inline_content', $replacement, 'field_ic_tap_widget_alignment')) {
      $align = reset($align);
      $alignment = $align['value'];
    }

    //Generate TAP Embed
    $tap_embed = takeaction_view_tap_embed($overrides, $alignment);

    //Return the replacement
    $content['#replacements'][] = array(
      '#type' => 'markup',
      '#markup' => $tap_embed,
    );

    return $content;
  }
}
