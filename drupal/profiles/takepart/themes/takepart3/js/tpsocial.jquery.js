(function(window, $, undefined) {

/*
	test2
	data- attributes:
	tps-url: URL override
	tps-image: Image override
*/

// Plugin

var dpre = 'tps-';
var cpre = 'tp-social-';
var $window = $(window);

// function to make social share link
var makeLink = function(args) {
	var $link = $('<a href="#"/>')
		.addClass(cpre + args.name)
		.addClass(cpre + 'link')
		.html(args.display);

	return $link;
};

// Default values
var default_url = document.location.href;
var $rel_canonical = $('link[rel="canonical"]');
if ( $rel_canonical.length ) default_url = $rel_canonical.attr('href');

var defaults = {
	url: default_url,
	title: document.title
};

// Service specific defaults
var valid_services = {
	facebook: {
		name: 'facebook',
		display: 'Facebook',
		image: null,
		caption: null,
		description: null,
		share: function(args) {
			FB.ui({
				method: 'feed',
				name: args.title,
				link: args.url + '',
				picture: args.image,
				caption: args.caption,
				description: args.description //,
				// message: 'Facebook Dialogs are easy!' ???
			},
			function(response) {
				if (response && response.post_id) {
					// Post was published
					$window.trigger(cpre + 'share', args);
				} else {
					//Post was not published
				}
			});
		}
	},
	twitter: {
		name: 'twitter',
		display: 'Twitter',
		width: 550,
		height: 420,
		share: function(args) {
			// Replace variables in twitter template
			var twitter_tpl_reg = /{{([a-zA-Z\-_]+)}}/g;
			var template_tplvar_clean_reg = /({{)|(}})/g;

			var text = args.text || '';
			var matches = text.match(twitter_tpl_reg);

			for ( var i in matches ) {
				var match = matches[i];
				var prop = match.replace(template_tplvar_clean_reg, '');

				if ( match != 'text' && args[prop] != undefined && args[prop] ) {
					text = text.replace(match, args[prop]);
				} else {
					text = text.replace(match, '');
				}
			}

			// Create twitter URL
			var url_obj = {
				url: args.url,
				via: args.via,
				text: text,
				in_reply_to: args.in_reply_to,
				hashtags: args.hashtags,
				related: args.related
			};

			var url_parts = [];
			for ( var i in url_obj ) {
				var val = url_obj[i];
				if ( val != undefined && val ) url_parts.push(i + '=' + encodeURIComponent(val));
			}
			var url = 'https://twitter.com/intent/tweet?' + url_parts.join('&');

			// Open twitter share
			var windowOptions = 'scrollbars=yes,resizable=yes,toolbar=no,location=yes,';
			var left = 0;
			var tops = Number((screen.height/2)-(args.height/2));
			window.open(url, undefined, windowOptions + ["width="+args.width,"height="+args.height,"left="+left,"top="+tops].join(", "));
		}
	},
	googleplus: {
		name: 'googleplus',
		display: 'Google +1'
	},
	email: {
		name: 'email',
		display: 'Email'
	}
};

// Make an object based on data- attributes from the given jQuery object
var get_data = function($el, prefix_main, prefix_secondary) {
	var data = $el.data();
	var ret = {};
	var prop, i;
	for ( i in data ) {
		if ( i.indexOf(prefix_main) === 0 ) {
			prop = i.substring(prefix_main.length);
			ret[prop] = data[i];
		} else if ( i.indexOf(prefix_secondary) === 0 ) {
			prop = i.substring(prefix_secondary.length);
			ret[prop] = data[i];
		}
	}

	return ret;
};

$.fn.tpsocial = function(args) {
	//var settings = $.extend(defaults, args);
	//var services = settings.services;
	var services = args.services;

	return this.each(function() {
		var $this = $(this);
		if ( $this.data(dpre + 'processed') ) return true;

		// Loop through the requested services
		for ( var s in services ) {
			var service = services[s];
			var name = service.name;
			// See if the requested service has been added
			if ( !(name in valid_services) ) continue;
			var srvc = $.extend({}, valid_services[name], service);

			// Find the link for the requested service in the node
			var $link = $this.find('a.' + cpre + name + ', .' + cpre + name + ' a');
			// If none exists, create and append it
			if ( !$link.length ) {
				$link = makeLink(srvc);

				var $container = $this.find('.' + cpre + name);
				if ( $container.length ) {
					$container.append($link);
				} else {
					$this.append($link);
				}
			}

			// Add service specific arguments to the links'd data object
			for ( var i in service ) {
				if ( typeof service[i] == 'function' ) continue;
				$link.data(dpre + name + '-' + i, service[i]);
			}

			// Bind an event to the link
			$link
				.bind('click', (function(srvc, $parent, $lnk) {
						return function(e) {
							var data = $.extend({}, defaults, srvc, get_data($parent, dpre + srvc.name + '-', dpre), get_data($lnk, dpre + srvc.name + '-', dpre));

							srvc.share(data);
							e.preventDefault();
						}
					})(srvc, $this, $link)
				);
		}

		$this.data(dpre + 'processed', true);
		$this.addClass(cpre + 'processed');
	});
};

// Temp: event tracking example

$window.bind('tp-social-share', function(e, args) {
	console.log('tp-social-share')
	console.log(args)
});


// -----------------------------------------------
// Old: (Only PATT Alumni Gallery ----------------
// -----------------------------------------------



// Setup
var open_link = function(link, network) {
	var $this = $(link);
	var href = link.href;
	if ( link.pathname == '#' ) href = window.document.location.href;
	if ( $this.data('tpsocial-href') ) href = $this.data('tpsocial-href');
	if ( $this.data('tpsocial-' + network + '-href') ) href = $this.data('tpsocial-' + network + '-href');
	$this.data('tpsocial-' + network + '-href', href);

	switch ( network ) {
		case 'facebook':
			href = 'http://www.facebook.com/sharer/sharer.php?u=' + encodeURIComponent(href);
			break;
	}

	window.open(href, '_blank');

	takepart.analytics.track('generic_tpsocial', network);
	//link.target = '_blank';
};

// Document load
$(function() {
	$('body')
		/*.delegate('.tpsocial-facebook a, a.tpsocial-facebook', 'click focus mouseover', function(e) {
			update_link(this, 'facebook');
		})*/
		.delegate('.tpsocial-facebook a, a.tpsocial-facebook', 'click', function(e) {
			open_link(this, 'facebook');
		});
});

})(window, jQuery);