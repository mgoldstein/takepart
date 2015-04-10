/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
// To understand behaviors, see https://drupal.org/node/756722#behaviors
$(document).ready(function() {

	// Some general touch vars to set globally
    var isTouch = 'ontouchstart' in window || 'msmaxtouchpoints' in window.navigator;
    var isTouchmove = false;
    var click = isTouch ? "touchend" : "click";

	$('.comments-count').on(click, function(e){
		if(typeof FB != 'undefined') {
			jQuery('fb:comments').attr('href', window.location.href);
			FB.XFBML.parse();
			$('#comments').show();
			$(this).hide();
		}
		e.disableDefault();
		return false;
	});

});
