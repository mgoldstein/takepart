<?php
/**
 * Template for the Playlist Navigation
 * TODO: We will need to configure this to the sliders specs
 */
?>
<!--<div id="effect-6" class="effects clearfix">-->
<nav class="video-playlist">
	<?php foreach($variables['video_displays'] as $key => $video_display): ?>
		<div class="video-item" data-video-number="<?php print $key; ?>">
			<?php print drupal_render($video_display); ?>
		</div>
	<?php endforeach; ?>
</nav>
<!--	</div>-->
<div class="clearfix"></div>