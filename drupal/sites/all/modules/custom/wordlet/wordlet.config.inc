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
    // Contagion LOL ------------------------------
    // --------------------------------------------
    'contagion_campaign' => array(
      'title' => 'Contagion - Campaign',
    ),

    // Contagion - Home
    'contagion_home' => array(
      'title' => 'Contagion - Home',
      'path' => 'contagion',
      'published' => TRUE,
      'wrappers' => array('contagion', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/contagion/styles/main.css',
        'campaigns/contagion/styles/plugins.css',
      ),
      'js' => array(
        'campaigns/contagion/script/jquery.movingboxes.min.js',
        'campaigns/contagion/script/jquery.tools.min.js',
        'campaigns/contagion/script/jquery.zrssfeed.min.js',
        'campaigns/contagion/script/global.js',
      ),
      'load' => array('site', 'contagion_campaign'),
    ),

    // --------------------------------------------
    // Interstitials ------------------------------
    // --------------------------------------------
    'interstitials_campaign' => array(
      'title' => 'Interstitials - Campaign',
    ),

    // Interstitials - Social
    'interstitial_social_follows' => array(
      'title' => 'Interstitial: Social Follows',
      'path' => 'interstitials/social-follows',
      'published' => TRUE,
      'wrappers' => array('interstitials', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/interstitials/css/social_interstitial.css',
      ),
      'js' => array(
        'campaigns/interstitials/social_follows/social_interstitial.js',
      ),
      'load' => array('site', 'interstitials_campaign'),
    ),

    'interstitial_newsletter' => array(
      'title' => 'Interstitial: Newsletter',
      'path' => 'interstitials/newsletter',
      'published' => TRUE,
      'wrappers' => array('interstitials', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/interstitials/css/newsletter.css',
      ),
      'js' => array(
        'campaigns/interstitials/newsletter/newsletter.js',
      ),
      'load' => array('site', 'interstitials_campaign'),
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
    'patt_snap_iframe' => array(
      'title' => 'APATT - Gallery: SNAP Alumni (iframe)',
      'path' => 'place-at-the-table/snap-gallery',
      'published' => TRUE,
      'wrappers' => array(/* 'patt', */ 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/patt/patt.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/patt/patt.js',
      ),
      'load' => array('site' , 'patt_campaign'),
    ),
      
    // Place at the Table - The Book
    'patt_book' => array(
      'title' => 'A Place at the Table - The Book',
      'path' => 'place-at-the-table/book',
      'published' => TRUE,
      'wrappers' => array('patt', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/patt/patt.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/patt/patt.js',
      ),
      'load' => array('site', 'patt_campaign'),
    ),

    // Place at the Table - Hungry to Get By
    'patt_game' => array(
      'title' => 'A Place at the Table - Hungry to Get By',
      'path' => 'place-at-the-table/game',
      'published' => TRUE,
      'wrappers' => array('patt', 'campaign', 'html'),
      'css' => array(
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
    'patt_videos' => array(
      'title' => 'A Place at the Table - Videos',
      'path' => 'place-at-the-table/videos',
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
    // TEACH Campaign ----------------
    // -----------------------------
    'teach_campaign' => array(
      'title' => 'TEACH Campaign',
    ),

    // teach Home
    'teach_home' => array(
      'title' => 'TEACH - Home',
      'path' => 'teach',
      'published' => TRUE,
      'wrappers' => array('teach', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/teach/css/teach.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/teach/js/teach.js',
      ),
      'load' => array('site', 'teach_campaign'),
    ),

    // teach Students
    'teach_students' => array(
      'title' => 'TEACH - Students',
      'path' => 'teach/students',
      'published' => TRUE,
      'wrappers' => array('teach', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/teach/css/teach.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/teach/js/teach.js',
        'campaigns/teach/js/film.js'
      ),
      'load' => array('site', 'teach_campaign'),
    ),

    // teach Parents
    'teach_parents' => array(
      'title' => 'TEACH - Parents',
      'path' => 'teach/parents',
      'published' => TRUE,
      'wrappers' => array('teach', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/teach/css/teach.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/teach/js/teach.js',
        'campaigns/teach/js/film.js'
      ),
      'load' => array('site', 'teach_campaign'),
    ),

    // teach Teachers
    'teach_teachers' => array(
      'title' => 'TEACH - Teachers',
      'path' => 'teach/teachers',
      'published' => TRUE,
      'wrappers' => array('teach', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/teach/css/teach.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/teach/js/teach.js',
        'campaigns/teach/js/film.js'
      ),
      'load' => array('site', 'teach_campaign'),
    ),

    // teach Alliances
    'teach_alliances' => array(
      'title' => 'TEACH - Alliances',
      'path' => 'teach/alliances',
      'published' => TRUE,
      'wrappers' => array('teach', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/teach/css/teach.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/teach/js/teach.js',
      ),
      'load' => array('site', 'teach_campaign'),
    ),

    // teach News
    'teach_news' => array(
      'title' => 'TEACH - News',
      'path' => 'teach/news',
      'published' => TRUE,
      'wrappers' => array('teach', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/teach/css/teach.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/teach/js/teach.js',
      ),
      'load' => array('site', 'teach_campaign'),
    ),

    // teach Share Your Story
    'teach_share_your_story' => array(
      'title' => 'TEACH - Share Your Story',
      'path' => 'teach/share-your-story',
      'published' => TRUE,
      'wrappers' => array('teach', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/teach/css/teach.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/teach/js/teach.js',
        'campaigns/teach/js/teach.app.js', // the "share your story" app
      ),
      'load' => array('site', 'teach_campaign'),
    ),

    // teach Teach Fund More Information
    'teach_fund_about' => array(
      'title' => 'TEACH - About the Teach Fund',
      'path' => 'teach/about-teach-fund',
      'published' => TRUE,
      'wrappers' => array('teach', 'campaign', 'html'),
      'css' => array(
	'css/normalize_cms.css',
	'campaigns/teach/css/teach.css',
      ),
      'js' => array(
	'campaigns/campaign.js',
	'campaigns/teach/js/teach.js',
      ),
      'load' => array('site', 'teach_campaign'),
    ),

    // teach Film Page
    'teach_film' => array(
      'title' => 'TEACH - The Film',
      'path' => 'teach/film',
      'published' => TRUE,
      'wrappers' => array('teach', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/teach/css/teach.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/teach/js/teach.js',
        'campaigns/teach/js/film.js'
      ),
      'load' => array('site', 'teach_campaign'),
    ),

    // teach Teacher Stories Page
    'teach_teacher_stories' => array(
      'title' => 'TEACH - Teacher Stories',
      'path' => 'teach/teacher-stories',
      'published' => TRUE,
      'wrappers' => array('teach', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/teach/css/teach.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/teach/js/teach.js',
      ),
      'load' => array('site', 'teach_campaign'),
    ),

    // -----------------------------
    // FOOD INC Campaign ----------------
    // -----------------------------
    'foodinc_campaign' => array(
      'title' => 'FOODINC Campaign',
    ),


    // Food Inc About
    'foodinc_howto' => array(
      'title' => 'FOODINC - howto',
      'path' => 'foodinc/awards/about',
      'published' => TRUE,
      'wrappers' => array('foodinc', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/foodinc/css/foodinc.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/foodinc/js/foodinc.js',
      ),
      'load' => array('site', 'foodinc_campaign'),
      'suppress_ad_block' => TRUE,
    ),

    // Food Inc Awards
    'foodinc_awards' => array(
      'title' => 'FOODINC - Awards',
      'path' => 'foodinc/awards',
      'published' => TRUE,
      'wrappers' => array('foodinc', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/foodinc/css/foodinc.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/foodinc/js/foodinc.js',
      ),
      'load' => array('site', 'foodinc_campaign'),
      'suppress_ad_block' => TRUE,
    ),

    // Food Inc Entry
    'foodinc_entry' => array(
      'title' => 'FOODINC - Entry',
      'path' => 'foodinc/awards/enter',
      'published' => TRUE,
      'wrappers' => array('foodinc', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/foodinc/css/foodinc.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/foodinc/js/foodinc.js',
        'campaigns/foodinc/js/tpselect.jquery.js',
      ),
      'load' => array('site', 'foodinc_campaign'),
      'suppress_ad_block' => TRUE,
    ),

    // Food Inc Entry Received
    'foodinc_entryreceived' => array(
      'title' => 'FOODINC - EntryReceived',
      'path' => 'foodinc/awards/enter/received',
      'published' => TRUE,
      'wrappers' => array('foodinc', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/foodinc/css/foodinc.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/foodinc/js/foodinc.js',
      ),
      'load' => array('site', 'foodinc_campaign'),
      'suppress_ad_block' => TRUE,
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
      'path' => 'can/about',
      'published' => FALSE,
      'wrappers' => array('can', 'campaign', 'html'),
      'css' => array(
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
        'css/normalize_cms.css',
        'campaigns/eyelevel/eyelevel.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/eyelevel/eyelevel.js',
      ),
      'load' => array('site', 'eyelevel_campaign'),
    ),

    // -----------------------------------
    // I Am Education Campaign ----------------
    // -----------------------------------
    'education_campaign' => array(
      'title' => 'I Am Education Campaign',
    ),

    // I Am Education Home
    'education_home' => array(
      'title' => 'I Am Education - Home',
      'path' => 'i-am-education',
      'published' => TRUE,
      'wrappers' => array('education', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/education/education.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/education/education.js',
      ),
      'load' => array('site', 'education_campaign'),
    ),

    // I Am Education Videos
    'education_video' => array(
      'title' => 'I Am Education - Videos',
      'path' => 'i-am-education/videos',
      'published' => TRUE,
      'wrappers' => array('education', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/education/education.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/education/education.js',
      ),
      'load' => array('site', 'education_campaign'),
    ),


    // -----------------------------------
    // Every 3 Seconds Campaign ----------
    // -----------------------------------
    'every3seconds_campaign' => array(
      'title' => 'Every 3 Seconds Campaign',
    ),

    // Every 3 Seconds Home
    'every3seconds_home' => array(
      'title' => 'Every 3 Seconds - Home',
      'path' => 'every-3-seconds',
      'published' => FALSE,
      'wrappers' => array('every3seconds', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/every3seconds/every3seconds.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/every3seconds/education.js',
      ),
      'load' => array('site', 'every3seconds_campaign'),
    ),

    // Every Three Seconds Videos
    'every3seconds_video' => array(
      'title' => 'Every 3 Seconds - Videos',
      'path' => 'every-3-seconds/action',
      'published' => FALSE,
      'wrappers' => array('every3seconds', 'campaign', 'html'),
      'css' => array(
        'css/normalize_cms.css',
        'campaigns/every3seconds/every3seconds.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/every3seconds/every3seconds.js',
      ),
      'load' => array('site', 'every3seconds_campaign'),
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
        'campaigns/intelgirls/intelgirls.css',
      ),
      'js' => array(
        'campaigns/intelgirls/intelgirls.js',
      ),
      'load' => array('site', 'intel_girls_campaign'),
    ),

    // ------------------------------------------
    // Intel For Change (Finalists Phase) Campaign ----------------
    // ------------------------------------------
    'intelchange_finalists_campaign' => array(
      'title' => 'Intel For Change Campaign',
    ),

    // Intel For Change - Home
    'intelchange_finalists_home' => array(
      'title' => 'Intel For Change - Home',
      'path' => 'intelforchange_finalists',
      'published' => TRUE,
      'wrappers' => array('intelchange_finalists', 'campaign', 'html'),
      'css' => array(
        'campaigns/reset.css',
        'css/normalize_cms.css',
        'campaigns/intelchange_finalists/intelchange-finalists.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/intelchange_finalists/intelchange-finalists.js',
      ),
      'load' => array('site', 'intelchange_finalists_campaign'),
    ),

    // Intel For Change - About
    'intelchange_finalists_about' => array(
      'title' => 'Intel For Change - About',
      'path' => 'intelforchange_finalists/about',
      'published' => TRUE,
      'wrappers' => array('intelchange_finalists', 'campaign', 'html'),
      'css' => array(
        'campaigns/reset.css',
        'css/normalize_cms.css',
        'campaigns/intelchange_finalists/intelchange-finalists.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/intelchange_finalists/intelchange-finalists.js',
      ),
      'load' => array('site', 'intelchange_finalists_campaign'),
    ),

    // Intel For Change - Contest
    'intelchange_finalists_contest' => array(
      'title' => 'Intel For Change - Contest',
      'path' => 'intelforchange_finalists/contest',
      'published' => TRUE,
      'wrappers' => array('intelchange_finalists', 'campaign', 'html'),
      'css' => array(
        'campaigns/reset.css',
        'css/normalize_cms.css',
        'campaigns/intelchange_finalists/intelchange-finalists.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/intelchange_finalists/intelchange-finalists.js',
      ),
      'load' => array('site', 'intelchange_finalists_campaign'),
    ),

    // Intel For Change - Vote
    'intelchange_finalists_vote' => array(
      'title' => 'Intel For Change - Vote',
      'path' => 'intelforchange_finalists/contest/vote',
      'published' => TRUE,
      'wrappers' => array('intelchange_finalists', 'campaign', 'html'),
      'css' => array(
        'campaigns/reset.css',
        'css/normalize_cms.css',
        'campaigns/intelchange_finalists/intelchange-finalists.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/intelchange_finalists/intelchange-finalists.js',
      ),
      'load' => array('site', 'intelchange_finalists_campaign'),
    ),

    // ------------------------------------------
    // Intel For Change (Winners Phase) Campaign ----------------
    // ------------------------------------------
    'intelchange_winners_campaign' => array(
      'title' => 'Intel For Change Campaign',
    ),

    // Intel For Change - Home
    'intelchange_winners_home' => array(
      'title' => 'Intel For Change - Home',
      'path' => 'intelforchange',
      'published' => TRUE,
      'wrappers' => array('intelchange_winners', 'campaign', 'html'),
      'css' => array(
        'campaigns/reset.css',
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/intelchange_winners/intelchange-winners.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/intelchange_winners/intelchange-winners.js',
      ),
      'load' => array('site', 'intelchange_winners_campaign'),
    ),

    // Intel For Change - About
    'intelchange_winners_about' => array(
      'title' => 'Intel For Change - About',
      'path' => 'intelforchange/about',
      'published' => TRUE,
      'wrappers' => array('intelchange_winners', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'campaigns/reset.css',
        'css/normalize_cms.css',
        'campaigns/intelchange_winners/intelchange-winners.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/intelchange_winners/intelchange-winners.js',
      ),
      'load' => array('site', 'intelchange_winners_campaign'),
    ),

    // Intel For Change - Learn More
    'intelchange_winners_learn' => array(
      'title' => 'Intel For Change - Learn More',
      'path' => 'intelforchange/learn-more',
      'published' => TRUE,
      'wrappers' => array('intelchange_winners', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'campaigns/reset.css',
        'css/normalize_cms.css',
        'campaigns/intelchange_winners/intelchange-winners.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/intelchange_winners/intelchange-winners.js',
      ),
      'load' => array('site', 'intelchange_winners_campaign'),
    ),

    // Intel For Change - Stay Involved
    'intelchange_winners_involved' => array(
      'title' => 'Intel For Change - Stay Involved',
      'path' => 'intelforchange/stay-involved',
      'published' => TRUE,
      'wrappers' => array('intelchange_winners', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'campaigns/reset.css',
        'css/normalize_cms.css',
        'campaigns/intelchange_winners/intelchange-winners.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/intelchange_winners/intelchange-winners.js',
      ),
      'load' => array('site', 'intelchange_winners_campaign'),
    ),

    // Intel For Change - Contest
    'intelchange_winners_teams' => array(
      'title' => 'Intel For Change - Teams',
      'path' => 'intelforchange/teams',
      'published' => TRUE,
      'wrappers' => array('intelchange_winners', 'campaign', 'html'),
      'css' => array(
        'campaigns/reset.css',
        'css/normalize_cms.css',
        'campaigns/intelchange_winners/intelchange-winners.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/intelchange_winners/intelchange-winners.js',
      ),
      'load' => array('site', 'intelchange_winners_campaign'),
    ),

    // ------------------------------------------
    // Intel For Change (Interim Phase) Campaign ----------------
    // ------------------------------------------
    'intelchange_interim_campaign' => array(
      'title' => 'Intel For Change Campaign',
    ),

    // Intel For Change - Home
    'intelchange_interim_home' => array(
      'title' => 'Intel For Change - Home',
      'path' => 'intelforchange_interim',
      'published' => TRUE,
      'wrappers' => array('intelchange_interim', 'campaign', 'html'),
      'css' => array(
        'campaigns/reset.css',
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/intelchange_interim/intelchange-interim.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/intelchange_interim/intelchange-interim.js',
      ),
      'load' => array('site', 'intelchange_interim_campaign'),
    ),

    // Intel For Change - About
    'intelchange_interim_about' => array(
      'title' => 'Intel For Change - About',
      'path' => 'intelforchange_interim/about',
      'published' => TRUE,
      'wrappers' => array('intelchange_interim', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'campaigns/reset.css',
        'css/normalize_cms.css',
        'campaigns/intelchange_interim/intelchange-interim.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/intelchange_interim/intelchange-interim.js',
      ),
      'load' => array('site', 'intelchange_interim_campaign'),
    ),

    // Intel For Change - Contest
    'intelchange_interim_contest' => array(
      'title' => 'Intel For Change - Contest',
      'path' => 'intelforchange_interim/contest',
      'published' => TRUE,
      'wrappers' => array('intelchange_interim', 'campaign', 'html'),
      'css' => array(
        'campaigns/reset.css',
        'css/slim-header.css',
        'css/normalize_cms.css',
        'campaigns/intelchange_interim/intelchange-interim.css',
      ),
      'js' => array(
        'campaigns/campaign.js',
        'campaigns/intelchange_interim/intelchange-interim.js',
      ),
      'load' => array('site', 'intelchange_interim_campaign'),
    )


  );
}
