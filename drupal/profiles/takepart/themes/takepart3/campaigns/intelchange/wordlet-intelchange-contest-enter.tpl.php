<h2><?=w('header')?></h2>

<div class="first-block">
	<? if ( wordlet_edit_mode() ): ?>
		<div>
			<p>Share Block Message: <?=w('thanks_share_message')?></p>
			<p>Share Block URL: <?=w('thanks_share_url')?></p>
		</div>
	<? endif ?>

	<div class="form-block cms"
		data-thankyouUrl='<?=addslashes(w('thanks_share_url')->single(false))?>'
		data-thankyouMessage='<?=addslashes(w('thanks_share_message')->single(false))?>'>
		<?=w('contest_form')?>
	</div>

	<div class="info-block">
		<div class="important-info-block">
			<h3><?=w('important_info_header')?></h3>
			<ol <?=wa('important_info')?> class='cms'>
				<? foreach ( wl('important_info') as $w ): ?>
					<li>
						<?=$w->multi(false)?>
					</li>
				<? endforeach ?>
			</ol>
		</div>

		<div class="tips-block">
			<h3><?=w('tips_header')?></h3>
			<ul <?=wa('tips')?> class='cms'>
				<? foreach ( wl('tips') as $w ): ?>
					<li>
						<strong><?=$w->single(false)?></strong> <?=$w->multi(false)?>
					</li>
				<? endforeach ?>
			</ul>
		</div>
	</div>
</div>