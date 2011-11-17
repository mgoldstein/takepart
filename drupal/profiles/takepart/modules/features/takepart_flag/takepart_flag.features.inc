<?php
/**
 * @file
 * takepart_flag.features.inc
 */

/**
 * Implements hook_views_api().
 */
function takepart_flag_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function takepart_flag_flag_default_flags() {
  $flags = array();
  // Exported flag: "Needs Review".
  $flags['needs_review'] = array(
    'content_type' => 'node',
    'title' => 'Needs Review',
    'global' => '1',
    'types' => array(
      0 => 'openpublish_article',
      1 => 'openpublish_blog_post',
      2 => 'openpublish_photo_gallery',
      3 => 'openpublish_video',
      4 => 'section_front',
      5 => 'profile',
      6 => 'action',
      7 => 'audio',
      8 => 'blog_front',
      9 => 'takepart_campaign',
      10 => 'takepart_group',
      11 => 'takepart_page',
      12 => 'takepart_quick_study',
      13 => 'takepart_slide',
      14 => 'topic_front',
    ),
    'flag_short' => 'Needs Review',
    'flag_long' => 'Mark a specific piece of content as needs review',
    'flag_message' => 'Content marked as needs review',
    'unflag_short' => 'Content no longer needs review',
    'unflag_long' => 'Removes the needs review flag',
    'unflag_message' => 'Content no longer needs review',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
      ),
      'unflag' => array(
        0 => '2',
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_on_form' => 1,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'takepart_flag',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Test Content".
  $flags['test_content'] = array(
    'content_type' => 'node',
    'title' => 'Test Content',
    'global' => '1',
    'types' => array(
      0 => 'openpublish_article',
      1 => 'openpublish_blog_post',
      2 => 'openpublish_photo_gallery',
      3 => 'openpublish_video',
      4 => 'profile',
      5 => 'action',
      6 => 'audio',
      7 => 'blog_front',
      8 => 'takepart_campaign',
      9 => 'webform',
      10 => 'takepart_group',
      11 => 'takepart_page',
      12 => 'takepart_quick_study',
      13 => 'takepart_slide',
      14 => 'topic_front',
      15 => 'section_front',
    ),
    'flag_short' => 'Test Content',
    'flag_long' => 'Marks a specific piece of content as test data.',
    'flag_message' => 'Content marked as test data',
    'unflag_short' => 'Not Test Content',
    'unflag_long' => 'Remove this item from being considered test content',
    'unflag_message' => 'Content no longer considered test content',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
      ),
      'unflag' => array(
        0 => '2',
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_on_form' => 1,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'takepart_flag',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}
