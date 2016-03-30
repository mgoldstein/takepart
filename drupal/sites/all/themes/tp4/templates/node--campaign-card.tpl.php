<?php
/**
 * @file
 * Returns the HTML for the campaign card nodes.
 * TODO: Transition all Cards to use this template with individual 'Card Content' templates.
 * Variables created in template.php: $card_title, $variables['classes_array'], $instructional, $card_inner['classes_array'], $card_content
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
<div class="card campaign-1col <?php print implode(' ', $variables['classes_array']); ?>" style="<?php print implode(' ', $variables['styles']); ?>">
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
    <div class="card-content">
      <?php print $variables['card_content']; ?>
    </div>
  </article>
</div>
