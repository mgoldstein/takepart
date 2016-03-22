/**
 * @file
 * Scripts for Takepart Campaigns.
 */
(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.campaignSlideShows = {
    attach: function() {
      if (!$('body').is('.node-type-campaign-page')) {
        return;
      }

      var $sliders = $('.slider');
      var $swipes = $('.swipe');

      // setup slideshows
      $sliders.each(function() {
        // set up the slider
        var $this = $(this).Swipe({
          continuous: false,
          speed: 800,
          callback: function(index, slide) {
            $navLinks
              .filter('[data-slide=' + index % $navLinks.length + ']').addClass('active')
              .siblings('.active').removeClass('active')
            ;
            var maxCards = $this.data('Swipe').getNumSlides() - 1;

            if(index  === 0){
              $this.addClass('on-first-slide');
              $this.removeClass('on-last-slide');
            }
            else if(index == maxCards){
              $this.addClass('on-last-slide');
              $this.removeClass('on-first-slide');
            }
            else{
              $this.removeClass('on-last-slide');
              $this.removeClass('on-first-slide');
            }

            //Height of the slideshow should match the height of the active slide
            var wrapper = $this.find('.swipe-wrap');
            var current_height = wrapper.find('.card-wrapper[data-index="'+ index +'"]').height();
            wrapper.height(current_height);

          }
        });
        var slider = $this.data('Swipe');
        var $navLinks = $this.find('.slider-pagination a');

        // setup forward/back nav
        $this.find('.left-arrow').on('click', function() { slider.prev(); });
        $this.find('.right-arrow').on('click', function() { slider.next();  });

        // set up pagination -- active class and click event
        $navLinks.filter(':first').addClass('active')
          .parent().on('click', 'a', function(e) {
            e.preventDefault();
            slider.slide($(this).data('slide'));
          })
        ;
      }); // end $sliders.each()

      // deal with card padding
      var adjustCardHeightsAndPadding = function() {
        $swipes.each(function() {
          var $this = $(this);
          var titleHeight = $this.find('.tray-header').outerHeight();
          var multipleCards = $this.is('.has-multiple-cards');

          // if there is a tray title, set card padding
          // and contextual link position
          if (titleHeight > 0) {
            $this.find('.card .card-inner')
              .css("padding-top", titleHeight)
              .find('.contextual-links-wrapper')
                .css({
                  top: titleHeight + 2,
                  right: multipleCards ? 80 : 5
                })
            ;
          }
        });
      };

      //Full Screen Ambient Video
      //Assuming there is only a top video
      var adjustCardBackgroundVideo = function() {
        //find/set video ratio
        if(window.videoRatio !== 'undefined') {
          window.videoRatio = $('.has-videoBG video').width()/$('.has-videoBG video').height();
        }
        var winh = window.innerHeight;
        var winw = window.innerWidth;
        //Set the parent divs to set heights
        $('.has-videoBG').parent('.card-wrapper').height('100%');
        $('.has-videoBG').parents('.swipe-wrap').height('100%');
        $('.has-videoBG').parents('.tray-img-width-full').height(winh);
        //check to see if the screen ratio needs us to
        //Change if we are using the height or width as our set variable
        if((winw/winh) >= window.videoRatio) {
          $('.has-videoBG video').height(winw/window.videoRatio);
          $('.has-videoBG video').width(winw);
        } else {
          $('.has-videoBG video').height(winh);
          $('.has-videoBG video').width(winh*window.videoRatio);
        }
      };

      // bind the previous function to window load and resize
      // debouncing for 300ms
      var resizeTimeout = null;
      var resizeVideo = null;
      $(window).on('load resize', function() {
        clearTimeout(resizeTimeout);
        resizeTimeout = setTimeout($.proxy(adjustCardHeightsAndPadding, this), 250);
        //Activate ambient video
        if ($('.is-ambient').length != 0) {
          clearTimeout(resizeVideo);
          resizeVideo = setTimeout($.proxy(adjustCardBackgroundVideo, this), 150);
        }

      });

      //addresses issue with hover state - removed touchstart
      $('.mobile-arrow.right-arrow, .mobile-arrow.left-arrow').bind('mouseover', function() {
        $(this).addClass('hover-class');
      });

      //addresses issue with hover state remove touchend
      $('.mobile-arrow.right-arrow, .mobile-arrow.left-arrow').bind('mouseout touchend', function() {
        $(this).removeClass('hover-class');
      });
    }
  };

  Drupal.behaviors.campaignHeaderMenu = {
    attach: function() {
      if ($('body').is('.node-type-campaign-page')) {
          if ($('#block-tp-campaigns-tp-campaigns-hero').length > 0) {
              $('ul.sf-menu').superfish();

              // minimum mobile height
              var HeaderMobileMinHeight = $('.header-inner').attr("data-mheight");
              if(HeaderMobileMinHeight != '-20px'){
                  if($(window).width() < 768){
                      $('.header-inner').css( "min-height", HeaderMobileMinHeight);
                      $('.branding-header').css( "min-height", HeaderMobileMinHeight);
                  }
              }
          }
      }
    }
  };

  Drupal.behaviors.campaignResponsiveMenu = {
    attach: function() {
      function bindStickupToMenus() {
        //initiating jQuery
        //enabling stickUp on the '.navbar-wrapper' class
        var desktopWidth = ( $(window).width() > 768),
            campaignHasNoMenus = $('#campaign-drawers li').length == 0,
            stickUpSettings = {
              parts:     Drupal.settings.tp_campaigns.stickupParts,
              itemClass: 'anchored',
              itemHover: 'active'
            };

        if ( desktopWidth ) {
          $('#block-tp-campaigns-tp-campaigns-hero').stickUp( stickUpSettings );
        }
        if ( campaignHasNoMenus ) {
          $('.campaign-menu-toggle').hide();
        }
      }

      //only bind when document is ready to bind
      $(document).ready(function() {
        //addresses issue with race condition
        if ( Drupal.settings.tp_campaigns )
          setTimeout( bindStickupToMenus, 2000 );

        //ensures that this only runs on campaign displays
        //if there is a transparent nav then the page slides under the header
        //to the top of the page
        if ($('body').hasClass('campaign-display') && !$('body').hasClass('campaign-transparent-nav')) {
          $(window).scroll(function() {
            if ($('#block-tp-campaigns-tp-campaigns-hero').hasClass('isStuck')) {
              $('#main-wrap').css('margin-top', parseInt($('#block-tp-campaigns-tp-campaigns-hero').height()) + 'px');
            }
            else {
              $('#main-wrap').css('margin-top', '');
            }
          });
        }
      });
    }
  };


    Drupal.behaviors.campaignVideoBG = {
        attach: function() {

            var Environment = {
                //mobile or desktop compatible event name, to be used with '.on' function
                TOUCH_DOWN_EVENT_NAME: 'mousedown touchstart',
                TOUCH_UP_EVENT_NAME: 'mouseup touchend',
                TOUCH_MOVE_EVENT_NAME: 'mousemove touchmove',
                TOUCH_DOUBLE_TAB_EVENT_NAME: 'dblclick dbltap',

                isAndroid: function() {
                    return navigator.userAgent.match(/Android/i);
                },
                isBlackBerry: function() {
                    return navigator.userAgent.match(/BlackBerry/i);
                },
                isIOS: function() {
                    return navigator.userAgent.match(/iPhone|iPad|iPod/i);
                },
                isOpera: function() {
                    return navigator.userAgent.match(/Opera Mini/i);
                },
                isWindows: function() {
                    return navigator.userAgent.match(/IEMobile/i);
                },
                isMobile: function() {
                    return (Environment.isAndroid() || Environment.isBlackBerry() || Environment.isIOS() || Environment.isOpera() || Environment.isWindows());
                }
            };

            //Create ambient video backgrounds
            $('.card.has-videoBG').each( function( index, element ) {

              $prop = $(this).data('video-bg');
              var src = $prop[1];
              var poster =  $prop[0];

              if(!Environment.isMobile()){
                //Only add it to the markup if there is no video
                if ($(this).find('video').length == 0) {
                  var videoWrapper = document.createElement("div");
                  var video = document.createElement("video");
                  var videoSource = document.createElement("source");
                  videoWrapper.className = 'videoBG_wrapper';
                  videoSource.type = "video/mp4";
                  videoSource.src = src;
                  videoSource.poster = poster;
                  video.className = 'background-video';
                  video.setAttribute('autoplay', '');
                  video.setAttribute('loop', '');
                  //video.setAttribute('muted', '');
                  video.setAttribute('poster', poster);
                  video.appendChild(videoSource);
                  videoWrapper.appendChild(video);
                  $(this).prepend(videoWrapper);
                }
              }else{
                 //If a mobile device is detected AND the card has a video background then use the poster image as bg
                $(this).css('background-image', 'url(' + poster + ')');
              }
            });
        }
    };

  Drupal.behaviors.campaignPageSocialShare = {
    attach: function() {
      var $body = $('body');

      if (!$body.is('.node-type-campaign-page')) {
        return;
      }

      var $social = $('#campaign-page-social');
      var title = $social.data('title');
      var description = $social.data('description');
      var imageSrc = $social.data('imagesrc');

      var mainShares = {
          url_append: '?cmpid=organic-share-{{name}}',
          services: [
            {
              name: 'facebook',
              title: title,
              image: imageSrc,
              description: description
            },
            {
              name: 'twitter',
              text: title
            },
            {
              name: 'googleplus'
            }
          ]
      };
      var moreShares = {
          url_append: '?cmpid=organic-share-{{name}}',
          services: [
            {
              name: 'pinterest',
              media: imageSrc,
              description: title
            },
            {
              name: 'tumblr',
              source: imageSrc,
              caption: title + " - " + description
            },
            {
              name: 'mailto',
              title: title,
              note: description
            }
          ]
      };

      $('#campaign-page-share').tpsocial(mainShares);
      $('#campaign-page-more-shares').find('p').tpsocial(moreShares);
      $moreShares = $('#campaign-page-social-more');

      var moreSharesClose = function() {
        $moreShares.removeClass('focus');
        $body.off('click.campaignSocial');
      };

      $moreShares
        .on('click', '.trigger a', function(e) {
          e.preventDefault();
          if (!$moreShares.is('.focus')) {
            $moreShares.addClass('focus');
            setTimeout(function() {
              $body.on('click.campaignSocial', moreSharesClose);
            }, 100);
          }
        })
        .on('focusin', function() {
          $moreShares.addClass('focus');
        })
        .on('focusout', function() {
          $moreShares.removeClass('focus');
        })
      ;
    }
  };
})(jQuery, Drupal, this, this.document);
