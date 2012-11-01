(function($) {
  Drupal.behaviors.tastemakersVenue = {
    attach: function(context) {
      var containerSelector = '.tastemakers.node-type-venue';
      
      // $(document).ready and after every ajax call
      var container = $(containerSelector);
      container.once('venue-js', _init);
      
      // $(document).ready only
      function _init(){
        // variables
        var element = $(this);
                      
        // on load
        $('.horizontal-tabs', container).prepend($('.field-name-field-name', container));
        
      }
    }
  };
})(jQuery);