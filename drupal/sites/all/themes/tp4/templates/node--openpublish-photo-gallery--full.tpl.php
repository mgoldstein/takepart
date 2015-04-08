<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<div class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php if( $gallery_description =  render($content['body'])) : ?>
  <div id="gallery-description" class="gallery-description hidden">
    <?php print $gallery_description; ?>
    <p class="enter-link"><a id="gallery-description-enter-link" href="#enter-gallery">Enter Photo Gallery</a></p>
  </div>
  <?php endif; ?>
  <aside id="gallery-footer">

    <?php print render($gallery_tap_banner); ?>

    <?php if ($show_fb_comments): ?>
      <div id="gallery-comments">
        <h3 class="top-border"><?php print t('Comments'); ?> <span>(<fb:comments-count href="<?php print $url_production; ?>"></fb:comments-count>)</span></h3>
        <fb:comments href="<?php print $url_production; ?>" numposts="15"></fb:comments>
      </div>
      <script id="facebook-comments-template" type="text/x-javascript-template">
        <h3 class="top-border"><?php print t('Comments'); ?> <span>(<fb:comments-count href="<?php print $url_production; ?>"></fb:comments-count>)</span></h3>
        <fb:comments href="<?php print $url_production; ?>" numposts="15"></fb:comments>
      </script>
    <?php endif; ?>
  </aside>
</div>