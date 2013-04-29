<div class="first-block">
    <div class="intro-block">
        <div class="intro-content">
            <div class="intro-image" <?=wa('intro-image')?>>
                <? if ( ($w = w('intro-image')) && $w->img_src ): ?>
                    <p>
                        <img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" />
                    </p>
                <? endif ?>
            </div>
            <div class="intro-text">
                <div class="intro-blurb">
                    <?=w('intro')?>
                </div>
                <p class="intro-link">
                    <?=w('intro_link')?>
                </p>
            </div>
        </div>
        <p class="video-play" <?=wa('video')?>>
            <? if ( w('video')->video ): ?>
                <a href="http://www.youtube.com/watch?v=<?=w('video')->video?>"><?=w('video')->single?></a>
            <? elseif( wordlet_edit_mode() ): ?>
                Add Video
            <? endif ?>
        </p>
    </div>

    <script id="video-template" type="text/x-javascript-template">
        <div class="video-block">
            <iframe width="560" height="315" src="http://www.youtube.com/embed/<?=w('video')->video?>?autoplay=true" frameborder="0" allowfullscreen></iframe>
            <p class="close">
                <a href="#">Close</a>
            </p>
        </div>
    </script>
</div>

<div class="second-block">
    <div class="first-sub" <?=wa('cta_image')?>>
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
        <p class="important">
            <a href="<?=wu('intelchange_vote')?>"><?=w('view_finalists_cta')?></a>
        </p>

        <div class="more" <?=wa('contest_more')?>>
            <? $w = w('contest_more') ?>
            <? if ( $w->multi(false) != "" ): ?>
                <?=$w->multi(false)?>
            <? else: ?>
                <p><a href="<?=wu('intelchange_contest')?>"><?=$w->single(false)?></a></p>
            <?endif?>
        </div>
    </div>

    <div class="second-sub form_wrapper">
        <div class="default-state">
            <div class="default-content">
                <h3><?=w('default_header')?></h3>
                <div class="finalists-wrapper">
                    <ul class="finalists-menu" <?=wa('finalists')?>>
                        <? foreach ( wl('finalists', true) as $w ): ?>
                            <li>
                                <p class="image"><img src="<?=$w->small_src?>" alt="<?=$w->single(false)?>" ></p>
                                <div class="bio">
                                    <h4 class="finalist_headline"><?=$w->single(false) ?></h4>
                                    <p class="info"><?=$w->multi_short ?></p>
                                    <div class="blurb"><?=$w->multi(false) ?></div>
                                </div>
                                <a href="<?=wu('intelchange_vote')?>#<?=$w->token?>"><?=w('read_more') ?></a>
                            </li>
                        <? endforeach ?>
                    </ul>
                </div>
                <p class="enter-contest important">
                    <a href="<?=wu('intelchange_contest')?>"><?=w('enter_the_contest')?></a>
                </p>
            </div>
            <div class="stay-contected cta" <?=wa('stay_connected')?>>
                <a href="#stay-connected">
                    <? if ( $w = w('stay_connected') ): ?>
                        <h4><?=$w->single(false)?></h4>
                        <?=$w->multi(false)?>
                    <? endif ?>
                </a>
            </div>
        </div>

        <div id="stay-connected" class="form-state form-content">
            <?=w('stay_connected_form')?>
        </div>
    </div>
</div>

<div class="footer-block">
    <div class="facts-block" <?=wa('facts')?>>
        <? foreach ( wl('facts') as $i => $w ): ?>
            <div class="fact fact<?=$i?>">
                <? if ( $w->href ): ?>
                    <a href="<?=$w->href?>"><img src="<?=$w->img_src?>"></a>
                <? else: ?>
                    <img src="<?=$w->img_src?>">
                <? endif ?>
            </div>
        <? endforeach ?>
    </div>

    <div class="partners-block">
        <a href="<?=wu('intelchange_about')?>#about-partners">
            <h4><?=w('partners_header')?></h4>
            <ul class="partners-list" <?=wa('partners_list')?>>
                <? foreach ( wl('partners_list') as $w ): ?>
                    <li class="parnter">
                        <img alt="<?=$w->single(false)?>" src="<?=$w->thumb_src?>"/>
                    </li>
                <? endforeach ?>
            </ul>
        </a>
    </div>
</div>