/**
 * @file
 * A JavaScript file for the theme.
 *
 */

(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.mobileMenuToggle = {
    attach: function(context, settings) {

      var $body = $('body');
      $('.toggle-menu.toggle-left, .left-drawer-control .i-close-x').click(function(){
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
          if ($('body.node-type-feature-article').length != 0) {
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
          $('#header .toggle-search').click(function(){
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

  Drupal.behaviors.mobileMenuBehaviors = {
    attach: function(context, settings) {
      /* TODO: TP4 is unexpectedly dependent on the menu being 'exposed'.  Remove this dependency and use classes
      that come with Drupal */

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
        }
      });
    }
  }

  /* Position stick share Done here to not bother tp4 */
  $('document').ready(function(){
    window.featureFirst = false;
    window.tp_shareTopOffset();
    window.tp_shareLeftAlign();
    $(window).resize(function(){
      window.tp_shareTopOffset();
      window.tp_shareLeftAlign();
    });

    //Give the sticky share a fighting chance to load
    setTimeout(function(){$('.social').show();window.tp_shareTopOffset();window.tp_shareLeftAlign();},200);
  });

  /**
   *  @function:
   *    Function copied from tp_ad_takeover.jquery.js
   */
  window.tp_ad_takeover = function(bgcolor, bgimage, link) {
    //do not do on Feature Articles
    if(typeof $('.fresh-content-wrapper') != 'undefined' && $('.fresh-content-wrapper').hasClass('feature_article-wrapper') == false) {
      var $body = jQuery('body');
      var $a = jQuery('<a id="tp_ad_takeover" href="' + link + '" target="_blank"></a>');

      $body.css({
        background: bgcolor + ' url("' + bgimage + '") center top no-repeat',
        backgroundAttachment: 'fixed'
      }).addClass('tp_ad_takeover');

      $a.css({
        position: 'fixed',
        height: '100%',
        width: '100%',
        left: 0,
        top: 0,
        zIndex: 0
      });

      jQuery('body #footer-wrapper').after($a);

      //only do on fresh theme
      if ($('.fresh-content-wrapper').length != 0) {

        jQuery('body #footer-wrapper').after($a);
        //variables
        var background_image = new Image();
        background_image.src = bgimage;

        //checks to see if the image is loaded
        if (background_image.complete) {
          var background_image_height = background_image.height;
          takeover_ad(background_image_height);
        }
        //otherwise load image and then call function
        else {
          $(background_image).load(function() {
            var background_image_height = background_image.height;
            takeover_ad(background_image_height);
          });
        }

        //triggers a scroll so the background takeover will go in place
        $(window).scroll();
      }
    }
  };

  /**
   *  @function:
   *    Function is used to update the article only if on fresh
   */
  window.takeover_ad = function(background_image_height) {
    //ensures that the height is defined
    if (background_image_height != undefined) {
      //binds a window scroll
      $(window).bind('scroll', function() {
        //variables
        var first_article = $('article:first').offset();
        var window_top = $(window).scrollTop();
        var window_bottom = $(window).height() + window_top;
        first_article.bottom = first_article.top + $('article:first').height();
        var background_pos = first_article.bottom - background_image_height;
        $takeover_ad = $('#tp_ad_takeover');

        //updates the background position
        if (window_bottom > first_article.bottom) {
          $('body').css('background-attachment', 'scroll');
          $('body').css('background-position', 'center ' + background_pos + 'px');
          $takeover_ad.css('position', 'absolute');
          $takeover_ad.css('top', background_pos);
        }
        else {
          $('body').css('background-attachment', 'fixed');
          $('body').css('background-position', 'center top');
          $takeover_ad.css('position', 'fixed');
          $takeover_ad.css('top', 0);
        }

      });
    }
  };


  Drupal.behaviors.scrollUp = {
    attach: function(context, settings) {
      var lastScrollTop = 0;
      window.scrollUp = false;
      $(window).scroll(function(event){
         var st = $(this).scrollTop();
         if (st > lastScrollTop){
           window.scrollUp = false;
         } else {
           window.scrollUp = true;
         }
         lastScrollTop = st;
      });
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
        $('#page-wrapper').prepend(markup);
        $('.tou-close').click(function() {
          $('.tou-alert').slideUp('slow');
        });
      }
    }
  };

})(jQuery, Drupal, this, this.document);
