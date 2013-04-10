<div class="first-block" <?=wa('cta_image')?>>
    <div class="header-block cms">
        <h2><?=w('cta_header')?></h2>
        <h3><?=w('cta_subheader')?></h3>
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
    <div class="vote" <?=wa('finalists')?>>
        <h3><?=w('vote_header')?></h3>
        <ul class="finalists">
        <?
        $finalists = iterator_to_array(wl('finalists'));
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
        <div class="finalist_content">
            <? foreach ( $finalists as $i => $w ): ?>
            <div id='<?=$w->token?>' class="finalist">
                <div class="video">
                    <iframe width="541" height="305" src="http://www.youtube.com/embed/<?=$w->video?>" frameborder="0" allowfullscreen></iframe>
                </div>
                <h4><?=$w->single(false)?></h4>
                <div class="cms">
                    <?=$w->multi(false)?>
                </div>
                <p class="important">
                    <a href="google.com"><?=w('vote_finalist_'.$w->token)?></a>
                </p>
                <div class="addThis"
                    data-message="MESSAGEVARIABLE"
                    data-url="URLVARIABLE">
                    <a class="addthis_button_facebook at300b" title="Facebook" href="#"><img src="/profiles/takepart/modules/takepart_addthis/images/ta_fb_share.png" alt="Share on Facebook"></a>
                    <a class="addthis_button_twitter at300b" title="Tweet" href="#"><img src="/profiles/takepart/modules/takepart_addthis/images/ta_twitter_share.png" alt="Share on Twitter"></a>
                    <a class="addthis_button_email at300b" title="Email" href="#"><img src="/profiles/takepart/modules/takepart_addthis/images/ta_email_share.png" alt="Share by Email"></a>
                </div>
            </div>
            <? endforeach ?>
        </div>
    </div>
</div>