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
      // and second to wrap around the content.
      'templates' => array(
        'wrapper' => 'html',
        'content' => 'page__wordlet__intel_girls_home',
      ),
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
      'templates' => array(
        'wrapper' => 'html',
        'content' => 'page__wordlet__intel_girls_home',
      ),
      'css' => array(
        'campaigns/intelchange/intelchange.css',
      ),
      'js' => array(),
      'load' => array('site', 'intel_girls_campaign'),
    ),

    // Place at the Table Campaign
    'patt_campaign' => array(
      'title' => 'Place at the Table Campaign',
    ),

    // Place at the Table Home
    'patt_home' => array(
      'title' => 'Place at the Table Home',
      'path' => 'place-at-the-table',
      'published' => TRUE,
      'templates' => array(
        'wrapper' => 'html',
        'content' => 'page__wordlet__patt_home',
      ),
      'css' => array(
        'css/slim-header.css',
        'campaigns/patt/patt.css',
      ),
      'js' => array(
        'campaigns/patt/patt.js',
      ),
      'load' => array('site', 'patt_campaign'),
    ),

  );
}
