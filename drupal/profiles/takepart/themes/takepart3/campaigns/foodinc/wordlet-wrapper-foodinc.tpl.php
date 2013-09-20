<?
	$menu_block = module_invoke('menu', 'block_view', 'food_inc_new_multipage_campaign');

	$element = array(
	  '#tag' => 'link',
	  '#attributes' => array(
	    'href' => '//cloud.typography.com/625388/701462/css/fonts.css',
	    'rel' => 'stylesheet',
	    'type' => 'text/css',
	  ),
	);
	drupal_add_html_head($element, 'archer');
	drupal_add_js('//connect.facebook.net/en_US/all.js');
?>

<!-- Insert into HTML <head> -->
<script type='text/javascript'>
var googletag = googletag || {};
googletag.cmd = googletag.cmd || [];
(function()
{ var gads = document.createElement('script'); gads.async = true; gads.type = 'text/javascript'; var useSSL = 'https:' == document.location.protocol; gads.src = (useSSL ? 'https:' : 'http:') + '//www.googletagservices.com/tag/js/gpt.js'; var node = document.getElementsByTagName('script')[0]; node.parentNode.insertBefore(gads, node); }
)();
</script>
<script type='text/javascript'>
googletag.cmd.push(function()
{ googletag.defineSlot('/4355895/TP3_ROS_Background_1x1', [1, 1], 'div-gpt-ad-1379616672161-0').addService(googletag.pubads()); googletag.defineSlot('/4355895/TP3_ROS_RR_ATF_300x250', [300, 250], 'div-gpt-ad-1379616725962-0').addService(googletag.pubads()); googletag.pubads().enableSingleRequest(); googletag.pubads().setTargeting("Type", "wordlet"); googletag.pubads().setTargeting("Topic", "Food"); googletag.pubads().setTargeting("FreeTag", ["Food Inc. Awards", "Food Inc."]); googletag.pubads().setTargeting("PageTitle", "Food Inc. Awards"); googletag.enableServices(); }
);
</script>
<!-- /Insert into HTML <head> -->


<?php
	$w = w('header_image');
	global $base_url;
?>
<div id="page-wrapper" class="campaign foodinc">
	<?php print foodinc_awards_is_embedded() ? '' : render($header); ?>


	<div class="page-wrap">
		<?=w('background_skin')?>

		<div class="main">
			<header class="header">
				<span class="slug"><?=w('header_slug')?></span>
				<h1 class="page-header"><?=w('header_title')?></h1>
				<img src="<?php print $base_url; ?>/profiles/takepart/themes/takepart3/campaigns/foodinc/images/foodinc-banner.jpeg" alt="Food Inc">
				<div id="main-navigation" class="menu-wrapper">
						<?php print render($menu_block['content']); ?>
				</div>
					<div class="logo"><img src="<?php print w('foodin_logo')->img_src; ?>" alt="<?php print w('foodin_logo')->single; ?>"></div>
					<?php if(current_path() == 'wordlet/foodinc_awards'): ?>
	  				<aside id="foodinc-social" class="social">
	  					<h3 class="headline"><?php print t('SHARE'); ?></h3>
	  					<div class="tp-social"></div>
	  				</aside>
  				<?php endif; ?>

			</header>
			<main id="page">
				<?=$content?>
			</main>
		</div>
	</div><!-- /.page-wrap -->

	<!-- end -->

	<?php print foodinc_awards_is_embedded() ? '' : render($footer); ?>
</div>
<!-- /place in the <body> to display the 300x250 ad -->
<!-- place in the <body> to display the background skin ad -->
<!-- TP3_ROS_Background_1x1 -->
<div id='div-gpt-ad-1379616672161-0' style='width:1px; height:1px;'>
<script type='text/javascript'>
googletag.cmd.push(function()
{ googletag.display('div-gpt-ad-1379616672161-0'); }
);
</script>
</div>
