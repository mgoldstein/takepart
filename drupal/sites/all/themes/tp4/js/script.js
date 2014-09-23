/**
 * @file
 * Scripts for the theme.
 */
(function ($, Drupal, window, document, undefined) {

  /**
  * Megamenu Behaviors
  */
  Drupal.behaviors.megaMenuBehaviors = {
    attach: function(context, settings) {
      //prevent parent links on megamenu from linking on touch (link on double touch)
      $('#megamenu li.mega-item:has(.mega-content)').doubleTapToGo();

      //Toggle search on mobile
      $('html').click(function() {
        $('.search-toggle').parent().removeClass('active');
      });

      $('.search-toggle').parent().click(function(event){
        event.stopPropagation();
        $(this).addClass('active');
      });

    $('.search-toggle').parent().hover(function(){
        $(this).addClass('active');
    }, function(){
        $(this).removeClass('active');
    });

      function makeTall(){$(this).find('.mega-content').fadeIn(100);}
      function makeShort(){$(this).find('.mega-content').fadeOut(100);}

      $("#megamenu").hoverIntent({
        over: makeTall,
        out: makeShort,
        selector: 'li.mega-item'
      });
    }
  };

  /**
   * Set up snap.js for the main nav
   */
  Drupal.behaviors.mainSnapper = {
    attach: function(context, settings) {

      var snapper = new Snap({
        element: document.getElementById('page-wrap')
      });

      snapper.settings({
        dragger: null,
        disable: 'none',
        addBodyClasses: true,
        hyperextensible: false,
        resistance: 0.5,
        flickThreshold: 50,
        transitionSpeed: 0.3,
        easing: 'ease',
        maxPosition: 280,
        minPosition: -1,
        tapToClose: true,
        touchToDrag: false,
        clickToDrag: false,
        slideIntent: 40,
        minDragDistance: 5
      });

      snapper.on('animated', function() {
        if (snapper.state().state == "closed") {
          snapper.close();
          $('.snap-drawers').hide();
        }
      });

      $('.menu-toggle').on('click', function(e){
        e.preventDefault();
        if ( snapper.state().state == "closed" ) {
          $('#campaign-drawers').hide();
          $('#tp-drawers').show();
          snapper.open('left');
        }
        else {
          snapper.close();
          $('.snap-drawers').hide();
        }
      });
    }
  };


  Drupal.behaviors.campaignSnapper = {
    attach: function(context, settings) {
      var snapper = new Snap({
        element: document.getElementById('page-wrap')
      });

      snapper.settings({
        dragger: null,
        disable: 'none',
        addBodyClasses: true,
        hyperextensible: false,
        resistance: 0.5,
        flickThreshold: 50,
        transitionSpeed: 0.3,
        easing: 'ease',
        maxPosition: -280,
        minPosition: 50,
        tapToClose: true,
        touchToDrag: false,
        clickToDrag: false,
        slideIntent: 40,
        minDragDistance: 5
      });

      $('.snap-drawer a').on('click', function() {
        snapper.close();
        $('.snap-drawers').hide();
      });

      $('.campaign-menu-toggle').on('click', function(e) {
        e.preventDefault();

        if ( snapper.state().state == "closed" ) {
          $('#tp-drawers').hide();
          $('#campaign-drawers').show();
          snapper.open('right');
        }
        else  {
          snapper.close();
          $('.snap-drawers').hide();
        }
      });

      var anchorTarget = null;

      $('#campaign-drawers a[href*=#]').on('click', function(e) {
        e.preventDefault();
        var path = $(e.target)[0].href;
        anchorTarget = '#' + path.split('#')[1];
      });

      snapper.on('animated', function() {
        if (anchorTarget !== null) {
          $.scrollTo(anchorTarget, 250);
          anchorTarget = null;
        }
      });

      setTimeout(function() {
        var $header = $('.header-wrapper'),
            headerHeight = $header.height() - 30;

        if (  $(window).width() > 768 )
          $('a.card-anchor').css({ top: -headerHeight + 'px' });
      }, 1000 );
    }
  };

  /**
   * Behaviors for tpsocial shares
   */

  Drupal.behaviors.tpsocialShares = {
    attach: function() {
      var $body = $('body'),
      isOpenpublishArticle = $body.is('.page-node.node-type-openpublish-article'),
      isFeatureArticle = $body.is('.page-node.node-type-feature-article'),
      isVideoArticle = $body.is('.page-node.node-type-video'),
      isVideoPlaylist = $body.is('.page-node.node-type-video-playlist'),
      isFlashcard = $body.is('.page-node.node-type-flashcard');

      if (
        isOpenpublishArticle
        || isFeatureArticle
        || isVideoArticle
        || isVideoPlaylist
        || isFlashcard
      ) {
        // Setup Social Share Buttons
        var tp_social_config = {
          url_append: '?cmpid=organic-share-{{name}}',
          services: [
            {
              name: 'facebook',
              description: isFeatureArticle ? $('.field-name-field-article-subhead .field-item').text() : null
            },

            {
              name: 'twitter',
              text: '{{title}}' + (isFeatureArticle ? ' #longform' : ''),
              via: 'TakePart'
            },
            {
              name: 'googleplus'
            },

            {
              name: 'reddit'
            },

            {
              name: 'email'
            },
            
            {
              name: 'mailto'
            }
          ]
        };

        // initialize tpsocial and make it sticky.
        $.when($('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config))
          .then($('#article-social').tp4Sticky({offset: isFlashcard ? 0 : 7}));

        // Set up secondary social share buttons
        var main_image = '';
        if (isOpenpublishArticle) {
          main_image = $('.field-name-field-article-main-image').find('img').attr('src');
        } else if (isFeatureArticle) {
          main_image = $('.field-name-field-article-main-image').find('img').attr('src');
        }
        var more_services = {
          reddit: {
            name: 'reddit'
          },
          pinterest: {
            name: 'pinterest',
            media: main_image
          },
          tumblr_link: {
            name: 'tumblr_link'
          },
          gmail: {
            name: 'gmail'
          },
          hotmail: {
            name: 'hotmail'
          },
          yahoomail: {
            name: 'yahoomail'
          },
          aolmail: {
            name: 'aolmail'
          },

          //{name: 'myspace'},
          //{name: 'delicious'},
          linkedin: {
            name: 'linkedin'
          },
          //{name: 'myaol'},
          //{name: 'live'},
          digg: {
            name: 'digg'
          },
          stumbleupon: {
            name: 'stumbleupon'
          },
          //{name: 'hyves'}
        };
      
        if ( main_image == '' ) delete more_services.pinterest;
        
        $('#article-more-shares p').tpsocial({
          services: more_services
        });

        // set up behavior of "more" social links
        // this is untouched code from gerald burns and chunkpart
        var social_more_close = function() {
          $article_social_more.removeClass('focusin');
          $body.unbind('click', social_more_close);
        };

        var $article_social_more = $('#article-social-more')
          .bind('focusin', function() {
            $article_social_more.addClass('focusin');
          })
          .bind('focusout', function() {
            $article_social_more.removeClass('focusin');
          })
          .bind('click', function(e) {
            if ( !$article_social_more.is('.focusin') ) {
              $article_social_more.addClass('focusin');
              setTimeout(function() {
                $body.bind('click', social_more_close);
              }, 100);
            }
            e.preventDefault();
          })
        ;
        
        //additional code to handle the mousedown and touch for mobile
        $("body").bind('touchstart mousedown', function(event) {
          if (!$(event.target).hasClass('tplinkpos') && !$(event.target).hasClass('tp-social-link')) {
            //checks that class has focus
            if ($('#article-social-more').hasClass('focusin')) {
              //mimics the social more close
              $('#article-social-more').removeClass('focusin');
              $body.unbind('click', social_more_close);
            }
          }
        });
        
      }
    }
  };

  /**
   * Sticky Bottom Ad Unit
   */
  Drupal.behaviors.articleBehaviors = {
    attach: function() {
      var $body = $('body');

      if ($body.is('.page-node.node-type-openpublish-article')
        || $body.is('.page-node.node-type-video')
        || $body.is('.page-node.node-type-video-playlist')
        || $body.is('.page-node.node-type-flashcard')
      ) {
          $('.block-boxes-ga_ad-bottom').tp4Sticky();
      }
    }
  };

  /**
   * Add Content Type Labels to feature_secondary nodes
   * in the main flashcard display.
   */
   Drupal.behaviors.insertNodeLabelsForFlashcards = {
    attach: function() {
      if (!$('body').is('.page-node.node-type-flashcard')) {
        return;
      }

      $('.node.view-mode-feature-secondary').each(function() {
        var $this = $(this);
        $('<h4 class="flashcard-node-label">')
          .text($this.data('contenttype').replace(/_/g, ' ').replace(/openpublish/g, '').replace(/^\s+|\s+$/g, ''))
          .insertBefore($this.find('.node-title'))
        ;
      });
    }
  };

  /**
   * Monitor the global object and fire off analytics callbacks.
   */
  Drupal.behaviors.analytics = {
    attach: function() {
      $(window)
        .on('tp-social-share', function(e, args) {
          takepart.analytics.track('tp-social-share', args);
        })
        .on('tp-social-click', function(e, args) {
          takepart.analytics.track('tp-social-click', args);
        })
        .on('flashcard-tooltip', function(e, args) {
          try {
            takepart.analytics.track('flashcard-tooltip', args);            
          } catch (e) {}
        })
        .on('flashcard-click', function(e, args) {
          try {
            takepart.analytics.track('flashcard-click', args);
          } catch (e) {}
        })
      ;
    }
  };

  /**
   * Handle TP Infographics
   */
  Drupal.behaviors.infographics = {
    attach: function() {
      $('.tpinfographic').tpInfographic();
    }
  };

  /**
   * Set up the featured campaigns module in the footer.
   */
  Drupal.behaviors.featuredCampaignsModule = {
    attach: function() {
      var $campaignsModule = $('#block-bean-featured-campaigns-module');

      // bail early if we dont have a campaigns module
      if ($campaignsModule.length === 0) return;

      var $window = $(window);
      var $container = $campaignsModule.find('.field-collection-container')
        .append('<a class="featured-campaigns-nav prev">')
        .append('<a class="featured-campaigns-nav next">');
      var $wrapper = $container.find('.field-name-field-featured-campaigns');
      var $items = $container.find('.field-item');
      var $nav = $container.find('.featured-campaigns-nav');
      var containerWidth, lastScrollPoint;

      var getTranslateX = function() {
        var element = window.getComputedStyle($wrapper[0], null),
            matrix = element.getPropertyValue("-webkit-transform")
              || element.getPropertyValue("-ms-transform")
              || element.getPropertyValue("transform")
              || $wrapper.css('-webkit-transform')
              || $wrapper.css('-ms-transform')
              || $wrapper.css('transform'),
            position = matrix.replace(/^[^(]*\(|\)$/g, '').split(',');
        return Math.abs(position[4]);
      };

      // set variables for size and 
      var calculateWidth = function() {
        containerWidth = $container.width();
        lastScrollPoint = $container.find('.field-name-field-featured-campaigns').width() - containerWidth;
        if (getTranslateX() > lastScrollPoint) scrollTo(lastScrollPoint);
        calculateNav();
      };

      // determine which nav arrows to show
      // offload this function to the end of the
      var calculateNavTimeout = null;
      var calculateNav = function(duration) {
        duration || (duration = 0);
        clearTimeout(calculateNavTimeout);
        calculateNavTimeout = setTimeout(function() {
          var scrollLeft = getTranslateX();
          $nav.removeClass('hidden');
          if (scrollLeft === 0) {
            $nav.filter('.prev').addClass('hidden');
          }
          if (scrollLeft >= lastScrollPoint || $container.width() >= $container.find('.field-items').width()) {
            $nav.filter('.next').addClass('hidden');
          }
        }, duration + 50);
      };

      // perform a scroll
      var scrollTo = function(targetScroll, duration) {
        if (typeof targetScroll === 'undefined') return;
        duration || (duration = 500);
        var translate = "translateX(-" + targetScroll + "px)";

        $wrapper[0].style.webkitTransitionDuration =
        $wrapper[0].style.MozTransitionDuration =
        $wrapper[0].style.msTransitionDuration =
        $wrapper[0].style.OTransitionDuration =
        $wrapper[0].style.transitionDuration = duration + 'ms';

        $wrapper[0].style.webkitTransform = translate + ' translateZ(0)';
        $wrapper[0].style.msTransform =
        $wrapper[0].style.MozTransform =
        $wrapper[0].style.OTransform = translate;

        // when the css animation is done, recalcuate nav
        calculateNav(duration);
      };

      // recalculate waypoints on resize and
      // perform initial calculation
      var resizeTimeout;
      $window.on('resize', function() {
        clearTimeout(resizeTimeout);
        resizeTimeout = setTimeout(calculateWidth, 200);
      }).trigger('resize');

      // progressivley enhance to prevent
      // horizontal scroll on container
      $container
        .css('overflow', 'hidden')
        .hover(function() {
          $window.on('mousewheel.featuredCampaigns', function(e) {
            if (e.originalEvent.deltaX != 0) {
              e.preventDefault();
            }
          });
        }, function() {
          $window.off('.featuredCampaigns');
        })
      ;

      // handle click events:
      $campaignsModule.on('click', '.featured-campaigns-nav', function(e){
        e.preventDefault();
        var scrollLeft = getTranslateX();
        if (e.currentTarget.classList.contains('next')) {
          scrollTo(Math.min(scrollLeft + containerWidth, lastScrollPoint));
        } else {
          scrollTo(Math.max(scrollLeft - containerWidth, 0));
        }
      });

      // // handle touch events
      // if (
      //   'ontouchstart' in window
      //   || window.DocumentTouch && document instanceof DocumentTouch
      // ) {
        var hammerTime = new Hammer($container[0]);
        var isDragging = false, isScroll = false;
        var initialPosition, nextPosition, prevPosition;

        hammerTime.on('dragstart', function(e) {
          if (!isDragging) {
            initialPosition = getTranslateX();
            nextPosition = Math.min(initialPosition + containerWidth, lastScrollPoint);
            prevPosition = Math.max(initialPosition - containerWidth, 0);
            isDragging = true;
          }
        });

        hammerTime.on('drag', function(e) {
          if (['up', 'down'].indexOf(e.gesture.direction) > -1) return;
          e.preventDefault();
          delta = initialPosition - e.gesture.deltaX;
          if (e.gesture.direction === 'left') {
            scrollTo(Math.min(delta, lastScrollPoint), 0);
          } else {
            scrollTo(Math.max(delta, 0), 0);
          }
        });

        hammerTime.on('dragend', function(e) {
          if (isDragging) {
            if (Math.abs(e.gesture.deltaX) > containerWidth / 2) {
              scrollTo(e.gesture.direction === 'left' ? nextPosition : prevPosition);
            } else {
              scrollTo(initialPosition);
            }
            isDragging = false;
          }
        });

        hammerTime.on('swiperight swipeleft', function(e) {
          isDragging = false;
          scrollTo(e.gesture.direction === 'left' ? nextPosition : prevPosition);
        });
      // }
    }
  };

  /**
  * Mobile ad Behaviors
  */
  Drupal.behaviors.mobileAdBehaviors = {
    attach: function(context, settings) {
         $('body').once('mobile_ad', function() {
        mobile_ad();
      });
      
      function mobile_ad() {
          sticky_mobile_cookie = $.cookie('close_mobile_ad');
          if (sticky_mobile_cookie === '1') {
              $('#block-boxes-ga-mobile-320x50').addClass('hide');
          }
      }
      
      $('.close-mobile-ad').click(function(e) {
          e.preventDefault();
          if (sticky_mobile_cookie === null) { 
            $.cookie('close_mobile_ad', '1', { expires: 1, path:'/' });
          }
        $('#block-boxes-ga-mobile-320x50').addClass('hide');
      });
    }
  };

  /**
   * Playlist BxSlider
   * @type {{attach: attach}}
   */
  Drupal.behaviors.playlistBxSlider = {
    attach: function() {
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
            if (window['slider_' + index]) {

              window['slider_' + index].destroySlider();
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
          if (window['slider_' + index + '_view_mode'] == undefined) {
            window['slider_' + index + '_view_mode'] = viewMode;
          }
          else if (window['slider_' + index + '_view_mode'] != viewMode) {
            playlist.removeClass(window['slider_' + index + '_view_mode']);
            playlist.addClass(viewMode);
            window['slider_' + index + '_view_mode'] = viewMode;
          }

          //return if small
          if (viewMode == 'small') {
            return;
          }

          //destroy all slider
          if (window['slider_' + index]) {
            window['slider_' + index].destroySlider();
          }

          //init slider
          window['slider_' + index] = $(this).bxSlider({
            minSlides: slides,
            maxSlides: slides,
            slideWidth: 152,
            slideMargin: 15,
            infiniteLoop: false,
            hideControlOnEnd: true,
            pager: false,
            nextText: '',
            prevText: ''
          });
        });
      }

      //fires on init
      $(document).ready(function() {
        window.tp_initslider();

        //fires on all resize
        $(window).smartresize(function() {
          window.tp_initslider();
        });
      });
    }
  };
  
  // Omniture position tracking
  // Parent/ancestor vars to track in reverse order of importance
  $.tpregions.add({
    'Header logo' : '.logo',
    'Header social' : '#block-tp4-support-tp4-fat-header .follow-us',
    'Left Flyout Nav - Social' : '#block-tp4-support-tp4-mobile-menu-header .follow-us',
    'Header user menu' : '.user-menu',
    'Slim Header' : '.slim-nav',
    'Mega Menu' : '#megamenu',
    'Footer' : '#footer',
    'Daily Featured Content': '#block-bean-of-the-day',

    // Gallery Properties
    'Gallery - author name': '#block-takepart-gallery-support-takepart-gallery-content .author',
    'Gallery - cover - share icons': '#gallery-cover-social',
    'Gallery - share icons': '#galllery-content-social',
    'Gallery - cover slide - enter gallery': '#gallery-cover',
    'Gallery - gallery description - enter gallery': '#gallery-description .enter-link',
    'Gallery - next slide >': '#block-takepart-gallery-support-takepart-gallery-content #next-slide',
    'Gallery - previous slide <': '#block-takepart-gallery-support-takepart-gallery-content #previous-slide',
    'Gallery - next gallery >': '#block-takepart-gallery-support-takepart-gallery-content #previous-slide',
    'Gallery - related stories': '#gallery-footer .field-name-field-related-stories',

    'Partner Link': '#block-bean-on-our-radar-block',
    'Embedded Content' : '#article-content aside.inline-content',
    'Article - Related Stories' : '#article-footer .field-name-field-related-stories',
    'Series Navigation' : '#series-navigation',
    'Keyword Link' : '.topic-links',
    'Author Full Bio Link' : '.author-bio',
    'Taboola - TPs Most Popular' : '#taboola-bottom-main-column-mix',
    'Taboola - From the Web' : '#taboola-below-main-column',
    'Topic Box' : '.topic-box',
    'TakePart Features': '.node-feature-article .title-block',
    'Home - featured columns' : '#block-views-homepage-columns-block',
    'Home - featured actions' : '#block-views-takeaction-homepage-block',
    'Home - latest headlines' : 'body.page-tp4-homepage #block-views-latest-headlines-block',
    'Home - lead story action' : 'body.page-tp4-homepage .field-name-field-tab-action-override',
    'Home - lead story' : 'body.page-tp4-homepage .panel-main-featured',
    'Home - right rail galleries' : 'body.page-tp4-homepage #block-views-photo-galleries-promo-block',
    'Home - graveyard' : '#block-tp4-support-tp4-graveyard',
    'Home - stories under lead' : 'body.page-tp4-homepage .panel-secondary-featured',
    'Home - top horizontal promo' : '#block-tp4-support-tp4-dont-miss'
  });

})(jQuery, Drupal, this, this.document);
