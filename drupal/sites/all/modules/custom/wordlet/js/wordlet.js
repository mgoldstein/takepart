(function(window, $, undefined) {
$(function() {

var rscript = /<script\b[^<]*(?:(?!<\/script>)<[^<]*)*<\/script>/gi;
var modal_id = 'wordlets_';
var adding = false;

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
					if ( adding ) {
						adding = false;
						load_form(url);
					} else {
						$.tpmodal.show({id: modal_id, html: $success});
						//setTimeout(function() {
							// $.tpmodal.hide({id: 'wordlets'});
							location.reload(true);
						//}, 2000);
					}
					return true;
				}

				// Otherwise, condense html to just the form
				$div.find('*:not(form,input,label,legend,select,textarea,option,h1,.messages.error,.form-required):not(:has(textarea,input,label,select,option,legend,h1,.messages.error,.form-required))').remove();

				var $repeaters = $div.find('.repeating');

				// Add an extra submit button to refresh the form if "repeaters" are found
				if ( $repeaters.length ) {
					var $submit = $div.find('#edit-submit');
					var $add = $submit.clone();
					$add.attr('value', $add.attr('value') + ' and Add Another');
					$submit.attr('value', $submit.attr('value') + ' and Close');
					$add.insertAfter($submit);
					$add.bind('click', function() {
						adding = true;
					});
				}

				// Move values up/down
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

				// Enable/disable inputs based on "Enabled" checkboxes
				var check_enabled = function() {
					$div.find('#wordlet-edit-form-data input[type="checkbox"]').each(function() {
						var $cb = $(this);
						var f = $cb.data('for');
						if ( f ) {
							var $i = $div.find('.' + f);
							var $p = ( $i.is('textarea') ) ? $i.parent().parent() : $i.parent();
							if ( $cb.is(':checked') ) {
								$p.css({height: 'auto'});
							} else {
								$p.css({height: 0});
							}
						}
					});
				};

				check_enabled();

				$div.find('#wordlet-edit-form-data input[type="checkbox"]').bind('change', check_enabled);

				$div.find('#wordlet-edit-form-data').find('.form-type-textfield, .form-type-textarea')
					.css({
						overflow: 'hidden'
					});

				var $wysiwyg = null;
				var wysiwyg_id = null;

				// Submit hook
				$div.find('form')
					.each(function() {
						this.onsubmit = null;
					})
					.bind('submit', function(e) {
						var $this = $(this);
						if ( $wysiwyg.length  ) {
							$wysiwyg.css({
								display: 'block',
								height: '1px'
							});
							$wysiwyg.val(CKEDITOR.instances[wysiwyg_id].getData());
						}
						load_form(this.action, $this.serializeArray());

						e.preventDefault();
					});

				$.tpmodal.show({id: modal_id, html: $div, callback: function() {
					$wysiwyg = $div.find('.wordlet-full-html textarea').each(function() {
						wysiwyg_id = this.id;
						$.tpmodal.set({id: modal_id, values: {
							afterClose: function() {
								delete(CKEDITOR.instances[wysiwyg_id]);
							}
						}});
						//$(this).autosize();
						CKEDITOR.replace( this, {
							pasteFromWordRemoveStyles: true,
							pasteFromWordRemoveFontStyles: true,
							pasteFromWordNumberedHeadingToList: true,
							pasteFromWordCleanupFile: true,
							autoGrow_onStartup: true,
							toolbar_Full: [
								{ name: 'document',    items : [ 'Bold','Italic','Underline','JustifyLeft','JustifyCenter','BulletedList','NumberedList','Undo','Redo','Link','Unlink','Anchor','Blockquote','Source','HorizontalRule','Cut','Copy','Paste','PasteText','PasteFromWord','RemoveFormat' ] },
								'/',
								{ name: 'styles',      items : [ 'Format','Styles' ] },
								{ name: 'colors',      items : [ 'Table', 'Scayt','Image' ] }
							]
						});

						CKEDITOR.instances[wysiwyg_id].on("instanceReady", function(event) {
							$.tpmodal.position({id: modal_id, callback: null}, null, true);
						});
					});
				}});
			}
		}
	});
};

// Lazily copy/pasted cookie functions
var setCookie = function(c_name, value, exdays) {
	var exdate=new Date();
	exdate.setDate(exdate.getDate() + exdays);
	var c_value=escape(value) + ((exdays==null) ? "" : "; expires="+exdate.toUTCString());
	document.cookie=c_name + "=" + c_value + '; path=/';
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

var deleteCookie = function(name) {
    document.cookie = name + '=; expires=Thu, 01 Jan 1970 00:00:01 GMT; path=/';
};

// Wordlet toggle menu
var $menu = $('<li id="wordlet_toggle"><a id="wordlets_show" href="">Show Wordlets</a><a id="wordlets_hide" href="">Hide Wordlets</a></li>');

$('[data-edit]').addClass('wordlet');

// Wordlet events & other setup
$('body')
	.delegate('.wordlet', 'click', function(e) {
		var $this = $(this);
		var $link = ($this.is('[data-edit]')) ? $this : $this.find('.wordlet_configure, .wordlet_edit');
		var link = $link.data('edit') || $link.data('configure');
		load_form(link);
		e.preventDefault();
		e.stopPropagation();
	})
	.delegate('.wordlet_configure', 'click', function(e) {
		load_form($(this).data('configure'));
		e.preventDefault();
		e.stopPropagation();
	})
	.delegate('.wordlet_edit', 'click', function(e) {
		load_form($(this).data('edit'));
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
		deleteCookie('show_wordlets');
	})
	.addClass((getCookie('show_wordlets')?'':'hide_wordlets'))
	;

//$('a:has(.wordlet_configure, .wordlet_edit)').each(function() {
$('.wordlet:not(:has(.wordlet_configure))').each(function() {
	var $this = $(this);
	//var $wordlet = $this.find('.wordlet');

	var $link = $this.closest('a');
	var $edit = ( $this.is('[data-edit]') ) ? $this : $this.find('.wordlet_edit');
	if ( !$edit.data('configure') && !$link.length ) return true;
	var $configure = $this.find('.wordlet_configure');
	var edit = null;
	var configure = null;

	var $container = $('<div/>')
		.addClass('wordlet_helper_container')
		.css({
			display: 'block',
			position: 'absolute',
			right: '100%',
			top: 0,
			zIndex: 10000
		})
		.appendTo('body')
		;


	if ( $link.length ) {
		var $wlink = $('<a href="' + $link[0].href + '">Open Link</a>');
		$wlink.html('Open Link');
		$container.append($wlink);
	}

	if ( $edit.length ) {
		edit = $edit.data('edit');
		configure = ( $edit.data('configure') ) ? $edit.data('configure') : null;
	} else if ( $configure.length ) {
		configure = $edit.data('configure');
	}

	/*if ( edit ) {
		var $wedit = $('<span class="wordlet_edit" data-edit="' + edit + '">Edit</a>');
		$container.append($wedit);
	}*/

	if ( configure ) {
		var $wconfigure = $('<span class="wordlet_configure" data-configure="' + configure + '">Configure</a>');
		$container.append($wconfigure);
	}

	var do_hide = true;
	var hide = function() {
		if ( do_hide ) $container.css({left: '', right: '100%', top: 0});
	}

	$this
		.bind('mouseenter', function(e) {
			do_hide = false;

			if ( $container[0].style.right != '100%' ) return true;

			var x = $this.offset().left + $this.width();
			var y = $this.offset().top;

			$container
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

	$container
	$container
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