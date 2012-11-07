(function ($) {
  var takeactionThankYouShareListener = function (evt) {
    var title = 'Unknown';
    console.log(evt.data);
    console.log(Drupal.settings.takeaction);
  };
  Drupal.behaviors.addthisField = {
    attach: function (context, settings) {
      // Setup the share event listener.
      if (window.addthis) {
        $('body').once('addthis-init', function () {
          window.addthis.addEventListener('addthis.menu.share',
            takeactionThankYouShareListener);
        });
      }
    }
  };
})(jQuery);

