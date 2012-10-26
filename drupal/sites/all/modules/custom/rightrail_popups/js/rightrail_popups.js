// file: javascript support for rightrail_popups

/// add click trackers for popups and banner ads
(function ($) {
  Drupal.behaviors.rrPopups = {
    attach: function (context, settings) {
      $('.rr-preview .colorbox-inline').live('click', (function(){
        $('#cboxWrapper').css('height', '445px !important;');
      }));
    }
  }
})(jQuery);


