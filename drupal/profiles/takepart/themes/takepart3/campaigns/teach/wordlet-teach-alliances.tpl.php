<div class="content">
    <article class="content-inner">
        <h1 class="content-headline"><?=w('page_headline')?></h1>
        <h2 class="content-subheadline"><?=w('page_subheadline')?></h2>
        <div class="main-image-wrapper" <?=wa('main_image')?>>
           <img src="<?=w('main_image')->img_src?>" alt="<?=w('main_image')->single?>"> 
        </div>
        <div class="content-main">
            <?=w('content_main')?>
        </div>
        <div class="alliances" <?=wa('alliances')?>>
            <? foreach ( wl('alliances') as $i => $w ): ?>
                <div class="alliance">
                    <img src="<?=$w->img_src?>" alt="<?=$w->single?>">
                </div>
            <? endforeach ?>
        </div>
    </article>
    <? include('partials/teach-social-block.tpl.php') ?>
</div>