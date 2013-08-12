(function (window, $, undefined) {

// Document Ready
$(function() {
	var $body = $('body');

	var interstitial_url = $('body').attr('data-interstitial-provider');

	$.ajax({
		dataType: "json",
		url: interstitial_url,
		data: {},
		success: function(data){
			if(!data.show){
				//return;
			}
			data.show = 'interstitials/newsletter';
			$interstitial_link = $('<a></a>').attr('href', '/' + data.show);
			$interstitial = $('<div></div>').attr('id', 'interstitial').append($interstitial_link);
			interstitial_init($interstitial);
		}
	});

	function interstitial_init($interstitial){
		var interstitial_modal_id = 'interstitial_modal_';
		var $a = $interstitial.find('a');
		var $iframe = $('<iframe src="' + $a.attr('href') + '"></iframe>').css({border: '0'});
		var extend_pm_interstitial_cookie = function(days){
			var date = new Date();
			date.setTime(date.getTime() + (days * 24 * 60 * 60 * 1000));
			var myCookieValue = $.cookie('pm_igloo');
			$.cookie('pm_igloo', null);
			$.cookie('pm_igloo', myCookieValue, { expires:date, secure:true, path:'/' });
		};
		
		window.resize_interstitial = function(w, h) {
			$iframe.css({width: w, height: h});
			$.tpmodal.showModal({id: interstitial_modal_id});
		};

		window.dont_show_interstitial = function() {
			$.tpmodal.set({
				id: interstitial_modal_id,
				values: {
					afterClose: function() {
						extend_pm_interstitial_cookie(365 * 5);
					}
				}
			});
			$.tpmodal.hide({id: interstitial_modal_id});
		};

		$.tpmodal.load({
			id: interstitial_modal_id,
			node: $iframe,
			afterClose: function() {
				extend_pm_interstitial_cookie(7);
			}
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
