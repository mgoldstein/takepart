<?php

/**
 * Implements hook_preprocess_page()
 */
function base_preprocess_page(&$variables) {
  // jquery.cookie plugin is not being loaded for anonymous users and needs to be for TAP
  drupal_add_library('system', 'jquery.cookie');

  /*
   * Adds <meta property="sponsored" content="Promoted" /> to sponsored content
   */
  if (isset($variables['node'])) {
    if (!empty($variables['node']->field_sponsored[$variables['node']->language][0]['tid'])) {
	 $sponsored_metatag = array(
	   '#type' => 'html_tag',
	   '#tag' => 'meta',
	   '#attributes' => array(
		'property' => 'sponsored',
		'content' => 'Promoted',
	   )
	 );
	 drupal_add_html_head($sponsored_metatag, 'sponsored_metatag');
    }
  }

  // Add Node-specific page templates
  if (!empty($variables['node'])) {
    $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
  }

  drupal_add_js("(function() { 
    function loadHorizon() 
    { var s = document.createElement('script'); 
    s.type = 'text/javascript'; s.async = true; 
    s.src = location.protocol + '//ak.sail-horizon.com/horizon/v1.js'; 
    var x = document.getElementsByTagName('script')[0]; 
    x.parentNode.insertBefore(s, x); }
    loadHorizon();
    var oldOnLoad = window.onload;
    window.onload = function() {
    if (typeof oldOnLoad === 'function') { oldOnLoad(); }
    Sailthru.setup({ domain: 'horizon.takepart.com', useStoredTags: false });
    };
    })();", array('type' => 'inline', 'scope' => 'footer', 'weight' => 5));
}
