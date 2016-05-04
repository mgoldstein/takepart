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

    node_view($node, 'full');
    /* Get the DDL */
    module_load_include('inc', 'tp_digital_data', 'includes/common');
    $ddl = tp_digital_data_build_ddl_content($node);
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
 * Delivery callback used to override html.tpl.php
 *
 * @param $page_callback_result
 */
function tp_fbia_html_analytics($page_callback_result) {
  // Pass variables to the template.
  $variables = array(
    'head_title'  => drupal_set_title('Analytics'),
    'head' => $page_callback_result['head'],
    'body' => $page_callback_result['body']
  );

  print theme('tp_fbia_html_analytics', $variables);

}

/**
 * Implements theme_HOOK
 */
function theme_tp_fbia_page_analytics(&$variables) {
  $markup = array();
  $markup['head'] = theme('html_tag', array(
    'element' => array(
      '#tag' => 'script',
      '#attributes' => array(
        'type' => 'text/javascript',
        'src' => $variables['dtm_js']
      ),
      '#value' => ''
    )
  ));

  //DDl
  $markup['head'] .= theme('html_tag', array(
    'element' => array(
      '#tag' => 'script',
      '#attributes' => array(
        'type' => 'text/javascript'
      ),
      '#value' => 'window.digitalData =' . $variables['ddl']
    )
  ));

  //DTM Bottom
  $markup['body'] = theme('html_tag', array(
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
