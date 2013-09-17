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
				<div class="menu-wrapper">
					<ul id="main-navigation" class='menu' <?=wa('menu') ?>>
						<? foreach( wl('menu') as $w ): ?>
							<li class="item <?=ws($w->href)?>"><a href="<?=$w->href?>"><?=$w->single(false)?></a></li>
						<? endforeach ?>
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
