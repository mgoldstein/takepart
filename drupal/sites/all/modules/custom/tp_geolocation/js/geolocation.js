(function($, Drupal, window, document, undefined) {

  /**
   * Store user's country in a cookie to comply with
   * Canada's CAN-SPAM law.
   * @see https://jira.takepart.com/browse/TP-1812
   */
  Drupal.behaviors.blameCanada = {
    attach: function() {
      var countryCookieName = 'tp_countryISOCode';

      // bail if the cookie is already set
      if (document.cookie.indexOf(countryCookieName) > -1) return;

      geoip2.country(function(geoIPData) {
        var expiresDate = new Date(Date.now() + 14*24*60*60*1000);
        document.cookie = countryCookieName
          + '=' + encodeURIComponent(geoIPData.country.iso_code)
          + ';path=/'
          + ';domain=.takepart.com'
          + ';expires=' + expiresDate.toUTCString()
        ;
      });
    }
  };

})(jQuery, Drupal, this, this.document);
