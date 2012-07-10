// file: javascript support for takepart_vidpop


(function ($) {
      Drupal.behaviors.scVidpopClick = {
        attach: function (context, settings) {
          // add click trackers for banner ads

          // On page view of a page with an embedded video
          $('.vidpop-embedded9', context).load(function(){
            alert('trap 40');
            s.linkTrackVars="eVar40, prop40, eVar41, prop41, events";
            s.linkTrackEvents="event40";
            s.events='event41';
            s.prop40=Drupal.settings.takepart_vidpop.embeddedvideotitle;
            s.eVar40=Drupal.settings.takepart_vidpop.embeddedvideotitle;
            s.prop41=Drupal.settings.takepart_vidpop.hostpagetitle;
            s.eVar41=Drupal.settings.takepart_vidpop.hostpagetitle;
            s.tl(true, 'o', 'Video Popup Click');
          });

          // On click on embedded video to launch and play modal
      $('.vidpop-preview', context).click(function(){
        //alert('trap 41');
        s.linkTrackVars="eVar40, prop40, eVar41, prop41, events";
        s.linkTrackEvents="event41";
        s.events='event41';
        s.prop40=Drupal.settings.takepart_vidpop.embeddedvideotitle;
        s.eVar40=Drupal.settings.takepart_vidpop.embeddedvideotitle;
        s.prop41=Drupal.settings.takepart_vidpop.hostpagetitle;
        s.eVar41=Drupal.settings.takepart_vidpop.hostpagetitle;
        s.tl(true, 'o', 'Video Popup Click');
      });

      // On click of any of the share icons in the modal, pls fire (once per session per button)
      $('#vidpop-details .addthis_button_email span', context).click(function(){
        //alert('trap 42');
        s.linkTrackVars="eVar40, prop40, eVar41, prop41, events";
        s.linkTrackEvents="event42";
        s.events='event41';
        s.prop40=Drupal.settings.takepart_vidpop.embeddedvideotitle;
        s.eVar40=Drupal.settings.takepart_vidpop.embeddedvideotitle;
        s.prop41=Drupal.settings.takepart_vidpop.hostpagetitle;
        s.eVar41=Drupal.settings.takepart_vidpop.hostpagetitle;
        s.tl(true, 'o', 'Video Popup Click');
      });

      // On-click of the subscribe button, pls fire (only once per session)
      $('.vidpop-popup .subscribe', context).click(function(){
        alert('trap 43');
        s.linkTrackVars="eVar40, prop40, eVar41, prop41, events";
        s.linkTrackEvents="event43";
        s.events='event41';
        s.prop40=Drupal.settings.takepart_vidpop.embeddedvideotitle;
        s.eVar40=Drupal.settings.takepart_vidpop.embeddedvideotitle;
        s.prop41=Drupal.settings.takepart_vidpop.hostpagetitle;
        s.eVar41=Drupal.settings.takepart_vidpop.hostpagetitle;
        s.tl(true, 'o', 'Video Popup Click');
      });
    }
  }
})(jQuery);