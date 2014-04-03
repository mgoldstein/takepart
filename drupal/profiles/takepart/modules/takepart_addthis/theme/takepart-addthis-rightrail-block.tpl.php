<?php
$node = menu_get_object(); 
$view = views_get_view('photo_gallery'); 
$style = <<<STYLE
<style type="text/css">
.view-photo-gallery{ font-family:Helvetica, Arial, sans-serif; width: 302px; }
.view-photo-gallery a,
.view-photo-gallery a:link,
.view-photo-gallery a:visited{ border:none; text-decoration:none; }
.view-photo-gallery .views-field-field-gallery-main-image img{ border:solid 1px black; display:block; }
.view-photo-gallery .views-field-field-promo-headline a,
.view-photo-gallery .views-field-field-promo-headline a:link,
.view-photo-gallery .views-field-field-promo-headline a:visited{ font-size: 20px; color:#333; font-weight:bold; display:block; margin:10px 0; }
.view-photo-gallery .views-field-field-promo-text a,
.view-photo-gallery .views-field-field-promo-text a:link,
.view-photo-gallery .views-field-field-promo-text a:visited{ color:#333; font-size:14px; line-height:16px; }
.view-photo-gallery .views-field-field-promo-headline a:hover,
.view-photo-gallery .views-field-field-promo-text a:hover{ color:#1CA9E7; }
</style>
STYLE;
$addthis_embed = $view->preview('block_2'). $style;
?>
 
<!-- AddThis Button BEGIN -->
<div class="takepart_addthis_rightrail clearfix">
  <div class="addthis_share clearfix">
    <div class="addthis_rightrail_title">Share</div>
    <div class="addthis_toolbox addthis_default_style addthis_rightrail_firstrow clearfix">
      <span class="button_container button_fb"><a class="addthis_button_facebook_like" fb:like:layout="button_count" fb:like:action="<?php print $variables['takepart_addthis_facebook_like_text'];?>" fb:like:href="<?php echo url(current_path(), array('absolute' => TRUE)); ?>"></a></span>
      <span class="button_container button_twitter"><a class="addthis_button_tweet" tw:via="<?php print $variables['takepart_addthis_tweet_via']; ?>" tw:text="<?php print $node->title; ?>"></a></span><br style="clear: both" />
      <span class="button_container"><a class="addthis_button_google_plusone"></a></span>
      <span class="button_container"><a class="addthis_button_linkedin_counter"></a></span>
    </div>

    <div class="addthis_toolbox clearfix">
       <div class="custom_images clearfix"><?php print $variables['addthis_custom_buttons'] ?></div>
    </div>
  </div>

  <div class="addthis_embed">
    <div class="addthis_rightrail_title">Embed</div>
    <div class="addthis_embed_textbox">
      <input value ='<?php print $addthis_embed ?>'>
    </div>
  </div>

</div>
  <script type="text/javascript" src="//s7.addthis.com/js/250/addthis_widget.js#pubid=<?php print $variables['addthis_pubid'] ?>"></script>
<!-- AddThis Button END -->

