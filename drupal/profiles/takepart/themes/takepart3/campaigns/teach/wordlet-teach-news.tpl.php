<div class="content teach-news-content">
	<article class="content-inner">
    <?php if ($w = w('page_preheader')) : ?>
        <h3 class="label-headline"><?=$w?></h3>
    <?php endif; ?>
    <?php if ($w = w('social_follow_body')) : ?>
        <h4 class="peek-a-boo"><?=$w?></h4>
    <?php endif; ?>
    <?php if($w = w('video')) : ?>
        <div class="main-video-wrapper" <?=wa('video')?>>
            <script src="<?=$w?>"></script>
        </div>
    <?php endif; ?>
    <?php if($w = w('page_headline')) : ?>
        <h1 class="content-headline"><?=$w?></h1>
    <?php endif; ?>
    <?php if($w = w('page_subheadline')) : ?>
        <h2 class="content-subheadline"><?=$w?></h2>
    <?php endif; ?>
    <?php if($w = w('featured_articles')) : ?>
        <div class="news-featured-wrapper">
            <?=$w?>
        </div>
    <?php endif; ?>
    <?php if($w = w('related_articles')) : ?>
        <div class="related-articles">
            <?=$w?>
        </div>
    <?php endif; ?>
    </article>
    <section class="social-menu">
        <? include('partials/teach-social-block.tpl.php') ?>
    </section>
    <? include('partials/teach-watch-promo.tpl.php') ?>
    <?php if($w = w('ad')) : ?>
    <div class="ad">
        <?=$w?>
    </div>
    <?php endif; ?>
</div>