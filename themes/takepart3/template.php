<?php

/**
 * Each item of the array should be keyed as follows:
 * url (String, 21 characters ) http://www.google.com
 * title (String, 7 characters ) Boo Boo
 * attributes (Array, 0 elements)
 * these are the normal results from a field.
 */
function takepart3_dolinks($links_field) {
  
  if(empty($links_field)) 
    return;
  
  $links = array();
  $opts = array('external' => TRUE);
  foreach($links_field as $link) {
    $links[] = l($link['title'], $link['url'], $opts);
  }
  
  return implode("<span class='delimiter'>|</span>", $links);
  
}