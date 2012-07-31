(function ($) {

  var addthisShareListener = function (evt) {
    alert('here');
  };

  Drupal.behaviors.addthisField = {
    attach: function (context, settings) {

      // configure the individual share bars
      $('div.share-bar-field').once('addthis-init', function () {
        var id = $(this).attr('id');
        var configuration = {
          ui_email_note: settings.addthis.fields[id].email_message
        };
        var sharing = {
          templates: {
            twitter: settings.addthis.fields[id].twitter_message
          }
        };
        if (settings.addthis.fields[id].alternate_url.length > 0) {
          sharing['url'] = settings.addthis.fields[id].alternate_url;
        }
        $(this).find('.addthis_toolbox').each(function () {
          addthis.toolbox(this, configuration, sharing);
        });
      });

      // setup the share event listener
      $('body').once('addthis-init', function () {
        addthis.addEventListener('addthis.menu.share', addthisShareListener);
      });
    }
  };
})(jQuery);
