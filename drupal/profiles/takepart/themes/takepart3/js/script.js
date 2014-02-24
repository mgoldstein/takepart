// TODO: Put all the document ready code in one document ready closure
(function(window, $, undefined) {
    // Document ready
    $(function() {
        var $body = $('body');

        // Delegates
        $body
            // Skip link tabbing fix for Webkit
            .delegate('#skip-link a', 'click', function() {
                $($(this).attr('href')).attr('tabIndex', '-1').focus();
            })
            // Infographic pop-up
            .delegate('.tpinfographic a', 'click', function(e) {
                $.tpmodal.show({id: 'tpinfographic_modal_', url: this.href, hideOnModalClick: true});
                takepart.analytics.track('tpinfographic_show', {name: $(this).find('img')[0].alt});
                e.preventDefault();
            })
            .delegate('.tpinfographic_embed_link a', 'click', function(e) {
                e.preventDefault();
                var $this = $(this);
                var $embed_textarea_p = $this.closest('.tpinfographic_embed_container').find('.tpinfographic_embed_textarea');
                if ( $embed_textarea_p.css('display') == 'none' ) {
                    $embed_textarea_p.show();
                    takepart.analytics.track('tpinfographic_embed_show', {name: $this.closest('.tpinfographic_container').find('img')[0].alt});
                } else {
                    $embed_textarea_p.hide();
                }
            })
            .delegate('.tpinfographic_embed_textarea textarea', 'focus keyup', function(e) {
                var keycode = e.keyCode ? e.keyCode : e.which ? e.which : e.charCode;
                if(keycode === 9 || !keycode){
                    // Hacemos select
                    var $this = $(this);
                    $this.select();

                    // Para Chrome's que da problema
                    $this.bind("mouseup", function() {
                        // Unbindeamos el mouseup
                        $this.unbind("mouseup");
                        return false;
                    });
                }
            })
            ;

        // Admin tabs
        $('.tabs.primary li').appendTo('.toolbar-shortcuts ul');

        // Make tpinfographic stuff
        $('.tpinfographic').each(function() {
            var $this = $(this);
            var html = $this.html().replace(/^\s+|\s+$/g, '') + '<br />Via: <a href="http://www.takepart.com">TakePart.com</a>';
            var $container = $('<div/>').addClass('tpinfographic_container');
            var $embed = $('<div/>').addClass('tpinfographic_embed_container');
            var $embed_link_p = $('<p/>').addClass('tpinfographic_embed_link');
            var $embed_link_a = $('<a href="#"/>').html('Embed This Infographic on Your Site');
            var $embed_textarea_p = $('<p/>').addClass('tpinfographic_embed_textarea').hide();
            var $embed_textarea = $('<textarea/>').addClass('tpinfographic_embed_textarea').attr({cols: 56, rows: 7}).val(html);

            $embed_link_p.append($embed_link_a);

            $embed_textarea_p.append($embed_textarea);

            $embed
                .append($embed_link_p)
                .append($embed_textarea_p)

            $container
                .insertAfter($this)
                .append($this)
                .append($embed)
                ;
        });

        // Sticky social nav on article page
        $('.node-type-openpublish-article', '.node-type-video').children('#left-rail .region-sidebar-first').tpsticky({
            offsetNode: '#content'
        });

        // TODO reduce code duplication
        // Lazy load facebook comments
        $('.fb_comments')
            .lazyload({threshold: 200, load: function() {
                var $div = $('<div/>');
                var $template = $(this).find('.fb_comments_template');
                var html = $template.text();
                $div.html(html);
                $div.insertAfter($template);
                FB.XFBML.parse($div[0]);
            }});

        // Lazy load takepart_addthis_footer
        // TODO check to see if this has the proper settings
        $('.takepart_addthis_footer')
            .lazyload({threshold: 200, load: function() {
                var $div = $('<div/>');
                var $template = $(this).find('.takepart_addthis_footer_template');
                var html = $template.text();
                $div.html(html);
                $div.insertAfter($template);
                addthis.toolbox('.addthis_toolbox');
            }});
    });
})(window, jQuery);



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

  jQuery('#top-search .form-text').DefaultValue('Search');
  jQuery('#top-search .form-text').click(function() {
    jQuery('#top-search .form-text').css("font-style", "normal");
    return false;
  });
});

/* rewrites all absolute links to open in a new window
(function($) {
    Drupal.behaviors.takepart3 = {
        attach: function(context) {
            jQuery("a[href^='http']", context).attr('target','_blank');

        }
    };
})(jQuery);
*/

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


/* fix the height in the featured galleries */
jQuery(document).ready(function () {
    var target = '.boxes-selected-style-6 .views-row';
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

jQuery(document).ready(function () {
    var targets = jQuery('.front .block-boxes-current-promo .views-row');
    var gHeight = 0;
    jQuery.each(targets, function (i, target) {
        gHeight = Math.max(gHeight, jQuery(target).height());
    });
    jQuery.each(targets, function (i, target) {
    	jQuery(target).height(gHeight);
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

/*
 * Function for setting the active image in the jquery carousel, either from the left / right
 * navigation arrow on the large image, or from the image in the carousel itself.
 */
function gallery_swap_active(origin) {
	var activeid = 0;
	//remove the highlight class from all the images in the carousel:
	jQuery('#widget_pager_top_photo_gallery-block .highlight').removeClass('highlight');
	if((jQuery(origin).attr('id') == "views_slideshow_controls_text_next_photo_gallery-block") ||
	   (jQuery(origin).attr('id') == "views_slideshow_controls_text_previous_photo_gallery-block")) {
		var imgstring = 0;
		var firstimgstring = false;
		//life clocks are a lie, carousel is a lie, there is no renewal
	    jQuery('#views_slideshow_cycle_teaser_section_photo_gallery-block > div').each(function () {
	    	if(jQuery(this).css('display') == 'block') {
	    		imgstring = jQuery(this).attr('id');
	    		imgstring = imgstring.match(/\d+$/);
	    		imgstring = parseInt(imgstring);
	    		if(!firstimgstring) firstimgstring = imgstring;
	    	}
	    });
	    //logic for wrapping at the end of, or begining of the carousel
	    postdirection = ((jQuery('#views_slideshow_cycle_teaser_section_photo_gallery-block > div').length-1 == imgstring));
	    predirection = ((jQuery('#views_slideshow_cycle_teaser_section_photo_gallery-block > div').length-1 == firstimgstring));
	    //forward button:
	    if(jQuery(origin).attr('id') == "views_slideshow_controls_text_next_photo_gallery-block") {
	    	if(postdirection && predirection) {
	    		imgstring = 1;
	    	} else {
	    		imgstring = imgstring + 2;
	    	}
	    	activeid = imgstring - 1;
	    }
	    //reverse button:
	    if(jQuery(origin).attr('id') == "views_slideshow_controls_text_previous_photo_gallery-block") {
	    	if(postdirection && predirection) {
	    		imgstring = imgstring + 1;
	    	}
	    	activeid = imgstring - 1;
	    	if(activeid == -1) {
	    		activeid = jQuery('#views_slideshow_cycle_teaser_section_photo_gallery-block > div').length - 1;
	    		imgstring = imgstring - 1;
	    	}
	    }
	    //Add highlight css class to this image:
	    jQuery('#widget_pager_top_photo_gallery-block .jcarousel-item-' + imgstring + ' img').toggleClass('highlight');
	} else {
		//If the user clicked an image in the
		//carousel, add highlight css class to
		//the image they clicked:
		jQuery(origin).toggleClass('highlight');
		activeid = 0;
	}
	//alert(activeid);
	return activeid;
}

jQuery(document).ready(function() {
	jQuery('#widget_pager_top_photo_gallery-block .jcarousel-item-1 img').toggleClass('highlight');
	//jQuery('#widget_pager_top_photo_gallery-block').css('display', 'block');
});

// enable rollover images and image input buttons
jQuery(document).ready(function () {
  jQuery("img.rollover-image-off").hover(
    function () { this.src = this.src.replace("_off","_on");
    },
    function () { this.src = this.src.replace("_on","_off");
    }
  );
  jQuery("input.rollover-image-off").hover(
    function () { this.src = this.src.replace("_off","_on");
    },
    function () { this.src = this.src.replace("_on","_off");
    }
  );
});

// prevent vertical display of photo gallery; ticket #23275 pglatz 4/25/12, 5/2/12 (inside pages)
    jQuery(document).ready(function() {
        jQuery('#block-boxes-box-3df7e268').show();
        jQuery('#widget_pager_top_photo_gallery-block li').show();
    });







(function ($, Drupal, window, document, undefined) {
    /**
     * Settings for the snap.js library
     */
    Drupal.behaviors.snapperSettings = {
      attach: function(context, settings) {
        var snapper = new Snap({
          element: document.getElementById('page-wrapper')
        });

        snapper.settings({
          dragger: null,
          disable: 'none',
          addBodyClasses: true,
          hyperextensible: true,
          resistance: 0.5,
          flickThreshold: 50,
          transitionSpeed: 0.3,
          easing: 'ease',
          maxPosition: 280,
          minPosition: 0,
          tapToClose: true,
          touchToDrag: false,
          clickToDrag: false,
          slideIntent: 40,
          minDragDistance: 5
        });

        $('.menu-toggle').on('click', function(){
            if( snapper.state().state=="left" ){
                snapper.close();
            } else {
                snapper.open('left');
            }
        });
      }
    };
})(jQuery, Drupal, this, this.document);

