// Social menu
/**
 * @file
 * Scripts social menu
 */
(function ($, Drupal, window, document, undefined) {

  /**
   * Function for tpsocial shares
   */
  Drupal.tpsocialShares = function () {
	 var $body = $('body'),
		    isOpenpublishArticle = $body.is('.page-node.node-type-openpublish-article'),
		    isFeatureArticle = $body.is('.page-node.node-type-feature-article'),
		    isVideoArticle = $body.is('.page-node.node-type-video'),
		    isVideoPlaylist = $body.is('.page-node.node-type-video-playlist'),
		    isFlashcard = $body.is('.page-node.node-type-flashcard'),
		    isCampaignPage = $body.is('.node-type-campaign-page'),
		    isGallery = $body.is('.node-type-openpublish-photo-gallery');

	 // Setup Social Share Buttons
	 window.tp_social_config = {
	   url_append: '?cmpid=organic-share-{{name}}',
	   services: {
		facebook: {
		  name: 'facebook',
		  description: isFeatureArticle ? $('.field-name-field-article-subhead .field-item').text() : null
		},
		twitter: {
		  name: 'twitter',
		  text: '{{title}}',
		  via: 'TakePart'
		},
		mailto: {
		  name: 'mailto'
		},
		googleplus: {
		  name: 'googleplus'
		},
		tumblr: {
		  name: 'tumblr'
		},
		whatsapp: {
		  name: 'whatsapp'
		},
		pinterest: {
		  name: 'pinterest'
		}
	   }
	 };

	 /* If page is a gallery, article or featured article, add Pinterest */
	 if (isGallery || isFeatureArticle || isOpenpublishArticle) {
	   main_image = $('.field-name-field-article-main-image').find('img').attr('src');
	 }
	 /* If page is a campaign page, remove mailto, reddit and tumblr */
	 if (isCampaignPage) {
	   delete tp_social_config.services.mailto;
	   delete tp_social_config.services.reddit;
	   delete tp_social_config.services.tumblr;
	   delete tp_social_config.services.whatsapp;
	   delete tp_social_config.services.pinterest;
	 }

	 //alters the config for the services based on content type
	 if ($('body').hasClass('node-type-openpublish-photo-gallery')) {
	   delete tp_social_config.services.tumblr;
	 }
	 else {
	   delete tp_social_config.services.pinterest;
	 }

	 if (window.innerWidth >= 800) {
	   delete tp_social_config.services.whatsapp;
	 }

	 //Just Make Sticky. Will handle Mobile through CSS
	 $.when($('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config)).done(function () {
     $('.social-vertical.stick').tp4Sticky({offset: isFlashcard ? 0 : 7});
	 });
  };

  /*
   * Social Menu Behaviors
   */
  Drupal.behaviors.socialMenuBehaviors = {
    attach: function (context, settings) {
  	 //trigger tp_initSocialMenu
  	 $(document).ready(function () {
       //Not reloading social on Drupal Attach Behaviors
       if(!$('.social').hasClass('socialMenu-processed')) {
         Drupal.tpsocialShares();
    	   window.tp_initSocialMenu();
    	   $(window).smartresize(function () {
    		    window.tp_initSocialMenu();
    	   });
         //Show the social after everything is loaded.
         $('.social').once('socialMenu');
       }
  	 });
    }
  }

  // To understand behaviors, see https://drupal.org/node/756722#behaviors
  Drupal.behaviors.mobileSocialNav = {
    attach: function (context, settings) {

      // Show the mobile social nav bar when window scrolls down
      var didScroll;
        $(window).scroll(function (event) {
          didScroll = true;
          window.tp_shareFeatureHide();
      });

      setInterval(function () {
        if (didScroll && window.innerWidth < 480) {
          var delta = 5;
          hasScrolled(delta);
          didScroll = false;
        }
      }, 250);
    }
  };

  Drupal.behaviors.InlineSocialShare = {
    attach: function (context, settings) {
      //trigger tp_initSocialMenu
      $(document).ready(function () {
        $('.inlineSharingButtons').each(function(){
          $(this).once('inlineSharing',function(){
            var author_name = $(this).parent().attr('data-author-name') || $("meta[name='sailthru.author']").attr('content');
            var append_author = "—"+author_name;
            var caption = '';
            if($("meta[property='og:description']").length) {
              caption =$("meta[property='og:description']").attr("content");
            }

            var services = {
              url_append: '?cmpid=organic-share-{{name}}',
              services: {
                twitter: {
                  name: 'twitter',
                  text: $(this).siblings('.inlineSharingQuote').text(),
                  via: 'TakePart',
                  anchor: $(this).parent().attr('data-anchor'),
                  author_name: append_author,
                  quote: true,
                  class_target: 'inlineSharingUnique-'+$(this).parent().attr('data-unique-id')
                },
                facebook: {
                  name: 'facebookfeed',
                  description: "\""+$(this).siblings('.inlineSharingQuote').text()+"\""+append_author,
                  anchor: $(this).parent().attr('data-anchor'),
                  author_name: author_name,
                  share_title: $(this).parent().attr('data-title'),
                  caption: caption,
                  picture: true
                }
              }
            };
            $(this).tpsocial(services);
          });
        });
      });
    }
  };

  Drupal.behaviors.HighlightShare = {
    attach: function (context, settings) {
      $(document.body).on('mouseup', function (evt) {
        var menu = $('#highlight_menu');
        var s = window.getSelection();
        if(s.rangeCount <= 0) {
          return;
        }

        var r = s.getRangeAt(0);

        if (r && s.toString()) {
          var p = r.getBoundingClientRect();

          if (p.left || p.top) {
            menu.css({
              left: (p.left + (p.width / 2)) - (menu.width() / 2),
              top: ((p.top - menu.height() - 10)+$(window).scrollTop()),
              display: 'block',
              opacity: 0
          })
          .animate({
            opacity:1
          }, 300);

          setTimeout(function() {
            menu.addClass('highlight_menu_animate');
          }, 10);
          return;
        }
        }
        menu.animate({ opacity:0 }, function () {
          menu.hide().removeClass('highlight_menu_animate');
        });
      });


      $('#highlight_share_container').each(function(){
        $(this).once('highlightSharing',function(){

          var services = {
            url_append: '?cmpid=organic-share-{{name}}',
            services: {
              twitter: {
                name: 'twitter',
                text: '{{highlight}}',
                via: 'TakePart',
                quote: true,
                author_name: '',
                class_target: 'highlightShareUnique'
              },
              facebook: {
                name: 'facebookfeed',
                description: '{{highlight}}',
                picture: false
              }
            }
          };
          $(this).tpsocial(services);
        });
      });
    }
  };

  var lastScrollTop = 0;
  function hasScrolled(delta) {
    var st = $(this).scrollTop();

    // Make sure they scroll more than delta
    if (Math.abs(lastScrollTop - st) <= delta)
      return;

    if (st > lastScrollTop) {
      // Scroll Down
      $('.header-wrapper.mobile').removeClass('nav-show').addClass('nav-hide');
    } else {
      // Scroll Up
      $('.header-wrapper.mobile').removeClass('nav-hide').addClass('nav-show');
    }

    lastScrollTop = st;
  }

  window.tp_initSocialMenu = function () {
    var mobile = 479;
    var social_menu = $('.social-wrapper');
    var main_menu = $('.header-wrapper');

    //mobile
    if (window.innerWidth <= mobile || (typeof window.orientation != 'undefined' && window.orientation != 0 && window.innerHeight < 500)) {
  	 $(social_menu).addClass('mobile');
  	 $(main_menu).addClass('mobile');
  	 $(social_menu).removeClass('desktop');
  	 $(main_menu).removeClass('desktop');
    } else {
  	 $(social_menu).removeClass('mobile');
  	 $(main_menu).removeClass('mobile');
  	 $(social_menu).addClass('desktop');
  	 $(main_menu).addClass('desktop');
    }
  };

  /**
   * Sticky Share Left Align
   */
  window.tp_shareLeftAlign = function() {
    var leftAlign = (((window.innerWidth - 780)/2) - $('.sticky-wrapper aside').width()) - 35;
    if(leftAlign > 0) {
      $('.sticky-wrapper').css('left', leftAlign);
    } else {
      $('.sticky-wrapper').css('left', 0);
    }
  };

  /**
   * Sticky Share Top Offset
   */
  window.tp_shareTopOffset = function() {
    var cic_space = 0;
    //Add an extra 60px if its in-campaign experience
    if ($('.campaign-experience').length != 0) {
      cic_space = 60;
    }
    $('article.node').each(function(index){
      if(index == 0) {
        if($(this).hasClass('node-feature-article')) {
          window.featureFirst = true;
          var stickyOffset = $(".align-sticky").offset().top - $(".main-content").offset().top + cic_space;
          //Adjust the sticky for feature with alternative hero
          if ($(this).has('.feature_alt_hero').length != 0) {
             stickyOffset = $(this).find('.field-name-body').offset().top;
          }
        } else {
          window.featureFirst = false;
          var stickyOffset = $(".align-sticky").offset().top - $(".main-content").offset().top + cic_space;
        }
        $('.sticky-wrapper').css('margin-top', stickyOffset - 7);
      }
    });
  };

  /**
   * Sticky Share hide if in presence of feature main image
   */
  window.tp_shareFeatureHide = function(){
    if($('.fresh-content-wrapper').length && $('.sticky-wrapper .social').length) {
      //Only do this on Desktop so we check for mobile
      if(window.innerWidth >= 768) {
        var elem = $('.fresh-content-wrapper').nextAll(':not(#block-workbench-block,.tp-fresh-bottom-content)'), count = elem.length, showSticky = true;

        //Get the sticky measurements
        window.stickHeight = $('.sticky-wrapper .social').height();
        window.stickTop = $('.sticky-wrapper .social').offset().top;
        window.stickBot = stickTop + stickHeight;

        //First check for the main media image being collided with.
        $('article.node').each(function(index){
          if($(this).parent().parent().hasClass('feature_article-wrapper')) {
            $(this).find('.full-width').each(function(){
              var mITop = $(this).offset().top;
              var mIBot = $(this).height() + mITop;
              //Test if the share bar is colliding with feature main image
              //Using Visibility because .show()/.hide() causes a blinky
              //share for 7 pixels when collision is detected
              if(stickBot > mITop-25 && stickTop < mIBot+25) {
                $('.sticky-wrapper').css('visibility', 'hidden');
                showSticky = false;
              }
            });
          }
          //Hide the share between moreon section and the top of the next article

          var moreontop = $(this).parents('.fresh-content-wrapper').find('.tp-fresh-bottom-content').offset().top;
          var arttop = $(this).parents('.fresh-content-wrapper').offset().top;
          var artbot = arttop + $(this).parents('.fresh-content-wrapper').height() + 15;
          //Showing after it passes the first section
          var artbegin = $(this).find('.section').offset().top - 15;
          //Checking the bottom of the sticky share first and then the top of the
          //Sticky share
          if(
            ( (stickBot > moreontop && stickBot < artbot)
              || (stickBot > arttop && stickBot < artbegin)
            ) || (
              (stickTop > moreontop && stickTop < artbot)
                || (stickTop > arttop && stickTop < artbegin)
            )
          ) {
            $('.sticky-wrapper').css('visibility', 'hidden');
            showSticky = false;
          }
          if(!--count) {
            if(showSticky == true) {
              $('.sticky-wrapper').css('visibility', 'visible');
            }
          }
        });
      } else {
        if($('.sticky-wrapper').css('visibility') != 'visible') {
          $('.sticky-wrapper').css('visibility', 'visible');
        }
      }
    }
  };

})(jQuery, Drupal, this, this.document);
