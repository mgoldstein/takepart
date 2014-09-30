(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.tp_video_player = {
    attach: function() {
      $('.tp-video-player').once('initialized', function(index, element) {
        //make calls to maxmind and sets variables
        var tp_country_cookie = getCookie('tp_countryISOCode');
        
        //set window variable for blocking
        if (window['tp_client_location'] == undefined) {
          if (tp_country_cookie != '') {
            window['tp_client_location'] = tp_country_cookie;
          }
          else {
            geoip2.country(function(response) {
              window['tp_client_location'] = response.country.iso_code;
            });
          }
        }
        
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
        
        //moved code from pm-jwplayer over to new player.js
        var regions = Drupal.settings.tp_video_player.settings[element_id].allowed_regions[0];
        if (regions.length > 0 && !$('body').hasClass('node-type-video-playlist')) {
          var blockVideo = function() {
            $(element).addClass('blocked').removeClass('loading');
          };
          var handleResponse = function(response) {
            if (!response.country || !response.country.iso_code) {
              $(element).addClass('blocked').removeClass('loading');
              return false;
            }
            var code = response.country.iso_code.toLowerCase();
            if ($.inArray(code, regions) < 0) {
              $(element).addClass('blocked').removeClass('loading');
            }
            else {
              $(element).removeClass('loading');
              jwplayer.key = Drupal.settings.tp_video_player.key;
              jwplayer(element).setup(settings);
            }
          };
          geoip2.country(handleResponse, blockVideo);
        }
        else {
          jwplayer.key = Drupal.settings.tp_video_player.key;
          jwplayer(element).setup(settings);
          
          //this is used for the playlist to hide the items
          jwplayer(element_id).onReady(function() {
            var playlist_index = jwplayer(element_id).getPlaylistIndex();
            var allowed_regions = Drupal.settings.tp_video_player.settings[element_id]['allowed_regions'][playlist_index];
            tp_video_blocked(allowed_regions, element_id);
          });
        }
      });
    }
  };
})(jQuery, Drupal, this, this.document);
