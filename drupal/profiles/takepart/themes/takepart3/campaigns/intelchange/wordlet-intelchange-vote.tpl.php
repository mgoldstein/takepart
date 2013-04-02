<div class="first-block" <?=wa('cta_image')?>>
    <div class="header-block">
        <h3><?=w('cta_header')?></h3>
        <h4><?=w('cta_subheader')?></h4>
    </div>
    <? if ( $w = w('cta_image') ): ?>
    <div class="prize-image">
        <img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>">
    </div>
    <? endif ?>
    <div class="vote-desc">
        <?=w('vote_desc')?>
    </div>
</div>