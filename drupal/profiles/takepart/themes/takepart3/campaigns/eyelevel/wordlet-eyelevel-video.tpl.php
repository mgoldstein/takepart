<div class="content">
	<h2><?=w('headline')?></h2>

	<div class="artists_list">
		<ul <?=wa('artists')?>>
			<? foreach( wl('artists') as $w ): ?>
				<li><a href="#<?=$w->token?>">
					<p class="portrait">
						<img src="<?=$w->img_src?>" alt="Portrait"/>
					</p>
					<p class="name">
						<?=$w->single(false)?>
					</p>
				</a></li>
			<? endforeach ?>
		</ul>
	</div>

	<div class="artist_info" <?=wa('artists')?>>
		<? foreach( wl('artists') as $w ): ?>
			<div id="<?=$w->token?>">
				<h3><?=$w->single(false)?></h3>
				<div class="info cms">
					<?=$w->multi(false)?>
				</div>
				<div class="video">
					<iframe width="560" height="315" src="http://www.youtube.com/embed/<?=$w->video?>" frameborder="0" allowfullscreen></iframe>
				</div>
			</div>
		<? endforeach ?>
	</div>
</div>