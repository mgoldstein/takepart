// file: javascript support for tastemaker_popups


(function ($) {
  Drupal.behaviors.tastemakerPopups = {
    attach: function (context, settings) {
      $('#video-popup-grid table.video-thumb-table .vid-arrow').live('click', (function(){
        vidpopSource = 'tastemaker';
      }));

      // resize popup, based on source
      $(document).bind('cbox_complete', function() {
        switch(vidpopSource) {
          case 'tastemaker':
            $('#colorbox').css('height', '445px');
            $('#cboxWrapper').css('height', '445px');
            $('#cboxContent').css('height', '445px');
            break;
        }
      });
    }
  }
})(jQuery);


