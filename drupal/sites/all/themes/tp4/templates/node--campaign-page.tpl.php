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
  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    print render($content);
    // print render($content['links']);
    // print render($content['comments']);
  ?>
  <div id="article-comments">
    <h3 class="top-border">Comments <span>(<fb:comments-count href="<?php print $url_production; ?>"></fb:comments-count>)</span></h3>
    <fb:comments href="<?php print $url_production; ?>" numposts="15"></fb:comments>
  </div>
</article>

