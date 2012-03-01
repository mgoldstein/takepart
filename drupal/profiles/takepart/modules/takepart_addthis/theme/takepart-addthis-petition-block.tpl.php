<?php
$node = menu_get_object(); 
?>
<h2 class="tp_block_addthis_petition_header">Share This Petition</h2>
<p>Every signature counts! Share this petition with friends and family to have an even greater impact!</p>
<!-- AddThis Button BEGIN -->
<div class="tp-pet-share-button-bar">
<div class="addthis_toolbox addthis_default_style addthis_32x32_style">
<a class="addthis_button_facebook"></a>
<a class="addthis_button_twitter" tw:via="TakePart"></a>
<a class="addthis_button_email"></a>
</div>
</div>
<script type="text/javascript">
  var addthis_config = {
    ui_email_note: 'SHARE THE BILL OF RIGHTS\nThe more names we have, the more powerful our message. Share the Water Bill of Rights with friends and family!',
    ui_email_from: "<?php print $_COOKIE['petition_signed_as'] ?>"
  };
var addthis_share = {
   templates: {
      twitter: "Water is a right, not a privilege! Sign the Water Bill of Rights today. {{url}} #knowyourwater via @TakePart"
   }
};
</script></script>
<script type="text/javascript" src="http://s7.addthis.com/js/250/addthis_widget.js#pubid=ra-4e48103302adc2d8"></script>
<!-- AddThis Button END -->
