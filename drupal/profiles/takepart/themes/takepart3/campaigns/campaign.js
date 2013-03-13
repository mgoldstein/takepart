var addthis_config = {
     data_track_clickback: false 
};

(function(window, $, undefined){
// Setup ----------------

// Onload ----------------
$(function() {

// Delegates
$('body')
	// Open non-takepart URLs in a new window
	.delegate('a:not([href*="takepart.com"])', 'click', function() {
		if ( location.hostname != this.hostname ) {
			$(this).attr({target: '_blank'});
		}
	})
	.delegate('#page a[href*="privacy-policy"], #page a[href*="terms-of-use"]', 'click', function() {
		$(this).attr({target: '_blank'});
	})
	;

});
})(window, jQuery);