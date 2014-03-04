
<?php
  // Does the Tray title exist?
  if(isset($variables['entity']->field_campaign_tray_title['und'][0]['value']) == TRUE) {
    $tray_title = $variables['entity']->field_campaign_tray_title['und'][0]['value'];
  }


?>
<div class="swipe-wrap">
<?php
  foreach ($items as $key => $item) {
    $node = node_load($item['target_id']);

    //Set the background of the card
    //If Tray contains a background image, set all other slides to transparent.
    $background_image = $node->field_campaign_background['und'][0]['uri'];
    $background_image = file_create_url($background_image);

    //If a tray has a background we make the card transparent and set the background on the slider level.
    $card_styles = '';
    if(isset($variables['entity']->field_campaign_background) ==  true && $variables['entity']->field_campaign_background != NULL){
      $card_styles = 'style="background-image: none; background-color: transparent;"';
    }
    else{
      $card_styles = 'style="background-image: url(\''. $background_image. '\');"';
    }


    //Card classes in the CSS control background properties.
    $card_classes = array();
    if(isset($tray_title) == true){
      $card_classes[] = 'has-tray-title';
    }
    if(isset($tray_background) == true){
      $card_classes[] = 'has-tray-background';
    }
    $card_classes[] = $node->type;

    print '<div class="card-wrapper '. implode(' ', $card_classes). '" '. $card_styles. '">';
    print drupal_render(node_view($node, 'full', NULL));
    print '</div>';
  }
?>
</div>

<?php // Print arrows is multiple cards exist in the card ?>
<?php if(isset($variables['entity']->field_campaign_card_reference[1]) == true || isset($variables['entity']->field_campaign_card_reference['und'][1]) == true): ?>
  <div class="tray-header">
    <?php if(isset($tray_title) == true): ?>
      <h1 class="card-title"><?php print $tray_title; ?></h1>
    <?php endif; ?>
    <div class="slider pagination"></div>
  </div>
<?php endif; ?>

<?php // Print arrows is multiple cards exist in the card ?>
<?php if(isset($variables['entity']->field_campaign_card_reference['und'][1]) == true): ?>
  <div class="left-arrow"><</div>
  <div class="right-arrow">></div>
<?php endif; ?>