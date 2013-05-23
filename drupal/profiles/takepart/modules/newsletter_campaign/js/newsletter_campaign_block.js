(function ($) {
  $(document).ready(function() {
    // Newsletter signup event
    $(".takepart-newsletter-wrapper > .takepart-newsletter-message").bind(
      'newsletter_signup', function(e, title) {
        s.linkTrackVars = "eVar23,eVar30,events";
        s.linkTrackEvents = "event39";
        s.eVar23 = title;
        s.eVar30 = s.pageName;
        s.events = 'event39';
        s.tl(true, 'o', 'Newsletter Signup');
      }
    );
    $("body").bind(
      'newsletter_signup', function(e, title) {
        s.linkTrackVars = "eVar23,eVar30,events";
        s.linkTrackEvents = "event39";
        s.eVar23 = title;
        s.eVar30 = s.pageName;
        s.events = 'event39';
        s.tl(true, 'o', 'Newsletter Signup');
      }
    );
    $(".takepart-newsletter-wrapper").each(function() {
      // setup the email input field to have a placeholder message
      $(".form-item-email > input", this).focus(function() {
        // when the email field receives the focus remove the placeholder
        // if it is present
        if ($(this).val() == 'Your Email') {
          $(this).val('').removeClass('takepart-newsletter-empty');
        }
      }).blur(function() {
        // when the email field loses the focus restore the placeholder
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
