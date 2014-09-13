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
					<h3 class="video-title"><?php print $video->title; ?></h3>
					<?php $subhead = field_get_items('node', $video, 'field_article_subhead'); ?>
						<div class="video-description"><?php print $subhead[0]['value']; ?></div>
				</div>
			<?php endforeach; ?>
		</div>
	</div>
	<?php print $variables['navigation']; ?>
</div>
