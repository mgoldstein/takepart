// file: javascript support for takepart_vidpop


(function ($) {
  Drupal.behaviors.vidpopLoad = {
    attach: function (context, settings) {
      $(".vidpop-preview-overlay-headline").html(Drupal.settings.vidpop.promo_headline);
    }
  }

  Drupal.behaviors.scVidpopClick = {
    attach: function (context, settings) {
      for( x in Drupal.settings.media_youtube) {
        Drupal.settings.media_youtube[x]['options']['autoplay'] = 1;
      }

      // add click tracker for banner ad
      $('.vidpop-preview', context).click(function(){
        s.linkTrackVars="events";
        s.linkTrackEvents="event41";
        s.events='event41';
        s.tl(true, 'o', 'Video Popup Click');
      });
    }
  }
})(jQuery);
