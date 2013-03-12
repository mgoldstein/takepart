<h2><?=w('header')?></h2>

<div class="first-block">
    <script type="text/javascript">
	    if (typeof addthis_config !== "undefined") {
			addthis_config.ui_email_note = '<?=addslashes(w('thanks_email_message')->single(false))?>';
		} else {
			var addthis_config = {
				ui_email_note: '<?=addslashes(w('thanks_email_message')->single(false))?>'
			};
		}
    </script>

	<? if ( wordlet_edit_mode() ): ?>
		<p>
			Thank-you Email Note: <?=w('thanks_email_message')?>
		</p>
	<? endif ?>

	<div class="form-block cms">
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