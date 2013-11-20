<?php
/**
 * @file
 * Theme Implementation to display an On The radar block.
 */
?>
<!-- The Block Formerly Known As "On Our Radar" -->
<aside class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <h3<?php print $title_attributes; ?>>From The Web</h3>
  <?php print render($title_suffix); ?>

<div id='taboola-below-main-column'></div>
<script type="text/javascript">
window._taboola = window._taboola || [];
_taboola.push({mode:'thumbs-1r', container:'taboola-below-main-column', placement:'below-main-column'});
</script>


    <h3>On Our Radar</h3>
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
