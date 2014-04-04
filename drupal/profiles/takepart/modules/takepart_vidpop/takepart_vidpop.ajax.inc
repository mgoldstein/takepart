<?php

/***
 * ajax callback to embed video in a map
 *
 * arg is the nid
 *
 * url is /vidpop/mapembed/NID
 */
function takepart_vidpop_get_map_video() {
  $nid = arg(2);
  $node = node_load($nid);
  $output = 'error reading node';
  if ($node) {
    //$build = node_view($node, 'vidpop_popup');
    $build = node_view($node, 'full');
    $build['#theme'] = 'vidpop_popup';
    $rendered = render($build);

    // format like a colorbox
    $id = 'vidpop-details-' . $nid;
    $output = <<<EOT
<div class="vidpop-overlay">
  <div id="$id">
    $rendered
  </div>
</div>
EOT;
  }

  print $output;
  drupal_exit();
}


/***
 * ajax callback to get map details
 *
 * arg is the nid
 *
 * url is /vidpop/mapembed/NID
 *
 * @returns rendered video for display
 */
function takepart_vidpop_get_map_details() {
  $nid = arg(2);
  $node = node_load($nid);
  if (variable_get('takepart_log_requests', false)) {
    watchdog('takepart_browsercaps', 'video map  details ' . $nid . ': ' . $node->title);
  }

  if ($node) {
    $vnode = node_view($node);

    // old way - this creates a non-embedded player, which is pretty much obsolete
    //$output = drupal_render($vnode['field_video_embedded']);

    // create embedded player
    // get the id of the embedded video
    $uri = $vnode['field_video_embedded'][0]['file']['#uri'];
    $u2 = explode('/', $uri);
    $youtube_id = $u2[3];
    $output = '<iframe width="640" height="360" src="//www.youtube.com/embed/' . $youtube_id . '?hl=en&fs=1&showinfo=1" frameborder="0" allowfullscreen></iframe>';

  }
  else {
    $output = __FUNCTION__ . ': could not load nid ' . $nid;
  }

  print $output;
  drupal_exit();
}


/***
 * ajax callback to get map details, mobile version
 *
 * arg is the nid
 *
 * url is /vidpop/mapembed/NID
 *
 * @returns rendered video for display
 */
function takepart_vidpop_get_map_details_mobile() {
  $nid = arg(2);
  $node = node_load($nid);
  if ($node) {
    $vnode = node_view($node);
    $output = drupal_render($vnode['field_video_embedded']);
  }
  else {
    $output = __FUNCTION__ . ': could not load nid ' . $nid;
  }

  print $output;
  drupal_exit();
}


/***
 * ajax callback to display video node page, mobile version
 * includes details from desktop video popup
 *
 * arg is the nid
 *
 * url is /vidpop/mobile_video_page_from_node/NID
 *
 * @returns rendered video for display
 */
function takepart_vidpop_mobile_video_page_from_node() {
  $nid = arg(2);
  $node = node_load($nid);
  $GLOBALS['vidpop_textlink'] = true;

  if (variable_get('takepart_log_requests', false)) {
    watchdog('takepart_browsercaps', 'video page from node ' . $nid . ': ' . $node->title);
  }

  $modpath = drupal_get_path('module', 'takepart');
  drupal_add_css($modpath . '/modules/takepart_vidpop/css/takepart_vidpop_mobile.css', array('every_page' => TRUE));

  drupal_set_title("Takepart video: " . $node->title);

  $file = file_load($node->field_video_embedded['und'][0]['fid']);
  $uri = 0;
  $u2 = explode('/', $file->uri);
  $youtube_id = $u2[3];

  $text = field_view_field('node', $node, 'field_promo_text');
  $text['#label_display'] = 'hidden';
  $rendered_text = render($text);

  $formatted_page = theme('vidpop_mobile_video_page', array(
    'p_video_nid'   => $nid,
    'p_video_title' => $node->title,
    'p_video_text'  => $rendered_text,
    'p_youtube_id'  => $youtube_id,
    'p_referrer'    => $_SERVER['HTTP_REFERER']

  ));

  return array('#markup' => $formatted_page);
}




/***
 * ajax callback to get map details, mobile version
 *
 * arg is the nid
 *
 * url is /vidpop/mapembed/NID
 *
 * @returns rendered video for display
 */
function takepart_vidpop_get_video_details() {
  $nid = arg(2);
  $node = node_load($nid);
  if ($node) {
    $output = array(
      'title' => $node->title,
      'type' => $node->type,
    );
  }
  else {
    $output = __FUNCTION__ . ': could not load nid ' . $nid;
  }

  drupal_json_output($output);
}
