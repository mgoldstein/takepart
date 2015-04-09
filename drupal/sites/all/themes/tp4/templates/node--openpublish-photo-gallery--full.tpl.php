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
    <h3 id="related-stories"><?php print t('Related Stories on TakePart'); ?></h3>
    <?php print render($content['field_related_stories']); ?>
    <?php endif; ?>

    <h3><?php print t('Get More'); ?></h3>
    <ul class="topic-links links inline">
      <?php print render($content['field_topic']); ?>
      <?php print render($content['field_free_tag']); ?>
    </ul>


    <h3 class="top-border"><?php print t('Takepart&#8217;s Most Popular'); ?></h3>
    <div id="taboola-below-article-thumbnails"></div>
        <script type="text/javascript">
            window._taboola = window._taboola || [];
            _taboola.push(
                    {mode: 'organic-thumbnails-a', container: 'taboola-below-article-thumbnails', placement: 'Below Article Thumbnails', target_type: 'mix'}
            );
        </script>

    <h3><?php print t('From The Web'); ?></h3>
    <div id="taboola-below-article-thumbnails-2nd"></div>
        <script type="text/javascript">
            window._taboola = window._taboola || [];
            _taboola.push(
                    {mode: 'thumbnails-a', container: 'taboola-below-article-thumbnails-2nd', placement: 'Below Article Thumbnails 2nd', target_type: 'mix'}
            );
        </script>

    <?php print render($on_our_radar); ?>

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