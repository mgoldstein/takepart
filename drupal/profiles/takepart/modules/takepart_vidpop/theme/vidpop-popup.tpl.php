<?php
// node template to create video popup

// get the ad banner - yeah, should be done a little before this, but we're in crunch mode today
$top_banner = takepart_vidpop_get_banner('ga_leaderboard_ros');
  ?>

<?php if (!empty($pre_object)) print render($pre_object) ?>
<div class='<?php print $classes ?> clearfix node-embedded' <?php print ($attributes) ?>>
  <div class="inner-wrapper">
    <?php if (!empty($top_banner)): ?>
    <div class="video-banner-large"><?php print $top_banner ?></div>
    <?php endif; ?>
    <div class="contents">
      <div class="leftside">
      <?php print render($content['field_video_embedded']) ?>
      </div>
      <div class="rightside">
        <?php print render($content['field_promo_headline']) ?>
        <?php print render($content['field_promo_text']) ?>
        <!-- subscribe button -->
        <div class="subscribe"><a href="http://www.youtube.com/subscription_center?add_user_id=FYRWsIH2BivGa_-2LVTsBA&amp;feature=creators_cornier-http%3A//s.ytimg.com/yt/img/creators_corner/Subscribe_to_my_videos/YT_Subscribe_160x27_red.png"><img alt="Subscribe to me on YouTube" src="http://s.ytimg.com/yt/img/creators_corner/Subscribe_to_my_videos/YT_Subscribe_160x27_red.png"></a><img src="http://www.youtube-nocookie.com/gen_204?feature=creators_cornier-http%3A//s.ytimg.com/yt/img/creators_corner/Subscribe_to_my_videos/YT_Subscribe_160x27_red.png" style="display: none"></div>
        <p>[social]</p>
        <p>[comment - embed]</p>
      </div>
    </div>
  </div>
</div>
<?php if (!empty($post_object)) print render($post_object) ?>
