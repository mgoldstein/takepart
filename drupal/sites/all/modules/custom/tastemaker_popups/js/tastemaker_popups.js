// file: javascript support for tastemaker_popups


(function ($) {
  Drupal.behaviors.tastemakerPopups = {
    attach: function (context, settings) {
      $('.video-thumb-table .vid-arrow').live('click', (function(){
        vidpopSource = 'tastemaker';
      }));

      // resize popup, based on source
      $(document).bind('cbox_complete', function(){
        switch(vidpopSource) {
          case 'tastemaker':
            $('#colorbox').css('height', '440px');
            $('#cboxWrapper').css('height', '440px');
            $('.vidmap iframe body').css('height', '400px');
            break;
        }
      });
    }
  }
})(jQuery);


