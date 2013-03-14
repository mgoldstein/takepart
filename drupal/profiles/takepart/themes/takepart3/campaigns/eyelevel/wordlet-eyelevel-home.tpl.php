<div class="content">
    <div class="body cms">
        <?=w('body')?>
    </div>
	<div class="video_intro" <?=wa('video_intro')?>>
        <iframe allowfullscreen="" frameborder="0" height="480" src="http://www.youtube.com/embed/<?=w('video_intro')->video?>" width="853"></iframe>
	</div>
	<? include_once('subtemplates/eyelevel-artists-nav.tpl.php') ?>
</div>