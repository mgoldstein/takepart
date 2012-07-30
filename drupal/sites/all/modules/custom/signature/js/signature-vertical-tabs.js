(function ($) {
  Drupal.behaviors.signatureFieldsetSummaries = {
    attach: function (context) {
      $('fieldset.edit-signature', context).drupalSetSummary(function(context) {
        if($('#edit-signature-type').val().length > 0) {
          return $('#edit-signature-type option:selected').html();
        }
        else {
          return Drupal.t('No Signature');
        }
      });
    }
  };
})(jQuery);
