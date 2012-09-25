(function($) {
  Drupal.behaviors.pledges = {
    attach: function(context) {
      // $(document).ready and after every ajax call
      var container = $('.node-pledge-action');
      container.once('node-pledge-action', _init);
      
      // $(document).ready only
      function _init(){
        // variables
        var element = $(this);
        var wycdLongContainter = $('.node-pledge-action .field-name-field-pledge-action-long');
        var wycdShortContainer = $('.node-pledge-action .field-name-field-pledge-action-short');
        var wycdMoreLabel = 'Read more.';
        var wycdLessLabel = 'Read less.';
                      
        // on load
        var wycdLink = $('<a href="javascript:void(0)">' + wycdMoreLabel + '</a>').addClass('wycdLink').insertAfter(wycdShortContainer);
        
        // bind actions
        element.bind('click', { self: self }, _click);
        
        // action handlers
        function _click(event){
          var self = event.data.self;
          var element = self.element;
          var options = self.options;
          var target = $(event.target);
          
          // show more / show less link click
          if (target.is('.wycdLink') || target.parents(".wycdLink").length) {
            target = target.is(".wycdLink") ? target : target.parents(".wycdLink");
            if (!target.hasClass('less')){
              wycdShortContainer.hide();
              wycdLongContainter.show();
              target.addClass('less').text(wycdLessLabel);
            } else {
              wycdLongContainter.hide();
              wycdShortContainer.show();
              target.removeClass('less').text(wycdMoreLabel);
            }
          }
        };
      }
    }
  };
})(jQuery);