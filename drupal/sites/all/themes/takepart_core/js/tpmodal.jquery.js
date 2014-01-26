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
	hideOnModalClick: false,
	afterClose: null,
	autoReposition: true,
	height: null,
	width: null,
	alertOnChange: false,

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

	this.load = function(parameters) {
		var settings = get_settings(parameters);

		if ( settings.url ) {
			if ( settings.url.match(img_search) ) {
				me.loadImage(settings, settings.url);
			} else {
				var extra = '';
				if ( settings.urlSelector ) extra = ' ' + settings.urlSelector;
				me.loadUrl(settings, settings.url + extra);
			}
		} else if ( settings.html !== null ) {
			me.loadHtml(settings, settings.html);
		} else if ( settings.node !== null ) {
			me.loadNode(settings, settings.node);
		} else {
			me.loadNode(settings, null);
		}
	};

	this.show = function(parameters) {
		me.load(parameters);
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
			/*var fake_settings = $.extend({}, settings, {callback: null});
			me.showNode(fake_settings, null);*/
			me.showHtml(settings, settings.html);
		} else if ( settings.node !== null ) {
			me.showNode(settings, settings.node);
		} else {
			me.showNode(settings, null);
		}
	};

	/* Image -------------------------------- */
	this.loadImage = function(parameters, src, readyfn) {
		var settings = get_settings(parameters);
		var img = new Image();

		// once image is preloaded, resize image container
		img.onload = function() {
			img.onload = function(){}; // clear onLoad, IE behaves irratically with animated gifs otherwise

			me.loadNode(parameters, img);
			if ( readyfn ) readyfn();
		};

		img.src = src;
	}

	this.showImage = function(parameters, src) {
		me.loadImage(parameters, src, function() {
			me.showModal(parameters);
		});
	};

	/* HTML -------------------------------- */
	this.loadHtml = function(parameters, html) {
		var settings = get_settings(parameters);
		var $div = $('<div/>');
		$div.html(html);
		me.loadNode(parameters, $div);
	};

	// TODO: reduce duplicate code
	this.showHtml = function(parameters, html) {
		var settings = get_settings(parameters);
		var $div = $('<div/>');
		$div.html(html);

		me.showNode(parameters, $div);
	};

	/* AJAX -------------------------------- */
	var ajaxer;
	this.loadUrl = function(parameters, url, readyfn) {
		var settings = get_settings(parameters);

		var $div = $('<div/>');

		ajaxer = $div.load(url, function(data, status) {
			me.loadNode(settings, $div);
			if ( readyfn ) readyfn();
		});
	};

	this.showUrl = function(parameters, url) {
		loadUrl(parameters, url, function() {
			me.showModal(parameters);
		});
	};

	/* Show/Hide -------------------------------- */
	var hide_modal = function() {
		me.hide();
	};

	/* Node -------------------------------- */
	this.loadNode = function(parameters, node) {
		var settings = get_settings(parameters);

		if ( showing ) {
			// Do something?
		}

		$modal_content
			.html('')
			.append(node)
			.css({
				width: 'auto',
				height: 'auto'
			});

		if ( node ) $modal.removeClass(settings.prepend + 'loading');
		if ( settings.hideOnModalClick ) $modal.bind('click', hide_modal);
	};

	this.showModal = function(parameters) {
		var settings = get_settings(parameters);

		// store the modal's contents. At this point, the
		// the modal is hidden, so we need to clone the contents,
		// display them, and test height and width.
		var $child = $modal_content.children().first().clone();

		$child
			.css({
				position: 'absolute',
				bottom: '100%' // off the top of the page
			})
			.appendTo('body')
			.show()
		;

		var modalHeight = $child.height();
		var modalWidth = $child.width();

		$child.remove();

		$modal_content.css({
			height: 'auto',
			width: 'auto',
			opacity: 0,
			display: 'block'
		});
		
		me.position(parameters, {
			height: modalHeight,
			width: modalWidth
		});

		$modal_content
			.css({
				opacity: 1
			});

		$overlay
			.css({display: 'block'})
			.animate({opacity: settings.opacity}, settings.speed);

		$modal
			.css({display: 'block'})
			.animate({opacity: 1}, settings.speed);
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
			if ( settings.hideOnModalClick ) $modal.bind('click', hide_modal);
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

		animate = animate || false;
		css.position = 'fixed';
		css.margin = 'auto';
		css.top = '0';
		css.bottom = '0';
		css.left = '0';
		css.right = '0';

		if ( animate ) {
			$modal.animate(css, settings.speed, function() {
				$modal_content.css({height: '', width: ''});
				if ( settings.callback ) settings.callback();
			});
		} else {
			$modal.css(css);
			$modal_content.css({height: '', width: ''});
			if ( settings.callback ) settings.callback();
		}
	};

	this.hide = function(parameters) {
		var settings = get_settings(parameters);

		if ( ajaxer && ajaxer.abort ) {
			ajaxer.abort();
			ajaxer = null;
		}

		if ( settings.alertOnChange && form_edited && !confirm('Form has been edited. Continue?') ) return false;

		$modal.unbind('click', hide_modal);

		$modal_content.css({
			height: $modal_content.height(),
			width: $modal_content.width()
		});
		//.html('');

		$overlay.animate({opacity: 0}, settings.speed, function() {
			$overlay.hide();
		});

		$modal.animate({opacity: 0}, settings.speed, function() {
			if ( settings.afterClose ) settings.afterClose();
			$modal.hide();
			$modal_content.html('');
			$modal.css({
				width: '',
				height: '',
				left: '',
				top: ''
			});

			$modal_content.css({
				width: '',
				height: '',
				visibility: ''
			});
		});

		$root.removeClass(settings.prepend + 'showing');
		showing = false;
	};

	this.set = function(parameters) {
		settings = $.extend({}, settings, parameters.values);
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
		me.position(settings);
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
	load: function(parameters) {
		var modal = get_modal(parameters);
		modal.load(parameters);
	},
	show: function(parameters) {
		var modal = get_modal(parameters);
		modal.show(parameters);
	},
	showModal: function(parameters) {
		var modal = get_modal(parameters);
		modal.showModal(parameters);
	},
	hide: function(parameters) {
		var modal = get_modal(parameters);
		modal.hide(parameters);
	},
	position: function(parameters, css, animate) {
		var modal = get_modal(parameters);
		modal.position(parameters, css, animate);
	},
	set: function(parameters) {
		var modal = get_modal(parameters);
		modal.set(parameters);
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