(function(window, $, undefined){
// Setup ----------------

// Onload ----------------
$(function() {

// Add active class to anchors
$('a').each(function() {
	if ( this.pathname == location.pathname && this.protocol == location.protocol && this.hostname == location.hostname ) {
		$(this).addClass('active');
	}
});

// Delegates
$('body')
	// Open non-takepart URLs in a new window
	.delegate('a:not([href*="takepart.com/"])', 'click', function() {
		if ( location.hostname != this.hostname ) {
			$(this).attr({target: '_blank'});
		}
	})
	;

});
})(window, jQuery);