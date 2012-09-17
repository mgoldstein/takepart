// file: javascript support for takepart_unipop

// On page view of a page with an embedded video
//
// triggered by call in template.php, preprocess node
// doesn't work here as a behavior, like the others
function unipop_loaded() {
  return;

  s.linkTrackVars="eVar40, prop40, eVar41, prop41, events";
  s.linkTrackEvents="event40";
  s.events='event40';
  s.prop40=Drupal.settings.takepart_unipop.embeddedvideotitle;
  s.eVar40=Drupal.settings.takepart_unipop.embeddedvideotitle;
  s.prop41=Drupal.settings.takepart_unipop.hostpagetitle;
  s.eVar41=Drupal.settings.takepart_unipop.hostpagetitle;
  s.tl(true, 'o', 'Video Popup Click');
};


// add click trackers for banner ads
(function ($) {
  Drupal.behaviors.scunipopClick = {
        attach: function (context, settings) {
          // On click on embedded video to launch and play modal
          $('.unipop-preview', context).click(function(){
            // debug: alert('trap 41 ');
            s.linkTrackVars="eVar40, prop40, eVar41, prop41, events";
            s.linkTrackEvents="event41";
            s.events='event41';
            s.prop40=Drupal.settings.takepart_unipop.embeddedvideotitle;
            s.eVar40=Drupal.settings.takepart_unipop.embeddedvideotitle;
            s.prop41=Drupal.settings.takepart_unipop.hostpagetitle;
            s.eVar41=Drupal.settings.takepart_unipop.hostpagetitle;
            s.tl(true, 'o', 'Video Popup Click');
          });

          /*
           * not supported, because addthis is ona different omain
           * revisit when we replace addthis
           *
           // On click of any of the share icons in the modal, pls fire (once per session per button)
           $('#unipop-details #unipop-social', context).click(function(){
           // debug: alert('trap 42t');
           s.linkTrackVars="eVar40, prop40, eVar41, prop41, events";
           s.linkTrackEvents="event42";
           s.events='event41';
           s.prop40=Drupal.settings.takepart_unipop.embeddedvideotitle;
           s.eVar40=Drupal.settings.takepart_unipop.embeddedvideotitle;
           s.prop41=Drupal.settings.takepart_unipop.hostpagetitle;
           s.eVar41=Drupal.settings.takepart_unipop.hostpagetitle;
           s.tl(true, 'o', 'Video Popup Click');
           });
           $('#unipop-details .addthis_button_email span', context).click(function(){
           // debug: alert('trap 42e');
           s.linkTrackVars="eVar40, prop40, eVar41, prop41, events";
           s.linkTrackEvents="event42";
           s.events='event41';
           s.prop40=Drupal.settings.takepart_unipop.embeddedvideotitle;
           s.eVar40=Drupal.settings.takepart_unipop.embeddedvideotitle;
           s.prop41=Drupal.settings.takepart_unipop.hostpagetitle;
           s.eVar41=Drupal.settings.takepart_unipop.hostpagetitle;
           s.tl(true, 'o', 'Video Popup Click');
           });
           */

          // On-click of the subscribe button, pls fire (only once per session)
          $('.unipop-popup .subscribe', context).click(function(){
            if( typeof vp_43_triggered == 'undefined' ) {
              // block multiple calls
              // debug: alert('trap 43');
              vp_43_triggered = 1;
              s.linkTrackVars="eVar40, prop40, eVar41, prop41, events";
              s.linkTrackEvents="event43";
              s.events='event43';
              s.prop40=Drupal.settings.takepart_unipop.embeddedvideotitle;
              s.eVar40=Drupal.settings.takepart_unipop.embeddedvideotitle;
              s.prop41=Drupal.settings.takepart_unipop.hostpagetitle;
              s.eVar41=Drupal.settings.takepart_unipop.hostpagetitle;
              s.tl(true, 'o', 'Video Popup Click');
            }
          });
        }
  }
})(jQuery);