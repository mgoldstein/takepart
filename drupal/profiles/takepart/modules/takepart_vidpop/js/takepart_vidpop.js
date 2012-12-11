// file: javascript support for takepart_vidpop

// On page view of a page with an embedded video
//
// triggered by call in template.php, preprocess node
// doesn't work here as a behavior, like the others

var vp_embeddedvideotitle;
var vp_embeddedvideotype;

var vp_titles = new Array();   // list of titles
var vp_types  = new Array();   // list of node types
var vp_lookup = new Array();   // 0-based index lookup of title/types index

var vidpopSource = 0;          // source of popup (node, rtrail)


function vidpop_loaded() {
  vp_embeddedvideotitle = Drupal.settings.takepart_vidpop.embeddedvideotitle;
  vp_embeddedvideotype  = Drupal.settings.takepart_vidpop.embeddedvideotype;


  // there may be more than one embedded video on a page; send codes for each one
  // collect passed titles and types
  // event40 is called first, and sets these for other events as globals
  var lookup_index = 0;

  jQuery.each(vp_embeddedvideotitle, function(i, val){
    vp_titles[i] = val;
    vp_lookup[lookup_index] = i;
    lookup_index++;
  });

  jQuery.each(vp_embeddedvideotype, function(i, val){
    vp_types[i] = val;
  });

  for (i=0; i < lookup_index; i++) {
    var li = vp_lookup[i];
    var modaltitle = vp_titles[li];
    var modaltype  = vp_types[li];
    s.linkTrackVars="eVar30, prop30, eVar40, prop40, eVar42, prop42, events";
    s.linkTrackEvents="event40";
    s.events='event40';
    s.prop30=s.pageName;
    s.eVar30=s.pageName;
    s.prop40=modaltype+':'+modaltitle;
    s.eVar40=modaltype+':'+modaltitle;
    s.prop42=modaltype;
    s.eVar42=modaltype;
    s.tl(true, 'o', 'Video Popup Page Load');
  }
};


// add click trackers for popups and banner ads
(function ($) {
  Drupal.behaviors.scVidpopClick = {
    attach: function (context, settings) {
      // On click on embedded video to launch and play modal
      $('.vidpop-preview', context).click(function(){
        var n = $(this).attr('class').match(/ vp-(\d+)/);
        n = n[1];
        var modaltitle = vp_titles[n];
        var modaltype  = vp_types[n];
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
        //alert('vidpop-preview:' + n);
      });

      // On-click of the subscribe button, pls fire (only once per session)
      $('.vidpop-popup .subscribe', context).click(function(){
        if( typeof vp_43_triggered == 'undefined' ) {
          // block multiple calls
          vp_43_triggered = 1;

          var n = $(this).attr('class').match(/ vp-(\d+)/);
          n = n[1];
          var modaltitle = vp_titles[n];
          var modaltype  = vp_types[n];
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


  Drupal.behaviors.vidpopPopups = {
    attach: function (context, settings) {
      $('.vidpop-preview .colorbox-inline').live('click', (function(){
        //alert('wait');
        $('#cboxWrapper').css('height', '425px');
        vidpopSource = 'node';
      }));

      // resize popup, based on source
      $(document).bind('cbox_complete', function(){
        //alert(vidpopSource);
        switch(vidpopSource) {
          case 'node':
            $('#colorbox').css('height', '450px');
            $('#cboxWrapper').css('height', '450px');
            $('#cboxContent').css('height', '450px');
            break;
        }
      });
    }
  }


  Drupal.behaviors.popupClosed = {
    // ensure video stopped when colorbox closes
    attach: function (context, settings) {
      $('#cboxClose').live('click', (function(){
        //alert('wait 1');
        //$("#player").stopVideo();
        //$("#media-youtube-1").stopVideo();
        //$("media_youtube_b4Iyl7DNUFI_1").stopVideo();

        // remove the player; this ensures it will stop plaing
        $("#colorbox .vidmap").remove();
      }));
    }
  }
 })(jQuery);


// return video node contents for popup on map page
// this is outside of our normal jquery space to avoid closure issues
function vidpop_get_map_video(nid) {
  var output = '?';

  jQuery.ajax({
    url: "/vidpop/mapembed/" + nid,
    type: 'get',
    async: false,
    dataType: 'html',
    error: function(XMLHttpRequest, textStatus, errorThrown) {
      alert('vidpop_get_map_video: cannot fetch node ' + nid);
      console.log(JSON.stringify(XMLHttpRequest));
      console.log(JSON.stringify(textStatus));
      console.log(JSON.stringify(errorThrown));
    },
    success: function (data) {
      //alert('data: ' + data);
      output = data;
    }
  });

  return output;
}


// click handlers for grids of text links, i.e. Rollins page
//
//    n = nid of video
function vidpopTextGridPopupClick(n) {
  alert('folger:' + n);

  jQuery.ajax({
    url: "/vidpop/get_video_details/" + nid,
    type: 'get',
    async: false,
    dataType: 'html',
    error: function(XMLHttpRequest, textStatus, errorThrown) {
      alert('vidpop_get_map_video: cannot fetch node ' + nid);
      console.log(JSON.stringify(XMLHttpRequest));
      console.log(JSON.stringify(textStatus));
      console.log(JSON.stringify(errorThrown));
    },
    success: function (data) {
      //alert('data: ' + data);
      output = data;

      return output;
    }
  });
}

