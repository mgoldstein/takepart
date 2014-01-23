(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.pm_jwplayer = {
    attach: function() {
      $('.pm-jwplayer').once('initialized', function(index, element) {
        var element_id = $(element).attr('id');
        var settings = Drupal.settings.pm_jwplayer.configurations[element_id];
        var attribute = $(element).attr('data-allowed-regions');
        var regions = attribute ? attribute.split(',') : [];
        if (regions.length > 0) {
          var blockVideo = function() {
            $(element).addClass('blocked').removeClass('loading');
          };
          var handleResponse = function(response) {
            if (!response.country || !response.country.iso_code) {
              $(element).addClass('blocked').removeClass('loading');
              return false;
            }
            var code = response.country.iso_code.toLowerCase();
            if ($.inArray(code, regions) < 0) {
              $(element).addClass('blocked').removeClass('loading');
            }
            else {
              $(element).removeClass('loading');
              jwplayer.key = Drupal.settings.pm_jwplayer.key;
              jwplayer(element).setup(settings);
            }
          };
          geoip2.country(handleResponse, blockVideo);
        }
        else {
          jwplayer.key = Drupal.settings.pm_jwplayer.key;
          jwplayer(element).setup(settings);
        }
      });
    }
  };
})(jQuery, Drupal, this, this.document);
