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
    attach: function() {
      var $body = $('body'),
      isOpenpublishArticle = $body.is('.page-node.node-type-openpublish-article'),
      isFeatureArticle = $body.is('.page-node.node-type-feature-article'),
      isVideoArticle = $body.is('.page-node.node-type-video'),
      isVideoPlaylist = $body.is('.page-node.node-type-video-playlist'),
      isFlashcard = $body.is('.page-node.node-type-flashcard'),
      isCampaignPage = $body.is('.node-type-campaign-page'),
      isGallery = $body.is('.node-type-openpublish-photo-gallery');


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
              text: '{{title}}',
              via: 'TakePart'
            },
            {
              name: 'mailto'
            },
            {
              name: 'googleplus'
            },
            {
              name: 'tumblr'
            },
            {
              name: 'pinterest'
            },
            {
              name: 'reddit'
            }
          ]
        };

        /* If page is a gallery, article or featured article, add Pinterest */
        if(isGallery || isFeatureArticle || isOpenpublishArticle){
          main_image = $('.field-name-field-article-main-image').find('img').attr('src');
//          tp_social_config.services.push({"name":"pinterest", "media": main_image});
        }
        /* If page is a campaign page, remove mailto, reddit and tumblr */
        if(isCampaignPage){
          console.log(tp_social_config.services);
          delete tp_social_config.services[2]; //mailto
          delete tp_social_config.services[6]; //reddit
          delete tp_social_config.services[4]; //tumblr
          delete tp_social_config.services[5]; //pinterest
        }
				
        //alters the config for the services based on content type
        if ($('body').hasClass('node-type-openpublish-photo-gallery')) {
          delete tp_social_config.services[4];
        }
        else {
          delete tp_social_config.services[5];
        }
        
        //always remove reddit as it's not needed
				delete tp_social_config.services[6]; //reddit

        /* Make sticky when screensize is greater than 768px */
          $.when($('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config)).done(function() {
            if($(window).width() > 980){
              $('.social-vertical.stick').tp4Sticky({offset: isFlashcard ? 0 : 7});
            }
            });

    }
  };

  /*
   * Social Menu Behaviors
   */
  Drupal.behaviors.socialMenuBehaviors = {
    attach: function(context, settings) {

      //trigger tp_initSocialMenu
      $(document).ready(function() {
        window.tp_initSocialMenu();

        $(window).smartresize(function() {
          window.tp_initSocialMenu();
        });
      });

    }
  }

  // To understand behaviors, see https://drupal.org/node/756722#behaviors
  Drupal.behaviors.mobileSocialNav = {
    attach: function(context, settings) {

      $('li.share h3').toggle(function(){
        $(this).parents('.social-wrapper').addClass('sharing');
      }, function(){
        $(this).parents('.social-wrapper').removeClass('sharing');
      });


      // Show the mobile social nav bar when window scrolls down
      var didScroll;
      $(window).scroll(function(event){
        didScroll = true;
      });

      setInterval(function() {
        if (didScroll && $(window).width() < 768) {
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
    if(Math.abs(lastScrollTop - st) <= delta)
      return;

    if (st > lastScrollTop){
      // Scroll Down
//      $('.social-wrapper.mobile').removeClass('nav-hide').addClass('nav-show');
      $('.header-wrapper.mobile').removeClass('nav-show').addClass('nav-hide'); // Nav Bar (reverse)
    } else {
      // Scroll Up
      $('.header-wrapper.mobile').removeClass('nav-hide').addClass('nav-show');  // Nav Bar (reverse)
    }

    lastScrollTop = st;
  }

  window.tp_initSocialMenu = function() {
    var mobile = 480;
    var social_menu = $('.social-wrapper');
    var main_menu = $('.header-wrapper');

    //mobile
    if ($(window).width() <= mobile) {
      $(social_menu).addClass('mobile');
      $(main_menu).addClass('mobile');
    }else{
      $(social_menu).removeClass('mobile');
      $(main_menu).removeClass('mobile');
    }

  }
})(jQuery, Drupal, this, this.document);