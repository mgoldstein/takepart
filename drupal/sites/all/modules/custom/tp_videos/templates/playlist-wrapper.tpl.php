<div class="playlist-wrapper-wrapper">
	<div class="playlist-wrapper">
		<?php if($title != null): ?>
			<h2 class="playlist-title"><?php print $title; ?>
				<?php print (isset($playlist['#videos']) && !empty($playlist['#videos'])?"<span class=\"playlist-count\">".count($playlist['#videos'])." VIDEOS</span>":""); ?>
			</h2>
		<?php endif; ?>
	  <?php print render($playlist); ?>
	</div>
</div>
