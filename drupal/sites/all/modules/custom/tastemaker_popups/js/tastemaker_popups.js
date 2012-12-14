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


// we do it this instead of using a behavior, as on similar pages, because of
// binding problems due to the page being considered loaded before the
// javascript in the body tag is executed

// click handler for thumbnails
//
// n = nid of video node
function tastemakerPopupsClick(n) {
  var modaltitle = Drupal.settings.unipop.unipop_titles[n];
  var modaltype  = Drupal.settings.unipop.unipop_types[n];
  //alert('in rr41-tpt n:' + n + ' modaltitle:' + modaltitle + ' modaltype:' + modaltype);

  //alert('tm 41');
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
}


// click handler for popup subscribe link
//
// n = nid of video node
function tastemakerPopupsSubscribe(n) {
  if( typeof tmp_43_triggered == 'undefined' ) {
    // block multiple calls
    tmp_43_triggered = 1;
    //alert('tm 43');

    var modaltitle = Drupal.settings.unipop.unipop_titles[n];
    var modaltype  = Drupal.settings.unipop.unipop_types[n];
    //alert('in tpt43 ' + n + ' modaltitle:' + modaltitle + ' modaltype:' + modaltype);

    s.linkTrackVars="eVar40, prop40, eVar41, prop41, events";
    s.linkTrackEvents="event43";
    s.events='event43';
    s.prop40=modaltype+':'+modaltitle;
    s.eVar40=modaltype+':'+modaltitle;
    s.prop41=s.pageName;
    s.eVar41=s.pageName;
    s.tl(true, 'o', 'Video Popup Click');
  }
}
