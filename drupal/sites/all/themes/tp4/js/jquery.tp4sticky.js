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

    return this.each(function(index) {

      var $stickyEl = $(this),
          $wrap = $stickyEl.wrap('<div class="' + options.wrapperClass +  '" />').parent().css('position', 'static'),
          $bottomEl = $(options.stopAt);

      var adjustWrapper = function() {
        $wrap.css({
          height: $stickyEl.outerHeight(true) + 'px',
          width: $stickyEl.outerWidth(true) + 'px',
          'float': $stickyEl.css('float')
        });        
      };

      $(window).on('scroll', function(e) {
        var isSticky = $stickyEl.hasClass(options.stickyClass),
            stickyElLowestPoint = $bottomEl.offset().top - $stickyEl.outerHeight(true);

        // add/remove the sticky class
        if (window.scrollY > ($wrap.offset().top - options.offset)) {
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
