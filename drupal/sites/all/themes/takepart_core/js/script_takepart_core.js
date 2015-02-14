(function (window, $, undefined) {

// Document Ready
$(function() {
	var $body = $('body');


	// INTERSTITIALS
	interstitial_init();
	function interstitial_init(){

		// DISABLE INTERSTITIALS ON FIREFOX
		if(navigator.userAgent.toLowerCase().indexOf('firefox') > -1) {
			return;
		}

		// // FOR TESTING
		// var interstitial_links = $('#block-pm-interstitial-interstitials .content a');
		// if(interstitial_links.length > 0){
		// 	show_interstitial(interstitial_links.filter('[data-interstitial-type="email"]'));
		// }
		// return;

		var interstitial_cookie = $.cookie('pm_igloo');
		var referer_cookie = $.cookie('pm_referers') || '';
		var referers = $('body').attr('data-interstitial-referer');
		if (typeof referers === 'undefined'){ // opt out
			return;
		}

		if (interstitial_cookie === null){ // first page view

			// create ignore interstitial cookie and set to off
			$.cookie('pm_igloo', 0, { path:'/' });

			// create referer list cookie
			$.cookie('pm_referers', referers, { path:'/' });

		} else if(interstitial_cookie === '0') { // second page view (or subsequent page view without closing the interstitial)
			var excluded_links = referer_cookie.split(',');
			var $interstitial_links = $('#block-pm-interstitial-interstitials .content a');
			if($interstitial_links.length <= 0){
				return;
			}

			// exclude referrer classes and map the remaining hrefs
			var interstitial_links = $.map($interstitial_links, function(link, i){
				if ($.inArray($(link).attr('data-interstitial-type'), excluded_links) === -1){
					return $(link);
				}
			});
			// show random href from list of available interstitials
			show_interstitial(interstitial_links[Math.floor(Math.random() * interstitial_links.length)]);
		}
	}

	function show_interstitial(interstitial_link){
		var interstitial_modal_id = 'interstitial_modal_';
		var address = interstitial_link.attr('href');
		var $iframe = $('<iframe src="' + address + '"></iframe>').css({border: '0'});
		var interstitial_type = interstitial_link.attr('data-interstitial-type');
		var analytics_types = {
			'email': 'Newsletter',
			'social': 'Social'
		};

		$iframe.bind('load', function(){
			var $modal = $('#' + interstitial_modal_id + 'modal');
			$modal.show();
			var w = $iframe.contents().find('#page').width();
			var h = $iframe.contents().find('html').height();
			$modal.hide();
			$iframe.css({width: w, height: h});
			$modal.css({overflow: 'hidden'});
			$.tpmodal.showModal({id: interstitial_modal_id});
			takepart.analytics.track('tpinterstitial_show_modal', {interstitial_type: analytics_types[interstitial_type]});
		});

		var extend_pm_interstitial_cookie = function(days){
			var date = new Date();
			date.setTime(date.getTime() + (days * 24 * 60 * 60 * 1000));
			$.cookie('pm_igloo', null);
			$.cookie('pm_igloo', 1, { expires:date, path:'/' });
		};

		window.dont_show_interstitial = function() {
			$.tpmodal.set({
				id: interstitial_modal_id,
				values: {
					afterClose: function() {
						extend_pm_interstitial_cookie(365 * 5);
						takepart.analytics.track('tpinterstitial_dontshow', {interstitial_type: analytics_types[interstitial_type]});
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

		window.interstitial_newsletter_signup = function(title){
			takepart.analytics.track('tpinterstitial_newsletter_signup', {title: title});
		}

		$.tpmodal.load({
			id: interstitial_modal_id,
			node: $iframe,
			afterClose: function() {
				extend_pm_interstitial_cookie(7);
				takepart.analytics.track('tpinterstitial_dismiss', {interstitial_type: analytics_types[interstitial_type]});
			}
		});
	}

	// Omniture position tracking
	// Parent/ancestor vars to track in reverse order of importance
	$.tpregions.add({
		'Header': '#site-header',
                'Slim Header' : '.slimnav',
		'Footer': 'footer',
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
		'Taboola Widget - Gallery Page': '#taboola-bottom-main-column-mix',
    'Mobile Sticky Strip Share': '.social-wrapper.mobile',
    'Mobile Sticky Strip': '.social-wrapper.mobile'
		// no need to track articles, since those are already in tp4
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

(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.geoLimiting = {
    attach: function() {
      $('.geo-limited-video').once('initialized', function(index, element) {
        var player = element;
        var showBlocked = function() {
          $('.video-loading', player).hide();
          $('.video-blocked', player).show();
        };
        var handleRegion = function(response) {
          if (!response.country.iso_code) { showBlocked(); return false; }
          var code = response.country.iso_code.toLowerCase();
          var regions = $(player).attr('data-allowed-regions').split(',');
          if ($.inArray(code, regions) < 0) { showBlocked(); return false; }
          var url = window.location.protocol
            + "//content.jwplatform.com/players/"
            + $(player).attr('data-botr-id') + ".js";
          $.getScript(url).fail(showBlocked);
        };
        geoip2.country(handleRegion, showBlocked);
      });
    },
    attach: function(context, settings) {
	    //Toggle search on mobile
	    $('html').click(function() {
	      $('.search-toggle').parent().removeClass('active');
	    });

	    $('.search-toggle').parent().click(function(event){
	        event.stopPropagation();
	        $(this).addClass('active');
	    });
	  }
  };
})(jQuery, Drupal, this, this.document);


