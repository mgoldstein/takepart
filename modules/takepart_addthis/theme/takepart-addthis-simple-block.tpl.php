<!-- AddThis Button BEGIN -->
<h2>Share</h2>
<div class="takepart_addthis_simple">
  <div class="addthis_toolbox addthis_default_style">
      <a class="addthis_button_facebook"></a>
      <a class="addthis_button_twitter" tw:via="<?php print $variables['takepart_addthis_tweet_via']; ?>" ></a>
  </div>
  <span id="addthis_simple_sharethis">Share</span>
</div>
<?php
  drupal_add_js('var addthis_config = {"data_track_clickback":true};', 'inline');
  drupal_add_js('http://s7.addthis.com/js/250/addthis_widget.js#pubid=' . $variables['addthis_pubid'], 'external');
?>
<!-- AddThis Button END -->