jQuery(document).ready(function() {

  var shareattach = (function() {
  
    //Attach tracking to share icons
    jQuery('.tp-pet-share-button-bar div a').click(function() { 
    
      var link_title = jQuery(this).attr('title');
      var title = convert_title(link_title);
      
      s.events='event25';
      s.prop26=title;
      s.eVar27=title;
      s.linkTrackVars='eVar27,prop26,events';
      s.linkTrackEvents='event25';
      s.tl(this, 'o', 'Content Share');
    });
  });
  shareattach();
});
