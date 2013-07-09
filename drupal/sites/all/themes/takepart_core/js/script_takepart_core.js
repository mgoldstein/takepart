(function (window, $, undefined) {

// Document Ready
$(function() {
	var $body = $('body');

	var $interstitial = $('#interstitial');
	if ( $interstitial.length ) {
		var $a = $interstitial.find('a');
		var $iframe = $('<iframe src="' + $a.attr('href') + '"></iframe>').css({border: '0'});

		window.resize_interstitial = function(w, h) {
			$iframe.css({width: w, height: h});
		};

		$.tpmodal.load({
			id: 'interstitial_modal_',
			prepend: 'interstitial_modal_',
			node: $iframe
		});
	}

	// Omniture position tracking
	// Parent/ancestor vars to track in reverse order of importance
	$.tpregions.add({
		'Header': '#site-header',
		'Footer': '#site-footer',
		'Daily Featured Content': '.of_the_day_section',
		'Partner Link': '.on_our_radar_section',
		'Embedded Content': '#article-body .drupal-embed',
		'Related Stories': '.related-stories',
		'Next Article': '.next-article',
		'Keyword Link': '.page-tags',
		'Author Full Bio Link': '#article-author .full_bio_link',
		'Author Byline Link': '.authors',
		'Badge': '.badge',
		'Topic Box': '#topic_box',
		'Outbrain Widget': '.OUTBRAIN'
	});

	// Only place it on internal urls
	var relative_test = new RegExp("//" + location.host + "($|/)");

	$body
		.delegate('a:not(.tplinkpos)', 'focus mouseover', function() {
			var a = this;
			var $a = $(this);
			$a.addClass('tplinkpos');
			var is_local = (a.href.substring(0,4) === "http") ? relative_test.test(a.href) : true;
			if ( !is_local ) return;

			for ( var pos in positions ) {
				var sel = positions[pos];
				if ( $a.is(sel + ' a') ) a.name += '&lpos=' + pos;
			}
		});

	/* --------------------------------
	| Page Specific ---------------- */
	if ( $body.is('.page-iframes-header, .page-iframes-slim-header') ) {
		// Kill the query string on iframed pages and replace with new destination
		$('#site-user-nav a').each(function() {
			var link = this.href;
			if ( link.indexOf('?') !== -1 ) {
				link = link.substring(0, link.indexOf('?'));
			}
			link += '?destination=' + document.referrer;
			this.href = link;
		});
	}
});

})(window, jQuery);
