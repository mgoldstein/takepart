<?php

/* Template helpers */

// pretty print arrays
function _l($someArray, $prepend = '') {
    echo "<hr />";
    if ( !is_array($someArray) && !is_object($someArray) ) {
      echo '<div class="data"><span class="value">' . htmlspecialchars($v) . '</span></div>';
    }

    $someArray = (array)$someArray;
    $iterator = new RecursiveIteratorIterator(new RecursiveArrayIterator($someArray), RecursiveIteratorIterator::SELF_FIRST);
    foreach ($iterator as $k => $v) {
        //$indent = str_repeat('&nbsp;', 10 * $iterator->getDepth());
        // Not at end: show key only
        if ($iterator->hasChildren()) {
            //echo "$k :<br>";
        // At end: show key, value and path
        } else {
            for ($p = array(), $i = 0, $z = $iterator->getDepth(); $i <= $z; $i++) {
                $b = '[';
                $e = ']';
                $c = $iterator->getSubIterator($i)->current();
                if ( is_object($c) ){
                  $b = '{';
                  $e = '}';
                }
                $p[] = $b . '\'' . $iterator->getSubIterator($i)->key() . '\'' . $e;
            }
            $path = $prepend . implode('', $p);
            echo '<div class="data"><span class="key">' . $path . ': <span class="value">' . htmlspecialchars($v) . '</span></div>';
        }
    }
}

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
function _surl($var) {
  if ( is_array($var) && isset($var[0]) && isset($var[0]['node']) ) {
    return url('node/' . $var[0]['node']->nid);
  } elseif ( is_array($var) && isset($var['node']) ) {
    return url('node/' . $var['node']->nid);
  } elseif ( is_object($var) ) {
    return url('node/' . $var->nid);
  } elseif ( $var->_surl ) {
    return $var->_surl;
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
  } elseif( isset($ea['value']['taxonomy_term']) ) {
    $uri = entity_uri('taxonomy_term', $ea['value']['taxonomy_term']);
    $ea['value']['taxonomy_term']->_surl = url($uri['path']);
    return $ea['value']['taxonomy_term'];
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
