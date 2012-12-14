<?php
// node template to create video page for mobile devices
//
// vars:
//    p_video_nid
//    p_video_title
//    p_video_text
//    p_youtube_id


// get the social links
$social_links = takepart_vidpop_get_social_links();
$comment_link = l('COMMENT', 'node/' . $p_video_nid, array('fragment' => 'comments', 'attributes' => array('target' => '_blank')));

$embed_nid = $p_content['field_video_embedded']['#object']->nid;
$share_node_url = url('node/' . $p_video_nid, array('absolute' => TRUE));
$share_node_title = $p_video_title;
?>
<?php if (!empty($pre_object)) print render($pre_object) ?>
<div class='<?php print $classes ?> vidpop-popup clearfix node-embedded' <?php print ($attributes) ?>>
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
    }
?>
    <div class="contents">
      <div class="backto"><a href="<?print $p_referrer;?>">GO BACK</a></div>
      <div class="video">
        <iframe width="480" height="360" src="http://www.youtube.com/embed/<?php print $p_youtube_id; ?>?rel=0" frameborder="0" allowfullscreen></iframe>
      </div>
      <div class="leftside">
        <div class="vtitle"><?php print $p_video_title ?></div>
        <div class="vbody"><?php print $p_video_text ?></div>
      </div>
      <div class="rightside">
        <!-- subscribe button -->
        <div class="subscribe <?php print 'vp-' . $embed_nid; ?>"><a target="_blank" href="http://www.youtube.com/subscription_center?add_user_id=FYRWsIH2BivGa_-2LVTsBA&amp;feature=creators_cornier-http%3A//s.ytimg.com/yt/img/creators_corner/Subscribe_to_my_videos/YT_Subscribe_160x27_red.png"><img alt="Subscribe to me on YouTube" src="http://s.ytimg.com/yt/img/creators_corner/Subscribe_to_my_videos/YT_Subscribe_160x27_red.png" /></a></div>

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
        <div class="comment-link"><?php print $comment_link ?></div>
      </div>
    </div>
  </div>
</div>
