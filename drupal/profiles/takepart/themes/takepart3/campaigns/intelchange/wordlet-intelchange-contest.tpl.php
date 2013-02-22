<div class="first-block" <?=wa('first_block')?>>
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

<div class="second-block">
	<div class="first-sub">
		<h3><?=w('howto_header')?></h3>
		<div class="cms">
			<?=w('howto_body')?>
		</div>
		<p class="more">
			<? if ( $w = w('howto_more') ): ?>
				<a href="<?=$w->href?>"><?=$w->single?></a>
			<? endif ?>
		</p>
	</div>

	<div class="second-sub">
		<div class="instructions">
			<ol <?=wa('instructions')?>>
				<? foreach ( wl('instructions') as $w ): ?>
					<li>
						<?=$w?>
					</li>
				<? endforeach ?>
			</ol>
		</div>

		<p class="important">
			<a href="<?=wu('intelchange_contest_enter')?>"><?=w('enter_the_contest')?></a>
		</p>
	</div>
</div>

<div class="third-block">
	<h3><?=w('countries_header')?></h3>
	<div class="countries_nav">
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