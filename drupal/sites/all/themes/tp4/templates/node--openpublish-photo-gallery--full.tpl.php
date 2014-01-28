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
    <!-- related content? -->

    <?php print render($gallery_tap_banner); ?>

    <?php if($content['field_related_stories']) : ?>
    <h3><?php print t('Related Stories on TakePart'); ?></h3>
    <?php print render($content['field_related_stories']); ?>
    <?php endif; ?>

    <h3><? print t('Get More'); ?></h3>
    <ul class="topic-links links inline">
      <?php print render($content['field_topic']); ?>
      <?php print render($content['field_free_tag']); ?>
    </ul>

    <div class="OUTBRAIN" data-src="<?php print $url_production; ?>" data-widget-id="TR_1" data-ob-template="TakePart" ></div>
    <script type="text/javascript" async="async" src="http://widgets.outbrain.com/outbrain.js"></script>

    <h3 class="top-border"><?php print t('Takepart&#8217;s Most Popular'); ?></h3>
    <div id='taboola-bottom-main-column-mix'></div>
    <script type="text/javascript">
      window._taboola = window._taboola || [];
      _taboola.push({mode:'thumbs-1r-organic', container:'taboola-bottom-main-column-mix', placement:'bottom-main-column', target_type:'mix'});
    </script>

    <?php print render($on_our_radar); ?>

    <div id="gallery-comments">
      <h3 class="top-border"><?php print t('Comments'); ?> <span>(<fb:comments-count href="<?php print $url_production; ?>"></fb:comments-count>)</span></h3>
      <fb:comments href="<?php print $url_production; ?>" numposts="15"></fb:comments>
    </div>
    <script id="facebook-comments-template" type="text/x-javascript-template">
      <h3 class="top-border"><?php print t('Comments'); ?> <span>(<fb:comments-count href="<?php print $url_production; ?>"></fb:comments-count>)</span></h3>
      <fb:comments href="<?php print $url_production; ?>" numposts="15"></fb:comments>
    </script>
  </aside>
</div>