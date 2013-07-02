(function (window, $, undefined) {

window.tp_ad_takeover = function(bgcolor, bgimage, link) {
	var $body = $('body');
	var $a = $('<a id="tp_ad_takeover" href="' + link + '" target="_blank"></a>');

	$body
		.css({
			background: bgcolor + ' url("' + bgimage + '") center top no-repeat',
			backgroundAttachment: 'fixed'
		})
		.addClass('tp_ad_takeover');

	$a
		.css({
			position: 'fixed',
			height: '100%',
			width: '100%',
			left: 0,
			top: 0,
			zIndex: 1
		})
		$body.append($a);
};

})(window, jQuery);