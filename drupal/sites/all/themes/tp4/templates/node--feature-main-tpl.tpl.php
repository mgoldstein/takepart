<?php
/**
 * @file
 * Returns the HTML for the main featured node
 * on the TP4 Homepage.
 */
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="entry-content">
  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    print render($content);
  ?>
  </div>
  blah blah blah blah
</article>
