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
var $window = $(window);

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
	var show_fb_comments = function(el, url) {
		var $this = $(el);
		var url = url || '';
		var $template = $this.parent().find('.fb_comments_template');
		var html = $template.text();
		if ( url ) {
			html = html.replace(/href="[^"]+"/g, 'href="' + url + '"');
		}
		$this.html(html);
		FB.XFBML.parse($this[0]);
    }

	$('.fb_comments')
		.lazyload({threshold: 200, load: function() {
			show_fb_comments(this);
		}});

	// Track "On Our Radar" links - if we can ever get exit link tracking to work correctly
	$body
		.delegate('.on_our_radar_section a', 'click', function() {
			return takepart.analytics.track('on-our-radar-click', {element: this});
		});

	/* Page Specific ---------------------------------------------------------------------------------- */

	/* Article --------------------------------------------------- */
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

		var main_image = $('#article-image img').attr('src');
		var more_services = {
			pinterest: {
				name: 'pinterest',
				media: main_image
			},
			tumblr_link: {name: 'tumblr_link'},
			gmail: {name: 'gmail'},
			hotmail: {name: 'hotmail'},
			yahoomail: {name: 'yahoomail'},
			aolmail: {name: 'aolmail'},

			//{name: 'myspace'},
			//{name: 'delicious'},
			linkedin: {name: 'linkedin'},
			//{name: 'myaol'},
			//{name: 'live'},
			digg: {name: 'digg'},
			stumbleupon: {name: 'stumbleupon'},
			//{name: 'hyves'}
		};

		if ( !main_image ) delete more_services.pinterest;

		$('#article-more-shares p').tpsocial({
			services: more_services
		});

		// prevent 2 email calls from firing
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
	/* Gallery --------------------------------------------------- */
	} else if ( $body.is('.node-type-openpublish-photo-gallery') ) {
		// Tracking for "Next gallery" clicks
		$body
			.delegate('#next-gallery a, .forward-to-gallery a', 'click', function() {
				takepart.analytics.track('gallery-next-gallery-click', {
					headline: next_gallery_headline,
					topic: next_gallery_topic,
					a: this
				});
			});

		var $gallery_cover = $('#gallery-cover');
		var $gallery_main = $('#gallery-main');
		var $slides = $('#gallery-content > ul');
		var base_url = document.location.href.split(/\/|#/).slice(0,5).join('/');
		var $fb_comment = $('.fb_comments');
		var fb_comment_el = $fb_comment[0];

		var $first_slide = $slides.find('> li:first-child');
		var has_cover = $gallery_cover.length;
		var first_image;
		var first_description;
		var skip_next_pageview = false;
		var $next_gallery = $('#next-gallery');
		var next_gallery_headline = $next_gallery.find('.caption .headline').text();
		var next_gallery_topic = $next_gallery.find('.caption .topic').text();

		if ( has_cover ) {
			first_image = $gallery_cover.find('img').attr('src');
			first_description = $gallery_cover.find('.headline').text();
		} else {
			first_image = $first_slide.find('img').attr('src');
			first_description = $first_slide.find('.photo-caption').text().replace(/^\s+|\s+$/g, '').replace(/[\ |\t]+/g, ' ').replace(/[\n]+/g, "\n");
		}

		// Update ads/fb comments etc per slide load
		var update_to = null;
		var update_page = function(token) {
			clearTimeout(update_to);

			if ( !skip_next_pageview ) {
				setTimeout((function(token, skip_next_pageview) {
					return function() {
						takepart.analytics.track('gallery-track-slide', {
							token: token,
							skip_pageview: skip_next_pageview,
							next_gallery_headline: next_gallery_headline,
							next_gallery_topic: next_gallery_topic
						});
					}
				})(token, skip_next_pageview), 500);
			} else {
				skip_next_pageview = false;
			}

			update_to = setTimeout(function() {
				var token = get_curtoken();

				if ( token == 'next-gallery' ) {
					$fb_comment.hide();
				} else {
					$fb_comment.show();
				}

				show_fb_comments(fb_comment_el, base_url + '/' + token);

				if ( googletag != undefined ) {
					googletag.pubads().refresh();
				}
			}, 500);
		};

		// Social share buttons
		var tp_social_config = {
			services: {
				facebook: {
					name: 'facebook',
					url: '{current}'
				},
				twitter: {
					name: 'twitter',
					text: '{{title}}',
					via: 'TakePart',
					url: '{current}'
				},
				googleplus: {
					name: 'googleplus',
					url: '{current}'
				},
				pinterest: {
					name: 'pinterest',
					url: '{current}',
					media: first_image,
					description: first_description
				},
				tumblr: {
					name: 'tumblr',
					url: '{current}',
					source: first_image,
					caption: first_description
				},
				email: {
					name: 'email',
					url: '{current}'
				}
			}
		};

		// prevent 2 email calls from firing
		takepart.analytics.skip_addthis = true;

		// Get current "token" from last folder of URL
		var get_curtoken = function() {
			var token = document.location.href.split(/\/|#/).slice(5,6) + '';
			if(token.indexOf('?') > -1) {
				token =  token.substring(0, token.indexOf('?'));
                        }
			// Allow for back buttoning to #first-slide cover page
			return token;
		};

		// Update slideshow based on url
		var goto_slide = function() {
			var token = get_curtoken();
			var $slide = $slides.find('[data-token="' + token + '"]');
			$slides.tpslide_to($slide);
		};

		// Return history functionality in browser
		var has_history = function() {
			return (typeof history != 'undefined');
		};

		// Update html5 history if token is new
		var hpush = function(token, title, replace) {
			var curtoken = get_curtoken();
			var replace = replace || false;
			if ( curtoken == token ) return;
			update_page(token);

			if ( !has_history() ) return;
			if ( replace ) {
				history.replaceState(null, title, base_url + '/' + token);
			} else {
				history.pushState(null, title, base_url + '/' + token);
			}
		};

		// Callback for slideshow sliding a slide
		var $current_slide = null;
		var slide_callback = function($current) {
			var old_token = ( $current_slide ) ? $current_slide.data('token') : null;
			$current_slide = $current;

			if ( !$current_slide.prev().length ) {
				$gallery_main.addClass('on-first');
			} else {
				$gallery_main.removeClass('on-first');
			}

			if ( !$current_slide.next().length ) {
				$gallery_main.addClass('on-last');
			} else {
				$gallery_main.removeClass('on-last');
			}

			var current_image = $current_slide.find('img').attr('src');
			tp_social_config.services.pinterest.media = current_image;
			tp_social_config.services.tumblr.source = current_image;

			var current_description = $current_slide.find('.photo-caption').text().replace(/^\s+|\s+$/g, '').replace(/[\ |\t]+/g, ' ').replace(/[\n]+/g, "\n");
			tp_social_config.services.pinterest.description = current_description;
			tp_social_config.services.tumblr.caption = current_description;

			$('#gallery-photos .tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);

			var token = $current.data('token');
			if ( token == 'next-gallery' ) {
				$('#gallery-header-main .social').css({visibility: 'hidden', display: 'none'});
			} else {
				$('#gallery-header-main .social').css({visibility: 'visible', display: 'block'});
			}

			$slides.height($current_slide.height());

			if ( !gallery_showing ) return;
			hpush(token, $current.find('.headline').text());
		}

		var gallery_showing = false;
		var show_gallery = function(replace) {
			if ( gallery_showing ) return;
			gallery_showing = true;
			$gallery_cover.hide();
			$gallery_main.removeClass('hide_gallery').addClass('show_gallery');
			hpush($current_slide.data('token'), $current_slide.find('.headline').text(), replace);
		};

		var hide_gallery = function() {
			$gallery_cover.show();
			$gallery_main.removeClass('show_gallery').addClass('hide_gallery');

			var current_image = $gallery_cover.find('img').attr('src');
			tp_social_config.services.pinterest.media = current_image;
			tp_social_config.services.tumblr.source = current_image;

			var current_description = $gallery_cover.find('.headline').text();
			tp_social_config.services.pinterest.description = current_description;
			tp_social_config.services.tumblr.caption = current_description;

			$('#gallery-cover .tp-social:not(.tp-social-skip)').tpsocial(tp_social_config);

			gallery_showing = false;
		};

		// Make slideshow
		$slides.tpslide({
			onslide: slide_callback,
			threshold: 75,
			swipeTarget: 'img',
			cycle: false
		});

		// Make img clicks forward gallery
		$slides
			.delegate('.gallery-slide img, .image-content-wrapper', 'mouseover', function() {
				$gallery_main.addClass('image-hover');
			})
			.delegate('.gallery-slide img, .image-content-wrapper', 'mouseout', function() {
				$gallery_main.removeClass('image-hover');
			})
			.delegate('.gallery-slide img', 'click', function() {
				$slides.tpslide_next(false);
			})
			;

		// Fix heights for responsive
		$window.bind('resize', function () {
			$slides.height($current_slide.height());
		});

		// Event for fake back button to go to cover page
		$('.back-to-cover a').bind('click', function(e) {
			e.preventDefault();
			if ( !gallery_showing ) return;
			hide_gallery();
			hpush('', $('#gallery-cover-main').find('.headline').text());
		});

		// Initialize page based on URL
		if ( get_curtoken() && get_curtoken() != 'first-slide' ) {
			goto_slide();
			show_gallery();
		} else if ( get_curtoken() == 'first-slide' ) {
			skip_next_pageview = true;
			show_gallery(true);
		} else if ( $gallery_cover.length ) {
			hide_gallery();
		} else {
			skip_next_pageview = true;
			show_gallery(true);
		}

		var first_pop = true;
		// Listen for html5 history updates/back button
		window.addEventListener('popstate', function(e) {
			if ( first_pop ) {
				first_pop = false;
				return;
			}

			var token = get_curtoken();

			if ( token ) {
				goto_slide();
				show_gallery();
			} else if ( $gallery_cover.length ) {
				hide_gallery();
			}

			update_page(token);
		});

		// Cover page link event
		$('#gallery-cover .enter-link, #gallery-body .enter-link').bind('click', function(e) {
			e.preventDefault();
			show_gallery();
		});
	}
});

})(window, jQuery);
