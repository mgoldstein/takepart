<?php
/**
 * @file
 * Theme Implementation to display an On The radar block.
 */
?>
<!-- The Block Formerly Known As "On Our Radar" -->
<aside class="<?php print $classes; ?>"<?php print $attributes; ?>>

    <ol>
      <?php foreach ( $links as $link ) : ?>
	<?php if ( $link['title'] ) : ?>
	  <li>
	    <a href="<?php print $link['link'] ?>" target="_blank">
	      <?php print $link['title'] ?> <span class="topic">(<?=$link['topic'] ?>)</span>
	    </a>
	  </li>
	<?php endif; ?>
      <?php endforeach; ?>
  </ol>
</aside>
