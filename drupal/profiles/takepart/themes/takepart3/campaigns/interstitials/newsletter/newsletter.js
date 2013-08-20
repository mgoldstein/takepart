(function (window, $, undefined) {

$(function() {
	console.log('asdf');
	$('.form-item-email input').bind('blur', function(){
		var newCss = {'z-index': ''};
		if($(this).val()){
			newCss['z-index'] = 3;
		}
		console.log(newCss);
		$(this).css(newCss);
	});

	$('#dont a').bind('click', function(e) {
		e.preventDefault();
		if ( window.parent && window.parent.dont_show_interstitial ) window.parent.dont_show_interstitial();
	})
});

})(window, jQuery);