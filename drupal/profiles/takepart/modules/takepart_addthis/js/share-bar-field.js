(function ($) {
  var addthisShareListener = function (evt) {
  };
  Drupal.behaviors.addthisField = {
    attach: function (context, settings) {
      // Configure the individual share bars.
      $('div.share-bar-field').once('addthis-init', function () {
        var id = $(this).attr('id');
        if (id in settings.addthis.fields) {
          var configuration = {
            ui_email_note: settings.addthis.fields[id].email_message,
            ui_email_from: settings.addthis.email
          };
          var sharing = {
            templates: {
              twitter: settings.addthis.fields[id].twitter_message
            }
          };
          if (settings.addthis.fields[id].alternate_url.length > 0) {
            sharing['url'] = settings.addthis.fields[id].alternate_url;
          }
          $('.addthis_toolbox', this).each(function () {
            addthis.toolbox(this, configuration, sharing);
          });
        }
      });
      // Setup the share event listener.
      if (window.addthis) {
        if ($('.share-bar-field.display-type-full-page').length > 0) {
          $('body').once('addthis-init', function () {
            window.addthis.addEventListener('addthis.menu.share',
              addthisShareListener);
          });
        }
      }
    }
  };
})(jQuery);
