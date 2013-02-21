<div class="first-block">
    <div class="inro-content cms">
        <?=w('intro')?>
    </div>
    <? if ( $w = w('intro_link') ): ?>
        <p class="intro-link">
            <a href="<?=$w->href?>"><?=$w->single?></a>
        </p>
    <? endif ?>
    <p class="video-play">
        <a href="http://www.youtube.com/watch?v=<?=$w->video?>">Video</a>
    </p>
    <div class="video-block">

    </div>
    <script id="video-template" type="text/x-javascript-template">
        <iframe width="560" height="315" src="http://www.youtube.com/embed/<?=$w->video?>?autoplay=true" frameborder="0" allowfullscreen></iframe>
    </script>
</div>

<div class="second-block">
    <div class="form-desc">
        <h2><?=w('form_desc_header')?></h2>
        <div class="form-blurb">
            <?=w('form_blurb')?>
        </div>
        <? if ( $w = w('contest_more') ): ?>
            <p class="more">
                <a href="<?=$w->href?>"><?=$w->single?></a>
            </p>
        <? endif ?>
    </div>

    <div class="form_wrapper">
        <div class="form-bg"></div>

        <div class="default-state">
            <h3><?=w('default_header')?></h3>
            <p class="enter-contest">
                <a href="<?=wu('intelchange_contest')?>"><?=w('enter_the_contest')?></a>
            </p>
            <p class="stay-contected cta">
                <a href="#stay-connected">
                    <? if ( $w = w('stay_connected') ): ?>
                        <h4><?=$w->single?></h4>
                        <p><?=$w->multi?></p>
                    <? endif ?>
                </a>
            </p>
            <p class="more-ways cta">
                <? if ( $w = w('more_ways') ): ?>
                    <a href="<?=$w->href?>">
                        <h4><?=$w->signle?></h4>
                        <p><?=$w->multi?></p>
                    </a>
                <? endif ?>
            </p>
        </div>

        <div id="stay-connected" class="form-state form-content">
            <?=w('stay_connected_form')?>
        </div>
    </div>
</div>

<div class="footer-block">
    <div class="facts-block">
        <? foreach ( w('facts') as $w ): ?>
            <div class="fact">
                <a href="<?=$w->href?>"><img src="<?=$w->img_src?>"></a>
            </div>
        <? endforeach ?>
    </div>

    <div class="partners-block">
        <h4><?=w('partners_header')?></h4>
        <ul>
            <? foreach ( wl('partners_list') as $w ): ?>
                <li class="parnter">
                    <a href="<?=$w->href?>">
                        <img alt="<?=$w->single(false)?>" src="<?=$w->thumb_src?>"/>
                    </a>
                </li>
            <? endforeach ?>
        </ul>
    </div>
</div>