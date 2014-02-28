<div class="content teach-news-content">
	<article class="content-inner">
        <h1 class="content-headline"><?php print w('page_headline'); ?></h1>
        <h2 class="content-subheadline"><?php print w('page_subheadline'); ?></h2>
        <div class="news-featured-wrapper"><?php print w('featured_articles'); ?></div>
        <div class="related-articles">
            <?php print w('related_articles');?>
        </div>
    </article>
    <section class="social-menu"><?php include('partials/teach-social-block.tpl.php'); ?></section>
    <?php include('partials/teach-watch-promo.tpl.php'); ?>
</div>
