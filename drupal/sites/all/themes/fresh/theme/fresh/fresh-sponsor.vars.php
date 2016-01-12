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
			$img_vars = array(
					'style_name' => 'sponsor_logo',
					'path' => $logo->uri,
					'alt' => $sponsored_by.' '.$sponsor->name,
					'title' => $sponsored_by.' '.$sponsor->name,
			);
			if(module_exists('lazyloader')) {
				$img_vars['path'] = file_create_url($logo->uri);

	      $logo =  theme('lazyloader_image', $img_vars);
			} else {
				$logo = theme('image', $img_vars);
			}
		} else {
			$logo = ' '.$sponsor->name;
		}

		$variables['sponsor'] = $sponsored_by;
		$variables['logo'] = $logo;
	}

}
