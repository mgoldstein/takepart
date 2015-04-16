<?php

/**
 * Implements theme_preprocess_fresh_sponsor()
 */
function fresh_preprocess_fresh_sponsor(&$variables){

	if($variables['tid']) {
		
		$sponsor = taxonomy_term_load($variables['tid']);

		$sponsored_by = $sponsor->field_sponsor_label['und'][0]['value'];

		// Add the sponsor logo, or the name, if there isn't one
		if( $sponsor->field_sponsor_logo['und'][0]['fid'] ) {
			$logo = file_load($sponsor->field_sponsor_logo['und'][0]['fid']);
			$logo = theme('image', array(
					'style_name' => 'sponsor_logo',
					'path' => $logo->uri,
					'alt' => $sponsored_by.' '.$sponsor->name,
					'title' => $sponsored_by.' '.$sponsor->name,
			));
		} else {
			$logo = ' '.$sponsor->name;
		}

		$variables['sponsor'] = $sponsored_by;
		$variables['logo'] = $logo;
	}

}
