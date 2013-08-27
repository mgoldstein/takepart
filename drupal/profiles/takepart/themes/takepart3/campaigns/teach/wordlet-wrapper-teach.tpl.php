<?
	$w = w('header_image')
?>
<div id="page-wrapper" class="campaign">
	<?=$header ?>

	<!-- start -->

	<div class="page-wrap">
		<div class="main">
			<div class="header">
				<div class="slug"><?=w('header_slug')?></div>
				<h1><?=w('header_title')?></h1>
				<div class="credit"><?=w('header_credit')?></div>
				<div class="burst"><?=w('header_burst')?></div>
				<div class="date"><?=w('header_date')?></div>
				<img class="hero" src="/profiles/takepart/themes/takepart3/campaigns/teach/img/teachers-hero.png" alt="" />
				<div class="fine">
					<?=w('header_fine')?>
					<div class="right"><?=w('header_photo_credit')?></div>
				</div>
				<div class="menu">
					<ul <?=wa('menu') ?>>
						<? foreach( wl('menu') as $w ): ?>
							<li class="<?=ws($w->href)?>"><a href="<?=$w->href?>"><?=$w->single(false)?></a></li>
						<? endforeach ?>
					</ul>
				</div>
			</div>
			<main id="page">
				<?=$content?>
			</main>
		</div>
	</div><!-- /.page-wrap -->

	<!-- end -->

	<?=$footer ?>
</div>
