<div id="page-wrapper" class="campaign">
<?php print $header ?>
    <div class="smartgirls">
        <div class="header-block">
            <span class="logo-intro"><?=w("presented_by")?></span>
            <? foreach ( wl('intel_logo') as $w ): ?>
                <img src="<?=$w->img_src?>" alt="<?=$w->single(false)?>" class="logo" <?=wa('intel_logo')?> />
            <? endforeach ?>
            
            <? foreach ( wl('site_title') as $w ): ?>
                <h1 <?=wa("site_title")?> style="background-image:url(<?=$w->img_src?>);">
                    <?=$w->single(false)?>
                </h1>
            <? endforeach ?>

        </div>
        <div class="first-block clearfix">
            <div class="main-info">
                <div class='vid-embed' <?=wa("video")?> >
                    <? foreach ( wl('video') as $w ): ?>
                        <? if ( $w->img_src != NULL ) : ?>
                            <iframe width="602" height="339" src="http://www.youtube.com/embed/<?=$w->img_src?>?rel=0&showinfo=0&theme=light&showsearch=0&hd=1&cc_load_policy=1&enablejsapi=1" frameborder="0" allowfullscreen></iframe>
                        <? else : ?>
                            <img src="<?=$w->href?>" alt="Intel for Change video placeholder" />
                        <? endif ?>
                    <? endforeach ?>
                </div>
            </div>
            <div class="intro">
                <?=w("intro_blurb")?>
                <div class="addThis">
                    <a class="addthis_button_facebook_like"></a>
                    <a class="addthis_button_tweet"></a>
                    <a class="addthis_button_email"></a>
                </div>
            </div>
        </div>

        <div class="second-block">
            <div class="form-desc">
                <h2><?=w("form_desc_title")?></h2>
                <div class="form-blurb">
                    <?=w("form_desc")?>
                </div>
            </div>
            <div class="form_wrapper">
                <div class="form-bg"></div>
                <div class="form-content">
                    <?=w("signup_form")?>
                </div>
            </div>
        </div>
        <div class="footer-block"></div>
    </div>
<?php print $footer ?>
</div>