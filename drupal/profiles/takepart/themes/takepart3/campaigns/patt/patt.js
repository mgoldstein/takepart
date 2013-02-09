(function(window, $, undefined) {
// Setup


// Document load
$(function() {

var $columns = $('.column-1 .content, .column-3 .content');

if ( $columns.length ) {
	$columns.tpsticky({
		offsetNode: '.page-wrap .main'
	});

	var height = $('.page-wrap .main').outerHeight();
	$columns.each(function() {
		var tempheight;
		height = ( (tempheight = $(this).parent().outerHeight()) && tempheight > height ) ? tempheight : height;
	});

	$columns.parent().add('.page-wrap .main').height(height);
}

// Snap gallery

var $modal = $('#grid-modal');
var $overlay = $('#grid-overlay');
var speed = 'fast';
var $current_tile;

var show_modal = function() {
	$modal.find('.modal-left').html($current_tile.find('.modal-left').html());
	$modal.find('.modal-right').html($current_tile.find('.modal-right').html());
};

$('body')
	.delegate('.tile', 'click', function() {
		$current_tile = $(this);
		show_modal();

		$overlay.fadeIn(speed);
		$modal.fadeIn(speed);
	})
	.delegate('.close-btn', 'click', function() {
		$modal.fadeOut(speed);
		$overlay.fadeOut(speed);
	})
	.delegate('#nav-right', 'click', function() {
		$current_tile = $current_tile.next('.tile.person, .tile.fact');
		if ( !$current_tile.length ) {
			$current_tile = $('.tile.person, .tile.fact').first();
		}

		show_modal();
	})
	.delegate('#nav-left', 'click', function() {
		$current_tile = $current_tile.prev('.tile.person, .tile.fact');
		if ( !$current_tile.length ) {
			$current_tile = $('.tile.person, .tile.fact').last();
		}

		show_modal();
	})
	;

});
})(window, jQuery);