(function(window, $, undefined) {
// Setup

// Document load
$(function() {

var $columns = $('.column-1 .content, .column-3 .content');

// Make columns stay in viewport
if ( $columns.length ) {
	$columns.tpsticky({
		offsetNode: '.page-wrap .main'
	});
}

// Make columns equal height
var height = 0;
$('.table.int .column').each(function() {
	var tempheight;
	height = ( (tempheight = $(this).outerHeight()) && tempheight > height ) ? tempheight : height;
})
.height(height);


// Snap gallery

var $modal = $('#grid-modal');
var $overlay = $('#grid-overlay');
var speed = 400;
var $current_tile;
//var modal_options = {id: 'snap_modal';

var getQueryParam = function(name) {
	var result = {}, queryString = location.search.substring(1),
		re = /([^&=]+)=([^&]*)/g, m;

	while (m = re.exec(queryString)) {
		result[decodeURIComponent(m[1])] = decodeURIComponent(m[2]);
	}

	return result[name];
};

var clean_myth = function(text) {
	text = text.replace(/^[\n\r\s]*/,'').replace(/[\n\r\s]*$/,'').replace(/[\n\r]+/g,'').replace(/\s{2,}/,': ');
	return text;
}

var show_modal = function(animate) {
	$modal.find('.modal-left').html($current_tile.find('.modal-left').html());
	$modal.find('.modal-right').html($current_tile.find('.modal-right').html());

	var dospeed = animate ? speed : 0;

	var url = [location.protocol, '//', location.host, location.pathname].join('') + '?slide=' + $current_tile.data('token');
	$modal.find('.addthis_toolbox a')
		.attr('addthis:url', url)
		.attr('data-tpsocial-href', url);

	$.tpmodal.show({id: 'snap_modal_', html: $modal.html(), prepend: 'snap_modal_', speed: dospeed});

	var name = clean_myth($current_tile.find('.modal-left .fact').text()) || $current_tile.find('.modal-header h1').html() || 'Share Your Story';

	takepart.analytics.track('patt_show_modal', name);

	addthis.toolbox('.addthis_toolbox_modal');
};

var next = function() {
	$current_tile = $current_tile.next('.tile.person, .tile.fact, .tile.link');
	if ( $current_tile.is('.link') ) {
		next();
		return;
	}
	if ( !$current_tile.length ) {
		$current_tile = $('.tile.person, .tile.fact').first();
	}

	show_modal(false);
};

var prev = function() {
	$current_tile = $current_tile.prev('.tile.person, .tile.fact, .tile.link');
	if ( $current_tile.is('.link') ) {
		prev();
		return;
	}
	if ( !$current_tile.length ) {
		$current_tile = $('.tile.person, .tile.fact').last();
	}

	show_modal(false);
};

$current_tile = $('.tile[data-token="' + getQueryParam('slide') + '"]');
if ( $current_tile.length ) show_modal();

$('body')
	.delegate('.tile[data-token] a', 'click', function(e) {
		e.preventDefault();
	})
	.delegate('.tile[data-token]', 'click', function() {
		$current_tile = $(this);

		show_modal(true);

		//$overlay.fadeIn(speed);
		//$modal.fadeIn(speed);
	})
	.delegate('.close-btn', 'click', function() {
		$.tpmodal.hide({id: 'snap_modal_'});
		//$modal.fadeOut(speed);
		//$overlay.fadeOut(speed);
	})
	.delegate('#nav-right', 'click', next)
	.delegate('#nav-left', 'click', prev)
	.delegate('#snap_modal_modal .addthis_button_email', 'click', function() {
		var name = clean_myth($current_tile.find('.modal-left .fact').text()) || $current_tile.find('.modal-header h1').html() || 'Share Your Story';

		takepart.analytics.track('patt_email_modal', name);
	})
	.delegate('#snap_modal_modal .addthis_button_twitter', 'click', function() {
		var name = clean_myth($current_tile.find('.modal-left .fact').text()) || $current_tile.find('.modal-header h1').html() || 'Share Your Story';

		takepart.analytics.track('patt_twitter_modal', name);
	})
	.delegate('#snap_modal_modal .addthis_button_facebook, #snap_modal_modal .tpsocial-facebook', 'click', function() {
		var name = clean_myth($current_tile.find('.modal-left .fact').text()) || $current_tile.find('.modal-header h1').html() || 'Share Your Story';

		takepart.analytics.track('patt_facebook_modal', name);
	})
	.delegate('.social-buttons .addthis_button_email', 'click', function() {
		takepart.analytics.track('patt_email_gallery');
	})
	.delegate('.social-buttons .addthis_button_twitter', 'click', function() {
		takepart.analytics.track('patt_twitter_gallery');
	})
	.delegate('.social-buttons .addthis_button_facebook, .social-buttons .tpsocial-facebook', 'click', function() {
		takepart.analytics.track('patt_facebook_gallery');
	})
	;

var ytreg = /v=([a-zA-Z0-9]+)/;
// Page specific:
if ( $('body').is('.page-wordlet-patt-home') ) {
	$('.table .tag img')
		.each(function() {
			var $img = $(this);
			var $a = $img.parent();
			var img = new Image();
			img.src = $img.data('onsrc');
			$a.data({
				off: $img.attr('src'),
				on: $img.data('onsrc')
			});
		});

	$('body')
		.delegate('.table .tag', 'mouseover focus', function() {
			var $a = $(this);
			var $img = $a.find('img');
			$img.attr({src: $a.data('on')});
		})
		.delegate('.table .tag', 'mouseout blur', function() {
			var $a = $(this);
			var $img = $a.find('img');
			$img.attr({src: $a.data('off')});
		})
		;
} else if ( $('body').is('.page-wordlet-patt-film') ) {
	$('body')
		.delegate('a[href^="http://www.youtube.com"]', 'click', function(e) {
			var m = ytreg.exec(this.href);
			var yt = m[1];
			//var html = '<iframe width="560" height="315" src="http://www.youtube.com/embed/' + yt + '?autoplay=1" frameborder="0" allowfullscreen></iframe>';
			var html = '<iframe width="560" height="315" src="/video/players/?id=Mcam9iPd-Y3bNKxgM" frameborder="0" allowfullscreen=""></iframe>';
			$.tpmodal.show({html: html});
			e.preventDefault();
		});
} else if ( $('body').is('.page-wordlet-patt-nav') ) {
	$('a').attr({target: '_top'});
}

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