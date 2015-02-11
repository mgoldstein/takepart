<div class="content">
    <h2 class='main-headline'><?=w('main_headline')?></h2>
    <div class="body first cms">
        <?=w('intro')?>
    </div>
	<div class="video_intro" <?=wa('video_intro')?>>
        <iframe allowfullscreen="" frameborder="0" height="480" src="http://www.youtube.com/embed/<?=w('video_intro')->video?>" width="853"></iframe>
	</div>
    <div class="body second cms">
        <?=w('body')?>
    </div>
	<h2 class='nav-headline'><?=w('headline')?></h2>
    <?php include_once('subtemplates/education-artists-nav.tpl.php') ?>
</div>