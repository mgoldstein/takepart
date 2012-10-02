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
        $('.horizontal-tabs', container).prepend($('.field-name-field-venue-name', container));
        
        // bind actions
        element.bind('click', _click);
        
        // action handlers
        function _click(event){
          var element = this;
          var target = $(event.target);
          
          // show more / show less link click
          var firstSelectorAction = '.class';
          if (target.is(firstSelectorAction) || target.parents(firstSelectorAction).length) {
            target = target.is(firstSelectorAction) ? target : target.parents(firstSelectorAction);

          }
        };
      }
    }
  };
})(jQuery);