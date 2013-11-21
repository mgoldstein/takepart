<?
	$w = w('header_image')
?>
<div id="page-wrapper" class="campaign">

	 <div class="slimnav responsive">
    <?php $slimnav = module_invoke('tp4_support', 'block_view', 'tp4_slim_nav'); ?>
    <?php print $slimnav['content']; ?>
  </div>

	<!-- start -->

	<div class="page-wrap">
		<?=w('background_skin')?>

		<div class="main">
			<header class="header">
				<span class="slug"><?=w('header_slug')?></span>
				<h1 class="page-header"><?=w('header_title')?></h1>
				<span class="credit"><?=w('header_credit')?></span>
				<span class="burst"><?=w('header_burst')?></span>
				<span class="date"><?=w('header_date')?></span>
				<div class="fine">
					<img class="logos" src="/profiles/takepart/themes/takepart3/campaigns/teach/img/hero-logos.png" alt="CBS | Participant media" />
					<?=w('header_fine')?>
					<div class="right"><?=w('header_photo_credit')?></div>
				</div>
				<img class="hero" src="/profiles/takepart/themes/takepart3/campaigns/teach/img/teachers-hero.png" alt="Teachers" />
				<div class="menu-wrapper">
					<ul class='menu' <?=wa('menu') ?>>
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

</div>
<div class="footer-wrapper responsive"> 
  <footer>
    <?php $footer = module_invoke('tp4_support', 'block_view', 'tp4_footer'); ?>
    <?php print $footer['content']; ?>
  </footer>
</div>
