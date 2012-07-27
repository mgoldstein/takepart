// click on "participant films" button to right of main menu in header
// ticket #29546
(function($) {
  Drupal.behaviors.participantPulldown = {
    attach: function(context) {
      $('#participant-pulldown .pp-button').click(function() {
        $('#participant-pulldown .inner').toggle();
        return false;
      });
    }
  };
})(jQuery);

