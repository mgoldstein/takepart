function badgeImageAddThisShareListener (evt) {
};
function badgeImageTrackPinterestShare () {
  badgeImageAddThisShareListener({evt:{data:{service:'pinterest_share'}}});
};

(function ($) {
  Drupal.behaviors.badgeImageMetrics = {
    attach: function (context, settings) {
      $('body').once('addthis-init', function () {
        addthis.addEventListener('addthis.menu.share', badgeImageAddThisShareListener);
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
