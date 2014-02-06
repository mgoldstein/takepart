<?php

/*
  Preprocess
*/

/**
* Implements template_preprocess_node().
*/
function chunkpart_preprocess_node(&$vars) {
  // Add 'After node' block region inside node.
  if ( $vars['view_mode'] == 'full' ) {
    if ( $block_region_name = block_get_blocks_by_region('node_region') ) {
      $vars['node_region'] = $block_region_name;
    }
  }
}

// Don't let nasty Drupal classes get put on the menu ul's
function chunkpart_menu_tree($variables) {
  return '<ul>' . $variables['tree'] . '</ul>';
}

function chunkpart_preprocess_page(&$variables) {
  $variables['header'] = _render_tp3_header($variables);
  $variables['footer'] = _render_tp3_footer($variables);

  // add Taboola JS if we're on an article or photo gallery page
  // but only if we're on the production site: variable_get('environment', 'dev') === 'prod' && 
  if (variable_get('environment', 'dev') === 'prod' && !empty($variables['node']) && in_array($variables['node']->type, array('openpublish_article', 'openpublish_photo_gallery', 'feature_article', 'video'))) {
    drupal_add_js(drupal_get_path('theme', 'tp4') . '/js/taboola.js', 'file');
    drupal_add_js('window._taboola = window._taboola || []; _taboola.push({flush:true});', array('type' => 'inline', 'scope' => 'footer'));
  }
}

function chunkpart_preprocess_html(&$variables) {
}

function chunkpart_css_alter(&$css) {
  _alter_generated_css($css);
}

function chunkpart_image_style($variables) {
  $style_name = $variables['style_name'];
  $path = $variables['path'];
  
  // theme_image() can only honor the $getsize parameter with local file paths.
  // The derivative image is not created until it has been requested so the file
  // may not yet exist, in this case we just fallback to the URL.
  $style_path = image_style_path($style_name, $path);
  if (!file_exists($style_path)) {
    $style_path = image_style_url($style_name, $path);
  }
  $variables['path'] = $style_path;
  if (

  is_file($style_path)) {
    if (list($width, $height, $type, $attributes) = @getimagesize($style_path)) {
      $variables['width'] = $width;
      $variables['height'] = $height;
    }
  }
  
  return theme('image', $variables);
}

/*

function takepart3_preprocess_entity(&$variables, $hook) {

    $variables["custom_render"] = array();

    switch ($variables['entity_type']) {
        case "bean":
            if($variables['bean']->{'type'} == "of_the_day") {
                //Look for a tpl file called bean--of-the-day-custom.tpl.php:
                $variables['theme_hook_suggestions'][] = 'bean__of_the_day_custom';
                $acnids = $variables['bean']->{'field_associated_content'}['und'];

                for ($i = 0; $i <= sizeof($acnids); $i++) {

                    $acnid = $variables['bean']->{'field_associated_content'}['und'][$i]['nid'];
                    $node = node_load($acnid);
		    if($node->status == 1) {
	                    if($node->type == 'openpublish_article') {
	                        $main_image = field_get_items('node', $node, 'field_article_main_image');
	                    }
	                    if($node->type == 'action') {
	                        $main_image = field_get_items('node', $node, 'field_action_main_image');
	                    }
	                    if($node->type == 'openpublish_photo_gallery') {
	                        $main_image = field_get_items('node', $node, 'field_gallery_main_image');
	                    }
	                    if($node->type == 'openpublish_video') {
	                        $main_image = field_get_items('node', $node, 'field_main_image');
	                    }

	                    if(isset($main_image[0]['fid'])) {
	                        $img_url = file_load($main_image[0]['fid']);
	                        if(isset($img_url->{'uri'})){
	                            $variables['custom_render'][$i]['thumbnail'] = image_style_url('thumbnail_v2', $img_url->{'uri'});
	                        }
	                    }

	                    $types = node_type_get_types();
	                    if(isset($types[$node->type]->{'name'})) {
	                        $variables['custom_render'][$i]['type'] = $types[$node->type]->{'name'};
	                    }

	                    if(isset($node->{'title'})) {
	                        $variables['custom_render'][$i]['title'] = $node->{'title'};
	                    }

	                    $variables['custom_render'][$i]['url'] = url('node/'. $node->nid);
                	}
		}
            }
          break;
    }
}
*/


function chunkpart_preprocess_entity(&$variables, $hook) {

  $variables["custom_render"] = array();

  switch ($variables['entity_type']) {

    case "bean":

      if ($variables['bean']->{'type'} == "of_the_day") {
        //Look for a tpl file called bean--of-the-day-custom.tpl.php:
        $variables['theme_hook_suggestions'][] = 'bean__of_the_day_custom';

        for ($i = 0; $i <= sizeof($variables['elements']['field_listing_collection']); $i++) {
          $listing = $variables['elements']['field_listing_collection'][$i];
          $collection = $listing['entity']['field_collection_item'];

          foreach ($collection as $key => $collectiondata) {

            $acnid = $collectiondata['field_associated_content']['#items'][0]['nid'];
            $node  = node_load($acnid);

            if ($node->status == 1) {

              $variables['custom_render'][$key]['typename'] = $collectiondata['field_type_label']['#items'][0]['value'];

              if ($node->type == 'openpublish_article' || $node->type == 'feature_article') {
                $main_image = field_get_items('node', $node, 'field_thumbnail');
              }
              if ($node->type == 'action') {
                $main_image = field_get_items('node', $node, 'field_action_main_image');
              }
              if ($node->type == 'openpublish_photo_gallery') {
                //field_gallery_main_image would also work here:
                $main_image = field_get_items('node', $node, 'field_gallery_images');
              }
              if ($node->type == 'openpublish_video') {
                $main_image = field_get_items('node', $node, 'field_thumbnail');
              }
              if (isset($main_image[0]['fid'])) {
                $img_url = file_load($main_image[0]['fid']);
                $img_alt = field_get_items('file', $img_url, 'field_media_alt');
                $variables['custom_render'][$key]['thumbnail_alt'] = $img_alt[0]['safe_value'];
                if (isset($img_url->{'uri'})) {
                  $variables['custom_render'][$key]['thumbnail'] = image_style_url('thumbnail_v2', $img_url->{'uri'});
                }
              }

              $types = node_type_get_types();
              if (isset($types[$node->type]->{'name'})) {
                $variables['custom_render'][$key]['type'] = $types[$node->type]->{'name'};
              }

	      $variables['custom_render'][$key]['title'] = field_get_items('node', $node, 'field_promo_headline');
	      
              if ((isset($node->{'title'})) && (!isset($variables['custom_render'][$key]['title']))) {
                $variables['custom_render'][$key]['title'] = $node->{'title'};
              }

              $variables['custom_render'][$key]['url'] = url('node/' . $node->nid);

            }

          }

        }
      }
      break;
  }
}
