<?php
/**
 * @file
 * Template for Takepart Photo Gallery Content
 */
?>
<article id="node-<?php print $node->nid; ?>" class="gallery-content">
  <header id="gallery-header" class="gallery-header clearfix">
    <?php if (isset($field_topic_box_top)) : ?>
    <div class="topic-box">
      <?php print $field_topic_box_top; ?>
    </div>
    <?php endif; ?>
    <h1 class="gallery-headline"><?php print $gallery_title; ?></h1>
    <?php print render($gallery_subhead); ?>
    <div class="author">
      <date class="publish-date" datetime="<?php print date('c', $node->created); ?>"><?php print date('F d, Y',$node->created) ?></date>
      <span class="byline"><?php print $gallery_authors; ?></span>
    </div>
    <aside id="gallery-content-social" class="social">
       <div class="tp-sharing-container">
         <h3 class="headline"><?=t('Share Photo') ?></h3>
         <div class="tp-social" id="gallery-cover-share"></div>
        </div>
      <div class="tap-influence-overlay"></div>
    </aside>
  </header>

  <div class="slides-wrapper">
    <div id="slides" class="swipe">
      <div class="swipe-wrap">
      <?php foreach($slides as $delta => $slide) : ?>
        <div<?php print drupal_attributes($slide['attributes']) ?>>
          <figure>
            <div class="slide-image-wrapper">
              <?php print $slide['image']; ?>
            </div>
            <figcaption class="slide-caption">
              <h2 class="slide-caption-headline"><?php print $slide['title']; ?></h2>
              <div class="slide-caption-content"><?php print $slide['caption']; ?></div>
            </figcaption>
          </figure>
        </div>
      <?php endforeach; ?>
      <?php if ($next_gallery) : ?>
        <div id="next-gallery"<?php print drupal_attributes($next_gallery['attributes']); ?>>
          <figure>
            <a id="next-gallery-enter-link" href="<?php print $next_gallery['href']; ?>">
              <div class="slide-image-wrapper">
                <?php print $next_gallery['image']; ?>
                <div class="gallery-cover-content">
                  <div class="gallery-cover-branding"><?php print t('Up Next'); ?></div>
                  <div class="gallery-cover-title"><?php print $next_gallery['title']; ?></div>
                  <div class="gallery-cover-enter"><?php print t('Enter Photo Gallery'); ?></div>
                </div>
              </div>
            </a>
            <figcaption class="slide-caption">
            <h2 class="slide-caption-headline"><?php print $next_gallery['title']; ?></h2>
            <div class="slide-caption-content"><?php print $next_gallery['caption']; ?></div>
            </figcaption>
          </figure>
        </div>
      <?php endif; ?>
      </div>
    </div>
    <nav id="gallery-nav" class="gallery-nav">
      <span id="previous-slide" class="gallery-nav-link previous" title="Previous Slide"></span>
      <span class="pagination"><span id="current-slide">0</span> of <span id="total-slides">0</span></span>
      <span id="next-slide" class="gallery-nav-link next" title="Next Slide"></span>
      <?php if($next_gallery) : ?><a href="<?php print $next_gallery['href']; ?>" id="next-gallery-nav-link" class="gallery-nav-link next-gallery hidden" title="Next Slide"></a><? endif; ?>
    </nav>
  </div>
</article>
