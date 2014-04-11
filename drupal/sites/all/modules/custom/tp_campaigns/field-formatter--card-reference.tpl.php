
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
      $card_styles = 'style="background-image: none; background-color: transparent; background-size: 980px;"';

    }
    else{
      // $card_styles = 'style="background-image: url(\''. $background_image. '\');"';
    }


    //Card classes in the CSS control background properties.
    $card_classes = array();
    if(isset($tray_title) == true){
      $card_classes[] = 'has-tray-title';
    }
    if(isset($tray_background) == true){
      $card_classes[] = 'has-tray-background';
    }
    if(isset($node->field_campaign_card_title['und'][0]['value']) == true){
      $card_classes[] = 'has-card-title';
    }

    $card_classes[] = $node->type;

    print '<div class="card-wrapper '. implode(' ', $card_classes). '" '. $card_styles. '>';
    print drupal_render(node_view($node, 'full', NULL));
    print '</div>';
  }
?>
</div>
<?php
    if(isset($variables['entity']->field_campaign_anchor_tag['und'][0]['value']) == true){
      $title = strtolower($variables['entity']->field_campaign_anchor_tag['und'][0]['value']);
      $title = preg_replace("/[^a-z0-9_\s-]/", "", $title);
      $title = preg_replace("/[\s-]+/", " ", $title);
      $title = preg_replace("/[\s_]/", "-", $title);
    }
?>

<?php print '<a class="card-anchor" id="'. $title. '"></a>'; ?>
<?php // Print arrows is multiple cards exist in the card ?>



<?php if(isset($variables['entity']->field_campaign_card_reference[1]) == true || isset($variables['entity']->field_campaign_card_reference['und'][1]) == true): ?>
  <div class="tray-header">

    <nav class="slider-pagination">
    <div class="mobile-arrow arrow-left"></div>
      <?php for($i = 0; $i < count($items); $i++) : ?>
        <a<?php print drupal_attributes(array(
            'href' => '#',
            'data-slide' => $i,
            'data-for-tray' => $variables['entity']->title,
          ));
          ?>><?php print $i; ?></a>
      <?php endfor; ?>
      <div class="mobile-arrow arrow-right"></div>
    </nav>

    <?php if(isset($tray_title) == true): ?>
      <h1 class="card-title"><?php print $tray_title; ?></h1>
    <?php endif; ?>
  </div>
<?php endif; ?>

<?php // Print arrows is multiple cards exist in the card ?>
<?php if(isset($variables['entity']->field_campaign_card_reference['und'][1]) == true): ?>
  <nav class="slider-nav">
    <div class="slider-inner">
      <div<?php print drupal_attributes(array(
        'class' => array('arrow','left-arrow'),
        'data-for-tray' => $variables['entity']->title)); ?>
        ><div class="arrow-inner"></div></div>
      <div<?php print drupal_attributes(array(
        'class' => array('arrow','right-arrow'),
        'data-for-tray' => $variables['entity']->title)); ?>
        ><div class="arrow-inner"></div></div>
    </div>
  </nav>
<?php elseif(isset($tray_title) == true): ?>
  <div class="tray-header">
    <h1 class="card-title"><?php print $tray_title; ?></h1>
  </div>
<?php endif; ?>





