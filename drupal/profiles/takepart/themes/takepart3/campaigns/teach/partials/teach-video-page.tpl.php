<div class="teach-video-page">
    <h3 class="content-preheader"><?=w('page_preheader')?></h3>
    <h1 class="content-headline"><?=w('page_headline')?></h1>
    <h2 class="content-subheadline"><?=w('page_subheadline')?></h2>
    <h4 class="peek-a-boo"><?=w('social_follow_body')?></h4>
    <div class="main-video-wrapper" <?=wa('video')?>>
        <script src="<?=w('video')?>"></script>
    </div>
    <? foreach ( wl('columns') as $i => $w ): ?>
        <? $column_number = $i + 1; // the array is zero indexed ?>
        <? $zebra = ($column_number % 2 == 0) ? 'even' : 'odd'; ?>
        <section class="content-column column-<?=$column_number?> column-<?=$zebra?>">
            <h1 class='col-headline'><?=$w->single?></h1>
            <div class="col-content cms">
                <?=$w->multi?>
            </div>
        </section>
    <? endforeach ?>
    <section class="social-menu">
        <? include('teach-social-block.tpl.php') ?>
    </section>
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