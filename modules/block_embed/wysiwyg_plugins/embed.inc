<?php
function block_embed_embed_plugin() {
  $plugins['embed'] = array(
    'title' => 'DRUPALEMBED',
    'settings' => array(),
    'icon title' => 'Embed me',
  );
  $embeds = block_embed_embeds();

  //we want to run through all of the embeds
  //and make plugins for them
  //we are going to use the same js as embed
  //and we will look in the embed path for the icon
  //
  foreach($embeds as $id => $embed) {
    dpm($embed);
    
    $plugins[$id] = isset($embed['wysiwyg plugin']) ? $embed['wysiwyg plugin'] : array();
    $plugins[$id]  = $plugins[$id] + array(
      'title'=> 'Embed ' .$embed['name'],
      'settings' => array('embed_type' => $id),
      'icon title' => 'Embed '. $embed['name'],
      'icon path' => $embed['path'],
      'icon file' => "$id.png",
      'path' => drupal_get_path('module', 'block_embed') . '/wysiwyg_plugins/embed',
      'filename' => 'embed.js',

    );
  }
  
  return $plugins;
}
