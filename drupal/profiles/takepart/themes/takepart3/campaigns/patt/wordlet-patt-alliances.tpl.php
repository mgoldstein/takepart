<div class="column">
	<div class="inner">
		<div class="overview">
			<div class="cms">
				<?=w('body')?>
			</div>
		</div>

		<div class="primary_alliances">
			<ul <?=wa('primary_alliances')?>>
				<? foreach ( wl('primary_alliances') as $w ): ?>
					<li><a href="<?=$w->href?>">
						<img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" width="275" height="86" />
					</a></li>
				<? endforeach ?>
			</ul>
		</div>

		<div class="secondary_alliances">
			<div class="cms">
				<?=w('secondary_alliances_header')?>
			</div>

			<ul <?=wa('secondary_alliances')?>>
				<? foreach ( wl('secondary_alliances') as $w ): ?>
					<li><a href="<?=$w->href?>">
						<?=$w->single(false)?>
					</a></li>
				<? endforeach ?>
			</ul>
		</div>
	</div><!-- /.inner -->
</div>