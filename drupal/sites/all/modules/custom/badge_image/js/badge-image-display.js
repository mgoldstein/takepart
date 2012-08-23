var addthis_share = {};

(function ($) {
  Drupal.behaviors.loadBadgeImage = {
    attach: function (context, settings) {
      if (settings.badge_image) { 
        var sharing = settings.badge_image.display.sharing;
        addthis.update('config', 'ui_email_note', sharing.email);
        addthis.update('share', 'templates', {twitter:sharing.twitter});
        $('.addthis_button_facebook').each(function (index) {
          $(this).attr('addthis:url', sharing.url);    
        });
        $('.addthis_button_twitter').each(function (index) {
          $(this).attr('addthis:url', sharing.url);    
        });
        $('.addthis_button_pinterest_share').each(function (index) {
          $(this).attr('addthis:url', sharing.url);    
          $(this).attr('pi:pinit:media', sharing.pinterest);
        });
        $('.addthis_button_email').each(function (index) {
          $(this).attr('addthis:url', sharing.url);    
        });
        $('.badge-image-button-download').each(function (index) {
          $(this).attr('href', sharing.pinterest);    
        });
        $('.addthis_toolbox').each(function (index) {
          addthis.toolbox($(this));
        });
      }
    }
  };
})(jQuery);
