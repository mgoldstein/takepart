/**
 * @file
 * Scripts for Takepart Campaigns.
 */

(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.campaignSlideShow = {
    attach: function() {
      var count = $('.slider').length;
      for (var i=0; i<=count; i++){
        console.log(i);
        window.mySwipe = new Swipe(document.getElementById('slider_' + i), {
          auto: 5000,
          continuous: true,
          disableScroll: false,
          stopPropagation: false,
          callback: function(index, elem) {},
          transitionEnd: function(index, elem) {}
        });
      }
    }
  };

})(jQuery, Drupal, this, this.document);
