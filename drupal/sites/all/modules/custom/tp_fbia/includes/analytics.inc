<?php
/**
 * @file
 * Output for FBIA content analytics pages
 */

/**
 * Callback for fbia/node/%node/analytics
 */
function tp_fbia_page_analytics($node) {

  if(!empty($node)) {

    //TODO: Get DDL
    $ddl = '';

    return theme('tp_fbia_page_analytics', array(
      'ddl' => $ddl,

    ));
  }
  else {
    drupal_not_found();
  }

}

/**
 * Delivery callback used to override html.tpl.php
 *
 * @param $page_callback_result
 */
function tp_fbia_html_analytics($page_callback_result) {

  //TODO: Get DTM path
  $dtm = '';

  // Pass variables to the template.
  $variables = array(
    'dtm'         => $dtm,
    'content'     => $page_callback_result,
  );

  print theme('tp_fbia_html_analytics', $variables);

}
