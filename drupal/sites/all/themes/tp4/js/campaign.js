/**
 * @file
 * Scripts for Takepart Campaigns.
 */

(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.campaignSlideShow = {
    attach: function() {
      var count = $('.slider').length;
      for (var i=0; i<=count; i++){
        sliderID = '#slider_' + i;
        paginationID = '#pagination_' + i;
        window.mySwipe = new Swipe(document.getElementById('slider_' + i), {
          auto: 0,
          speed: 800,
          continuous: true,
          disableScroll: false,
          stopPropagation: false,
          callback: function(index, elem) {
            var i = paginationID.length; //Gets the number of items (em elements) in the var bullets.
            while (i--) {
              bullets[i].className = ' '; //Sets the inactive position indicators.
            }
            bullets[pos].className = 'on'; //Applies styling of .on to active position indicator.

          },
          transitionEnd: function(index, elem) {}
        });

        $('.slider').each(function(){
          var $this = $(this);
          var $Slider = $('#' + $this.attr('id')).Swipe().data('Swipe');
          $this.find('.left-arrow').on('click', function(){$Slider.prev()});
          $this.find('.right-arrow').on('click', function(){$Slider.next()}); 
        });
      }

      // Detect height on page load and on page resize
      window.onresize = function(event) {
          $('.slider').each(function(){
              var $this = $(this);
              $this.find('.card.has-tray-title').css("padding-top", $this.find('.tray-header').height() + 50);
          });
      };
        window.onload = function(event) {
          $('.slider').each(function(){
              var $this = $(this);
              $this.find('.card.has-tray-title').css("padding-top", $this.find('.tray-header').height() + 50);
          });
      };
    }
  };

})(jQuery, Drupal, this, this.document);
