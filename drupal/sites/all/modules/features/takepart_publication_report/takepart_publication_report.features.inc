<?php
/**
 * @file
 * takepart_publication_report.features.inc
 */

/**
 * Implements hook_views_api().
 */
function takepart_publication_report_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

function takepart_publication_report_views_query_alter(&$view, &$query) {
  dd($view->name);
    switch($view->name) {
    case 'myViewName':       
      $query->orderby[0] = "FIELD(node.type, 'story', 'page', 'productTypeC', 'productTypeD') ASC";
      $query->orderby[1] = "node_title ASC";
      break;
  }
  
}