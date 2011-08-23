(function ($) {
  // handle the click funciton on the take action button.
  Drupal.behaviors.TPactionClick = {
    attach: function (context, settings) {
      $('.node-action .field-name-field-action-url a', context).click(
        function(e) {
          //if it is marked as local we are just recording the hit
          if ($(this).attr('href') == '/local') {
            e.preventDefault();
          }
          s.linkTrackVars="eVar28,events";
          s.linkTrackEvents="event37";
          s.eVar28='tpaction'
          s.events='event37';
          s.tl(this.href, 'o', 'Take Action Button Click');
          $(this).html('Action Taken').addClass('action-taken');
          
        }
      );
    }
  };

}(jQuery));
