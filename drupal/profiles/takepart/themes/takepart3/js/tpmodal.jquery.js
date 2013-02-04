(function(window, $, undefined) {

// Shared variables
var $window = $(window);
var img_search = /(\.jpg|\.jpeg|\.png|\.gif|\.bmp)$/;

// Default settings
var defaults = {
	id: 'tpmodal_',
	prepend: 'tpmodal_',
	root: 'body',
	speed: 500,
	opacity: .8,
	hideOnOverlayClick: true,
	afterClose: null,
	autoReposition: true,
	height: null,
	width: null,

	urlSelector: '',
	url: null,
	node: null,
	html: null,
	callback: null
};

// Modal class
var tpmodal = function(parameters) {
	// Variale setup
	var me = this;
	var settings = parameters;

	settings.urlSelector = defaults.urlSelector;
	settings.url = defaults.url;
	settings.node = defaults.node;
	settings.html = defaults.html;
	settings.callback = defaults.callback;

	this.settings = settings;
	var $root = $(settings.root);
	var showing = false;
	var form_edited = false;

	var $overlay = $('<div/>')
		.addClass(settings.prepend + 'overlay')
		.addClass(settings.id + 'overlay')
		.css({
			position: 'fixed',
			left: 0,
			top: 0,
			width: '100%',
			height: '100%',
			// TODO: Find highest?
			zIndex: 10000,
			opacity: 0
		})
		.attr({id: settings.id + 'overlay'})
		.hide();

	var $modal = $('<div/>')
		.addClass(settings.prepend + 'modal')
		.addClass(settings.id + 'modal')
		.css({
			position: 'absolute',
			// TODO: Find highest?
			zIndex: 10001,
			opacity: 0
		})
		.attr({id: settings.id + 'modal'})
		.hide();

	var $modal_dummy = $modal.clone()
		.addClass(settings.prepend + 'modal_dummy')
		.addClass(settings.id + 'modal_dummy')
		.attr({id: settings.id + 'modal_dummy'})
		.hide();

	var $modal_content = $('<div/>')
		.addClass(settings.prepend + 'content')
		.addClass(settings.id + 'content')
		.css({
			opacity: 0
		});

	var $modal_content_dummy = $modal_content.clone()
		.addClass(settings.prepend + 'content_dummy')
		.addClass(settings.id + 'content_dummy')
		;

	var $close = $('<a href="#">Close</a>')
		.addClass(settings.prepend + 'close')
		.addClass(settings.id + 'close')
		.css({
			display: 'block',
			position: 'absolute',
			right: '0',
			top: '0',
			// TODO: Find highest?
			zIndex: 10000
		});

	// Functions/methods
	var get_settings = function(parameters) {
		var new_settings = $.extend({}, settings, parameters);
		return new_settings;
	};

	this.show = function(parameters) {
		var settings = get_settings(parameters);

		if ( settings.url ) {
			if ( settings.url.match(img_search) ) {
				me.showImage(settings, settings.url);
			} else {
				var extra = '';
				if ( settings.urlSelector ) extra = ' ' + settings.urlSelector;
				me.showUrl(settings, settings.url + extra);
			}
		} else if ( settings.html !== null ) {
			me.showNode(settings, null);
			me.showHtml(settings, settings.html);
		} else {
			me.showNode(settings, null);
		}
	};

	this.showImage = function(parameters, src) {
		var settings = get_settings(parameters);
		var img = new Image();

		// once image is preloaded, resize image container
		img.onload = function() {
			img.onload = function(){}; // clear onLoad, IE behaves irratically with animated gifs otherwise

			me.showNode(settings, img);
		};

		img.src = src;
		me.showNode(settings, null);
	};

	this.showHtml = function(parameters, html) {
		var settings = get_settings(parameters);
		var $div = $('<div/>');

		$div.html(html);

		me.showNode(settings, $div);
	};

	this.showUrl = function(parameters, url) {
		var settings = get_settings(parameters);

		var $div = $('<div/>');

		$div.load(settings.url, function(data, status) {
			me.showNode(settings, $div);
		});

		me.showNode(settings, null);
	};

	this.showNode = function(parameters, node) {
		var settings = get_settings(parameters);

		$modal_content_dummy
			.append(node);

		$modal_dummy
			.css({display: 'block'});

		var mwidth = $modal_dummy.width();
		var mheight = $modal_dummy.height();

		var cwidth = $modal_content_dummy.width();
		var cheight = $modal_content_dummy.height();

		$modal_dummy.hide();

		$modal.addClass(settings.prepend + 'loading');

		var $forms = $(node).find('form');
		if ( $forms.length ) {
			$forms.find('input, textarea').bind('change', function() {
				form_edited = true;
			});
		} else {
			form_edited = false;
		}

		if ( showing ) {
			$modal_content.animate({opacity: 0}, settings.speed, function() {
				$modal_content
					.css({width: cwidth, height: cheight})
					.html('')
					.append(node)
					.animate({opacity: 1}, settings.speed);

				if ( node ) $modal.removeClass(settings.prepend + 'loading');
			});
		} else {
			$modal_content
				.css({width: cwidth, height: cheight})
				.html('')
				.append(node)
				.animate({opacity: 1}, settings.speed);

			$modal_dummy
				.css({display: 'block'});

			var mtwidth = $modal_dummy.width();
			var mtheight = $modal_dummy.height();

			$modal_dummy.hide();

			me.position(settings, {
				width: mtwidth,
				height: mtheight
			});

			if ( node ) $modal.removeClass(settings.prepend + 'loading');
		}

		$root.addClass(settings.prepend + 'showing');
		showing = true;

		$overlay
			.css({display: 'block'})
			.animate({opacity: settings.opacity}, settings.speed);

		$modal
			.css({display: 'block'});

		me.position(settings, {
			width: mwidth,
			height: mheight,
			opacity: 1
		}, true);
	};

	this.position = function(parameters, css, animate) {
		css = css || {};
		var settings = get_settings(parameters);
		css.width = css.width || $modal.width();
		css.height = css.height || $modal.height();
		animate = animate || false;

		css.left = $window.scrollLeft() + $window.width() / 2 - css.width / 2;
		css.top = $window.scrollTop() + $window.height() / 2 - css.height / 2;
		if ( css.left < $window.scrollLeft() ) css.left = $window.scrollLeft();
		if ( css.top < $window.scrollTop() ) css.top = $window.scrollTop();

		if ( animate ) {
			$modal.animate(css, settings.speed, function() {
				$modal.css({height: ''});
				$modal_content.css({height: ''});
				if ( settings.callback ) settings.callback();
			});
		} else {
			$modal.css(css);
			if ( settings.callback ) settings.callback();
		}
	};

	this.hide = function(parameters) {
		var settings = get_settings(parameters);

		if ( form_edited && !confirm('Form has been edited. Continue?') ) return false;

		$overlay.animate({opacity: 0}, settings.speed, function() {
			$overlay.hide();
		});

		$modal.animate({opacity: 0}, settings.speed, function() {
			$modal.hide();
			$modal_content.html('');
			if ( settings.afterClose ) settings.afterClose();
			$modal.css({
				width: '',
				height: '',
				left: '',
				top: ''
			});

			$modal_content.css({
				width: '',
				height: ''
			});
		});

		$root.removeClass(settings.prepend + 'showing');
		showing = false;
	};

	// Setup
	$modal
		.append($close)
		.append($modal_content);

	$modal_dummy.append($modal_content_dummy);

	$root
		.append($overlay)
		.append($modal)
		.append($modal_dummy);

	if ( settings.hideOnOverlayClick ) {
		$overlay.bind('click', function(e) {
			e.preventDefault();
			me.hide();
		});
	}

	$close.bind('click', function(e) {
		e.preventDefault();
		me.hide();
	});

	if ( settings.autoReposition ) $window.bind('resize', function() {
		this.position(settings);
	});
};

// Modals indexed by parameters.id
var modals = {};

// "Private" functions
var get_settings = function(parameters) {
	var settings = $.extend({}, defaults, parameters);
	return settings;
}

var new_modal = function(parameters) {
	var settings = get_settings(parameters);
	var modal = new tpmodal(settings);
	modals[modal.settings.id] = modal;
	return modal;
};

var get_modal = function(parameters) {
	var settings = get_settings(parameters);
	modal = modals[settings.id] || new_modal(settings);
	return modal;
};

// Public delegate functions for easy access
$.tpmodal = {
	show: function(parameters) {
		var modal = get_modal(parameters);
		modal.show(parameters);
	},
	hide: function(parameters) {
		var modal = get_modal(parameters);
		modal.hide(parameters);
	},
	position: function(parameters) {
		var modal = get_modal(parameters);
		modal.position(parameters);
	},
	get: function (parameters) {
		return get_modal(parameters);
	}
};

$.fn.tpmodal = function(parameters) {
	return this.each(function() {
		var settings = get_settings(parameters);
		var $this = $(this);

		if ( this.nodeName == 'A' ) {
			settings.url = this.href;

			$this.bind('click', function(e) {
				$.tpmodal.show(settings);
				e.preventDefault();
			});
		// Not tested
		} else if ( this.nodeName == 'FORM'  ) {
			settings.url = this.action;

			$this.bind('submit', function(e) {
				settings.data = $this.serializeArray();
				$.tpmodal.formShow(settings);
				e.preventDefault();
			});

		}
	});
};

})(window, jQuery);