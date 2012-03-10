jQuery(document).ready(function() {

  var trackmetrics = (function() {
  
    if (jQuery.cookie("petition_submit_tracking") != null) {
    
      var events = jQuery.cookie("petition_submit_tracking");
      if (events.length > 0) {
        
        pieces = events.split("|");
        
        // Action (event 19)
        s.events='event19';
        s.eVar28='Petition';
        s.linkTrackVars='eVar28,events';
        s.linkTrackEvents='event19';
        s.tl(true, 'o', 'Action');

        // Petition Complete (event 27)
        s.events='event27';
        s.eVar25=pieces[0];
        s.prop25=pieces[0];
        s.linkTrackVars='eVar25,prop25,events';
        s.linkTrackEvents='event27';
        s.tl(true, 'o', 'Petition Complete');
      
        // Newsletter Sign-up (event 39)
        for (var i=1; i<pieces.length; i++) {
          s.events='event39';
          s.eVar23=pieces[i];
          s.prop23=pieces[i];
          s.linkTrackVars='eVar23,prop23,events';
          s.linkTrackEvents='event39';
          s.tl(true, 'o', 'Newsletter Sign-up');
        }
      }
      
      // delete the cookie
      jQuery.cookie("petition_submit_tracking", null);
    }
  });
  
  trackmetrics();
});
