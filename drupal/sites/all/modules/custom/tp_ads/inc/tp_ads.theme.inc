<?php

/**
 *  @function:
 *    Theme function that is used to generate the div for the ads
 */
function theme_tp_ads_script($variables) {
  //script generate
  $script = theme('html_tag', array(
    'element' => array(
      '#tag' => 'script',
      '#value' => "googletag.cmd.push(function () { googletag.display('" . $variables['ad_gpd_id'] . "'); });",
  )));
  
  //output div
  $output = theme('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#value' => $script,
      '#attributes' => array(
        'id' => $variables['ad_gpd_id'],
        'style' => 'width: ' . $variables['width'] . '; height: ' . $variables['height'] . ';'
  ))));
  
  //output wrapper
  $output_wrapper = theme('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#value_prefix' => '<!--' . $variables['ad_slot'] .  '-->',
      '#value' => $output,
      '#attributes' => array(
        'style' => 'text-align: center;'
      )
  )));
  
  //returns output
  return theme('fresh_ad', array('ad_tag' => $output_wrapper));
}

/**
 *  @function:
 *    Theme function that creates the define slot for the ads
 */
function theme_tp_ads_header($variables) {
  $output = '';
  
  $output = "googletag.defineSlot('/" . $variables['dpf_code'] . "/" . $variables['ad_slot'] . "', [" . $variables['width'] . ", " . $variables['height'] . "], '" . $variables['ad_gpd_id'] . "').addService(googletag.pubads());";
  
  return $output;
}