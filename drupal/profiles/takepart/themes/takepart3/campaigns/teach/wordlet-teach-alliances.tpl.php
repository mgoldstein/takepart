<div class="teach-alliances-content">
    <article class="content-inner">
        <h1 class="content-headline"><?=w('page_headline')?></h1>
        <h2 class="content-subheadline"><?=w('page_subheadline')?></h2>
        <div class="main-image-wrapper" <?=wa('main_image')?>>
            <? $w = w('main_image'); ?>
            <? $markup = '<img src="' . $w->img_src . '" alt="' . $w->single_no_markup . '">'; ?>
            <? if ($w->href) $markup = '<a href="' . $w->href . '">' . $markup . '</a>'; ?>
            <?=$markup;?>
        </div>
    	<div class="content-main cms">
            <?=w('content_main')?>
        </div>
        <div class="alliances" <?=wa('alliances')?>>
        <? foreach ( wl('alliances') as $i => $w ): ?>
    		<? $row_count = $i + 1; //array is zero-indexed ?>
    		<? $zebra = 'alliance-' .($row_count % 2 == 0) ? 'even' : 'odd'; ?>
    		<? $zebra .= ($row_count % 4 == 0) ? ' alliance-nth-child-4n' : ''; ?>
    		<div class="alliance alliance-<?=$row_count?> <?=$zebra?>">
    		    <? $markup = '<img src="' . $w->img_src . '" alt="' . $w->single_no_markup . '">'; ?>
    		    <? if ($w->href) $markup = '<a href="' . $w->href . '">' . $markup . '</a>'; ?>
    		    <?=$markup?>
            </div>
        <? endforeach ?>
    </div>
    </article>
    <section class="social-menu">
        <? include('partials/teach-social-block.tpl.php') ?>
    </section>
    <? include('partials/teach-watch-promo.tpl.php') ?>
</div>