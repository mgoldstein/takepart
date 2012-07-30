(function ($) {
  Drupal.behaviors.embedactionInit = {
    attach: function (context, settings) {
      $('div.embedaction-wrapper').each(function () {
        // Connect the 'Take Action' button and field promo headline
        $('div.embedaction-button', this).click({wrapper: this}, function (event) {
          var wrapper = event.data['wrapper'];
          event.preventDefault();
          $('div.embedaction-content:hidden', wrapper).slideDown('fast', function () {
            $('h2.embedaction-divider > a', wrapper).show();
          });
        });
        $('div.field-name-field-promo-headline', this).click({wrapper: this}, function (event) {
          var wrapper = event.data['wrapper'];
          event.preventDefault();
          $('div.embedaction-content:hidden', wrapper).slideDown('fast', function () {
            $('h2.embedaction-divider > a', wrapper).show();
          });
        });
        $('div.embedaction-button', this).hover(function () {
          $(this).siblings('div.field-name-field-promo-headline').css('color', '#1ca9e7');
        }, function () {
          $(this).siblings('div.field-name-field-promo-headline').css('color', '#000000');
        });
        // Connect the 'CLOSE' link
        $('h2.embedaction-divider > a', this).click({wrapper: this}, function (event) {
          var wrapper = event.data['wrapper'];
          event.preventDefault();
          $('div.embedaction-content', wrapper).slideUp('fast', function () {
            $('h2.embedaction-divider > a', wrapper).hide();
          });
        });
        // Set the initial state of the embedded action
        $('h2.embedaction-divider > a', this).hide();
        $('div.embedaction-content', this).hide();
      });
    }
  }
})(jQuery);
