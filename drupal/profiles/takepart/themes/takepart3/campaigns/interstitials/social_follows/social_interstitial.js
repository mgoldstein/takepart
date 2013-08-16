(function (window, $, undefined) {

$(function() {
	
	// $(window).bind('load', function(){
	// 	debugger;
	// 	console.log('WINDOW LOAD');
	// 	var w = $('#page').width();
	// 	var h = $('html').height();
	// 	console.log('PAGE: ');
	// 	console.log($('#page'));
	// 	console.log('WIDTH: ' + w);
	// 	if ( window.parent && window.parent.resize_interstitial ) window.parent.resize_interstitial(w, h);
	// });

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