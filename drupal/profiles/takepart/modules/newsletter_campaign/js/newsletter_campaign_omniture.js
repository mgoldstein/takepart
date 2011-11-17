(function ($) {
  // handle the click funciton on the take action button.
  Drupal.behaviors.scNewsletterClick = {
    attach: function (context, settings) {
      $('#newsletter-campaign-signup-form .form-submit', context).click(
        function(e) {
          s.linkTrackVars="eVar28,events";
          s.linkTrackEvents="event39";
          s.eVar28='newsletter';
          s.events='event39';
          s.tl(true, 'o', 'Newsletter Sign-Up');
        }
      );
    }
  };

}(jQuery));
