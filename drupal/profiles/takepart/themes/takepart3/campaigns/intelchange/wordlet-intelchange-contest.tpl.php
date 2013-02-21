<div class="first-block">
	<? if ( $w = w('first_block') ): ?>
		<p class="image">
			<img src="<?=$w->img_src?>"/>
		</p>
		<div class="first-content">
			<h2><?=$w->single?></h2>
			<div class="cms">
				<?=$w->multi?>
			</div>
		</div>
	<? endif ?>
</div>