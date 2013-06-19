<?php
  /**
   *  Variables defined in on_our_radar.module
   */
?>

<ol>
	<? foreach ( $links as $link ): ?>
		<? if ( $link['title'] ): ?>
			<li>
				<a href="<?=$link['link'] ?>">
					<p class="title"><?=$link['title'] ?> <span class="topic">(<?=$link['topic'] ?>)</span></p>
				</a>
			</li>
		<? endif ?>
	<? endforeach ?>
</ol>
