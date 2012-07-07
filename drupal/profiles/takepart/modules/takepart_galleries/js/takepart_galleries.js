
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
            	//var data = takepart_galleries_json;
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
                            
                            pageurl = (window.location.href.split("?")[0]).replace("#","/");
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
                            	
                            	fastmatch_refreshstuff(x, true);
                            	
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
			
			urlar = ((window.location.href).replace("#","/")).split('/');
			
			if(urlar[3] == 'photos') {
				if(y==0) {
					if (history.pushState) {
						history.pushState(null, null, '/' + urlar[3] + '/' + urlar[4]);
					} else {
						window.location.hash = "";
					}
				} else {
					if (history.pushState) {
						history.pushState(null, null, '/' + urlar[3] + '/' + urlar[4] + '/' + _galleryFastMatch[y]);
					} else {
						window.location.hash = "#" + _galleryFastMatch[y];
					}
				}
			}
			
			fastmatch_refreshstuff(y, false);
			
		}
	    y++;
	});
}



function fastmatch_refreshstuff(y, first) {

	document.title = _galleryFastMatch_titles[y];
	
	//not the first hit to the gallery, don't track event15
	if(!first) {
		if (s.linkTrackEvents.indexOf(",") != -1) {
			arlte = s.linkTrackEvents.split(',');
			s.linkTrackEvents = "";
			for (var i=0;i<arlte.length;i++) {
				if(arlte[i] != 'event15') {
					if(i != 0) {
						s.linkTrackEvents = s.linkTrackEvents + "," + arlte[i];
					} else {
						s.linkTrackEvents = arlte[i]; 
					}
				}
			}
		} else if(s.linkTrackEvents == 'event15') { s.linkTrackEvents = ""; }
	}
			
	omniture = s.prop15.split(':');
	s.prop15 = omniture[0] + ':' + omniture[1] + ':' + _galleryFastMatch_titles[y];
	s.eVar15 = s.prop15;
	s.t();
	
	//Refresh Facebook comments:
	//OLD WAY:
	if(typeof FB != 'undefined') {
		fbchtml = '<div class="fb-comments" ' +
	     		  'data-href="' + (window.location.href).replace("#","/") + '" ' +
	     	      'data-num-posts="15" ' +
	              'data-width="640" ' +
	              'data-colorscheme="light"></div>';
		
		jQuery('.fb-comments').html(fbchtml);	
		FB.XFBML.parse(jQuery('#comments').get(0));
	}
	
	//NEW WAY:
	/*
	if(typeof FB != 'undefined') {
		jQuery('fb:comments').attr('href', window.location.href);
		FB.XFBML.parse();
	}
	*/
	
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
    	newsrc = fastmatch_fb_iframe_refresh(src);
    	jQuery(this).attr('src', newsrc);
    });
    
    //twitter refresh:
	if(typeof twttr != 'undefined') {
		twttr.widgets.load();
	}
	
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
		if(i != 0) {
			token = "&";
		} else {
			token = "";
		}
		if((pair[0] == 'href') || 
		   (pair[0] == '?href')) {
			nq = nq + token + pair[0] + '=' + encodeURIComponent(window.location.href.split("?")[0]).replace("#","/");
		} else {
			nq = nq + token + pair[0] + '=' + pair[1];
		}
	}
	return nq;
}

