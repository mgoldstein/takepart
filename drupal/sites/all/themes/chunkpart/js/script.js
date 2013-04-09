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
	// Social share buttons
	var tp_social_defaults = {
		services: [
			{name: 'facebook'},
			{name: 'twitter'},
			{name: 'googleplus'},
			{name: 'reddit'},
			{name: 'email'}
		]
	};

	$('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_defaults);

	$('#article-more-shares').tpsocial({
		services: [{
			name: 'more'
		}]
	});

	// Adding tab support to participant nav
	var $site_participant_nav = $('#site-participant-nav')
		.bind('focusin', function() {
			$site_participant_nav.addClass('focusin');
		})
		.bind('focusout', function() {
			$site_participant_nav.removeClass('focusin');
		});

	// Responsive nav
	var nav = '#site-header';
	var $nav = $('#site-header');

	var click = 'click';
	var is_touchmove = false;
	if ( 'ontouchend' in document.documentElement ) click = 'touchend';

	$body
		.delegate(nav, 'touchmove', function () {
			is_touchmove = true;
		})
		.delegate(nav, click, function () {
			if ( click == 'touchend' && is_touchmove ) {
				is_touchmove = false;
				return true;
			}

			if ( $body.is('.clickedon') ) {
				$body.removeClass('clickedon');
			} else {
				$body.addClass('clickedon');
			}
		})
		.delegate(nav + ' a', click, function (e) {
			e.stopPropagation();
		})
		.delegate(nav, 'focusin', function (e) {
			$body.addClass('clickedon');
		})
		.delegate(nav, 'focusout', function (e) {
			$body.removeClass('clickedon');
		});


	/* --------------------------------
	| Page Specific ---------------- */
	if ( $body.is('.node-type-article') ) {
		$('#article-author').css('padding-top', $('#article-social').outerHeight());

		// Sticky social nav on article page
		$('#article-sidebar aside').tpsticky({
			offsetNode: '#article-content'
		});
	}


});

})(window, jQuery);