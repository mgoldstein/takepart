<?php
/**
 * @file
 * Returns the HTML for the main featured node
 * on the TP4 Homepage.
 */
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <header class="entry-header">
      <?php print render($content['field_thumbnail']); ?>

      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php if ($unpublished): ?>
        <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>

      <?php print render($content['field_author']); ?>
    </header>

  <div class="entry-content">
  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    print render($content);
  ?>
  </div>
</article>
