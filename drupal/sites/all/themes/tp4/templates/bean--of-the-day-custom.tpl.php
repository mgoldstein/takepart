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
  <?php foreach ( $custom_render as $item ): 
      dd($item);
      ?>
    
    <li class="of-the-day-item">
      <a href="<?=$item['url'] ?>">
	<img src="<?=$item['thumbnail']; ?>" alt="<?=$item['thumbnail_alt']; ?> image" height="100" width="100" />
	<h4 class="subhead"><?=$item['typename']; ?></h4>
	<h2 class="node-title"><?= $item['title'][0]['safe_value']; ?></h2>
      </a>
    </li>
  <?php endforeach ?>
</ul>
