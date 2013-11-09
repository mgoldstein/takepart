/**
 * @file
 * Scripts for thetheme.
 */

(function ($, Drupal, window, document, undefined) {

/**
 * Megamenu Behaviors
 */
Drupal.behaviors.megaMenuBehaviors = {
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

/**
 * Settings for the snap.js library
 */
Drupal.behaviors.snapperSettings = {
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
      touchToDrag: false,
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
