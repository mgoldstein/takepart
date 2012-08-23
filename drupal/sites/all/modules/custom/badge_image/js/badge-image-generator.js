(function ($) {
  Drupal.behaviors.badgeImagePreview = {
    attach: function (context, settings) {
      if (settings.badge_image) {
        $('.badge-image-generator').each(function (index) {
          var height = settings.badge_image.preview.height
            - settings.badge_image.preview.offset_y;
          $('.badge-image-preview', this).css({
            'font-size': settings.badge_image.preview.font_size + 'px',
            'padding-top': settings.badge_image.preview.offset_y + 'px',
            'text-align': 'center',
            'height': height + 'px',
            'line-height': settings.badge_image.preview.font_size + 'px',
          });
        });
        setInterval(function () {
          $('.badge-image-generator').each(function (index) {
            var text = $('.badge-image-text-input', this).val();
            $('.badge-image-preview', this).text(text.toUpperCase());
          });  
        }, 100);
      }
    }
  };
})(jQuery);
