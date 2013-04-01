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
function _s($var) {
  if ( is_string($var) ) {
    return $var;
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
function _simage($var) {
  $image = null;
  if ( is_object($var) && get_class($var) == 'EntityStructureWrapper' ) {
    $var = $var->value();
  }

  if ( isset($var['type']) && $var['type'] == 'image') {
    $image = $var;
  } elseif ( isset($var['und']) && isset($var['und'][0]) && isset($var['und'][0]['file']) ) {
    echo 'Bad und stuff; plz fix :(';
    $image = (array)$var['und'][0]['file'];
  /*} elseif ( isset($var['und']) && $var['und'][0] ) {
    echo 'und2';
    $image = $var['und'][0];*/
  } else {
    return '';
  }

  if ( !isset($image['path']) ) {
    $image['path'] = file_create_url($image['uri']);
    /*if ( $wrapper = file_stream_wrapper_get_instance_by_uri($image['uri']) ) {
      $image['path'] = $wrapper->realpath();
    }*/
  }

  return theme_image($image);
}

// Rip out Drupal system classes
function _smenu($menu_name) {
  $items = menu_tree($menu_name);
  foreach( $items as $ikey => &$item ) {
    foreach ( $item['#attributes']['class'] as $ckey => $class ) {
      if ( $class == 'leaf' ) {
        unset($items[$ikey]['#attributes']['class'][$ckey]);
        break;
      }
    }
  }

  return render($items);
}

// Get a node
function _snode($var) {
  if ( isset($var[0]) ) {
    return entity_metadata_wrapper('node', $var[0]['node']);
  }
}

// Loop through a node?
function _seach(&$arr) {
  $ea = each($arr);
  if ( !$ea ) {
    reset($arr);
    return $ea;
  }

  if ( isset($ea['value']['node']) ) {
    return entity_metadata_wrapper('node', $ea['value']['node']);
  } elseif( isset($ea['value']['taxonomy_term']) ) {
    return $ea['value']['taxonomy_term'];
  }

  return null;
}

/*
  Preprocess
*/

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
    $menu_data = menu_tree_page_data("user-menu");
    $uri = drupal_get_path_alias($_GET['q']);
    $uri_substr = substr($uri, 0, 14);
    $links = array();
    foreach ($menu_data as $menu_item) {
        $opts = array(
            'attributes' => _default_menu_options($menu_item),
        );
        if (($uri_substr == 'bsd/header') || ($uri_substr == 'bsd/footer')) {
            $opts['absolute'] = TRUE;
        }

        $opts['attributes']['class'][] = 'user-menu-' . strtolower($menu_item['link']['title']);

        if (empty($opts['attributes']['title'])) {
            unset($opts['attributes']['title']);
        }

        if ($menu_item['link']['href'] == 'user') {
            if (user_is_logged_in()) {
                global $user;
                if (function_exists('_takepart_facebookapis_get_user_session')) {
                    $fbsession = _takepart_facebookapis_get_user_session();
                    $username = $fbsession->name;
                    if ($username == '') {
                        $username = $user->name;
                    }
                } else {
                    $username = $user->name;
                }

                if ($variables['node']->type == 'venue' || $variables['node']->type == 'action'
                        || $variables['node']->type == 'petition_action' || $variables['node']->type == 'pledge_action'
                        || (!empty($variables['node']->field_multi_page_campaign[$variables['node']->language][0]['context']))) {
                    if (strlen($username) > 10 && isset($fbsession->first_name) && isset($fbsession->last_name)) {
                        $username = $fbsession->first_name . " " . substr($fbsession->last_name, 0, 1);
                        if (strlen($username) < 10) {
                            $username = $username . ".";
                        }
                    }
                    if (strlen($username) > 10) {
                        $username = substr($username, 0, 10) . "…";
                    }
                }
                $menu_item['link']['title'] = $username;
                $menu_item['link']['href'] = variable_get('takeaction_dashboard_url', '');
            } else {
                $opts['attributes']['class'][] = 'join-login';
                $opts['query'] = drupal_get_destination();
                $menu_item['link']['title'] = variable_get("takepart_user_login_link_name", "Login");
            }
        } else {
            switch ($menu_item['link']['href']) {
                case 'user/register':
                    $opts['attributes']['class'][] = 'join-takepart';
                    break;
            }
        }
        if (empty($menu_item['link']['href'])) {
            $link = $menu_item['link']['title'];
        } else {
            $link = l($menu_item['link']['title'], $menu_item['link']['href'], $opts);
        }
        $links[] = '<li class="login-' . count($links) . '">' . $link . "</li>";
    }
    $output = "<ul id='user-nav'>" . implode($links) . "</ul>";
    return $output;
}

function _default_menu_options($menu_item) {
    $menu_opts = empty($menu_item['link']['options']['attributes']) ? array() : $menu_item['link']['options']['attributes'];
    return $menu_opts;
}
