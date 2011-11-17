<?php
/*
 * @file
 *
 * This file holds custom hook for the takepart blog feature
 */
function takepart_blog_entity_info_alter(&$entity_info) {
  $entity_info['taxonomy_term']['view modes']['summary'] = array('label' => 'Summary', 'custom settings' => FALSE);
  $entity_info['taxonomy_term']['view modes']['our_blogs_summary'] = array('label' => 'Our Blogs Summary', 'custom settings' => FALSE);
}
