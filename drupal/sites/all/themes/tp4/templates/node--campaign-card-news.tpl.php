<?php
/**
 * @file
 * Returns the HTML for a Campaign Card Tray.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 *
 * Keep this as plain as possible.  Tray formatting is primarily done at the field-formatter level
 * Create a separate view mode for the field formatter to use so this template can be used to view cards
 * on a node level
 */
?>
<?php
  // // We hide the comments and links now so that we can render them later.
  // hide($content['comments']);
  // hide($content['links']);
  // // print drupal_render(node_view_multiple($variables['output'], 'default'));
  // foreach($variables['output'] as $key => $item){
  //   $file = file_load($item->field_article_main_image['und'][0]['fid']);
  //   $image = '<img src="'. file_create_url($file->uri). '">';
  //   $headline = '<div class="headline">'. $item->field_promo_headline['und'][0]['value']. '</div>';
  //   print '<div class="news-column">'. $image. $headline. $item->type. $item->nid. '</div>';
  // }
?>


