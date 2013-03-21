(function(window, $, undefined) {

/*
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

// Return string from template
var twitter_tpl_reg = /{{([a-zA-Z\-_]+)}}/g;
var template_tplvar_clean_reg = /({{)|(}})/g;

var template_value = function(tpl_name, args) {
	// Replace variables in twitter template
	var text = args[tpl_name] || '';
	var matches = text.match(twitter_tpl_reg);

	for ( var i in matches ) {
		var match = matches[i];
		var prop = match.replace(template_tplvar_clean_reg, '');

		if ( match != tpl_name && args[prop] != undefined && args[prop] ) {
			text = text.replace(match, args[prop]);
		} else {
			text = text.replace(match, '');
		}
	}

	return text;
};

// Load script and run callback
var queues = {};
var load_script = function(test, url, context, callback) {
	if ( test != undefined ) {
		callback.call(context);
		return true;
	}

	if ( queues[url] == undefined ) queues[url] = [];
	queues[url].push(callback);

	var ready = function(s) {
		// Use this in IE if we want to track throughout the load.
		if ( s.readyState == 'loaded' || s.readyState == 'complete' ) done();
	}

	var done = function() {
		for ( var i in queues[url] ) {
			var cb = queues[i];
			cb.call(context);
		}
	}

	var s = document.createElement('script');
	s.type = "text/javascript";
	s.onreadystatechange = function(s) { return function() { ready(s) } }(s);
	s.onerror = s.onload = done;
	s.src = url;
	document.getElementsByTagName('head')[0].appendChild(s);
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

			// Set up link
			var data = $.extend({}, defaults, srvc, get_data($this, dpre + srvc.name + '-', dpre), get_data($link, dpre + srvc.name + '-', dpre));
			if ( typeof data.prepare == 'function' ) {
				data.prepare($link[0], data);
			}

			// Bind an event to the link
			$link
				.bind('click', (function(srvc, $parent, $lnk) {
						return function(e) {
							var data = $.extend({}, defaults, srvc, get_data($parent, dpre + srvc.name + '-', dpre), get_data($lnk, dpre + srvc.name + '-', dpre));
							data.element = this;

							srvc.share(data);
							e.preventDefault();
						}
					})(srvc, $this, $link)
				);
			if ( typeof data.hoverfocus == 'function' ) {
				$link
					.bind('mouseover focus', (function(srvc, $parent, $lnk) {
							return function(e) {
								var data = $.extend({}, defaults, srvc, get_data($parent, dpre + srvc.name + '-', dpre), get_data($lnk, dpre + srvc.name + '-', dpre));
								data.element = this;

								srvc.hoverfocus(data);
								//e.preventDefault();
							}
						})(srvc, $this, $link)
					);
			}
		}

		$this.data(dpre + 'processed', true);
		$this.addClass(cpre + 'processed');
	});
};

var valid_services = {};

$.tpsocial = {
	add_service: function(args) {
		valid_services[args.name] = args;
	}
};

// Temp: event tracking example

$window.bind('tp-social-share', function(e, args) {
	console.log('tp-social-share')
	console.log(args)
});

$.tpsocial.add_service({
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
});

$.tpsocial.add_service({
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
		var windowOptions = 'scrollbars=yes,resizable=yes,toolbar=no,location=yes';
		var left = 0;
		var tops = Number((screen.height/2)-(args.height/2));
		window.open(url, undefined, [windowOptions,"width="+args.width,"height="+args.height,"left="+left,"top="+tops].join(", "));

		// TODO use Twitter's twttr object for the sake of event tracking
		$window.trigger(cpre + 'share', args);
	}
});

$.tpsocial.add_service({
	name: 'googleplus',
	display: 'Google +1',
	width: 600,
	height: 600,
	share: function(args) {
		var url = 'https://plus.google.com/share?url=' + encodeURIComponent(args.url);

		var windowOptions = 'menubar=no,toolbar=no,resizable=yes,scrollbars=yes';
		/*var left = 0;
		var tops = Number((screen.height/2)-(args.height/2));*/
		window.open(url, undefined, [windowOptions,"width="+args.width,"height="+args.height/*,"left="+left,"top="+tops*/].join(", "));
	}
});

$.tpsocial.add_service({
	name: 'email',
	display: 'Email',
	share: function(args) {

	},
	prepare: function(el, args) {
	},
	hoverfocus: function(args) {
		var note = template_value('note', args);

		var email_config = {
			ui_email_note: note
		};

		var addthis_config = {
			url: args.url,
            title: args.title
		};

		$(args.element)
			.addClass('addthis_button_email addthis_button_compact');

		load_script(addthis, 'http://s7.addthis.com/js/250/addthis_widget.js#pubid=ra-4e48103302adc2d8', this, function() {
			addthis.toolbox(
				$(args.element).parent()[0],
				email_config,
				addthis_config
			);
		});
	}
});


$(function() {
	var tp_social_defaults = {
		services: [
			{name: 'facebook'},
			{name: 'twitter'},
			{name: 'googleplus'},
			{name: 'email'}
		]
	};

	$('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_defaults);
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