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

            //stops video 
            if ($('#' + element_id).hasClass('blocked')) {
              jwplayer(element_id).stop();
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
          var item_index = $(this).data('video-number');
          
          var player_id = element;
          if (player_id == undefined) {
            var player_id = $('object', playlist).attr('id');
          }
          
          window['currentVideo_' + index] = $(this).data('video-number');
          playlist.find('.video-description .description-item').removeClass('active');
          playlist.find('ul.video-playlist .video-item').removeClass('active');
          
          tp_video_blocked(player_id, window['currentVideo_' + index], index);
          
          //stops video 
          if (!$('#' + player_id).hasClass('blocked')) {
            jwplayer(player_id).playlistItem(window['currentVideo_' + index]);
          }
          else {
            jwplayer(player_id).stop();
          }
          
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

  /**
   *  @function:
   *    This window function is used to get cookies value
   */
  window.getCookie = function(cname) {
    var name = cname + "=";
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) return c.substring(name.length,c.length);
    }
    return "";
  }
  
  /**
   *  @function:
   *    This function is used to update the video player to block videos
   */
  window.tp_video_blocked = function(id, index_item, player_id) {
    //if player id is empty then use window
    if (player_id != '') {
      index_item = window['currentVideo_0'];
    }
    
    //allowed regions
    var allowed = Drupal.settings.tp_video_player.settings[id]['allowed_regions'][index_item];
    
    //overrides for flash to make the id the wrapper for blocking
    if ($('#' + id).is('object')) {
      id = id + '_wrapper';
    }
    
    //conditional check to see if the video is valid to play
    if (allowed == '') {
      //built in case of other
      $('#' + id).removeClass('blocked');
      return;
    }
    else {
      //default variables
      var allowed_regions = allowed;
      var video_allow = false;
      
      //does for each allowed region
      $(allowed_regions).each(function(index, value) {
        //compares to see if the value exist in the allowed region
        if (tp_client_location.toUpperCase() == value.toUpperCase()) {
          video_allow = true;
        }
      });
      
      //deny video
      if (video_allow == false) {
        $('#' + id).addClass('blocked');
      }
      else {
        $('#' + id).removeClass('blocked');
      }
    }
  }

})(jQuery, Drupal, this, this.document)

