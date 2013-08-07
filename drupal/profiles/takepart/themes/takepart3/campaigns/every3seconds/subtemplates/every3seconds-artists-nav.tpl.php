<div class="artists-list">
	<ul <?=wa('artists')?>>
		<? foreach( wl('artists') as $w ): ?>
			<? if ( $w->active ): ?>
				<li><a href="<?=wu('every3seconds_video')?>#<?=$w->token?>">
					<div class="portrait">
						<img src="<?=$w->img_src?>" alt="Portrait"/>
					</div>
					<span class="name">
						<?=$w->single(false)?>
					</span>
				</a></li>
			<? else: ?>
				<li class='inactive'>
					<div class="portrait">
						<img src="<?=$w->img_src?>" alt="Portrait"/>
					</div>
					<span class="name">
						<?=$w->single(false)?>
					</span>
				</li>
			<? endif ?>
		<? endforeach ?>
	</ul>
</div>