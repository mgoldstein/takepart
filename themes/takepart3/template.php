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
    if(empty($opts['attributes']['title'])){
      unset($opts['attributes']['title']);
    }
    
    if($menu_item['link']['href'] == 'user') {
      if (user_is_logged_in()) {
        global $user;
        $menu_item['link']['title'] = $user->name;
        $menu_item['link']['href'] = 'user/' . $user->uid . '/edit';
      } 
      else {
        $opts['attributes']['class'][] = 'join-login';
        $menu_item['link']['title'] = variable_get("takepart_user_login_link_name","Login or");
      }
      
    }else{
        switch($menu_item['link']['href']){
          case 'user/register':
            $opts['attributes']['class'][] = 'join-takepart';
            break;
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
function takepart3_preprocess_node(&$vars, $hook) {
  
  // Suggests a custom template for embedded node content through the WYSIWYG
  if($vars['view_mode'] == 'embed') {
      $vars['theme_hook_suggestions'][] = 'node__embed';
  }   
  
  // Provides a method for printing regions within node templates
  if ($blocks = block_get_blocks_by_region('sidebar_first')) {
    $vars['sidebar_first'] = $blocks;
    $vars['sidebar_first']['#theme_wrappers'] = array('region');
    $vars['sidebar_first']['#region'] = 'sidebar_first';
  }
  
  // Rewrites the 'Submitted' text for each node
  $vars['submitted'] = "<div class='submitted-wrapper'><div class='submitted clearfix'>" . render($vars['content']['field_author']) . '<div class="field article-date">' . render($vars['date']) . '</div><div class="field article-comment-count"><a href="#comments">' . render($vars['node']->comment_count) . ' comments </a></div></div></div>';
  
  
  // Standardizes the variable names for each 'Subhead' field for the below content types. Removes logic from tpl.
  // Use render($content['subhead']) in node templates to print all subheads.
  if($hook == 'node'){
    foreach(array('field_article_subhead', 'field_blogpost_subhead') as $key => $value){
      if(isset($vars['content'][$value]) && !empty($vars['content'][$value])){
        $vars['content']['subhead'] = $vars['content'][$value];
        hide($vars['content'][$value]);
        break;
      }
    }
  }
    
}


// Rewrites 'field_tp_campaign_4_things_link' in Campaign content types
// Prepends a <span> with id before each bullet point for theming
function takepart3_field__field_tp_campaign_4_things_link(&$vars){
  $output = '';
  foreach($vars['items'] as $key => &$value){
     $output .= "<span class='campaign-link campaign-link-" . ($key+1) . "'>" . ($key+1) . "</span>" . $vars['items'][$key]['#markup'];
  }
  return '<div class="field-name-field-tp-campaign-4-things-link">' . $output . '</div>';  
}


// Renders a comma separated list of taxonomy terms for a node
// Used in page.tpl.php
function _render_tp3_taxonomy_links($content) {
  
    // Set labels to hidden, if they aren't already
    $content['field_free_tag']['#label_display'] = 'hidden';
    $content['field_topic']['#label_display'] = 'hidden';
    
    // Merge and modify the output
    $combined_markup = render($content['field_topic']) . render($content['field_free_tag']);
    $output = str_replace("<a", ", <a", $combined_markup); // adds commas
    $output = strip_tags($output, '<a>'); // strips div tags
    $output = substr($output, 2); // removes first comma
    
    return '<div class="node-topics"><div class="node-topics-label">Topics</div>' . $output . '</div>';
}


/**
 * Preprocessor for theme('block').
 *
 *  - Adds additional classes based on block title, view and delta
 *
 */
function takepart3_preprocess_block(&$vars) {
  
    if (!empty($vars['block']->title)) {
      $vars['classes_array'][] = 'block-boxes-title-' . preg_replace( array('/[^a-zA-Z\s0-9]/', '/[\s]/', '/---|--/'), array('', '-', '-'), strtolower($vars['block']->title));
    }
  
    if(!empty($vars['elements']['#block']->current_view)){
      $vars['classes_array'][] = 'block-boxes-current-' . $vars['elements']['#block']->current_view;
    }
  
    if(!empty($vars['elements']['content']['#views_contextual_links_info']['views_ui']['view_name'])){
      $vars['classes_array'][] = 'block-boxes-view-name-' . $vars['elements']['content']['#views_contextual_links_info']['views_ui']['view_name'];
    }
  
    if(!empty($vars['elements']['#block']->delta)){
      $vars['classes_array'][] = 'block-boxes-delta-' . $vars['elements']['#block']->delta;
    }

}
