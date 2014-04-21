<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <header>
      <?php
	// We hide the comments and links now so that we can render them later.
	hide($content['comments']);
	hide($content['links']);
	print render($content); 
        ?>
  <?php if (!$page && $title && $type != "poll"): ?>
    <h2 class="inline-title"><?php print $title; ?></h2>
  <?php endif; ?>

    </header>
</article>
