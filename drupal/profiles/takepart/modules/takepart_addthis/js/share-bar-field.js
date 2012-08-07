(function ($) {
  var addthisShareListener = function (evt) {
    var title = 'Unknown';
    if (evt.data.service == 'email') { title = 'Email'; }
    else if (evt.data.service == 'facebook') { title = 'Facebook'; }
    else if (evt.data.service == 'twitter') { title = 'Twitter'; }
    s.linkTrackVars = "eVar27,eVar30,events";
    s.linkTrackEvents = "event25";
    s.eVar27 = title;
    s.eVar30 = s.pageName;
    s.events = 'event25';
    s.tl(true, 'o', 'Content Share');
  };
  Drupal.behaviors.addthisField = {
    attach: function (context, settings) {
      // Configure the individual share bars.
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
        $('.addthis_toolbox', this).each(function () {
          addthis.toolbox(this, configuration, sharing);
        });
      });
      // Setup the share event listener.
      $('body').once('addthis-init', function () {
        addthis.addEventListener('addthis.menu.share', addthisShareListener);
      });
    }
  };
})(jQuery);
