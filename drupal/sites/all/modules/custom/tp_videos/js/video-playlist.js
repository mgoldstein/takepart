(function($, Drupal, window, document, undefined){
  Drupal.behaviors.playlistNavigation = {
    attach: function() {

      /* add on page load stuff here */
      $(document).ready(function(){

        /* Add class 'active' to  navigation and description elements */
        $('.playlist').each(function(index){

          $(this).attr('playlist-id', index );


        });

        /* Navigation */
        $('.video-item').click(function(){
          var playlist = $(this).parents('.playlist');
          var element = playlist.find('.jwplayer').attr('id');
          var index = playlist.attr('playlist-id');
          var item_index = $(this).data('video-number');
          
          var player_id = element;
          if (player_id == undefined) {
            var player_id = $('object', playlist).attr('id');
          }
          
          window['currentVideo_' + index] = $(this).data('video-number');
          playlist.find('.video-description .description-item').removeClass('active');
          playlist.find('ul.video-playlist .video-item').removeClass('active');
          
          jwplayer(player_id).playlistItem(window['currentVideo_' + index]);
          
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

