<?php
$node = menu_get_object(); 
?>
<!-- AddThis Button BEGIN -->
<div class="takepart_addthis_simple">
  <span id="addthis_simple_sharethis">Share:</span>
  <div class="addthis_toolbox addthis_default_style">
      <a class="addthis_button_facebook"  addthis:url="<?php echo url(current_path(), array('absolute' => TRUE)); ?>"></a>
      <a class="addthis_button_twitter" tw:via="<?php print $variables['takepart_addthis_tweet_via']; ?>" tw:text="<?php print $node->title; ?>"  tw:url="<?php echo ((empty($_SERVER["HTTPS"])) ? 'http://' : 'https://') . $_SERVER["SERVER_NAME"].$_SERVER["REQUEST_URI"]; ?>" tw:counturl="<?php echo ((empty($_SERVER["HTTPS"])) ? 'http://' : 'https://') . $_SERVER["SERVER_NAME"].$_SERVER["REQUEST_URI"]; ?>"></a>
      <a class="addthis_button_linkedin_counter"></a>
  </div>
</div>
<?php
  drupal_add_js('var addthis_config = {"data_track_clickback":true};', 'inline');
  drupal_add_js('//s7.addthis.com/js/250/addthis_widget.js#pubid=' . $variables['addthis_pubid'], 'external');
?>
<!-- AddThis Button END -->