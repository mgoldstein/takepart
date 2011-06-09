<?php
/*
 * @file
 *
 * This file holds custom hook for the takepart blog feature
 */
function takepart_our_blogs_entity_info_alter(&$entity_info) {
  $entity_info['taxonomy_term']['view modes']['our blogs summary'] = array('label' => 'Our Blogs Summary', 'custom settings' => FALSE);
}
