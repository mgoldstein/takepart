var addthis_share = {};

(function ($) {

  var loadPinterestFiles = function (d) {
    var script = d.createElement('SCRIPT');
    script.type = 'text/javascript';
    script.async = true;
    script.src = '//assets.pinterest.com/js/pinit.js';
    var first = d.getElementsByTagName('SCRIPT')[0];
    first.parentNode.insertBefore(script, first);
  }

  $(document).ready(function () {
    if (Drupal.settings.badge_image) {
      var sharing = Drupal.settings.badge_image.sharing;
      $('.pin-it-button').each(function (index) {
        var href  = 'http://pinterest.com/pin/create/button/'
         + '?url=' + encodeURIComponent(sharing.pinterest.url)
         + '&media=' + encodeURIComponent(sharing.pinterest.media)
         + '&description=' + encodeURIComponent(sharing.pinterest.message)
        $(this).attr('href', href);
      });
      loadPinterestFiles(document);
    }
  });

  Drupal.behaviors.loadBadgeImage = {
    attach: function (context, settings) {
      if (settings.badge_image) { 
        var sharing = settings.badge_image.sharing;
        $('.addthis_button_facebook').each(function (index) {
          $(this).attr('addthis:url', sharing.facebook.url);    
        });
        $('.addthis_button_twitter').each(function (index) {
          $(this).attr('addthis:url', sharing.twitter.url);    
        });
        $('.addthis_button_email').each(function (index) {
          $(this).attr('addthis:url', sharing.email.url);    
        });
        $('.badge-image-button-download').each(function (index) {
          $(this).attr('href', settings.badge_image.download.href);    
        });
        $('.badge-image-button-print').each(function (index) {
          $(this).click(function (event) {
            event.preventDefault();
            var w = settings.badge_image.print.width + 100;
            var h = settings.badge_image.print.height + 60;
            var attr = "menubar=0,location=0,height=" + h + ",width=" + w;
            var popup = window.open('','Print Badge', attr);
            var img = $('.badge-image-display')[0];
            $(img).clone().appendTo(popup.document.body);
            popup.print();
          });
        });
        addthis.toolbox('.addthis_toolbox');
        addthis.update('config', 'ui_email_note', sharing.email.message);
        addthis.update('share', 'templates', {twitter:sharing.twitter.message});
      }
    }
  };
})(jQuery);
