<?php
$node = menu_get_object(); 
?>
<!-- AddThis Button BEGIN -->
<div class="takepart_addthis_leftpanel clearfix">
  <div class="addthis_toolbox addthis_default_style">
    <a class="addthis_button_facebook_like" fb:like:layout="button_count" fb:like:action="<?php print $variables['takepart_addthis_facebook_like_text'];?>" fb:like:href="<?php echo url(current_path(), array('absolute' => TRUE)); ?>"></a>
    <a class="addthis_button_tweet" tw:via="<?php print $variables['takepart_addthis_tweet_via']; ?>" tw:text="<?php print $node->title; ?>" tw:url="<?php echo ((empty($_SERVER["HTTPS"])) ? 'http://' : 'https://') . $_SERVER["SERVER_NAME"].$_SERVER["REQUEST_URI"]; ?>" tw:counturl="<?php echo ((empty($_SERVER["HTTPS"])) ? 'http://' : 'https://') . $_SERVER["SERVER_NAME"].$_SERVER["REQUEST_URI"]; ?>"></a>
    <!-- <a class="addthis_button_linkedin_counter"></a> --> 
    <a class="addthis_button_linkedin"></a>
    <a class="addthis_button_google_plusone" g:plusone:count="false"></a>
    <a class="addthis_button_pinterest_pinit" pi:pinit:url="<?php echo ((empty($_SERVER["HTTPS"])) ? 'http://' : 'https://') . $_SERVER["SERVER_NAME"].$_SERVER["REQUEST_URI"]; ?>" pi:pinit:layout="horizontal"></a> 
  </div>
  <div class="addthis_toolbox">
    <div class="custom_images">
      <?php print $variables['addthis_custom_buttons'] ?>
    </div>
  </div>
</div>
<script type="text/javascript" src="//s7.addthis.com/js/250/addthis_widget.js#pubid=<?php print $variables['addthis_pubid'] ?>"></script>
<!-- AddThis Button END -->