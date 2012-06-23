<?php if (!empty($pre_object)) print render($pre_object) ?>
<div class='<?php print $classes ?> clearfix node-embedded' <?php print ($attributes) ?>>
  <?php if (!empty($content['field_video_banner_large'])): ?>
  <div class="video-banner-large"><?php print $content['field_video_banner_large'] ?></div>
  <?php endif; ?>
  <div class="inner-wrapper">
    <div class=leftside">
    <?php print $content['thumbnail_image'] ?>
    </div>
    <div class="rightside">
      <?php print render($content['field_promo_headline']) ?>
      <?php print render($content['field_promo_text']) ?>
      <p>[subscribe]</p>
      <p>[social]</p>
      <p>[comment - embed]</p>
    </div>
  </div>
</div>
<?php if (!empty($post_object)) print render($post_object) ?>
