// Social menu
/**
 * @file
 * Scripts social menu
 */
(function ($, Drupal, window, document, undefined) {

  /**
   * Behaviors for tpsocial shares
   */
  Drupal.behaviors.tpsocialShares = {
    attach: function () {
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

	 //only fix for iphone
	//  if (/iPhone/i.test(navigator.userAgent)) {
	//    //on load adjust the sticky with
	//    var window_width = window.innerWidth;
	//    $('.social-wrapper.mobile').width(window_width);
   //
	//    //add bing to resize so that it resizes for iphone
	//    $(window).smartresize(function () {
	// 	var window_width = window.innerWidth;
	// 	$('.social-wrapper.mobile').width(window_width);
	//    });
	//  }

	 if (window.innerWidth >= 800) {
	   delete tp_social_config.services.whatsapp;
	 }

	 //Just Make Sticky. Will handle Mobile through CSS
	 $.when($('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config)).done(function () {

       $('.social-vertical.stick').tp4Sticky({offset: isFlashcard ? 0 : 7});

	 });

	 window.tp_initSocialMenu();
   //Show the social after everything is loaded.
   $('.social').show();
  }
  };

  /*
   * Social Menu Behaviors
   */
  Drupal.behaviors.socialMenuBehaviors = {
    attach: function (context, settings) {
  	 //trigger tp_initSocialMenu
  	 $(document).ready(function () {
  	   window.tp_initSocialMenu();

  	   $(window).smartresize(function () {
  		    window.tp_initSocialMenu();
  	   });
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
    if(window.featureFirst) {
      var leftAlign = (((window.innerWidth - 780)/2) - $('.sticky-wrapper aside').width()) - 35;
      if(leftAlign > 0) {
        $('.sticky-wrapper').css('left', leftAlign);
      } else {
        $('.sticky-wrapper').css('left', 0);
      }
    }
  };

  /**
   * Sticky Share Top Offset
   */
  window.tp_shareTopOffset = function() {
    $('article.node').each(function(index){
      if(index == 0) {
        if($(this).hasClass('node-feature-article')) {
          window.featureFirst = true;
          var stickyOffset = $(this).find('.author-teaser').offset().top + 10 - $(".main-content").offset().top;
        } else {
          window.featureFirst = false;
          var stickyOffset = $(".main-media").offset().top - $(".main-content").offset().top;
        }
        $('.sticky-wrapper').css('margin-top', stickyOffset - 7);
      }
    });
  };
})(jQuery, Drupal, this, this.document);
