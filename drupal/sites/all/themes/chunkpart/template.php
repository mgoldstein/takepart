<?php

/* Template helpers */

// return safe variable
function _s($var, $prop = NULL, $type = 'node') {
  if ( is_string($var) ) {
    return $var;
  } elseif ( is_object($var) && $prop ) {
    $ret = field_get_items($type, $var, $prop);
    return $ret[0];
  // Avoid doing ->value()
  } elseif ( is_object($var) && get_class($var) == 'EntityValueWrapper' ) {
    return $var->value();
  // In case a node is passed to this function
  } elseif ( isset($var[0]) && isset($var[0]['node']) ) {
    return entity_metadata_wrapper('node', $var[0]['node']);
  // Body attribute
  } elseif ( isset($var[0]) && isset($var[0]['safe_value']) ) {
    return $var[0]['safe_value'];
  }
}

/* Return a URL */
function _surl($var, $prop = NULL, $type = 'node') {
  if ( is_array($var) && isset($var[0]) && isset($var[0]['node']) ) {
    return url('node/' . $var[0]['node']->nid);
  } elseif ( is_array($var) && isset($var['node']) ) {
    return url('node/' . $var['node']->nid);
  } elseif ( $var->_surl ) {
    return $var->_surl;
  } elseif ( is_object($var) ) {
    return url('node/' . $var->nid);
  }
  return '/';
}

// return a block
function _sblock($var) {
  // Only print blocks
  // TODO: add appropriate rules for a block
  if ( is_array($var) ) {
    return render($var);
  }
  return '';
}


// return an image
function _simage($var, $prop = NULL, $type = 'node') {
  if ( is_object($var) && $prop ) {
    if ( isset($var->_stype) ) $type = $var->_stype;
    $var = field_get_items($type, $var, $prop);
  }

  $image = null;
  if ( is_object($var) && get_class($var) == 'EntityStructureWrapper' ) {
    $var = $var->value();
  }

  if ( isset($var['type']) && $var['type'] == 'image') {
    $image = $var;
  } elseif ( isset($var[0]) && isset($var[0]['file']) ) {
    $image = (array)$var[0]['file'];
  } elseif ( isset($var[0]) ) {
    $image = $var[0];
  } else {
    return '';
  }

  if ( !isset($image['path']) ) {
    $image['path'] = file_create_url($image['uri']);
  }

  return theme_image($image);
}

// Rip out Drupal system classes
function _smenu($menu) {
  if ( is_string($menu) ) {
    $items = menu_tree($menu);
  } elseif ( is_array($menu) ) {
    $items = $menu;
  }

  // Strip drupal system class
  foreach( $items as $ikey => &$item ) {
    foreach ( $item['#attributes']['class'] as $ckey => $class ) {
      if ( $class == 'leaf' ) {
        // Pretty hacky, but whatcha gonna do :\
        //unset($items[$ikey]['#attributes']['class'][$ckey]);
        $items[$ikey]['#attributes']['class'][$ckey] = 'text-' . preg_replace('/[^a-z]+/', '_', strtolower($items[$ikey]['#title']));
        break;
      }
    }
  }

  return render($items);
}

// Get a node
function _snode($var) {
  if ( isset($var[0]) ) {
    return $var[0]['node'];
  }
}

// Get link
function _slink($var, $prop = NULL, $type = NULL) {
  if ( is_object($var) && isset($var->_stype) && $prop ) {
    $ret = field_get_items($var->_stype, $var, $prop);
    return $ret[0];
  }
  return '';
}

// Loop through a node?
function _seach(&$var /*, $prop = null, $type = 'node'*/ ) {
  /*if ( is_object($var) && $prop ) {
    $var = field_get_items($type, $var, $prop);
  }*/

  if ( !is_array($var) ) return null;

  $ea = each($var);
  if ( !$ea ) {
    reset($var);
    return $ea;
  }

  if ( isset($ea['value']['node']) ) {
    return $ea['value']['node'];
  }

  $taxonomy_term = null;
  if( isset($ea['value']['taxonomy_term']) ) {
    $taxonomy_term = $ea['value']['taxonomy_term'];
  } elseif ( isset($ea['taxonomy_term']) ) {
    $taxonomy_term = $ea['taxonomy_term'];
  }

  if ( $taxonomy_term ) {
    $uri = entity_uri('taxonomy_term', $taxonomy_term);
    $taxonomy_term->_surl = url($uri['path']);
    $taxonomy_term->_stype = 'taxonomy_term';
    return $taxonomy_term;
  }

  return null;
}

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

function _default_menu_options($menu_item) {
    $menu_opts = empty($menu_item['link']['options']['attributes']) ? array() : $menu_item['link']['options']['attributes'];
    return $menu_opts;
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
