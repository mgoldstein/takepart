<div class="content">
	<h2><?=w('headline')?></h2>

	<?php include_once('subtemplates/education-artists-nav.tpl.php') ?>

	<div class="artist-info" <?=wa('artists')?>>
		<?php foreach( wl('artists') as $w ): ?>
			<?php if ( $w->active ): ?>
				<div id="<?=$w->token?>" class='artist'>
					<div class="info-wrapper">
						<h3><?=$w->single(false)?></h3>
						<div class="info">
							<?=$w->multi(false)?>
						</div>
					</div>
					<div class="video">
						<iframe width="460" height="315" src="http://www.youtube.com/embed/<?=$w->video?>" frameborder="0" allowfullscreen></iframe>
					</div>
				</div>
			<?php endif ?>
		<?php endforeach ?>
	</div>
</div>