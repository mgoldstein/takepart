<?php
$node = menu_get_object(); 
?>
<!-- AddThis Button BEGIN -->
<div class="takepart_addthis_footer">
  <script class="takepart_addthis_footer_template" type="text/x-javascript-template">
    <div class="addthis_toolbox addthis_default_style">
        <a class="addthis_button_facebook" addthis:url="<?php echo url(current_path(), array('absolute' => TRUE)); ?>"></a>
        <a class="addthis_button_twitter" tw:via="<?php print $variables['takepart_addthis_tweet_via']; ?>" tw:text="<?php print $node->title; ?>" tw:url="<?php echo ((empty($_SERVER["HTTPS"])) ? 'http://' : 'https://') . $_SERVER["SERVER_NAME"].$_SERVER["REQUEST_URI"]; ?>" tw:counturl="<?php echo ((empty($_SERVER["HTTPS"])) ? 'http://' : 'https://') . $_SERVER["SERVER_NAME"].$_SERVER["REQUEST_URI"]; ?>"></a>
        <a class="addthis_button_google_plusone"></a>
        <a class="addthis_button_linkedin"></a>
        <a class="addthis_button_pinterest" pi:pinit:url="<?php echo ((empty($_SERVER["HTTPS"])) ? 'http://' : 'https://') . $_SERVER["SERVER_NAME"].$_SERVER["REQUEST_URI"]; ?>"></a> 
        <a class="addthis_button_stumbleupon"></a>
        <a class="addthis_button_digg"></a>
        <a class="addthis_button_email"></a>
    </div>
  </script>
  <span id="addthis_footer_sharethis">Share this</span>
</div>
<?php
  //Add these scripts for the block
  drupal_add_js('var addthis_config = {"data_track_clickback":true};', 'inline');
  drupal_add_js('//s7.addthis.com/js/250/addthis_widget.js#pubid=' . $variables['addthis_pubid'], 'external');
?>
<!-- AddThis Button END -->
