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
				$div.find('*:not(form,input,label,legend,select,textarea,option,h1):not(:has(textarea,input,label,select,option,legend,h1))').remove();

				/*var $type = $div.find('#edit-type');

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
				}*/

				var $repeaters = $div.find('.repeating');

				$repeaters.each(function(i) {
					var $repeater = $(this);
					var $up = $('<a href="#" class="wordlet_up">Up</a>');
					var $down = $('<a href="#" class="wordlet_down">Down</a>');
					var $inputs = $repeater.find('input, textarea, select');

					var up = function(e) {
						e.preventDefault();
						var $previnputs = $($repeaters.get(i - 1)).find('input, textarea, select');

						$inputs.each(function(ii) {
							var $input = $(this);
							var $previnput = $($previnputs.get(ii));
							var value = $input.val();
							var prevvalue = $previnput.val();

							$input.val(prevvalue);
							$previnput.val(value);
						});
					};

					var down = function(e) {
						e.preventDefault();

						var $nextinputs = $($repeaters.get(i + 1)).find('input, textarea, select');

						$inputs.each(function(ii) {
							var $input = $(this);
							var $nextinput = $($nextinputs.get(ii));
							var value = $input.val();
							var nextvalue = $nextinput.val();

							$input.val(nextvalue);
							$nextinput.val(value);
						});
					};

					$up.bind('click', up);
					$down.bind('click', down);

					if ( i != 0 ) $repeater.append($up);

					if ( i != $repeaters.length - 1 ) $repeater.append($down);
				});

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

				/*if ( $type.length ) {
					type_change();
				}*/
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
		var $link = $(this).find('.wordlet_configure, .wordlet_edit');
		load_form($link.data('href'));
		e.preventDefault();
		e.stopPropagation();
	})
	.delegate('.wordlet_configure, .wordlet_edit', 'click', function(e) {
		load_form($(this).data('href'));
		e.preventDefault();
		e.stopPropagation();
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

$('a:has(.wordlet_configure, .wordlet_edit)').each(function() {
	var $this = $(this);
	var $wordlet = $this.find('.wordlet');
	var $a = $('<a href="' + this.href + '" class="wordlet_helper_link">Open Link</a>')
		.css({
			display: 'block',
			position: 'absolute',
			right: '100%',
			top: 0,
			zIndex: 10000
		})
		.appendTo('body')
		;

	var do_hide = true;
	var hide = function() {
		if ( do_hide ) $a.css({left: '', right: '100%', top: 0});
	}

	$this
		.bind('mouseenter', function(e) {
			do_hide = false;

			if ( $a.css('right') != '100%' ) return true;

			var x = $wordlet.offset().left + $wordlet.width();
			var y = $wordlet.offset().top;

			$a
				.css({
					right: '',
					left: x,
					top: y
				});
		})
		.bind('mouseleave', function(e) {
			do_hide = true;
			setTimeout(hide, 0);
		})
		;

	$a
		.bind('mouseenter', function(e) {
			do_hide = false;
		})
		.bind('mouseleave', function(e) {
			do_hide = true;
			setTimeout(hide, 0);
		})
		;
});

$('#toolbar .toolbar-shortcuts .menu')
	.append($menu)
	.append($('.tabs.primary li'));

});

})(window, jQuery);