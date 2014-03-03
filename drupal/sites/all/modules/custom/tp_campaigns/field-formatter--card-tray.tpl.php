<?php
  foreach ($items as $key => $item) {
    $node = node_load($item['target_id']);
    //If a tray has a background we make the card transparent and set the background on the slider level.
    $slider_styles = '';
    if(isset($node->field_campaign_background) ==  true && $node->field_campaign_background != NULL){
      $background_image = $node->field_campaign_background['und'][0]['uri'];
      $background_image = file_create_url($background_image);
      $slider_styles = 'style="background-image: url(\''. $background_image. '\');"';
      $slider_class = 'has-tray-background';
    }
    else{
      $slider_class = '';
      $slider_styles = '';
    }
    print '<div id="slider_'. $key. '" class="swipe slider '. $slider_class. '" '. $slider_styles. '>';
    print drupal_render(node_view($node, 'full', NULL));
    print '</div>';
  }
?>