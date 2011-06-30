<?php

/**
 * Each item of the array should be keyed as follows:
 * url (String, 21 characters ) http://www.google.com
 * title (String, 7 characters ) Boo Boo
 * attributes (Array, 0 elements)
 * these are the normal results from a field.
 */
function takepart3_dolinks($links_field) {
  
  if(empty($links_field)) 
    return;
  
  $links = array();
  $opts = array('external' => TRUE);
  foreach($links_field as $link) {
    $links[] = l($link['title'], $link['url'], $opts);
  }
  
  return implode("<span class='delimiter'>|</span>", $links);
  
}

function takepart3_preprocess_page(&$variables) {

  //debug($main_menu_data);
  //debug(array_keys($main_menu_data));

  $variables['top_nav']               = _render_tp3_main_menu();
  $variables['hottopic_nav']          = _render_tp3_hottopics_menu();
  $variables['film_camp_nav']         = _render_tp3_film_campaign_menu();
  $variables['friends_takepart_nav']  = _render_tp3_friends_takepart_menu();
  $variables['takepart_topics_nav']   = _render_tp3_topics_takepart_menu();
  $variables['corporate_links_nav']   = _render_tp3_corporate_links_menu();
  $variables['user_nav']              = _render_tp3_user_menu();
  $variables['takepart_theme_path']   = drupal_get_path('theme', 'takepart3');
  
  // Adds page template suggestions for specific content types
  if (isset($variables['node'])) {  
    $variables['theme_hook_suggestions'][] = 'page__type__'. $variables['node']->type;
  }
  
  return $variables;
}


/**
 * Helper to output the custom HTML for out main menu.
 */
function _render_tp3_main_menu() {
  $menu_data = menu_tree_page_data("main-menu");

  $links = array();
  foreach($menu_data as $menu_item) {
    $opts = array(
      'attributes' => _default_menu_options($menu_item),
    );
    
    $link = l($menu_item['link']['title'], $menu_item['link']['href'], $opts);
    $links[] = "<li>". $link ."</li>";
  }
  
  return "<ul id='top-nav'>" . implode($links) ."</ul>";
}

/**
 * Helper to output the custom HTML for out main menu.
 */
function _render_tp3_user_menu() {
  $menu_data = menu_tree_page_data("user-menu");

  $links = array();
  foreach($menu_data as $menu_item) {
    $opts = array(
      'attributes' => _default_menu_options($menu_item),
    );
    if($menu_item['link']['href'] == 'user') {
      if (user_is_logged_in()) {
        global $user;
        $menu_item['link']['title'] = $user->name;
        $menu_item['link']['href'] = 'user/' . $user->uid . '/edit';
      } 
      else {
        $menu_item['link']['title'] = variable_get("takepart_user_login_link_name","Login or");
      }
    }
    
    $link = l($menu_item['link']['title'], $menu_item['link']['href'], $opts);
    $links[] = "<li>". $link ."</li>";
  }
    $output = "<ul id='user-nav'>" . implode($links) ."</ul>";
    
    if (!user_is_logged_in()) {
    	$output .= 	"<span class='fb'>  			 
  				  <fb:login-button>Connect</fb:login-button>
  				</span>";
    }
  
  return $output;
}

/**
 * Helper to output the custom HTML for out hot topic menu.  
 * could be refactored to just one menu themer, but since the class and such were
 * sllightly different, waiting to see how the submenus pan out.
 */
function _render_tp3_hottopics_menu() {
  $menu_data = menu_tree_page_data("menu-hot-topics");

  $links = array( 0 => "<li class='title'>hot topics:</li>" );
  
  foreach($menu_data as $menu_item) {
     
    $opts = array(
      'attributes' => _default_menu_options($menu_item),
    );
    
    $link = l($menu_item['link']['title'], $menu_item['link']['href'], $opts);
    $links[] = "<li>". $link ."</li>";
  }
  
  return "<ul class='clearfix'>" . implode($links) ."</ul>";
}

function _render_tp3_corporate_links_menu() {
  $menu_data = menu_tree_page_data("menu-takepart-links");

  $links = array();
  
  foreach($menu_data as $menu_item) {
    $opts = array(
      'attributes' => _default_menu_options($menu_item),
    );
    
    $link = l($menu_item['link']['title'], $menu_item['link']['href'], $opts);
    $links[] = "<li>". $link ."</li>";
  }
  
  return "<ul class='clearfix' id='global-links'>" . implode($links) ."</ul>";
}

function _render_tp3_film_campaign_menu() {
  return _render_menu_columns("menu-takepart-film-campaigns", 4);
}

function _render_tp3_friends_takepart_menu() {
  return _render_menu_columns('menu-takepart-friends', 5);
}

function _render_tp3_topics_takepart_menu() {
  return _render_menu_columns('menu-takepart-topics', 4);
}

function _render_menu_columns($menu_key, $col_limit) {
  $menu_data = menu_tree_page_data($menu_key);
  $columns = array();
  $count = 0;

  foreach($menu_data as $menu_item) {
    // divide by number in each column
    $column_number = round(floor($count / $col_limit));
   
    $opts = array(
      'attributes' => _default_menu_options($menu_item),
    );
    $link = l($menu_item['link']['title'], $menu_item['link']['href'], $opts);
    $columns[$column_number][] = "<li>". $link ."</li>";
    $count++;
  }

  $menu_cols = "";
  foreach ($columns as $col) {
    $menu_cols .= "<div class='column'><ul>".  implode($col) ."</ul></div>\n";
  }
  return $menu_cols;
}


function _default_menu_options($menu_item) {
  $menu_opts = empty($menu_item['link']['options']['attributes']) ? array() : $menu_item['link']['options']['attributes'];
  return $menu_opts;
}


/**
 * Preprocessor for theme('block').
 */
function takepart3_preprocess_block(&$vars) {
  
  if ($vars['block']->module === 'boxes' && isset($vars['block']->boxes_plugin)) {
    if(!empty($vars['block']->title)){
      $vars['classes_array'][] = 'block-box-' . preg_replace( array('/[^a-zA-Z\s0-9]/', '/[\s]/', '/---|--/'), array('', '-', '-'), strtolower($vars['block']->title));
    }
    $vars['classes_array'][] = 'block-boxes-' . $vars['block']->boxes_plugin;
  }else if($vars['block']->module === 'views' && isset($vars['block']->subject)) {
    if(!empty($vars['block']->subject)){
      $vars['classes_array'][] = 'block-view-' . preg_replace( array('/[^a-zA-Z\s0-9]/', '/[\s]/', '/---|--/'), array('', '-', '-'), strtolower($vars['block']->subject));
    }
  }
}

/*
function takepart3_preprocess_node(&$vars){ 
  if($vars['type'] == 'openpublish_article'){
    $vars['submitted'] = '';
  }
}
*/