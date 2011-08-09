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
          s.events='event37';
          s.tl(true, 'o', 'Take Action Button Click');
          $(this).html('Action Taken').addClass('action-taken');
        }
      );
    }
  };

}(jQuery));
