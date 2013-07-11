<?php
// node template to create video popup


// get the social links
$social_links = takepart_vidpop_get_social_links();
$comment_link = l('COMMENT', 'node/' . $p_content['field_video_embedded']['#object']->nid, array('fragment' => 'comments', 'attributes' => array('target' => '_blank')));

$embed_nid = $p_content['field_video_embedded']['#object']->nid;
$embed_node = node_load($embed_nid);

$share_node_url = url('node/' . $embed_nid, array('absolute' => TRUE));
$share_node_title = $embed_node->title;

// override options to make large for popup
$p_content['field_video_embedded'][0]['file']['#options']['width'] = 640;
$p_content['field_video_embedded'][0]['file']['#options']['height'] = 360;
?>
<?php if (!empty($pre_object)) print render($pre_object) ?>
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
       <div id="vidpop-social" class="social-links">
         <div class="addthis_toolbox addthis_default_style">
           <a class="addthis_button_facebook_like"
              addthis:url="<?php print $share_node_url; ?>"
              fb:like:href="<?php echo $share_node_url; ?>"
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
      <?php print render($p_content['field_video_embedded']) ?>
      </div>
      <div class="rightside">
        <?php print render($p_content['field_promo_headline']) ?>
        <?php print render($p_content['field_promo_text']) ?>
        <!-- subscribe button -->
        <div class="subscribe standard <?php print 'vp-' . $embed_nid; ?>"><a target="_blank" href="http://www.youtube.com/subscription_center?add_user_id=FYRWsIH2BivGa_-2LVTsBA&amp;feature=creators_cornier-http%3A//s.ytimg.com/yt/img/creators_corner/Subscribe_to_my_videos/YT_Subscribe_160x27_red.png"><img alt="Subscribe to me on YouTube" src="http://s.ytimg.com/yt/img/creators_corner/Subscribe_to_my_videos/YT_Subscribe_160x27_red.png" /></a></div>
        <div class="comment-link"><?php print $comment_link ?></div>
      </div>
    </div>
  </div>
</div>
<?php if (!empty($post_object)) print render($post_object) ?>
