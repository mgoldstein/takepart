/**
 * @file
 * the tp4Sticky plugin.
 *
 * NOTE: This plugin uses the hard-coded ".footer-wrapper" class
 * as its default "lowest point" for sticky elements.
 */

(function ($, window, document, undefined) {
  $.fn.tp4Sticky = function(opts) {

    var defaults = {
      offset: 0,
      stopAt: '.footer-wrapper',
      wrapperClass: 'sticky-wrapper',
      stickyClass: 'sticky'
    },

    options = $.extend({}, defaults, opts);

    //overrides the stopat for fresh theme
    if ($('.fresh-content-wrapper').length !=0) {
      options.stopAt = '.footer';
    }

    return this.each(function(index) {
      //Add Sticky Share on page load only
      if ($('.sticky-wrapper').length != 0) {
        return;
      }
      var $stickyEl = $(this),
          $wrap = $stickyEl.wrap('<div class="' + options.wrapperClass +  '" />').parent().css('position', 'absolute'),
          $bottomEl = $(options.stopAt);

      var adjustWrapper = function() {
        $wrap.css({
          height: $stickyEl.outerHeight(true) + 'px',
          'float': $stickyEl.css('float')
        });
      };

      $(window).on('touchend touchmove scroll', function(e) {
        //Disable clicks of the share links when touch scrolling
        //This does it by adding a disable class
        //This should stop the Phantom Tumbler clicks
        if(e.type == 'touchmove') {
          $('.tp-social a').each(function(){
            $(this).addClass('disabled');
          });
        }
        if(e.type == 'touchend') {
          $('.tp-social a').each(function(){
            $(this).removeClass('disabled');
          });
        }

        //adding a conditional check to ensure that it doesn't stop the page.
        //this functionality may not be in used anymore.
        var bottom_el = ($bottomEl.offset() != null) ? $bottomEl.offset().top - $stickyEl.outerHeight(true) : $stickyEl.outerHeight(true);
        var isSticky = $stickyEl.hasClass(options.stickyClass),
            stickyElLowestPoint = bottom_el;

        //Check if the CIC banner is present then add an offset to where the scroll should start
        if($('body').hasClass('sticky-cic-nav')) {
          options.offset = 100;
        }

        // add/remove the sticky class
        // Check if close to the top
        // Check if in mobile state to prevent jumping mobile menu
        if ((window.scrollY > ($wrap.offset().top - options.offset))
          //Width is greater than 480px
          && (window.innerWidth > 480)
          //If no orientation meaning not tablet
          && ((typeof window.orientation == 'undefined')
            //OR landscape and the height is greater 500px
            || ((typeof window.orientation != 'undefined' && window.orientation != 0)
              && (window.innerHeight >= 499))
            //OR portrait and the width is within 480px
            || ((typeof window.orientation != 'undefined' && window.orientation == 0)
              && (window.innerWidth > 480))
          )
        ) {
          if (!isSticky) {
            adjustWrapper();
            isSticky || $stickyEl.addClass(options.stickyClass);
          }
        } else {
          if(isSticky) {
            $stickyEl.removeClass(options.stickyClass);
          }
        }

        if (isSticky && window.scrollY > stickyElLowestPoint) {
          $stickyEl.css('top', stickyElLowestPoint - window.scrollY);
        } else {
          $stickyEl.css('top', '');
        }
      }).on('resize', function() {
        $wrap.css({
          height: '',
          width: '',
          'float': ''
        });
      });
    });

  };
})(jQuery, this, this.document);
