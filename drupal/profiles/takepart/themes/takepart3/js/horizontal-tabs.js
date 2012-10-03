(function($) {
  Drupal.behaviors.horizontalTabsCustom = {
    attach: function(context) {
      // $(document).ready and after every ajax call
      var containerSelector = '.horizontal-tabs';
      var container = $(containerSelector);
      container.once(containerSelector + '-js', _init);      
      
      // $(document).ready only
      function _init(){
        // variables
        var container = $(this);
        
        // horizontal-tabs-panes wrapper height adjustments
        $('.horizontal-tabs-panes', container).each(function (index) {
          // Find the tab that defines the height
          var sourceWrapper = $('fieldset.same-height-source > .fieldset-wrapper', this);
          if (sourceWrapper.length <= 0) { // if no source, break
            return;
          }
          var sourceHeight = sourceWrapper.height();
          
          // Adjust the other tabs to that height
          var otherTabs = $('fieldset.same-height-adjust > .fieldset-wrapper', this);
          otherTabs.each(function (index) {
            if ($(this).height() > sourceHeight) {
              $(this).height(sourceHeight);
              $(this).css('overflow-y', 'scroll');
            }
          });
        });
        
      }
    }
  };
})(jQuery);
