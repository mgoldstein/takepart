(function ($) {
  Drupal.behaviors.ideasforgood = {
    attach: function (context, settings) {
      if ($('#ideasforgood-share-bar').length) {
        $('#ideasforgood-share-bar').once('ideasforgood', function() {
          window.addthis.toolbox('#ideasforgood-share-bar');
        });
      }
    }
  };
})(jQuery);
