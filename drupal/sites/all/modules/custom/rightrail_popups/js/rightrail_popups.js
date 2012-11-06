// file: javascript support for rightrail_popups


(function ($) {
  Drupal.behaviors.rrPopups = {
    attach: function (context, settings) {
      $('.rr-preview .colorbox-inline').live('click', (function(){
      // click on rt rail popup
        vidpopSource = 'rtrail';
      }));
     }
  }
})(jQuery);


