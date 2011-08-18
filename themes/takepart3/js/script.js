jQuery.fn.DefaultValue = function(text){
    return this.each(function(){
		//Make sure we're dealing with text-based form fields
		if(this.type != 'text' && this.type != 'password' && this.type != 'textarea')
			return;
		
		//Store field reference
		var fld_current=this;
		
		//Set value initially if none are specified
        if(this.value=='') {
			this.value=text;
		} else {
			//Other value exists - ignore
			return;
		}
		
		//Remove values on focus
		$(this).focus(function() {
			if(this.value==text || this.value=='')
				this.value='';
		});
		
		//Place values back on blur
		$(this).blur(function() {
			if(this.value==text || this.value=='')
				this.value=text;
		});
		
		//Capture parent form submission
		//Remove field values that are still default
		$(this).parents("form").each(function() {
			//Bind parent form submit
			$(this).submit(function() {
				if(fld_current.value==text) {
					fld_current.value='';
				}
			});
		});
    });
};

		var el = jQuery('.photo-wrapper img');
	  
		function makeMargin(el, app){
			var margin = ''; 
			var dirs = ['top','right', 'bottom', 'left']; 
			for(var t in dirs){ 
				var t = dirs[t]; 
				var mar = jQuery(el).css('margin-'+t);
				jQuery(app).css('margin-'+t, mar);
			}
		}


jQuery(document).ready(function() {
	
		//for eaach photo wrapper element presented:
		//store inline style value in 'floated'
		//traverse back to parent div and apply style value there
		//clear style value from nested image
	  jQuery.each( jQuery('.photo-wrapper img'), function(index, value){
		var floated = jQuery(value).css('float');
		jQuery(value).closest('.photo-wrapper').css('float', floated);
		jQuery(value).css('float','');
		
		makeMargin(value, jQuery(value).parent());
					
		jQuery('.photo-wrapper img').css('margin','');
			
		
	  })
	  
			
		//detect width of photo-wrapper based on img size and set container to that size 
	  jQuery('.photo-wrapper').width(function(ind, width){
        return jQuery('img', this).outerWidth(true);
      });
	  
	  
	  

	jQuery('#top-search .form-text').DefaultValue('Search TakePart');		
});

(function($) {
  Drupal.behaviors.takepart3 = { attach: function(context) {
    jQuery("a[href^='http']", context).attr('target','_blank');
    
  }};
})(jQuery);

(function($) {
  Drupal.behaviors.campaignVideo = { attach: function(context) {
    $('.field-name-field-tp-campaign-intro-media .close').click(function() {
      $('.campaign-video').hide();
      $('.field-name-field-tp-campaign-intro-media .play').show();
      return false;
    });
    $('.field-name-field-tp-campaign-intro-media .play').click(function() {
      $('.field-name-field-tp-campaign-intro-media .play').hide();
      $('.campaign-video').show();
      return false;
    });    
  }};
})(jQuery);
