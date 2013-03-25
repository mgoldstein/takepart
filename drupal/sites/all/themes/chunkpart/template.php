<?php

/* Template helpers */

// pretty print arrays
function listArrayRecursive($someArray, $prepend = '') {
    $someArray = (array) $someArray;
    $iterator = new RecursiveIteratorIterator(new RecursiveArrayIterator($someArray), RecursiveIteratorIterator::SELF_FIRST);
    foreach ($iterator as $k => $v) {
        //$indent = str_repeat('&nbsp;', 10 * $iterator->getDepth());
        // Not at end: show key only
        if ($iterator->hasChildren()) {
            //echo "$k :<br>";
        // At end: show key, value and path
        } else {
            for ($p = array(), $i = 0, $z = $iterator->getDepth(); $i <= $z; $i++) {
                $p[] = '[\'' . $iterator->getSubIterator($i)->key() . '\']';
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
  // Body attribute
  } elseif ( isset($var[0]) && isset($var[0]['safe_value']) ) {
    return $var[0]['safe_value'];
  // Node
  } elseif ( isset($var[0]) && $var[0]['node'] ) {
    return $var[0]['node'];
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

/*
  Preprocess
*/
function chunkpart_preprocess_page(&$vars) {
  // Batshit crazy nav stuff
  $user_nav = menu_tree('user-menu');
  foreach ($user_nav as &$nav) {
    if ($nav['#href'] == 'user') {
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
      }
      $nav['#title'] = $username;
      break;
    }
  }
  $vars['user_nav'] = $user_nav;
}
