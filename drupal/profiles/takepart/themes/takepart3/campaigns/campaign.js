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
	;

});
})(window, jQuery);