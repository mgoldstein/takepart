<?php
// Flush all image styles in Drupal 7.
foreach (image_styles() as $style) {
  image_style_flush($style);
}
?>
