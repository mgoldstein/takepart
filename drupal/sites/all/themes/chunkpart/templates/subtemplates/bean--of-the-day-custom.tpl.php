<?php

/**
 * @file
 * Theme implementation for "of the day" block.
 *
 * Available variables:
 * - $custom_render
 * @see template_preprocess_entity()
 */
?>

<ul>
	<? foreach ( $custom_render as $item ): ?>
		<li>
			<a href="<?=$item['url'] ?>">
				<h4 class="subhead"><?=$item['typename'] ?></h4>
				<p class="image"><img src="<?=$item['thumbnail'] ?>" alt="<?=$item['typename'] ?> image" height="100" width="100" /></p>
				<p class="link"><?=$item['title'] ?></p>
			</a>
		</li>
	<? endforeach ?>
</ul>