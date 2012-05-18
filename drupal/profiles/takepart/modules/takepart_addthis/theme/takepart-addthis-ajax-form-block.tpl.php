<div style="clear: both; margin-bottom: 20px;">
  <div class="tp-pet-thank-you-heading">Thank You For Signing!</div>
  <?php print $thank_you_message; ?>
  <div class="tp-pet-share-button-bar">
  <div class="addthis_toolbox addthis_default_style addthis_32x32_style">
  <a class="addthis_button_facebook"><img src="/profiles/takepart/modules/takepart_addthis/images/fb_share.png" alt="Share on Facebook" /></a>
  <a class="addthis_button_twitter" tw:via="TakePart"><img src="/profiles/takepart/modules/takepart_addthis/images/twitter_share.png" alt="Share on Twitter" /></a>
  <a class="addthis_button_email"><img src="/profiles/takepart/modules/takepart_addthis/images/email_share.png" alt="Share by E-mail" /></a>
  </div>
  </div>
</div>
<script type="text/javascript">
  var email_from = "";
  var email_note = "";
  var twitter_template = "";
  if (Drupal.settings.sharing) {
    if ('email' in Drupal.settings.sharing) {
      email_from = Drupal.settings.sharing['email'];
    }
    if ('email_msg' in Drupal.settings.sharing) {
      email_note = Drupal.settings.sharing['email_msg'];
    }
    if ('twitter_msg' in Drupal.settings.sharing) {
      twitter_template = Drupal.settings.sharing['twitter_msg'];
    }
  }
  var addthis_config = {
    ui_email_from: email_from,
    ui_email_note: email_note
  };
  var addthis_share = {
    templates: {
      twitter: twitter_template
    }
  };
  if (Drupal.settings.sharing) {
    if ('share_url' in Drupal.settings.sharing) {
      addthis_share['url'] = Drupal.settings.sharing['share_url'];
    }
  }
  jQuery(document).ready(function() {
    if (email_from.length > 0) {
      jQuery("input#edit-email").val(email_from).removeClass('takepart-newsletter-empty');
    }
  });
</script>
