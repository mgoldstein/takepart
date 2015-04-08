<?php
	
/**
 * Admin form callback.
 */
function tp_theme_support_footer_form($form, &$form_state) {

	$form['about_us'] = array(
		'#type' => 'fieldset',
		'#title' => t('About Us'),
		'#description' => t('Content settings for the About Us footer.'),
		'#tree' => false,
		'#collapsible' => false,
		'#collapsed' => false,
	);

	$form['about_us']['tp_theme_support_about_us_title'] = array(
		'#type' => 'textfield',
		'#title' => t('Title'),
		'#description' => t('The footer headline.'),
		'#required' => false,
		'#default_value' => variable_get('tp_theme_support_about_us_title', 'About Us'),
	);

	$form['about_us']['tp_theme_support_about_us_body'] = array(
		'#type' => 'text_format',
		'#title' => t('About Us Body Text'),
		'#description' => t('Rich text about us block for the site-wide footer.'),
		'#required' => false,
		'#rows' => 12,
		'#format' => 'full_html',
		'#default_value' => variable_get('tp_theme_support_about_us_body', ''),
	);

	$menus = menu_get_menus();

	$form['footer_links'] = array(
		'#type' => 'fieldset',
		'#title' => t('Footer Links'),
		'#description' => t('Menu setting for the About Us footer.'),
		'#tree' => false,
		'#collapsible' => false,
		'#collapsed' => false,
	);

	$form['footer_links']['tp_theme_support_about_us_menu'] = array(
		'#type' => 'select',
		'#title' => t('Footer Menu'),
		'#default_value' => variable_get('tp_theme_support_about_us_menu',''),
		'#options' => $menus,
		'#description' => t('Select the menu to display in the footer.'),
	);

	return system_settings_form($form);	// Obviates the need for _validate and _submit functions
}
