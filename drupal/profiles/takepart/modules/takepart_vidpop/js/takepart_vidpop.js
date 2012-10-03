// file: javascript support for takepart_vidpop

// On page view of a page with an embedded video
//
// triggered by call in template.php, preprocess node
// doesn't work here as a behavior, like the others
function vidpop_loaded() {
  // debug: alert('trap 40 c');
  s.linkTrackVars="eVar40, prop40, eVar41, prop41, events";
  s.linkTrackEvents="event40";
  s.events='event40';
  s.prop40=Drupal.settings.takepart_vidpop.embeddedvideotitle;
  s.eVar40=Drupal.settings.takepart_vidpop.embeddedvideotitle;
  s.prop41=Drupal.settings.takepart_vidpop.hostpagetitle;
  s.eVar41=Drupal.settings.takepart_vidpop.hostpagetitle;
  s.tl(true, 'o', 'Video Popup Click');
};


// add click trackers for banner ads
(function ($) {
  Drupal.behaviors.scVidpopClick = {
        attach: function (context, settings) {
          // On click on embedded video to launch and play modal
          $('.vidpop-preview', context).click(function(){
            // debug: alert('trap 41 ');
            s.linkTrackVars="eVar40, prop40, eVar41, prop41, events";
            s.linkTrackEvents="event41";
            s.events='event41';
            s.prop40=Drupal.settings.takepart_vidpop.embeddedvideotitle;
            s.eVar40=Drupal.settings.takepart_vidpop.embeddedvideotitle;
            s.prop41=Drupal.settings.takepart_vidpop.hostpagetitle;
            s.eVar41=Drupal.settings.takepart_vidpop.hostpagetitle;
            s.tl(true, 'o', 'Video Popup Click');
          });

          /*
           * not supported, because addthis is ona different omain
           * revisit when we replace addthis
           *
           // On click of any of the share icons in the modal, pls fire (once per session per button)
           $('#vidpop-details #vidpop-social', context).click(function(){
           // debug: alert('trap 42t');
           s.linkTrackVars="eVar40, prop40, eVar41, prop41, events";
           s.linkTrackEvents="event42";
           s.events='event41';
           s.prop40=Drupal.settings.takepart_vidpop.embeddedvideotitle;
           s.eVar40=Drupal.settings.takepart_vidpop.embeddedvideotitle;
           s.prop41=Drupal.settings.takepart_vidpop.hostpagetitle;
           s.eVar41=Drupal.settings.takepart_vidpop.hostpagetitle;
           s.tl(true, 'o', 'Video Popup Click');
           });
           $('#vidpop-details .addthis_button_email span', context).click(function(){
           // debug: alert('trap 42e');
           s.linkTrackVars="eVar40, prop40, eVar41, prop41, events";
           s.linkTrackEvents="event42";
           s.events='event41';
           s.prop40=Drupal.settings.takepart_vidpop.embeddedvideotitle;
           s.eVar40=Drupal.settings.takepart_vidpop.embeddedvideotitle;
           s.prop41=Drupal.settings.takepart_vidpop.hostpagetitle;
           s.eVar41=Drupal.settings.takepart_vidpop.hostpagetitle;
           s.tl(true, 'o', 'Video Popup Click');
           });
           */

          // On-click of the subscribe button, pls fire (only once per session)
          $('.vidpop-popup .subscribe', context).click(function(){
            if( typeof vp_43_triggered == 'undefined' ) {
              // block multiple calls
              // debug: alert('trap 43');
              vp_43_triggered = 1;
              s.linkTrackVars="eVar40, prop40, eVar41, prop41, events";
              s.linkTrackEvents="event43";
              s.events='event43';
              s.prop40=Drupal.settings.takepart_vidpop.embeddedvideotitle;
              s.eVar40=Drupal.settings.takepart_vidpop.embeddedvideotitle;
              s.prop41=Drupal.settings.takepart_vidpop.hostpagetitle;
              s.eVar41=Drupal.settings.takepart_vidpop.hostpagetitle;
              s.tl(true, 'o', 'Video Popup Click');
            }
          });
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

