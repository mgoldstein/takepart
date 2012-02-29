var tp_pet_start_events_tracked = false;

jQuery(document).ready(function() {

  var shareattach = (function() {
  
    // Attach tracking to submit button
    jQuery('.petition-form').submit(function() { 
    
      var form_title = jQuery(this).attr('title');
      var title = convert_title(form_title);
    
      // Action (event 19)
      s.events='event19';
      s.eVar28='Petition';
      s.linkTrackVars='eVar28,events';
      s.linkTrackEvents='event19';
      s.tl(this, 'o', 'Action');

      // Petition Complete (event 27)
      s.events='event27';
      s.eVar25=title;
      s.prop25=title;
      s.linkTrackVars='eVar25,prop25,events';
      s.linkTrackEvents='event27';
      s.tl(this, 'o', 'Petition Complete');
      
      jQuery('input[type="checkbox"]').filter('.pet-form-optin-event').each(function(index,element) {
        checkbox = jQuery(this);
        if (checkbox.attr('checked')) {
          var cb_title = checkbox.attr('title');
          var nl_title = convert_title(cb_title);
          // Newsletter Sign-up (event 39)
          s.events='event39';
          s.eVar23=nl_title;
          s.prop32=nl_title;
          s.linkTrackVars='eVar23,prop23,events';
          s.linkTrackEvents='event39';
          s.tl(this, 'o', 'Newsletter Sign-up');
        }
      });
    });

    // Attach tracking to the form fields
    jQuery('.pet-form-focus-event').focus(function() { 
    
      if (! tp_pet_start_events_tracked) {
      
        tp_pet_start_events_tracked = true;
      
        var parent_form = jQuery(this).closest('form');
        var form_title = parent_form.attr('title');
        var title = convert_title(form_title);
    
        s.events='event26';
        s.eVar25=title;
        s.prop25=title;
        s.linkTrackVars='eVar25,prop25,events';
        s.linkTrackEvents='event26';
        s.tl(this.href, 'o', 'Petition Start');
      }
    });
    jQuery('.pet-form-click-event').click(function() { 
    
      if (! tp_pet_start_events_tracked) {

        tp_pet_start_events_tracked = true;
      
        var parent_form = jQuery(this).closest('form');
        var form_title = parent_form.attr('title');
        var title = convert_title(form_title);
    
        s.events='event26';
        s.eVar25=title;
        s.prop25=title;
        s.linkTrackVars='eVar25,prop25,events';
        s.linkTrackEvents='event26';
        s.tl(this.href, 'o', 'Petition Start');
      }
    });

  });
  shareattach();
});
