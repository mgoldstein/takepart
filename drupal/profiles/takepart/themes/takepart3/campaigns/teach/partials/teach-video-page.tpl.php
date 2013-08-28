<div class="teach-video-page">
    <h1 class="content-headline"><?=w('page_headline')?></h1>
    <h2 class="content-subheadline"><?=w('page_subheadline')?></h2>
    <div class="main-video-wrapper" <?=wa('video')?>>
       VIDEO PLAYER GOES HERE LOL!
    </div>
    <? foreach ( wl('columns') as $i => $w ): ?>
        <section class="column-first">
            <h1 class='col-headline'><?=$w->single?></h1>
            <div class="col-content">
                <?=$w->multi?>
            </div>
        </section>
    <? endforeach ?>
    <? include('partials/teach-social-block.tpl.php') ?>
    <div class="social-footer">
        <span><?=w('social_footer_label')?></span>
        <a href="<?=w('social_facebook')->href?>" target="_blank">
            <img src="<?=w('social_facebook')->img_src?>" alt="<?=w('social_facebook')->img_single?>">
        </a>
        <a href="<?=w('social_twitter')->href?>" target="_blank">
            <img src="<?=w('social_twitter')->img_src?>" alt="<?=w('social_twitter')->img_single?>">
        </a>
        <a href="<?=w('social_gplus')->href?>" target="_blank">
            <img src="<?=w('social_gplus')->img_src?>" alt="<?=w('social_gplus')->img_single?>">
        </a>
    </div>
    <div class="ad">
        <?=w('ad')?>
    </div>
</div>