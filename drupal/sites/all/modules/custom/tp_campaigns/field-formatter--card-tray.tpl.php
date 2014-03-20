<?php
  foreach ($items as $key => $item) {
    $node = node_load($item['target_id']);
    //If a tray has a background we make the card transparent and set the background on the slider level.
    $slider_styles = array();
    $slider_class = array();

// i need to print inline styling to the
    if(isset($node->field_campaign_bgw_image['und'][0]['value']) == TRUE) {
      $bg_width_img = $node->field_campaign_bgw_image['und'][0]['value'];
    }
    if(isset($node->field_campaign_bgw['und'][0]['value']) == TRUE) {
      $bg_width = $node->field_campaign_bgw['und'][0]['value'];
    }
    if(isset($node->field_campaign_bg_color['und'][0]['rgb']) == TRUE) {
      $bg_color = $node->field_campaign_bg_color['und'][0]['rgb'];
      $slider_styles[] = 'background-color: '. $bg_color. ';';
    }
    // print_r($node->field_campaign_bgw_image);
    if(isset($bg_width) == true){
      $slider_class[] = ($bg_width == 0 ? 'tray-width-full' : 'tray-width-1000');
    }
    if(isset($bg_width_img) == true){
      $slider_class[] = ($bg_width_img == 0 ? 'tray-img-width-full' : 'tray-img-width-1000');
    }




    if(isset($node->field_campaign_background) ==  true && $node->field_campaign_background != NULL){
      $background_image = $node->field_campaign_background['und'][0]['uri'];
      $background_image = file_create_url($background_image);
      $slider_styles[] = 'background-image: url(\''. $background_image. '\');';
      $slider_class[] = 'has-tray-background';
    }
    else{
      $slider_class[] = '';
    }
    if(isset($node->field_campaign_card_reference['und'][1]) == true){
      $slider_class[] = 'has-multiple-cards';
    }
    print '<div id="slider_'. $key. '" class="swipe slider '. implode(' ', $slider_class). '" style="'. implode(' ', $slider_styles). '">';
    print drupal_render(node_view($node, 'full', NULL));
    print '</div>';
  }?>