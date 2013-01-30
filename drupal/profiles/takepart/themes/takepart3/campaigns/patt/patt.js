(function(window, $, undefined) {
// Setup


// Document load
$(function() {

$('.column-1 .content, .column-3 .content').tpsticky({
	offsetNode: '.page-wrap .main'
});

$('.page-wrap .main').height($('.page-wrap .main').height());

});
})(window, jQuery);