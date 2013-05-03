<?php

/*
  Preprocess
*/

// Don't let nasty Drupal classes get put on the menu ul's
function chunkpart_menu_tree($variables) {
  return '<ul>' . $variables['tree'] . '</ul>';
}

function chunkpart_preprocess_page(&$variables) {
  // Batshit crazy nav stuff
  if ((!isset($variables['user_nav'])) || (!$variables['user_nav'])) {
    $variables['user_nav'] = _render_tp3_user_menu($variables);
  }

  $variables['header'] = _render_tp3_header($variables);
  $variables['footer'] = _render_tp3_footer($variables);
}

/**
 * Helper to output the custom HTML for out main menu.
 */
function _render_tp3_user_menu($variables) {
    // dpm($vars);
    $menu_data = menu_tree_page_data('user-menu');

    foreach ( $menu_data as &$menu_item ) {
        if ( $menu_item['link']['href'] == 'user' ) {
            if ( user_is_logged_in() ) {
                global $user;
                if ( function_exists('_takepart_facebookapis_get_user_session') ) {
                    $fbsession = _takepart_facebookapis_get_user_session();
                    $username = $fbsession->name;
                    if ( $username == '' ) {
                        $username = $user->name;
                    }
                } else {
                    $username = $user->name;
                }

                $menu_item['link']['title'] = $username;
                $menu_item['link']['href'] = variable_get('takeaction_dashboard_url', '');
            } else {
                $menu_item['link']['localized_options']['query'] = drupal_get_destination();
                $menu_item['link']['title'] = variable_get("takepart_user_login_link_name", "Login");
                $menu_item['link']['hidden'] = 0;
            }
        }
    }

    return _smenu(menu_tree_output($menu_data));
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
                            $variables['custom_render'][$i]['thumbnail'] = image_style_url('thumbnail', $img_url->{'uri'});
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
          break;
    }
}
*/

function chunkpart_preprocess_entity(&$variables, $hook) {

    $variables["custom_render"] = array();

    switch ($variables['entity_type']) {
        case "bean":
            if($variables['bean']->{'type'} == "of_the_day") {
                //Look for a tpl file called bean--of-the-day-custom.tpl.php:
                $variables['theme_hook_suggestions'][] = 'bean__of_the_day_custom';

                for ($i = 0; $i <= sizeof($variables['elements']['field_listing_collection']); $i++) {
                   $listing = $variables['elements']['field_listing_collection'][$i];

                    $collection = $listing['entity']['field_collection_item'];

                    foreach ($collection as $key => $collectiondata) {

                        $acnid = $collectiondata['field_associated_content']['#items'][0]['nid'];
                        $variables['custom_render'][$key]['typename'] = $collectiondata['field_type_label']['#items'][0]['value'];

                        $node = node_load($acnid);

                        if($node->type == 'openpublish_article') {
                            $main_image = field_get_items('node', $node, 'field_article_main_image');
                        }
                        if($node->type == 'action') {
                            $main_image = field_get_items('node', $node, 'field_action_main_image');
                        }
                        if($node->type == 'openpublish_photo_gallery') {
                            //field_gallery_main_image would also work here:
                            $main_image = field_get_items('node', $node, 'field_gallery_images');
                        }
                        if($node->type == 'openpublish_video') {
                            $main_image = field_get_items('node', $node, 'field_main_image');
                        }

                        if(isset($main_image[0]['fid'])) {
                            $img_url = file_load($main_image[0]['fid']);
                            if(isset($img_url->{'uri'})){
                                $variables['custom_render'][$key]['thumbnail'] = image_style_url('thumbnail', $img_url->{'uri'});
                            }
                        }

                        $types = node_type_get_types();
                        if(isset($types[$node->type]->{'name'})) {
                            $variables['custom_render'][$key]['type'] = $types[$node->type]->{'name'};
                        }

                        if(isset($node->{'title'})) {
                            $variables['custom_render'][$key]['title'] = $node->{'title'};
                        }

                        $variables['custom_render'][$key]['url'] = url('node/'. $node->nid);

                    }

                }
            }
          break;
    }
}
