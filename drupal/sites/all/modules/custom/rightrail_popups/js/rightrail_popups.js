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
            $('#colorbox').css('height', '455px');
            $('#cboxWrapper').css('height', '455px');
            $('#cboxContent').css('height', '455px');
            break;
        }
      });
    }
  }

// add click trackers for popups and banner ads
  Drupal.behaviors.scRightRailClick = {
    attach: function (context, settings) {
      // On click on embedded video to launch and play modal
      $('.rr-preview', context).click(function(){
        var n = $(this).attr('class').match(/ rr-(\w+)/);
        n = n[1];

        // alert('rr 41');
        var modaltitle = Drupal.settings.unipop.unipop_titles[n];
        var modaltype  = Drupal.settings.unipop.unipop_types[n];
        //alert('in rr41 n:' + n + ' modaltitle:' + modaltitle + ' modaltype:' + modaltype);

        s.linkTrackVars="eVar30, prop30, eVar40, prop40, eVar42, prop42, events";
        s.linkTrackEvents="event41";
        s.events='event41';
        s.prop30=s.pageName;
        s.eVar30=s.pageName;
        s.prop40=modaltype+':'+modaltitle;
        s.eVar40=modaltype+':'+modaltitle;
        s.prop42=modaltype;
        s.eVar42=modaltype;
        s.tl(true, 'o', 'Video Popup Click');
        //alert('rr-preview:' + n);
      });

      // On-click of the subscribe button, pls fire (only once per session)
      $('.rightrail-video-popup .subscribe', context).click(function(){
        if( typeof rr_43_triggered == 'undefined' ) {
          // block multiple calls
          rr_43_triggered = 1;

          // alert('rr 43');
          var n = $(this).attr('class').match(/ rr-(\w+)/);
          n = n[1];
          var modaltitle = Drupal.settings.unipop.unipop_titles[n];
          var modaltype  = Drupal.settings.unipop.unipop_types[n];
          //alert('in rr43 ' + n + ' modaltitle:' + modaltitle + ' modaltype:' + modaltype);

          s.linkTrackVars="eVar40, prop40, eVar41, prop41, events";
          s.linkTrackEvents="event43";
          s.events='event43';
          s.prop40=modaltype+':'+modaltitle;
          s.eVar40=modaltype+':'+modaltitle;
          s.prop41=s.pageName;
          s.eVar41=s.pageName;
          s.tl(true, 'o', 'Video Popup Click');
        }
      });
    }
  }
})(jQuery);
