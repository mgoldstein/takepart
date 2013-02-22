<div class="content">
	<h2><?=w('headline')?></h2>

	<div class="artists-list">
		<ul <?=wa('artists')?>>
			<? foreach( wl('artists') as $w ): ?>
				<? if ( $w->active ): ?>
					<li><a href="#<?=$w->token?>">
						<div class="portrait">
							<img src="<?=$w->img_src?>" alt="Portrait"/>
						</div>
						<span class="name">
							<?=$w->single(false)?>
						</span>
					</a></li>
				<? endif ?>
			<? endforeach ?>
		</ul>
	</div>

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
						<iframe width="560" height="315" src="http://www.youtube.com/embed/<?=$w->video?>" frameborder="0" allowfullscreen></iframe>
					</div>
				</div>
			<? endif ?>
		<? endforeach ?>
	</div>
</div>