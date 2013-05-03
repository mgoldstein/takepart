(function(window, $, undefined) {
$(function() {

var rscript = /<script\b[^<]*(?:(?!<\/script>)<[^<]*)*<\/script>/gi;
var modal_id = 'wordlets_';
var adding = false;
var ajaxer = null;

var load_form = function(url, data) {
	data = data || null;
	$.tpmodal.show({id: modal_id, alertOnChange: true, afterClose: function() { if ( ajaxer ) ajaxer.abort(); }});

	// Updated jQuery.load function, basically:
	// Request the remote document
	ajaxer = jQuery.ajax({
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
				$div.find('*:not(form,input,label,legend,.description,select,textarea,option,h1,.messages.error,.form-required):not(:has(textarea,input,label,select,option,legend,.description,h1,.messages.error,.form-required))').remove();

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
					var $move = $('<a href="#" class="wordlet_move">Move</a>');
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

					$repeater.append($move);

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

				$div.find('#wordlet-edit-form-data').find('.form-type-textfield, .form-type-textarea, .form-type-container, .form-type-select, .form-type-checkbox')
					.css({
						overflow: 'hidden'
					});

				var wysiwygs = [];

				// Submit hook
				$div.find('form')
					.each(function() {
						this.onsubmit = null;
					})
					.bind('submit', function(e) {
						var $this = $(this);
						if ( wysiwygs.length  ) {
							for ( var i in wysiwygs ) {
								var w = wysiwygs[i];
								var $wysiwyg = w.$wysiwyg;
								var wysiwyg_id = w.wysiwyg_id;

								$wysiwyg.css({
									display: 'block',
									height: '1px'
								});

								$wysiwyg.val(CKEDITOR.instances[wysiwyg_id].getData());
								delete(CKEDITOR.instances[w.wysiwyg_id]);
							}
						}
						load_form(this.action, $this.serializeArray());

						e.preventDefault();
					});

				$.tpmodal.show({id: modal_id, html: $div, callback: function() {
					$div.find('.wordlet-full-html textarea').each(function() {
						var wysiwyg = {};
						wysiwyg.$wysiwyg = $(this);
						wysiwyg.wysiwyg_id = this.id;
						wysiwygs.push(wysiwyg);

						$.tpmodal.set({id: modal_id, values: {
							afterClose: function() {
								for ( var i in wysiwygs ) {
									var w = wysiwygs[i];
									delete(CKEDITOR.instances[w.wysiwyg_id]);
								}
							}
						}});

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

						CKEDITOR.instances[wysiwyg.wysiwyg_id].on("instanceReady", function(event) {
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

$('[data-edit],[data-configure]').each(function() {
	var $this = $(this);
	$this.addClass('wordlet');
	if ( $this.is('[data-configure]') && !$this.is('[data-edit]') ) $this.addClass('wordlet_configure');
});

// Wordlet events & other setup
var moving = false;
var $repeating_start = null;

$('body')
	.delegate('.wordlet', 'click', function(e) {
		var $target = $(e.target);
		if ( $target.is('input') || $target.is('textarea') || $target.is('select') || $target.is('label') ) return true;
		var $this = $(this);
		var $link = ($this.is('[data-edit]') || $this.is('[data-configure]')) ? $this : $this.find('.wordlet_configure, .wordlet_edit');
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
	// Drag/drop
	.delegate('.wordlet_move', 'mousedown', function() {
		moving = true;
		$repeating_start = $(this).closest('.repeating');
		$repeating_start.addClass('repeating_start');
		return false;
	})
	.delegate('.repeating', 'mouseover', function() {
		if ( !moving ) return;
		$(this).addClass('repeating_end');
	})
	.delegate('.repeating', 'mouseout', function() {
		if ( !moving ) return;
		$(this).removeClass('repeating_end');
	})
	.delegate('.repeating', 'mouseup', function() {
		if ( !moving ) return;
		var $this = $(this);
		if ( $this[0] == $repeating_start[0] ) return;

		if ( $repeating_start.nextAll().filter('#' + $this[0].id).length ) {
			$nexts = $repeating_start.nextUntil('#' + $this[0].id);
			$repeating_start.find('.wordlet_down').click();
			$nexts.each(function() {
				$(this).find('.wordlet_down').click();
			});
			//$this.filter('.wordlet_down').click();
		} else {
			//console.log($repeating_start.prevAll().filter('#' + $this[0].id).length);
			$prevs = $repeating_start.prevUntil('#' + $this[0].id);
			$repeating_start.find('.wordlet_up').click();
			$prevs.each(function() {
				$(this).find('.wordlet_up').click();
			});
		}

		//console.log($this.nextUntil('#' + $repeating_start[0].id));
		//console.log($this.prevUntil('#' + $repeating_start[0].id));
	})
	.bind('mouseup', function() {
		moving = false;
		$repeating_start = null;
		$('.repeating').removeClass('repeating_end').removeClass('repeating_start');
	})
	;

// Configure links
$('.wordlet_edit').each(function() {
	var $this = $(this);
	$this.parent()
		.addClass('wordlet')
		.attr({
			'data-edit': $this.data('edit'),
			'data-configure': $this.data('configure')
		});
});

$('.wordlet a, .wordlet:not(:has(.wordlet_configure))').each(function() {
	var $this = $(this);
	var $link;
	var $wordlet;

	if ( $this.is('.wordlet') ) {
		$wordlet = $this;
		$link = $wordlet.closest('a');
	} else {
		$wordlet = $this.closest('.wordlet');
		$link = $this;
	}

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

	if ( $wordlet.data('edit') ) {
		var $elink = $('<a class="wordlet_edit" href="' + $wordlet.data('edit') + '" data-edit="' + $wordlet.data('edit') + '">Edit</a>');
		$container.append($elink);
	}

	if ( $link.length ) {
		var $wlink = $('<a class="wordlet_link" href="' + $link[0].href + '">Open Link</a>');
		$container.append($wlink);
	}

	if ( $wordlet.data('configure') ) {
		var $clink = $('<a class="wordlet_configure" href="' + $wordlet.data('configure') + '" data-configure="' + $wordlet.data('configure') + '">Configure</a>');
		$container.append($clink);
	}

	var do_hide = true;
	var hide = function() {
		if ( do_hide ) $container.css({left: '', right: '100%', top: 0});
	}

	$this
		.bind('mouseenter', function(e) {
			do_hide = false;

			if ( $container[0].style.right != '100%' ) return true;

			var x = $this.offset().left + $this.width() - $container.width();
			if ( x < $this.offset().left ) x = $this.offset().left;
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
		.bind('mouseenter', function(e) {
			do_hide = false;
		})
		.bind('mouseleave', function(e) {
			do_hide = true;
			setTimeout(hide, 0);
		})
		;
});

// Put edit/view links into Drupal admin bar
$('#toolbar .toolbar-shortcuts .menu')
	.append($menu)
	.append($('.tabs.primary li'));

});

})(window, jQuery);
