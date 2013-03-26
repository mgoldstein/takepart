(function (window, $, undefined) {

// Remove Drupal default stylings
// TODO: fix this
//jQuery('style').get(0).innerHTML = '';

var $body = $('body');

// Delegates
$body
	// Skip link tabbing fix for Webkit
	.delegate('.skip-link a', 'click', function() {
		$($(this).attr('href')).attr('tabIndex', '-1').focus();
	})

// Document Ready
$(function() {
	var $site_participant_nav = $('#site-participant-nav')
		.bind('focusin', function() {
			$site_participant_nav.addClass('focusin');
		})
		.bind('focusout', function() {
			$site_participant_nav.removeClass('focusin');
		});


	/* --------------------------------
	| Page Specific ---------------- */
	if ( $body.is('.node-type-article') ) {
		// Sticky social nav on article page
		$('#article-social').tpsticky({
			offsetNode: '#article-content'
		});
	}


});

})(window, jQuery);