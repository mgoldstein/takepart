<div class="content">
	<h2><?=w('headline')?></h2>

	<? include_once('subtemplates/eyelevel-artists-nav.tpl.php') ?>

	<div class="artist-info" <?=wa('artists')?>>
		<? foreach( wl('artists') as $w ): ?>
			<? if ( $w->active ): ?>
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
			<? endif ?>
		<? endforeach ?>
	</div>
</div>