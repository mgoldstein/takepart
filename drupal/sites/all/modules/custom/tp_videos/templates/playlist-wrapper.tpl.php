<div class="playlist-wrapper-wrapper">
	<div class="playlist-wrapper">
		<?php if($title != null): ?>
			<h2 class="playlist-title"><?php print $title; ?></h2>
		<?php endif; ?>
	  <?php print render($playlist); ?>
	</div>
</div>
