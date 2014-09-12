<?php
/**
 * Template for the Playlist DETAILED View Mode
 */
?>
<div class="playlist" data-playlist-type="detailed">
	<div class="current-video">
		<div class="video-placeholder"></div>
		<div class="video-description">
			<?php foreach($variables['videos'] as $key => $video): ?>
				<div class="description-item" data-video-description="<?php print $key; ?>">
					<h2 class="title"><?php print $video->title; ?></h2>
					<?php $subhead = field_get_items('node', $video, 'field_article_subhead'); ?>
					<?php print drupal_render(field_view_field('node', $video, 'field_article_subhead', $subhead)); ?>
				</div>
			<?php endforeach; ?>
		</div>
	</div>
	<?php print $variables['navigation']; ?>
</div>
