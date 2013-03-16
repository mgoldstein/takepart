<!-- campaign wrapper start -->
<div id="page-wrapper" class="campaign">
	<?=$header ?>

	<div class="page-wrap">
		<div class="main">
			<main id="page" class="content">
				<!-- campaign page start -->
				<div class="cms">
					<h1>Social Sharing Test</h1>
					<section id="all-js">
						<h2>All JS W/One HTML Hook</h2>
						<div class="tp-social"></div>
					</section>

					<section id="js-data">
						<h2>JS W/One HTML Hook &amp; Data- Attributes</h2>
						<div class="tp-social"
							data-tps-url="http://bananas.com"
							data-tps-image="http://placekitten.com/500/500"
							></div>
					</section>

					<section id="full-html">
						<h2>JS W/Full HTML</h2>
						<div class="tp-social">
							<ul>
								<li class="tp-social-facebook"></li>
								<li class="tp-social-twitter"></li>
								<li class="tp-social-googleplus"></li>
								<li class="tp-social-email"></li>
							</ul>
						</div>
					</section>

					<section id="counts">
						<h2>Counts</h2>
						<div class="tp-social"></div>
					</section>

					<section id="skip">
						<h2>Skip The Default Social Setup</h2>
						<div class="tp-social tp-social-skip"></div>
					</section>

					<section id="lazy-load">
						<h2>Lazy Load</h2>
						<div class="tp-social tp-lazy-load"></div>
					</section>
				</div>
				<!-- campaign page end -->
			</main>
		</div>
	</div>

	<?=$footer ?>
</div>
<!-- campaign wrapper end -->

<script type="text/javascript">

/*
	data- attributes:
	tps-url: URL override
	tps-image: Image override
*/

// Plugin:
(function(window, $, undefined) {

var dpre = 'tps-';
var cpre = 'tp-social-';
var $window = $(window);

var Service = function(args) {
	var name = args.name;
	var display = args.display;

	this.makeLink = function() {
		var $link = $('<a href="#"/>')
			.addClass(cpre + name)
			.addClass(cpre + 'link')
			.html(display);

		return $link;
	};

	this.Share = function() {
		return args.share(args);
	};
};

var valid_services = {
	facebook: {
		name: 'facebook',
		display: 'Facebook',
		image: null,
		caption: null,
		description: null,
		share: function(args) {
			// calling the API ...
			var obj = {
				method: 'feed',
				redirect_uri: args.url + '#facebook-share-complete',
				link: args.url,
				picture: args.image,
				name: args.title,
				caption: args.caption,
				description: args.description
			};

			/*function callback(response) {
				document.getElementById('msg').innerHTML = "Post ID: " + response['post_id'];
			}*/

			FB.ui(obj /*, callback*/);
		}
	},
	twitter: {
		name: 'twitter',
		display: 'Twitter',
		width: 550,
		height: 420,
		share: function(args) {
			var url = 'https://twitter.com/intent/tweet?original_referer=https%3A%2F%2Fdev.twitter.com%2Fdocs%2Ftweet-button&text=Tweet%20Button%20%7C%20Twitter%20Developers&tw_p=tweetbutton&url=https%3A%2F%2Fdev.twitter.com%2Fdocs%2Ftweet-button';
			left = 0;
			top = 100;
			window.open(url, undefined, ["width="+args.width,"height="+args.height,"left="+left,"top="+top].join(","));
		}
	},
	googleplus: {
		name: 'googleplus',
		display: 'Google +1'
	},
	email: {
		name: 'email',
		display: 'Email'
	}
};

var default_url = document.location;
var $rel_canonical = $('link[rel="canonical"]');
if ( $rel_canonical.length ) default_url = $rel_canonical.attr('href');

var defaults = {
	url: default_url,
	title: document.title
};

// Make an object based on data- attributes from the given jQuery object
var get_properties = function($el) {

};

$.fn.tpsocial = function(args) {
	var settings = $.extend(defaults, args);
	var services = settings.services;

	return this.each(function() {
		var $this = $(this);
		if ( $this.data(dpre + 'processed') ) return true;

		for ( var s in settings.services ) {
			var service = settings.services[s];
			var name = service.name;
			if ( !(name in valid_services) ) continue;
			service = $.extend(defaults, valid_services[name], service);
			service = new Service(service);

			var $link = $this.find('a.' + cpre + name + ', .' + cpre + name + ' a');
			if ( !$link.length ) {
				$link = service.makeLink();

				var $container = $this.find('.' + cpre + name);
				if ( $container.length ) {
					$container.append($link);
				} else {
					$this.append($link);
				}
			}

			$this
				.delegate('a.' + cpre + name, 'click', (function(service) {
						return function(e) {
							service.Share();
							e.preventDefault();
						}
					})(service)
				);

		}

		$this.data(dpre + 'processed', true);
		$this.addClass(cpre + 'processed');
	});
};

})(window, jQuery);


// Page:
(function(window, $, undefined) {

$(function() {
	var tp_social_defaults = {
		services: [
			{name: 'facebook'},
			{name: 'twitter'},
			{name: 'googleplus'},
			{name: 'email'}
		]
	};
	$('.tp-social:not(.tp-social-skip)').tpsocial(tp_social_defaults);
});

})(window, jQuery);

</script>