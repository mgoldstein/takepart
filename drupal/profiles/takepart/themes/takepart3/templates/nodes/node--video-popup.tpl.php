<?php
// hide all content, we will render them one by one
hide($content['field_video_embedded']);
hide($content['links']);
hide($content['field_promo_headline']);
hide($content['field_promo_text']);
hide($content['embedded_video_link']);
hide($content['field_video_banner_large']);
hide($content['field_video_banner_small']);
?>
<?php if (!empty($pre_object)) print render($pre_object) ?>
<div class='<?php print $classes ?> clearfix node-embedded' <?php print ($attributes) ?>>
  <?php if (!empty($content['field_video_banner_large'])): ?>
  <div class="video-banner-large"><?php print $content['field_video_banner_large'] ?></div>
  <?php endif; ?>
  <div class="inner-wrapper">
    <div class=leftside">
    <?php print $content['field_video_banner_large'] ?>
    </div>
    <div class="rightside">
      <?php if (!empty($title)): ?>
        <h2 <?php if (!empty($title_attributes)) print $title_attributes ?>>
          <a href="<?php print $node_url ?>"><?php print $title ?></a>
        </h2>
      <?php endif; ?>
      <?php print $content['field_promo_headline'] ?>
      <?php print $content['field_promo_text'] ?>
      <p>[subscribe]</p>
      <p>[social]</p>
      <p>[comment - embed]</p>
    </div>
  </div>
  <?php print render($content['field_video_embedded']); ?>
</div>
<?php if (!empty($post_object)) print render($post_object) ?>
