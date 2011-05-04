<?php
/**
 * @file
 * takepart_default_content.features.content.inc
 */

/**
 * Implementation of hook_content_defaults().
 */
function takepart_default_content_content_defaults() {
$content = array();
$content['blogs_landing_page'] = (object)array(
  'exported_path' => 'blogs',
  'title' => 'Blogs',
  'status' => '1',
  'promote' => '0',
  'sticky' => '0',
  'type' => 'section_front',
  'language' => 'und',
  'created' => '1304000047',
  'comment' => '1',
  'translate' => '0',
  'machine_name' => 'blogs_landing_page',
  'body' => array(),
  'field_section_front_context' => array(
    'und' => array(
      0 => array(
        'context' => 'context_field-node-blogs_landing_page',
      ),
    ),
  ),
);
return $content;
}
