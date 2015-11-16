<div class="playlist-wrapper-wrapper">
	<div class="playlist-wrapper">
		<?php if($title != null): ?>
			<h2 class="playlist-title"><?php print $title; ?> <span class="playlist-count"><?php print count($playlist['#videos']); ?> VIDEOS</span></h2>
		<?php endif; ?>
	  <?php print render($playlist); ?>
	</div>
</div>
