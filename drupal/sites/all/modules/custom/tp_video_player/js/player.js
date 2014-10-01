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

        var playlist = $(this);
        jwplayer(element_id).onComplete(function(event) {

          window.videoTransition; //hack for jwplayer firing twice onPlay and onComplete
          if(null == window.videoTransition){
            window['currentVideo_' + index] = window['currentVideo_' + index] + 1;
            jwplayer(element).playlistItem(window['currentVideo_' + index]);
            playlist.find('.video-description .description-item').removeClass('active');
            playlist.find('ul.video-playlist .video-item').removeClass('active');
            updateVideo(window['currentVideo_' + index], playlist);
            window.videoTransition = 'not null';
          }

          /* Move slider over if it needs to be */
          var slides;
          if(window['slider_' + index + '_view_mode'] == 'large'){
            slides = 4;
          }else{
            slides = 3;
          }
          var ratio = (window['currentVideo_' + index])/slides;

          if(ratio % 1 === 0){
            window['slider_' + index].goToNextSlide();
          }
        });

        jwplayer(element).onPlay(function(event){
          delete window.videoTransition;

          /* Analytics */
          var autoplay = jwplayer(element).config.autostart;
          if(autoplay == true){
            autoplay = 'Auto-play';
          }else{
            autoplay = 'Manual';
          }
          takepart.analytics.track('playlist-play', {
            playerName: jwplayer(element).config.primary,
            listName: jwplayer(element).config.title,
            playConfig: autoplay
          });
        });

        function updateVideo(current_video, playlist){
          var playlistType = playlist.data('playlist-type');
          if(playlistType == 'detailed'){
            playlist.find('.video-description .description-item[data-video-description="' + current_video + '"]').addClass('active');
            playlist.find('ul.video-playlist .video-item[data-video-number="' + current_video + '"]').addClass('active');
          }
          else if(playlistType == 'basic'){
            playlist.find('ul.video-playlist .video-item[data-video-number="' + current_video + '"]').addClass('active');
          }
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
          var allowed = Drupal.settings.tp_video_player.settings[element_id]['allowed_regions'][0];
    
          //calls the country to get the code
          geoip2.country(function(response) {
            window['tp_client_location'] = response.country.iso_code;
            tp_video_blocked(element_id, 0);
            
            //unsets first ad if blocked
            if ($('#' + element_id).hasClass('blocked')) {
              delete settings.playlist[0]['adschedule'];
            }
          });

          jwplayer(element).setup(settings);
          
          //this is used for the playlist to hide the items
          jwplayer(element_id).onReady(function() {
            var playlist_index = jwplayer(element_id).getPlaylistIndex();
            tp_video_blocked(element_id, playlist_index);
          });
          
          //stops the player if it has blocked class
          jwplayer(element_id).onPlay(function() {
            if ($('#' + element_id).hasClass('blocked')) {
              jwplayer(element_id).stop();
            }
          });
        }
      });
    }
  };
})(jQuery, Drupal, this, this.document);
