<?php
/*
 * This is the template for the action embed not that we are NOT RENDERING
 * THE CONTENT OF THE DISPLAY MODE SETTING.  This is an isolated case
 * of just action embeds so it might not be a problem.
 *
 * We are going to leave the embed display mode empty so it is
 * clear that we are not using those settings
 */

$graphic_link = '';
$title_link = '';

$items = field_get_items('node', $node, 'field_tab_link_only');
$link_only = FALSE;
if (!empty($items)) {
  // Use only the first value (there should be only one).
  $item = reset($items);
  $link_only = !empty($item['value']);
}

if ($link_only) {
  $items = field_get_items('node', $node, 'field_action_url');
  if (!empty($items)) {

    // There should be only one value for the field.
    $item = reset($items);
    $attributes = array(
      'href' => 'javascript:void();',
      'nid' => $node->nid,
    );
    if (!empty($item['url']) && $item['url'] !== 'local') {
      $attributes['action-href'] = $item['url'];    
    }
    if (isset($item['attributes'])) {
      if (isset($item['attributes']['target'])) {
        $attributes['target'] = $item['attributes']['target'];
      }
      if (isset($item['attributes']['class'])) {
        $attributes['class'] = array('external-action-link');
      }
    }
    if ($vars['element']['#entity_type'] === 'node') {
      $attributes['nid'] = $vars['element']['#object']->nid;
    }
    $variables = array(
      'element' => array(
        '#tag' => 'a',
        '#attributes' => $attributes,
        '#value' => '<span>' . $item['title'] . '!</span>',
      ),
    );
    $graphic_link = theme('html_tag', $variables);
    $variables = array(
      'element' => array(
        '#tag' => 'a',
        '#attributes' => $attributes,
        '#value' => check_plain($node->title),
      ),
    );
    $title_link = theme('html_tag', $variables);
  }
}

if (empty($graphic_link)) {
  $variables = array(
    'element' => array(
      '#tag' => 'a',
      '#attributes' => array(
        'href' => 'javascript:void();',
        'action-href' => url("node/{$node->nid}"),
        'class' => array('external-action-link'),
        'nid' => $node->nid,
      ),
      '#value' => t('<span>Take Action!</span>'),
    ),
  );
  $graphic_link = theme('html_tag', $variables);
}

if (empty($title_link)) {
  $variables = array(
    'element' => array(
      '#tag' => 'a',
      '#attributes' => array(
        'href' => 'javascript:void();',
        'action-href' => url("node/{$node->nid}"),
        'class' => array('external-action-link'),
        'nid' => $node->nid,
      ),
      '#value' => check_plain($node->title),
    ),
  );
  $title_link = theme('html_tag', $variables);
}
?>
<div class="embedaction-wrapper link clearfix">
  <div class="more-actions">
  <a class="button takepart-custom-take-action-button" href="javascript:void()"><span>See More Actions</span></a></div>
  <div class="header">
  <table>
  <tbody>
  <tr>
  <td class="graphic"><?php print $graphic_link; ?></td>
  <td class="title"><?php print $title_link; ?></td>
  </tr>
  </tbody>
  </table>
  </div>
</div>
