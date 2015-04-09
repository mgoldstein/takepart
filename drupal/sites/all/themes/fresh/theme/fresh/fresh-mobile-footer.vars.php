<?php

/**
 * Implements theme_preprocess_fresh_mobile_footer()
 */
function fresh_preprocess_fresh_mobile_footer(&$variables){
	$variables['title'] = variable_get('tp_theme_support_about_us_title','');

	$body = variable_get('tp_theme_support_about_us_body','');
	$variables['body'] = $body['value'];

	$menu = variable_get('tp_theme_support_about_us_menu','');
	$variables['menu'] = theme('links', array('links' => menu_navigation_links($menu)));
}
