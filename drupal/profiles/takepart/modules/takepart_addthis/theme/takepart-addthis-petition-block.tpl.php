<h2 class="tp_block_addthis_petition_header">Spread the word!</h2>
<p>Every signature counts! Share this petition with friends and family to have an even greater impact!</p>
<div class="tp-pet-share-button-bar">
  <div class="addthis_toolbox addthis_default_style addthis_32x32_style">
    <span class="tp-pet-share-label">Share Petition</span>
    <a class="addthis_button_facebook"><img src="/profiles/takepart/modules/takepart_addthis/images/fb_share_icon.png" alt="Share on Facebook" /></a>
    <a class="addthis_button_twitter" tw:via="TakePart"><img src="/profiles/takepart/modules/takepart_addthis/images/twitter_share_icon.png" alt="Share on Twitter" /></a>
    <a class="addthis_button_email"><img src="/profiles/takepart/modules/takepart_addthis/images/email_share_icon.png" alt="Share by E-mail" /></a>
  </div>
</div>
<script type="text/javascript">
  var sharing_email = '<?php print $_COOKIE['petition_signed_as'] ?>';
  if (Drupal.settings.sharing) {
    if ('email' in Drupal.settings.sharing) {
      sharing_email = Drupal.settings.sharing['email'];
    }
  }
  var addthis_config = {
    ui_email_note: 'SHARE THE BILL OF RIGHTS\nThe more names we have, the more powerful our message. Share the Water Bill of Rights with friends and family!',
    ui_email_from: sharing_email
  };
  var addthis_share = {
    templates: {
      twitter: "Water is a right, not a privilege! Sign the Water Bill of Rights today. {{url}} #knowyourwater via @TakePart"
    }
  };
</script>
