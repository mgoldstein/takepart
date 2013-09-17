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
	drupal_add_html_head($element, 'archer screensmart semibold italic');
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
				<div class="menu-wrapper">
					<ul id="main-navigation" class='menu' <?=wa('menu') ?>>
						<?php $block = module_invoke('menu', 'block_view', 'food_inc_new_multipage_campaign'); ?>
						<?php print render($block['content']); ?>
					</ul>
				</div>
			</header>
			<main id="page">
				<?=$content?>
			</main>
		</div>
	</div><!-- /.page-wrap -->

	<!-- end -->

  <?php print (isset($_REQUEST['signed_request']) ? '' : render($footer)); ?>
</div>
