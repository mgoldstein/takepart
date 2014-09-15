(function($, Drupal, window, document, undefined){

  Drupal.behaviors.playlistNavigation = {
    attach: function() {

      /* add on page load stuff here */
      $(document).ready(function(){

        /* Add class 'active' to  navigation and description elements */
        $('.playlist').each(function(){
          var current_video = 0;
          updateVideo(current_video, $(this));
        });

        /* Navigation */
        $('.video-item').click(function(){
          var playlist = $(this).parents('.playlist');
          var current_video = $(this).data('video-number');
          playlist.find('.video-description .description-item').removeClass('active');
          playlist.find('ul.video-playlist .video-item').removeClass('active');
          updateVideo(current_video, playlist);

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
    else if(playlist.hasClass('basic')){
      $('ul.video-playlist .video-item[data-video-number="' + current_video + '"]').addClass('active');
    }
  }


})(jQuery, Drupal, this, this.document)

