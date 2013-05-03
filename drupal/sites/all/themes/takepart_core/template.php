<?php

/*
  Preprocess
*/

/**
 * Implementation of hook_theme().
 */
function takepart_core_theme() {
    return array(
        'takepart3_footer' => array(
            'template' => 'templates/subtemplates/_footer',
            'arguments' => array(
                'params' => NULL,
            ),
        ),
        'takepart3_header' => array(
            'template' => 'templates/subtemplates/_header',
            'arguments' => array(
                'params' => NULL,
            ),
        ),
    );
}

function takepart_core_preprocess_html(&$vars) {
    // Optimizely
    drupal_add_js('//cdn.optimizely.com/js/77413453.js', array(
        'type' => 'external',
        'scope' => 'footer',
        'group' => JS_DEFAULT,
        'every_page' => TRUE,
        'weight' => -1,
    ));
}

function takepart_core_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $element['#localized_options']['absolute'] = TRUE;
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/* Custom functions */

function _render_tp3_header(&$params) {
    return theme('takepart3_header', $params);
}

function _render_tp3_footer(&$params) {
    return theme('takepart3_footer', $params);
}

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
    //if ( substr($item['#href'], 0, 4) == 'http' ) {
	//	$items[$ikey]['#href'] = $_SERVER['HTTP_HOST'] . $item['#href'];
    //}

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
