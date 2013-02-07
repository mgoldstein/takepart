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

    // Intel Girls Campaign
    'intel_girls_campaign' => array(
      'title' => 'Intel Girls Campaign',
    ),

    // Intel Girls Home
    'intel_girls_home' => array(
      'title' => 'Intel Girls Home',
      'path' => 'intelgirls',
      'published' => TRUE,
      'wrappers' => array('campaign', 'html'),
      'css' => array(
        'campaigns/intelchange/intelchange.css',
      ),
      'js' => array(
        'campaigns/intelchange/intelchange.js',
      ),
      'load' => array('site', 'intel_girls_campaign'),
    ),

    // Place at the Table Campaign
    'patt_campaign' => array(
      'title' => 'Place at the Table Campaign',
    ),

    // Place at the Table Home
    'patt_home' => array(
      'title' => 'A Place at the Table - Home',
      'path' => 'place-at-the-table',
      'published' => TRUE,
      'wrappers' => array('patt', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'campaigns/patt/patt.css',
      ),
      'js' => array(
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
        'campaigns/patt/patt.css',
      ),
      'js' => array(
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
        'campaigns/patt/patt.css',
      ),
      'js' => array(
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
        'campaigns/patt/patt.css',
      ),
      'js' => array(
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
        'campaigns/patt/patt.css',
      ),
      'js' => array(
        'campaigns/patt/patt.js',
      ),
      'load' => array('site', 'patt_campaign'),
    ),

    // Place at the Table - Events & Resources
    'patt_events' => array(
      'title' => 'A Place at the Table - Events &amp; Resources',
      'path' => 'place-at-the-table/events-resources',
      'published' => TRUE,
      'wrappers' => array('patt', 'campaign', 'html'),
      'css' => array(
        'css/slim-header.css',
        'campaigns/patt/patt.css',
      ),
      'js' => array(
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
        'campaigns/patt/patt.css',
      ),
      'js' => array(
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
        'campaigns/patt/patt.css',
      ),
      'js' => array(
        'campaigns/patt/patt.js',
      ),
      'load' => array('site', 'patt_campaign'),
    ),

    // Place at the Table - I Need Food Assistance
    'patt_json' => array(
      'title' => 'A Place at the Table - JSON',
      'path' => 'place-at-the-table/json/snapgriddata.txt',
      'published' => TRUE,
      'wrappers' => array(),
    ),
  );
}
