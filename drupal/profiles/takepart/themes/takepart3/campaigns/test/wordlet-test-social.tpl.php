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
							data-tps-twitter-text="Page title: {{title}}"
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