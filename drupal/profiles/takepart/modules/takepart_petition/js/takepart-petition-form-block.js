var tp_pet_start_events_tracked = false;

jQuery(document).ready(function() {

  var shareattach = (function() {
  
    if (jQuery.cookie("petition_start_tracking") != null) {
      tp_pet_start_events_tracked = true;
      return;
    }

    // Attach tracking to the form fields
    jQuery('.pet-form-focus-event').focus(function() { 
    
      if (! tp_pet_start_events_tracked) {
        tp_pet_start_events_tracked = true;
        var parent_form = jQuery(this).closest('form');
        s.events='event26';
        s.eVar25=parent_form.attr('title');
        s.prop25=parent_form.attr('title');
        s.linkTrackVars='eVar25,prop25,events';
        s.linkTrackEvents='event26';
        s.tl(true, 'o', 'Petition Start');
      }
    });
    jQuery('.pet-form-click-event').click(function() { 
    
      if (! tp_pet_start_events_tracked) {
        tp_pet_start_events_tracked = true;
        var parent_form = jQuery(this).closest('form');
        s.events='event26';
        s.eVar25=parent_form.attr('title');
        s.prop25=parent_form.attr('title');
        s.linkTrackVars='eVar25,prop25,events';
        s.linkTrackEvents='event26';
        s.tl(true, 'o', 'Petition Start');
      }
    });
  });
  
  shareattach();
});
