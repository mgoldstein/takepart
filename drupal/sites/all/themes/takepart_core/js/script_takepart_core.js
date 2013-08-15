(function (window, $, undefined) {

// Document Ready
$(function() {
	var $body = $('body');


	// INTERSTITIALS

	interstitial_init();

	function interstitial_init(){
		if($('#block-pm-interstitial-interstitials .content a').length > 0){
			show_interstitial('/interstitials/social-follows');
		}
		return;

		var interstitial_cookie = $.cookie('pm_igloo');
		var referer_cookie = $.cookie('pm_referers');
		var referers = $('body').attr('data-interstitial-referer');
		if (typeof referers === 'undefined'){ // opt out
			return;
		}

		if (interstitial_cookie === null){ // first page view
			// create ignore interstitial cookie and set to off
			$.cookie('pm_igloo', 0);
			
			// create referer list cookie
			$.cookie('pm_referers', referers);

		} else if(interstitial_cookie === '0') { // second page view (or subsequent page view without closing the interstitial)
			var excluded_links = $.cookie('pm_referers').split(',');
			var $interstitial_links = $('#block-pm-interstitial-interstitials .content a');
			if($interstitial_links.length <= 0){
				return;
			}
			
			// exclude referrer classes and map the remaining hrefs
			var interstitial_hrefs = $.map($interstitial_links, function(link, i){
				if ($.inArray($(link).attr('data-interstitial-type'), excluded_links) === -1){
					return $(link).attr('href');
				}
			});
			// show random href from list of available interstitials
			show_interstitial(interstitial_hrefs[Math.floor(Math.random() * interstitial_hrefs.length)]);
		}
	}

	function show_interstitial(address){
		var interstitial_modal_id = 'interstitial_modal_';
		var $iframe = $('<iframe src="' + address + '"></iframe>').css({border: '0'});
		
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
						takepart.analytics.track('tpinterstitial_dontshow');
					}
				}
			});
			$.tpmodal.hide({id: interstitial_modal_id});
		};

		window.interstitial_social_click = function(service){
			if (service === "twitter"){
				takepart.analytics.track('tpinterstitial_twitter');
			} else if (service === "facebook"){
				takepart.analytics.track('tpinterstitial_facebook');
			}
		}

		$.tpmodal.load({
			id: interstitial_modal_id,
			node: $iframe,
			afterClose: function() {
				extend_pm_interstitial_cookie(7);
				takepart.analytics.track('tpinterstitial_dismiss');
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
