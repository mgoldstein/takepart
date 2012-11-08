// file: javascript support for rightrail_popups


(function ($) {
  Drupal.behaviors.rrPopups = {
    attach: function (context, settings) {
      $('.rr-preview .colorbox-inline').live('click', (function(){
      // click on rt rail popup
        vidpopSource = 'rtrail';
      }));

      // resize popup, based on source
      $(document).bind('cbox_complete', function(){
        //alert(vidpopSource);
        switch(vidpopSource) {
          case 'rtrail':
            $('#cboxWrapper').css('height', '445px');
            break;
        }
      });
    }
  }
})(jQuery);
