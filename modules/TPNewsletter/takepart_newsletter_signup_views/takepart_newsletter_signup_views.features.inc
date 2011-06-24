<?php

/**
 * Implementation of hook_views_default_views().
 */
function takepart_newsletter_signup_views_views_default_views() {
  module_load_include('inc', 'takepart_newsletter_signup_views', 'takepart_newsletter_signup_views.features.views');
  $args = func_get_args();
  return call_user_func_array('_takepart_newsletter_signup_views_views_default_views', $args);
}
