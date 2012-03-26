(function ($) {
  // handle the click funciton on the take action button.
  Drupal.behaviors.scNewsletterClick = {
    attach: function (context, settings) {
      $('#newsletter-campaign-signup-form .form-submit', context).click(
        function(e) {
          
          s.linkTrackVars="eVar23,events";
          s.linkTrackEvents="event39";
          s.eVar23='TakePart Newsletter';
          s.events='event39';
          s.tl(true, 'o', 'Newsletter Signup');

          s.linkTrackVars="eVar28,events";
          s.linkTrackEvents="event19";
          s.eVar28='Newsletter Signup';
          s.events='event19';
          s.tl(true, 'o', 'Action Click');
        }
      );
    }
  };

}(jQuery));
