<? if ( wordlet_edit_mode() ): ?>
	<div class="wordlet_edit_mode">
		<p>
			Page Title: <span><?=w('title')?></span>
		</p>
		<p>
			Campaign Name: <span><?=w('campaign_name')?></span>
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
			Google Ad Slots: <span><?=w('google_ad_slots')?></span>
		</p>
		<p>
			FB Image: <span><?=w('fb_image')?></span>
		</p>
		<p>
			FB Description: <span><?=w('fb_description')?></span>
		</p>
		<p>
			Meta Description: <span><?=w('meta_description')?></span>
		</p>
	</div>
<? endif ?>

<?=$content?>
