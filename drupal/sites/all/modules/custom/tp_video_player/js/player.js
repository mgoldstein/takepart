(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.tp_video_player = {
    attach: function() {
      $('.tp-video-player').once('initialized', function(index, element) {
        var element_id = $(element).attr('id');
        var settings = Drupal.settings.tp_video_player.settings[element_id];
        if (!window.s || !window.s.Media) {
          delete settings['sitecatalyst'];
        }
        jwplayer.key = Drupal.settings.tp_video_player.key;
        jwplayer(element).setup(settings);
      });
    }
  };
})(jQuery, Drupal, this, this.document);
