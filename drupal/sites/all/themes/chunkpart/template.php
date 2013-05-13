<?php

/*
  Preprocess
*/

// Don't let nasty Drupal classes get put on the menu ul's
function chunkpart_menu_tree($variables) {
  return '<ul>' . $variables['tree'] . '</ul>';
}

function chunkpart_preprocess_page(&$variables) {
  $variables['header'] = _render_tp3_header($variables);
  $variables['footer'] = _render_tp3_footer($variables);
}

function chunkpart_preprocess_html(&$variables) {
}

function chunkpart_css_alter(&$css) {
  _alter_generated_css($css);
}

function chunkpart_field__field_series(&$vars) {
    $base = base_path() . 'sites/default/files/styles/action_header_image/public/';
    $filename = $vars['element']['#object']->field_series['und'][0]['taxonomy_term']->field_series_graphic_header['und'][0]['filename'];
    $url = $base . $filename;
    $linkOverride = $filename = $vars['element']['#object']->field_series['und'][0]['taxonomy_term']->field_series_graphic_header_link;
    if (!empty($linkOverride)) {
        $link = $linkOverride['und'][0]['url'];
    } else {
        $link = url($vars['items'][0]['#href']);
    }
    $altText = $filename = $vars['element']['#object']->field_series['und'][0]['taxonomy_term']->field_series_graphic_header['und'][0]['alt'];
    return sprintf('<a href="%s"><img class="field-name-field-series-graphic-header" src="%s" alt="%s" /></a>', $link, $url, $altText);
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
              
              if ($node->type == 'openpublish_article') {
                $main_image = field_get_items('node', $node, 'field_article_main_image');
              }
              if ($node->type == 'action') {
                $main_image = field_get_items('node', $node, 'field_action_main_image');
              }
              if ($node->type == 'openpublish_photo_gallery') {
                //field_gallery_main_image would also work here:
                $main_image = field_get_items('node', $node, 'field_gallery_images');
              }
              if ($node->type == 'openpublish_video') {
                $main_image = field_get_items('node', $node, 'field_main_image');
              }
              
              if (isset($main_image[0]['fid'])) {
                $img_url = file_load($main_image[0]['fid']);
                if (isset($img_url->{'uri'})) {
                  $variables['custom_render'][$key]['thumbnail'] = image_style_url('thumbnail_v2', $img_url->{'uri'});
                }
              }
              
              $types = node_type_get_types();
              if (isset($types[$node->type]->{'name'})) {
                $variables['custom_render'][$key]['type'] = $types[$node->type]->{'name'};
              }
              
              if (isset($node->{'title'})) {
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
