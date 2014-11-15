// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {


  // To understand behaviors, see https://drupal.org/node/756722#behaviors
  Drupal.behaviors.mobileSocialNav = {
    attach: function(context, settings) {

      $('.mobile-social-wrapper .share').toggle(function(){
        $(this).addClass('active');
      }, function(){
        $(this).removeClass('active');
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
      $('.mobile-social-wrapper').removeClass('nav-hide').addClass('nav-show');
    } else {
      // Scroll Up
        $('.mobile-social-wrapper').removeClass('nav-show').addClass('nav-hide');
    }

    lastScrollTop = st;
  }




})(jQuery, Drupal, this, this.document);
