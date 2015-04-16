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

  })(jQuery, Drupal, this, this.document);
