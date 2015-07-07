<?php

/**
 *  @function:
 *    Theme function that is used to generate the div for the ads
 */
function theme_tp_ads_script($variables) {
  $label = '';
  
  //script generate
  $script = theme('html_tag', array(
    'element' => array(
      '#tag' => 'script',
      '#value' => "googletag.cmd.push(function() { window." . str_replace('-', '_', $variables['ad_slot']) . "  = googletag.pubads().display('/4355895/" . $variables['ad_slot'] . "', [" . $variables['width'] . ", " . $variables['height'] . "], '" . $variables['ad_gpd_id'] . "'); googletag.pubads().setTargeting('PageTitle', '[page-title]'); googletag.pubads().setTargeting('Type', '[type]'); googletag.pubads().setTargeting('Topic', [topics]);});"
  )));

  if (!$variables['disable_label']) {
    $label = '<h5 class="ad-label text-center">Advertisement</h5>';
  }
  
  //output div
  $output = theme('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#value' => $script,
      '#value_prefix' => $label,
      '#attributes' => array(
        'id' => $variables['ad_gpd_id'],
        'style' => 'width: ' . $variables['width'] . 'px; height: ' . ($variables['height'] + 25). 'px; margin: 0 auto;',
        'class' => $variables['class'],
  ))));
  
  //output wrapper
  $output_wrapper = theme('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#value_prefix' => '<!--' . $variables['ad_slot'] .  '-->',
      '#value' => $output,
      '#attributes' => array(
        'style' => 'text-align: center;',
        'class' => 'tp-main-ad-wrapper'
      )
  )));

  //returns output
  return theme('fresh_ad', array('ad_tag' => $output_wrapper, 'class' => $class));
}

/**
 *  @function:
 *    Theme function that creates the define slot for the ads
 */
function theme_tp_ads_header($variables) {
  $output = '';
  
  if (!empty($variables['dpf_code']) && !empty($variables['ad_slot']) && !empty($variables['width']) && !empty($variables['height'])) {
    $output = "googletag.defineSlot('/" . $variables['dpf_code'] . "/" . $variables['ad_slot'] . "', [" . $variables['width'] . ", " . $variables['height'] . "], '" . $variables['ad_gpd_id'] . "').addService(googletag.pubads());";
  }
  
  return $output;
}