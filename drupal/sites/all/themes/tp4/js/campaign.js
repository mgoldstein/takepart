/**
 * @file
 * Scripts for Takepart Campaigns.
 */

(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.campaignSlideShows = {
    attach: function() {
      if (!$('body').is('.node-type-campaign-page')) {
        return;
      }

      //TODO: There is an error when testing videos with only 2 slides
      //swipejs duplicates slides if only two exist throwing an error with videos

      var $sliders = $('.slider');

      // setup slideshows
      $sliders.each(function() {
        // set up the slider
        var $this = $(this).Swipe({
          callback: function(index, slide) {
            $navLinks
              .filter('[data-slide=' + index % $navLinks.length + ']').addClass('active')
              .siblings('.active').removeClass('active')
            ;
          }
        });
        var slider = $this.data('Swipe');
        var $navLinks = $this.find('.slider-pagination a');

        // setup forward/back nav
        $this.find('.left-arrow').on('click', function() { slider.prev() });
        $this.find('.right-arrow').on('click', function() { slider.next() });

        // set up pagination -- active class and click event
        $navLinks.filter(':first').addClass('active')
          .parent().on('click', 'a', function(e) {
            e.preventDefault();
            slider.slide($(this).data('slide'));
          })
        ;
      }); // end $sliders.each()

      // deal with card padding
      var adjustCardHeightsAndPadding = function() {
        $sliders.each(function() {
          var $this = $(this);
          var titleHeight = $this.find('.tray-header').outerHeight();
          var multipleCards = $this.is('.has-multiple-cards');

          // Set all cards to equal height
          if (multipleCards) {
            $this.find('.swipe-wrap').each(function(){
              var $this = $(this);
              $this.find('.card-wrapper').css("height", $this.height());
            });
          }

          // if there is a tray title, set card padding
          // and contextual link position
          if (titleHeight > 0) {
            $this.find('.card .card-inner')
              .css("padding-top", titleHeight)
              .find('.contextual-links-wrapper')
                .css({
                  top: titleHeight + 2,
                  right: multipleCards ? 80 : 5
                })
            ;
          }
        });
      };

      // bind the previous function to window load and resize
      // debouncing for 300ms
      var resizeTimeout = null;
      $(window).on('load resize', function() {
        clearTimeout(resizeTimeout);
        resizeTimeout = setTimeout($.proxy(adjustCardHeightsAndPadding, this), 250);
      });
    }
  };

  Drupal.behaviors.campaignHeaderMenu = {
    attach: function() {
      if ($('body').is('.node-type-campaign-page')) {
        $('ul.sf-menu').superfish();
      }
    }
  };

})(jQuery, Drupal, this, this.document);
