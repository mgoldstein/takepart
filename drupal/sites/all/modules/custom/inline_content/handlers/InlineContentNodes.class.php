<?php
/**
 * @file
 * Embedded node(s) inline content controller.
 */

class InlineContentNodes extends InlineContentReplacementController {

  /**
   * Update the replacement content's display label.
   */
  public function updateLabel($replacement) {

    // Grab the content list.
    $content = field_get_items('inline_content', $replacement, 'field_ic_content');
    $titles = array();
    if ($content !== FALSE) {

      // Grab the title of each node.
      $nids = array();
      foreach ($content as $data) {
        $nids[] = (int) $data['nid'];
      }
      foreach (node_load_multiple($nids) as $node) {
        $titles[] = '<br /> : ' . $node->title;
      }
    }

    // Collapse the titles into a single title.
    $title = count($titles) ? implode('', $titles) : t('[No Content]');

    // Determine the display orientation.
    $orientation = t('Horizontal');
    $items = field_get_items('inline_content', $replacement, 'field_ic_orientation');
    if ($items !== FALSE && count($items) > 0) {
      $data = reset($items);
      if ($data['value'] == 'vertical') {
        $orientation = t('Vertical');
      }
    }

    // Format the label.
    $replacement->label = t('Embedded Content: (!orientation) !titles', array(
      '!titles' => $title,
      '!orientation' => $orientation,
    ));
  }

  /**
   * Return the replacement content.
   */
  public function view($replacement, $content, $view_mode = 'default', $langcode = NULL) {

    $orientation = 'horizontal';
    $items = field_get_items('inline_content', $replacement, 'field_ic_orientation');
    if ($items !== FALSE && count($items) > 0) {
      $data = reset($items);
      $orientation = $data['value'];
    }

    $content['#attributes'] = array(
      'class' => array('inline-content', $orientation),
    );
    $content['#orientation'] = $orientation;
    //$content['#theme_wrappers'] = array('container');

    $items = field_get_items('inline_content', $replacement, 'field_ic_content');
    if ($items !== FALSE) {
      $nids = array();
      foreach ($items as $data) {
        $nids[] = (int) $data['nid'];
      }
      foreach (node_load_multiple($nids) as $nid => $node) {

	      // Replace the campaign_page with its parent promo_headline, thumbnail if none exists
	      if($node->type == 'campaign_page') {

					// Get the parent campaign
					$field_campaign_reference = field_get_items('node' ,$node, 'field_campaign_reference');
					$field_campaign_reference = $field_campaign_reference[0]['target_id'];
					$campaign_node = node_load($field_campaign_reference);

					if( !field_get_items('node' ,$node, 'field_promo_headline') ) {
						$field_promo_headline = field_get_items('node' ,$campaign_node, 'field_promo_headline');
						$node->field_promo_headline[$node->language] = $field_promo_headline;
					}

					if( !field_get_items('node',$node,'field_thumbnail') ) {
						$field_thumbnail = field_get_items('node' ,$campaign_node, 'field_thumbnail');
						$node->field_thumbnail[$node->language] = $field_thumbnail;
					}

	      }
        $content['#replacements'][] = node_view($node, 'inline_content');
      }
    }
    return $content;
  }
}
