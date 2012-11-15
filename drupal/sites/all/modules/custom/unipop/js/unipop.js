// file: javascript support for Takepart Universal Popups Support

  // return youtube id from video node id
  function unipop_video_id_from_node(nid) {
    var output = '?';

    jQuery.ajax({
      url: "/unipop/video_id_from_node/" + nid,
      type: 'get',
      async: false,
      dataType: 'html',
      error: function(XMLHttpRequest, textStatus, errorThrown) {
        alert('unipop_video_id_from_node: cannot fetch node ' + nid);
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

function unipop_loaded() {
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


(function ($) {
})(jQuery);


