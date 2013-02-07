<div class="column">
	<div class="inner">
		<div class="overview">
			<div class="cms">
				<?=w('body')?>
			</div>
		</div>

		<div class="primary_alliances">
			<?=we('primary_alliances')?>
			<? if ( w('primary_alliances') ): ?>
				<ul>
					<? foreach ( wl('primary_alliances') as $w ): ?>
						<li><a href="<?=$w->href?>">
							<img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" width="275" height="86" />
						</a></li>
					<? endforeach ?>
				</ul>
			<? endif ?>
		</div>

		<div class="secondary_alliances">
			<div class="cms">
				<?=w('secondary_alliances_header')?>
			</div>
			<?=we('secondary_alliances')?>
			<? if ( w('secondary_alliances') ): ?>
				<ul>
					<? foreach ( wl('secondary_alliances') as $w ): ?>
						<li><a href="<?=$w->href?>">
							<?=$w->single(false)?>
						</a></li>
					<? endforeach ?>
				</ul>
			<? endif ?>
		</div>
	</div><!-- /.inner -->
</div>