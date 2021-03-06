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
        var FF = !(window.mozInnerScreenX == null);
        var MAC = (navigator.platform.indexOf('Mac')>=0);
        var win = (navigator.platform.indexOf('Win') >= 0);
        var user_agent = window.navigator.userAgent;
        var old_ie = user_agent.indexOf('MSIE '); //ie10 and lower
        var new_ie = user_agent.indexOf('Trident/'); //ie11

        //Force mp4 on FF (Mac && PC)
        if (FF) {
          window.forceMp4 = true;
        }
        //force to use flash on IE 11 and older versions
        if ((old_ie > -1) || (new_ie > -1)) {
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
          }, 75);

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
    var playlist = $(element).parent().parent().parent();

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
            $('.image-wrapper', this).css('height', '');
            $('.image-wrapper .overlay', this).css('height', '');

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

      //Add a new custom share functionality to replace email
      if (!settings['chromeless']) {
        var player_sharing = settings.sharing;
        var share_link = settings.sharing.link;
        var vid_title = settings.title;
        vid_title = $('<div/>').html(vid_title).text();
        var email_icon = '//' + document.location.host + '/sites/all/themes/base/images/jwp_share_email.png'

        player_sharing.sites = [ 'facebook', 'twitter', {
            icon: email_icon,
            src: function() {
              window.location.href = 'mailto:?subject=' + vid_title + '&body=' + share_link;
            },
            label: 'email'
        }];
      }

      //Update the playlist to include mp4 extension for FF & IE.
      //This addresses the issue with FF falling back to Flash on HLS.
      var mp4_playlist = settings.playlist;
      if (window.forceMp4 && typeof mp4_playlist == 'string' && mp4_playlist.includes('xml')) {
        //Load the xml file
        $.ajax({
          url: mp4_playlist,
          success: function(data) {
            var item = $(data).find('item');
            //Find the source attr with mp4 extension
            item.children().each(function(index, el) {
              var fileAttr = $(el).attr('file');
              if (el.nodeName === 'jwplayer:image') {
                settings.image = $(el).text();
              }
              if (fileAttr && fileAttr.indexOf('mp4') > -1) {
                delete settings.playlist;
                settings.file = fileAttr;
              }
            });
            jwplayer(element).setup(settings);
            tp_init_jwplayer_callbacks(element, index, settings);
          }
        });
      }
      else {
        //if it has passed all conditions then render a jwplayer
        jwplayer(element).setup(settings);
        tp_init_jwplayer_callbacks(element, index, settings);
      }


    });
  }

  /**
   *  @function:
   *    This function is used to init the jwplayer callbacks
   */
  function tp_init_jwplayer_callbacks(element, index, settings){
    var element_id = $(element).attr('id');
    var playlist = $('#' + element_id).parent().parent().parent();
    var chromeless = settings['chromeless'];

    window['currentVideo_' + index] = 0;
    updateVideo(window['currentVideo_' + index], playlist);

    var onPlay = function(event) {
      if (chromeless) {
        //override controls
        jwplayer(element_id).setControls(false);
        $('#' + element_id).parent().addClass('playing');
        $('#' + element_id).css('background-color', 'white');
      }
      else {
        //Update the custom email share info for video playlist
        var playlist_item = settings.playlist;
        //Is it a playlist?
        if (playlist_item.length > 1 && typeof playlist != 'string') {
          //Is there a mediaid passed for the share link
          if (settings.sharing.link.includes('MEDIAID')) {
            var share_link = settings.sharing.link;
            //Which vid is currently playing?
            if ($('.video-item.active').length !=0) {
              vid_index = $('.video-item.active').attr('data-video-number');
              var mediaId = playlist_item[vid_index].mediaid;
              //Replace the MEDIAID token with the appropriate value
              share_link = share_link.replace('MEDIAID' , mediaId);
              share_title = playlist_item[vid_index].title;
              share_title = $('<div/>').html(share_title).text();
              //Update the custom email share function with the current vid info
              if (settings.sharing.sites[2] && settings.sharing.sites[2].label == 'email') {
                settings.sharing.sites[2].src = function() {
                  window.location.href = 'mailto:?subject=' + share_title + '&body=' + share_link;
                }
              }
            }
          }
        }
      }
    },

    onPause = function(event) {
      if (chromeless) {
        $('#' + element_id).parent().removeClass('playing');
      }
    },

    onReady = function() {
      DTM && DTM.JWP && DTM.JWP.bindVideoInstance( jwplayer( element_id ) );
    },

    onComplete = function(event) {
      window['currentVideo_' + index] = window['currentVideo_' + index] + 1;

      $(playlist).find('.video-description .description-item').removeClass('active');
      playlist.find('ul.video-playlist .video-item').removeClass('active');
      updateVideo(window['currentVideo_' + index], playlist);

      /* Move Slider to slide containing the current video */
      var slides;
      if(window['bxslider_' + index + '_view_mode'] == 'large'){
        slides = 4;
      }else if(window['bxslider_' + index + '_view_mode'] == 'small'){
        slides = 2;
      }else{
        slides = 3;
      }
      var newValCurrentSlide = Math.floor(window['currentVideo_' + index]/slides);
      var current_slide = window['bxslider_' + index].getCurrentSlide();
      if( newValCurrentSlide != current_slide){
        window['bxslider_' + index].goToSlide(newValCurrentSlide);
      }
    };

    jwplayer(element_id).onPlay( onPlay);
    jwplayer(element_id).onPause(onPause);
    jwplayer(element_id).onReady(onReady);
    jwplayer(element_id).onComplete(onComplete );

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

        //if it has class then dont continue
        if ($(this).hasClass('disable-autoplay')) {
          return;
        }

        if (player_mid_pos > window_mid_pos - 150 && player_mid_pos < window_mid_pos + 150 ) {
          var video_state = jwplayer(control_id).getState();

          //only want to play if it's not playing
          if (video_state != "PLAYING") {
            jwplayer(control_id).play();
          }
        }
        else {
          //we want to only pause if it has playing
          if ($(this).hasClass('playing')) {
            jwplayer(control_id).pause();
          }
        }
      });
    }
  }

  //document ready
  $(document).ready(function() {
    $('.chromeless-controls .pause').click(function() {
      var player_id = $(this).data('playerId');
      jwplayer(player_id).pause();

      //adds a class so that it disables autoplay
      $(this).parent().parent().addClass('disable-autoplay');

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
        slides = 2;
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

      //destroy all slider
      if (window['bxslider_' + index] != undefined) {
        //window['bxslider_' + index].destroySlider();
        return;
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
        slideWidth: 228,
        slideMargin: 8,
        infiniteLoop: false,
        hideControlOnEnd: true,
        responsive: true,
        pager: false,
        nextText: '',
        prevText: '',
        startSlide: window['bxslider_' + index + '_current']
      });

      //adjustment to auto correct location of slider control
      $(window).resize(function(){
        //Mobile titles are too long so we are ellipissississing them
        if(window.innerWidth <= 480) {
          $('.video-item .promo-headline').each(function(index){
            var mobileTitle = decodeURIComponent($(this).attr('data-mobile'));
            if(mobileTitle != $(this).text()) {
              $(this).text(mobileTitle);
              if($(this).parents('.bx-viewport').height() < $(this).parent('.video-item').height() || index == 0) {
                $(this).parents('.bx-viewport').height($(this).parent('.video-item').height());
              }
            }
          });
        } else {
          $('.video-item .promo-headline').each(function(index){
            var fullTitle = decodeURIComponent($(this).attr('data-full')).trim();
            if(fullTitle != $(this).text().trim()) {
              $(this).text(fullTitle);
              if($(this).parents('.bx-viewport').height() < $(this).parent('.video-item').height() || index == 0) {
                $(this).parents('.bx-viewport').height($(this).parent('.video-item').height());
              }
            }
          });
        }

        var all_slides = $('.bxslider');

        //does for each slider
        all_slides.each(function(index) {
          var bxslider_wrapper = $(window['bxslider_' + index]).parent().parent();
          if(window.innerWidth < 480) {
            var height = 40;
            var imgh = $('.video-item[data-video-number="0"] img', bxslider_wrapper).height();
            var toptemp = (imgh/2)-20;
          } else {
            var height = $('.video-item[data-video-number="0"] img', bxslider_wrapper).height();
            var toptemp = 0;
          }

          $('.bx-controls a', bxslider_wrapper).css({'height': height,'top': toptemp});

        });
      });
      setTimeout(function(){
        var bxslider_wrapper = $(window['bxslider_' + index]).parent().parent();

        if(window.innerWidth < 480) {
          var height = 40;
          var imgh = $('.video-item[data-video-number="0"] img', bxslider_wrapper).height();
          var toptemp = (imgh/2)-20;
        } else {
          var height = $('.video-item[data-video-number="0"] img', bxslider_wrapper).height();
          var toptemp = 0;
        }

        $('.bx-controls a', bxslider_wrapper).css({'height': height,'top': toptemp});

        //Mobile titles are too long so we are ellipissississing them
        if(window.innerWidth <= 480) {
          $('.video-item .promo-headline').each(function(index){
            var mobileTitle = decodeURIComponent($(this).attr('data-mobile'));
            if(mobileTitle != $(this).text()) {
              $(this).text(mobileTitle);
              if($(this).parents('.bx-viewport').height() < $(this).parent('.video-item').height() || index == 0) {
                $(this).parents('.bx-viewport').height($(this).parent('.video-item').height());
              }
            }
          });
        } else {
          $('.video-item .promo-headline').each(function(index){
            var fullTitle = decodeURIComponent($(this).attr('data-full')).trim();
            if(fullTitle != $(this).text().trim()) {
              $(this).text(fullTitle);
              if($(this).parents('.bx-viewport').height() < $(this).parent('.video-item').height() || index == 0) {
                $(this).parents('.bx-viewport').height($(this).parent('.video-item').height());
              }
            }
          });
        }
      },500);
    });
  }
})(jQuery, Drupal, this, this.document);
