<?php
  /**
   *  Variables defined in on_our_radar.module
   */
?>

<ol>
	<?php foreach ( $links as $link ): ?>
		<?php if ( $link['title'] ): ?>
			<li>
				<a href="<?=$link['link'] ?>" target="_blank">
					<p class="title"><?=$link['title'] ?> <span class="topic">(<?=$link['topic'] ?>)</span></p>
				</a>
			</li>
		<?php endif ?>
	<?php endforeach ?>
</ol>
