(function (window, $, undefined) {

$(function() {
	var $main = $('#main');
	var w = $main.width();
	var h = $main.height();
	window.parent.resize_interstitial(w, h);

	$('#dont a').bind('click', function(e) {
		e.preventDefault();
		window.parent.dont_show_interstitial();
	})
});

})(window, jQuery);