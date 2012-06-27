// file: javascript support for takepart_vidpop


(function ($) {
  Drupal.behaviors.scVidpopClick = {
    attach: function (context, settings) {
      $('.vidpop-preview', context).click(function(){
        s.linkTrackVars="events";
        s.linkTrackEvents="event41";
        s.events='event41';
        s.tl(true, 'o', 'Video Popup Click');
      });
    }
  }
})(jQuery);
