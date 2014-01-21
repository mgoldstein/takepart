<?php
/**
 * @file
 * Template for a Gallery Cover Slide.
 */
?>
<div class="gallery-cover-slide">
  <aside id="gallery-cover-social" class="social">
    <h3 class="headline"><?=t('Share Gallery') ?></h3>
    <div class="tp-social" id="gallery-cover-share"></div>
  </aside>
  <a href="#enter-gallery">
    <?php print $gallery_cover_image; ?>
    <div class="gallery-cover-content">
      <div class="gallery-cover-branding"><?php print t('Photo Gallery'); ?></div>
      <div class="gallery-cover-title"><?php print $gallery_title; ?></div>
      <div class="gallery-cover-enter"><?php print t('Enter Photo Gallery'); ?></div>
    </div>
  </a>
</div>