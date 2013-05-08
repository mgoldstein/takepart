<div class="first-block">
    <div class="intro-block">
        <div class="intro-block-inner">
            <div class="intro-content">
                <div class="intro-image" <?=wa('intro-image')?>>
                    <? if ( ($w = w('intro-image')) && $w->img_src ): ?>
                        <p>
                            <img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" />
                        </p>
                    <? elseif( wordlet_edit_mode() ): ?>
                        Add Image
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
    <div class="first-sub">
        <h2 class='title'><?=w('second_block_first_sub_title')?></h2>
        <div class="text-block cms">
            <?=w('second_block_first_sub_first_text')?>
        </div>
        <h3 class='subtitle'><?=w('second_block_first_sub_subtitle')?></h3>
        <div class="text-block cms">
            <?=w('second_block_first_sub_text')?>
        </div>
        <div class="important">
            <a href="<?=wu('intelchange_winners_involved')?>"><?=w('second_block_first_sub_cta')?></a>
        </div>
    </div>

    <div class="second-sub form_wrapper">
        <div class="default-state">
            <div class="default-content">
                <h2 class='title'><?=w('default_header')?></h2>

                <div class="winners-wrapper">
                    <h4 class="subtitle"><?=$w->single(false) ?></h4>
                    <div class="important">
                        <a href="<?=wu('intelchange_winners_vote')?>#<?=$w->token?>"><?=w('read_more') ?></a>
                    </div>
                    <ul class="finalists-menu" <?=wa('finalists')?>>
                        <? foreach ( wl('finalists', true) as $w ): ?>
                            <li>
                                <p class="image"><img src="<?=$w->small_src?>" alt="<?=$w->single(false)?>" ></p>
                                <div class="bio">
                                    <h4 class="subtitle"><?=$w->single(false) ?></h4>
                                    <div class="info"><?=$w->multi_short(false) ?></div>
                                    <div class="blurb"><?=$w->multi(false) ?></div>
                                </div>

                            </li>
                        <? endforeach ?>
                    </ul>
                </div>

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