<?php
$node = menu_get_object(); 
?>
<!-- AddThis Button BEGIN -->
<div class="takepart_addthis_leftpanel clearfix">
  <div class="addthis_toolbox addthis_default_style">
    <a class="addthis_button_google_plusone"></a>
    <a class="addthis_button_facebook_like" fb:like:layout="button_count" fb:like:action="<?php print $variables['takepart_addthis_facebook_like_text'];?>"></a> 
    <a class="addthis_button_tweet" tw:via="<?php print $variables['takepart_addthis_tweet_via']; ?>" tw:text="<?php print $node->title; ?>"></a>
    <a class="addthis_button_linkedin_counter"></a>
  </div>
  <div class="addthis_toolbox">
    <div class="custom_images">
      <?php print $variables['addthis_custom_buttons'] ?>
    </div>
  </div>
</div>
<script type="text/javascript" src="http://s7.addthis.com/js/250/addthis_widget.js#pubid=<?php print $variables['addthis_pubid'] ?>"></script>
<!-- AddThis Button END -->