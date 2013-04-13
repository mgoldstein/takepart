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
					<p class="topic"><?=$link['topic'] ?></p>
					<p class="topic"><?=$link['title'] ?></p>
				</a>
			</li>
		<? endif ?>
	<? endforeach ?>
</ol>
