(function ($, Drupal, window, document, undefined) {
  $(document).ready(function() {
    Drupal.behaviors.newsletterSocialSignupSubmitted = {
      attach: function (context) {
        if (context.is('.newsletter-signup.thank-you-message')){
           var name = context.attr('data-newsletter-name');
           takepart.analytics.track('newsletter_signup', {name: name});
        }
      }
    }
  });
})(jQuery, Drupal, this, this.document);
