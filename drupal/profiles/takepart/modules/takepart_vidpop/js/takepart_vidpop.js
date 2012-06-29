// file: javascript support for takepart_vidpop


(function ($) {
  Drupal.behaviors.scVidpopClick = {
    attach: function (context, settings) {
      for( x in Drupal.settings.media_youtube) {
        //alert(x);
        //Drupal.settings.media_youtube[x]['options']['autoplay'] = 1;
      }

      var config = { data_track_clickback: true };
      var share = { templates: { twitter: "{{title}} {{url}} bob @TakePart" } };
      $('.social-links').find('.addthis_toolbox').once('addthis-init', function() {
        window.addthis.toolbox(this, config, share);
      });

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
