<?php

function listArrayRecursive($someArray, $prepend = '') {
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

/*
  Preprocess
*/

function chunkpart_preprocess_html(&$vars) {
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

/*
function chunkpart_preprocess_page(&$vars,$hook) {
  //typekit
  //drupal_add_js('http://use.typekit.com/XXX.js', 'external');
  //drupal_add_js('try{Typekit.load();}catch(e){}', array('type' => 'inline'));

  //webfont
  //drupal_add_css('http://cloud.webtype.com/css/CXXXX.css','external');
  
  //googlefont 
  //  drupal_add_css('http://fonts.googleapis.com/css?family=Bree+Serif','external');
 
}

function chunkpart_preprocess_region(&$vars,$hook) {
  //  kpr($vars['content']);
}

function chunkpart_preprocess_block(&$vars, $hook) {
  //  kpr($vars['content']);

  //lets look for unique block in a region $region-$blockcreator-$delta
   $block =  
   $vars['elements']['#block']->region .'-'. 
   $vars['elements']['#block']->module .'-'. 
   $vars['elements']['#block']->delta;
   
  // print $block .' ';
   switch ($block) {
     case 'header-menu_block-2':
       $vars['classes_array'][] = '';
       break;
     case 'sidebar-system-navigation':
       $vars['classes_array'][] = '';
       break;
    default:
    
    break;

   }


  switch ($vars['elements']['#block']->region) {
    case 'header':
      $vars['classes_array'][] = '';
      break;
    case 'sidebar':
      $vars['classes_array'][] = '';
      $vars['classes_array'][] = '';
      break;
    default:

      break;
  }

}

function chunkpart_preprocess_node(&$vars,$hook) {
  //  kpr($vars['content']);
}

function chunkpart_preprocess_comment(&$vars,$hook) {
  //  kpr($vars['content']);
}

function chunkpart_preprocess_field(&$vars,$hook) {
  //  kpr($vars['content']);
  //add class to a specific field
  switch ($vars['element']['#field_name']) {
    case 'field_ROCK':
      $vars['classes_array'][] = 'classname1';
    case 'field_ROLL':
      $vars['classes_array'][] = 'classname1';
      $vars['classes_array'][] = 'classname2';
      $vars['classes_array'][] = 'classname1';
    case 'field_FOO':
      $vars['classes_array'][] = 'classname1';
    case 'field_BAR':
      $vars['classes_array'][] = 'classname1';    
    default:
      break;
  }

}

function chunkpart_preprocess_maintenance_page(){
  //  kpr($vars['content']);
}
*/