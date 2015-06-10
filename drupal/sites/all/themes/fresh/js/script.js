/**
 * @file
 * A JavaScript file for the theme.
 *
 */

(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.mobileMenuToggle = {
    attach: function(context, settings) {

      var $body = $('body');
      $('.toggle-menu.toggle-left').click(function(){

        if ($body.hasClass('mobile-menu-show')) {
          $body.removeClass("mobile-menu-show" );
        } else {
          $body.addClass("mobile-menu-show" );
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
        if($(window).width() < 481){
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

  /**
   *  @function:
   *    Function copied from tp_ad_takeover.jquery.js
   */
  window.tp_ad_takeover = function(bgcolor, bgimage, link) {
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
    
    //only do on fresh theme with article-wrapper
    if ($('.article-wrapper').length !== 0) {
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
  
})(jQuery, Drupal, this, this.document);
