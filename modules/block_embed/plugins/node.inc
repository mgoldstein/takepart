<?php
$plugin = array(
  'embed callback' => 'embed_node'
);
function embed_node($info) {
  $nid = $info['nid'];
  $view_mode = isset($info['view_mode']) ? $info['view_mode'] : 'embed';

  return drupal_render(node_view(node_load($nid), $view_mode));
}

function node_wysiwyg_form(&$form, &$form_state) {
  $form['nid'] = array(
    '#type' => 'textfield',
    '#title' => 'Node Id',
  );
  $info = entity_get_info("node");
  $view_mode_options = array();
  foreach($info['view modes'] as $key => $mode) {
    $view_mode_options[$key] = $mode['label'];
  }
  $form['view_mode'] = array(
    '#type' => 'select',
    '#options' => $view_mode_options,
    '#title' => 'View Mode',
  );
}
// return array that of data that can be used to build
// node
function node_wysiwyg_submit(&$form, &$form_state) {
  $data['nid'] = $form_state['values']['nid'];
  $data['view_mode'] = $form_state['values']['view_mode'];
  return $data;
}

function node_wysiwyg_preview_title($data) {
  $node = node_load($data['nid']);
  return "CONTENT: " . $node->title;

}

