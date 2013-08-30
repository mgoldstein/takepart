<div class="content">
	<article class="content-inner">
        <h1 class="content-headline"><?=w('page_headline')?></h1>
        <h2 class="content-subheadline"><?=w('page_subheadline')?></h2>
        <div class="images-wrapper">
            <? foreach ( wl('images') as $i => $w ): ?>
                <div class="column-first">
                    <div class="image-wrapper">
                        <img src="<?=$w->img_src?>" alt="<?=$w->single?>">
                    </div>
                    <div class="image-text">
                        <?=$w->multi?>
                    </div>
                </div>
            <? endforeach ?>
        </div>
        <div class="related-articles">
            <?=w('related_articles')?>
        </div>
    </article>
    <? include('partials/teach-social-block.tpl.php') ?>
</div>