<?php
/**
 * @file
 * Badge Image user generated badge form template.
 *
 * $heading
 * $instructions
 * $form
 * $css_prefix
 */
?>
<style type="text/css">
.<?php print $css_prefix; ?>-preview {
  background: url(<?php print $preview_bg_src; ?>) no-repeat top left;
  height: <?php print $preview_height; ?>px;
  width: <?php print $preview_width; ?>px;
}
</style>
<div class="badge-image-generator <?php print $css_prefix; ?>-generator">
<h2 class="badge-image-heading <?php print $css_prefix; ?>-heading"><?php print $heading; ?></h2>
<div class="badge-image-instructions <?php print $css_prefix; ?>-instructions"><?php print $instructions; ?></div>
<?php print render($form) ?>
<div class="badge-image-preview <?php print $css_prefix; ?>-preview"></div>
</div>
