(function ($) {
  $(document).ready(function() {
    // Newsletter signup event
    $(".takepart-newsletter-wrapper > .takepart-newsletter-message").bind(
      'newsletter_signup', function(e, title) {
        takepart.analytics.track('newsletter_signup', {
          name: title,
          source: 'Sidebar Sign-up Block'
        });
      }
    );
    $("body").bind(
      'newsletter_social_signup', function(e, title) {
        takepart.analytics.track('newsletter_signup', {
          name: title,
          source: 'Sidebar Sign-up Block w/Social Shares'
        });
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
