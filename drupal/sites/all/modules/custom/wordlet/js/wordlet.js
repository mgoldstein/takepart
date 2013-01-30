(function(window, $, undefined) {
$(function() {

var rscript = /<script\b[^<]*(?:(?!<\/script>)<[^<]*)*<\/script>/gi;

var load_form = function(url, data) {
	data = data || null;
	$.tpmodal.show({id: 'wordlets'});

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
					$.tpmodal.show({id: 'wordlets', html: $success});
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
							$string.hide();
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

				$.tpmodal.show({id: 'wordlets', html: $div});

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
})(window, jQuery);