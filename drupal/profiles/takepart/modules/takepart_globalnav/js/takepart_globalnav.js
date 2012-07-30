// click on "participant films" button to right of main menu in header
// ticket #29546
(function($) {
  Drupal.behaviors.participantPulldown = {
    attach: function(context) {
      $('#participant-pulldown').mouseover(function() {
        $('#participant-pulldown .inner').show();
        return false;
      });
      $('#participant-pulldown').mouseout(function() {
        $('#participant-pulldown .inner').hide();
        return false;
      });
    }
  };
})(jQuery);

