<?php

/**
 * Implements theme_preprocess_fresh_sponsor()
 */
function fresh_preprocess_fresh_sponsor_disclaimer(&$variables){

	if($variables['tid']) {
		
		$sponsor = taxonomy_term_load($variables['tid']);

		// Get (default) disclaimer
		if($sponsor->field_sponsor_disclaimer['und'][0]['value']) {
			$disclaimer = $sponsor->description;
		} else {
	    	$default_disclaimer = taxonomy_term_load($sponsor->field_sponsor_type['und'][0]['tid']);
	    	$disclaimer = $default_disclaimer->description;
		}

		$variables['disclaimer'] = trim($disclaimer);
	}

}
