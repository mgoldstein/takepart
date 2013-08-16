(function (window, $, undefined) {

$(function() {
	
	$('#dont a').bind('click', function(e) {
		e.preventDefault();
		if ( window.parent && window.parent.dont_show_interstitial ) window.parent.dont_show_interstitial();
	});

	$('.social-link').bind('click', function(e) {
		if ( window.parent && window.parent.interstitial_social_click ){
			window.parent.interstitial_social_click($(this).attr('data-service'));
		}
	});
});

})(window, jQuery);