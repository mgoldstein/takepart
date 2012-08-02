// click on "participant films" button to right of main menu in header
// ticket #29546
(function($) {
  Drupal.behaviors.participantPulldown = {
    attach: function(context) {
      $('#participant-pulldown').mouseover(function() {
        $('#participant-pulldown .inner').show();
        $('#participant-pulldown .pp-button').addClass('pp-button-hover');
        return false;
      });
      $('#participant-pulldown').mouseout(function() {
        $('#participant-pulldown .inner').hide();
        $('#participant-pulldown .pp-button').removeClass('pp-button-hover');
        return false;
      });
    }
  };
})(jQuery);

