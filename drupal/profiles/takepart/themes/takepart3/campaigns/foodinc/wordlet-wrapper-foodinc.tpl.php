<?php
	$element = array(
	  '#tag' => 'link',
	  '#attributes' => array(
	    'href' => '//cloud.typography.com/625388/701462/css/fonts.css',
	    'rel' => 'stylesheet',
	    'type' => 'text/css',
	  ),
	);
	drupal_add_html_head($element, 'archer');
?>


<?php
	$w = w('header_image');
	global $base_url;
?>
<div id="page-wrapper" class="campaign foodinc">
	<?php print (isset($_REQUEST['signed_request']) ? '' : render($header)); ?>


	<div class="page-wrap">
		<?=w('background_skin')?>

		<div class="main">
			<header class="header">
				<span class="slug"><?=w('header_slug')?></span>
				<h1 class="page-header"><?=w('header_title')?></h1>
				<img src="<?php print $base_url; ?>/profiles/takepart/themes/takepart3/campaigns/foodinc/images/foodinc-banner.jpeg" alt="Food Inc">
				<div id="main-navigation" class="menu-wrapper">
						<?php $block = module_invoke('menu', 'block_view', 'food_inc_new_multipage_campaign'); ?>
						<?php print render($block['content']); ?>
				</div>
					<div class="logo"><img src="<?php print w('foodin_logo')->img_src; ?>" alt="<?php print w('foodin_logo')->single; ?>"></div>

				<aside id="foodinc-social" class="social">
					<h3 class="headline"><?php print t('SHARE'); ?></h3>
					<div class="tp-social"></div>
				</aside>


			</header>
			<main id="page">
				<?=$content?>
			</main>
		</div>
	</div><!-- /.page-wrap -->

	<!-- end -->

  <?php print (isset($_REQUEST['signed_request']) ? '' : render($footer)); ?>
</div>
