/**
 * @file
 * the tp4Sticky plugin.
 *
 * NOTE: This plugin uses the hard-coded ".footer-wrapper" class
 * as its default "lowest point" for sticky elements.
 */

(function ($, Drupal, window, document, undefined) {
  $.fn.tp4Sticky = function(options) {

    return this.each(function(options) {

      var stickyEl = this,
          $stickyEl = $(this),
          stickyElOffset = $stickyEl.offset().top,
          stickyElHeight = $stickyEl.outerHeight(true),
          $doc = $(document),
          bottomElSelector = options.stopAt || '.footer-wrapper',
          $bottomEl = $(bottomElSelector);

      $(window).on('scroll', function(e) {
        var isSticky = $stickyEl.hasClass('sticky'),
            documentHeight = $doc.height(),
            stickyElLowestPoint = documentHeight - stickyElHeight - $bottomEl.outerHeight();

        // add/remove the sticky class
        if (window.scrollY > stickyElOffset) {
          isSticky || $stickyEl.addClass('sticky');
        } else {
          !isSticky || $stickyEl.removeClass('sticky');
        }

        if (isSticky && window.scrollY > stickyElLowestPoint) {
          $stickyEl.css('top', stickyElLowestPoint - window.scrollY);
        } else {
          $stickyEl.css('top', '');
        }
      });

    });

  };
})(jQuery, Drupal, this, this.document);

