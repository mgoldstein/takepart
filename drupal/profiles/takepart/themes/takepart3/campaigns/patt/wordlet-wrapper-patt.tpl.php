<div id="page-wrapper" class="campaign">
		  <div class="slimnav <?php print (current_path() == 'wordlet/patt_game' ? 'non-responsive' : 'responsive mobile-only'); ?>">		  
    <?php $slimnav = module_invoke('tp4_support', 'block_view', 'tp4_slim_nav'); ?>
    <?php print $slimnav['content']; ?>
  </div>

	<!-- start -->

	<div class="page-wrap">
		<div class="table int">
		
			<div class="header">
				<div class="logo">
					<a href="<?=wu('patt_home')?>">
						<?php if ( $w = w('logo') ): ?>
							<img src="<?=$w->img_src?>" width="357" height="206" alt="<?=$w->single(false)?>" <?=wa('logo')?> />
						<?php endif ?>
					</a>
				</div>
				<p class="mobile" id="mobile_back">
					<a href="<?=wu('patt_home')?>"><?=w('back')?></a>
				</p>
			</div>
			
			<div class="nav">
				<ul <?=wa('top_nav')?>>
					<?php foreach ( wl('top_nav') as $w ): ?>
						<li class="<?=wc($w->href_raw)?>"><a href="<?=$w->href?>" class="<?=ws($w->href)?>">
							<img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" />
							<span><?=$w->single(false)?></span>
						</a></li>
					<?php endforeach ?>
				</ul>
			</div>

			<main id="page" class="main">
				<?=$content?>
			</main>
			
		</div><!-- /.table -->
		
	</div><!-- /.page-wrap -->

	<!-- end -->

</div>
<div class="footer-wrapper <?php print (current_path() == 'wordlet/patt_game' ? 'non-responsive' : 'responsive mobile-only'); ?>"> 
  <footer>
    <?php $footer = module_invoke('tp4_support', 'block_view', 'tp4_footer'); ?>
    <?php print $footer['content']; ?>
  </footer>
</div>