var tp_pet_start_events_tracked = false;
var tp_pet_submit_event_tracked = false;

jQuery(document).ready(function() {

  var shareattach = (function() {
  
    // Attach tracking to submit button
    jQuery('.petition-form').submit(function() { 
    
      if (! tp_pet_submit_event_tracked) {

        var form_title = jQuery(this).attr('title');
        var title = convert_title(form_title);

        // Action (event 19)
        s.events='event19';
        s.eVar28='Petition';
        s.linkTrackVars='eVar28,events';
        s.linkTrackEvents='event19';
        s.tl(true, 'o', 'Action');

        // Petition Complete (event 27)
        s.events='event27';
        s.eVar25=title;
        s.prop25=title;
        s.linkTrackVars='eVar25,prop25,events';
        s.linkTrackEvents='event27';
        s.tl(true, 'o', 'Petition Complete');
      
        jQuery('input[type="checkbox"]').filter('.pet-form-optin-event').each(function(index,element) {
          checkbox = jQuery(this);
          if (checkbox.attr('checked')) {
            // Newsletter Sign-up (event 39)
            s.events='event39';
            s.eVar23=checkbox.attr('title');
            s.prop23=checkbox.attr('title');
            s.linkTrackVars='eVar23,prop23,events';
            s.linkTrackEvents='event39';
            s.tl(true, 'o', 'Newsletter Sign-up');
          }
        });
        
        // Submit events have been tracked
        tp_pet_submit_event_tracked = true;
        
        // Don't immediately submit the form,
        // give the events some time to complete
        setTimeout( function() {jQuery('.petition-form').submit();}, 500);
        return false;
      }
      return true;
    });

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
