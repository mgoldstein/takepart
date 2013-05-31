(function (window, $, undefined) {

// Temp: event tracking example
$(window).bind('tp-social-share', function(e, args) {
	takepart.analytics.track('tp-social-share', args);
});

$(window).bind('tp-social-click', function(e, args) {
	takepart.analytics.track('tp-social-click', args);
});

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
	;

// Drupal tab stuff
$('.tabs-toolbar li').appendTo('.toolbar-shortcuts ul');

// Document Ready
$(function() {
    // Make tpinfographic stuff
    $('.tpinfographic').each(function() {
        var $this = $(this);
        var html = $this.html().replace(/^\s+|\s+$/g, '') + '<br />Via: <a href="http://www.takepart.com">TakePart.com</a>';
        var $container = $('<div/>').addClass('tpinfographic_container');
        var $embed = $('<div/>').addClass('tpinfographic_embed_container');
        var $embed_link_p = $('<p/>').addClass('tpinfographic_embed_link');
        var $embed_link_a = $('<a href="#"/>').html('Embed This Infographic on Your Site');
        var $embed_textarea_p = $('<p/>').addClass('tpinfographic_embed_textarea').hide();
        var $embed_textarea = $('<textarea/>').addClass('tpinfographic_embed_textarea').attr({cols: 56, rows: 7}).val(html);

        $embed_link_p.append($embed_link_a);

        $embed_textarea_p.append($embed_textarea);

        $embed
            .append($embed_link_p)
            .append($embed_textarea_p)

        $container
            .insertAfter($this)
            .append($this)
            .append($embed)
            ;
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

    // TODO reduce code duplication
    // Lazy load facebook comments
    $('.fb_comments')
        .lazyload({threshold: 200, load: function() {
            var $div = $('<div/>');
            var $template = $(this).find('.fb_comments_template');
            var html = $template.text();
            $div.html(html);
            $div.insertAfter($template);
            FB.XFBML.parse($div[0]);
        }});

	/* --------------------------------
	| Page Specific ---------------- */
	if ( $body.is('.node-type-article') ) {
		// Social share buttons
		var tp_social_config = {
			services: [
				{name: 'facebook'},
				{
					name: 'twitter',
					text: '{{title}}',
					via: 'TakePart'
				},
				{name: 'googleplus'},
				{name: 'reddit'},
				{name: 'email'}
			]
		};

		$('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);

		$('#article-more-shares p').tpsocial({
			services: [
				/*{
					name: 'more',
					services_compact: 'myspace,linkedin,delicious,myaol,live,digg,stumbleupon,hyves',
					services_expanded: 'myspace,linkedin,delicious,myaol,live,digg,stumbleupon,hyves',
					services_exclude: 'facebook,twitter,google_plusone,reddit,email'
				},*/
				{name: 'myspace'},
				{name: 'delicious'},
				{name: 'linkedin'},
				{name: 'myaol'},
				{name: 'live'},
				{name: 'digg'},
				{name: 'stumbleupon'},
				{name: 'hyves'}
			]
		});

		takepart.analytics.skip_addthis = true;
		$('#article-author').css('padding-top', $('#article-social').outerHeight());

		// Sticky social nav on article page
		$('#article-sidebar aside').tpsticky({
			offsetNode: '#article-content'
		});

		// more share tab support & click event

		var social_more_close = function() {
			$article_social_more.removeClass('focusin');
			$body.unbind('click', social_more_close);
		};

		var $article_social_more = $('#article-social-more')
			.bind('focusin', function() {
				$article_social_more.addClass('focusin');
			})
			.bind('focusout', function() {
				$article_social_more.removeClass('focusin');
			})
			.bind('click', function(e) {
				if ( !$article_social_more.is('.focusin') ) {
					$article_social_more.addClass('focusin');
					setTimeout(function() {
						$body.bind('click', social_more_close);
					}, 100);
				}
				e.preventDefault();
			})
			;
	} else if ( $body.is('.node-type-openpublish-photo-gallery') ) {
		var $slides = $('#gallery-content ul');
		var base_url = '/' + document.location.href.split(/\/|#/).slice(3,5).join('/');
		// Social share buttons
		var tp_social_config = {
			services: [
				{name: 'facebook'},
				{
					name: 'twitter',
					text: '{{title}}',
					via: 'TakePart'
				},
				{name: 'googleplus'},
				{name: 'pinterest'},
				{name: 'tumblr'}
			]
		};

		var get_curtoken = function() {
			return document.location.href.split(/\/|#/).slice(5,6) + '';;
		};

		var goto_slide = function() {
			var token = get_curtoken();
			var $slide = $slides.find('[data-token="' + token + '"]');
			$slides.tpslide_to($slide);
		};

		$slides.find('.image img').each(function() {
			var $this = $(this);
			if ( this.clientHeight ) {
				$this.closest('li').height($this.height());
			} else {
				$this.bind('load', function() {
					$this.closest('li').height($this.height());
				});
			}
		});

		$('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);

		var has_history = function() {
			return (typeof history != 'undefined');
		};

		var hpush = function(token, title) {
			var curtoken = get_curtoken();
			if ( !has_history() || curtoken == token ) return;
			history.pushState(null, title, base_url + '/' + token);
		};

		var slide_callback = function($current) {
			if ( !gallery_showing ) return;
			hpush($current.data('token'), $current.find('.headline').text());
		}

		var gallery_showing = false;
		var show_gallery = function() {
			$('#gallery-cover').hide();
			$('#gallery-photos').show();

			window.addEventListener("popstate", function(e) {
				goto_slide();
			});
			gallery_showing = true;
		};

		$slides.tpslide({onslide: slide_callback});

		if ( get_curtoken() ) {
			goto_slide();
			show_gallery();
		}

		//$('#gallery-photos').hide();

		$('#gallery-cover .enter-link').bind('click', function(e) {
			e.preventDefault();
			show_gallery();
		});
	}
});

})(window, jQuery);