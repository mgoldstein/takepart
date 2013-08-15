(function (window, $, undefined) {

$(function() {
	var $main = $('#page');

	$(window).bind('load', function(){
		var w = $main.width();
		var h = $('html').height();
		if ( window.parent && window.parent.resize_interstitial ) window.parent.resize_interstitial(w, h);
	});

	$('#dont a').bind('click', function(e) {
		e.preventDefault();
		if ( window.parent && window.parent.dont_show_interstitial ) window.parent.dont_show_interstitial();
	})
});

})(window, jQuery);