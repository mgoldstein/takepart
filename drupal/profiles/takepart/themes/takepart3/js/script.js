if (typeof takepart == "undefined" || !takepart) {
    var takepart = {};
}

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
        var real = t.substring(0, 1).toUpperCase() + t.substring(1);
        if(mar && ( (t == 'top' || t == 'bottom') || (el.style['margin'+real] &&  jQuery(el).css('float') != 'none') ) ){
            jQuery(app).css('margin-'+t, mar);
        } else {					
            jQuery(app).css('margin-'+t, 'auto');	
        }
    }
}


jQuery(document).ready(function() {
	
    //for eaach photo wrapper element presented:
    //store inline style value in 'floated'
    //traverse back to parent div and apply style value there
    //clear style value from nested image
    jQuery.each( jQuery('.photo-wrapper img'), function(index, value){

        makeMargin(value, jQuery(value).parent());
		
        var floated = jQuery(value).css('float');
        jQuery(value).closest('.photo-wrapper').css('float', floated);
        jQuery(value).css('float','');			
    //jQuery('.photo-wrapper img').css('margin','');
    })
	  
    jQuery('#top-search .form-text').DefaultValue('Search TakePart');		
});

(function($) {
    Drupal.behaviors.takepart3 = {
        attach: function(context) {
            jQuery("a[href^='http']", context).attr('target','_blank');
    
        }
    };
})(jQuery);

(function($) {
    Drupal.behaviors.campaignVideo = {
        attach: function(context) {
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
        }
    };
})(jQuery);

//Fix for dhtml menus:
jQuery(document).ready(function() {
    jQuery('div > ul.menu > li').each(function() {
        jQuery(this).mouseleave(function() {
            jQuery(this).parent().children().each(function() {
                jQuery(this).addClass( 'collapsed' );
                jQuery(this).removeClass( 'expanded' );
                jQuery(this).children('ul').hide();
            });
        });
    });
});

//Analytics functions:
//@todo: move into seprate file
takepart.analytics = takepart.analytics || {};

takepart.analytics.addThis_shareEventHandler = function (evt) {

    if (evt.type == 'addthis.menu.share') {

        var title;

        switch (evt.data.service) {
            case ("facebook_like"):
                title = "Facebook Recommend";
                break;
            case ("tweet"):
                title = "Twitter Tweet";
                break;
            case ("google_plusone"):
                title = "Google Plus One";
                break;
            case ("linkedin"):
                title = "LinkedIn";
                break;
        }

        if (title) {
            s.events = 'event25';
            s.prop26 = title;
            s.eVar27 = title;
            s.linkTrackVars = 'eVar27,prop26,events';
            s.linkTrackEvents = 'event25';
            s.tl(this.href, 'o', 'Content Share');
        }
    }
}

takepart.analytics.omn_clickTrack = function (target) {
    jQuery(target).click(function() { 
        var link_title = jQuery(this).attr('title');
        var title = convert_title(link_title);
        s.events='event25';
        s.prop26=title;
        s.eVar27=title;
        s.linkTrackVars='eVar27,prop26,events';
        s.linkTrackEvents='event25';
        s.tl(this.href, 'o', 'Content Share');						
    });
}

takepart.analytics.addThis_ready = function (evt) {
    addthis.addEventListener('addthis.menu.share', takepart.analytics.addThis_shareEventHandler);
}

jQuery(document).ready(function () {
    if (typeof addthis != "undefined" || addthis) {
        addthis.addEventListener('addthis.ready', takepart.analytics.addThis_ready);
    }
    /* Incorrectly attaches social sharing event to Take Action button
     * takepart.analytics.omn_clickTrack('.take_action_button'); 
     */ 
});


/* place dots on image rotator */
jQuery(document).ready(function () {
	//this object doesn't work on point:
    var slideshows = Drupal.settings.viewsSlideshowCycle;
    var slidecount = 0;
    if (slideshows) {
        for (slideshow in slideshows) {
            var ss_obj = slideshows[slideshow];
            var slidecount = ss_obj['totalImages'] ? ss_obj['totalImages'] : 3;
            var ss_block_id = ss_obj['targetId'] ? ss_obj['targetId'] : '#views_slideshow_cycle_teaser_section_slide_rotator-block';
            var x = 0;
            jQuery(ss_block_id).children('div').each(function () {
                var dotdiv = '<ul class="dots">';
                for (var i = 0; i < slidecount; i++) {
                    if (i == x) {
                        dotdiv = dotdiv + '<li class="active dotnav'+i+'"></li>';
                    } else {
                        dotdiv = dotdiv + '<li class="inactive dotnav'+i+'"></li>';
                    }
                }
                dotdiv = dotdiv + '</ul>';
                jQuery(this).find(".views-field-field-slide-headline-override div.field-content").append(dotdiv);
                x++;
            });
        }
        if(slidecount > 0) {
        	for (var i = 0; i < slidecount; i++) {
            	jQuery('.dotnav'+i).click(function() {
            		cssclass = (jQuery(this).attr('class'));
            		slidenum = cssclass.substring(cssclass.indexOf('dotnav')+6, cssclass.length);
    	    	    Drupal.viewsSlideshow.action({ "action": 'goToSlide', "slideshowID": 'slide_rotator-block', "slideNum": parseInt(slidenum) });
            		return false;
    	        });
        	}
        }
    }
});


/* fix the height in the featured galleries */
jQuery(document).ready(function () {
    var target = '.main-content .block-boxes-title-features .views-row';
    var i = 0;
    var index = 0;
    var tallestofthemall=new Object();
    jQuery(target).each(function () {
    	index = parseInt(i/3);
    	if ((!tallestofthemall[index]) || (jQuery(this).height() > tallestofthemall[index])) {
    		tallestofthemall[index] = jQuery(this).height();
    	} 
    	i++;
    });
    i = 0;
    jQuery(target).each(function () {
    	index = parseInt(i/3);
    	jQuery(this).height(tallestofthemall[index]);
    	i++;
    });  
});



/* center the blog headings vertically in the right rail 
jQuery(document).ready(function () {
    var target = '#right-rail .field-name-field-blog-view .views-field-title span.field-content';
    jQuery(target).each(function () {
    	var margin = parseInt(70-(jQuery(this).height()) / 2);
    	alert(margin);
    	if(margin > 0) {
    		jQuery(this).children(":first").css("margin-top", margin + "px");
    	}
    });
});
*/


/* fix the height in the featured galleries 
jQuery(document).ready(function () {
    var target = '.main-content .block-boxes-title-features .views-row';
    var tallestofthemall = 0;
    jQuery(target).each(function () {
    	index = parseInt(i/3);
    	if ((!tallestofthemall[index]) || (jQuery(this).height() > tallestofthemall[index])) {
    		tallestofthemall[index] = jQuery(this).height();
    	} 
    	i++;
    });
    i = 0;
    jQuery(target).each(function () {
    	index = parseInt(i/3);
    	jQuery(this).height(tallestofthemall[index]);
    	i++;
    });  
});

/*conditional padding for article imageas*/
jQuery(document).ready(function () {
	var target = '.field-type-text-with-summary img';
    jQuery(target).each(function () {
    	if(jQuery(this).css('float') == 'left') {
    		jQuery(this).css('padding-right', '10px');
    	}
    	if(jQuery(this).css('float') == 'right') {
    		jQuery(this).css('padding-left', '10px');
    	}
    	
    });
});


jQuery(document).ready(function () {
	jQuery("#views_slideshow_controls_text_previous_photo_gallery-block").click(function () {
		void(s.t());
	});
	jQuery("#views_slideshow_controls_text_next_photo_gallery-block").click(function () {
		void(s.t());
	});
	jQuery('.views-content-field-gallery-images img').click(function () {
    	void(s.t());
    });
});


