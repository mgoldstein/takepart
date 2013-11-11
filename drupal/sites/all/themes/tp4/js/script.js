/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.my_custom_behavior = {
  attach: function(context, settings) {
    //prevent parent links on megamenu from linking on touch (link on double touch)
    $('#megamenu li.mega-item:has(.mega-content)').doubleTapToGo();

    //Toggle search on mobile
    $('html').click(function() {
      $('.search-toggle').parent().removeClass('active');
    });

    $('.search-toggle').parent().click(function(event){
        event.stopPropagation();
        $(this).addClass('active');
    });
  }
};
Drupal.behaviors.snapper_settings = {
  attach: function(context, settings) {
    var snapper = new Snap({
      element: document.getElementById('page-wrap')
    });

    snapper.settings({
      dragger: null,
      disable: 'none',
      addBodyClasses: true,
      hyperextensible: true,
      resistance: 0.5,
      flickThreshold: 50,
      transitionSpeed: 0.3,
      easing: 'ease',
      maxPosition: 280,
      minPosition: 0,
      tapToClose: true,
      touchToDrag: true,
      slideIntent: 40,
      minDragDistance: 5
    });
    
    $('.menu-toggle').on('click', function(){
        if( snapper.state().state=="left" ){
            snapper.close();
        } else {
            snapper.open('left');
        }
    });



  }
};


})(jQuery, Drupal, this, this.document);
