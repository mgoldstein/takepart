<div style="clear: both; margin-bottom: 20px;">
  <div class="tp-pet-thank-you-heading">Thank You For Signing!</div>
  <p>Your signature has been added to the petition, and our movement is one person stronger!</p>
  <p>Every signature matters - share yours with people you know who also care about progress. Ask your friends, family, coworkers, and neighbors to join our campaign.</p>
  <p>You can share the petition on Facebook or Twitter, or send an email using the form below.</p>
  <div class="addthis_toolbox addthis_default_style addthis_32x32_style">
  <a class="addthis_button_facebook">
    <img src="/profiles/takepart/modules/takepart_addthis/images/fb_share.png" alt="Share on Facebook" />
  </a>
  <a class="addthis_button_twitter" tw:via="TakePart">
    <img src="/profiles/takepart/modules/takepart_addthis/images/twitter_share.png" alt="Share on Twitter" />
  </a>
  <a class="addthis_button_email">
    <img src="/profiles/takepart/modules/takepart_addthis/images/share_email.png" alt="Share on Twitter" />
  </a>
  </div>
</div>
<script type="text/javascript">
  var addthis_config = {
    ui_email_note: 'SHARE THE BILL OF RIGHTS\nThe more names we have, the more powerful our message. Share the Water Bill of Rights with friends and family!',
    ui_email_from: "<?php print $_COOKIE['petition_signed_as'] ?>",
  };
  var addthis_share = {
    templates: {
      twitter: "Water is a right, not a privilege! Sign the Water Bill of Rights today. {{url}} #knowyourwater via @TakePart"
    },
  };
  jQuery(document).ready(function() {
    var petition_signed_as = "<?php print $_COOKIE['petition_signed_as'] ?>";
    if (petition_signed_as.length > 0) {
      jQuery("input#edit-email").val(petition_signed_as).removeClass('takepart-newsletter-empty');   
    } 
  });
</script>
