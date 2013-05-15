<div class="first-block">
	<div class="image-wrapper" <?=wa('first_block_image')?>>
        <? if ( ($w = w('first_block_image')) && $w->img_src ): ?>
            <img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" />
        <? elseif( wordlet_edit_mode() ): ?>
            Add Image
        <? endif ?>
    </div>
    <h2 class='headline'><?=w('first_block_headline')?></h2>
    <div class="text-block cms">
    	<?=w('first_block_text')?>
    </div>
</div>
<div class="second-block">
	<h3 class="headline"><?=w('second_block_headline')?></h3>
    <div class="resources" <?=wa('resources')?>>
        <?=w('resources_view')?>
        <? foreach ( wl('resources') as $i => $resource ): ?>
            <a class="resource" href="<?=$resource->href?>">
                <span class="label"><?=$resource->single(false)?></span>
                <div class="text-block cms"><?=$resource->multi(false)?></div>
            </a>
        <? endforeach ?>
    </div>
</div>