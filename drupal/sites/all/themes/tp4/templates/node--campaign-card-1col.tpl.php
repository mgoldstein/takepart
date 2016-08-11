<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<?php if($variables['background_class']) { ?>
<style>
.<?php print $variables['background_class']; ?> {
  <?php print $variables['background_image_mobile'][0]; ?>
}
@media only screen and (min-width: 728px) {
  .<?php print $variables['background_class']; ?> {
    <?php print $variables['background_image_tablet'][0]; ?>
  }
}
@media only screen and (min-width: 980px) {
  .<?php print $variables['background_class']; ?> {
    <?php print $variables['background_image_desktop'][0]; ?>
  }
}
</style>
<?php } ?>
<!-- This sets the bg for parallax field
<?php if($variables['parallax_bg']) { ?>
<style>
<?php foreach ($variables['parallax_bg'] as $key => $parallax_bg) { ?>
  .<?php print ($variables['background_class'] . ' .parallax-' . $key); ?> {
    <?php print $parallax_bg['background_image_mobile']; ?>
  }
  @media only screen and (min-width: 728px) {
    .<?php print ($variables['background_class'] . ' .parallax-' . $key); ?> {
      <?php print $parallax_bg['background_image_tablet']; ?>
    }
  }
  @media only screen and (min-width: 980px) {
    .<?php print ($variables['background_class'] . ' .parallax-' . $key); ?> {
      <?php print $parallax_bg['background_image_desktop']; ?>
    }
  }
  <?php } ?>
  </style>
<?php } ?>
 -->

<div class="card campaign-1col <?php print implode(' ', $variables['classes_array']) ?>" style="<?php print implode(' ', $variables['styles']); ?>" <?php print $variables['attributes']; ?>>
  <?php print render($title_prefix); ?>
  <article class="card-inner<?php if(isset($variables['slim_text'])){ print " ".$variables['slim_text']; }?>">
  <?php print render($title_suffix);  // contextual links ?>
    <?php if(isset($node->field_campaign_card_title['und'][0]['value']) == true): ?>
      <div class="title-wrapper"><h1 class="card-title <?php print (isset($variables['instructional']) == true ? 'has-instructional' : ''); ?>"><?php print $node->field_campaign_card_title['und'][0]['value']; ?></h1></div>
    <?php endif; ?>
    <?php if(isset($variables['instructional']) == true): ?>
      <div class="instructional">
        <?php print $variables['instructional']; ?>
      </div>
    <?php endif; ?>
    <div class="center-column">
      <?php print $variables['center']; ?>
    </div>
  </article>
<!--   <?php foreach ($variables['parallax'] as $parallax_class): ?>
    <div class = "parallax <?php print $parallax_class; ?>">
    </div>
  <?php endforeach; ?> -->
<!-- </div> -->
  </div>
