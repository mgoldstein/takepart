<?php
/**
 * Template for the Playlist Navigation
 * TODO: We will need to configure this to the sliders specs
 */
?>
<?php foreach($variables['videos'] as $video): ?>
	<div class="item">
		<?php print drupal_render($video); ?>
	</div>
<?php endforeach; ?>