(function ($) {

  $(document).ready(function() {
    // Newsletter signup event
    $("div.takepart-newsletter-wrapper > div.takepart-newsletter-message").bind(
      'newsletter_signup', function(e, title) {
        s.linkTrackVars = "eVar23,events";
        s.linkTrackEvents = "event39";
        s.eVar23 = title;
        s.events = 'event39';
        s.tl(true, 'o', 'Newsletter Signup');

        s.linkTrackVars = "eVar28,events";
        s.linkTrackEvents = "event19";
        s.eVar28 = 'Newsletter Signup';
        s.events = 'event19';
        s.tl(true, 'o', 'Action Click');
      }
    );
    $("div.takepart-newsletter-wrapper").each(function() {
      // setup the email input field to have a placeholder message
      $(this).find("div.form-item-email > input").focus(function() {
        // when the email field receives the focus remove the placeholder
        // message if it is present
        if ($(this).val() == 'Your Email') {
          $(this).val('').removeClass('takepart-newsletter-empty');
        }
      }).blur(function() {
        // when the email field loses the focus restore the placeholder message
        // if the field is empty
        if ($(this).val() == '') {
          $(this).val('Your Email').addClass('takepart-newsletter-empty');
        }
      }).each(function() {
        if ($(this).val() == "Your Email") {
          $(this).addClass("takepart-newsletter-empty");
        }
      });
    });
  });

})(jQuery);
