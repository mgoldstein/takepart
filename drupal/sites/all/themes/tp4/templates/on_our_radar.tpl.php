<?php
/**
 * @file
 * Theme Implementation to display an On The radar block.
 */
?>
<!-- The Block Formerly Known As "On Our Radar" -->
<aside class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <h3<?php print $title_attributes; ?>>On Our Radar</h3>
  <?php print render($title_suffix); ?>

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
