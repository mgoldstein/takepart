(function ($) {
  Drupal.behaviors.signaturePublicDisplay = {
    attach: function (context, settings) {

      // connect up the hiding and showing of the display claimer
      $('.signature-display-opt-in-field').click(function () {
        var parent_form = $(this).closest('form');
        if ($(this).is(':checked')) {
          $(parent_form).find('.signature-display-disclaimer').slideUp('fast');
        }
        else {
          $(parent_form).find('.signature-display-disclaimer').slideDown('fast');
        }
      });

      // set the initial state of the display disclaimer
      $('.signature-display-disclaimer').once('signature-init', function () {
        if ($('.signature-display-opt-in-field').is(':checked')) {
          $(this).hide();
        }
        else {
          $(this).show();
        }
      });
    }
  }
})(jQuery);
