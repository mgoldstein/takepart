<?php
/**
 * @file
 * Output for FBIA content analytics pages
 */

/*
 * Grab the DLL value
 */
function tp_fbia_page_analytics($node) {

  if(!empty($node)) {

    node_view($node, 'full');
    /* Get the DDL */
    module_load_include('inc', 'tp_digital_data', 'includes/common');
    $ddl = tp_digital_data_build_ddl_content($node, TRUE);
    //Add FBIA value
    $ddl['page']['pageInfo']['fbia'] = 'Facebook Instant Article';
    $ddl = drupal_json_encode($ddl);

    $dtm_js = variable_get('dtm_script_src', '');

    return theme('tp_fbia_page_analytics', array(
      'ddl' => $ddl,
      'dtm_js' => $dtm_js
    ));

  }
  else {
    drupal_not_found();
  }

}


/**
 * Implements the markup for adobe analytics
 */
function theme_tp_fbia_page_analytics(&$variables) {
  //DDl
  $markup = theme('html_tag', array(
    'element' => array(
      '#tag' => 'script',
      '#attributes' => array(
        'type' => 'text/javascript'
      ),
      '#value' => 'window.digitalData =' . $variables['ddl']
    )
  ));

  //DTM JS library requires jQuery
  $jquery_path = "https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js";

   $markup .= theme('html_tag', array(
    'element' => array(
      '#tag' => 'script',
      '#attributes' => array(
        'type' => 'text/javascript',
        'src' => $jquery_path
      ),
      '#value' => ''
    )
  ));

  $markup .= theme('html_tag', array(
    'element' => array(
      '#tag' => 'script',
      '#attributes' => array(
        'type' => 'text/javascript',
        'src' => $variables['dtm_js']
      ),
      '#value' => ''
    )
  ));


  //DTM Bottom
  $markup .= theme('html_tag', array(
    'element' => array(
      '#tag' => 'script',
      '#attributes' => array(
        'type' => 'text/javascript'
      ),
      '#value' => '_satellite.pageBottom();'
    )
  ));

  return $markup;

}
