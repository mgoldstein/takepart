<div class="first-block interim" <?=wa('first_block')?>>
	<? if ( $w = w('first_block') ): ?>
		<p class="image">
			<img src="<?=$w->img_src?>"/>
		</p>
		<div class="first-content">
			<h2><?=$w->single(false)?></h2>
			<div class="cms">
				<?=$w->multi(false)?>
			</div>
		</div>
	<? endif ?>
</div>

<div class="third-block interim">
	<h3><?=w('countries_header')?></h3>
	<div class="countries-nav">
		<ul <?=wa('countries')?>>
			<? foreach ( wl('countries') as $w ): ?>
				<li>
					<a href="#country_<?=$w->token?>"><?=$w->single(false)?></a>
				</li>
			<? endforeach ?>
		</ul>
	</div>

	<div class="countries" <?=wa('countries')?>>
		<? foreach ( wl('countries') as $w ): ?>
			<div id="country_<?=$w->token?>">
				<div class="country_image">
					<p>
						<img src="<?=$w->img_src?>" alt="<?=$w->single(false)?> Image" />
					</p>
				</div>
				<div class="country_body cms">
					<?=$w->multi(false)?>
				</div>
			</div>
		<? endforeach ?>
	</div>
</div>