<?php
  /**
   *  Variables defined in on_our_radar.module
   */
?>

<ol>
	<? foreach ( $links as $link ): ?>
		<? if ( $link['title'] ): ?>
			<li>
				<a href="<?=$link['link'] ?>" target="_blank">
					<p class="title"><?=$link['title'] ?> <span class="topic">(<?=$link['topic'] ?>)</span></p>
				</a>
			</li>
		<? endif ?>
	<? endforeach ?>
</ol>
