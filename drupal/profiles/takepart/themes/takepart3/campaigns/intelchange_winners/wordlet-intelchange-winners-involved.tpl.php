<div class="first-block">
	<div class="image-wrapper" <?=wa('first_block_image')?>>
        <? if ( ($w = w('first_block_image')) && $w->img_src ): ?>
            <img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" />
        <? elseif( wordlet_edit_mode() ): ?>
            Add Image
        <? endif ?>
    </div>
    <div class="first-sub">
        <h2 class='headline'><?=w('first_block_headline')?></h2>
        <div class="text-block cms">
            <?=w('first_block_text')?>
        </div>
        <div class="important" <?= wa('first_block_cta')?>>
            <a href="<?=w('first_block_cta')->href?>"><?=w('first_block_cta')->single(false)?></a>
        </div>
    </div>
</div>
<div class="second-block" <?=wa('read_more_items')?>>
    <h2 class='headline'><?=w('second_block_headline')?></h2>
    <? foreach ( wl('read_more_items') as $w ): ?>
    <div class="read-more">
        <div class="image-wrapper">
            <? if ( ($w->img_src ) ): ?>
                <img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" />
            <? elseif( wordlet_edit_mode() ): ?>
                Add Image
            <? endif ?>
        </div>
        <div class="first-sub">
            <span class="name"><?=$w->single(false)?></span>
            <div class="text-block cms">
                <?=$w->multi(false)?>
            </div>
            <a class="read-more-link" href='<?=$w->href(false)?>'><?=wr(w('read_more_link_label'), $w)?></a>
        </div>
    </div>
    <? endforeach ?>
</div>