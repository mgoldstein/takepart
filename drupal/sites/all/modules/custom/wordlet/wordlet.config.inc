<?php

function _wordlet_configuration() {
  return array(

    'site' => array(
      'title' => 'Site Wordlets',
    ),

    'intel_girls_home' => array(
      'title' => 'Intel Girls Home',
      'path' => 'intelgirls',
      'templates' => array(
        'wrapper' => 'html',
        'content' => 'page__wordlet__intel_girls_home',
      ),
      'css' => array(
        'reset.css',
        'intelgirls.css',
      ),
      'js' => array(
        'plugin.js',
        'intelgirls.js',
      ),
    ),
  );  
}
