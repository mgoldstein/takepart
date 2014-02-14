(function($, Drupal, undefined) {
  Drupal.behaviors.takepartCloudinarySupport = {
    attach: function() {
      // configure cloudinary
      $.cloudinary.config(Drupal.settings.cloudinary_support.config);
      // add data to form inputs
      $("input.cloudinary-fileupload[type=file]").data('form-data', Drupal.settings.cloudinary_support.file_field_data);
    }
  };
})(jQuery, Drupal);
