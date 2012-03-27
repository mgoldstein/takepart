(function ($) {
  // handle the click funciton on the take action button.
  Drupal.behaviors.scNewsletterClick = {
    attach: function (context, settings) {
      $('#newsletter-campaign-signup-form .form-submit', context).click(
        function(e) {
          
          var form = $('#newsletter-campaign-signup-form');
          var title = form.find('input[name="newsletter_title"]').attr('value');
          
          s.linkTrackVars="eVar23,events";
          s.linkTrackEvents="event39";
          s.eVar23=title;
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
