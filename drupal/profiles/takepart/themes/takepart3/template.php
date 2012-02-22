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




function takepart3_preprocess_html(&$vars){
  if (context_isset('takepart3_page', 'campaign_is_multipage') && context_get('takepart3_page', 'campaign_is_multipage')){
    $vars['classes_array'][]= 'multipage-campaign';
  }  
  _render_tp3_renderheaderfooterfeed($vars);
}

function takepart3_preprocess_page(&$variables) {

  _tp3_fill_template_vars($variables);

  $variables['is_multipage'] = FALSE;
  $variables['multipage_class'] = '';
  
  // Adds page template suggestions for specific content types
  if (isset($variables['node'])) {
    $variables['theme_hook_suggestions'][] = 'page__type__'. $variables['node']->type;
    
    if (!empty($variables['node']->field_multi_page_campaign[$variables['node']->language][0]['context'])) {
      $variables['is_multipage'] = TRUE;
      context_set('takepart3_page', 'campaign_is_multipage', TRUE);
      $variables['multipage_class'] = 'page-multipage';// although this is not needed because the context set the body class itself
    }

    if ($variables['node']->type == 'takepart_campaign') {
      if (!empty($variables['node']->field_tp_campaign_show_title[$variables['node']->language][0]['value'])) {
        unset($variables['page']['highlighted']['takepart_custom_page_title_h1']);
      }
    }
  }
  
  $status = drupal_get_http_header('status');
  $status_code = explode(' ', $status);
  if ($status_code[0] == '403') {
    unset($variables['page']['sidebar_second']);
  }  
  
  $variables['header']  = _render_tp3_header($variables);
  $variables['footer']  = _render_tp3_footer($variables);
  
  //if shares don't exists in the left sidebar, add them to the top:
  if($variables['node']->type == 'takepart_campaign') {
    if($variables['page']['sidebar_first']) {
      if (!array_key_exists('takepart_addthis_addthis_full', $variables['page']['sidebar_first'])) {
        if ((array_key_exists('highlighted', $variables['page'])) && (!array_key_exists('takepart_addthis_addthis_simple', $variables['page']['highlighted']))) {
          $block = block_load('takepart_addthis', 'addthis_simple');
          $addthisblock = array();
          $addthisblock['takepart_addthis_addthis_simple'] = (_block_get_renderable_array(_block_render_blocks(array($block))));
          array_unshift($variables['page']['highlighted'], $addthisblock);
        }
      }
    }
  }
  
  return $variables;
}

/**
 * Helper to output the custom HTML for out main menu.
 * starting release 342 we are using a new design and dropdown menu
 * We need to have the menus children rendered
 */
function _render_tp3_main_menu() {
  $tree = menu_tree("main-menu");
  return drupal_render($tree); 
}

function _render_tp3_main_menu_341() {
  $menu_data = menu_tree_page_data("main-menu");

  $links = array();
  $count = count($menu_data);
  $i = 0;
  foreach($menu_data as $menu_item) {
    $opts = array(
      'attributes' => _default_menu_options($menu_item),
    );
    
    $link = l($menu_item['link']['title'], $menu_item['link']['href'], $opts);
    if ($i == 0) {
      $li = '<li class="first">';
    } elseif ($i == ($count - 1)) {
      $li = '<li class="last">';
    } else {
      $li = '<li>';
    }
    $links[] = $li . $link ."</li>";
    $i++;
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
    
    $opts['attributes']['class'][] = 'user-menu-'.strtolower($menu_item['link']['title']);
    
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
        $opts['query'] = array("destination" => current_path());
        $menu_item['link']['title'] = variable_get("takepart_user_login_link_name","Login");
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

  $links = array( 0 => "<li class='title'>hot topics</li>" );
  
  $count = count($menu_data);
  $i = 0;
  foreach($menu_data as $menu_item) {
     
    $opts = array(
      'attributes' => _default_menu_options($menu_item),
    );
    
    $link = l($menu_item['link']['title'], $menu_item['link']['href'], $opts);
    if ($i == 0) {
      $li = '<li class="first">';
    } elseif ($i == ($count - 1)) {
      $li = '<li class="last">';
    } else {
      $li = '<li>';
    }
    $links[] = $li . $link ."</li>";
    $i++;
  }
  
  return "<ul class='clearfix'>" . implode($links) ."</ul>";
}

function _render_footer_links_menu($menu_key) {
  $menu_data = _tp_menu_tree_data($menu_key);

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

function _render_tp3_corporate_links_menu() {
  return _render_footer_links_menu("menu-takepart-links");
}
function _render_tp3_film_campaign_menu() {
  return _render_footer_links_menu("menu-takepart-film-campaigns");
}

function _render_tp3_friends_takepart_menu() {
  return _render_footer_links_menu('menu-takepart-friends');
}

function _render_tp3_topics_takepart_menu() {
  return _render_menu_columns('menu-takepart-topics', 6);
}

// so we need to render the menus as follows,
// order from top to bottom, but distribute evenly from left 
// to right.
function _render_menu_columns($menu_key, $col_limit) {
  $menu_data = _tp_menu_tree_data($menu_key);
  $columns = array();
  
  $total_items    = count($menu_data);
  $remainder_row = $total_items % $col_limit;
   
  $column_idx = 0;

  $half = count($menu_data)/2;
  
    foreach($menu_data as $menu_item) {
    $opts = array('attributes' => _default_menu_options($menu_item));
    $link = l($menu_item['link']['title'], $menu_item['link']['href'], $opts); 
    
    $columns[$column_idx][] = "<li>". $link ."</li>";
    
    if (count($columns[$column_idx]) > $half) {
      $column_idx++;
    }
  }
  
  $menu_cols = "";
  
  // add links to column 0 up to max #, then add the rest to second column

  
  foreach ($columns as $col) {
    $menu_cols .= "<div class='column'><ul>".  implode($col) ."</ul></div>\n";
  }
  
  return $menu_cols;
}

function _tp_col_depth($total, $col_limit, $remainder) {
  return floor($total / $col_limit) + ( $remainder === 0 ? 0 : 1);
}

function _tp_menu_tree_data($menu_key) {
  $menu_data = menu_tree_page_data($menu_key);
  
  return $menu_data;
  
  // $item['link']['hidden'] = 0
}

function _default_menu_options($menu_item) {
  $menu_opts = empty($menu_item['link']['options']['attributes']) ? array() : $menu_item['link']['options']['attributes'];
  return $menu_opts;
}

function takepart3_views_pre_render(&$vars) {
  if ($vars->name == 'featured_items' && $vars->current_display == 'block') {
    for ($i=0;$i<sizeof($vars->result);$i++) {
      if (!empty($vars->result[$i]->field_field_thumbnail)) {
        $vars->result[$i]->field_field_gallery_main_image = array();
        $vars->result[$i]->field_field_article_main_image = array();
        $vars->result[$i]->field_field_page_main_image = array();
        $vars->result[$i]->field_field_blogpost_main_image = array();
      }
    }
  }
}

/**
 * Preprocessor for theme('block').
 */
function takepart3_preprocess_node(&$vars, $hook) {
    
  // Suggests a custom template for embedded node content through the WYSIWYG
  // We suggest a theme for a general embed as well as for each content type
  //
  if($vars['view_mode'] == 'embed') {
      $vars['theme_hook_suggestions'][] = "node__embed";
      $vars['theme_hook_suggestions'][] = "node__embed__{$vars['type']}";
  }   
  // Provides a method for printing regions within node templates
  if ($blocks = block_get_blocks_by_region('sidebar_first')) {
    $vars['sidebar_first'] = $blocks;
    $vars['sidebar_first']['#theme_wrappers'] = array('region');
    $vars['sidebar_first']['#region'] = 'sidebar_first';
  }
  
  // Adds a 'Featured Action' link into the body of a blog entry automatically (TPB-423)
  if($hook == 'node'){
    if($vars['type'] == 'openpublish_article' || $vars['type'] == 'openpublish_blog_post'){

      $end = '/p>'; // end of a paragraph tag  
      
      if($vars['type'] == 'openpublish_article'){
        $featured_action = render($vars['content']['field_article_action']);
      }else{
        $featured_action = render($vars['content']['field_blogpost_featured_action']);  
      }

      $pos = 0; // Find the position of the end of the 3rd paragraph
      for($i=0;$i<3;$i++){
        $pos = strpos($vars['content']['body'][0]['#markup'], $end, $pos)+1;
      }

      $vars['content']['body'][0]['#markup'] = substr_replace($vars['content']['body'][0]['#markup'], $featured_action, $pos+2, 0);
    }

    $vars['remove_title'] = FALSE;
    if (!empty($vars['field_tp_campaign_show_title'][0]['value'])) {
      $vars['remove_title'] = TRUE;
    }    
  }
  
  // add read more link to blog posts.
  if ($hook == 'node' && $vars['view_mode'] == 'teaser' && $vars['type'] == 'openpublish_blog_post') {
    $markup_size = strlen($vars['content']['body'][0]['#markup']);
    $safe_size    = strlen($vars['body'][0]['safe_value']);

    // if markup and safe_value differ, then there is a page break.
    if ($markup_size < $safe_size) {
      $more_link = l("Continue Reading &raquo;", "node/". $vars['nid'], array('html' => TRUE));
      $vars['content']['body'][0]['#markup'] .= "<span class='blog-post-continue-reading-link'>" . $more_link . "</span>"; 
    }
  }
  /* add in out link to the title */
  if ($hook == 'node' && $vars['view_mode'] == 'embed' && $vars['type'] == 'openpublish_video') {
    $vars['content']['embedded_video_link'] = array(
      '#weight' => 10,
      '#theme' => 'link',
      '#text' => 'Full Video',
      '#path' => "node/". $vars['nid'],
      '#options' => array('html' => FALSE, 'attributes' => array('class' => 'embedded-video-link')),
    );
  }
  /* see https://takepart1.fogbugz.com/default.asp?17143*/
    if (isset($vars['field_tp_campaign_show_title']) && !empty($vars['field_tp_campaign_show_title'][$vars['language']]['0']['value'])) {
  	unset($vars['title']);
  }
}

/* Comment form */
function takepart3_form_comment_form_alter(&$form, &$form_state, $form_id) {
  $form['author']['#prefix'] = '<div class="comment-form-title">';
  $form['author']['#suffix'] = '<div class="comment-edge"></div></div>';
  unset($form['author']['_author']['#title']);
}

function takepart3_field__field_author(&$vars){

  // Author
  $authors = array();
  foreach($vars['items'] as $key => $value){
    $authors[] = render($value);
  }

  switch(count($authors)){
    case 1:
      $authors = $authors[0];
      break;
    case 2:
      $authors = implode( ' & ', $authors);
      break;
    default:
      $last_author = array_pop($authors);
      $authors = implode( ' & ', array(implode(', ', $authors), $last_author));
      break;
  }
  
  // Date
  $date = format_date($vars['element']['#object']->created, 'medium', 'F j, Y');
  
  //Comments
  $comments = $vars['element']['#object']->comment_count;
  
  return sprintf("<div class='submitted-wrapper'><div class='submitted clearfix'><div class='field field-author'>By %s</div><div class='field article-date'>%s</div><div class='field article-comment-count'><a href='#comments'>%s comments</a></div></div></div>", $authors, $date, $comments);
}

// Rewrites 'field_tp_campaign_4_things_link' in Campaign content types
// Prepends a <span> with id before each bullet point for theming
function takepart3_field__field_tp_campaign_5_things_head(&$vars){
  return '<div class="field field-name-field-tp-campaign-5-things-head"><div class="field-items field-5-things-head">' . $vars['element']['#items'][0]['safe_value'] . '</div>';

}

function takepart3_field__field_tp_campaign_header(&$vars){
  return '<div class="field field-name-field-tp-campaign-header field-type-media field-label-hidden"><div class="field-items"><div class="field-item even">' . l(render($vars['element'][0]), 'node/' . $vars['element']['#object']->nid, array('html' => TRUE)) . '</div></div></div>';
}

function takepart3_field__field_tp_campaign_4_things_link(&$vars){
  $output = '';
  foreach($vars['items'] as $key => &$value){
     $output .= "<span class='campaign-link campaign-link-" . ($key+1) . "'>" . ($key+1) . "</span>" . str_replace('&amp;amp;', '&amp;', $vars['items'][$key]['#markup']);
  }
  return '<div class="field-name-field-tp-campaign-4-things-link">' . $output . '</div></div>';  
}

function takepart3_field__field_tp_campaign_cover_link(&$vars){
  if(!empty($vars['element']['#items'][0])){
    return "<div class='field field-name-field-tp-campaign-cover-link field-type-link-field field-label-hidden'><div class='field-items'><div class='field-item even'>" . str_replace('&amp;amp;', '&amp;', $vars['items'][0]['#markup']) . "</div></div></div>";
  }
}


function takepart3_field__field_tp_campaign_intro_media(&$vars) {
  $delta = 0;
  $output = '<div class="field field-name-field-tp-campaign-intro-media field-type-media field-label-hidden"><div class="field-items">';
  
  // Videos go first
  foreach ($vars['element']['#items'] as $id => $item) {
    if ($item['file']->type == 'video') {
      $output .= '<div class="field-item ' . ($delta % 2 ? "odd" : "even") . ' field-item-video">' . render($vars['element'][$id]) . '</div>';
      $delta++;
    }
  }
  // Images go next
  foreach ($vars['element']['#items'] as $id => $item) {
    if ($item['file']->type == 'image') {
      $output .= '<div class="field-item ' . ($delta % 2 ? "odd" : "even") . ' field-item-image">' . render($vars['element'][$id]) . '</div>';
      $delta++;
    }
  }
  
  $output .= '</div></div>';
  return $output;
}



function takepart3_field__field_group_url(&$vars){
  if(isset($vars['element']['#items'][0]) & $vars['element']['#items'][0]){
    return "<div class='field field-name-field-group-url'>" . l('Visit Website', $vars['element']['#items'][0]['url']) . "</div>";
  }
}

function takepart3_field__field_tp_campaign_seg_1_rel(&$vars){
  $output = '';
  foreach ($vars['element']['#items'] as $item) {
    $node_type = takepart3_return_node_type($item['node']->type);
    $output .= '<div class="field-name-field-tp-campaign-seg_rel">';
    $output .= '<div class="title">' . check_plain($item['node']->title) . '</div>';
    $output .= l(t('View') . ' ' . $node_type . ' &raquo;', $item['node']->uri['path'], array('html' => TRUE)) . '</div>';
  }
  return $output;
}

function takepart3_field__field_tp_campaign_seg_2_rel(&$vars){
  $output = '';
  foreach ($vars['element']['#items'] as $item) {
    $node_type = takepart3_return_node_type($item['node']->type);
    $output .= '<div class="field-name-field-tp-campaign-seg_rel">';
    $output .= '<div class="title">' . check_plain($item['node']->title) . '</div>';
    $output .= l(t('View') . ' ' . $node_type . ' &raquo;', $item['node']->uri['path'], array('html' => TRUE)) . '</div>';
  }
  return $output;
}

function takepart3_field__field_tp_campaign_seg_3_rel(&$vars){
  $output = '';
  foreach ($vars['element']['#items'] as $item) {
    $node_type = takepart3_return_node_type($item['node']->type);
    $output .= '<div class="field-name-field-tp-campaign-seg_rel">';
    $output .= '<div class="title">' . check_plain($item['node']->title) . '</div>';
    $output .= l(t('View') . ' ' . $node_type . ' &raquo;', $item['node']->uri['path'], array('html' => TRUE)) . '</div>';
  }
  return $output;
}

function takepart3_field__field_tp_campaign_seg_4_rel(&$vars){
  $output = '';
  foreach ($vars['element']['#items'] as $item) {
    $node_type = takepart3_return_node_type($item['node']->type);
    $output .= '<div class="field-name-field-tp-campaign-seg_rel">';
    $output .= '<div class="title">' . check_plain($item['node']->title) . '</div>';
    $output .= l(t('View') . ' ' . $node_type . ' &raquo;', $item['node']->uri['path'], array('html' => TRUE)) . '</div>';
  }
  return $output;
}

function takepart3_return_node_type($type) {
  switch ($type) {
    case 'action': 
      return t('Action');
    case 'openpublish_article':
      return t('Article');
    case 'audio': 
      return t('Audio');
    case 'openpublish_blog_post':
      return t('Blog Post');
    case 'takepart_campaign': 
      return t('Campaign');
    case 'takepart_group':
      return t('Group');            
    case 'takepart_list': 
      return t('List');
    case 'takepart_page':
      return t('Page');    
    case 'openpublish_photo_gallery': 
      return t('Photo Gallery');
    case 'takepart_quick_study':
      return t('Quick Study');   
    case 'openpublish_video': 
      return t('Video');         
  }
  
  return '';
}


function takepart3_field__field_topic($vars){
  
  $field_free_tag = isset($vars['element']['#object']->field_free_tag['und']) ? $vars['element']['#object']->field_free_tag['und'] : $vars['element']['#object']->field_free_tag;
  if(count($vars['items']) || count($field_free_tag)){
    $links = array();
    foreach($vars['items'] as $key => $value){
      if(isset($value['#href'])) {
        $links[] = "<a href='" . url($value['#href']) . "'>" . $value['#title'] . '</a>';
      }
    }

    foreach($field_free_tag as $key => $value){
      $term = taxonomy_term_load($value['tid']);
      $links[] = "<a href='" . url('taxonomy/term/' . $value['tid']) . "'>" . $term->name . '</a>';
    }
    return '<div class="node-topics"><div class="node-topics-label">Topics</div>' . implode(', ', $links) . '</div>';
  }
}

function takepart3_preprocess_comment(&$vars){
  $vars['submitted'] = 'posted on ' . format_date($vars['elements']['#comment']->created, 'medium', 'M j, Y');
  //unlinking author name for logged in users
  $vars['author'] = '<span>' . $vars['author'] = $vars['elements']['#comment']->name . '</span>';
}
/**
 * Preprocessor for theme('block').
 *  - Adds additional classes based on block title, view and delta
 */
function takepart3_preprocess_block(&$vars) {

    if (!empty($vars['block']->title)) {
      $vars['classes_array'][] = 'block-boxes-title-' . preg_replace( array('/[^a-zA-Z\s0-9]/', '/[\s]/', '/---|--/'), array('', '-', '-'), strtolower($vars['block']->title));
    }
  
    if(!empty($vars['elements']['#contextual_links']['views_ui'][1][0])){
      $vars['classes_array'][] = 'block-boxes-view-name-' . $vars['elements']['#contextual_links']['views_ui'][1][0];
    }
    
    if(!empty($vars['elements']['#block']->current_view)){
      $vars['classes_array'][] = 'block-boxes-current-' . $vars['elements']['#block']->current_view;
    }
  
    if(!empty($vars['elements']['#block']->delta)){
      $vars['classes_array'][] = 'block-boxes-delta-' . $vars['elements']['#block']->delta;
    }
    
    if(!empty($vars['elements']['#block']->bid)){
      $vars['classes_array'][] = 'block-boxes-bid-' . $vars['elements']['#block']->bid;
    }
    
    if (in_array($vars['elements']['#block']->delta, array('box-4abd00a3', 'box-33756e58', 'box-5cd7d5ce', 'box-95b55e7', 'box-a08d035e'))) {
      if (stripos($vars['content'], '<div class="boxes-box-content"></div>')) {
        $vars['content'] = '';
      }
    }

    if (in_array($vars['elements']['#block']->delta, array('box-2988d8fb'))) {
      if (stripos($vars['content'], '<object')) {
        $vars['content'] = str_replace('<object', '<a class="play" href="#" style="display: none;">Play</a><div class="campaign-video"><object', $vars['content']);
        $vars['content'] = str_replace('</object>', '</object><a class="close" href="#">Close</a></div>', $vars['content']);
      }
    }
}

function _render_tp3_quick_study_topics($node){
  $output = array();
  if(isset($node->field_topic)){
    foreach($node->field_topic['und'] as $key => $value){
      $term = taxonomy_term_load($value['tid']);
      $output[] = l( $term->name, url('taxonomy/term/' . $value['tid']) );
    }
  }
  return '<div class="node-takepart-quick-study-topics field-name-field-display-tag">' . implode(' | ', $output) . '</div>';
}

/**
 * Theme function for displaying search results.
 */
function takepart3_search_api_page_results(array $variables) {
  drupal_add_css(drupal_get_path('module', 'search_api_page') . '/search_api_page.css');

  $index = $variables['index'];
  $results = $variables['results'];
  $entities = $variables['entities'];
  $keys = $variables['keys'];

  $output = '<p class="search-performance">' . format_plural($results['result count'],
      'Current search found 1 result for ' . check_plain($keys),
      'Current search found @count results for ' . check_plain($keys),
      array('@sec' => round($results['performance']['complete'], 3))) . '</p>';

  if (!$results['result count']) {
    $output .= "\n<h2>" . t('Your search yielded no results') . "</h2>\n";
    return $output;
  }
  else {
    $block = module_invoke('search_api_sorts', 'block_view', 'search-sorts');
    $output .= '<div id="block-search-api-sorts-search-sorts"><h2>Sort by:</h2><div class="content">' . $block['content'] . '</div></div>';
  }

  if ($variables['view_mode'] == 'search_api_page_result') {
    entity_prepare_view($index->entity_type, $entities);
    $output .= '<ol class="search-results">';
    foreach ($results['results'] as $item) {
      $output .= '<li class="search-result">' . theme('search_api_page_result', array('index' => $index, 'result' => $item, 'entity' => isset($entities[$item['id']]) ? $entities[$item['id']] : NULL, 'keys' => $keys)) . '</li>';
    }
    $output .= '</ol>';
  }
  else {
    $output .= '<div class="search-results">';
    $render = entity_view($index->entity_type, $entities, $variables['view_mode']);
    $output .= render($render);
    $output .= '</div>';
  }

  return $output;
}

/**
 * Theme function for displaying search results.
 *
 * @param array $variables
 *   An associative array containing:
 *   - index: The index this search was executed on.
 *   - result: One item of the search results, an array containing the keys
 *     'id' and 'score'.
 *   - entity: The loaded entity corresponding to the result.
 *   - keys: The keywords of the executed search.
 */
function takepart3_search_api_page_result(array $variables) {
  $index = $variables['index'];
  $id = $variables['result']['id'];
  $entity = $variables['entity'];

  $wrapper = entity_metadata_wrapper($index->entity_type, $entity);

  $url = entity_uri($index->entity_type, $entity);
  $name = entity_label($index->entity_type, $entity);

  if ($index->entity_type == 'file') {
    $url = array(
      'path' => file_create_url($url),
      'options' => array(),
    );
  }

  $text = '';
  if (!empty($variables['result']['excerpt'])) {
    $text = $variables['result']['excerpt'];
  }
  elseif (!empty($entity->field_promo_text[$entity->language][0]['safe_value'])) {
    $text = $entity->field_promo_text[$entity->language][0]['safe_value'];
  }
  
  $output = '';
  if (isset($entity->nid)){
    $type = takepart3_return_node_type($entity->type);
    if (!empty($type)) {
      $output = '<div class="views-field views-field-type"><span class="field-content">' . $type . '</span></div>';
    }
    $output .= '<h3>' . ($url ? l($name, $url['path'], $url['options']) : check_plain($name)) . "</h3>\n";
    if ($text) {
      $output .= $text;
    }
    $authors = _get_author($entity->nid);
    if (!empty($authors)){
      $output .= "<div class='by-line'>".t("Posted by !authors on @date", array('!authors'=> $authors,  '@date' => date('M d, Y', $entity->created))) . "</div>";
    }
  }
  return $output;
}

function _render_tp3_header_search_form() {
  return module_invoke('search_api_page', 'block_view', '2');
}


/**
 * find the authors of a nid.
 * Uses a caching mechanism based on static variable
 *  if the NID is already in the static array it will retrieve its value 
 *  if not will query the DB
 * then will build the HTML list
 */
function _get_author($nid) {
  static $nodes=array();
  #check first if we have the nid  
  $authors = array();
  if (isset($nodes[$nid])){
    $authors = $nodes[$nid];
  }
  else{
    $query = db_select('field_data_field_author', 'a');
    $query->addField('a', 'field_author_nid');
    $query->condition('a.entity_id', $nid);
  
    $query->join('field_data_field_profile_last_name', 'fpl', 'a.field_author_nid = fpl.entity_id');
    $query->join('field_data_field_profile_first_name', 'fpf', 'a.field_author_nid = fpf.entity_id');
    $query->addField('fpl', 'field_profile_last_name_value', 'last_name');
    $query->addField('fpf', 'field_profile_first_name_value', 'first_name');
    $query->orderBy('last_name', 'ASC')->orderby('first_name', 'ASC');
    $result = $query->execute();
    foreach($result as $record) {
      $authors[] = l($record->first_name ." ". $record->last_name, "node/".$record->field_author_nid);
    }

    if (empty($authors)){return NULL;}
    $nodes[$nid]=$authors;
  }
  switch(count($authors)){
    case 1:
      $authors = $authors[0];
      break;
    case 2:
      $authors = implode( ' & ', $authors);
      break;
    default:
      $last_author = array_pop($authors);
      $authors = implode( ' & ', array(implode(', ', $authors), $last_author));
      break;
  }

  return $authors;
}

/**
* Helper functions for header / footer.
*/
function _tp3_fill_template_vars(&$variables) {
  if(!$variables['top_nav']) $variables['top_nav'] = _render_tp3_main_menu();
  if(!$variables['hottopic_nav']) $variables['hottopic_nav'] = _render_tp3_hottopics_menu();
  if(!$variables['film_camp_nav']) $variables['film_camp_nav'] = _render_tp3_film_campaign_menu();
  if(!$variables['friends_takepart_nav']) $variables['friends_takepart_nav'] = _render_tp3_friends_takepart_menu();
  if(!$variables['takepart_topics_nav']) $variables['takepart_topics_nav'] = _render_tp3_topics_takepart_menu();
  if(!$variables['corporate_links_nav']) $variables['corporate_links_nav'] = _render_tp3_corporate_links_menu();
  if(!$variables['user_nav']) $variables['user_nav'] = _render_tp3_user_menu();
  if(!$variables['takepart_theme_path']) $variables['takepart_theme_path'] = drupal_get_path('theme', 'takepart3');
  if(!$variables['search_takepart_form']) $variables['search_takepart_form'] = _render_tp3_header_search_form();
  if(!$variables['follow_us_links']) $variables['follow_us_links'] = theme('takepart3_follow_us_links', $variables);

}

function _render_tp3_header(&$params) {
  return theme('takepart3_header', $params);
}

function _render_tp3_footer(&$params) {
  return theme('takepart3_footer', $params);
}
/*
 * Clears page, page bottom and top, fills custom section
 * with the header or footer depending on the path.
 */
function _render_tp3_renderheaderfooterfeed(&$vars) {
  $uri = drupal_get_path_alias($_GET['q']);
  $uri = substr($uri, 0, 14);
  if (($uri == 'iframes/header') || ($uri == 'iframes/footer')) {
    $vars['page_top'] = null;
    $vars['page_bottom'] = null;
    $vars['page'] = null;
    _tp3_fill_template_vars($vars);
    if ($uri == 'iframes/header') {
      $vars['custom'] = _render_tp3_header($vars);
    } elseif ($uri == 'iframes/footer') {
      $vars['custom'] = _render_tp3_footer($vars);
    }
  }
}

/**
* Implementation of hook_theme().
*/
function takepart3_theme() {
  return array(
    'takepart3_header' => array(
      'template' => 'templates/pages/header',
      'arguments' => array(
        'params' => NULL,
      ),
    ),  
    'takepart3_footer' => array(
      'template' => 'templates/pages/footer',
      'arguments' => array(
        'params' => NULL,
      ),
    ),    
    'takepart3_follow_us_links' => array(
          'template' => 'templates/pages/follow_us_links',
          'arguments' => array(
            'params' => NULL,
    ),
  ),
  );
}


function takepart3_preprocess_views_view_unformatted(&$vars) {
  //Add the node type to CSS classes for promos / block 1:
  if ($vars['view']->name == 'promo' && $vars['view']->current_display == 'block_1') {
    $rows = $vars['rows'];
    $vars['extra_classes_array'] = array();
    foreach ($rows as $id => $row) {
      $vars['extra_classes_array'][$id] = $vars['view']->result[$id]->node_type;
      //cheap fix for replacing empties:
      $vars['rows'][$id] = str_replace("<div class=\"field-content\"></div>", "", $vars['rows'][$id]);
      $vars['rows'][$id] = str_replace("<div class=\"views-field views-field-field-article-subhead\">          </div>", "", $vars['rows'][$id]);
    } 
  }
}