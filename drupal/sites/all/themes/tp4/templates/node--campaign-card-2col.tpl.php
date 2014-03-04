<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<div class="card campaign-2col <?php print implode(' ', $variables['classes_array']); ?>" style="background-image: url('<?php print $variables['card_background']; ?>')">
  <article class="card-inner">
    <h1 class="card-title"><?php print $title; ?></h1>
    <div class="instructional">
      <?php print $variables['instructional']; ?>
    </div>
    <div class="left-column">
      <?php print $variables['left']; ?>
    </div>
    <div class="right-column">
      <?php print $variables['right']; ?>
    </div>
  </article>
</div>
