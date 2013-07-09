(function (window, $, undefined) {

$(function() {
	var $main = $('#main');
	var w = $main.width();
	var h = $main.height();
	window.parent.resize_interstitial(w, h);
});

})(window, jQuery);