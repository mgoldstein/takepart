<div id="page-wrapper" class="campaign">
		<div class="slimnav non-responsive">
    <?php $slimnav = module_invoke('tp4_support', 'block_view', 'tp4_slim_nav'); ?>
    <?php print $slimnav['content']; ?>
  </div>

	<!-- start -->

	<div class="page-wrap">
		<div class="main">
			<div class="header">
				<?php if ( $w = w('header_image') ): ?>
					<h1 <?=wa('header_image')?>>
						<span><?=$w->single(false)?></span>
						<a href="<?=$w->href?>"><img src="<?=$w->img_src?>" alt="logo" /></a>
					</h1>
				<?php endif ?>
				<div class="menu">
					<ul <?=wa('menu')?>>
						<?php foreach( wl('menu') as $w ): ?>
							<li><a href="<?=$w->href?>" class="<?=ws($w->href)?>"><?=$w->single(false)?></a></li>
						<?php endforeach ?>
					</ul>
				</div>
			</div>
			<main id="page">
				<?=$content?>
			</main>
		</div>
	</div><!-- /.page-wrap -->

	<!-- end -->

</div>
<div class="footer-wrapper non-responsive"> 
  <footer>
    <?php $footer = module_invoke('tp4_support', 'block_view', 'tp4_footer'); ?>
    <?php print $footer['content']; ?>
  </footer>
</div>