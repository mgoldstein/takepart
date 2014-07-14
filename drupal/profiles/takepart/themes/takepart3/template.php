<?php

class Tp3Site {
    public static $logo;
}

function wordlet_teach_share_your_story_page_alter($page) {
    drupal_add_library('system', 'ui.autocomplete');
}
function wordlet_teach_teacher_stories_page_alter($page) {
    drupal_add_library('system', 'ui.autocomplete');
}
function wordlet_teach_browse_stories_page_alter($page) {
    drupal_add_library('system', 'ui.autocomplete');
}

function wordlet_patt_nav_page_alter($page) {
    // remove analytics from this page
    global $conf;
    $conf['googleanalytics_account'] = '';
    $conf['quantcast_account'] = '';
}

function wordlet_patt_snap_page_alter($page) {
    if (isset($_GET['slide'])) {
        $w = wordlet_find('snap_slides', 'token', $_GET['slide']);
        if ($w && $w->img_src) {
            $metatag = array(
                '#type' => 'html_tag',
                '#tag' => 'meta',
                '#attributes' => array(
                    'property' => 'og:image',
                    'content' => $w->img_src,
                ),
            );
            drupal_add_html_head($metatag, 'facebook_image');
        }
    }
    return '';
}

function wordlet_patt_snap_iframe_page_alter($page) {
    if (isset($_GET['slide'])) {
        $w = wordlet_find('snap_slides_iframe', 'token', $_GET['slide']);
        if ($w && $w->img_src) {
            $metatag = array(
                '#type' => 'html_tag',
                '#tag' => 'meta',
                '#attributes' => array(
                    'property' => 'og:image',
                    'content' => $w->img_src,
                ),
            );

            drupal_add_html_head($metatag, 'facebook_image');
        }
    }
    return '';
}

function wordlet_page_intelchange_winners_teams_preprocess(&$variables) {
    if (isset($_GET['team'])) {
        $cur_team = $_GET['team'];
    } else {
        $cur_team = w('teams')->token; //first team token
    }

    if (isset($_GET['member'])) {
        $cur_member = $_GET['member'];
    } else {
        $cur_member = w($cur_team.'_team')->token; //first member token of cur_team
    }

    $variables['cur_team'] = $cur_team;
    $variables['cur_member'] = $cur_member;
}

function wordlet_intelchange_vote_page_alter($page) {
    if (isset($_GET['finalist'])) {
        $w = wordlet_find('finalists', 'token', $_GET['finalist']);
        if ($w && $w->small_src) {
            $metatag = array(
                '#type' => 'html_tag',
                '#tag' => 'meta',
                '#attributes' => array(
                    'property' => 'og:image',
                    'content' => $w->small_src,
                ),
            );

            drupal_add_html_head($metatag, 'facebook_image');
        }
        if ($w && $w->single && $w->multi_short) {
            $metatag = array(
                '#type' => 'html_tag',
                '#tag' => 'meta',
                '#attributes' => array(
                    'property' => 'og:title',
                    'content' => 'Check out this Intel for Change finalist: ' . $w->single(false) . ' (' . strip_tags($w->multi_short(false)) . ')',
                ),
            );

            drupal_add_html_head($metatag, 'facebook_title');
        }
        if ($w && w('content_full_'.$w->token)->multi(false)) {
            $metatag = array(
                '#type' => 'html_tag',
                '#tag' => 'meta',
                '#attributes' => array(
                    'property' => 'og:description',
                    'content' => strip_tags(w('content_full_'.$w->token)->multi(false)),
                ),
            );

            drupal_add_html_head($metatag, 'facebook_description');
        }
    }
    return '';
}

/**
 * Each item of the array should be keyed as follows:
 * url (String, 21 characters ) http://www.google.com
 * title (String, 7 characters ) Boo Boo
 * attributes (Array, 0 elements)
 * these are the normal results from a field.
 */
function takepart3_dolinks($links_field) {
    if (empty($links_field))
        return;

    $links = array();
    $opts = array('external' => TRUE);
    foreach ($links_field as $link) {
        $links[] = l($link['title'], $link['url'], $opts);
    }
    return implode("<span class='delimiter'>|</span>", $links);
}

function takepart3_preprocess_html(&$vars) {

  // Pass the digital data to the HTML template.
  $vars['tp_digital_data'] =  isset($vars['page']['tp_digital_data'])
    ? $vars['page']['tp_digital_data'] : NULL;

    $uri = drupal_get_path_alias($_GET['q']);
    $vars['is_multipage'] = FALSE;
    $vars['is_iframed'] = FALSE;
    $vars['logo'] = Tp3Site::$logo;

    drupal_add_library('system', 'jquery.cookie');

    if (
     (context_isset('takepart3_page', 'campaign_is_multipage') && context_get('takepart3_page', 'campaign_is_multipage'))
     || (function_exists('wordlet_active_page') && ($wordlet_page = wordlet_active_page()))
     || ($uri == 'iframes/slim-header')
    ) {
        $vars['classes_array'][] = 'multipage-campaign';
        $vars['is_multipage'] = TRUE;
    }

    // Remove tracking from place at the table iframed header
    // TODO: fix this.
    if (preg_match('/^\/iframes\/place-at-the-table\/header/', $_SERVER['REQUEST_URI'])
      || preg_match('/^\/interstitials/', $_SERVER['REQUEST_URI'])
        ) {
        unset($vars['page']['page_bottom']['omniture']);
        unset($vars['page']['page_bottom']['quantcast']);
        unset($vars['page']['page_bottom']['federatedmedia']);
    }

    if (isset($vars['page']['content']['system_main']['nodes'])) {
        //Override header if field exists:
        $nodes = $vars['page']['content']['system_main']['nodes'];
        $header_override = false;
        if (!empty($nodes)) {
            while ((list($key, $value) = each($nodes)) && (!$header_override)) {
                if (is_numeric($key)) {
                    try {
                        if (isset($value['body'])) {
                            if (array_key_exists('field_html_title', $value['body']['#object'])) {
                                $header_override = $value['body']['#object']->field_html_title;
                            }
                        }
                        if (isset($value['field_html_title'])) {
                            if (array_key_exists('field_html_title', $value['field_html_title']['#object'])) {
                                $header_override = $value['field_html_title']['#object']->field_html_title;
                                unset($vars['page']['content']['system_main']['nodes'][$key]['field_html_title']);
                            }
                        }
                        if (isset($value['#node'])) {
                            if (array_key_exists('field_html_title', $value['#node'])) {
                                $header_override = $value['#node']->field_html_title;
                            }
                        }
                    } catch (Exception $e) {
                        $header_override = false;
                    }
                }
            }
        }
    }

    if (isset($header_override)) {
        if ($header_override) {
            $vars['head_title'] = $header_override['und'][0]['value'];
        }
    }

    _render_tp3_renderheaderfooterfeed($vars);
    _render_tp3_bsd_wrapper($vars);

    if ( ($uri == 'iframes/slim-header')
        || ($uri == 'bsd/header')
        || ($uri == 'iframes/place-at-the-table/header')
        || ($uri == 'iframes/header')
        ) {
        $vars['is_iframed'] = TRUE;
        $vars['page_top'] = null;
        $vars['page_bottom'] = null;
        $vars['page'] = null;
        _tp3_fill_template_vars($vars);
        $vars['custom'] = _render_tp3_header($vars);
    } elseif (
        ($uri == 'bsd/footer')
        || ($uri == 'iframes/footer')
        ) {
        $vars['is_iframed'] = TRUE;
        $vars['page_top'] = null;
        $vars['page_bottom'] = null;
        $vars['page'] = null;
        _tp3_fill_template_vars($vars);
        $vars['custom'] = _render_tp3_footer($vars);
    }
}

function takepart3_preprocess_page(&$variables) {
    Tp3Site::$logo = $variables['logo'];
    $uri = drupal_get_path_alias($_GET['q']);
    _tp3_fill_template_vars($variables);

    if (isset($variables['node'])) {
        if ($variables['node']->title == "Contact Us") {
            // #18868    pglatz 7/10/2012
            // save referrer URL to track in webform
            // it is saved as $_COOKIE['Drupal_visitor_webform_referrer']
            user_cookie_save(array('webform_referrer' => $_SERVER['HTTP_REFERER']));
        }
    }
    $variables['is_iframed'] = TRUE;
    $variables['is_multipage'] = FALSE;
    $variables['multipage_class'] = '';

    // Adds page template suggestions for specific content types
    if (isset($variables['node'])) {
        $variables['theme_hook_suggestions'][] = 'page__type__' . $variables['node']->type;
        $variables['theme_hook_suggestions'][] = 'page__type__' . $variables['node']->type . '__node__' . $variables['node']->nid;

        if (!empty($variables['node']->field_multi_page_campaign[$variables['node']->language][0]['context'])) {
            $variables['is_multipage'] = TRUE;
            context_set('takepart3_page', 'campaign_is_multipage', TRUE);
            $variables['multipage_class'] = 'page-multipage'; // although this is not needed because the context set the body class itself
        }

        if ($variables['node']->type == 'takepart_campaign') {
            if (!empty($variables['node']->field_tp_campaign_show_title[$variables['node']->language][0]['value'])) {
                unset($variables['page']['highlighted']['takepart_custom_page_title_h1']);
            }
        }

        if ($variables['node']->type == 'venue' || $variables['node']->type == 'action'
                || $variables['node']->type == 'petition_action' || $variables['node']->type == 'pledge_action') {
            $variables['is_multipage'] = TRUE;
        }
    }

    if ( ($uri == 'iframes/slim-header')
        || ($uri == 'bsd/header')
        || ($uri == 'bsd/footer')
        || ($uri == 'iframes/place-at-the-table/header')
        || ($uri == 'iframes/header')
        || ($uri == 'iframes/footer')
        ) {
        $variables['is_iframed'] = TRUE;
        $variables['is_multipage'] = TRUE;
    }

    $status = drupal_get_http_header('status');
    $status_code = explode(' ', $status);
    if ($status_code[0] == '403') {
        unset($variables['page']['sidebar_second']);
    }

    $variables['header'] = _render_tp3_header($variables);
    $variables['footer'] = _render_tp3_footer($variables);

    if (function_exists('wordlet_active_page')) {
        $wordlet_page = wordlet_active_page();
        if (!empty($wordlet_page)) {
            $variables['header'] .= render($variables['tabs']);
        }
    }

    return $variables;
}

/**
 * Preprocessor for theme('block').
 */
function takepart3_preprocess_node(&$vars, $hook) {
    $use_popup = false;   // set true if video popup are enabled and this node specifies using one

    if (module_exists('takepart_vidpop')) {
        /*
         * under certain conditions, we want to change the link of the embedded video to
         *  create a popup:
         * -view_mode is "embed"
         * -field_video_display_mode is 2 (modal popup)
         * or if
         * -view_mode is "full"
         * -field_video_display_mode is 3 (contextual)
         * -page type is video (permalink)
         */
        if ($vars['type'] == 'openpublish_video') {
            if (isset($vars['field_video_display_mode']['und'])) {
                if (isset($vars['field_video_display_mode']['und'][0]['value'])) {
                    // this video node has a display mode has a value set; change
                    // the link to create a popup
                    switch ($vars['field_video_display_mode']['und'][0]['value']) {
                        case 1:   // embedded
                            break;
                        case 2:   // modal popup
                            if ($vars['view_mode'] == 'embed') {
                                $use_popup = true;
                            }
                            break;
                        case 3:   // contextual (embedded on permalink page, modal elsewhere)
                            if ($vars['view_mode'] == 'full') {
                                $use_popup = true;
                            }
                            break;
                    }
                }
            } else {
                // mode is undefined - assume popup
                $use_popup = true;
            }
        }

        if ($use_popup) {
            $GLOBALS['has_vidpop'] = 1;
            // suggest a theme
            $vars['theme_hook_suggestions'][] = "node__video_embed";

            // render the video as large size for the popup
            $render_large = node_view(node_load($vars['nid']), 'large');
            $vars['large_video'] = drupal_render($render_large['field_video_embedded']);

            //if (!empty($vars['field_thumbnail']['und'][0]['file'])) {
            if (true) {
                // build preview image
                $vars['content']['thumbnail_image'] = takepart_vidpop_format_preview(file_build_uri($vars['field_thumbnail']['und'][0]['file']->filename), $vars);
            }

            // add identifying class
            $vars['classes_array'][] = 'vidpop-embedded';

            // add ad click call from vidpop
            static $vp_js_added;
            if (!isset($vp_js_added)) {
                drupal_add_js('jQuery(document).ready(function () { vidpop_loaded(); });', 'inline');
                $vp_js_added = 1;
            }
        }
    }

    if (module_exists('unipop')) {
        // add ad click call from unipop
        static $unipop_js_added;
        if (!isset($unipop_js_added)) {
            drupal_add_js('jQuery(document).ready(function () { unipop_loaded(); });', 'inline');
            $unipop_js_added = 1;
        }
    }

    // Suggests a custom template for embedded node content through the WYSIWYG
    // We suggest a theme for a general embed as well as for each content type
    if ($vars['view_mode'] == 'embed' && !$use_popup) {
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
    if ($hook == 'node') {
        if ($vars['type'] == 'openpublish_article' || $vars['type'] == 'openpublish_blog_post') {
            $end = '/p>'; // end of a paragraph tag
            if ($vars['type'] == 'openpublish_article') {
                $featured_action = render($vars['content']['field_article_action']);
            } else {
                $featured_action = render($vars['content']['field_blogpost_featured_action']);
            }
            $pos = 0; // Find the position of the end of the 3rd paragraph
            for ($i = 0; $i < 3; $i++) {
                $pos = strpos($vars['content']['body'][0]['#markup'], $end, $pos) + 1;
            }
            $vars['content']['body'][0]['#markup'] = substr_replace($vars['content']['body'][0]['#markup'], $featured_action, $pos + 2, 0);
        }
        $vars['remove_title'] = FALSE;
        if (!empty($vars['field_tp_campaign_show_title'][0]['value'])) {
            $vars['remove_title'] = TRUE;
        }
    }

    // add read more link to blog posts.
    if ($hook == 'node' && $vars['view_mode'] == 'teaser' && $vars['type'] == 'openpublish_blog_post') {
        $markup_size = strlen($vars['content']['body'][0]['#markup']);
        $safe_size = strlen($vars['body'][0]['safe_value']);
        // if markup and safe_value differ, then there is a page break.
        if ($markup_size < $safe_size) {
            $more_link = l("Continue Reading &raquo;", "node/" . $vars['nid'], array('html' => TRUE));
            $vars['content']['body'][0]['#markup'] .= "<span class='blog-post-continue-reading-link'>" . $more_link . "</span>";
        }
    }
    /* add in out link to the title */
    if ($hook == 'node' && $vars['view_mode'] == 'embed' && $vars['type'] == 'openpublish_video') {
        $vars['content']['embedded_video_link'] = array(
            '#weight' => 10,
            '#theme' => 'link',
            '#text' => 'Full Video',
            '#path' => "node/" . $vars['nid'],
            '#options' => array('html' => FALSE, 'attributes' => array('class' => 'embedded-video-link')),
        );
    }
    /* see https://takepart1.fogbugz.com/default.asp?17143 */
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

function takepart3_field__field_series(&$vars) {
    $base = base_path() . 'sites/default/files/styles/action_header_image/public/';
    $filename = $vars['element']['#object']->field_series['und'][0]['taxonomy_term']->field_series_graphic_header['und'][0]['filename'];
    $url = $base . $filename;
    $linkOverride = $filename = $vars['element']['#object']->field_series['und'][0]['taxonomy_term']->field_series_graphic_header_link;
    if (!empty($linkOverride)) {
        $link = $linkOverride['und'][0]['url'];
    } else {
        $link = url($vars['items'][0]['#href']);
    }
    $altText = $filename = $vars['element']['#object']->field_series['und'][0]['taxonomy_term']->field_series_graphic_header['und'][0]['alt'];
    return sprintf('<a href="%s"><img class="field-name-field-series-graphic-header" src="%s" alt="%s" /></a>', $link, $url, $altText);
}

function takepart3_field__field_actionheaderimghref(&$vars) {
    $base = base_path() . 'sites/default/files/styles/action_header_image/public/';
    $link = $vars['element']['#object']->field_actionheaderimghref['und'][0]['url'];
    $uri = $vars['element']['#object']->field_actionheaderimg['und'][0]['filename'];
    $url = $base . $uri;
    return sprintf('<a href="%s"><img src="%s" /></a>', $link, $url);
}

function takepart3_form_boxes_box_form_alter(&$form, &$form_state, $form_id) {
    if ($form_state['box']->options['view'] == 'campaigns--block_2') {
        $form['options']['settings']['nid']['#maxlength'] = 255;
    }
}

// Preprocess author field
function takepart3_field__field_author(&$vars) {
    // Author
    $authors = array();
    foreach ($vars['items'] as $key => $value) {
        $authors[] = l( t($value['#title']), $value['#href'], array('attributes' => array('rel' => 'author')) );
    }
    switch (count($authors)) {
        case 1:
            $authors = $authors[0];
            break;
        case 2:
            $authors = implode(' & ', $authors);
            break;
        default:
            $last_author = array_pop($authors);
            $authors = implode(' & ', array(implode(', ', $authors), $last_author));
            break;
    }
    $authors_field = sprintf("<div class='field field-author'>By %s</div>", $authors);

    // Date
    $date = format_date($vars['element']['#object']->created, 'medium', 'F j, Y');
    $date_field = sprintf("<div class='field article-date'>%s</div>", $date);

    //Comments
    $node = $vars['element']['#object'];
    if (($node->comment == COMMENT_NODE_OPEN) || (($node->comment == COMMENT_NODE_CLOSED) && (!empty($node->comment_count)) && ($node->comment_count != 0))) {
        // Comments are either open, or there are existing closed comments
        if ($node->comment_count == 0) {
            // There is no comment count to show so use a generic phrase
            $comments_field = "<div class='field article-comment-count'><a href='#comments'>Comment</a></div>";
        } else {
            // We have a comment count to show
            $comments = $vars['element']['#object']->comment_count;
            $comments_field = sprintf("<div class='field article-comment-count'><a href='#comments'>%s comments</a></div>", $comments);
        }
    } else {
        // Comments are hidden, or are closed and there are none
        $comments_field = '';
    }
    return sprintf("<div class='submitted-wrapper'><div class='submitted clearfix'>%s%s%s</div></div>", $authors_field, $date_field, $comments_field);
}

// Preprocess action URL
function takepart3_field__field_action_url(&$vars) {
    $output = '';
    if (!empty($vars['element']['#items'])) {
        // There should be only one value for the field.
        $item = reset($vars['element']['#items']);
        $attributes = array(
            'href' => 'javascript:void();',
        );
        if ($item['url'] !== 'local') {
            $attributes['action-href'] = $item['url'];
        }
        if (isset($item['attributes'])) {
            if (isset($item['attributes']['target'])) {
                $attributes['target'] = $item['attributes']['target'];
            }
            if (isset($item['attributes']['class'])) {
                $attributes['class'] = explode(' ', $item['attributes']['class']);
            }
        }
        if ($vars['element']['#entity_type'] === 'node') {
            $attributes['nid'] = $vars['element']['#object']->nid;
        }

        $variables = array(
            'element' => array(
                '#tag' => 'a',
                '#attributes' => $attributes,
                '#value' => '<span>' . $item['title'] . '</span>',
            ),
        );
        $output = theme('html_tag', $variables);
    }
    return $output;
}

// Rewrites 'field_tp_campaign_4_things_link' in Campaign content types
// Prepends a <span> with id before each bullet point for theming
function takepart3_field__field_tp_campaign_5_things_head(&$vars) {
    return '<div class="field field-name-field-tp-campaign-5-things-head"><div class="field-items field-5-things-head">' . $vars['element']['#items'][0]['safe_value'] . '</div>';
}

function takepart3_field__field_tp_campaign_header(&$vars) {
    return '<div class="field field-name-field-tp-campaign-header field-type-media field-label-hidden"><div class="field-items"><div class="field-item even">' . l(render($vars['element'][0]), 'node/' . $vars['element']['#object']->nid, array('html' => TRUE)) . '</div></div></div>';
}

function takepart3_field__field_tp_campaign_4_things_link(&$vars) {
  $output = '';
  foreach ($vars['items'] as $key => &$value) {
    $markup = render($value);
    $output .= '<span class="campaign-link campaign-link-' . ($key + 1) . '">'
      . ($key + 1) . '</span>'
      . str_replace('&amp;amp;', '&amp;', $markup);
  }
  return '<div class="field-name-field-tp-campaign-4-things-link">' . $output . '</div></div>';
}

function takepart3_field__field_tp_campaign_cover_link(&$vars) {
  if (!empty($vars['element']['#items'][0])) {
    $item = $vars['element']['#items'][0];
    $markup = l($item['title'], $item['url'], array('attributes' => $item['attributes']));
    return '<div class="field field-name-field-tp-campaign-cover-link field-type-link-field field-label-hidden"><div class="field-items"><div class="field-item even">'
      . str_replace('&amp;amp;', '&amp;', $markup) . '</div></div></div>';
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

function takepart3_field__field_group_url(&$vars) {
    if (isset($vars['element']['#items'][0]) & $vars['element']['#items'][0]) {
        return "<div class='field field-name-field-group-url'>" . l('Visit Website', $vars['element']['#items'][0]['url']) . "</div>";
    }
}

function takepart3_field__field_tp_campaign_seg_1_rel(&$vars) {
    $output = '';
    foreach ($vars['element']['#items'] as $item) {
        $node_type = takepart3_return_node_type($item['node']->type);
        $output .= '<div class="field-name-field-tp-campaign-seg_rel">';
        $output .= '<div class="title">' . check_plain($item['node']->title) . '</div>';
        $output .= l(t('View') . ' ' . $node_type . ' &raquo;', $item['node']->uri['path'], array('html' => TRUE)) . '</div>';
    }
    return $output;
}

function takepart3_field__field_tp_campaign_seg_2_rel(&$vars) {
    $output = '';
    foreach ($vars['element']['#items'] as $item) {
        $node_type = takepart3_return_node_type($item['node']->type);
        $output .= '<div class="field-name-field-tp-campaign-seg_rel">';
        $output .= '<div class="title">' . check_plain($item['node']->title) . '</div>';
        $output .= l(t('View') . ' ' . $node_type . ' &raquo;', $item['node']->uri['path'], array('html' => TRUE)) . '</div>';
    }
    return $output;
}

function takepart3_field__field_tp_campaign_seg_3_rel(&$vars) {
    $output = '';
    foreach ($vars['element']['#items'] as $item) {
        $node_type = takepart3_return_node_type($item['node']->type);
        $output .= '<div class="field-name-field-tp-campaign-seg_rel">';
        $output .= '<div class="title">' . check_plain($item['node']->title) . '</div>';
        $output .= l(t('View') . ' ' . $node_type . ' &raquo;', $item['node']->uri['path'], array('html' => TRUE)) . '</div>';
    }
    return $output;
}

function takepart3_field__field_tp_campaign_seg_4_rel(&$vars) {
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

function takepart3_field__field_topic($vars) {
    // do we have any free tags?
    $field_free_tag = isset($vars['element']['#object']->field_free_tag['und']) ? $vars['element']['#object']->field_free_tag['und'] : $vars['element']['#object']->field_free_tag;

    // how about tags from series?
    $field_series_tag = isset($vars['element']['#object']->field_series['und']) ? $vars['element']['#object']->field_series['und'] : $vars['element']['#object']->field_series;

    if (count($vars['items']) || count($field_free_tag) || count($field_free_series)) {
        $links = array();
        foreach ($field_series_tag as $key => $value) {
            $term = taxonomy_term_load($value['tid']);
            $links[] = "<a href='" . url('taxonomy/term/' . $value['tid']) . "'>" . $term->name . '</a>';
        }

        foreach ($vars['items'] as $key => $value) {
            if (isset($value['#href'])) {
                $links[] = "<a href='" . url($value['#href']) . "'>" . $value['#title'] . '</a>';
            }
        }

        foreach ($field_free_tag as $key => $value) {
            $term = taxonomy_term_load($value['tid']);
            $links[] = "<a href='" . url('taxonomy/term/' . $value['tid']) . "'>" . $term->name . '</a>';
        }
        return '<div class="node-topics"><div class="node-topics-label">Topics</div>' . implode(', ', $links) . '</div>';
    }
}

function takepart3_preprocess_comment(&$vars) {
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
        $vars['classes_array'][] = 'block-boxes-title-' . preg_replace(array('/[^a-zA-Z\s0-9]/', '/[\s]/', '/---|--/'), array('', '-', '-'), strtolower($vars['block']->title));
    }
    if (!empty($vars['elements']['#contextual_links']['views_ui'][1][0])) {
        $vars['classes_array'][] = 'block-boxes-view-name-' . $vars['elements']['#contextual_links']['views_ui'][1][0];
    }
    if (!empty($vars['elements']['#block']->current_view)) {
        $vars['classes_array'][] = 'block-boxes-current-' . $vars['elements']['#block']->current_view;
    }
    if (!empty($vars['elements']['#block']->delta)) {
        $vars['classes_array'][] = 'block-boxes-delta-' . $vars['elements']['#block']->delta;
    }
    if (!empty($vars['elements']['#block']->bid)) {
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

function _render_tp3_quick_study_topics($node) {
    $output = array();
    if (isset($node->field_topic)) {
        foreach ($node->field_topic['und'] as $key => $value) {
            $term = taxonomy_term_load($value['tid']);
            $output[] = l($term->name, url('taxonomy/term/' . $value['tid']));
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
    $entities = $variables['items'];
    $keys = $variables['keys'];
    $output = '<p class="search-performance">' .
            format_plural($results['result count'], 'Current search found 1 result for ' .
            check_plain($keys), 'Current search found @count results for ' .
            check_plain($keys), array('@sec' => round($results['performance']['complete'], 3))) . '</p>';
    if (!$results['result count']) {
        $output .= "\n<h2>" . t('Your search yielded no results') . "</h2>\n";
        return $output;
    } else {
        $block = module_invoke('search_api_sorts', 'block_view', 'search-sorts');
        $output .= '<div id="block-search-api-sorts-search-sorts"><h2>Sort by:</h2><div class="content">' . render($block['content']) . '</div></div>';
    }

    if ($variables['view_mode'] == 'search_api_page_result') {
        entity_prepare_view($index->entity_type, $entities);
        $output .= '<ol class="search-results">';
	// dpm($results);
        foreach ($results['results'] as $item) {
            $output .= '<li class="search-result">' . theme('search_api_page_result', array('index' => $index, 'result' => $item, 'entity' => isset($entities[$item['id']]) ? $entities[$item['id']] : NULL, 'keys' => $keys)) . '</li>';
        // $output .= '<li class="search-result">' . $item . '</li>';
	}
        $output .= '</ol>';
    } else {
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
    $wrapper = entity_metadata_wrapper($index->item_type, $entity);
    $url = entity_uri($index->item_type, $entity);
    $name = entity_label($index->item_type, $entity);
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
    else if (!empty($entity->field_promo_text[$entity->language][0]['safe_value'])) {
        $text = $entity->field_promo_text[$entity->language][0]['safe_value'];
    }
    $output = '';
    if (isset($entity->nid)) {
        $type = takepart3_return_node_type($entity->type);
        if (!empty($type)) {
            $output = '<div class="views-field views-field-type"><span class="field-content">' . $type . '</span></div>';
        }
        $output .= '<h3>' . ($url ? l($name, $url['path'], $url['options']) : check_plain($name)) . "</h3>\n";
        if ($text) {
            $output .= $text;
        }
        $authors = _get_author($entity->nid);
        if (!empty($authors)) {
            $output .= "<div class='by-line'>" . t("Posted by !authors on @date", array('!authors' => $authors, '@date' => date('M d, Y', $entity->created))) . "</div>";
        }
    }
    return $output;
}

/**
 * find the authors of a nid.
 * Uses a caching mechanism based on static variable
 *  if the NID is already in the static array it will retrieve its value
 *  if not will query the DB
 * then will build the HTML list
 */
function _get_author($nid) {
    static $nodes = array();
    #check first if we have the nid
    $authors = array();
    if (isset($nodes[$nid])) {
        $authors = $nodes[$nid];
    } else {
        $query = db_select('field_data_field_author', 'a');
        $query->addField('a', 'field_author_nid');
        $query->condition('a.entity_id', $nid);
        $query->join('field_data_field_profile_last_name', 'fpl', 'a.field_author_nid = fpl.entity_id');
        $query->join('field_data_field_profile_first_name', 'fpf', 'a.field_author_nid = fpf.entity_id');
        $query->addField('fpl', 'field_profile_last_name_value', 'last_name');
        $query->addField('fpf', 'field_profile_first_name_value', 'first_name');
        $query->orderBy('last_name', 'ASC')->orderby('first_name', 'ASC');
        $result = $query->execute();
        foreach ($result as $record) {
            $authors[] = l($record->first_name . " " . $record->last_name, "node/" . $record->field_author_nid);
        }
        if (empty($authors)) {
            return NULL;
        }
        $nodes[$nid] = $authors;
    }
    switch (count($authors)) {
        case 1:
            $authors = $authors[0];
            break;
        case 2:
            $authors = implode(' & ', $authors);
            break;
        default:
            $last_author = array_pop($authors);
            $authors = implode(' & ', array(implode(', ', $authors), $last_author));
            break;
    }
    return $authors;
}

function _render_tp3_wrapper_footer(&$params) {
    return theme('takepart3_wrapper_footer', $params);
}

/*
 * Clears page, page bottom and top, fills custom section
 * with the header or footer depending on the path.
 */

function _render_tp3_renderheaderfooterfeed(&$vars) {
    $uri = drupal_get_path_alias($_GET['q']);
    if (($uri == 'iframes/footer')) {
        $vars['page_top'] = null;
        $vars['page_bottom'] = null;
        $vars['page'] = null;
        _tp3_fill_template_vars($vars);
        if ($uri == 'iframes/footer') {
            $vars['custom'] = _render_tp3_footer($vars);
        }
    }
}

function _render_tp3_bsd_wrapper(&$vars) {
    $uri = drupal_get_path_alias($_GET['q']);
    $uri = substr($uri, 0, 14);
    if (($uri == 'bsd/footer')) {
        // dpm($vars);
        _tp3_fill_template_vars($vars);
        if ($uri == 'bsd/footer') {
            $vars['custom'] = _render_tp3_wrapper_footer($vars);
            // $vars['custom'] = _render_tp3_footer($vars);
        }
    }
}

/**
 * Implementation of hook_theme().
 */
function takepart3_theme() {
    return array(
        'takepart3_follow_us_links' => array(
            'template' => 'templates/pages/follow_us_links',
            'arguments' => array(
                'params' => NULL,
            ),
        ),
    );
}

function takepart3_preprocess_views_view(&$vars) {
    if (isset($vars['view']->name)) {
        if ($vars['view']->name == 'water_bill_of_rights_signatures') {
            drupal_add_css(drupal_get_path('module', 'takepart_petition') . '/css/takepart-petition-signatures-view.css', array('group' => CSS_DEFAULT, 'type' => 'file'));
        }
    }
}

/* * *
 * @function override for theme_pager_link
 *
 * rewrites link so first page has page=0 argument, and adds rel prev/next links to head
 *
 * @param $variables
 * @return string
 *
 */

function takepart3_pager_link($variables) {
    global $base_root;

    $text = $variables['text'];
    $page_new = $variables['page_new'];
    $element = $variables['element'];
    $parameters = $variables['parameters'];
    $attributes = $variables['attributes'];

    $page = isset($_GET['page']) ? $_GET['page'] : '';
    if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
        $parameters['page'] = $new_page;
    }

    $query = array();
    if (count($parameters)) {
        $query = drupal_get_query_parameters($parameters, array());
    }
    if ($query_pager = pager_get_query_parameters()) {
        $query = array_merge($query, $query_pager);
    }

    // Set each pager link title
    if (!isset($attributes['title'])) {
        static $titles = NULL;
        if (!isset($titles)) {
            $titles = array(
                t('« first') => t('Go to first page'),
                t('‹ previous') => t('Go to previous page'),
                t('next ›') => t('Go to next page'),
                t('last »') => t('Go to last page'),
            );
            drupal_add_html_head_link(array(
                'rel' => 'canonical',
                //'type' => 'application/rss+xml',
                //'href' => url($base_root . request_uri(), array()),
                // remove query string from "canonical" link; pglatz #27654
                'href' => url($base_root . '/' . drupal_lookup_path('alias', $_GET['q']), array()),
            ));
        }
    }

    // additional code for prev/next
    if (count($query) == 0) {
        // fix for page 0
        $query['page'] = 0;
    }

    // remove "first" link, page 1 link
    if (($text == 1) || $text == '« first') {
        $query = NULL;
    }

    // Pagination with rel=“next” and rel=“prev”. Does not support well multiple
    // pagers on the same page - it will create relnext and relprev links
    // in header for that case only for the first pager that is rendered.
    static $rel_prev = FALSE, $rel_next = FALSE;
    if (!$rel_prev && $text == t('‹ previous')) {
        $rel_prev = TRUE;
        if ($page == 1) {
            // remove  "previous" link on page 2
            $query = NULL;
        }
        drupal_add_html_head_link(array(
            'rel' => 'prev',
            //'type' => 'application/rss+xml',
            'href' => url($base_root . '/' . drupal_get_path_alias($_GET['q']), array('query' => $query)),
        ));
    }
    if (!$rel_next && $text == t('next ›')) {
        $rel_next = TRUE;
        drupal_add_html_head_link(array(
            'rel' => 'next',
            //'type' => 'application/rss+xml',
            'href' => url($base_root . '/' . drupal_get_path_alias($_GET['q']), array('query' => $query)),
        ));
    }
    if (($text == "« first") || ($text == "1")) {
        // special case: prev page is first page, leave off page arg
        $query = NULL;
    }
    return l($text, $_GET['q'], array('attributes' => $attributes, 'query' => $query));
}

/* * *
 * implementation of hook_html_head_alter()
 *
 * @param $head_elements
 */
function takepart3_html_head_alter(&$head_elements) {
    // check for duplicate canonical links - if found,
    // use the one from takepart3_pager_link()
    $remove = array(); // list of elements to remove
    foreach ($head_elements as $key => $data) {
        if ($data['#tag'] == 'link') {
            if ($data['#attributes']['rel'] == 'canonical') {
                if (strpos($data['#attributes']['href'], 'http') !== 0) {
                    // add to remove list; the ones added from pager_link will
                    // all have a full URL, starting with protocol
                    $remove[] = $key;
                }
            }
        }
    }
    // remove any duplicate canonical links (those not coming from pager link)
    foreach ($remove as $junk => $key) {
        unset($head_elements[$key]);
    }
}

function takepart3_field__field_video__video($variables) {
  $output = '';
  foreach ($variables['items'] as $delta => $item) {
    $output .= render($item);
  }
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';
  return $output;
}

