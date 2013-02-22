<h2><?=w('header')?></h2>

<div class="first-block">
	<div class="form-block">
		<?=w('contest_form')?>
	</div>

	<div class="info-block">
		<div class="important-info-block">
			<h3><?=w('important_info_header')?></h3>
			<ol <?=wa('important_info')?>>
				<? foreach ( wl('important_info') as $w ): ?>
					<li>
						<?=$w->multi(false)?>
					</li>
				<? endforeach ?>
			</ol>
		</div>

		<div class="tips-block">
			<h3><?=w('tips_header')?></h3>
			<ul <?=wa('tips')?>>
				<? foreach ( wl('tips') as $w ): ?>
					<li>
						<strong><?=$w->single(false)?></strong> <?=$w->multi(false)?>
					</li>
				<? endforeach ?>
			</ul>
		</div>
	</div>
</div>