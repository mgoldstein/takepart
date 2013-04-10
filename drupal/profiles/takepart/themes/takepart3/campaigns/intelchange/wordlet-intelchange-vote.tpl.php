<div class="first-block" <?=wa('cta_image')?>>
    <div class="header-block cms">
        <h3><?=w('cta_header')?></h3>
        <h4><?=w('cta_subheader')?></h4>
        <div class="vote-desc">
            <?=w('vote_desc')?>
        </div>
    </div>
    <? if ( $w = w('cta_image') ): ?>
    <div class="prize-image">
        <img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>">
    </div>
    <? endif ?>
</div>
<div class="second-block">
    <h4><?=w('vote_header')?></h4>
    <div class="vote" <?=wa('finalists')?>>
        <ul class="finalists">
        <?
        $finalists = array();
        foreach (wl('finalists') as $i => $w):
            array_push($w);
        endforeach
        shuffle($finalists);
        ?>
        <? foreach ( $finalists as $i => $w ): ?>
            <li class='<?= $i&1?"even":"odd"?>'>
                <a href="<?=wu('intelchange_vote')?>#<?=$w->token?>">
                    <img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>">
                    <span class="name"><?=$w->single(false)?></span>
                </a>
            </li>
        <? endforeach ?>
        </ul>
        <? endif ?>
    </div>
</div>