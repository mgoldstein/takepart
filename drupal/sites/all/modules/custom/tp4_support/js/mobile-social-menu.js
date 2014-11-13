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

  }
};


})(jQuery, Drupal, this, this.document);
