<div class="content teach-news-content">
	<article class="content-inner">
        <h3 class="label-headline"><?=w('page_preheader')?></h3>
        <h4 class="peek-a-boo"><?=w('social_follow_body')?></h4>
        <div class="main-video-wrapper" <?=wa('video')?>>
            <script src="<?=w('video')?>"></script>
        </div>
        <h1 class="content-headline"><?=w('page_headline')?></h1>
        <h2 class="content-subheadline"><?=w('page_subheadline')?></h2>
        <div class="news-featured-wrapper">
            <?=w('featured_articles')?>
        </div>
        <div class="related-articles">
            <?=w('related_articles')?>
        </div>
    </article>
    <section class="social-menu">
        <? include('partials/teach-social-block.tpl.php') ?>
    </section>
    <div class="ad">
        <?=w('ad')?>
    </div>
</div>