<?php
/**
 * @file rightrail-video-popup.tpl.php
 * Display right rail block in a popup
 *
 * - $p_title     block title
 * - $p_video_id  id of video
 * - $p_body      block body
 * - $p_fmt_pop   formatted video for popup
 *
 * @ingroup views_templates
 */

?>
<div class='<?php print $classes ?> clearfix node-embedded' <?php print ($attributes) ?>>
  <div class="inner-wrapper">
    <?php
    if (variable_get('takepart_vidpop_banners_enabled', false)) {
      // get the ad banner
      $top_banner = takepart_vidpop_get_banner();
      // get the logo to the left of the ad banner
      $banner_tp_logo = theme('image', array(
          'path' => drupal_get_path('module', 'takepart') . '/modules/takepart_vidpop/css/images/TP_modal_icon.png',
          'width' => '58px',
          'height' => '58px',
          'title' => 'Takepart'
        )
      );

      if (!$top_banner) {
        watchdog('vidpop', 'no banner retrieved for slot ' . variable_get('takepart_vidpop_ad_id', TAKEPART_VIDPOP_DEFAULT_AD_ID));
      }
      print '<div class="top-banner clearfix">';
      print '  <div class="tp-logo">' . $banner_tp_logo . '</div>';
      print '  <div class="video-banner-large">' . $top_banner . '</div>';
      print '</div>';
    }
    ?>
    <div class="contents">
      <div class="leftside">
        <div class="vidmap">
          <div id="vidpop-social" class="social-links">
            <div class="addthis_toolbox addthis_default_style">
              <a class="addthis_button_facebook_like"
                 addthis:url="<?php print $share_node_url; ?>"
                 fb:like:action="like"
                 fb:like:layout="button_count"></a>
              <a class="addthis_button_tweet"
                 tw:counturl="<?php print $share_node_url; ?>"
                 tw:count="horizontal"
                 tw:url="<?php print $share_node_url; ?>"
                 tw:text="<?php print $share_node_title; ?>"
                 tw:via="TakePart"
                 tw:title="Tweet"></a>
              <a class="addthis_button_email"
                 title="Email"
                 addthis:url="<?php print $share_node_url; ?>"></a>
            </div>
          </div>
        </div>
        <?php print $p_fmt_pop; ?>
      </div>
      <div class="rightside">
        <div class="field-name-field-promo-headline"><?php print $p_title; ?></div>
        <!-- subscribe button -->
        <div class="subscribe <?php print 'rr-' . $p_video_id; ?>"><a target="_blank" href="http://www.youtube.com/subscription_center?add_user_id=FYRWsIH2BivGa_-2LVTsBA&amp;feature=creators_cornier-http%3A//s.ytimg.com/yt/img/creators_corner/Subscribe_to_my_videos/YT_Subscribe_160x27_red.png"><img alt="Subscribe to me on YouTube" src="http://s.ytimg.com/yt/img/creators_corner/Subscribe_to_my_videos/YT_Subscribe_160x27_red.png" /></a></div>
        <div class="comment-link"><?php print $comment_link ?></div>
      </div>
    </div>
  </div>
</div>
