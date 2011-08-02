(function ($) {
  // handle the click funciton on the take action button.
  Drupal.behaviors.TPactionClick = {
    attach: function (context, settings) {
      $('.node-action form#take-action #take-action-btn', context).click(
        function() {
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