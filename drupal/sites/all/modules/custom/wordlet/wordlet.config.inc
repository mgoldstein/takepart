<?php

define('WORDLET_CSS_DIRECTORY', 'profiles/takepart/themes/takepart3/');
define('WORDLET_JS_DIRECTORY', 'profiles/takepart/themes/takepart3/');

/**
 * Templates can be placed in any directory under
 *
 *   profiles/takepart/themes/takepart3/templates
 *
 * Template names should use underscores (_) here, and dashes (-) in the actual
 * filename. The reason for the difference is so templates can be have a
 * preprocess hook function (the name of which may not include dashes)
 */

/*
    // Wordlet page.
    'intel_girls_home' => array(
      'title' => 'Intel Girls Home',
      // Path relative to site root (do NOT include the initial slash)
      'path' => 'intelgirls',
      // Access control flag
      'published' => TRUE,
      // When rendering a page Drupal uses two templates, one for the content
      // and second to wrap around the content. These are the wrapper templates
      // if this key is left out it will be defaulted to a single 'html' wrapper
      'wrappers' => array('html'),
      // CSS files to add when rendering the page, paths are relative to
      // WORDLET_CSS_DIRECTORY defined at the top of this file.
      'css' => array(
        //'reset.css',
        'campaigns/intelchange/intelchange.css',
      ),
      // JS files to add when rendering the page, paths are relative to
      // WORDLET_JS_DIRECTORY defined at the top of this file.
      'js' => array(
        //'plugin.js',
        //'intelgirls.js',
      ),
      // Additional wordlet groups to load ordered by precedence (lower to higer)
      'load' => array('site', 'intel_girls_campaign'),
    ),
*/

function _wordlet_configuration() {
  return array(

    // Simple wordlet group.
    'site' => array(
      'title' => 'Site Wordlets',
    ),

    // Responsive iframed header for outside devs
    'iframed_header' => array(
      'title' => 'Iframed header',
      'path' => 'iframes/responsive-header',
      'published' => TRUE,
      'wrappers' => array('html'),
      'css' => array(
        'css/slim-header.css',
      ),
    ),

    // Test
    'test' => array(
      'title' => 'Test',
      'path' => 'wordletstest',
      'published' => FALSE,
      'wrappers' => array(),
      /*'wrappers' => array('campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'campaigns/intelchange/intelchange.css',
      ),
      'js' => array(
        'campaigns/intelchange/intelchange.js',
      ),
      'load' => array('site', 'intel_girls_campaign'),*/
    ),

    // Test
    'test_social' => array(
      'title' => 'Social Sharing Test',
      'path' => 'socialtest',
      'published' => FALSE,
      'wrappers' => array(),
      'css' => array(
        'campaigns/reset.css',
        'css/slim-header.css',
        'css/normalize_cms.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
      ),
      'load' => array('site'),
    ),

    // Article Test
    'test_article' => array(
      'title' => 'Article Test',
      'path' => 'articletest',
      'published' => FALSE,
      'wrappers' => array(),
      'css' => array(
        'campaigns/reset.css',
        'css/normalize_cms.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
      ),
      'load' => array('site'),
    ),

    // Blank Wordlet Page
    'test_blank' => array(
      'title' => 'Test - Blank Campaign',
      'path' => 'test/blank-campaign-page',
      'published' => TRUE,
      'wrappers' => array('campaign', 'html'),
      'css' => array(
        'campaigns/reset.css',
        'css/slim-header.css',
        'css/normalize_cms.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
      ),
      'load' => array(),
    ),

    // Longtail video
    'longtail_video' => array(
      'title' => 'Video',
      'path' => 'video/players',
      'published' => TRUE,
      'wrappers' => array(),
      'css' => array(),
      'js' => array(),
      'load' => array(),
    ),

    // --------------------------------------------
    // Place at the Table Campaign ----------------
    // --------------------------------------------
    'patt_campaign' => array(
      'title' => 'A Place at the Table Campaign',
    ),

    // Place at the Table - Nav
    'patt_nav' => array(
      'title' => 'A Place at the Table - Top Navigation',
      'path' => 'iframes/place-at-the-table/header',
      'published' => TRUE,
      'wrappers' => array('html'),
      'css' => array(
        'css/slim-header.css',
        'campaigns/patt/patt.css',
      ),
      'js' => array(
        'campaigns/patt/patt.js'
      ),
      'load' => array('site', 'patt_campaign'),
    ),

    // Place at the Table - Home
    'patt_home' => array(
      'title' => 'A Place at the Table - Home',
      'path' => 'place-at-the-table',
      'published' => TRUE,
      'wrappers' => array('patt', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/patt/patt.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/patt/patt.js',
      ),
      'load' => array('site', 'patt_campaign'),
    ),

    // Place at the Table - Film
    'patt_film' => array(
      'title' => 'A Place at the Table - Film',
      'path' => 'place-at-the-table/film',
      'published' => TRUE,
      'wrappers' => array('patt', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/patt/patt.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/patt/patt.js',
      ),
      'load' => array('site', 'patt_campaign'),
    ),

    // Place at the Table - Take Action
    'patt_action' => array(
      'title' => 'A Place at the Table - Take Action',
      'path' => 'place-at-the-table/action',
      'published' => TRUE,
      'wrappers' => array('patt', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/patt/patt.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/patt/patt.js',
      ),
      'load' => array('site', 'patt_campaign'),
    ),

    // Place at the Table - Snap Alumni
    'patt_snap' => array(
      'title' => 'A Place at the Table - Gallery: SNAP Alumni',
      'path' => 'place-at-the-table/snap-alumni',
      'published' => TRUE,
      'wrappers' => array('patt', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/patt/patt.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/patt/patt.js',
      ),
      'load' => array('site', 'patt_campaign'),
    ),

    // Place at the Table - The Book
    'patt_book' => array(
      'title' => 'A Place at the Table - The Book',
      'path' => 'place-at-the-table/book',
      'published' => TRUE,
      'wrappers' => array('patt', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/patt/patt.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/patt/patt.js',
      ),
      'load' => array('site', 'patt_campaign'),
    ),

    // Place at the Table - Events & Resources
    'patt_events' => array(
      'title' => 'A Place at the Table - Events and Resources',
      'path' => 'place-at-the-table/events-resources',
      'published' => TRUE,
      'wrappers' => array('patt', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/patt/patt.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/patt/patt.js',
      ),
      'load' => array('site', 'patt_campaign'),
    ),

    // Place at the Table - Alliances
    'patt_alliances' => array(
      'title' => 'A Place at the Table - Alliances',
      'path' => 'place-at-the-table/alliances',
      'published' => TRUE,
      'wrappers' => array('patt', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/patt/patt.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/patt/patt.js',
      ),
      'load' => array('site', 'patt_campaign'),
    ),

    // Place at the Table - I Need Food Assistance
    'patt_assistance' => array(
      'title' => 'A Place at the Table - I Need Food Assistance',
      'path' => 'place-at-the-table/assistance',
      'published' => TRUE,
      'wrappers' => array('patt', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/patt/patt.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/patt/patt.js',
      ),
      'load' => array('site', 'patt_campaign'),
    ),

    // -----------------------------
    // CAN Campaign ----------------
    // -----------------------------
    'can_campaign' => array(
      'title' => 'CAN Campaign',
    ),

    // CAN Home
    'can_home' => array(
      'title' => 'CAN - Home',
      'path' => 'can',
      'published' => FALSE,
      'wrappers' => array('can', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/can/can.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/can/can.js',
      ),
      'load' => array('site', 'can_campaign'),
    ),

    // CAN About
    'can_about' => array(
      'title' => 'CAN - About',
      'template' => 'can_home',
      'path' => 'can/about',
      'published' => FALSE,
      'wrappers' => array('can', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/can/can.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/can/can.js',
      ),
      'load' => array('site', 'can_campaign'),
    ),

    // -----------------------------------
    // Eye Level Campaign ----------------
    // -----------------------------------
    'eyelevel_campaign' => array(
      'title' => 'Eye Level Campaign',
    ),

    // Eye Level Home
    'eyelevel_home' => array(
      'title' => 'Eve Level - Home',
      'path' => 'eyelevel',
      'published' => FALSE,
      'wrappers' => array('eyelevel', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/eyelevel/eyelevel.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/eyelevel/eyelevel.js',
      ),
      'load' => array('site', 'eyelevel_campaign'),
    ),

    // Eye Level Videos
    'eyelevel_video' => array(
      'title' => 'Eve Level - Video',
      'path' => 'eyelevel/video',
      'published' => FALSE,
      'wrappers' => array('eyelevel', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/eyelevel/eyelevel.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/eyelevel/eyelevel.js',
      ),
      'load' => array('site', 'eyelevel_campaign'),
    ),

    // -------------------------------------
    // Intel Girls Campaign ----------------
    // -------------------------------------
    'intel_girls_campaign' => array(
      'title' => 'Intel Girls Campaign',
    ),

    // Intel Girls Home
    'intel_girls_home' => array(
      'title' => 'Intel Girls Home',
      'path' => 'intelforchangeold',
      'published' => TRUE,
      'wrappers' => array('campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'campaigns/intelgirls/intelgirls.css',
      ),
      'js' => array(
        'campaigns/intelgirls/intelgirls.js',
      ),
      'load' => array('site', 'intel_girls_campaign'),
    ),

    // ------------------------------------------
    // Intel For Change Campaign ----------------
    // ------------------------------------------
    'intelchange_campaign' => array(
      'title' => 'Intel For Change Campaign',
    ),

    // Intel For Change - Home
    'intelchange_home' => array(
      'title' => 'Intel For Change - Home',
      'path' => 'intelforchange',
      'published' => true,
      'wrappers' => array('intelchange', 'campaign', 'html'),
      'css' => array(
        'campaigns/reset.css',
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/intelchange/intelchange.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'js/jquery.scrollTo.js',
        'js/tpscroll.jquery.js',
        'campaigns/intelchange/intelchange.js',
      ),
      'load' => array('site', 'intelchange_campaign'),
    ),

    // Intel For Change - About
    'intelchange_about' => array(
      'title' => 'Intel For Change - About',
      'path' => 'intelforchange/about',
      'published' => true,
      'wrappers' => array('intelchange', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'campaigns/reset.css',
        'css/normalize_cms.css',
        'campaigns/intelchange/intelchange.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/intelchange/intelchange.js',
      ),
      'load' => array('site', 'intelchange_campaign'),
    ),

    // Intel For Change - Contest
    'intelchange_contest' => array(
      'title' => 'Intel For Change - Contest',
      'path' => 'intelforchange/contest',
      'published' => true,
      'wrappers' => array('intelchange', 'campaign', 'html'),
      'css' => array(
        'campaigns/reset.css',
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/intelchange/intelchange.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/intelchange/intelchange.js',
      ),
      'load' => array('site', 'intelchange_campaign'),
    ),

    // Intel For Change - Contest Entry
    'intelchange_contest_enter' => array(
      'title' => 'Intel For Change - Contest Entry',
      'path' => 'intelforchange/contest/enter',
      'published' => true,
      'wrappers' => array('intelchange', 'campaign', 'html'),
      'css' => array(
        'campaigns/reset.css',
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/intelchange/intelchange.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/intelchange/intelchange.js',
      ),
      'load' => array('site', 'intelchange_campaign'),
    ),

    // Intel For Change - Vote
    'intelchange_vote' => array(
      'title' => 'Intel For Change - Vote',
      'path' => 'intelforchange/contest/vote',
      'published' => TRUE,
      'wrappers' => array('intelchange', 'campaign', 'html'),
      'css' => array(
        'campaigns/reset.css',
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/intelchange/intelchange.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/intelchange/intelchange.js',
      ),
      'load' => array('site', 'intelchange_campaign'),
    ),

    // Intel For Change - Take Action
    'intelchange_action' => array(
      'title' => 'Intel For Change - Take Action',
      'path' => 'intelforchange/action',
      'published' => true,
      'wrappers' => array('intelchange', 'campaign', 'html'),
      'css' => array(
        'campaigns/reset.css',
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/intelchange/intelchange.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/intelchange/intelchange.js',
      ),
      'load' => array('site', 'intelchange_campaign'),
    ),

    // Intel For Change - Resources
    'intelchange_resources' => array(
      'title' => 'Intel For Change - Resources',
      'path' => 'intelforchange/resources',
      'published' => true,
      'wrappers' => array('intelchange', 'campaign', 'html'),
      'css' => array(
        'campaigns/reset.css',
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/intelchange/intelchange.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/intelchange/intelchange.js',
      ),
      'load' => array('site', 'intelchange_campaign'),
    ),

  );
}
