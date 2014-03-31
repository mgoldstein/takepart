<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<div class="card campaign-2col <?php print implode(' ', $variables['classes_array']); ?>" style="background-image: url('<?php print $variables['card_background']; ?>'); <?php print implode(' ', $variables['styles']); ?>">
  <?php print render($title_prefix); ?>
  <?php print render($title_suffix);  // contextual links ?>
  <article class="card-inner">
    <?php if(isset($field_campaign_card_title[0]['value']) == true): ?>
      <h1 class="card-title"><?php print $field_campaign_card_title[0]['value']; ?></h1>
    <?php endif; ?>
    <?php if(isset($variables['instructional']) == true): ?>
      <div class="instructional">
        <?php print $variables['instructional']; ?>
      </div>
    <?php endif; ?>
    <div class="left-column">
      <?php print $variables['left']; ?>
    </div>
    <div class="right-column">
      <?php print $variables['right']; ?>
    </div>
  </article>
</div>
