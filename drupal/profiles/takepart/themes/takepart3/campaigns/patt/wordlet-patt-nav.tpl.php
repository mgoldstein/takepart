<div id="page-wrapper" class="campaign">
	<?=$header?>
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
						<li class="<?=wc($w->href_raw)?> <?=($w->token == 'patt_action')?'active':''?>"><a href="<?=$w->href?>">
							<img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" />
							<span><?=$w->single(false)?></span>
						</a></li>
					<?php endforeach ?>
				</ul>
			</div>
		</div><!-- /.table -->
	</div><!-- /.page-wrap -->
</div>