<?php
$view = views_get_view('photo_gallery'); 
$addthis_embed = $view->preview('block_2');
?>
 
<!-- AddThis Button BEGIN -->
<div class="takepart_addthis_rightrail clearfix">
  <div class="addthis_share clearfix">
    <div class="addthis_rightrail_title">Share</div>
    <div class="addthis_toolbox addthis_default_style addthis_rightrail_firstrow clearfix">
      <!-- <span class="button_container"><a class="addthis_button_google_plusone"></a></span> -->
      <span class="button_container button_fb"><a class="addthis_button_facebook_like" fb:like:layout="button_count"></a></span>
      <span class="button_container button_twitter"><a class="addthis_button_tweet"></a></span>
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
  <script type="text/javascript" src="http://s7.addthis.com/js/250/addthis_widget.js#pubid=<?php print $variables['addthis_pubid'] ?>"></script>
<!-- AddThis Button END -->

