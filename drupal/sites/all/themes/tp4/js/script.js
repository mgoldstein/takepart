/**
 * @file
 * Scripts for the theme.
 */

(function ($, Drupal, window, document, undefined) {

	Drupal.behaviors.mobileSearchToggle = {
    attach: function(context, settings) {

      /* Search for mobile and Desktop */
      tp_mobile_header_init();
      if(typeof smartresize == 'function'){
        $(window).smartresize(function() {
            tp_mobile_header_init();
        });
      }

      function tp_mobile_header_init(){
        if($(window).width() < 768){
          /* Show search field */
          var $body = $('body');
          $('.toggle-search').click(function(){
            if ($body.hasClass('mobile-search-show')) {
              $body.removeClass("mobile-search-show" );
            }else{
              $body.addClass("mobile-search-show" );
            }
          });

          /* Hide search if clicked away from */
          $(document).on('click', function(event) {
            if (!$(event.target).closest('.search').length) {
              $body.removeClass("mobile-search-show" );
            }
          });

          //makes the search go away on focus
          $('.search input').focus(function() {
            $(this).val('');
          });
        }
      }
    }
  };

  /*
   * Megamenu Behaviors
   */
  Drupal.behaviors.megaMenuBehaviors = {
    attach: function(context, settings) {
    //prevent ONLY parent links on megamenu from linking on touch, using doubletaptogo.js
//     $('#block-menu-menu-megamenu ul li a').not('li.is-leaf a').doubleTapToGo();

    var curItem = false;

    $('#block-menu-menu-megamenu ul li a').not('li.is-leaf a').on( 'click', function( e )
    {
      var item = $( this );
      if( item[ 0 ] != curItem[ 0 ] )
      {
        //e.preventDefault();
        curItem = item;
      }
    });

      //Toggle search on mobile
      $('html').click(function() {
        $('.search-toggle').parent().removeClass('active');
      });

      $('#block-menu-menu-megamenu ul li.level-0 a').click(function(event){
        if ($(this).parent().attr('id') != '') {

          var id = $(this).parent().attr('id');
          id = id.replace('menu-id-', '');

					if ($('#block-menu-menu-megamenu ul li.level-1.' + id).length !== 0) {
						event.preventDefault();
					}

          $('#block-menu-menu-megamenu ul li.level-1.' + id).slideToggle('fast');
        }
      });

      $('.search-toggle').parent().click(function(event){
        event.stopPropagation();
        $(this).addClass('active');
      });

      function makeTall(){$(this).find('.mega-content').fadeIn(100);}
      function makeShort(){$(this).find('.mega-content').fadeOut(100);}

      //allows the custom slim nav to instantly display the second level
      if ($('#megamenu').hasClass('tp-slim-nav')) {
        $('.mega-item').hover(
          function() {
            $('.mega-content', this).show();
          },
          function() {
            $('.mega-content', this).hide();
          }
        );
      }
      //fall back to the original for other pages
      else {
      $("#megamenu").hoverIntent({
        over: makeTall,
        out: makeShort,
        selector: 'li.mega-item'
      });
      }
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

      $('body:not(.campaign-transparent-nav) .menu-toggle').on('click', function(e){
        e.preventDefault();
        if ( snapper.state().state == "closed" ) {
          $('#campaign-drawers').hide();
          $('#tp-drawers').show();
          snapper.open('left');
					$(document).on('touchstart touchmove', function(e) {
            if (!$(e.target).parents('#tp-drawers').length) {
              e.preventDefault();
            }
          });
        }
        else {
          snapper.close();
          $('.snap-drawers').hide();
					$(document).off('touchstart touchmove');
        }
      });

      snapper.on('animated', function() {
        if (snapper.state().state == "closed") {
          snapper.close();
          $('.snap-drawers').hide();
					$(document).off('touchstart touchmove');
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

//      snapper.on('animated', function() {
//        if (anchorTarget !== null) {
//          $.scrollTo(anchorTarget, 250);
//          anchorTarget = null;
//        }
//      });

      setTimeout(function() {
        var $header = $('.header-wrapper'),
            headerHeight = $header.height() - 30;

        if (  $(window).width() > 768 )
          $('a.card-anchor').css({ top: -headerHeight + 'px' });
      }, 1000 );
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
        || $body.is('.page-node.node-type-openpublish-photo-gallery')
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
        .append('<a class="featured-campaigns-nav prev icon i-arrow-left">')
        .append('<a class="featured-campaigns-nav next icon i-arrow-right">');
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
    'Home - stories under lead' : 'body.page-tp4-homepage .panel-secondary-featured',
    'Home - top horizontal promo' : '#block-tp4-support-tp4-dont-miss'

//    'Mobile Sticky Strip': '.social-wrapper.mobile',
//    'Mobile Sticky Strip Share': '.social-wrapper.mobile li.share'

  });

    /**
     * Modal ad Behaviors
     */
    Drupal.behaviors.showModal = {
        attach: function(context, settings) {

            $(document).ready(function(){

                if($('body').hasClass('campaign-display')){
                    /* Append Modal Background to Page */
										if($('.modal-bg').length === 0) {
	                    var modalBG = document.createElement('div');
	                    modalBG.className = 'modal-bg';
	                    $('body').append(modalBG);
										}

										if($('.close-btn').length === 0) {
	                    var closeButton = document.createElement('a');
	                    closeButton.className = 'close-btn';
	                    closeButton.innerHTML = '<div class="icon i-close"></div>';
										}

                    /* Append overlay content to body */
                    $('.modal-content').each(function(){
                        $(closeButton).appendTo(this);
                        $(this).appendTo('body');
                    });

                    /* Initialize player ahead of time */
                    $('.modal-content.jwp').each(function(){
                      var playerId = $(this).data('jwp-id');

											if(!$(this).hasClass('jwp-'+playerId+'-processed')) {
												$(this).addClass('jwp-'+playerId+'-processed');
	                      var file = $(this).data('jwp-file');
	                      var title = $(this).data('jwp-title');
												if ( typeof window.playerInstance === 'undefined') {
													console.log('player array');
													window.playerInstance = [];
												}
	                      window.playerInstance[playerId] = jwplayer('jwp-' + playerId).setup({
	                        file: file,
	                        width: '100%',
	                        aspectratio: '16:9',
	                        primary: 'html5',
	                        title: title
	                      });
											}
                    });

                    $('.show-modal').click(function(event){
                        event.preventDefault();
                        var selectedModal = $(this).data('show-modal');

                        showModal(selectedModal);
                    });

                    $('.close-btn, .modal-bg').click(function(){
                        closeModal();
                    });
                }


                // function to show our popups
                function showModal(whichmodal){
                    var docHeight = $(document).height();
                    var scrollTop = $(window).scrollTop();

                    $('.modal-bg').fadeIn("slow").css({'height' : docHeight});
                    $('#'+whichmodal).fadeIn("slow").css({'top': scrollTop+20+'px'});

                    // if a video exists in the modal, play it
                    if($('#'+whichmodal+ ' video').length){
                        $('#'+whichmodal+ ' video')[0].play();
                    }


                    // if a jwplayer placeholder exists, play it
                    if($('#'+whichmodal+ '.jwp').length){

                      /* Append Modal Background to Page */
                      var playerElement = document.createElement('div');
                      playerElement.setAttribute("id", whichmodal+"-inner");
                      $('#'+whichmodal+ '.jwp').append(playerElement);

                      var playerId = $('#'+whichmodal+ '.jwp').data('jwp-id');
                      window.playerInstance[playerId].play();
                    }
                }

                // function to close our popups
                function closeModal(){
                    $('.modal-bg, .modal-content').fadeOut("slow");

                    // if a video exists in modal, pause it
                    if($('.modal-content video').length){
                        $('.modal-content video')[0].pause();
                    }
                }

            });
        }
    };

  /**
   * Set a Cookie/Message for the updated Terms of Use
   */
  Drupal.behaviors.TouCookie = {
    attach: function() {
      if (document.cookie.search('tou') == -1) {
        //Set the cookie - 5 years
        exdays = 1825;
        var d = new Date();
        d.setTime(d.getTime() + (exdays*24*60*60*1000));
        var expires = d.toGMTString();
        document.cookie="tou=1; expires=" + expires + "; path=/";
        var markup = '\
        <div class="tou-alert">\
          <p>We have updated our <a href="http://www.takepart.com/terms-of-service">Terms Of Service</a>\
           and <a href = "http://www.takepart.com/privacy-policy">Privacy Policy</a>.</p>\
          <span class="tou-close">close</span>\
        </div>';
        $('#page-wrap').prepend(markup);
        $('.tou-close').click(function() {
          $('.tou-alert').slideUp('slow',function(){
						//for campaign pages run the body check so it will not leave the user
						//trapped with no scrollbar
						if (typeof campaignBodyCheck === "function") {
							campaignBodyCheck();
						}
          });
        });
      }
    }
  };

	Drupal.behaviors.mobileMenuToggle = {
    attach: function(context, settings) {
			$('body').once('mobileMenuToggle', function(){
	      var $body = $('body');
	      $('body.campaign-transparent-nav .toggle-menu.toggle-left, .left-drawer-control .i-close-x').click(function(){
	        if ($body.hasClass('mobile-menu-show')) {
	          $body.removeClass("mobile-menu-show" );
	          //enable scroll on tablet
	          document.ontouchmove = function(e){ return true; }
	        } else {
	          $body.addClass("mobile-menu-show" );
	          //disable scroll on tablet
	          //document.ontouchmove = function(e){ e.preventDefault(); }
	          $(document).on('touchstart touchmove', function(e) {
	            if (!$(e.target).parents('nav#mobile-menu')) {
	              e.preventDefault();
	            }
	          });
	          //append a modal on feature articles
	          if ($('body.campaign-transparent-nav').length != 0) {
	            if ($('.feature-modal').length == 0) {
	              $('body').append('<div class = "feature-modal"></div>');
	            }
	            $('.feature-modal').click(function() {
	              if ($body.hasClass('mobile-menu-show')) {
	                $body.removeClass("mobile-menu-show" );
	              }
	            });
	          }
	        }
	      });
			});
    }
  };

  Drupal.behaviors.mobileSearchToggleStyleTwo = {
    attach: function(context, settings) {


      /* Show search field */
      var $body = $('body');
      $('.navbar-transparent .toggle-search').click(function(){
        $(this).parents('.navbar-transparent').addClass('search-open');
      });

      /* Hide search if clicked away from */
      $(document).on('click', function(event) {
        if (!$(event.target).closest('.navbar-transparent').length) {
          $('.navbar-transparent').removeClass("search-open");
        }
      });

      // Close search
      /*$('#search-api-page-search-form-site-search--2 input#edit-keys-2--2').click(function(e){
        var offset = $(this).offset();
        var width = $(this).outerWidth();
        var pos_x = e.pageX - offset.left;

        if(width - pos_x < 15) {
          $('.navbar-transparent').removeClass("search-open");
        }
      });*/
      //Close search
      $('.navbar-transparent .search-close').click(function(){
        if ($('.navbar-transparent').hasClass('search-open')) {
          $('.navbar-transparent').removeClass("search-open");
        }
      });

    }
  };

	Drupal.behaviors.mobileMenuBehaviors = {
    attach: function(context, settings) {
			//For campaign transparent nav
			$('body.campaign-transparent-nav #mobile-menu.menu').once('mobile-menu-drop-downs', function(){
	      /* Prevent parent item from clicking through on initial click */
	      var curItem = false;
	      $('.mobile-menu > ul > li > a').on( 'click', function( e ) {
	        var item = $( this );
	        if( item[ 0 ] != curItem[ 0 ] ) {
	          e.preventDefault();
	          curItem = item;
	        }
	      });

	      /* Show child menu. See _mobile-menu.scss */
	      $('.mobile-menu > ul > li').click(function(){
	        if (!$(this).hasClass('show')) {
	          $(this).addClass("show" );
						//Once upon time there was a transparent nav menu on campaigns that
						//did not want to show up on safari(ios and OSX) The DOM did not want
						//to repaint when the body was position:fixed. But the body needed to be fixed
						//in order for the hamburger menu to be scrollable. So along came the below
						///fix that will help the nav menu show up when the parent element is clicked.
						$(this).find('.menu').hide().show(0);
	        }
	      });
			});
			//for all instances of fat nav on tp4
			$('body:not(.campaign-transparent-nav) #tp-drawers').once('mobile-menu-drop-downs', function(){
	      /* Prevent parent item from clicking through on initial click */
	      var curItem = false;
	      $('#tp-drawers #block-menu-menu-megamenu > ul.menu > li > a').on( 'click', function( e ) {
	        var item = $( this );
	        if( item[ 0 ] != curItem[ 0 ] ) {
	          e.preventDefault();
	          curItem = item;
	        }
					if (!$(this).siblings('ul').is(":visible")) {
						$(this).siblings('ul').show();
						//Hack for ios scroll not working it needs a kick start.
						//There is an issue where you have to expand 2 menus for the scroll
						//to work.
						if($('#tp-drawers .snap-drawer').scrollTop() <= 1) {
							//Should be fast enough not to notice
							$('#tp-drawers .snap-drawer').scrollTop(1);
							$('#tp-drawers .snap-drawer').scrollTop(0);
						}
					}
	      });
			});
    }
  };

})(jQuery, Drupal, this, this.document);
