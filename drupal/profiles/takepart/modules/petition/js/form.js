jQuery(document).ready(function () {

  // hook up the rollover for the sign petition button
  jQuery("input.rollover-button").hover(
    function () { this.src = this.src.replace("_off","_on");
    },
    function () { this.src = this.src.replace("_on","_off");
    }
  );

  // hook up the public display disclaimer
  jQuery("#edit-signature-public-display-und").click(
    function () {
      var note = jQuery('#petition-signature-display-disclaimer');
      if (this.checked) {
        note.hide();
      }
      else {
        note.slideDown('fast', function () {});
      }
    }
  );

  if (Drupal.settings.petition) {
    if ('updates_redirect' in Drupal.settings.petition) {
      // the petition is already signed, redirect to the updates page
      jQuery(location).attr("href","/" + Drupal.settings.petition['updates_redirect']);
    }
    else {
      // fire off the petition view event
      var latch = Drupal.settings.petition['viewed_latch'];
      if (jQuery.cookie(latch) != null) {
        s.events='event26';
        s.eVar25=Drupal.settings.petition['name'];
        s.linkTrackVars='eVar25,events';
        s.linkTrackEvents='event26';
        s.tl(true, 'o', 'petition view');
        jQuery.cookie(latch, 1, {path:'/'});
      }
    }
  }
});
