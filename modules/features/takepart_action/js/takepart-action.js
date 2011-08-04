(function ($) {
  // handle the click funciton on the take action button.
  Drupal.behaviors.TPactionClick = {
    attach: function (context, settings) {
      $('.node-action form#take-action #take-action-btn', context).click(
        function() {
          s.events='event37';
          s.tl(true, 'o', 'Take Action Button Click');

          if(typeof settings.TPactionClick.action_url != 'undefined') {
            window.location = settings.TPactionClick.action_url;
          }
          else {
            $(this).val('Action Taken').addClass('action-taken');
          }
        }
      );
    }
  };

}(jQuery));