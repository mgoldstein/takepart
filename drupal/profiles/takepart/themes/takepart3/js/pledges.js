(function($) {
  Drupal.behaviors.pledges = {
    attach: function(context) {
      // onLoad and onAjax
      var container = $('.node-pledge-action');
      container.once('node-pledge-action', _init);
      
      // onLoad only
      function _init(){
        // variables
        var element = $(this);
        var wycdLongContainter = $('.node-pledge-action .field-name-field-pledge-action-long');
        var wycdShortContainer = $('.node-pledge-action .field-name-field-pledge-action-short');
        var wycdMoreLabel = 'read more';
        var wycdLessLabel = 'read less';
                      
        // onLoad
        var wycdLink = $('<a href="javascript:void(0)">' + wycdMoreLabel + '</a>').addClass('wycdLink').insertAfter(wycdShortContainer);
        
        // bind actions
        element.bind('click', { self: self }, _click);
        
        // action handlers
        function _click(event){
          
          var self = event.data.self;
          var element = self.element;
          var options = self.options;
          var target = $(event.target);
          
          if (target.is('.wycdLink') || target.parents(".wycdLink").length) {
            target = target.is(".wycdLink") ? target : target.parents(".wycdLink");
            if (target.hasClass('more')){
              wycdShortContainer.hide();
              wycdLongContainter.show();
              target.removeClass('more').text(wycdLessLabel);
            } else {
              wycdLongContainter.hide();
              wycdShortContainer.show();
              target.addClass('more').text(wycdMoreLabel);
            }
          }
        };
      }
    }
  };
})(jQuery);