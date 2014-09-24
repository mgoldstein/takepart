(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.tp_video_player = {
    attach: function() {
      $('.tp-video-player').once('initialized', function(index, element) {
        var element_id = $(element).attr('id');
        var settings = Drupal.settings.tp_video_player.settings[element_id];
        if (!window.s || !window.s.Media) {
          delete settings['sitecatalyst'];
        }
        // Use the flash player in Firefox on Macs.
        var FF = !(window.mozInnerScreenX == null);
        var MAC = (navigator.platform.indexOf('Mac')>=0);
        if (MAC && FF) {
          settings['primary'] = 'flash';
        }
        jwplayer.key = Drupal.settings.tp_video_player.key;
        jwplayer(element).setup(settings);
      });
    }
  };
})(jQuery, Drupal, this, this.document);
