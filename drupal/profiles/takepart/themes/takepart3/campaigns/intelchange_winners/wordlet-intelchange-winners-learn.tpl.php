<div class="first-block">
	<div class="image-wrapper" <?=wa('first_block_image')?>>
        <? if ( ($w = w('first_block_header_image')) && $w->img_src ): ?>
            <img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" />
        <? elseif( wordlet_edit_mode() ): ?>
            Add Image
        <? endif ?>
    </div>
    <h2 class='headline'><?=wl('first_block_headline')?></h2>
    <div class="text-block cms">
    	<?=wl('first_block_text')?>
    </div>
</div>
<div class="second-block">
	<h3 class="header-title"><?=wl('second_block_headline')?></h3>
	<div class="resources"><?=wl('resources_view')?></div>
</div>