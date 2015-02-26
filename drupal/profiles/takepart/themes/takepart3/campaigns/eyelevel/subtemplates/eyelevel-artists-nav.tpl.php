<div class="artists-list">
	<ul <?=wa('artists')?>>
		<?php foreach( wl('artists') as $w ): ?>
			<?php if ( $w->active ): ?>
				<li><a href="<?=wu('eyelevel_video')?>#<?=$w->token?>">
					<div class="portrait">
						<img src="<?=$w->img_src?>" alt="Portrait"/>
					</div>
					<span class="name">
						<?=$w->single(false)?>
					</span>
				</a></li>
			<?php else: ?>
				<li class='inactive'>
					<div class="portrait">
						<img src="<?=$w->img_src?>" alt="Portrait"/>
					</div>
					<span class="name">
						<?=$w->single(false)?>
					</span>
				</li>
			<?php endif ?>
		<?php endforeach ?>
	</ul>
</div>