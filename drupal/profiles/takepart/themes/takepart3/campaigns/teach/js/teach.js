(function ($, Drupal, window, document, undefined) {
  $(document).ready(function() {
    console.log('Setup');
    Drupal.behaviors.newsletterSocialSignupSubmitted = {
      attach: function (context) {
        console.log(context);
        if (context.is('.newsletter-signup.thank-you-message')){
           console.log('Fire');
           var name = context.attr('data-newsletter-name');
           takepart.analytics.track('newsletter_signup', {name: name});
        }
      }
    }
  });
})(jQuery, Drupal, this, this.document);
