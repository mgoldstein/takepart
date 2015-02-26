<?php
	$w = w('header_image');
?>

<div class="snap-drawers scrollable">
    <div class="snap-drawer snap-drawer-left">
      <?php
        $mobile_menu = drupal_render(module_invoke('menu', 'block_view', 'menu-megamenu'));
        print $mobile_menu;
      ?>

  </div>
</div>

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
				<h1 class="page-header"><a href="/teach"><?=w('header_title')?></a></h1>
				<span class="credit"><?=w('header_credit')?></span>
				<span class="burst"><span><?=w('header_burst')?></span><!--<img class="logos" src="/profiles/takepart/themes/takepart3/campaigns/teach/img/hero-logos.png" alt="CBS | Participant media" />--></span>
				<span class="date"><?=w('header_date')?></span>
				<div class="fine">
					<?=w('header_fine')?>
					<div class="right"><?=w('header_photo_credit')?></div>
				</div>
				<img class="hero" src="/profiles/takepart/themes/takepart3/campaigns/teach/img/hero-teachers.png" alt="Teachers" />
       <div class="campaign-social-share scribble-share" <?php print wa('header_share_data'); ?>
          <?php $w = w('header_share_data'); ?>
          data-shareurl="<?php print $w->href_raw; ?>"
          data-sharetitle="<?php print $w->single_no_markup; ?>"
          data-sharedescription="<?php print preg_replace('/<[^>]+>/i', '', $w->multi_short_no_markup); ?>"
        ><span>Share</span></div>
				<div class="menu-wrapper">
					<ul class='menu' <?=wa('menu') ?>>
						<?php foreach( wl('menu') as $w ): ?>
							<li class="item <?=ws($w->href)?>"><a href="<?=$w->href?>"><?=$w->single(false)?></a></li>
						<?php endforeach ?>
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
