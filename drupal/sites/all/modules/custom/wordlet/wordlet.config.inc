<?php

function wordlet_configuration() {
  return array(

    'site' => array(
      'title' => 'Site Wordlets',
    ),

    'intel_girls_home' => array(
      'title' => 'Intel Girls Home',
      'path' => 'intelgirls',
      'template' =>  'intelgirls',
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
