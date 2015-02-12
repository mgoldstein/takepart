// Social menu
/**
 * @file
 * Scripts social menu
 */
(function ($, Drupal, window, document, undefined) {

  /*
   * Social Menu Behaviors
   */
  Drupal.behaviors.socialMenuBehaviors = {
    attach: function(context, settings) {

      //trigger tp_initSocialMenu
      $(document).ready(function() {
        window.tp_initSocialMenu();

        $(window).smartresize(function() {
          console.log('test');
          window.tp_initSocialMenu();
        });
      });

    }
  }

  // To understand behaviors, see https://drupal.org/node/756722#behaviors
  Drupal.behaviors.mobileSocialNav = {
    attach: function(context, settings) {

      $('li.social h3').toggle(function(){
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
      $('.social-wrapper.mobile').removeClass('nav-hide').addClass('nav-show');
//      $('.social-wrapper.mobile').removeClass('nav-hide').addClass('nav-show'); // Nav Bar (reverse)
    } else {
      // Scroll Up
//      $('.social-wrapper.mobile').removeClass('nav-hide').addClass('nav-show');  // Nav Bar (reverse)
    }

    lastScrollTop = st;
  }

  window.tp_initSocialMenu = function() {
    var mobile = 480;
    var social_menu = $('.social-wrapper');

    //mobile
    if ($(window).width() <= mobile) {
      $(social_menu).addClass('mobile');
    }else{
      $(social_menu).removeClass('mobile');
    }

  }
})(jQuery, Drupal, this, this.document);