(function(window, $, undefined) {
// Setup


// Document load
$(function() {

var $columns = $('.column-1 .content, .column-3 .content');

if ( $columns.length ) {
	$columns.tpsticky({
		offsetNode: '.page-wrap .main'
	});

	$('.page-wrap .main').height($('.page-wrap .main').outerHeight());
}

});
})(window, jQuery);