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
      <a class="inline-content-link" href="<?php print $url_local; ?>">
      <?php print render($content); ?>
      <h2 class="inline-title"><?php print $title; ?></h2>
      </a>
    </header>
</article>
