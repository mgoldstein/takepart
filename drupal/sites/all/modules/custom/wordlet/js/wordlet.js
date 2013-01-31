(function(window, $, undefined) {
$(function() {

var rscript = /<script\b[^<]*(?:(?!<\/script>)<[^<]*)*<\/script>/gi;
var modal_id = 'wordlets_';

var load_form = function(url, data) {
	data = data || null;
	$.tpmodal.show({id: modal_id});

	// Updated jQuery.load function, basically:
	// Request the remote document
	jQuery.ajax({
		url: url,
		type: ((data)?'POST':'GET'),
		dataType: "html",
		data: data,
		// Complete callback (responseText is used internally)
		complete: function (jqXHR, status, responseText) {
			// Store the response as specified by the jqXHR object
			responseText = jqXHR.responseText;
			// If successful, inject the HTML into all the matched elements
			if (jqXHR.isResolved()) {
				// #4825: Get the actual response in case
				// a dataFilter is present in ajaxSettings
				jqXHR.done(function (r) {
					responseText = r;
				});

				responseText = responseText.replace(rscript, "");
				var $div = $('<div/>');
				$div.html(responseText);

				// Sniff for a success and close the modal
				var $success = $div.find('.messages.status');
				if ( $success.length ) {
					$.tpmodal.show({id: modal_id, html: $success});
					setTimeout(function() {
						// $.tpmodal.hide({id: 'wordlets'});
						location.reload(true);
					}, 2000);
					return true;
				}

				// Otherwise, condense html to just the form
				$div.find('*:not(form,input,label,select,textarea,option):not(:has(textarea,input,label,select,option))').remove();

				var $type = $div.find('#edit-type');

				if ( $type.length ) {
					var $string = $div.find('.form-item-string-value');
					var $text = $div.find('.form-item-text-value');
					var $integer = $div.find('.form-item-integer-value');

					var type_change = function(e) {
						var val = $type.val();
						if ( val == 'single-line' ) {
							$string.show();
							$text.hide();
							$integer.hide();
						} else if ( val == 'multiple-lines' ) {
							$string.hide();
							$text.show();
							$integer.hide();
						} else {
							$string.show();
							$text.hide();
							$integer.show();
						}
					};

					$type.bind('change', type_change);
				}

				// Submit hook
				$div.find('form')
					.each(function() {
						this.onsubmit = null;
					})
					.bind('submit', function(e) {
						var $this = $(this);
						load_form(this.action, $this.serializeArray());

						e.preventDefault();
					});

				$.tpmodal.show({id: modal_id, html: $div, callback: function() {
					setTimeout(function() {
						$div.find('textarea').autosize();
					}, 600);
				}});

				if ( $type.length ) {
					type_change();
				}
			}
		}
	});
};

// Lazily copy/pasted cookie functions
var setCookie = function(c_name, value, exdays) {
	var exdate=new Date();
	exdate.setDate(exdate.getDate() + exdays);
	var c_value=escape(value) + ((exdays==null) ? "" : "; expires="+exdate.toUTCString());
	document.cookie=c_name + "=" + c_value;
};

var getCookie = function(c_name) {
	var i,x,y,ARRcookies=document.cookie.split(";");
	for (i=0;i<ARRcookies.length;i++) {
		x=ARRcookies[i].substr(0,ARRcookies[i].indexOf("="));
		y=ARRcookies[i].substr(ARRcookies[i].indexOf("=")+1);
		x=x.replace(/^\s+|\s+$/g,"");
		if (x==c_name) {
			return unescape(y);
		}
	}
};

// Wordlet toggle menu
var $menu = $('<li id="wordlet_toggle"><a id="wordlets_show" href="">Show Wordlets</a><a id="wordlets_hide" href="">Hide Wordlets</a></li>');

// Wordlet events & other setup
$('body')
	.delegate('.wordlet', 'click', function(e) {
		var $link = $(this).find('.wordlet_add, .wordlet_edit');
		load_form($link.attr('href'));
		e.preventDefault();
	})
	.delegate('.wordlet_configure, .wordlet_edit', 'click', function(e) {
		load_form(this.href);
		e.preventDefault();
	})
	.delegate('#wordlet_toggle', 'change', function(e) {
		var $this = $(this);
		if ( this.checked ) {
			$('body').addClass('show_wordlets');
		} else {
			$('body').removeClass('show_wordlets');
		}
	})
	.delegate('#wordlets_show', 'click', function(e) {
		setCookie('show_wordlets', 1, 100);
	})
	.delegate('#wordlets_hide', 'click', function(e) {
		setCookie('show_wordlets', '', -1);
	})
	.addClass((getCookie('show_wordlets')?'':'hide_wordlets'))
	;

	$('#toolbar .toolbar-shortcuts .menu')
		.append($menu);
});

/*

Unobtrusive Accessible jQuery Auto Sizing Textarea

Overview:
	Makes textareas automatically expand when input nears the bottom.
	If the textarea is resized, the new maxHeight is set to the textarea's
	new height.

	If you call the .autosize method on a textarea twice, the settings will
	be set to the new method's parameters.

Usage:
	$('textarea').autosize();

Parameters:
	maxHeight: (Int) Maximum height textarea should resize to. null = no maximum
		Default: null
	expandAmount: (Int) Number of pixels to add to the height of the textarea
		Default: 32
	bufferHeight: (Int) How close in pixels to the bottom of the textarea
						content should get
		Default: 16
	intervalTime: (Int) Time to wait to check for textarea change
		Default: 400

Authors:
	http://james.padolsey.com, gburns

TODO:

*/

$.fn.autosize = function(parameters) {
	var settings = $.extend({
		maxHeight: null,
		expandAmount: 32,
		bufferHeight: 16,
		intervalTime: 400
	}, parameters || {});

	return this.each(function() {
		var $this = $(this);
		if ( !$this.is('textarea') ) $('textarea', this).autoexpand();

		// Check to see if .autosize() has already been called on this textarea
		if ( this.autosize_change_parameters ) {
			this.autosize_change_parameters(settings);
			return;
		}

		var $fauxbox;
		var interval;
		var keypressed = false;
		var maxHeight = parseInt(settings.maxHeight);
		var curHeight;
		var ignorePropChange = false;
		var expandAmount = parseInt(settings.expandAmount);
		var bufferHeight = parseInt(settings.bufferHeight);
		var intervalTime = parseInt(settings.intervalTime);

		this.autosize_change_parameters = function(settings) {
			maxHeight = parseInt(settings.maxHeight);
			expandAmount = parseInt(settings.expandAmount);
			bufferHeight = parseInt(settings.bufferHeight);
			expand(true);
		};

		$this
			.css({
				overflowY: 'hidden',
				resize: 'none'
			})
			.bind($.browser.msie ? 'propertychange' : 'DOMAttrModified', function() {
				if ( !ignorePropChange && $this.css('height') != curHeight ) {
					changeMaxHeight(parseInt($this.css('height')));
				}
			});

		var changeMaxHeight = function(h) {
			maxHeight = h;
			if ( parseInt(curHeight) > maxHeight ) {
				ignorePropChange = true;
				$this.css({height: maxHeight});
				$this.css({overflowY: 'auto'});
				ignorePropChange = false;
			}
		};

		// Only run expand if a key has been pressed
		var checkExpand = function() {
			if ( keypressed ) expand(true);
		};

		var expand = function(textchange) {
			keypressed = false;

			if ( textchange ) {
				$fauxbox
					.val($this.val());
			}

			$fauxbox
				[0].scrollTop = 10000;

			if ( $.browser.msie ) {
				var rng = $fauxbox[0].createTextRange();
				rng.collapse(false);
				rng.select();
			}

			var fauxheight = $fauxbox.innerHeight() - parseInt($fauxbox.css('paddingTop')) - parseInt($fauxbox.css('paddingBottom'));
			var thisheight = $this.innerHeight() - parseInt($this.css('paddingTop')) - parseInt($this.css('paddingBottom'));

			var scrollTop = $fauxbox[0].scrollTop + fauxheight;

			if ( maxHeight && scrollTop > maxHeight ) {
				ignorePropChange = true;
				$this.css({
					overflowY: 'auto',
					height: maxHeight
				});
				curHeight = $this.css('height');
				ignorePropChange = false;
			} else if ( scrollTop + bufferHeight > thisheight ) {
				ignorePropChange = true;
				$this.css({
					height: scrollTop + expandAmount,
					overflowY: 'hidden'
				});
				curHeight = $this.css('height');
				ignorePropChange = false;
			} else if ( scrollTop + bufferHeight < thisheight ) {
				ignorePropChange = true;
				$this.css({
					height: scrollTop + expandAmount,
					overflowY: 'hidden'
				});
				curHeight = $this.css('height');
				ignorePropChange = false;
			}
		};

		var makebox = function() {
			if ( !$fauxbox ) $fauxbox = $this.clone().removeAttr('id').removeAttr('name').attr({tabIndex: -1});

			$fauxbox.css({
				position: 'absolute',
				top: 0,
				left: -10000,
				resize: 'none',
				width: $this.css('width'),
				lineHeight: $this.css('lineHeight'),
				textDecoration: $this.css('textDecoration'),
				letterSpacing: $this.css('letterSpacing'),
				fontSize: $this.css('fontSize'),
				fontFamily: $this.css('fontFamily')
			});

			$fauxbox.appendTo('body');
		};

		var setKeyPressed = function() {
			keypressed = true;
		};

		$this.bind('keyup', setKeyPressed);

		$this.bind('focus', function() {
			makebox();
			interval = window.setInterval(checkExpand, intervalTime);
		});

		$this.bind('blur', function() {
			clearInterval(interval);
		});

		makebox();

		setTimeout(function() {
			var val = $this.val();
			$this.val('');
			$this.val(val);
			$fauxbox.val(val);
			expand();
		}, 0);
	});
};


})(window, jQuery);