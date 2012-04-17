jQuery(document).ready(function() {

  var trackmetrics = (function() {

    if ('petition' in Drupal.settings) {
      var track_latch = Drupal.settings.petition['track_latch'];
      if (jQuery.cookie(track_latch) != null) {

        // Action (event 19)
        s.events='event19';
        s.eVar28='Petition';
        s.linkTrackVars='eVar28,events';
        s.linkTrackEvents='event19';
        s.tl(true, 'o', 'Action');

        // Petition Complete (event 27)
        s.events='event27';
        s.eVar25=Drupal.settings.petition['name'];
        s.linkTrackVars='eVar25,events';
        s.linkTrackEvents='event27';
        s.tl(true, 'o', 'petition submit');

        // Newsletter Sign-up (event 39)
        for (var i=0; i<Drupal.settings.petition['newsletters'].length; i++) {
          s.events='event39';
          s.eVar23=Drupal.settings.petition['newsletters'][i];
          s.linkTrackVars='eVar23,events';
          s.linkTrackEvents='event39';
          s.tl(true, 'o', 'Newsletter Sign-up');
        }

        // delete the cookie
        jQuery.cookie(track_latch, null, {path:'/'});
      }
    }
  });

  trackmetrics();
});
