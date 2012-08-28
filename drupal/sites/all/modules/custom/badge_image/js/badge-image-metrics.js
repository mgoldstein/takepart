(function ($) {
  var addthisShareListener = function (evt) {
    var title = 'Unknown';
    if (evt.data.service == 'email') { title = "Email"; }
    else if (evt.data.service == 'facebook') { title = "Facebook"; }
    else if (evt.data.service == 'twitter') { title = "Twitter"; }
    else if (evt.data.service == 'pinterest_share') { title = "Pinterest"; }
    s.linkTrackVars = "eVar27,eVar30,events";
    s.linkTrackEvents = "event25";
    s.prop26 = title;
    s.eVar27 = title;
    s.eVar30 = s.pageName;
    s.events = "event25";
    s.tl(true, 'o', 'Content Share');
  };
  Drupal.behaviors.badgeImageMetrics = {
    attach: function (context, settings) {
      $('body').once('addthis-init', function () {
        addthis.addEventListener('addthis.menu.share', addthisShareListener);
      });
      if (settings.badge_image && settings.badge_image.metrics) {
        var latch = settings.badge_image.metrics.latch;
        if (jQuery.cookie(latch) != null) {
          s.linkTrackVars = "eVar30,events";
          s.linkTrackEvents = "event47";
          s.eVar30 = s.pageName;
          s.events = "event47";
          s.tl(true, 'o', 'badge creation');
          jQuery.cookie(latch, null, {path:'/'});
        }
      }
    }
  };
})(jQuery);
