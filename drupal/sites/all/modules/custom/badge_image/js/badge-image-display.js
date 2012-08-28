var addthis_share = {};

(function ($) {
  Drupal.behaviors.loadBadgeImage = {
    attach: function (context, settings) {
      if (settings.badge_image) { 
        var sharing = settings.badge_image.sharing;
        addthis.update('config', 'ui_email_note', sharing.email.message);
        addthis.update('share', 'templates', {twitter:sharing.twitter.message});
        $('.addthis_button_facebook').each(function (index) {
          $(this).attr('addthis:url', sharing.facebook.url);    
        });
        $('.addthis_button_twitter').each(function (index) {
          $(this).attr('addthis:url', sharing.twitter.url);    
        });
        $('.addthis_button_pinterest_share').each(function (index) {
          $(this).attr('pi:pinit:url', sharing.pinterest.url);    
          $(this).attr('pi:pinit:media', sharing.pinterest.media);
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
      }
    }
  };
})(jQuery);
