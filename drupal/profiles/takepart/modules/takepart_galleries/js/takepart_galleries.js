
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
                            
                            if ((obj['url'] == pageurl) && (filename_a == filename_b) && filename_a && filename_b) {
                                
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
				history.pushState(null, null, '/' + urlar[3] + '/' + urlar[4] + '/' + _galleryFastMatch[y]);	
			}
			
			document.title = _galleryFastMatch_titles[y];
			
			//Refresh Facebook comments:
			FB.XFBML.parse(document.getElementById("comments"));
			
			//Refresh Google Plus:
		    if((typeof gapi != 'undefined') && (gapi)) {
				gapi.plusone.go();
		    }
		    
		    //Refresh addthis:
			var script = 'http://s7.addthis.com/js/250/addthis_widget.js#domready=1';
			if (window.addthis){
				window.addthis = null;
			}
			jQuery.getScript( script );			
			
		}
	    y++;
	});
}


