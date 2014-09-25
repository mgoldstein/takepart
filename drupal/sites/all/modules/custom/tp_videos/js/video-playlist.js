(function($, Drupal, window, document, undefined){

  Drupal.behaviors.playlistNavigation = {
    attach: function() {

      /* add on page load stuff here */
      $(document).ready(function(){



        /* Add class 'active' to  navigation and description elements */
        $('.playlist').each(function(index){

          $(this).attr('playlist-id', index );

          window['currentVideo_' + index] = 0;
          updateVideo(window['currentVideo_' + index], $(this));

          var playlist = $(this);
          var element = playlist.find('.jwplayer').attr('id');

          jwplayer(element).onComplete(function(event) {

            window.videoTransition; //hack for jwplayer firing twice onPlay and onComplete
            if(null == window.videoTransition){
              window['currentVideo_' + index] = window['currentVideo_' + index] + 1;
              var file = Drupal.settings.tp_video_player.settings['tp-video-player'].playlist[0].sources[window['currentVideo_' + index]].file;
              jwplayer(element).load([{file: file}]);
              jwplayer(element).play();

              playlist.find('.video-description .description-item').removeClass('active');
              playlist.find('ul.video-playlist .video-item').removeClass('active');
              updateVideo(window['currentVideo_' + index], playlist);
              window.videoTransition = 'not null';
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

        });

        /* Navigation */
        $('.video-item').click(function(){
          var playlist = $(this).parents('.playlist');
          var element = playlist.find('.jwplayer').attr('id');
          var index = playlist.attr('playlist-id');
          window['currentVideo_' + index] = $(this).data('video-number');
          playlist.find('.video-description .description-item').removeClass('active');
          playlist.find('ul.video-playlist .video-item').removeClass('active');
          var file = Drupal.settings.tp_video_player.settings['tp-video-player'].playlist[index].sources[window['currentVideo_' + index]].file;

          jwplayer(element).load([{file: file}]);
          jwplayer(element).play();

          updateVideo(window['currentVideo_' + index], playlist);

        });
      });
    }
  };

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


})(jQuery, Drupal, this, this.document)

