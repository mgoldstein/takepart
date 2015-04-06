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
  };

})(jQuery, Drupal, this, this.document);
