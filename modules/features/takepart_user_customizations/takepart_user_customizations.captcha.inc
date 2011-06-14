<?php
/**
 * @file
 * takepart_user_customizations.captcha.inc
 */

/**
 * Implementation of hook_captcha_default_points().
 */
function takepart_user_customizations_captcha_default_points() {
  $export = array();

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_action_form';
  $captcha->module = 'recaptcha';
  $captcha->captcha_type = 'reCAPTCHA';
  $export['comment_node_action_form'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_audio_form';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['comment_node_audio_form'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_blog_front_form';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['comment_node_blog_front_form'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_openpublish_article_form';
  $captcha->module = 'recaptcha';
  $captcha->captcha_type = 'reCAPTCHA';
  $export['comment_node_openpublish_article_form'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_openpublish_blog_post_form';
  $captcha->module = 'recaptcha';
  $captcha->captcha_type = 'reCAPTCHA';
  $export['comment_node_openpublish_blog_post_form'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_openpublish_photo_form';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['comment_node_openpublish_photo_form'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_openpublish_photo_gallery_form';
  $captcha->module = 'recaptcha';
  $captcha->captcha_type = 'reCAPTCHA';
  $export['comment_node_openpublish_photo_gallery_form'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_openpublish_site_page_form';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['comment_node_openpublish_site_page_form'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_openpublish_video_form';
  $captcha->module = 'recaptcha';
  $captcha->captcha_type = 'reCAPTCHA';
  $export['comment_node_openpublish_video_form'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_profile_form';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['comment_node_profile_form'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_section_front_form';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['comment_node_section_front_form'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_takepart_campaign_form';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['comment_node_takepart_campaign_form'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_takepart_group_form';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['comment_node_takepart_group_form'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_takepart_page_form';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['comment_node_takepart_page_form'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_takepart_quick_study_form';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['comment_node_takepart_quick_study_form'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_takepart_slide_form';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['comment_node_takepart_slide_form'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_topic_front_form';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['comment_node_topic_front_form'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_video_series_form';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['comment_node_video_series_form'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'user_login';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['user_login'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'user_login_block';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['user_login_block'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'user_pass';
  $captcha->module = '';
  $captcha->captcha_type = '';
  $export['user_pass'] = $captcha;

  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'user_register_form';
  $captcha->module = 'recaptcha';
  $captcha->captcha_type = 'reCAPTCHA';
  $export['user_register_form'] = $captcha;

  return $export;
}
