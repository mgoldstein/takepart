<?php
/*
 * @file
 *
 * This file holds custom hook for the takepart blog feature
 */
function takepart_blog_entity_info_alter(&$entity_info) {
  $entity_info['taxonomy_term']['view modes']['summary'] = array('label' => 'Summary', 'custom settings' => FALSE);
}
