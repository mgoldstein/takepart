<div class="content">
    <h2 class='main-headline'><?=w('main_headline')?></h2>
    <div class="body cms">
        <?=w('body')?>
    </div>
	<div class="video_intro" <?=wa('video_intro')?>>
        <iframe allowfullscreen="" frameborder="0" height="480" src="http://www.youtube.com/embed/<?=w('video_intro')->video?>" width="853"></iframe>
	</div>
	<h2 class='nav-headline'><?=w('headline')?></h2>
    <? include_once('subtemplates/eyelevel-artists-nav.tpl.php') ?>
</div>