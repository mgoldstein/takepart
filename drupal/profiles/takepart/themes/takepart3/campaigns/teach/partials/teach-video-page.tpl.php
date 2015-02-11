<div class="teach-video-page">
    <!-- <h3 class="content-preheader"><?=w('page_preheader')?></h3> -->
    <h1 class="content-headline"><?=w('page_headline')?></h1>
    <h2 class="content-subheadline"><?=w('page_subheadline')?></h2>
    <!-- <h4 class="peek-a-boo"><?=w('social_follow_body')?></h4> -->
    <div data-jwposter-frame="<?= w('video')->src; ?>"
         data-jwplaylist="<?= w('video')->href; ?>"
         id="main-video-wrapper"
         class="main-video-wrapper" <?= wa('video'); ?>>
      <div id="main-video"></div>
    </div>

    <div class="columns-wrapper">
    <?php foreach ( wl('columns') as $i => $w ): ?>
        <?php $column_number = $i + 1; // the array is zero indexed ?>
        <?php $zebra = ($column_number % 2 == 0) ? 'even' : 'odd'; ?>
        <section class="content-column column-<?=$column_number?> column-<?=$zebra?>">
            <!-- <h1 class='col-headline'><?=$w->single?></h1> -->
            <div class="col-content cms">
                <?=$w->multi?>
            </div>
        </section>
    <?php endforeach ?>
    </div>
    <?php if (w('social_footer_label')) : ?>
    <div class="social-footer">
        <span><?=w('social_footer_label')?></span>
            <span <?=wa('social_facebook')?>>
            <?php if(w('social_facebook')->img_src) : ?>
            <a href="<?=w('social_facebook')->href?>" target="_blank">
    	       <img src="<?=w('social_facebook')->img_src?>" alt="<?=w('social_facebook')->single_no_markup?>">
            </a>
            <?php endif ?>
            </span>
            <span <?=wa('social_twitter')?>>
            <?php if(w('social_twitter')->img_src) : ?>
            <a href="<?=w('social_twitter')->href?>" target="_blank">
    	       <img src="<?=w('social_twitter')->img_src?>" alt="<?=w('social_twitter')->single_no_markup?>">
            </a>
            <?php endif ?>
            </span>
            <span <?=wa('social_gplus')?>>
            <?php if(w('social_gplus')->img_src) : ?>
            <a href="<?=w('social_gplus')->href?>" target="_blank">
    	       <img src="<?=w('social_gplus')->img_src?>" alt="<?=w('social_gplus')->single_no_markup?>">
            </a>
            </span>
            <?php endif ?>
    </div>
    <?php endif ?>
    <section class="social-menu">
        <?php include('teach-social-block.tpl.php') ?>
    </section>
    <?php include('teach-watch-promo.tpl.php') ?>
</div>