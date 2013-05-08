<div class="first-block">
	<div class="header-image" <?=wa('header_image')?>>
        <? if ( ($w = w('header_image')) && $w->img_src ): ?>
            <p>
                <img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" />
            </p>
        <? elseif( wordlet_edit_mode() ): ?>
            Add Image
        <? endif ?>
    </div>
    <h2 class='header-title'><?=wl('header_title')?></h2>
    <div class="header-text">
    	<?=wl('header_text')?>
    </div>
</div>

<div class="content-nav">
	<ul>
		<li>
            <a href="#about-intel"><span><?=w('intel_for_change')?></span></a>
        </li><li>
            <a href="#about-partners"><?=w('partners')?></a>
        </li>
	</ul>
</div>

<div class="content-info">
	<div id="about-intel" class="tab-content special-lists">
		<?=w('about_intel')?>
		<? if ( $w = w('intel_more') ): ?>
			<p class="more">
				<a href="<?=$w->href?>"><?=$w->single?></a>
			</p>
		<? endif ?>
	</div>

	<div id="about-partners"  class="tab-content" <?=wa('partners_list')?>>
		<? foreach ( wl('partners_list') as $w ): ?>
			<div class="partner">
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