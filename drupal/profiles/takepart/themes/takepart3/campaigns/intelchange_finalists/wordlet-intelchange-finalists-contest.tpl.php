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
	<div class="first-sub" <?=wa('cta_image')?>>
		<div class="header-block">
			<h3><?=w('cta_header')?></h3>
			<h4><?=w('cta_subheader')?></h4>
	        <div class='more-wrapper' <?=wa('contest_more')?>>
	            <div class="more">
	                <? $w = w('contest_more') ?>
	                <? if ( $w->multi(false) ): ?>
	                    <?=$w->multi(false)?>
	                <? elseif($w->single(false)): ?>
	                    <p><a href="<?=wu('intelchange_finalists_vote')?>"><?=$w->single(false)?></a></p>
	                <? elseif(wordlet_edit_mode()): ?>
	                    Add Link
	                <?endif?>
	            </div>
	        </div>
		</div>
		<? if ( $w = w('cta_image') ): ?>
		<div class="prize-image">
			<img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>">
		</div>
		<? endif ?>
	</div>

	<div class="second-sub">
		<div class="sub-wrapper">
			<div class="finalists-wrapper">
				<ul class="finalists-menu" <?=wa('finalists')?>>
					<? foreach ( wl('finalists', true) as $w ): ?>
						<li><a href="<?=wu('intelchange_finalists_vote')?>#<?=$w->token?>"><div class="outline"></div><img src="<?=$w->thumb_src?>" alt="<?=$w->single(false)?>" ></a></li>
					<? endforeach ?>
				</ul>
			</div>
			<div class="instructions">
				<?=w('cta_instructions')?>
			</div>
			<p class="important">
				<a href="<?=wu('intelchange_finalists_vote')?>"><?=w('view_finalists_cta')?></a>
			</p>
		</div>
	</div>
</div>

<div class="third-block">
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