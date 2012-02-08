
/*(function ($) {
  Drupal.behaviors.ss_controls = { 
    attach : function(context) {
    $(".views-slideshow-controls-top").appendTo($("#ss_controls"));
    $(".views-slideshow-controls-bottom").appendTo($("#ss_controls"));
    }
  };
})(jQuery);

/* place dots on image rotator 
jQuery(document).ready(function () {
    var slideshows = Drupal.settings.viewsSlideshowCycle;
    var slidecount = 0;
    if (slideshows) {
        for (slideshow in slideshows) {
            var ss_obj = slideshows[slideshow];
            var slidecount = ss_obj['totalImages'];
            var ss_block_id = ss_obj['targetId'];
            var x = 0;
            jQuery(ss_block_id).children('div').each(function () {
                var dotdiv = '<ul class="dots">';
                for (i = 0; i < slidecount; i++) {
                    if (i == x) {
                        dotdiv = dotdiv + '<li class="active"></li>';
                    } else {
                        dotdiv = dotdiv + '<li class="inactive"></li>';
                    }
                }
                dotdiv = dotdiv + '</ul>';
                jQuery(this).find(".views-field-field-slide-headline-override div.field-content").append(dotdiv);
                x++;
            });
        }
    }
}); */
/*
jQuery(document).ready(function () {
	var arrows = '<ul class="gallery_nav"><li class="left"></li><li class="right"></li></ul>';
	jQuery("#views_slideshow_cycle_div_photo_gallery-block_0").append(arrows);
	
	jQuery('#views_slideshow_cycle_div_photo_gallery-block_0 .gallery_nav .left').click(function() {
		  alert('left');
	});
	
	jQuery('#views_slideshow_cycle_div_photo_gallery-block_0 .gallery_nav .right').click(function() {
		  alert('right');
	});
});
*/	