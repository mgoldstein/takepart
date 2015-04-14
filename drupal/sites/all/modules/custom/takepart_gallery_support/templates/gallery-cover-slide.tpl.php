<?php
/**
 * @file
 * Template for a Gallery Cover Slide.
 */
?>
<div class="gallery-cover-slide">
  <aside class="social social-horizontal">
    <?php
    $social_elements = array(
        'share',
        'action' => array(
            'data-desktop-pos' => '0',
        ),
        'overlay'
    );
    $options = array('overlay' => TRUE);
    print theme('tp_social_menu', array('elements' => $social_elements, 'options' => $options));
    ?>
  </aside>
  <div id="gallery-cover">
    <a id="gallery-enter-link" href="#enter-gallery">
      <?php print $gallery_cover_image; ?>
      <div class="gallery-cover-content">
        <div class="gallery-cover-branding"><?php print t('Photo Gallery'); ?></div>
        <div class="gallery-cover-title"><?php print $gallery_title; ?></div>
        <div class="gallery-cover-enter"><?php print t('Enter Photo Gallery'); ?></div>
      </div>
    </a>
  </div>
</div>