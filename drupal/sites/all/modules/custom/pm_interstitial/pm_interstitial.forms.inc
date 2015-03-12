<?php
	
/**
 * Admin form callback.
 */
function pm_interstitial_admin_form($form, &$form_state) {

	$form['email'] = array(
		'#type' => 'fieldset',
		'#title' => t('Email Interstitials'),
		'#description' => t('Settings for the email interstitial.'),
		'#tree' => FALSE,
		'#collapsible' => FALSE,
		'#collapsed' => FALSE,
	);

	$form['email']['pm_interstitial_email_cmpids'] = array(
		'#type' => 'textarea',
		'#title' => t('Campaign ID Prefixes'),
		'#description' => t('List of campaign id (cmpid) prefixes that should be treated as email referrers. Prefixes should be listed one per line.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_email_cmpids', ''),
	);

	$form['social'] = array(
		'#type' => 'fieldset',
		'#title' => t('Social Interstitials'),
		'#description' => t('Settings for the social interstitial.'),
		'#tree' => FALSE,
		'#collapsible' => FALSE,
		'#collapsed' => FALSE,
	);

	$form['social']['pm_interstitial_social_cmpids'] = array(
		'#type' => 'textarea',
		'#title' => t('Campaign ID Prefixes'),
		'#description' => t('List of campaign id (cmpid) prefixes that should be treated as social site referrers. Prefixes should be listed one per line.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_social_cmpids', ''),
	);

	return system_settings_form($form);
}

/**
 * Newsletter settings form callback.
 */
function pm_interstitial_newsletter_form($form, &$form_state) {

	$form['pm_interstitial_newsletter_published'] = array(
		'#type' => 'checkbox',
		'#title' => t('Published'),
		'#description' => t('Is this published?'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_newsletter_published', ''),
	);
	
	$form['pm_interstitial_newsletter_interstitials'] = array(
		'#type' => 'textfield',
		'#title' => t('Header  URL'),
		'#description' => t('The path to the interstitial form.'),
		'#required' => true,
		'#disabled' => true,
		'#default_value' => 'interstitials/newsletter',
	);
	
	$form['pm_interstitial_newsletter_page_title'] = array(
		'#type' => 'textfield',
		'#title' => t('Page Title'),
		'#description' => t('Web page title.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_newsletter_page_title', ''),
	);

	$form['pm_interstitial_newsletter_header_image'] = array(
		'#type' => 'textfield',
		'#title' => t('Header Image URL'),
		'#description' => t('The full url and path to the header image.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_newsletter_header_image', ''),
	);

	$form['pm_interstitial_newsletter_header_alt'] = array(
		'#type' => 'textfield',
		'#title' => t('Header Image Alt Text'),
		'#description' => t('Alt text to display if the image does not load.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_newsletter_header_alt', ''),
	);

	$form['pm_interstitial_newsletter_header'] = array(
		'#type' => 'textfield',
		'#title' => t('Header'),
		'#description' => t('Header, appears below the header image.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_newsletter_header', ''),
	);

	$form['pm_interstitial_newsletter_body'] = array(
		'#type' => 'textfield',
		'#title' => t('Body'),
		'#description' => t('Single-line text below the header.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_newsletter_body', ''),
	);

	$form['newsletter_form'] = array(
		'#type' => 'fieldset',
		'#title' => t('Newsletter Form'),
		'#tree' => FALSE,
		'#collapsible' => false,
		);

	$form['newsletter_form']['pm_interstitial_newsletter_signup_name'] = array(
		'#type' => 'select',
	    '#title' => t('Signup Name'),
	    '#description' => t('The name of the signup endpoint.'),
		'#options' => array(
			'newsletter_interstitial' => t('Newsletter Interstitial Signup'),
		),
	    '#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_newsletter_signup_name', 'newsletter_interstitial'),
	);

	$form['newsletter_form']['pm_interstitial_newsletter_name'] = array(
		'#type' => 'textfield',
		'#title' => t('Newsletter Name'),
		'#description' => t('Name of the newsletter list submitted in the form.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_newsletter_name', ''),
	);

	$form['newsletter_form']['pm_interstitial_newsletter_signup_source'] = array(
		'#type' => 'textfield',
		'#title' => t('Signup Source'),
		'#description' => t('The signup source name.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_newsletter_signup_source', ''),
	);

	$form['newsletter_form']['pm_interstitial_newsletter_form_header'] = array(
		'#type' => 'textarea',
		'#title' => t('Form Header HTML'),
		'#description' => t('Form header HTML.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_newsletter_form_header', ''),
	);

	$form['newsletter_form']['pm_interstitial_newsletter_email_label'] = array(
		'#type' => 'textfield',
		'#title' => t('Email Label'),
		'#description' => t('Label for the Email form field.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_newsletter_email_label', ''),
	);

	$form['newsletter_form']['pm_interstitial_newsletter_email_placeholder'] = array(
		'#type' => 'textfield',
		'#title' => t('Email Placeholder'),
		'#description' => t('Email form field placeholder.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_newsletter_email_placeholder', 'Email'),
	);

	$form['newsletter_form']['pm_interstitial_newsletter_submit_caption'] = array(
		'#type' => 'textfield',
		'#title' => t('Button Text'),
		'#description' => t('Text on subscribe link.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_newsletter_submit_caption', 'subscribe'),
	);

	$form['newsletter_form']['pm_interstitial_newsletter_thank_you'] = array(
		'#type' => 'textarea',
		'#title' => t('Thank You Message'),
		'#description' => t('Thank you message for subscribing.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_newsletter_thank_you', ''),
	);

	$form['pm_interstitial_newsletter_footer'] = array(
		'#type' => 'textarea',
		'#title' => t('Footer HTML'),
		'#description' => t('Footer information and ToS.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_newsletter_footer', ''),
	);

	$form['pm_interstitial_newsletter_dont_show_text'] = array(
		'#type' => 'textfield',
		'#title' => t("Don't Show Text"),
		'#description' => t("Don't show me this form again."),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_newsletter_dont_show_text', ''),
	);

	return system_settings_form($form);
}

/**
 * Social Follow settings form callback.
 */
function pm_interstitial_social_form($form, &$form_state) {
	
	global $base_url;

	$form['pm_interstitial_social_published'] = array(
		'#type' => 'checkbox',
		'#title' => t('Published'),
		'#description' => t('Is this published?'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_social_published', true),
	);

	$form['pm_interstitial_social_interstitials'] = array(
		'#type' => 'textfield',
		'#title' => t('Interstitial URL'),
		'#description' => t('The path to the interstitial form.'),
		'#required' => true,
		'#disabled' => true,
		'#default_value' => 'interstitials/social-follows',
	);

	$form['pm_interstitial_social_page_title'] = array(
		'#type' => 'textfield',
		'#title' => t('Page Title'),
		'#description' => t('Web page title.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_social_page_title', ''),
	);

	$form['pm_interstitial_social_header_image'] = array(
		'#type' => 'textfield',
		'#title' => t('Header Image URL'),
		'#description' => t('The full url and path to the header image.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_social_header_image', ''),
	);

	$form['pm_interstitial_social_header_alt'] = array(
		'#type' => 'textfield',
		'#title' => t('Header Image Alt Text'),
		'#description' => t('Alt text to display if the image does not load.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_social_header_alt', ''),
	);

	$form['pm_interstitial_social_header'] = array(
		'#type' => 'textfield',
		'#title' => t('Header'),
		'#description' => t('Header, appears below the header image.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_social_header', ''),
	);

	$form['pm_interstitial_social_body'] = array(
		'#type' => 'textarea',
		'#title' => t('Body'),
		'#description' => t('Single-line text below the header.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_social_body', ''),
	);

	$form['pm_interstitial_social_dont_show_text'] = array(
		'#type' => 'textfield',
		'#title' => t("Don't Show Text"),
		'#description' => t("Don't show me this form again."),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_social_dont_show_text', ''),
	);

	$form['social_form'] = array(
		'#type' => 'fieldset',
		'#title' => t('Social Share Links'),
		'#tree' => FALSE,
		'#collapsible' => false,
	);

	// Facebook
	$form['social_form']['facebook'] = array(
		'#type' => 'fieldset',
		'#title' => t('Facebook'),
		'#tree' => FALSE,
		'#collapsible' => false,
	);

	$form['social_form']['facebook']['pm_interstitial_social_fb_url'] = array(
		'#type' => 'textfield',
		'#title' => t('Facebook URL'),
		'#description' => t('Full url to the Facebook page.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_social_fb_url', 'https://www.facebook.com/[account]'),
	);

	$form['social_form']['facebook']['pm_interstitial_social_fb_image'] = array(
		'#type' => 'textfield',
		'#title' => t('Facebook Image'),
		'#description' => t('Full url to the Facebook share icon.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_social_fb_image', $base_url.base_path().drupal_get_path('module', 'pm_interstitial').'/images/share-fb.png'),
	);

	$form['social_form']['facebook']['pm_interstitial_social_fb_alt'] = array(
		'#type' => 'textfield',
		'#title' => t('Facebook Image Alt Text'),
		'#description' => t('Image alt text.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_social_fb_alt', ''),
	);

	$form['social_form']['facebook']['pm_interstitial_social_fb_token'] = array(
		'#type' => 'textfield',
		'#title' => t('Facebook Token'),
		'#description' => t('The social token.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_social_fb_token', 'facebook'),
	);

	// Twitter
	$form['social_form']['twitter'] = array(
		'#type' => 'fieldset',
		'#title' => t('Twitter'),
		'#tree' => FALSE,
		'#collapsible' => false,
	);

	$form['social_form']['twitter']['pm_interstitial_social_twitter_url'] = array(
		'#type' => 'textfield',
		'#title' => t('Twitter Handle'),
		'#description' => t('Name of the social follow list submitted in the form.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_social_twitter_url', '@'),
	);

	$form['social_form']['twitter']['pm_interstitial_social_twitter_image'] = array(
		'#type' => 'textfield',
		'#title' => t('Twitter Image URL'),
		'#description' => t('Name of the social follow list submitted in the form.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_social_twitter_image', $base_url.base_path().drupal_get_path('module', 'pm_interstitial').'/images/share-twitter.png'),
	);

	$form['social_form']['twitter']['pm_interstitial_social_twitter_alt'] = array(
		'#type' => 'textfield',
		'#title' => t('Twitter Image Alt Text'),
		'#description' => t('Image alt text.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_social_twitter_alt', ''),
	);

	$form['social_form']['twitter']['pm_interstitial_social_twitter_token'] = array(
		'#type' => 'textfield',
		'#title' => t('Twitter Token'),
		'#description' => t('The social token.'),
		'#required' => FALSE,
		'#default_value' => variable_get('pm_interstitial_social_twitter_token', 'twitter'),
	);

	return system_settings_form($form);
}

