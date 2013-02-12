<? if ( wordlet_edit_mode() ): ?>
	<div class="wordlet_edit_mode">
		<p>
			Page Title: <?=w('title')?>
		</p>
		<? if ( ($wlinks = wordlet_configure_links()) ): ?>
			<p>Configure:
				<? foreach ( $wlinks as $wlink ): ?>
					<span>
						<?=$wlink?>
					</span>
				<? endforeach ?>
			</p>
		<? endif ?>
		<p>
			FB Image: <?=w('fb_image')?>
		</p>
		<p>
			FB Description: <?=w('fb_description')?>
		</p>
	</div>
<? endif ?>

<?=$content?>