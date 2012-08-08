(function ($) {
  $.fn.sameSizeTabs = function () {
    $('.horizontal-tabs-panes', this).each(function (index) {
      // Find the tab that defines the height
      var height = 0;
      $('fieldset.same-height-source > .fieldset-wrapper', this).each(function (index) {
        height = $(this).height();
      });
      // Adjust the other tabs to that height
      if (height > 0) {
        $('fieldset.same-height-adjust > .fieldset-wrapper', this).each(function (index) {
          if (($this).height() > height) {
            $(this).height(height);
            $(this).css('overflow-y', 'scroll');
          }
        });
      }
    });
  };
})(jQuery);
