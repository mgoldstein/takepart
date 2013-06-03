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

function takepart_core_preprocess_page(&$variables) {
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

function takepart_core_preprocess_html(&$variables) {
    // Optimizely
    drupal_add_js('//cdn.optimizely.com/js/77413453.js', array(
        'type' => 'external',
        'scope' => 'footer',
        'group' => JS_DEFAULT,
        'every_page' => TRUE,
        'weight' => -1,
    ));

	// Batshit crazy nav stuff
	if ((!isset($variables['user_nav'])) || (!$variables['user_nav'])) {
		$variables['user_nav'] = _render_tp3_user_menu($variables);
	}
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

function takepart_core_form_search_api_page_search_form_site_search_alter(&$form, &$form_state, $form_id) {
  $form['keys_2']['#attributes'] = array('placeholder' => array("Search"));
  // On the 404 page, unset any form tokens so that we bypass attempted validation ( and give a warning to authenticated users )
  if (request_uri() == '/' . drupal_get_normal_path(variable_get('static_404', ''))) {
    unset($form['form_token']);
    unset($form['#token']);
  }
}

function takepart_core_css_alter(&$css) {
  _alter_generated_css($css);
}

/* Custom functions */

/**
 * Helper functions for header / footer.
 */
function _tp3_fill_template_vars(&$variables) {
    if ((!isset($variables['takepart_theme_path'])) || (!$variables['takepart_theme_path'])) {
        $variables['takepart_theme_path'] = drupal_get_path('theme', 'takepart3');
    }
    if ((!isset($variables['follow_us_links'])) || (!$variables['follow_us_links'])) {
        $variables['follow_us_links'] = theme('takepart3_follow_us_links', $variables);
    }
	// Batshit crazy nav stuff
	if ((!isset($variables['user_nav'])) || (!$variables['user_nav'])) {
		$variables['user_nav'] = _render_tp3_user_menu($variables);
	}
}

function _render_tp3_header(&$params) {
    return theme('takepart3_header', $params);
}

function _render_tp3_footer(&$params) {
    return theme('takepart3_footer', $params);
}

function _alter_generated_css(&$css) {
	return;
  // Pull important styles from the themes .info file and place them above all stylesheets.
	foreach ($css as $i => $style_from_foo) {
		$dirname = dirname($i);
		$basename = basename($i);
		$file = explode('.', $basename);
		$filename = $file[0] . '-sprite.' . $file[1];
		if ( file_exists($dirname . '/' . $filename) ) {
			if ( filemtime($i) - filemtime($dirname . '/' . $filename) < 10 ) {
				$new = str_replace($basename, $filename, $i);
				//$css[$new]['data'] = $new;
				//unset($css[$i]);
				$css[$i]['data'] = $new;
			}
		}
	}
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
  } elseif ( is_array($var) && isset($var['safe_value']) ) {
    return $var['safe_value'];
  } elseif ( is_object($var) && $prop && isset($var->{$prop}) && is_string($var->{$prop}) ) {
    return $var->{$prop};
  } elseif ( is_object($var) && $prop ) {
    $ret = field_get_items($type, $var, $prop);
    if ( is_array($ret) ) return _s($ret[0]);
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
  } elseif ( isset($var['value']) ) {
    return $var['value'];
  }
}

/* Return a URL */
function _surl($var, $prop = NULL, $type = 'node') {
  if ( is_array($var) && isset($var[0]) && isset($var[0]['node']) ) {
    return url('node/' . $var[0]['node']->nid);
  } elseif ( is_array($var) && isset($var[0]) && isset($var[0]['nid']) ) {
    return url('node/' . $var[0]['nid']);
  } elseif ( is_array($var) && isset($var['node']) ) {
    return url('node/' . $var['node']->nid);
  } elseif ( is_object($var) && isset($var->_surl) ) {
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
function _simage($var, $prop = NULL, $type = 'node', $style = null) {
  if ( is_object($var) && $prop ) {
    if ( isset($var->_stype) ) $type = $var->_stype;
    $var = field_get_items($type, $var, $prop);
  }

  $image = null;
  if ( is_object($var) && get_class($var) == 'EntityStructureWrapper' ) {
    $var = $var->value();
  }

  if ( isset($var['file']) ) {
    $image = (array)$var['file'];
  } elseif ( isset($var['type']) && $var['type'] == 'image') {
    $image = $var;
  } elseif ( isset($var[0]) && isset($var[0]['file']) ) {
    $image = (array)$var[0]['file'];
  } elseif ( isset($var[0]) && isset($var[0]['fid']) ) {
    $image = file_load($var[0]['fid']);
    $image = (array)$image;
  } elseif ( isset($var[0]) ) {
    $image = $var[0];
  } else {
    return '';
  }

  if ( $style ) {
    if ( !isset($image['path']) ) {
      $image['path'] = $image['uri'];
    }

    $image['style_name'] = $style;
    $image['getsize'] = TRUE;
    return theme('image_style', $image);
  } else {
    if ( !isset($image['path']) ) {
      $image['path'] = file_create_url($image['uri']);
    }

    return theme('image', $image);
  }
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
function _snode($var, $prop = null, $type = 'node') {
  if ( is_object($var) && $prop ) {
    $var = field_get_items($type, $var, $prop);
    return $var;
  }

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

  list($k, $ea) = each($var);

  if ( !$ea ) {
    reset($var);
    return $ea;
  }

  if ( isset($ea['node']) ) {
    return array($k, $ea['node']);
  }

  $taxonomy_term = null;
  if ( isset($ea['tid']) ) {
    $taxonomy_term = taxonomy_term_load($ea['tid']);
  } elseif ( isset($ea['taxonomy_term']) ) {
    $taxonomy_term = $ea['taxonomy_term'];
  }

  if ( $taxonomy_term ) {
    $uri = entity_uri('taxonomy_term', $taxonomy_term);
    $taxonomy_term->_surl = url($uri['path']);
    $taxonomy_term->_stype = 'taxonomy_term';
    return array($k, $taxonomy_term);
  }

  if ( is_array($ea) && count($ea) < 3 && isset($ea['nid']) ) {
    $ea = node_load($ea['nid']);
  }

  return array($k, $ea);
}
