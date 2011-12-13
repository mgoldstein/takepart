<?php
$node = menu_get_object(); 
?>
<!-- AddThis Button BEGIN -->
<div class="takepart_addthis_footer">
  <div class="addthis_toolbox addthis_default_style">
      <a class="addthis_button_facebook"></a>
      <a class="addthis_button_twitter" tw:via="<?php print $variables['takepart_addthis_tweet_via']; ?>" tw:text="<?php print $node->title; ?>"></a>
      <a class="addthis_button_google_plusone"></a>
      <a class="addthis_button_linkedin"></a>
      <a class="addthis_button_stumbleupon"></a>
      <a class="addthis_button_digg"></a>
      <a class="addthis_button_email"></a>
  </div>
  <span id="addthis_footer_sharethis">Share this</span>
</div>
<?php
  //Add these scripts for the block
  //<script type="text/javascript">var addthis_config = {"data_track_clickback":true};</script>
  //<script type="text/javascript" src="http://s7.addthis.com/js/250/addthis_widget.js#pubid=ra-4e090234793de9ba"></script>
  drupal_add_js('var addthis_config = {"data_track_clickback":true};', 'inline');
  drupal_add_js('http://s7.addthis.com/js/250/addthis_widget.js#pubid=' . $variables['addthis_pubid'], 'external');
?>
<!-- AddThis Button END -->
