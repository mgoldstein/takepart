(function($) {
  Drupal.behaviors.tastemakersNationwide = {
    attach: function(context) {
      var containerSelector = '.tastemakers.nationwide';
      
      // $(document).ready and after every ajax call
      var container = $(containerSelector);
      container.once('tastemakersNationwide-js', _init);
      
      // $(document).ready only
      function _init(){
        // variables
        var container = $(this);
                      
        // on load
        $('.stores li:nth-child(odd)', container).addClass('odd');
        
        // bind actions
        container.bind('click', _click);
        
        // action handlers
        function _click(event){
          var container = this;
          var target = $(event.target);
          
          // show more / show less link click
          var firstSelectorAction = '.city-plate';
          if (target.is(firstSelectorAction) || target.parents(firstSelectorAction).length) {
            target = target.is(firstSelectorAction) ? target : target.parents(firstSelectorAction);
            var cityBlock = target.parents('.city-block');
            var stores = cityBlock.find('.stores');
            cityBlock.toggleClass('expanded');
            stores.toggle('blind');
          }
        };
      }
    }
  };
})(jQuery);