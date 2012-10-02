(function($) {
  Drupal.behaviors.venue = {
    attach: function(context) {
      var containerSelector = '.node-venue';
      
      // $(document).ready and after every ajax call
      var container = $(containerSelector);
      container.once(containerSelector + '-js', _init);
      
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