
var _galleryFastMatch = new Array();
var _galleryFastMatch_titles = new Array();

jQuery(document).ready(function () {

    var historyapi = (function () {
        if (Drupal.settings.gallery.nid) {

            var slideshows = Drupal.settings.viewsSlideshowCycle;

            if (slideshows) {
                for (slideshow in slideshows) {
                    ssid = slideshows[slideshow]['slideshowId'];
                    target = slideshows[slideshow]['targetId'];
                }
            }

            path = '/galleries_json_nid/' + Drupal.settings.gallery.nid;
            jQuery.getJSON(path, function (data) {
                for (var i = 0; i < data.length; i++) {
                    var obj = data[i];

                    _galleryFastMatch[i] = obj['url'];
                    _galleryFastMatch_titles[i] = obj['title'];
                    
                    if (obj) {
                        x = 0;
                        jQuery(target + ' img').each(function () {
                        	
                            imgsrc = (jQuery(this).attr('src'));
                            filename_a = imgsrc.substr(imgsrc.lastIndexOf("/") + 1);
                            filename_a = filename_a.substr(0, filename_a.lastIndexOf("_"));
                            filename_b = obj['filename'];
                            filename_b = filename_b.substr(0, filename_a.length);
                            pageurl = window.location.href;
                            pageurl = pageurl.substr(pageurl.lastIndexOf("/") + 1);
                            
                            //if ((obj['url'] == pageurl) && (filename_a == filename_b) && filename_a && filename_b) {
                            if ((obj['url'] == pageurl) && (x == i)) {
                                
                         
                            	Drupal.viewsSlideshow.action({
                                    action: "goToSlide",
                                    slideshowID: ssid,
                                    slideNum: x
                                });
                                
                            	var y = 0;
                            	jQuery('#widget_pager_top_photo_gallery-block img').each(function () {
                            	    if(y == x) {
                            	    	jQuery(this).addClass('highlight');
                            	    } else {
                            	    	jQuery(this).removeClass('highlight');
                            	    }
                            	    y++;
                            	});
                            	
                            	fastmatch_refreshstuff(x);
                            	
                            }
                            
                            x++;

                        });
                    }

                }

            });
        }
        // history.pushState(null, null, '/test');
    });

    historyapi();
    
	jQuery('#widget_pager_top_photo_gallery-block img').each(function () {		
	    jQuery(this).click(function() {
	    	fastmatch_historyapi();
	    }); 	
	});
  	
    jQuery('#views_slideshow_controls_text_previous_photo_gallery-block').click(function() {
    	fastmatch_historyapi();
    });
	
    jQuery('#views_slideshow_controls_text_next_photo_gallery-block').click(function() {
    	fastmatch_historyapi();
    });
    
});


function fastmatch_historyapi() {
	var y = 0;
	jQuery('#widget_pager_top_photo_gallery-block img').each(function () {
		
		if(jQuery(this).hasClass('highlight')) {
			
			urlar = window.location.href.split('/');
			
			if(urlar[3] == 'photos') {
				if(y==0) {
					history.pushState(null, null, '/' + urlar[3] + '/' + urlar[4]);
				} else {
					history.pushState(null, null, '/' + urlar[3] + '/' + urlar[4] + '/' + _galleryFastMatch[y]);
				}
			}
			
			fastmatch_refreshstuff(y);
			
		}
	    y++;
	});
}



function fastmatch_refreshstuff(y) {

	document.title = _galleryFastMatch_titles[y];
	
	omniture = s.prop15.split(':');
	s.prop15 = omniture[0] + ':' + omniture[1] + ':' + _galleryFastMatch_titles[y];
	s.eVar15 = s.prop15;
	s.t();
	
	//Refresh Facebook comments:
	fbchtml = '<div class="fb-comments" ' +
     		  'data-href="' + window.location.href + '" ' +
     	      'data-num-posts="15" ' +
              'data-width="640" ' +
              'data-colorscheme="light"></div>';
	
	jQuery('.fb-comments').html(fbchtml);	
	FB.XFBML.parse(jQuery('#comments').get(0));
	
	//Refresh Google Plus:
    if((typeof gapi != 'undefined') && (gapi)) {
		gapi.plusone.go();
    }
    		    
    //Refresh addthis:
    jQuery('script[src*="addthis_widget"]').each(function(i){
    	atscript = (this.src);
    });
    if (window.addthis){
		window.addthis = null;
	}
    jQuery.getScript(atscript);
    
    
    //Force the damn FB shares to refresh ... rebuild iFrames:
    jQuery(".addthis_toolbox .addthis_button_facebook_like iframe").each(function() {
    	var src = jQuery(this).attr('src');
    	src = fastmatch_fb_iframe_refresh(src);
    	jQuery(this).attr('src', src);
    });
 	
	//Refresh DFP Ads:
	if(typeof googletag != 'undefined') {
		googletag.pubads().refresh();
	}
}


function fastmatch_fb_iframe_refresh(q) {
	nq = q.substr(0,q.lastIndexOf("?"));
	oq = q.substr(q.lastIndexOf("?"));
	var qs = oq.split("&");
	for (var i=0;i<qs.length;i++) {
		var pair = qs[i].split("=");
		if(pair[0] == 'href') {
			nq = nq + "&" + pair[0] + '=' + encodeURIComponent(window.location.href);
		} else {
			nq = nq + "&" + pair[0] + '=' + pair[1];
		}
	}
	return nq;
}

