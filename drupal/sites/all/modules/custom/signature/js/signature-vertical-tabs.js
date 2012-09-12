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
      $('fieldset.edit-signature-newsletters', context).drupalSetSummary(
        function(context) {
          var count = 0;
          $('.signature-newsletter-label').each(function (index) {
            if ($(this).val().length > 0) { count += 1; }
          });
          if (count == 0) {
            return Drupal.t('No newsletter opt-ins');
          }
          else if (count == 1) {
            return Drupal.t('1 newsletter opt-in');
          }
          return Drupal.t(count + ' newsletter opt-ins');
        }
      );
    }
  };
})(jQuery);
