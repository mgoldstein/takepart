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
<div class="second-block">
	<h3 class="header-title"><?=wl('secondary_header_title')?></h3>
	<div class="resources"><?=wl('resources_view')?></div>
</div>