<?php

/**
 * Implementation of hook_content_default_fields().
 */
function takepart_newsletter_signup_bulk_feature_content_default_fields() {
  module_load_include('inc', 'takepart_newsletter_signup_bulk_feature', 'takepart_newsletter_signup_bulk_feature.defaults');
  $args = func_get_args();
  return call_user_func_array('_takepart_newsletter_signup_bulk_feature_content_default_fields', $args);
}

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function takepart_newsletter_signup_bulk_feature_fieldgroup_default_groups() {
  module_load_include('inc', 'takepart_newsletter_signup_bulk_feature', 'takepart_newsletter_signup_bulk_feature.defaults');
  $args = func_get_args();
  return call_user_func_array('_takepart_newsletter_signup_bulk_feature_fieldgroup_default_groups', $args);
}

/**
 * Implementation of hook_node_info().
 */
function takepart_newsletter_signup_bulk_feature_node_info() {
  module_load_include('inc', 'takepart_newsletter_signup_bulk_feature', 'takepart_newsletter_signup_bulk_feature.features.node');
  $args = func_get_args();
  return call_user_func_array('_takepart_newsletter_signup_bulk_feature_node_info', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function takepart_newsletter_signup_bulk_feature_user_default_permissions() {
  module_load_include('inc', 'takepart_newsletter_signup_bulk_feature', 'takepart_newsletter_signup_bulk_feature.defaults');
  $args = func_get_args();
  return call_user_func_array('_takepart_newsletter_signup_bulk_feature_user_default_permissions', $args);
}
