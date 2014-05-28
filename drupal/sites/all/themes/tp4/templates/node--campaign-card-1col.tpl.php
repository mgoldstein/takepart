<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<div class="card campaign-1col <?php print implode(' ', $variables['classes_array']); ?>" style="background-image: url('<?php print $variables['card_background']; ?>'); <?php print implode(' ', $variables['styles']); ?>">
  <?php print render($title_prefix); ?>
  <article class="card-inner<?php if(isset($variables['slim_text'])){ print " ".$variables['slim_text']; }?>">
  <?php print render($title_suffix);  // contextual links ?>
    <?php if(isset($node->field_campaign_card_title['und'][0]['value']) == true): ?>
      <?php dpm($variables, 'variables'); ?>
      <div class="title-wrapper"><h1 class="card-title <?php print (isset($variables['instructional']) == true ? 'has-instructional' : ''); ?>"><?php print $node->field_campaign_card_title['und'][0]['value']; ?></h1></div>
    <?php endif; ?>
    <?php print render($content['field_campaign_instructional']); ?>
    <div class="center-column">
      <?php print $variables['center']; ?>
    </div>
  </article>
</div>
