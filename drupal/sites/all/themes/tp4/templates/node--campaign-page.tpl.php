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
    hide($content['comments']);
    hide($content['links']);
    print render($content);
  ?>
  <?php if ($show_facebook_comments) : ?>
  <div id="campaign-page-comments" class="campaign-page-comments">
    <h1>Comments <span class="count">(<fb:comments-count href="<?php print $url_production; ?>"></fb:comments-count>)</span></h1>
    <fb:comments href="<?php print $url_production; ?>" numposts="15"></fb:comments>
  </div>
  <?php endif; ?>
</article>
