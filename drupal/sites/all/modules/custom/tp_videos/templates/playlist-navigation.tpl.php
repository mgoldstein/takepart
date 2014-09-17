<?php
/**
 * Template for the Playlist Navigation
 * TODO: We will need to configure this to the sliders specs
 */
?>
<ul class="video-playlist bxslider">
	<?php foreach($variables['video_displays'] as $key => $video_display): ?>
		<li class="video-item" data-video-number="<?php print $key; ?>">
			<?php print drupal_render($video_display); ?>
		</li>
	<?php endforeach; ?>
</ul>
<div class="clearfix"></div>