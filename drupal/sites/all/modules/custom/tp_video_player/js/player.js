(function ($, Drupal, window, document, undefined) {
  var chromeless_timer;

  Drupal.behaviors.tp_video_player = {
    attach: function() {
      $('.tp-video-player').once('initialized', function(index, element) {
        var $el = $(element);
        var element_id = element.id;
        var settings = JSON.parse($el.find('script').text());
//        if (!window.s || !window.s.Media) {
//          delete settings['sitecatalyst'];
//        }
        // Use the flash player in Firefox on Macs.
        var FF = !(window.mozInnerScreenX == null);
        var MAC = (navigator.platform.indexOf('Mac')>=0);
        var win = (navigator.platform.indexOf('Win') >= 0);
        var user_agent = window.navigator.userAgent;
        var old_ie = user_agent.indexOf('MSIE '); //ie10 and lower
        var new_ie = user_agent.indexOf('Trident/'); //ie11

        //force to use flash. this will address issue with ie and youtube
        if ((old_ie > -1) || (new_ie > -1) || (MAC && FF)) {
          settings['primary'] = 'flash';
        }
        
        //we will force it to use html5 as primary
        if (settings['chromeless']) {
          settings['primary'] = 'html5';
          settings['controls'] = false;
        }

        //adjusts the playlist quality on load to handle caching
        settings = window.playlist_quality(settings);

        //moved code from pm-jwplayer over to new player.js
        var regions = settings.allowed_regions[0];
        if (regions.length > 0 && !$('body').hasClass('node-type-video-playlist')) {
          var blockVideo = function() {
            $el.addClass('blocked').removeClass('loading');
          };
          var handleResponse = function(response) {
            if (!response.country || !response.country.iso_code) {
              $el.addClass('blocked').removeClass('loading');
              return false;
            }
            var code = response.country.iso_code.toLowerCase();
            if ($.inArray(code, regions) < 0) {
              $el.addClass('blocked').removeClass('loading');
            }
            else {
              $el.removeClass('loading');
              jwplayer.key = Drupal.settings.tp_video_player.key;
              tp_video_playlist_init(element, settings, index);
            }
          };
          geoip2.country(handleResponse, blockVideo);
        }
        else {
          jwplayer.key = Drupal.settings.tp_video_player.key;

          //init the playlist after processing
          tp_video_playlist_init(element, settings, index);
        }
        
        //bind the chromeless play at the end of the jwplayer init
        $(window).bind('scroll', function() {
          if (chromeless_timer) {
            window.clearTimeout(chromeless_timer);
            chromeless_timer = null;
          }
          
          chromeless_timer = setTimeout(function() {
            tp_chromeless_play();
          }, 100);
          
        });
      });

      //fires the init for bxslider on ready
      $(document).ready(function() {

        window.tp_initslider();

        if(typeof smartresize == 'function'){
          $(window).smartresize(function() {
            window.tp_initslider();
          });
        }
      });
    }
  };

  /**
   *  @function:
   *    function is used to adjust the playlist quality in the front end
   *    to allow higher quality within the playlist
   */
  window.playlist_quality = function(settings) {
    //default variables
    var playlist = settings.playlist;
    var window_width = $(window).width();
    var file_width = '.mp4';

    //by default return settings only if width is less then 480
    if (window_width < 480) {
      return settings;
    }
    //960 and lower
    else if (window_width < 960) {
      file_width = '-960.mp4';
    }
    //anything abover 960
    else {
      file_width = '-1280.mp4';
    }

    //does for each of the playlist items to set quality
    if (typeof playlist != 'string') {
      $(playlist).each(function(i, v) {
        //only does if v.source is set
        if (v.sources != undefined) {
          //replace the correct width requested
          file_url = v.sources[0]['file'];
          file_url = file_url.replace('.mp4', file_width);
          playlist[i].sources[0]['file'] = file_url;
        }
      });
    }

    //assigns it back to the playlist
    settings.playlist = playlist;
    return settings;
  }

  /**
   *  @function:
   *    This function is used to process the settings
   */
  window.tp_video_playlist_init = function(element, settings, index) {
    var playlist = $(element).parent().parent();

    //initialize player only after geoip2 call
    geoip2.country(function(response) {
      //sets window var for location
      window['tp_client_location'] = response.country.iso_code.toLowerCase();

      //only process the settings if allowed region is set
      if (settings.allowed_regions != undefined && typeof settings.playlist !== 'string') {
        var allowed_regions = settings.allowed_regions;

        //goes thro each allowed region on the items
        $(allowed_regions).each(function(index, value) {
          //goes thro each video if not empty then check if the clients location is allowed within the array
          if (value != '' && $.inArray(tp_client_location, value) === -1) {
            //delete and remove the slider item
            delete settings.allowed_regions[index];
            delete settings.playlist[index];
            $('.description-item[data-video-description="' + index + '"]', playlist).remove();
            $('.video-item[data-video-number="' + index + '"]', playlist).remove();
          }
        });

        //resets the key within the settings
        settings.playlist = settings.playlist.filter(function(){return true;});
        settings.allowed_regions = settings.allowed_regions.filter(function(){return true;});

        //reset the data-video-description
        $('.description-item', playlist).each(function(index, value) {
          $(this).attr('data-video-description', index);

          //ensures that the first element is active
          if (index === 0) {
            $(this).addClass('active');
          }
        });

        //reset the data-video-numbers
        $('.video-item', playlist).each(function(index, value) {
          if ($(window).width() < 480) {
            $('.image-wrapper', this).height($(this).height());
            $('.image-wrapper .overlay', this).height($('img', this).height());
          }
          else {
            $('.image-wrapper', this).css('height', '');
            $('.image-wrapper .overlay', this).css('height', '');
          }

          $(this).attr('data-video-number', index);

          //ensures that the first element is active
          if (index === 0) {
            $(this).addClass('active');
          }
        });
      }

      //removes the playlist slider as there are no elements
      if (settings.playlist == '') {
        //removes class
        $('.tp-video-player', playlist).addClass('blocked');
        $('.bxslider', playlist).removeClass('bxslider').addClass('empty');
        $(playlist).addClass('blocked');
        return;
      }
      
      //if it has passed all conditions then render a jwplayer
      jwplayer(element).setup(settings);
      tp_init_jwplayer_callbacks(element, index, settings);
    });
  }

  /**
   *  @function:
   *    This function is used to init the jwplayer callbacks
   */
  function tp_init_jwplayer_callbacks(element, index, settings){

    var element_id = $(element).attr('id');
    var playlist = $('#' + element_id).parent().parent();
    var chromeless = settings['chromeless'];
    
    window['currentVideo_' + index] = 0;
    updateVideo(window['currentVideo_' + index], playlist);
    
    //only override controls if chromeless is set
    if (chromeless) {
      jwplayer(element_id).onPlay(function(event) {
        jwplayer(element_id).setControls(false);
      });
    }
    
    jwplayer(element_id).onComplete(function(event) {
      window['currentVideo_' + index] = window['currentVideo_' + index] + 1;

      $(playlist).find('.video-description .description-item').removeClass('active');
      playlist.find('ul.video-playlist .video-item').removeClass('active');
      updateVideo(window['currentVideo_' + index], playlist);

      /* Move Slider to slide containing the current video */
      var slides;
      if(window['bxslider_' + index + '_view_mode'] == 'large'){
        slides = 4;
      }else{
        slides = 3;
      }
      var newValCurrentSlide = Math.floor(window['currentVideo_' + index]/slides);
      var current_slide = window['bxslider_' + index].getCurrentSlide();
      if( newValCurrentSlide != current_slide){
        window['bxslider_' + index].goToSlide(newValCurrentSlide);
      }
    });

  }
  /**
   *  @function:
   *    This function is used to update the Video
   */
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
   *    function used to play and trigger chromeless tp videos within the view
   *
   *    @todo: update code to only trigger correctly
   */
  window.tp_chromeless_play = function() {
    //variables
    var window_height = $(window).height();
    var window_y_pos = window.pageYOffset;
    var window_viewport = window_y_pos + window_height;
    var window_mid_pos = window_y_pos + (window_height / 2);
    
    var autoplay = $.cookie('chromeless-autoplay');
   
    //only do autoplay if no cookie is set
    if (autoplay == null) { 
      //check each chromless video
      $('.chromeless-video').each(function(key, value) {
        //variables local to scope
        var player_y_pos = $(this).offset();
        var player_mid_height = $(this).height() / 2;
        var player_mid_pos = player_y_pos.top + player_mid_height;  
        var control_id = $(this).data('videoControlId');
        
        if (player_mid_pos > window_mid_pos - 100 && player_mid_pos < window_mid_pos + 100 ) {
          var video_state = jwplayer(control_id).getState();
          
          //ensures we only play video once since play will pause
          if (!$(this).hasClass('playing')) {
            $(this).addClass('playing');
            
            //only want to play if it's not playing
            if (video_state != "PLAYING") {
              jwplayer(control_id).play();
            }
          }
        }
        else {
          //we want to only pause if it has playing
          if ($(this).hasClass('playing')) {
            jwplayer(control_id).pause();
            $(this).removeClass('playing');
          }
        }
      });
    }
  }
  
  //document ready
  $(document).ready(function() {
    $('.chromeless-controls .pause').click(function() {
      var player_id = $(this).data('playerId');
      var video_state = jwplayer(player_id).getState();
      jwplayer(player_id).pause();
      
      if (video_state == 'PLAYING') {
        $(this).parent().parent().addClass('playing');
      }
      else {
        $(this).parent().parent().removeClass('playing');
      }
      return false;
    });
    
    $('.chromeless-controls .stop-autoplay').click(function() {
      $.cookie("chromeless-autoplay", 0);
      $(".stop-autoplay").hide();
      return false;
    });
  });

  /**
   *  @function:
   *    This function is used to init the bxslider for video playlist
   */
  window.tp_initslider = function() {
    var small = 401;
    var large = 701;
    var all_slides = $('.bxslider');

    //does for each slider
    all_slides.each(function(index) {
      var playlist = $(this).parents('.playlist');
      var viewMode;

      //mobile
      if (playlist.width() <= small) {
        viewMode = 'small';
        playlist.addClass(viewMode);

        //destroy on small display
        if (window['bxslider_' + index]) {
          window['bxslider_' + index].destroySlider();
        }
      }
      //tablet
      else if (playlist.width() < large) {
        viewMode = 'medium';
        slides = 3;
      }
      //desktop
      else {
        viewMode = 'large';
        slides = 4;
      }

      //changes class by viewmode
      if (window['bxslider_' + index + '_view_mode'] == undefined) {
        window['bxslider_' + index + '_view_mode'] = viewMode;
      }
      else if (window['bxslider_' + index + '_view_mode'] != viewMode) {
        playlist.removeClass(window['bxslider_' + index + '_view_mode']);
        playlist.addClass(viewMode);
        window['bxslider_' + index + '_view_mode'] = viewMode;
      }

      //return if small
      if (viewMode == 'small') {
        $(this).show();
        return;
      }

      //destroy all slider
      if (window['bxslider_' + index] != undefined) {
        window['bxslider_' + index].destroySlider();
      }

      if(null == window['bxslider_' + index + '_current']){
        window['bxslider_' + index + '_current'] = 0;
      }else{
        window['bxslider_' + index + '_current'] = window['bxslider_' + index].getCurrentSlide();
      }

      //init slider
      $(this).show();
      window['bxslider_' + index] = $(this).bxSlider({
        minSlides: slides,
        maxSlides: slides,
        slideWidth: 200,
        slideMargin: 15,
        infiniteLoop: false,
        hideControlOnEnd: true,
        pager: false,
        nextText: '',
        prevText: '',
        startSlide: window['bxslider_' + index + '_current']
      });

      //adjustment to auto correct location of slider control
      setTimeout(function() {
        var bxslider_wrapper = $(window['bxslider_' + index]).parent().parent();
        var img = $('.video-item[data-video-number="0"] img', bxslider_wrapper).height();
        var height = (img / 2) + 3;

        $('.bx-controls a', bxslider_wrapper).css('top', height);
      }, 500);
    });
  }
})(jQuery, Drupal, this, this.document);
