<div id="page-wrapper" class="campaign">
	<?php print $header ?>

	<!-- start -->

	<div class="page-wrap">
		<div class="table int">
		
			<div class="header">
				<div class="logo">
					<a href="<?=wu('patt_home')?>">
						<? foreach ( wl('logo') as $w ): ?>
							<a href="<?=$w->href?>"><img src="<?=$w->img_src?>" width="357" height="206" alt="<?=$w->single(false)?>" <?=wa('logo')?> /></a>
						<? endforeach ?>
					</a>
				</div>
				<p class="mobile" id="mobile_back">
					<a href="<?=wu('patt_home')?>"><?=w('back')?></a>
				</p>
			</div>
			
			<div class="nav">
				<ul>
					<? foreach ( wl('top_nav') as $w ): ?>
						<li class="<?=wc($w->href_raw)?>"><a href="<?=$w->href?>">
							<span><?=$w->single?></span>
						</a></li>
					<? endforeach ?>
				</ul>
			</div>

			<div class="main">
				<?=$content?>
			</div>
			
		</div><!-- /.table -->
		
	</div><!-- /.page-wrap -->

	<!-- end -->

	<?php print $footer ?>
</div>