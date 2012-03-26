<div id="mg-contest-addthis-block">
  <div class="mg-contest-share-button-bar">
  <div class="mg-contest-addthis-label">Share This</div>
  <div class="addthis_toolbox addthis_default_style">
  <a class="addthis_button_facebook mg-contest-addthis-button">
    <img src="/profiles/takepart/modules/takepart_contests/includes/marigold-hotel-contest/images/share_facebook.png" alt="Share on Facebook" />
  </a>
  <a class="addthis_button_twitter mg-contest-addthis-button" tw:via="TakePart">
    <img src="/profiles/takepart/modules/takepart_contests/includes/marigold-hotel-contest/images/share_twitter.png" alt="Share on Twitter" />
  </a>
  <a class="addthis_button_email mg-contest-addthis-button">
    <img src="/profiles/takepart/modules/takepart_contests/includes/marigold-hotel-contest/images/share_email.png" alt="Share through Email" />
  </a>
  </div>
  </div>
</div>
<script type="text/javascript">
  var addthis_config = {
    ui_email_note: "",
    ui_email_from: "<?php print $_COOKIE['contest_entered_as'] ?>"
  };
  var addthis_share = {
    templates: {
      twitter: ""
    }
  };
  jQuery(document).ready(function() {
    var contest_entered_as = "<?php print $_COOKIE['contest_entered_as'] ?>";
    if (contest_entered_as.length > 0) {
      jQuery("input#edit-email").val(contest_entered_as).removeClass('takepart-newsletter-empty');   
    } 
  });
</script>
