<?php

/**
 *  @function:
 *    Theme function that is used to generate the div for the ads
 */
function theme_tp_ads_script($variables) {
  $label = '';

  //generate the list of ad sizes for multiple ad unit sizes
  $adwidth = explode(',', str_replace(' ', '', $variables['width']));
  $adheight = explode(',',str_replace(' ', '', $variables['height']));
  $i = 0;
  $adsizes = "[";
  //Run through all the different ad sizes
  while( $i < count($adwidth) && $i < count($adheight) ) {
    $adsizes .= ($i == 0?'':',');
    $adsizes .= "[".(isset($adwidth[$i])?$adwidth[$i]:0).",".(isset($adheight[$i])?$adheight[$i]:0)."]";
    $i++;
  }
  $adsizes .= "]";

  //script generate
  $script = theme('html_tag', array(
    'element' => array(
      '#tag' => 'script',
      '#value' => "googletag.cmd.push(function() { [targets]
      window." . str_replace('-', '_', $variables['ad_slot']) . " = googletag.defineSlot('/4355895/" . $variables['ad_slot'] . "', ".$adsizes.", '" . $variables['ad_gpd_id'] . "').addService(googletag.pubads());
        googletag.enableServices();
        googletag.display('" . $variables['ad_gpd_id'] . "');
        });"
  )));

  if (!$variables['disable_label']) {
    $label = '<h5 class="ad-label text-center">Advertisement</h5>';
  }

  //$styles = 'width: ' . $variables['width'] . 'px; height: ' . ($variables['height'] + 25). 'px; ';
  $styles = '';

  //output div
  $output = theme('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#value' => $script,
      '#attributes' => array(
        'id' => $variables['ad_gpd_id'],
        'style' => (($variables['class'] == 'leaderboard desktop') ? '' : $styles),
        'class' => $variables['class'] . ' dfp-ad-tag',
  ))));

  //output wrapper
  $output_wrapper = theme('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#value_prefix' => '<!--' . $variables['ad_slot'] .  '-->' . $label,
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
 *    Theme function that is used to generate the div for the responsive ads
 */
function theme_tp_ads_responsive_script($variables) {
  $label = '';

  $sizes = array('mobile', 'tablet', 'desktop');
  foreach($sizes as $size) {
    $i = 0;
    //generate the list of ad sizes for multiple ad unit sizes
    $adwidth[$size] = explode(',', str_replace(' ', '', $variables['width_'.$size]));
    $adheight[$size] = explode(',',str_replace(' ', '', $variables['height_'.$size]));
    $adsizes[$size] = "[";

    //Run through all the different ad sizes
    while( $i < count($adwidth[$size]) && $i < count($adheight[$size]) ) {
      $adsizes[$size] .= ($i == 0?'':',');
      $adsizes[$size] .= "[".(isset($adwidth[$size][$i])?$adwidth[$size][$i]:0).",".(isset($adheight[$size][$i])?$adheight[$size][$i]:0)."]";
      $i++;
    }
    $adsizes[$size] .= "]";
  }

  $mapping = "var mapping = googletag.sizeMapping().addSize([980, 0], ".$adsizes['desktop'].").addSize([768, 0], ".$adsizes['tablet'].").addSize([0, 0], ".$adsizes['mobile'].").build();";
  //script generate
  $script = theme('html_tag', array(
    'element' => array(
      '#tag' => 'script',
      '#value' => "googletag.cmd.push(function() { [targets]
        ".$mapping."
      window." . str_replace('-', '_', $variables['ad_slot']) . " = googletag.defineSlot('/4355895/" . $variables['ad_slot'] . "', [728,90], '" . $variables['ad_gpd_id'] . "').defineSizeMapping(mapping).addService(googletag.pubads());
        googletag.enableServices();
        googletag.display('" . $variables['ad_gpd_id'] . "');
        });"
  )));

  if (!$variables['disable_label']) {
    $label = '<h5 class="ad-label text-center">Advertisement</h5>';
  }

  //$styles = 'width: ' . $variables['width'] . 'px; height: ' . ($variables['height'] + 25). 'px; ';
  $styles = '';

  //output div
  $output = theme('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#value' => $script,
      '#attributes' => array(
        'id' => $variables['ad_gpd_id'],
        'style' => (($variables['class'] == 'leaderboard desktop') ? '' : $styles),
        'class' => $variables['class'] . ' dfp-ad-tag',
  ))));

  //output wrapper
  $output_wrapper = theme('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#value_prefix' => '<!--' . $variables['ad_slot'] .  '-->' . $label,
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
    //generate the list of ad sizes for multiple ad unit sizes
    $adwidth = explode(',', str_replace(' ', '', $variables['width']));
    $adheight = explode(',',str_replace(' ', '', $variables['height']));
    $i = 0;
    $adsizes = "[";
    //Run through all the different ad sizes
    while( $i < count($adwidth) && $i < count($adheight) ) {
      $adsizes .= ($i == 0?'':',');
      $adsizes .= "[".(isset($adwidth[$i])?$adwidth[$i]:0).",".(isset($adheight[$i])?$adheight[$i]:0)."]";
      $i++;
    }
    $adsizes .= "]";

    $output = "googletag.defineSlot('/" . $variables['dpf_code'] . "/" . $variables['ad_slot'] . "', [" . $variables['width'] . ", " . $variables['height'] . "], '" . $variables['ad_gpd_id'] . "').addService(googletag.pubads());";
  }

  return $output;
}
