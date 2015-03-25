/**
 * @file
 * A JavaScript file for the theme.
 *
 */

(function ($, Drupal, window, document, undefined) {


Drupal.behaviors.mobileMenuToggle = {
  attach: function(context, settings) {

    var $body = $('body');
    $('.toggle-mobile-left').click(function(){

      if ($body.hasClass('mobile-menu-show')) {
        $body.removeClass("mobile-menu-show" );
      } else {
        $body.addClass("mobile-menu-show" );
      }
    });
  }
};

})(jQuery, Drupal, this, this.document);
