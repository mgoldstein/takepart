<div class="content-nav">
	<ul>
		<li><a href="#about-intel"><?=w('intel_for_change')?></a></li>
		<li><a href="#about-partners"><?=w('partners')?></a></li>
	</ul>
</div>

<div class="content-info">
	<div id="about-intel">
		<?=w('about_intel')?>
		<? if ( $w = w('intel_more') ): ?>
			<p class="more">
				<a href="<?=$w->href?>"><?=$w->single?></a>
			</p>
		<? endif ?>
	</div>

	<div id="about-partners" <?=wa('about_partners')?>>
		<? foreach ( wl('about_partners') as $w ): ?>
			<div class="parnter">
				<p class="image">
					<a href="<?=$w->href?>">
						<img src="<?=$w->img_src?>"/>
					</a>
				</p>
				<div class="description cms">
					<?=$w->multi(false)?>
				</div>
			</div>
		<? endforeach ?>
	</div>
</div>