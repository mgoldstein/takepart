(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.newsletterSocialSignupSubmitted = {
    attach: function (context) {
      if ($(context).is('.newsletter-signup.thank-you-message')){
         var name = context.attr('data-newsletter-name');
         takepart.analytics.track('newsletter_signup', {name: name});
      }
    }
  };
  Drupal.behaviors.teachAllianceLogoResize = {
    attach: function () {
      if ($('body').is('.page-wordlet-teach-alliances')) {
        var $alliance = $('.alliances').find('.alliance'),
            resizeAlliances = function() {
              $alliance.each(function(i, el) {
                var $el = $(el),
                    height = Math.round(($el.width() * 3) / 4);
                $el.height(height).css('line-height', (height - 20) + 'px');
              });
            };
        resizeAlliances();
        $(window).resize(function() {
          resizeAlliances();
        });
      }
    }
  }
})(jQuery, Drupal, this, this.document);
