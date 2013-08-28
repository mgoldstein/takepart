<?
	$w = w('header_image')
?>
<div id="page-wrapper" class="campaign">
	<?=$header ?>

	<!-- start -->

	<div class="page-wrap">
		<div class="main">
			<header class="header">
				<span class="slug"><?=w('header_slug')?></span>
				<h1 class="page-header"><?=w('header_title')?></h1>
				<span class="credit"><?=w('header_credit')?></span>
				<span class="burst"><?=w('header_burst')?></span>
				<span class="date"><?=w('header_date')?></span>
				<img class="hero" src="/profiles/takepart/themes/takepart3/campaigns/teach/img/teachers-hero.png" alt="" />
				<p class="fine">
					<?=w('header_fine')?>
					<div class="right"><?=w('header_photo_credit')?></div>
				</p>
				<div class="menu">
					<ul <?=wa('menu') ?>>
						<? foreach( wl('menu') as $w ): ?>
							<li class="<?=ws($w->href)?>"><a href="<?=$w->href?>"><?=$w->single(false)?></a></li>
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

	<?=$footer ?>
</div>
