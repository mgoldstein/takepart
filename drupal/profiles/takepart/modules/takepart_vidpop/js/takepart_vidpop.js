// file: javascript support for takepart_vidpop


(function ($) {
  Drupal.behaviors.scVidpopClick = {
    attach: function (context, settings) {
      $('.vidpop-preview', context).click(function(){
        // these two lines will set autoplay - just need a way to get the embed_id
        //var embed_id = 'media_youtube_quuC9mfV2aY_1';
        //Drupal.settings.media_youtube[embed_id].options.autoplay = 1;
        s.linkTrackVars="events";
        s.linkTrackEvents="event41";
        s.events='event41';
        s.tl(true, 'o', 'Video Popup Click');
      });
    }
  }
})(jQuery);
